#!/usr/bin/env python3
"""Update README Array/UMap tables from lib-metrics.json."""

import argparse
import json
import pathlib
import re
import sys
from typing import Any

METRICS_HEADER_PATTERN = re.compile(r"^\|\s*(Array|UMap)-(Int|Str|mpz) programs\s*\|", re.IGNORECASE)
SIZE_HEADER_PATTERN = re.compile(r"^\|\s*(array|umap)-(int|str|mpz) size\s*\|\s*bytes\s*\|$", re.IGNORECASE)
COMP_HEADER_PATTERN = re.compile(
    r"^\|\s*(array|umap)-(int|str|mpz) compilation\s*\|\s*time\s*\|$",
    re.IGNORECASE,
)


def parse_row(line: str) -> list[str]:
    return [cell.strip() for cell in line.strip().strip("|").split("|")]


def format_table(rows: list[list[str]]) -> str:
    widths = [max(len(row[i]) for row in rows) for i in range(len(rows[0]))]

    def fmt_row(row: list[str]) -> str:
        return "| " + " | ".join(cell.ljust(widths[i]) for i, cell in enumerate(row)) + " |"

    header = fmt_row(rows[0])
    sep = "|" + "|".join("-" * (w + 2) for w in widths) + "|"
    body = "\n".join(fmt_row(row) for row in rows[1:])
    return "\n".join([header, sep, body])


def table_program_from_metrics_header(header_cell: str) -> str | None:
    match = re.match(r"(Array|UMap)-(Int|Str|mpz) programs", header_cell)
    if not match:
        return None
    return f"{match.group(1).lower()}-{match.group(2).lower()}"


def table_program_from_simple_header(header_cell: str, suffix: str) -> str | None:
    match = re.match(rf"(array|umap)-(int|str|mpz) {suffix}$", header_cell)
    if not match:
        return None
    return f"{match.group(1).lower()}-{match.group(2).lower()}"


def to_cell(value: Any) -> str:
    if value is None:
        return "NA"
    return str(value)


def update_metrics_table(table_text: str, programs_data: dict[str, Any]) -> str:
    lines = table_text.splitlines()
    header_cells = parse_row(lines[0])
    if not header_cells:
        return table_text

    program = table_program_from_metrics_header(header_cells[0])
    if program is None:
        return table_text

    program_data = programs_data.get(program, {})
    if not isinstance(program_data, dict):
        program_data = {}

    libraries = header_cells[1:]
    chars_row = ["number of characters"]
    loc_row = ["number of line of codes"]
    wa_row = ["number of workarounds"]

    for lib in libraries:
        lib_data = program_data.get(lib, {})
        if not isinstance(lib_data, dict):
            lib_data = {}
        chars_row.append(to_cell(lib_data.get("number of characters")))
        loc_row.append(to_cell(lib_data.get("number of line of codes")))
        wa_row.append(to_cell(lib_data.get("number of workarounds")))

    return format_table([header_cells, chars_row, loc_row, wa_row])


def update_size_table(table_text: str, programs_data: dict[str, Any]) -> str:
    lines = table_text.splitlines()
    header_cells = parse_row(lines[0])
    if not header_cells:
        return table_text

    program = table_program_from_simple_header(header_cells[0], "size")
    if program is None:
        return table_text

    program_data = programs_data.get(program, {})
    if not isinstance(program_data, dict):
        program_data = {}

    rows: list[tuple[str, int]] = []
    for lib, lib_data in program_data.items():
        if not isinstance(lib_data, dict):
            continue
        value = lib_data.get("binary size (bytes)")
        if isinstance(value, int):
            rows.append((lib, value))

    rows.sort(key=lambda item: (item[1], item[0].casefold()))
    body_rows = [[lib, str(size)] for lib, size in rows]
    if not body_rows:
        body_rows = [["NA", "NA"]]

    return format_table([header_cells, *body_rows])


