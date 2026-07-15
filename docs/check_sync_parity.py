"""
Self-check a single language branch for sync issues.

Run from ``docs/``:

    python check_sync_parity.py          # check only
    python check_sync_parity.py --fix    # check + auto-fix indentation issues

This script does NOT compare against the English source --- every language branch
is self-contained and should validate independently.

Checks performed
================
1. Arduino Cloud iframes       --- any ``create.arduino.cc/editor`` iframes left?
2. Unreachable literalinclude  --- ``.. literalinclude::`` pointing to missing _code/ files
3. Unused _code/ files         --- .ino files never referenced by any literalinclude
4. Heading underline length    --- RST requires underline >= heading text
5. Orphan RST files            --- files under source/ not linked in any toctree
6. Broken toctree references   --- toctree entries pointing to non-existent files
7. Indented / merged literalinclude --- ``--fix`` auto-repairs: de-indent blocks,
                                        split merged lines, add blank line spacing
"""

import io
import os
import re
import sys
import glob

# Ensure Unicode output works on Windows with GBK terminals
if hasattr(sys.stdout, "buffer"):
    sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding="utf-8", errors="replace")

DOCS_DIR = os.path.dirname(os.path.abspath(__file__))
SOURCE = os.path.join(DOCS_DIR, "source")
CODE_DIR = os.path.join(SOURCE, "_code")

FIX_MODE = "--fix" in sys.argv


# ==============================================================================
# Helpers
# ==============================================================================

def rst_files():
    """Yield (rel_path, abs_path) for every .rst under source/ excluding _code/ and build/."""
    for abs_path in glob.glob(os.path.join(SOURCE, "**", "*.rst"), recursive=True):
        rel = os.path.relpath(abs_path, SOURCE)
        parts = rel.replace("\\", "/").split("/")
        if "_code" in parts or "build" in parts:
            continue
        yield rel, abs_path


def read_file(filepath):
    try:
        with open(filepath, "r", encoding="utf-8") as f:
            return f.read()
    except Exception:
        return ""


def read_lines(filepath):
    try:
        with open(filepath, "r", encoding="utf-8") as f:
            return f.readlines()
    except Exception:
        return []


def extract_toctree_entries(filepath):
    """Return list of doc names referenced in all toctree blocks."""
    entries = []
    lines = read_lines(filepath)
    in_toc = False
    for line in lines:
        if line.startswith(".. toctree::"):
            in_toc = True
            continue
        if in_toc:
            if line.strip() == "":
                continue
            if not line.startswith(" "):
                in_toc = False
                continue
            stripped = line.strip()
            if stripped.startswith(":") or stripped.startswith(".."):
                continue
            entry = re.sub(r"\s*<.*>", "", stripped)
            entries.append(entry)
    return entries


def extract_anchors(filepath):
    """Return set of ``.. _anchor_name:`` labels defined in the file."""
    return set(re.findall(r"\.\. _([a-zA-Z0-9_]+):", read_file(filepath)))


def _toc_line_has_self(raw_content, entry):
    """Check whether *entry* appeared with a ``<self>`` marker in the raw RST."""
    for line in raw_content.split("\n"):
        stripped = line.strip()
        if stripped == entry or stripped.startswith(entry + " "):
            if "<self>" in stripped:
                return True
    return False


def extract_literalincludes(filepath):
    """Return list of _code/ paths referenced by ``.. literalinclude::``."""
    paths = []
    for m in re.finditer(r"\.\. literalinclude::\s+(/_code/\S+)", read_file(filepath)):
        paths.append(m.group(1))
    return paths


# ==============================================================================
# Checks (report-only)
# ==============================================================================

def check_arduino_iframes():
    """1. Find remaining Arduino Cloud editor iframes."""
    issues = []
    for rel, abs_path in rst_files():
        content = read_file(abs_path)
        for i, line in enumerate(content.split("\n"), 1):
            if "create.arduino.cc/editor" in line and "<iframe" in line:
                issues.append(f"  {rel}:{i}  Arduino Cloud iframe still present")
    return issues


def check_missing_code():
    """2. literalinclude paths that don't exist on disk."""
    issues = []
    for rel, abs_path in rst_files():
        for literal_path in extract_literalincludes(abs_path):
            disk_path = os.path.join(SOURCE, literal_path.lstrip("/"))
            if not os.path.exists(disk_path):
                issues.append(f"  {rel}  literalinclude -> {literal_path}  (file missing)")
    return issues


