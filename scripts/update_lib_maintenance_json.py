#!/usr/bin/env python3
"""Generate lib-maintenance.json from GitHub repository metadata.

The script reads repository URLs from Makefile git clone commands and computes
maintenance indicators for the compared libraries.

Environment:
  GITHUB_TOKEN  Optional GitHub token to increase API rate limits.
"""

import argparse
import datetime as dt
import json
import os
import pathlib
import re
import sys
import time
import urllib.error
import urllib.parse
import urllib.request
from typing import Any

# Libraries used in README comparison tables.
LIBRARIES_ORDER = [
    "STL",
    "M*LIB",
    "STC",
    "CMC",
    "CTL",
    "CollecC",
    "CC",
    "GLIB",
    "STB_DS",
    "KLIB",
    "CCC",
]

# Map library labels to Makefile external directory names.
LIB_TO_EXTERNAL_DIR = {
    "M*LIB": "mlib",
    "STC": "STC",
    "CMC": "C-Macro-Collections",
    "CTL": "ctl",
    "CollecC": "Collections-C",
    "CC": "CC",
    "STB_DS": "stb",
    "KLIB": "klib",
    "CCC": "ccc",
}

ISO_FMT = "%Y-%m-%dT%H:%M:%SZ"


def parse_iso8601_utc(value: str) -> dt.datetime:
    return dt.datetime.strptime(value, ISO_FMT).replace(tzinfo=dt.timezone.utc)


def hours_between(a: dt.datetime, b: dt.datetime) -> float:
    return (b - a).total_seconds() / 3600.0


def average(values: list[float]) -> float | None:
    if not values:
        return None
    return sum(values) / len(values)


def parse_link_header(link_header: str | None) -> dict[str, str]:
    if not link_header:
        return {}
    out: dict[str, str] = {}
    for part in link_header.split(","):
        section = part.strip().split(";")
        if len(section) < 2:
            continue
        url = section[0].strip()
        if not (url.startswith("<") and url.endswith(">")):
            continue
        rel = None
        for elem in section[1:]:
            elem = elem.strip()
            m = re.match(r'rel="([^"]+)"', elem)
            if m:
                rel = m.group(1)
                break
        if rel:
            out[rel] = url[1:-1]
    return out


class GitHubClient:
    def __init__(self, token: str | None = None, timeout: int = 30):
        self.token = token
        self.timeout = timeout
        self.base = "https://api.github.com"

    def _request(self, path_or_url: str) -> tuple[Any, dict[str, str], int]:
        if path_or_url.startswith("http://") or path_or_url.startswith("https://"):
            url = path_or_url
        else:
            url = f"{self.base}{path_or_url}"

        headers = {
            "Accept": "application/vnd.github+json",
            "User-Agent": "c-stl-comparison-maintenance-script",
        }
        if self.token:
            headers["Authorization"] = f"Bearer {self.token}"

        req = urllib.request.Request(url=url, headers=headers)

        try:
            with urllib.request.urlopen(req, timeout=self.timeout) as resp:
                raw = resp.read().decode("utf-8")
                meta = {k.lower(): v for (k, v) in resp.headers.items()}
                ctype = meta.get("content-type", "").lower()
                if raw and "json" in ctype:
                    body: Any = json.loads(raw)
                else:
                    body = raw if raw else None
                return body, meta, resp.status
        except urllib.error.HTTPError as exc:
            raw = exc.read().decode("utf-8", errors="replace")
            msg = raw
            try:
                payload = json.loads(raw)
                msg = payload.get("message", raw)
            except json.JSONDecodeError:
                pass
            raise RuntimeError(f"GitHub API error {exc.code} on {url}: {msg}") from exc
        except urllib.error.URLError as exc:
            raise RuntimeError(f"Network error on {url}: {exc}") from exc

    def get_json(self, path_or_url: str) -> tuple[Any, dict[str, str]]:
        data, headers, _ = self._request(path_or_url)
        return data, headers


def parse_owner_repo(url: str) -> str | None:
    parsed = urllib.parse.urlparse(url)
    if parsed.netloc.lower() != "github.com":
        return None
    path = parsed.path.strip("/")
    if path.endswith(".git"):
        path = path[:-4]
    parts = path.split("/")
    if len(parts) < 2:
        return None
    return f"{parts[0]}/{parts[1]}"


def extract_makefile_github_urls(makefile_text: str) -> dict[str, str]:
    """Extract mapping external/<dir> -> GitHub clone URL from Makefile."""
    out: dict[str, str] = {}
    current_target: str | None = None

    for line in makefile_text.splitlines():
        target = re.match(r"^external/([^:\s]+):\s*$", line)
        if target:
            current_target = target.group(1)
            continue

        if current_target and "git clone" in line and "https://github.com/" in line:
            m = re.search(r"(https://github\.com/[^\s]+)", line)
            if m:
                url = m.group(1)
                if url.endswith(".git"):
                    url = url[:-4]
                out[current_target] = url
            current_target = None
        elif line.strip() and not line.startswith("\t"):
            current_target = None

    return out


