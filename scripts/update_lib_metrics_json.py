#!/usr/bin/env python3
"""Generate lib-metrics.json from source files and build outputs.

This script extracts, per program and per library:
- number of characters
- number of line of codes
- number of workarounds
- binary size (bytes)
- compilation time (seconds)

Binary size and compilation time are collected from make measure-size output
and time.log, using the same parsing logic as the README update scripts.
"""

import argparse
import datetime as dt
import json
import pathlib
import re
import subprocess
import sys
from decimal import Decimal
from typing import Any

PROGRAMS = [
    "array-int",
    "array-str",
    "array-mpz",
    "umap-int",
    "umap-str",
    "umap-mpz",
]

LIB_TO_SUFFIX = {
    "CC": "CC",
    "CCC": "ccc",
    "CMC": "cmc",
    "CollecC": "collectionsC",
    "CTL": "ctl",
    "GLIB": "glib",
    "KLIB": "klib",
    "M*LIB": "mlib",
    "OpenCSTL": "opencstl",
    "STB_DS": "stb",
    "STC": "stc",
    "STL": "stl",
}

SUFFIX_TO_LABEL = {
    "CC": "CC",
    "ccc": "CCC",
    "cmc": "CMC",
    "collectionsC": "CollecC",
    "ctl": "CTL",
    "glib": "GLIB",
    "klib": "KLIB",
    "mlib": "M*LIB",
    "opencstl": "OpenCSTL",
    "stb": "STB_DS",
    "stc": "STC",
    "stl": "STL",
}

SIZE_LINE_PATTERN = re.compile(r"^(?P<size>\d+) bytes for (?P<exe>.+)\.exe$")
COMMAND_PATTERN = re.compile(r'^\s*Command being timed: "(?P<command>.*)"$')
USER_TIME_PATTERN = re.compile(r"^\s*User time \(seconds\): (?P<time>[0-9]+(?:\.[0-9]+)?)$")
SYSTEM_TIME_PATTERN = re.compile(r"^\s*System time \(seconds\): (?P<time>[0-9]+(?:\.[0-9]+)?)$")
OUTPUT_EXE_PATTERN = re.compile(r'-o (?P<exe>[^\s"]+\.exe)')


def line_count(content: str) -> int:
    if not content:
        return 0
    return content.count("\n") + (0 if content.endswith("\n") else 1)


def byte_count(content: str) -> int:
    return len(content.encode("utf-8"))


def workaround_count(content: str) -> int:
    return len(re.findall(r"WORKAROUND", content))


def source_file_for_lib(repo_root: pathlib.Path, program: str, library: str) -> pathlib.Path | None:
    suffix = LIB_TO_SUFFIX.get(library)
    if suffix is None:
        return None

    container_prefix = program.split("-", 1)[0]
    c_path = repo_root / program / f"{container_prefix}-{suffix}.c"
    if c_path.exists():
        return c_path

    cc_path = repo_root / program / f"{container_prefix}-{suffix}.cc"
    if cc_path.exists():
        return cc_path

    return None


def run_measure_size(repo_root: pathlib.Path) -> str:
    completed = subprocess.run(
        ["make", "measure-size"],
        cwd=repo_root,
        text=True,
        capture_output=True,
    )
    if completed.returncode != 0:
        if completed.stderr:
            print(completed.stderr, file=sys.stderr, end="")
        raise RuntimeError("make measure-size failed")
    return completed.stdout


def parse_measure_size_output(output: str) -> dict[str, dict[str, int]]:
    sizes: dict[str, dict[str, int]] = {}
    for line in output.splitlines():
        match = SIZE_LINE_PATTERN.match(line.strip())
        if match is None:
            continue

        size = int(match.group("size"))
        exe = match.group("exe")
        if "-" not in exe:
            continue
        program, suffix = exe.rsplit("-", 1)
        if program not in PROGRAMS:
            continue

        library = SUFFIX_TO_LABEL.get(suffix)
        if library is None:
            continue

        sizes.setdefault(program, {})[library] = size

    return sizes


def parse_time_log(content: str) -> dict[str, dict[str, float]]:
    times: dict[str, dict[str, float]] = {}
    command: str | None = None
    user_time: Decimal | None = None

    for line in content.splitlines():
        command_match = COMMAND_PATTERN.match(line)
        if command_match is not None:
            command = command_match.group("command")
            user_time = None
            continue

        if command is None:
            continue

        user_match = USER_TIME_PATTERN.match(line)
        if user_match is not None:
            user_time = Decimal(user_match.group("time"))
            continue

        system_match = SYSTEM_TIME_PATTERN.match(line)
        if system_match is None or user_time is None:
            continue

        output_match = OUTPUT_EXE_PATTERN.search(command)
        if output_match is None:
            command = None
            user_time = None
            continue

        exe = output_match.group("exe")
        exe_base = exe[:-4]
        if "-" not in exe_base:
            command = None
            user_time = None
            continue

        program, suffix = exe_base.rsplit("-", 1)
        if program not in PROGRAMS:
            command = None
            user_time = None
            continue

        library = SUFFIX_TO_LABEL.get(suffix)
        if library is None:
            command = None
            user_time = None
            continue

        total_time = float(user_time + Decimal(system_match.group("time")))

        # If multiple measurements exist, keep the fastest one.
        previous = times.setdefault(program, {}).get(library)
        if previous is None or total_time < previous:
            times[program][library] = total_time

        command = None
        user_time = None

    return times