def check_unused_code():
    """3. _code/ files never referenced by any literalinclude."""
    referenced = set()
    for _, abs_path in rst_files():
        for lp in extract_literalincludes(abs_path):
            referenced.add(os.path.basename(lp))

    unused = []
    if os.path.isdir(CODE_DIR):
        for fname in sorted(os.listdir(CODE_DIR)):
            if fname not in referenced:
                unused.append(f"  _code/{fname}  (not referenced by any RST file)")
    return unused


def check_heading_underlines():
    """4. Heading underline must be >= heading text length."""
    issues = []
    for rel, abs_path in rst_files():
        lines = read_lines(abs_path)
        for i, line in enumerate(lines):
            stripped = line.rstrip("\n\r")
            if stripped and len(stripped) >= 2:
                char = stripped[0]
                if char in "=-~^" and all(c == char for c in stripped):
                    if i > 0:
                        heading = lines[i - 1].rstrip("\n\r")
                        if len(stripped) < len(heading):
                            issues.append(
                                f"  {rel}:{i + 1}  underline ({len(stripped)})"
                                f" < heading ({len(heading)}): {heading[:60]}"
                            )
    return issues


def check_orphan_files():
    """5. RST files not referenced in ANY toctree."""
    referenced_stems = set()
    for _, abs_path in rst_files():
        for entry in extract_toctree_entries(abs_path):
            entry_dir = os.path.dirname(abs_path)
            stem = os.path.normpath(
                os.path.join(os.path.relpath(entry_dir, SOURCE), entry)
            ).replace("\\", "/")
            referenced_stems.add(stem)

    orphans = []
    ROOT_DOCS = {"index", "download_the_code", "thank_learning"}
    for rel, _ in rst_files():
        stem = os.path.splitext(rel.replace("\\", "/"))[0]
        if stem in referenced_stems:
            continue
        if stem in ROOT_DOCS:
            continue
        orphans.append(f"  {rel}")
    return orphans


def check_broken_toctree():
    """6. Toctree entries that point to non-existent files."""
    issues = []
    for rel, abs_path in rst_files():
        entry_dir = os.path.dirname(abs_path)
        raw_content = read_file(abs_path)
        for entry in extract_toctree_entries(abs_path):
            if _toc_line_has_self(raw_content, entry):
                continue
            resolved = os.path.normpath(
                os.path.join(os.path.relpath(entry_dir, SOURCE), entry)
            )
            rst_path = os.path.join(SOURCE, resolved + ".rst")
            alt = os.path.join(entry_dir, entry + ".rst")
            if not os.path.isfile(rst_path) and not os.path.isfile(alt):
                issues.append(f"  {rel}  toctree entry -> {entry}  (file not found)")
    return issues


# ==============================================================================
# Check #7 --- indented / merged literalinclude  (supports --fix)
# ==============================================================================

# Pattern: ".. literalinclude:: /_code/XX.ino   :language: cpp" on one line
_MERGE_RE = re.compile(
    r'^(\.\. literalinclude:: /_code/\S+\.\S+)(   :language: cpp)$',
    re.MULTILINE
)
_MERGE_REPLACEMENT = r'\1\n\2'


# Pattern: blank line between ``.. literalinclude::`` and its ``:options:``
_BLANK_BEFORE_OPTION_RE = re.compile(
    r'(\.\. literalinclude:: /_code/\S+)\n\n(\s+:language:)'
)


def check_indented_literalinclude():
    """7. Detect indented literalinclude blocks, merged lines, blank-line gaps."""
    issues = []
    for rel, abs_path in rst_files():
        content = read_file(abs_path)
        for i, line in enumerate(content.split("\n"), 1):
            if not (line.startswith(" ") or line.startswith("\t")):
                continue
            if ".. literalinclude::" in line:
                issues.append(f"  {rel}:{i}  literalinclude is indented")
        for m in _MERGE_RE.finditer(content):
            lineno = content[:m.start()].count("\n") + 1
            issues.append(f"  {rel}:{lineno}  literalinclude merged with :language: on one line")
        for m in _BLANK_BEFORE_OPTION_RE.finditer(content):
            lineno = content[:m.start()].count("\n") + 1
            issues.append(f"  {rel}:{lineno}  blank line between literalinclude and its options")
    return issues