def get_total_count_from_search(client: GitHubClient, query: str) -> int:
    payload, _ = client.get_json(f"/search/issues?q={urllib.parse.quote(query)}&per_page=1")
    return int(payload.get("total_count", 0))


def get_commit_count_and_last_commit(
    client: GitHubClient, owner_repo: str, now: dt.datetime
) -> tuple[int, float | None]:
    items, headers = client.get_json(f"/repos/{owner_repo}/commits?per_page=1")
    commits = items if isinstance(items, list) else []

    link_map = parse_link_header(headers.get("link"))
    if "last" in link_map:
        qs = urllib.parse.parse_qs(urllib.parse.urlparse(link_map["last"]).query)
        last_page = int(qs.get("page", ["1"])[0])
        commit_count = last_page
    else:
        commit_count = len(commits)

    last_commit_age_days: float | None = None
    if commits:
        last_date_s = commits[0].get("commit", {}).get("committer", {}).get("date")
        if last_date_s:
            last_dt = parse_iso8601_utc(last_date_s)
            last_commit_age_days = (now - last_dt).total_seconds() / 86400.0

    return commit_count, last_commit_age_days


def get_releases_info(client: GitHubClient, owner_repo: str) -> tuple[int, str | None]:
    releases, headers = client.get_json(f"/repos/{owner_repo}/releases?per_page=1")
    items = releases if isinstance(releases, list) else []

    link_map = parse_link_header(headers.get("link"))
    if "last" in link_map:
        qs = urllib.parse.parse_qs(urllib.parse.urlparse(link_map["last"]).query)
        count = int(qs.get("page", ["1"])[0])
    else:
        count = len(items)

    last_release_date = None
    if items:
        last_release_date = items[0].get("published_at") or items[0].get("created_at")

    return count, last_release_date


def get_contributors_main_authors(client: GitHubClient, owner_repo: str) -> int | None:
    contributors: list[dict[str, Any]] = []
    url = f"/repos/{owner_repo}/contributors?per_page=100&anon=1"

    while url:
        page, headers = client.get_json(url)
        if not isinstance(page, list):
            break
        contributors.extend(page)
        next_url = parse_link_header(headers.get("link")).get("next")
        url = next_url if next_url else ""

    counts = [int(c.get("contributions", 0)) for c in contributors]
    total = sum(counts)
    if total <= 0:
        return None

    threshold = total * 0.10
    return sum(1 for c in counts if c > threshold)


def get_issues_for_sampling(
    client: GitHubClient, owner_repo: str, state: str, limit: int
) -> list[dict[str, Any]]:
    items: list[dict[str, Any]] = []
    page = 1

    while len(items) < limit:
        batch, _ = client.get_json(
            f"/repos/{owner_repo}/issues?state={state}&sort=created&direction=desc&per_page=100&page={page}"
        )
        if not isinstance(batch, list) or not batch:
            break

        for it in batch:
            # GitHub issue API returns PRs too; keep only pure issues.
            if "pull_request" not in it:
                items.append(it)
                if len(items) >= limit:
                    break

        page += 1

    return items


def get_prs_for_sampling(
    client: GitHubClient, owner_repo: str, state: str, limit: int
) -> list[dict[str, Any]]:
    items: list[dict[str, Any]] = []
    page = 1

    while len(items) < limit:
        batch, _ = client.get_json(
            f"/repos/{owner_repo}/pulls?state={state}&sort=created&direction=desc&per_page=100&page={page}"
        )
        if not isinstance(batch, list) or not batch:
            break

        items.extend(batch)
        if len(items) >= limit:
            break

        page += 1

    return items[:limit]


def first_issue_response_hours(
    client: GitHubClient,
    owner_repo: str,
    issue_number: int,
    issue_author: str,
    created_at_s: str,
) -> float | None:
    comments, _ = client.get_json(
        f"/repos/{owner_repo}/issues/{issue_number}/comments?per_page=100&page=1"
    )
    if not isinstance(comments, list) or not comments:
        return None

    created_dt = parse_iso8601_utc(created_at_s)
    for c in comments:
        user = (c.get("user") or {}).get("login", "")
        if user and user != issue_author:
            date_s = c.get("created_at")
            if date_s:
                return hours_between(created_dt, parse_iso8601_utc(date_s))
    return None


