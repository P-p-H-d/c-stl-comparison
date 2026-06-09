#!/usr/bin/env python3
"""Update the Project Sizes table in README.md from lib-project-lines.json."""

from __future__ import annotations

import argparse
import json
import pathlib
import re
import sys
from typing import Any


PROJECT_SIZES_TABLE_PATTERN = re.compile(
    r"(^\|\s*Project Sizes\s*\|.*\n"
    r"\|[-| ]+\n"
    r"(?:\|.*\n)*)",
    re.MULTILINE,
)

LIBRARY_LABEL_TO_JSON_KEY = {
    "CC": "CC",
    "CCC": "ccc",
    "CMC": "C-Macro-Collections",
    "CollecC": "Collections-C",
    "CTL": "ctl",
    "GLIB": "glib",
    "KLIB": "klib",
    "M*LIB": "mlib",
    "OpenCSTL": "OpenCSTL",
    "STB_DS": "stb",
    "STC": "STC",
}

LIBRARIES_ORDER = [
    "CC",
    "CCC",
    "CMC",
    "CollecC",
    "CTL",
    "GLIB",
    "KLIB",
    "M*LIB",
    "OpenCSTL",
    "STB_DS",
    "STC",
]


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


def to_text(value: Any) -> str:
    if value is None:
        return "NA"
    return str(value)


def format_percent(part: Any, total: Any) -> str:
    if not isinstance(part, (int, float)) or not isinstance(total, (int, float)):
        return "NA"
    if float(total) <= 0:
        return "NA"
    return f"{(100.0 * float(part) / float(total)):.2f}%"


def ordered_libraries(libraries_data: dict[str, Any]) -> list[str]:
    present: set[str] = set()
    for label, json_key in LIBRARY_LABEL_TO_JSON_KEY.items():
        if isinstance(libraries_data.get(json_key), dict):
            present.add(label)

    ordered: list[str] = []
    for lib in LIBRARIES_ORDER:
        if lib in present:
            ordered.append(lib)
            present.remove(lib)

    ordered.extend(sorted(present, key=str.casefold))
    return ordered


def build_rows(libraries: list[str], data: dict[str, Any]) -> list[list[str]]:
    rows: list[list[str]] = [
        ["Number of source lines"],
        ["% of examples / source"],
        ["% of documentation / source"],
        ["% of tests / source"],
    ]

    libraries_data = data.get("libraries", {})
    if not isinstance(libraries_data, dict):
        libraries_data = {}

    for lib in libraries:
        json_key = LIBRARY_LABEL_TO_JSON_KEY.get(lib, lib)
        entry = libraries_data.get(json_key, {})
        if not isinstance(entry, dict):
            entry = {}

        source = entry.get("source")
        examples = entry.get("examples")
        documentation = entry.get("documentation")
        tests = entry.get("tests")

        rows[0].append(to_text(source))
        rows[1].append(format_percent(examples, source))
        rows[2].append(format_percent(documentation, source))
        rows[3].append(format_percent(tests, source))

    return rows


def update_project_sizes_table(readme_text: str, project_lines_data: dict[str, Any]) -> tuple[str, int]:
    replacements = 0

    def repl(match: re.Match[str]) -> str:
        nonlocal replacements
        replacements += 1
        table_lines = match.group(1).splitlines()
        header_cells = parse_header_cells(table_lines[0])
        if not header_cells or header_cells[0] != "Project Sizes":
            return match.group(1)

        libraries_data = project_lines_data.get("libraries", {})
        if not isinstance(libraries_data, dict):
            libraries_data = {}

        libraries = ordered_libraries(libraries_data)
        if not libraries:
            libraries = header_cells[1:]

        body_rows = build_rows(libraries, project_lines_data)
        return format_table([[header_cells[0], *libraries], *body_rows])

    new_text = PROJECT_SIZES_TABLE_PATTERN.sub(repl, readme_text)
    return new_text, replacements


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Update the README Project Sizes table from lib-project-lines.json."
    )
    parser.add_argument(
        "--readme",
        default="README.md",
        help="Path to README file to update (default: README.md).",
    )
    parser.add_argument(
        "--project-lines-json",
        default="lib-project-lines.json",
        help="Path to lib-project-lines.json (default: lib-project-lines.json).",
    )
    args = parser.parse_args()

    readme_path = pathlib.Path(args.readme).resolve()
    project_lines_path = pathlib.Path(args.project_lines_json).resolve()

    try:
        readme_text = readme_path.read_text(encoding="utf-8")
    except OSError as exc:
        print(f"error: cannot read {readme_path}: {exc}", file=sys.stderr)
        return 1

    try:
        project_lines_data = json.loads(project_lines_path.read_text(encoding="utf-8"))
    except OSError as exc:
        print(f"error: cannot read {project_lines_path}: {exc}", file=sys.stderr)
        return 1
    except json.JSONDecodeError as exc:
        print(f"error: invalid JSON in {project_lines_path}: {exc}", file=sys.stderr)
        return 1

    if not isinstance(project_lines_data, dict):
        print(f"error: invalid schema in {project_lines_path}", file=sys.stderr)
        return 1

    new_text, replacements = update_project_sizes_table(readme_text, project_lines_data)
    if replacements == 0:
        print("error: no matching Project Sizes table found", file=sys.stderr)
        return 2

    if new_text != readme_text:
        readme_path.write_text(new_text + ("\n" if readme_text.endswith("\n") else ""), encoding="utf-8")
        print(f"updated {readme_path} ({replacements} table)")
    else:
        print(f"no changes needed in {readme_path}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
