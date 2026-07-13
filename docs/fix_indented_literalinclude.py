"""
Fix RST files where ``.. literalinclude::`` is either:

1. Indented inside a ``.. note::`` / ``.. warning::`` block (de-indent it), OR
2. Merged onto a single line with ``:language: cpp`` (split it back).

Also ensures proper blank line separation around the directive.

Usage:
    python fix_indented_literalinclude.py
"""

import os
import re
import glob

DOCS_SOURCE = os.path.join(os.path.dirname(__file__), "source")

# ---------------------------------------------------------------------------
# Step 1: Split merged lines
#   ".. literalinclude:: /_code/XX.ino   :language: cpp"
#   becomes two lines
# ---------------------------------------------------------------------------
MERGE_RE = re.compile(
    r'^(\.\. literalinclude:: /_code/\S+\.ino)(   :language: cpp)$',
    re.MULTILINE
)

MERGE_REPLACEMENT = r'\1\n\2'


# ---------------------------------------------------------------------------
# Step 2: Find indented literalinclude blocks and de-indent them
# ---------------------------------------------------------------------------
INDENTED_LI_RE = re.compile(
    r'^(\s+)(\.\. literalinclude::.*)',
    re.MULTILINE
)


def fix_file(filepath):
    """Fix merged and/or indented literalinclude blocks in a single RST file."""
    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    original = content

    # Step 1: Split merged lines
    content, n_merge = MERGE_RE.subn(MERGE_REPLACEMENT, content)
    if n_merge:
        print(f"  [SPLIT] {n_merge} merged line(s) fixed")

    # Step 2: De-indent indented literalinclude blocks (line by line for precision)
    lines = content.splitlines(keepends=True)
    new_lines = []
    i = 0
    n_indented = 0

    while i < len(lines):
        line = lines[i]
        m = re.match(r'^(\s+)(\.\. literalinclude::.*)', line)
        if m:
            base_indent = m.group(1)
            # Collect the block
            block = [line]  # keep original line with newline
            block_start = i
            i += 1

            while i < len(lines):
                if lines[i].strip() == '':
                    # peek for continuation
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

            # De-indent
            deindented = []
            for bline in block:
                if bline.strip() == '':
                    deindented.append('\n')
                elif bline.startswith(base_indent):
                    deindented.append(bline[len(base_indent):])
                else:
                    deindented.append(bline.lstrip())

            # Ensure blank line before
            while new_lines and new_lines[-1].strip() == '':
                new_lines.pop()
            new_lines.append('\n')

            new_lines.extend(deindented)
            new_lines.append('\n')
            n_indented += 1
            print(f"  [DE-INDENT] line {block_start + 1}: {len(block)} lines")
        else:
            new_lines.append(line)
            i += 1

    content = ''.join(new_lines)

    if content == original:
        return False

    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)

    return True


def main():
    rst_files = glob.glob(os.path.join(DOCS_SOURCE, "**", "*.rst"), recursive=True)
    fixed_count = 0

    for filepath in sorted(rst_files):
        stem = os.path.splitext(os.path.basename(filepath))[0]
        if fix_file(filepath):
            fixed_count += 1
            print(f"  [FILE] {stem}\n")

    print(f"{'=' * 60}")
    print(f"Fixed: {fixed_count} files")
    print("Done.")


if __name__ == "__main__":
    main()
