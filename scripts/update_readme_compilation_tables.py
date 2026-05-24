#!/usr/bin/env python3
import argparse
import pathlib
import re
import subprocess
import sys
from collections import defaultdict
from decimal import Decimal


COMMAND_PATTERN = re.compile(r'^\s*Command being timed: "(?P<command>.*)"$')
USER_TIME_PATTERN = re.compile(r'^\s*User time \(seconds\): (?P<time>[0-9]+(?:\.[0-9]+)?)$')
SYSTEM_TIME_PATTERN = re.compile(r'^\s*System time \(seconds\): (?P<time>[0-9]+(?:\.[0-9]+)?)$')
OUTPUT_EXE_PATTERN = re.compile(r'-o (?P<exe>[^\s"]+\.exe)')
TABLE_HEADER_PATTERN = re.compile(r'^\| (array|umap)-(int|str|mpz) compilation \| time \|$')

LABEL_ORDER = [
    'STC',
    'GLIB',
    'M*LIB',
    'CC',
    'CTL',
    'KLIB',
    'CollecC',
    'STL',
    'CMC',
]

SUFFIX_TO_LABEL = {
    'CC': 'CC',
    'ccc': 'CCC',
    'cmc': 'CMC',
    'collectionsC': 'CollecC',
    'ctl': 'CTL',
    'glib': 'GLIB',
    'klib': 'KLIB',
    'mlib': 'M*LIB',
    'stb': 'STB_DS',
    'stc': 'STC',
    'stl': 'STL',
}


def parse_row(line: str) -> list[str]:
    return [cell.strip() for cell in line.strip().strip('|').split('|')]


def format_table(rows: list[list[str]]) -> str:
    widths = [max(len(row[i]) for row in rows) for i in range(len(rows[0]))]

    def fmt_row(row: list[str]) -> str:
        return '| ' + ' | '.join(cell.ljust(widths[i]) for i, cell in enumerate(row)) + ' |'

    header = fmt_row(rows[0])
    separator = '|' + '|'.join('-' * (width + 2) for width in widths) + '|'
    body = '\n'.join(fmt_row(row) for row in rows[1:])
    return '\n'.join([header, separator, body])


def parse_time_log(content: str) -> dict[str, list[tuple[str, Decimal, int]]]:
    table_times: dict[str, list[tuple[str, Decimal, int]]] = defaultdict(list)
    command: str | None = None
    user_time: Decimal | None = None
    command_index = 0

    for line in content.splitlines():
        command_match = COMMAND_PATTERN.match(line)
        if command_match is not None:
            command = command_match.group('command')
            user_time = None
            continue

        if command is None:
            continue

        user_match = USER_TIME_PATTERN.match(line)
        if user_match is not None:
            user_time = Decimal(user_match.group('time'))
            continue

        system_match = SYSTEM_TIME_PATTERN.match(line)
        if system_match is None or user_time is None:
            continue

        output_match = OUTPUT_EXE_PATTERN.search(command)
        if output_match is None:
            command = None
            user_time = None
            continue

        exe = output_match.group('exe')
        exe_base = exe[:-4]
        if '-' not in exe_base:
            command = None
            user_time = None
            continue

        prefix, suffix = exe_base.rsplit('-', 1)
        if prefix not in {
            'array-int',
            'array-str',
            'array-mpz',
            'umap-int',
            'umap-str',
            'umap-mpz',
        }:
            command = None
            user_time = None
            continue

        label = SUFFIX_TO_LABEL.get(suffix, suffix)
        total_time = user_time + Decimal(system_match.group('time'))
        table_times[prefix].append((label, total_time, command_index))
        command_index += 1
        command = None
        user_time = None

    return table_times


def update_compilation_table(
    table_text: str, table_times: dict[str, list[tuple[str, Decimal, int]]]
) -> str:
    lines = table_text.splitlines()
    header_cells = parse_row(lines[0])
    header_match = re.match(r'(array|umap)-(int|str|mpz) compilation', header_cells[0])
    if not header_match:
        return table_text

    prefix = f'{header_match.group(1)}-{header_match.group(2)}'
    rows = table_times.get(prefix, [])
    rows = sorted(rows, key=lambda item: (item[1], item[2], LABEL_ORDER.index(item[0]) if item[0] in LABEL_ORDER else len(LABEL_ORDER)))

    body_rows = [[label, f'{time:.2f}'] for label, time, _ in rows]
    if not body_rows:
        body_rows = [['NA', 'NA']]

    return format_table([header_cells, *body_rows])


def update_readme(text: str, table_times: dict[str, list[tuple[str, Decimal, int]]]) -> tuple[str, int]:
    lines = text.splitlines()
    updated_lines: list[str] = []
    replacements = 0
    i = 0

    while i < len(lines):
        line = lines[i]
        if TABLE_HEADER_PATTERN.match(line) and i + 1 < len(lines) and lines[i + 1].startswith('|-'):
            table_start = i
            table_end = i + 2
            while table_end < len(lines) and lines[table_end].startswith('|'):
                table_end += 1

            table_text = '\n'.join(lines[table_start:table_end])
            updated_lines.append(update_compilation_table(table_text, table_times))
            replacements += 1
            i = table_end
            continue

        updated_lines.append(line)
        i += 1

    return '\n'.join(updated_lines), replacements


def main() -> int:
    parser = argparse.ArgumentParser(
        description='Read time.log and update README compilation tables.'
    )
    parser.add_argument(
        '--readme',
        default='README.md',
        help='Path to README file to update (default: README.md).',
    )
    parser.add_argument(
        '--time-log',
        default='time.log',
        help='Path to time.log file to read (default: time.log).',
    )
    args = parser.parse_args()

    readme_path = pathlib.Path(args.readme).resolve()
    time_log_path = pathlib.Path(args.time_log).resolve()

    try:
        readme_text = readme_path.read_text(encoding='utf-8')
    except OSError as exc:
        print(f'error: cannot read {readme_path}: {exc}', file=sys.stderr)
        return 1

    if not time_log_path.exists():
        print(
            f'{time_log_path} not found; running "make measure-size" to generate it...',
            file=sys.stderr,
        )
        try:
            subprocess.run(
                ['make', 'measure-size'],
                cwd=readme_path.parent,
                check=True,
            )
        except (OSError, subprocess.CalledProcessError) as exc:
            print(f'error: failed to run make measure-size: {exc}', file=sys.stderr)
            return 1

    try:
        time_log_text = time_log_path.read_text(encoding='utf-8')
    except OSError as exc:
        print(f'error: cannot read {time_log_path}: {exc}', file=sys.stderr)
        return 1

    table_times = parse_time_log(time_log_text)
    new_text, replacements = update_readme(readme_text, table_times)

    if replacements == 0:
        print('error: no matching compilation tables found', file=sys.stderr)
        return 2

    if new_text != readme_text:
        readme_path.write_text(
            new_text + ('\n' if readme_text.endswith('\n') else ''),
            encoding='utf-8',
        )
        print(f'updated {readme_path} ({replacements} tables)')
    else:
        print(f'no changes needed in {readme_path}')

    return 0


if __name__ == '__main__':
    raise SystemExit(main())