def fix_literalinclude_issues():
    """Auto-fix indented blocks, merged lines, and blank-line spacing.

    Returns the number of files modified.
    """
    fixed_count = 0

    for rel, filepath in rst_files():
        with open(filepath, "r", encoding="utf-8") as f:
            original = f.read()

        content = original
        n_merge = 0

        # Step A --- split merged lines
        content, n_merge = _MERGE_RE.subn(_MERGE_REPLACEMENT, content)

        # Step A2 --- remove blank line between directive and its options
        n_blank = 0
        content, n_blank = _BLANK_BEFORE_OPTION_RE.subn(r'\1\n\2', content)

        # Step B --- de-indent indented literalinclude blocks
        lines = content.splitlines(keepends=True)
        new_lines = []
        i = 0
        n_indented = 0

        while i < len(lines):
            line = lines[i]
            m = re.match(r'^(\s+)(\.\. literalinclude::.*)', line)
            if m:
                base_indent = m.group(1)
                block = [line]
                block_start = i
                i += 1

                # Collect continuation lines (more-indented than base)
                while i < len(lines):
                    if lines[i].strip() == '':
                        peek = i + 1
                        while peek < len(lines) and lines[peek].strip() == '':
                            peek += 1
                        if peek < len(lines):
                            ni = len(lines[peek]) - len(lines[peek].lstrip())
                            if ni > len(base_indent):
                                block.append(lines[i])
                                i += 1
                                continue
                        break
                    li = len(lines[i]) - len(lines[i].lstrip())
                    if li > len(base_indent):
                        block.append(lines[i])
                        i += 1
                        continue
                    break

                # De-indent every line in the block
                deindented = []
                for bline in block:
                    if bline.strip() == '':
                        deindented.append('\n')
                    elif bline.startswith(base_indent):
                        deindented.append(bline[len(base_indent):])
                    else:
                        deindented.append(bline.lstrip())

                # Ensure blank line before directive
                while new_lines and new_lines[-1].strip() == '':
                    new_lines.pop()
                new_lines.append('\n')
                new_lines.extend(deindented)
                new_lines.append('\n')
                n_indented += 1
                print(f"  [FIX] {rel}:{block_start + 1}  de-indented {len(block)} lines")
            else:
                new_lines.append(line)
                i += 1

        content = ''.join(new_lines)

        if n_merge:
            print(f"  [FIX] {rel}  split {n_merge} merged line(s)")
        if n_blank:
            print(f"  [FIX] {rel}  removed {n_blank} blank line(s) before options")

        if content != original:
            with open(filepath, "w", encoding="utf-8") as f:
                f.write(content)
            fixed_count += 1

    return fixed_count


# ==============================================================================
# Report
# ==============================================================================

def section(title, issues):
    print(f"\n{'=' * 65}")
    print(f"  {title}")
    print(f"{'=' * 65}")
    if issues:
        for item in issues:
            print(item)
        print(f"  -> {len(issues)} issue(s)")
    else:
        print("  [OK]")


# ==============================================================================
# Main
# ==============================================================================

def main():
    lang = "this branch"
    conf_py = os.path.join(SOURCE, "conf.py")
    if os.path.exists(conf_py):
        m = re.search(r"""language\s*=\s*['"]([^'"]+)['"]""", read_file(conf_py))
        if m:
            lang = m.group(1)

    mode = "CHECK + FIX" if FIX_MODE else "CHECK ONLY"
    print("=" * 67)
    print(f"  SYNC SELF-CHECK  |  language = {lang}  |  {mode}")
    print(f"  {SOURCE}")
    print("=" * 67)

    # --- fix pass (runs first when --fix) ---
    if FIX_MODE:
        print(f"\n{'=' * 65}")
        print("  Auto-fixing literalinclude issues ...")
        print(f"{'=' * 65}")
        n = fix_literalinclude_issues()
        if n == 0:
            print("  (nothing to fix)")

    # --- check passes ---
    total = 0

    issues = check_arduino_iframes()
    section("Arduino Cloud iframes (should be 0)", issues)
    total += len(issues)

    issues = check_missing_code()
    section("literalinclude -> missing _code/ files", issues)
    total += len(issues)

    issues = check_unused_code()
    section("Unused files in _code/ (not referenced by any RST)", issues)
    total += len(issues)

    issues = check_heading_underlines()
    section("Heading underline too short", issues)
    total += len(issues)

    issues = check_broken_toctree()
    section("Broken toctree references", issues)
    total += len(issues)

    issues = check_orphan_files()
    section("Orphan RST files (not in any toctree)", issues)
    total += len(issues)

    issues = check_indented_literalinclude()
    section("Indented / merged literalinclude", issues)
    total += len(issues)

    print()
    print("=" * 67)
    if total == 0:
        print("  All checks passed [OK]")
    else:
        print(f"  {total} issue(s) found")
        if not FIX_MODE:
            print("  Run with --fix to auto-repair indentation / merge issues")
    print("=" * 67)


if __name__ == "__main__":
    main()
