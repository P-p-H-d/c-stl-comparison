#!/usr/bin/env python3
"""Update README.md Characteristics and Containers tables from JSON files.

Reads lib-features.json  (libraries -> characteristics -> value)
and  lib-containers.json (libraries -> containers    -> value)
and regenerates all matching tables in the ## Synthesis section of README.md.

Values stored as  "X* [some long explanation]"  in the JSON are written into
the table as just  "X*"  (the bracketed annotation is stripped so that the
table cells stay compact).  The full value is preserved in the JSON files.
"""

import argparse
import json
import pathlib
import re
import sys

# Canonical left-to-right order of libraries in every table column.
LIBS_ORDER = ["STL", "M*LIB", "STC", "CMC", "CTL", "CollecC", "CC", "GLIB", "STB_DS", "KLIB", "CCC"]


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def strip_annotation(value: str) -> str:
    """Remove trailing  ' [...]'  annotation from a cell value."""
    return re.sub(r"\s*\[.*?\]", "", value).strip()


def parse_row_names(block_lines: list[str]) -> list[str]:
    """Return the first-column text of every data row (skip header + separator)."""
    names = []
    for line in block_lines[2:]:          # index 0 = header, 1 = separator
        if not line.startswith("|"):
            break
        parts = [p.strip() for p in line.strip().strip("|").split("|")]
        if parts:
            names.append(parts[0])
    return names


def format_table(header_label: str, row_names: list[str],
                 lib_data: dict, libs: list[str]) -> str:
    """Build a markdown table string from JSON data."""
    header_row = [header_label] + libs
    data_rows = []
    for name in row_names:
        row = [name]
        for lib in libs:
            raw = lib_data.get(lib, {}).get(name, "?")
            row.append(strip_annotation(raw))
        data_rows.append(row)

    all_rows = [header_row] + data_rows
    widths = [max(len(r[i]) for r in all_rows) for i in range(len(libs) + 1)]

    def fmt(row: list[str]) -> str:
        return "| " + " | ".join(cell.ljust(widths[i]) for i, cell in enumerate(row)) + " |"

    sep = "|" + "|".join("-" * (w + 2) for w in widths) + "|"
    lines = [fmt(header_row), sep] + [fmt(r) for r in data_rows]
    return "\n".join(lines)


# ---------------------------------------------------------------------------
# README patching
# ---------------------------------------------------------------------------

# Matches a complete markdown table block whose first column header is either
# "Characteristics" or "Containers".  The block spans from the header line
# through all consecutive lines starting with "|".
TABLE_RE = re.compile(
    r"(\| (?:Characteristics|Containers)[^\n]*\n"   # header line
    r"\|[-| ]+\n"                                    # separator line
    r"(?:\|[^\n]*\n)*)",                             # data lines
    re.MULTILINE,
)


def make_replacer(features_libs: dict, containers_libs: dict, libs: list[str]):
    """Return a replacement callable for re.sub."""
    def replace(match: re.Match) -> str:
        block = match.group(1)
        block_lines = block.splitlines()
        first_line = block_lines[0]

        if first_line.startswith("| Characteristics"):
            lib_data = features_libs
            header_label = "Characteristics"
        elif first_line.startswith("| Containers"):
            lib_data = containers_libs
            header_label = "Containers"
        else:
            return match.group(0)  # leave unchanged

        row_names = parse_row_names(block_lines)
        new_table = format_table(header_label, row_names, lib_data, libs)
        # Preserve the trailing newline that the original block had.
        if block.endswith("\n"):
            new_table += "\n"
        return new_table

    return replace


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main() -> int:
    parser = argparse.ArgumentParser(
        description=(
            "Update README.md Characteristics and Containers tables "
            "from lib-features.json and lib-containers.json."
        )
    )
    parser.add_argument(
        "--readme",
        default="README.md",
        help="Path to README file to update (default: README.md).",
    )
    parser.add_argument(
        "--features",
        default="lib-features.json",
        help="Path to lib-features.json (default: lib-features.json).",
    )
    parser.add_argument(
        "--containers",
        default="lib-containers.json",
        help="Path to lib-containers.json (default: lib-containers.json).",
    )
    args = parser.parse_args()

    readme_path     = pathlib.Path(args.readme).resolve()
    features_path   = pathlib.Path(args.features).resolve()
    containers_path = pathlib.Path(args.containers).resolve()

    for p in (readme_path, features_path, containers_path):
        if not p.exists():
            print(f"error: file not found: {p}", file=sys.stderr)
            return 1

    with features_path.open(encoding="utf-8") as f:
        features_libs: dict = json.load(f)["libraries"]

    with containers_path.open(encoding="utf-8") as f:
        containers_libs: dict = json.load(f)["libraries"]

    readme_text = readme_path.read_text(encoding="utf-8")
    updated = TABLE_RE.sub(
        make_replacer(features_libs, containers_libs, LIBS_ORDER),
        readme_text,
    )

    if updated == readme_text:
        print("README.md: no tables were changed.")
    else:
        readme_path.write_text(updated, encoding="utf-8")
        # Count how many table blocks were replaced
        n = len(TABLE_RE.findall(readme_text))
        print(f"README.md: updated {n} table(s).")

    return 0


if __name__ == "__main__":
    sys.exit(main())