def first_pr_response_hours(
    client: GitHubClient,
    owner_repo: str,
    pr_number: int,
    pr_author: str,
    created_at_s: str,
) -> float | None:
    created_dt = parse_iso8601_utc(created_at_s)
    candidates: list[dt.datetime] = []

    issue_comments, _ = client.get_json(
        f"/repos/{owner_repo}/issues/{pr_number}/comments?per_page=100&page=1"
    )
    if isinstance(issue_comments, list):
        for c in issue_comments:
            user = (c.get("user") or {}).get("login", "")
            if user and user != pr_author and c.get("created_at"):
                candidates.append(parse_iso8601_utc(c["created_at"]))

    reviews, _ = client.get_json(
        f"/repos/{owner_repo}/pulls/{pr_number}/reviews?per_page=100&page=1"
    )
    if isinstance(reviews, list):
        for r in reviews:
            user = (r.get("user") or {}).get("login", "")
            if user and user != pr_author and r.get("submitted_at"):
                candidates.append(parse_iso8601_utc(r["submitted_at"]))

    review_comments, _ = client.get_json(
        f"/repos/{owner_repo}/pulls/{pr_number}/comments?per_page=100&page=1"
    )
    if isinstance(review_comments, list):
        for c in review_comments:
            user = (c.get("user") or {}).get("login", "")
            if user and user != pr_author and c.get("created_at"):
                candidates.append(parse_iso8601_utc(c["created_at"]))

    if not candidates:
        return None

    first_dt = min(candidates)
    return hours_between(created_dt, first_dt)


def ci_metrics(client: GitHubClient, owner_repo: str) -> tuple[bool, int, int]:
    try:
        entries, _ = client.get_json(f"/repos/{owner_repo}/contents/.github/workflows")
    except RuntimeError as exc:
        if " 404 " in f" {exc} ":
            return False, 0, 0
        raise

    if not isinstance(entries, list) or not entries:
        return False, 0, 0

    workflow_urls = []
    for e in entries:
        name = str(e.get("name", "")).lower()
        if name.endswith(".yml") or name.endswith(".yaml"):
            download_url = e.get("download_url")
            if isinstance(download_url, str) and download_url:
                workflow_urls.append(download_url)

    if not workflow_urls:
        return False, 0, 0

    os_set: set[str] = set()
    compiler_set: set[str] = set()

    for url in workflow_urls:
        text, _ = client.get_json(url)
        yaml_text = str(text) if text is not None else ""

        low = yaml_text.lower()

        for token in ("ubuntu", "windows", "macos", "linux", "self-hosted"):
            if token in low:
                os_set.add(token)

        patterns = [
            (r"\bgcc\b|\bg\+\+\b", "gcc"),
            (r"\bclang\b|\bclang\+\+\b", "clang"),
            (r"\bmsvc\b|\bcl\b", "msvc"),
            (r"\bmingw\b", "mingw"),
            (r"\bicc\b|\bicx\b", "intel"),
        ]
        for pat, label in patterns:
            if re.search(pat, low):
                compiler_set.add(label)

    return True, len(os_set), len(compiler_set)


