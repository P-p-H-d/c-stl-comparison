#!/usr/bin/env python3
"""Generate lib-project-lines.json from projects in external/.

For each direct subdirectory of external/, this script computes four line-count
categories:
- source code
- test suite
- examples
- documentation

Rules are implemented from the repository specification.
"""

from __future__ import annotations

import argparse
import datetime as dt
import json
from pathlib import Path


SOURCE_DIR_NAMES = {"src", "source", "sources", "include", "headers", "header"}
TEST_DIR_NAMES = {"tests", "test", "check", "checks"}
EXAMPLE_DIR_NAMES = {"examples", "example"}
DOC_DIR_NAMES = {"doc", "docs", "documentation", "documentations"}

TEST_EXCLUDED_SUBDIR_NAMES = {"perf", "benchmark", "bench"}
DOC_ROOT_MD_EXCLUDE = {"CODE_OF_CONDUCT.md", "CONTRIBUTING.md", "SECURITY.md"}


def line_count(text: str) -> int:
    if not text:
        return 0
    return text.count("\n") + (0 if text.endswith("\n") else 1)


def looks_like_text_file(path: Path) -> bool:
    try:
        data = path.read_bytes()
    except OSError:
        return False

    if b"\x00" in data:
        return False

    if not data:
        return True

    try:
        data.decode("utf-8")
        return True
    except UnicodeDecodeError:
        # Fallback heuristic for mostly printable content.
        printable = 0
        for byte in data:
            if byte in (9, 10, 13) or 32 <= byte <= 126:
                printable += 1
        return printable / len(data) >= 0.9


def read_text_for_count(path: Path) -> str:
    return path.read_text(encoding="utf-8", errors="replace")


def gather_files_recursive(dir_path: Path) -> set[Path]:
    files: set[Path] = set()
    if not dir_path.is_dir():
        return files
    for file_path in dir_path.rglob("*"):
        if file_path.is_file():
            files.add(file_path)
    return files


def collect_source_files(lib_dir: Path) -> set[Path]:
    files: set[Path] = set()

    # All *.h and *.c files at root.
    for p in lib_dir.iterdir():
        if p.is_file() and p.suffix.lower() in {".h", ".c"}:
            files.add(p)

    # All *.h and *.c files in selected named directories.
    for p in lib_dir.iterdir():
        if p.is_dir() and p.name.lower() in SOURCE_DIR_NAMES:
            for child in gather_files_recursive(p):
                if child.suffix.lower() in {".h", ".c"}:
                    files.add(child)

    # All *.h and *.c files in the directory named like the library.
    same_name_dir = lib_dir / lib_dir.name
    if same_name_dir.is_dir():
        for child in gather_files_recursive(same_name_dir):
            if child.suffix.lower() in {".h", ".c"}:
                files.add(child)

    return files


def collect_test_files(lib_dir: Path) -> set[Path]:
    files: set[Path] = set()

    # All text files in tests/test/check/checks directories.
    for p in lib_dir.iterdir():
        if p.is_dir() and p.name.lower() in TEST_DIR_NAMES:
            for child in gather_files_recursive(p):
                if any(part.lower() in TEST_EXCLUDED_SUBDIR_NAMES for part in child.parts):
                    continue
                if looks_like_text_file(child):
                    files.add(child)

    # All test_*.c files at root.
    for p in lib_dir.iterdir():
        if p.is_file() and p.suffix.lower() == ".c" and p.name.lower().startswith("test_"):
            files.add(p)

    return files


def collect_example_files(lib_dir: Path) -> set[Path]:
    files: set[Path] = set()
    for p in lib_dir.iterdir():
        if p.is_dir() and p.name.lower() in EXAMPLE_DIR_NAMES:
            for child in gather_files_recursive(p):
                if child.suffix.lower() in {".h", ".c"}:
                    files.add(child)
    return files


def collect_documentation_files(lib_dir: Path) -> set[Path]:
    files: set[Path] = set()

    # All text files in documentation directories.
    for p in lib_dir.iterdir():
        if p.is_dir() and p.name.lower() in DOC_DIR_NAMES:
            for child in gather_files_recursive(p):
                if looks_like_text_file(child):
                    files.add(child)

    # All .md files at root except excluded names.
    excluded_upper = {name.upper() for name in DOC_ROOT_MD_EXCLUDE}
    for p in lib_dir.iterdir():
        if p.is_file() and p.suffix.lower() == ".md" and p.name.upper() not in excluded_upper:
            files.add(p)

    # README file at root, with or without extension.
    for p in lib_dir.iterdir():
        if not p.is_file():
            continue
        stem_upper = p.stem.upper()
        name_upper = p.name.upper()
        if stem_upper == "README" or name_upper == "README":
            files.add(p)

    return files


def count_lines(files: set[Path]) -> int:
    total = 0
    for p in sorted(files):
        try:
            total += line_count(read_text_for_count(p))
        except OSError:
            continue
    return total


def build_data(external_dir: Path) -> dict[str, object]:
    libraries: dict[str, dict[str, int]] = {}

    for lib_dir in sorted(external_dir.iterdir()):
        if not lib_dir.is_dir():
            continue

        source_files = collect_source_files(lib_dir)
        test_files = collect_test_files(lib_dir)
        example_files = collect_example_files(lib_dir)
        documentation_files = collect_documentation_files(lib_dir)

        libraries[lib_dir.name] = {
            "source": count_lines(source_files),
            "tests": count_lines(test_files),
            "examples": count_lines(example_files),
            "documentation": count_lines(documentation_files),
        }

    return {
        "Date of analysis": dt.date.today().isoformat(),
        "libraries": libraries,
    }


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate lib-project-lines.json")
    parser.add_argument(
        "--external-dir",
        default="external",
        help="Path to the external directory (default: external)",
    )
    parser.add_argument(
        "--output",
        default="lib-project-lines.json",
        help="Output JSON file path (default: lib-project-lines.json)",
    )
    args = parser.parse_args()

    external_dir = Path(args.external_dir)
    if not external_dir.is_dir():
        raise SystemExit(f"External directory not found: {external_dir}")

    data = build_data(external_dir)

    output_path = Path(args.output)
    output_path.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")
    print(f"Written {output_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
