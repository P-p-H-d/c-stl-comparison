#!/usr/bin/env python3
"""Update BENCH.md tables with historical best/worst rank columns.

The script adds or refreshes two columns in each benchmark table:
- Best Rank
- Worst Rank

For each row key ("Library / Container"), values are computed from the previous
N commits (default: 10) of the same BENCH.md file. If fewer commits are
available, all available previous commits are used.
"""

import argparse
import subprocess
import sys
from pathlib import Path
from typing import Dict, Iterable, List, Tuple


HistoryKey = Tuple[str, str]


def run_git(args: List[str], cwd: Path) -> str:
    result = subprocess.run(
        ["git", *args],
        cwd=cwd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        check=False,
    )
    if result.returncode != 0:
        raise RuntimeError(result.stderr.strip() or f"git {' '.join(args)} failed")
    return result.stdout


def split_cells(line: str) -> List[str]:
    return line.split("|")


def try_parse_rank_row(line: str) -> Tuple[int, str, str] | None:
    cells = split_cells(line)
    if len(cells) < 4:
        return None

    rank_str = cells[0].strip()
    if not rank_str.isdigit():
        return None

    rank = int(rank_str)
    library = cells[1].strip()
    container = cells[2].strip()
    if not library or not container:
        return None

    return rank, library, container


def get_table_metric(line: str) -> str | None:
    cells = [cell.strip() for cell in split_cells(line)]
    if len(cells) < 4:
        return None
    return cells[3].lower()


def collect_rank_history(text: str) -> Dict[HistoryKey, Tuple[int, int]]:
    history: Dict[HistoryKey, Tuple[int, int]] = {}
    current_metric: str | None = None

    for line in text.splitlines():
        if is_bench_table_header(line):
            current_metric = get_table_metric(line)
            continue

        parsed = try_parse_rank_row(line)
        if parsed is None or current_metric is None:
            continue

        rank, library, container = parsed
        key = (current_metric, f"{library} / {container}")

        if key in history:
            best, worst = history[key]
            history[key] = (min(best, rank), max(worst, rank))
        else:
            history[key] = (rank, rank)

    return history


def merge_histories(histories: Iterable[Dict[HistoryKey, Tuple[int, int]]]) -> Dict[HistoryKey, Tuple[int, int]]:
    merged: Dict[HistoryKey, Tuple[int, int]] = {}

    for history in histories:
        for key, (best, worst) in history.items():
            if key in merged:
                cur_best, cur_worst = merged[key]
                merged[key] = (min(cur_best, best), max(cur_worst, worst))
            else:
                merged[key] = (best, worst)

    return merged


def is_bench_table_header(line: str) -> bool:
    cells = [cell.strip() for cell in split_cells(line)]
    if len(cells) < 4:
        return False

    return (
        cells[0].lower() == "rank"
        and cells[1].lower() == "library"
        and cells[2].lower() == "container"
    )


def update_tables(text: str, history: Dict[HistoryKey, Tuple[int, int]]) -> str:
    lines = text.splitlines()
    updated: List[str] = []
    i = 0

    while i < len(lines):
        line = lines[i]

        if not is_bench_table_header(line):
            updated.append(line)
            i += 1
            continue

        header_cells = split_cells(line)
        base_header = [cell.strip() for cell in header_cells[:4]]
        current_metric = (base_header[3].strip().lower() if len(base_header) >= 4 else "")
        updated.append("|".join(base_header + ["Best Rank", "Worst Rank"]))

        i += 1
        if i < len(lines):
            sep_cells = split_cells(lines[i])
            base_sep = [cell.strip() or "----" for cell in sep_cells[:4]]
            while len(base_sep) < 4:
                base_sep.append("----")
            updated.append("|".join(base_sep + ["---------", "----------"]))
            i += 1

        while i < len(lines):
            row = lines[i]
            parsed = try_parse_rank_row(row)
            if parsed is None:
                break

            _, library, container = parsed
            key = (current_metric, f"{library} / {container}")
            if key in history:
                best, worst = history[key]
                best_text = str(best)
                worst_text = str(worst)
            else:
                best_text = "-"
                worst_text = "-"

            row_cells = split_cells(row)
            base_row = row_cells[:4]
            updated.append("|".join(base_row + [f" {best_text} ", f" {worst_text}"]))
            i += 1

    output = "\n".join(updated)
    if text.endswith("\n"):
        output += "\n"
    return output


def main() -> int:
    parser = argparse.ArgumentParser(description="Update BENCH.md with historical best/worst ranks.")
    parser.add_argument(
        "--file",
        default="bench/doc/BENCH.md",
        help="Path to BENCH markdown file, relative to repository root.",
    )
    parser.add_argument(
        "--commits",
        type=int,
        default=10,
        help="Number of previous commits to inspect (default: 10).",
    )
    args = parser.parse_args()

    try:
        repo_root = Path(run_git(["rev-parse", "--show-toplevel"], cwd=Path.cwd()).strip())
    except RuntimeError as exc:
        print(f"Error: {exc}", file=sys.stderr)
        return 1

    target_rel = Path(args.file)
    target_abs = repo_root / target_rel

    if not target_abs.exists():
        print(f"Error: file not found: {target_abs}", file=sys.stderr)
        return 1

    try:
        log_output = run_git(["log", "--format=%H", "--", str(target_rel)], cwd=repo_root)
    except RuntimeError as exc:
        print(f"Error: {exc}", file=sys.stderr)
        return 1

    all_commits = [line.strip() for line in log_output.splitlines() if line.strip()]
    previous_commits = all_commits[0 : args.commits + 1]

    histories: List[Dict[HistoryKey, Tuple[int, int]]] = []
    for commit in previous_commits:
        try:
            text = run_git(["show", f"{commit}:{target_rel.as_posix()}"], cwd=repo_root)
        except RuntimeError:
            continue
        histories.append(collect_rank_history(text))

    merged_history = merge_histories(histories)

    current_text = target_abs.read_text(encoding="utf-8")
    new_text = update_tables(current_text, merged_history)

    if new_text != current_text:
        target_abs.write_text(new_text, encoding="utf-8")
        print(f"Updated {target_rel} using {len(previous_commits)} previous commit(s).")
    else:
        print(f"No changes needed for {target_rel}.")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