def update_compilation_table(table_text: str, programs_data: dict[str, Any]) -> str:
    lines = table_text.splitlines()
    header_cells = parse_row(lines[0])
    if not header_cells:
        return table_text

    program = table_program_from_simple_header(header_cells[0], "compilation")
    if program is None:
        return table_text

    program_data = programs_data.get(program, {})
    if not isinstance(program_data, dict):
        program_data = {}

    rows: list[tuple[str, float]] = []
    for lib, lib_data in program_data.items():
        if not isinstance(lib_data, dict):
            continue
        value = lib_data.get("compilation time (seconds)")
        if isinstance(value, (int, float)):
            rows.append((lib, float(value)))

    rows.sort(key=lambda item: (item[1], item[0].casefold()))
    body_rows = [[lib, f"{seconds:.2f}"] for lib, seconds in rows]
    if not body_rows:
        body_rows = [["NA", "NA"]]

    return format_table([header_cells, *body_rows])


def update_readme(readme_text: str, programs_data: dict[str, Any]) -> tuple[str, int]:
    lines = readme_text.splitlines()
    updated_lines: list[str] = []
    replacements = 0
    i = 0

    while i < len(lines):
        line = lines[i]

        is_metrics = bool(METRICS_HEADER_PATTERN.match(line))
        is_size = bool(SIZE_HEADER_PATTERN.match(line))
        is_comp = bool(COMP_HEADER_PATTERN.match(line))

        if (is_metrics or is_size or is_comp) and i + 1 < len(lines) and lines[i + 1].startswith("|-"):
            start = i
            end = i + 2
            while end < len(lines) and lines[end].startswith("|"):
                end += 1

            table_text = "\n".join(lines[start:end])
            if is_metrics:
                new_table = update_metrics_table(table_text, programs_data)
            elif is_size:
                new_table = update_size_table(table_text, programs_data)
            else:
                new_table = update_compilation_table(table_text, programs_data)

            updated_lines.append(new_table)
            replacements += 1
            i = end
            continue

        updated_lines.append(line)
        i += 1

    return "\n".join(updated_lines), replacements


def main() -> int:
    parser = argparse.ArgumentParser(
        description=(
            "Update README Array/UMap metrics, size, and compilation tables "
            "from lib-metrics.json."
        )
    )
    parser.add_argument(
        "--readme",
        default="README.md",
        help="Path to README file to update (default: README.md).",
    )
    parser.add_argument(
        "--metrics-json",
        default="lib-metrics.json",
        help="Path to lib-metrics.json (default: lib-metrics.json).",
    )
    args = parser.parse_args()

    readme_path = pathlib.Path(args.readme).resolve()
    metrics_path = pathlib.Path(args.metrics_json).resolve()

    try:
        readme_text = readme_path.read_text(encoding="utf-8")
    except OSError as exc:
        print(f"error: cannot read {readme_path}: {exc}", file=sys.stderr)
        return 1

    try:
        metrics_data = json.loads(metrics_path.read_text(encoding="utf-8"))
    except OSError as exc:
        print(f"error: cannot read {metrics_path}: {exc}", file=sys.stderr)
        return 1
    except json.JSONDecodeError as exc:
        print(f"error: invalid JSON in {metrics_path}: {exc}", file=sys.stderr)
        return 1

    programs_data = metrics_data.get("programs", {})
    if not isinstance(programs_data, dict):
        print("error: invalid schema in lib-metrics.json (missing programs object)", file=sys.stderr)
        return 1

    new_text, replacements = update_readme(readme_text, programs_data)
    if replacements == 0:
        print("error: no matching Array/UMap tables found", file=sys.stderr)
        return 2

    if new_text != readme_text:
        readme_path.write_text(new_text + ("\n" if readme_text.endswith("\n") else ""), encoding="utf-8")
        print(f"updated {readme_path} ({replacements} tables)")
    else:
        print(f"no changes needed in {readme_path}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())