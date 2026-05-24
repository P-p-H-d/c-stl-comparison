#!/usr/bin/env python3
"""Update the Maintenance table in README.md from lib-maintenance.json."""

from __future__ import annotations

import argparse
import datetime as dt
import json
import pathlib
import re
import sys
from typing import Any

MAINTENANCE_TABLE_PATTERN = re.compile(
    r"(^\|?\s*Maintenance\s*\|.*\n"
    r"\|[-| ]+\n"
    r"(?:\|.*\n)*?)"
    r"(?=\n+This information is also available as a \[JSON file\]\(lib-maintenance\.json\)\.)",
    re.MULTILINE,
)


def parse_header_cells(line: str) -> list[str]:
    text = line.strip()
    if text.startswith("|") and text.endswith("|"):
        parts = text[1:-1].split("|")
    else:
        parts = text.split("|")
    return [part.strip() for part in parts if part.strip()]


def format_table(rows: list[list[str]]) -> str:
    widths = [max(len(row[i]) for row in rows) for i in range(len(rows[0]))]

    def fmt_row(row: list[str]) -> str:
        return "| " + " | ".join(cell.ljust(widths[i]) for i, cell in enumerate(row)) + " |"

    header = fmt_row(rows[0])
    sep = "|" + "|".join("-" * (w + 2) for w in widths) + "|"
    body = "\n".join(fmt_row(row) for row in rows[1:])
    return "\n".join([header, sep, body]) + "\n"


def parse_iso8601(value: str | None) -> dt.datetime | None:
    if not value:
        return None
    try:
        return dt.datetime.strptime(value, "%Y-%m-%dT%H:%M:%SZ").replace(tzinfo=dt.timezone.utc)
    except ValueError:
        return None


def get_ci_os_count(entry: dict[str, Any]) -> Any:
    if "Number of OS supported by CI" in entry:
        return entry.get("Number of OS supported by CI")
    return entry.get("Number of systems supported by CI")


def to_text(value: Any) -> str:
    if value is None:
        return "NA"
    if isinstance(value, float):
        return f"{value:.2f}".rstrip("0").rstrip(".")
    return str(value)


def format_days(value: Any) -> str:
    if value is None:
        return "NA"
    if isinstance(value, (int, float)):
        return f"{value:.2f} days"
    return f"{value} days"


def format_years(value: float | None) -> str:
    if value is None:
        return "NA"
    return f"{value:.2f} years"


def format_release_date(value: Any) -> str:
    if not isinstance(value, str) or not value:
        return "NA"
    if "T" in value:
        return value.split("T", 1)[0]
    return value


def compute_project_age_years(entry: dict[str, Any], analysis_date: dt.datetime) -> float | None:
    oldest = parse_iso8601(entry.get("Oldest commit date"))
    if oldest is None:
        return None
    age_days = (analysis_date - oldest).total_seconds() / 86400.0
    if age_days < 0:
        return None
    return age_days / 365.25


def format_releases_per_year(entry: dict[str, Any], project_age_years: float | None) -> str:
    releases = entry.get("Number of releases")
    if not isinstance(releases, (int, float)) or project_age_years is None or project_age_years <= 0:
        return "NA"
    return to_text(float(releases) / project_age_years)


def format_open_issue_percent(entry: dict[str, Any]) -> str:
    open_issues = entry.get("Number of open issues")
    closed_issues = entry.get("Number of closed issues")
    if not isinstance(open_issues, (int, float)) or not isinstance(closed_issues, (int, float)):
        return "NA"
    total = float(open_issues) + float(closed_issues)
    if total <= 0:
        return "NA"
    pct = 100.0 * float(open_issues) / total
    return f"{pct:.2f}%"


def format_hours(value: Any) -> str:
    if value is None:
        return "NA"
    if isinstance(value, (int, float)):
        return f"{value:.2f} h"
    return f"{value} h"


