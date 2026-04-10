#!/usr/bin/env python3
import argparse
import pathlib
import re
import sys

LIB_TO_SUFFIX = {
    "STL": "stl",
    "M*LIB": "mlib",
    "STC": "stc",
    "CMC": "cmc",
    "CTL": "ctl",
    "CollecC": "collectionsC",
    "CC": "CC",
    "GLIB": "glib",
    "STB_DS": "stb",
    "KLIB": "klib",
}

TABLE_PREFIX_TO_DIR_PREFIX = {
    "Array": "array",
    "UMap": "umap",
}

TABLE_PATTERN = re.compile(
    r"(^\| (Array|UMap)-(Int|Str|mpz) programs.*\n"
    r"\|[-| ]+\n"
    r"\| number of characters.*\n"
    r"\| number of line of codes.*\n"
    r"\| number of workarounds.*$)",
    re.MULTILINE,
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


def file_for_lib(
    base: pathlib.Path, container_dir: str, container_prefix: str, lib_name: str
) -> pathlib.Path | None:
    suffix = LIB_TO_SUFFIX.get(lib_name)
    if suffix is None:
        return None
    c_file = base / container_dir / f"{container_prefix}-{suffix}.c"
    if c_file.exists():
        return c_file
    cc_file = base / container_dir / f"{container_prefix}-{suffix}.cc"
    if cc_file.exists():
        return cc_file
    return None


def line_count(content: str) -> int:
    if not content:
        return 0
    return content.count("\n") + (0 if content.endswith("\n") else 1)


def byte_count(content: str) -> int:
    return len(content.encode("utf-8"))


def workaround_count(content: str) -> int:
    return len(re.findall(r"WORKAROUND", content))


def update_table(table_text: str, repo_root: pathlib.Path) -> str:
    lines = table_text.splitlines()
    header_cells = parse_row(lines[0])
    table_match = re.match(r"(Array|UMap)-(Int|Str|mpz) programs", header_cells[0])
    if not table_match:
        return table_text

    table_prefix = table_match.group(1)
    table_kind = table_match.group(2)
    container_dir = f"{TABLE_PREFIX_TO_DIR_PREFIX[table_prefix]}-{table_kind.lower()}"
    container_prefix = TABLE_PREFIX_TO_DIR_PREFIX[table_prefix]
    libraries = header_cells[1:]

    chars_row = ["number of characters"]
    lines_row = ["number of line of codes"]
    workarounds_row = ["number of workarounds"]

    for lib in libraries:
        source_file = file_for_lib(
            repo_root, container_dir, container_prefix, lib
        )
        if source_file is None:
            chars_row.append("NA")
            lines_row.append("NA")
            workarounds_row.append("NA")
            continue

        content = source_file.read_text(encoding="utf-8")
        chars_row.append(str(byte_count(content)))
        lines_row.append(str(line_count(content)))
        workarounds_row.append(str(workaround_count(content)))

    return format_table([header_cells, chars_row, lines_row, workarounds_row])


def main() -> int:
    parser = argparse.ArgumentParser(
        description=(
            "Update README Array/UMap metrics tables "
            "(chars, lines, workarounds)."
        )
    )
    parser.add_argument(
        "--readme",
        default="README.md",
        help="Path to README file to update (default: README.md).",
    )
    args = parser.parse_args()

    readme_path = pathlib.Path(args.readme).resolve()
    repo_root = readme_path.parent

    try:
        text = readme_path.read_text(encoding="utf-8")
    except OSError as exc:
        print(f"error: cannot read {readme_path}: {exc}", file=sys.stderr)
        return 1

    replacements = 0

    def repl(match: re.Match[str]) -> str:
        nonlocal replacements
        replacements += 1
        return update_table(match.group(1), repo_root)

    new_text = TABLE_PATTERN.sub(repl, text)

    if replacements == 0:
        print(
            "error: no matching Array/UMap metrics tables found",
            file=sys.stderr,
        )
        return 2

    if new_text != text:
        readme_path.write_text(new_text, encoding="utf-8")
        print(f"updated {readme_path} ({replacements} tables)")
    else:
        print(f"no changes needed in {readme_path}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