def build_source_metrics(repo_root: pathlib.Path, libraries: list[str]) -> dict[str, dict[str, dict[str, Any]]]:
    result: dict[str, dict[str, dict[str, Any]]] = {}

    for program in PROGRAMS:
        result[program] = {}
        for library in libraries:
            entry: dict[str, Any] = {
                "number of characters": None,
                "number of line of codes": None,
                "number of workarounds": None,
                "binary size (bytes)": None,
                "compilation time (seconds)": None,
            }

            source_path = source_file_for_lib(repo_root, program, library)
            if source_path is not None:
                content = source_path.read_text(encoding="utf-8")
                entry["number of characters"] = byte_count(content)
                entry["number of line of codes"] = line_count(content)
                entry["number of workarounds"] = workaround_count(content)

            result[program][library] = entry

    return result


def merge_size_and_time(
    metrics: dict[str, dict[str, dict[str, Any]]],
    sizes: dict[str, dict[str, int]],
    times: dict[str, dict[str, float]],
) -> None:
    for program, by_lib in sizes.items():
        if program not in metrics:
            continue
        for library, size in by_lib.items():
            if library in metrics[program]:
                metrics[program][library]["binary size (bytes)"] = size

    for program, by_lib in times.items():
        if program not in metrics:
            continue
        for library, seconds in by_lib.items():
            if library in metrics[program]:
                metrics[program][library]["compilation time (seconds)"] = round(seconds, 2)


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Generate lib-metrics.json from source files, size output, and time.log."
    )
    parser.add_argument(
        "--repo-root",
        default=".",
        help="Path to repository root (default: current directory).",
    )
    parser.add_argument(
        "--output",
        default="lib-metrics.json",
        help="Output JSON file (default: lib-metrics.json).",
    )
    parser.add_argument(
        "--measure-size-log",
        help="Optional file containing output of make measure-size.",
    )
    parser.add_argument(
        "--time-log",
        default="time.log",
        help="Path to time.log file (default: time.log).",
    )
    args = parser.parse_args()

    repo_root = pathlib.Path(args.repo_root).resolve()
    output_path = pathlib.Path(args.output).resolve()
    time_log_path = pathlib.Path(args.time_log).resolve()

    libraries = sorted(LIB_TO_SUFFIX.keys(), key=str.casefold)

    try:
        metrics = build_source_metrics(repo_root, libraries)
    except OSError as exc:
        print(f"error: failed reading source files: {exc}", file=sys.stderr)
        return 1

    ran_measure_size = False
    measure_size_output: str | None = None

    if args.measure_size_log:
        try:
            measure_size_output = pathlib.Path(args.measure_size_log).read_text(encoding="utf-8")
        except OSError as exc:
            print(f"error: cannot read {args.measure_size_log}: {exc}", file=sys.stderr)
            return 1
    else:
        try:
            measure_size_output = run_measure_size(repo_root)
            ran_measure_size = True
        except RuntimeError as exc:
            print(f"error: {exc}", file=sys.stderr)
            return 1

    if not time_log_path.exists():
        if not ran_measure_size:
            try:
                _ = run_measure_size(repo_root)
                ran_measure_size = True
            except RuntimeError as exc:
                print(f"error: {exc}", file=sys.stderr)
                return 1

    if measure_size_output is None:
        measure_size_output = ""

    sizes = parse_measure_size_output(measure_size_output)

    try:
        time_log_text = time_log_path.read_text(encoding="utf-8")
    except OSError as exc:
        print(f"error: cannot read {time_log_path}: {exc}", file=sys.stderr)
        return 1

    times = parse_time_log(time_log_text)
    merge_size_and_time(metrics, sizes, times)

    payload = {
        "Date of analysis": dt.date.today().isoformat(),
        "programs": metrics,
    }

    try:
        output_path.write_text(json.dumps(payload, indent=2, ensure_ascii=True) + "\n", encoding="utf-8")
    except OSError as exc:
        print(f"error: cannot write {output_path}: {exc}", file=sys.stderr)
        return 1

    print(f"wrote {output_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())