def build_rows(libraries: list[str], data: dict[str, Any], analysis_date: dt.datetime) -> list[list[str]]:
    rows: list[list[str]] = [
        ["Number of stars"],
        ["Last commit age"],
        ["Number of commits"],
        ["How old is the project?"],
        ["Last release date"],
        ["Number of release per year"],
        ["Percent of open issues / total (open+closed) issues"],
        ["Average Time to answer an issue"],
        ["Number of main authors"],
        ["Number of OS supported by CI"],
        ["Number of hardware architecture supported by CI"],
        ["Number of compilers supported by CI"],
    ]

    libraries_data = data.get("libraries", {})
    if not isinstance(libraries_data, dict):
        libraries_data = {}

    for lib in libraries:
        entry = libraries_data.get(lib, {})
        if not isinstance(entry, dict):
            entry = {}

        project_age_years = compute_project_age_years(entry, analysis_date)

        values = [
            to_text(entry.get("Number of stars")),
            format_days(entry.get("Last commit age (days)")),
            to_text(entry.get("Number of commits")),
            format_years(project_age_years),
            format_release_date(entry.get("Last release date")),
            format_releases_per_year(entry, project_age_years),
            format_open_issue_percent(entry),
            format_hours(entry.get("Average Time to answer an issue (hours)")),
            to_text(entry.get("Number of main authors")),
            to_text(get_ci_os_count(entry)),
            to_text(entry.get("Number of hardware architecture supported by CI")),
            to_text(entry.get("Number of compilers supported by CI")),
        ]

        for row, value in zip(rows, values):
            row.append(value)

    return rows


def update_maintenance_table(readme_text: str, maintenance_data: dict[str, Any]) -> tuple[str, int]:
    replacements = 0

    date_raw = maintenance_data.get("Date of analysis")
    analysis_date = dt.datetime.now(tz=dt.timezone.utc)
    if isinstance(date_raw, str):
        try:
            analysis_date = dt.datetime.strptime(date_raw, "%Y-%m-%d").replace(tzinfo=dt.timezone.utc)
        except ValueError:
            pass

    def repl(match: re.Match[str]) -> str:
        nonlocal replacements
        replacements += 1
        table_lines = match.group(1).splitlines()
        header_cells = parse_header_cells(table_lines[0])
        if not header_cells or header_cells[0] != "Maintenance":
            return match.group(1)

        libraries = sorted(header_cells[1:], key=str.casefold)
        header_cells = [header_cells[0], *libraries]
        body_rows = build_rows(libraries, maintenance_data, analysis_date)
        return format_table([header_cells, *body_rows])

    new_text = MAINTENANCE_TABLE_PATTERN.sub(repl, readme_text)
    return new_text, replacements


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Update README Maintenance table from lib-maintenance.json."
    )
    parser.add_argument(
        "--readme",
        default="README.md",
        help="Path to README file to update (default: README.md).",
    )
    parser.add_argument(
        "--maintenance-json",
        default="lib-maintenance.json",
        help="Path to lib-maintenance.json (default: lib-maintenance.json).",
    )
    args = parser.parse_args()

    readme_path = pathlib.Path(args.readme).resolve()
    maintenance_path = pathlib.Path(args.maintenance_json).resolve()

    try:
        readme_text = readme_path.read_text(encoding="utf-8")
    except OSError as exc:
        print(f"error: cannot read {readme_path}: {exc}", file=sys.stderr)
        return 1

    try:
        maintenance_data = json.loads(maintenance_path.read_text(encoding="utf-8"))
    except OSError as exc:
        print(f"error: cannot read {maintenance_path}: {exc}", file=sys.stderr)
        return 1
    except json.JSONDecodeError as exc:
        print(f"error: invalid JSON in {maintenance_path}: {exc}", file=sys.stderr)
        return 1

    new_text, replacements = update_maintenance_table(readme_text, maintenance_data)
    if replacements == 0:
        print("error: no matching Maintenance table found", file=sys.stderr)
        return 2

    if new_text != readme_text:
        readme_path.write_text(new_text, encoding="utf-8")
        print(f"updated {readme_path} ({replacements} table)")
    else:
        print(f"no changes needed in {readme_path}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())