def collect_repo_metrics(
    client: GitHubClient,
    owner_repo: str,
    issue_sample: int,
    pr_sample: int,
    now: dt.datetime,
) -> dict[str, Any]:
    commit_count, last_commit_age_days = get_commit_count_and_last_commit(client, owner_repo, now)

    issues_open = get_total_count_from_search(client, f"repo:{owner_repo} type:issue state:open")
    issues_closed = get_total_count_from_search(client, f"repo:{owner_repo} type:issue state:closed")
    prs_open = get_total_count_from_search(client, f"repo:{owner_repo} type:pr state:open")
    prs_closed = get_total_count_from_search(client, f"repo:{owner_repo} type:pr state:closed")

    closed_issues = get_issues_for_sampling(client, owner_repo, "closed", issue_sample)
    all_issues = get_issues_for_sampling(client, owner_repo, "all", issue_sample)

    issue_close_hours: list[float] = []
    for issue in closed_issues:
        created_s = issue.get("created_at")
        closed_s = issue.get("closed_at")
        if created_s and closed_s:
            issue_close_hours.append(
                hours_between(parse_iso8601_utc(created_s), parse_iso8601_utc(closed_s))
            )

    issue_response_hours: list[float] = []
    for issue in all_issues:
        created_s = issue.get("created_at")
        number = issue.get("number")
        author = (issue.get("user") or {}).get("login", "")
        if created_s and isinstance(number, int) and author:
            val = first_issue_response_hours(client, owner_repo, number, author, created_s)
            if val is not None:
                issue_response_hours.append(val)

    closed_prs = get_prs_for_sampling(client, owner_repo, "closed", pr_sample)
    all_prs = get_prs_for_sampling(client, owner_repo, "all", pr_sample)

    pr_close_hours: list[float] = []
    for pr in closed_prs:
        created_s = pr.get("created_at")
        closed_s = pr.get("closed_at")
        if created_s and closed_s:
            pr_close_hours.append(
                hours_between(parse_iso8601_utc(created_s), parse_iso8601_utc(closed_s))
            )

    pr_response_hours: list[float] = []
    for pr in all_prs:
        created_s = pr.get("created_at")
        number = pr.get("number")
        author = (pr.get("user") or {}).get("login", "")
        if created_s and isinstance(number, int) and author:
            val = first_pr_response_hours(client, owner_repo, number, author, created_s)
            if val is not None:
                pr_response_hours.append(val)

    releases_count, last_release_date = get_releases_info(client, owner_repo)
    main_authors = get_contributors_main_authors(client, owner_repo)
    ci_present, ci_systems, ci_compilers = ci_metrics(client, owner_repo)

    return {
        "Last commit age (days)": round(last_commit_age_days, 2) if last_commit_age_days is not None else None,
        "Number of commits": commit_count,
        "Number of open issues": issues_open,
        "Number of closed issues": issues_closed,
        "Average Time to answer an issue (hours)": round(average(issue_response_hours), 2)
        if average(issue_response_hours) is not None
        else None,
        "Average Time to close an issue (hours)": round(average(issue_close_hours), 2)
        if average(issue_close_hours) is not None
        else None,
        "Number of open pull requests": prs_open,
        "Number of closed pull requests": prs_closed,
        "Average Time to answer a pull request (hours)": round(average(pr_response_hours), 2)
        if average(pr_response_hours) is not None
        else None,
        "Average Time to close or merge a pull request (hours)": round(average(pr_close_hours), 2)
        if average(pr_close_hours) is not None
        else None,
        "Number of releases": releases_count,
        "Last release date": last_release_date,
        "Number of main authors": main_authors,
        "CI Presence": ci_present,
        "Number of systems supported by CI": ci_systems,
        "Number of compilers supported by CI": ci_compilers,
        "sampling": {
            "issues_checked": len(all_issues),
            "closed_issues_checked": len(closed_issues),
            "prs_checked": len(all_prs),
            "closed_prs_checked": len(closed_prs),
        },
    }


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Generate lib-maintenance.json from GitHub repositories."
    )
    parser.add_argument(
        "--makefile",
        default="Makefile",
        help="Path to Makefile containing git clone URLs (default: Makefile)",
    )
    parser.add_argument(
        "--output",
        default="lib-maintenance.json",
        help="Output JSON file path (default: lib-maintenance.json)",
    )
    parser.add_argument(
        "--issue-sample",
        type=int,
        default=50,
        help="Max issues sampled per repo for response/close timing (default: 50)",
    )
    parser.add_argument(
        "--pr-sample",
        type=int,
        default=50,
        help="Max PRs sampled per repo for response/close timing (default: 50)",
    )
    parser.add_argument(
        "--sleep-seconds",
        type=float,
        default=0.0,
        help="Optional delay between repositories to reduce API burst (default: 0)",
    )
    args = parser.parse_args()

    makefile_path = pathlib.Path(args.makefile).resolve()
    output_path = pathlib.Path(args.output).resolve()

    if not makefile_path.exists():
        print(f"error: Makefile not found: {makefile_path}", file=sys.stderr)
        return 1

    makefile_text = makefile_path.read_text(encoding="utf-8")
    target_to_url = extract_makefile_github_urls(makefile_text)

    token = None
    if "GITHUB_TOKEN" in os.environ:
        token = os.environ["GITHUB_TOKEN"].strip() or None

    client = GitHubClient(token=token)
    now = dt.datetime.now(tz=dt.timezone.utc)

    result: dict[str, Any] = {
        "Date of analysis": now.date().isoformat(),
        "libraries": {},
    }

    for lib in LIBRARIES_ORDER:
        lib_entry: dict[str, Any] = {}
        ext_dir = LIB_TO_EXTERNAL_DIR.get(lib)
        repo_url = target_to_url.get(ext_dir, "") if ext_dir else ""
        owner_repo = parse_owner_repo(repo_url) if repo_url else None

        lib_entry["repository_url"] = repo_url if repo_url else None
        lib_entry["repository"] = owner_repo

        if owner_repo is None:
            lib_entry["status"] = "skipped (no GitHub URL in Makefile for this library)"
            result["libraries"][lib] = lib_entry
            continue

        try:
            metrics = collect_repo_metrics(
                client=client,
                owner_repo=owner_repo,
                issue_sample=args.issue_sample,
                pr_sample=args.pr_sample,
                now=now,
            )
            lib_entry.update(metrics)
            lib_entry["status"] = "ok"
        except Exception as exc:
            lib_entry["status"] = "error"
            lib_entry["error"] = str(exc)

        result["libraries"][lib] = lib_entry

        if args.sleep_seconds > 0:
            time.sleep(args.sleep_seconds)

    output_path.write_text(json.dumps(result, indent=2, ensure_ascii=True) + "\n", encoding="utf-8")
    print(f"wrote {output_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
