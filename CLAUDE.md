# SunFounder Elite Explorer Kit — Documentation Project

## Project Overview

This is the documentation repository for the **SunFounder Elite Explorer Kit** (Arduino Uno R4 WiFi). Built with **Sphinx 7.3.7** + **docutils 0.18.1** + **reStructuredText (RST)**, hosted on **Read the Docs**.

- **Main branch**: `main` (English docs, deployed as `docs` version)
- **Chinese branch**: `docs-cn` (Chinese docs, deployed as `docs-cn` version)
- **Repo**: `sunfounder/elite-explorer-kit`
- **RTD URL pattern**: `https://docs.sunfounder.com/projects/elite-explorer-kit/{lang}/latest/`
- **Toolchain**: Sphinx 7.3.7 + docutils 0.18.1 + sphinx_rtd_theme

### Repository Structure

```
├── .readthedocs.yaml
├── docs/
│   ├── Makefile / make.bat
│   ├── requirements.txt           # sphinx, sphinx_rtd_theme, sphinx_copybutton
│   └── source/
│       ├── conf.py                # Sphinx config (theme, language, rst_epilog links)
│       ├── index.rst              # Main page (toctrees, copyright, language selector)
│       ├── _static/               # JS, CSS, videos
│       ├── _templates/            # HTML templates
│       ├── arduino_start/         # 10 files — Arduino入门教程
│       ├── video_lesson/          # 33 files — 32 lessons + index
│       ├── components/            # 40 files — 元件参考文档
│       ├── basic_projects/        # 34 files — 基础项目教程
│       ├── fun_projects/          # 14 files — 趣味项目 (含游戏)
│       ├── iot_projects/          # 9 files — IoT 项目
│       ├── new_feature_projects/  # 10 files — R4 WiFi 新功能
│       └── appendix/              # 3 files — I2C 扫描, 固件升级
```

---

## Branch & Language Configuration

### conf.py Settings

```python
language = 'zh_CN'           # 'en' for English, 'zh_CN' for Chinese
github_version = "docs-cn"   # Branch name for GitHub "Edit on GitHub" link
html_theme = 'sphinx_rtd_theme'
```

### Multi-language Note in index.rst

`index.rst` contains a `.. note::` block listing available languages via `|link_xx_tutorials|` substitution refs. This block must be **preserved** (not deleted) — it is distinct from the Facebook promotion note.

---

## Step 1: Remove Facebook Promotion Note Block

Every `.rst` file starts with an identical Facebook community promotion note:

```rst
.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!
    (followed by a blank or indented-blank line, i.e. ``\n\n`` or ``\n    \n``)
```

### Correct Removal Command

```bash
# Step 1: Normalize CRLF → LF (CRLF causes regex failures)
find docs/source -name "*.rst" -print0 | xargs -0 sed -i 's/\r$//'

# Step 2: Remove ONLY the Facebook note (non-greedy, specific anchor text)
find docs/source -name "*.rst" -print0 | while IFS= read -r -d '' f; do
  perl -i -0777 -pe 's/\.\. note::\n\n\s{4}Hello, welcome to the SunFounder.*?join today!\n\s*\n//s' "$f"
done

# Step 3: Clean leading blank lines left after removal
find docs/source -name "*.rst" -print0 | xargs -0 sed -i '/./,$!d'

# Step 4: Remove any duplicate/copy files
rm -f "docs/source/iot_projects/02_iot_arduino_iot_cloud copy.rst"
```

### Why NOT sed Range Delete

```bash
# WRONG — destroys files with multiple .. note:: blocks:
sed '/^\.\. note::/,/link_sf_facebook.*join today!/d'
```

**Problem**: sed ranges are greedy. After deleting the first `.. note::` block, the sed engine encounters the SECOND `.. note::` (e.g., language links in `index.rst`) and starts a NEW range. Since `link_sf_facebook.*join today!` never appears again, the range extends to **end of file** — silently deleting all content after the second note. Over 60 files have multiple `.. note::` blocks.

The perl solution uses **non-greedy** `.*?` and the specific anchor `Hello, welcome to the SunFounder` to match only the Facebook note.

### Trailing Blank Line Variation

Some files have `\n\n` (fully blank) after "join today!", others have `\n    \n` (indented blank, still part of the note block content). The regex uses `\n\s*\n` to match both.

---

## Step 2: Translation

### Core Rules (Must Follow Exactly)

1. **Translate ONLY English prose** — every sentence, paragraph, table cell, list item
2. **NEVER modify or delete**:
   - RST directives: `.. note::`, `.. image::`, `.. code-block::`, `.. raw:: html`, `.. toctree::`, `.. _labels:`, `.. list-table::`, `.. |substitutions|`, `.. tip::`, `.. warning::`, `.. important::`
   - Code blocks — ALL Arduino/C++ code stays AS-IS (including comments!)
   - URLs, file paths, image paths
   - Inline RST roles: `:ref:`, `:doc:`
   - HTML tags and raw HTML blocks (`<video>`, `<iframe>`, `<a>`)
   - Substitution references: `|link_xxx|`
   - Pin names (`A0`, `D3`, `GND`), function names (`setup()`, `loop()`), library names (`Wire.h`, `FastLED.h`), variable names, component model numbers
3. **PRESERVE exactly**: heading underlines (same `===`/`---` length), all indentation, all blank lines, all RST markup syntax
4. **DO NOT truncate**: The output file must contain EVERY line from the input. No summarization, no omission.

### Terminology Table

| English | 中文 | Context |
|---------|------|---------|
| Overview | 概述 | Section heading |
| Required Components | 所需元件 | Section heading |
| Wiring | 接线 | Section heading |
| Circuit | 电路 | Section heading |
| Schematic Diagram | 原理图 | Section heading |
| Code | 代码 | Section heading |
| Code Analysis | 代码分析 | Section heading |
| How it works | 工作原理 | Section heading |
| Experiment | 实验 | Section heading |
| Phenomenon | 现象 | Section heading |
| Summary | 小结 | Section heading |
| Steps | 步骤 | Section heading |
| Note | 注意 | Directive |
| Warning | 警告 | Directive |
| Tip | 提示 | Directive |
| Lesson | 课程 | video_lesson |
| Homework Assignment | 课后作业 | video_lesson |
| Coming Soon... | 即将推出... | video_lesson placeholder |
| Project | 项目 | General |
| Component | 元件 | components |
| Contents | 目录 | index.rst |
| Copyright Notice | 版权声明 | index.rst footer |
| Download the Code | 下载代码 | root file |
| Appendix | 附录 | appendix |
| GAME | 游戏 | fun_projects |
| ITEMS IN THIS KIT | 套件所含项目 | list-table header |
| LINK | 链接 | list-table header |
| Name | 名称 | list-table header |
| BUY | 购买 | list-table cell |
| Thank You | 感谢 | thank_learning |
| Example | 示例 | components section |

### English Terms That Stay UNTRANSLATED

These are proper nouns, UI labels, or technical identifiers — keep in English:
- Arduino IDE menu items inside `**...**`: **Verify**, **Upload**, **Debug**, **File**, **Edit**, **Sketch**, **Tools**, **Help**, **Board**, **Port**, **INSTALLED**
- Library names: FastLED, Wire, SPI, ArduinoBLE, WiFiS3
- Board names: Arduino UNO R4 WiFi, Arduino UNO R4 Minima
- Protocol names: MQTT, BLE, I2C, SPI, UART
- Service names: IFTTT, CheerLights, HiveMQ, Arduino IoT Cloud
- App names: LightBlue, MIT App Inventor

### Parallel Agent Strategy

For ~156 files (~40K words), use 5 parallel agents:

| Agent | Scope | Files |
|-------|-------|-------|
| 1 | `arduino_start/` + `video_lesson/` | ~43 |
| 2 | `components/` | ~40 |
| 3 | `basic_projects/` | ~34 |
| 4 | `fun_projects/` + `iot_projects/` + `new_feature_projects/` | ~33 |
| 5 | `index.rst` + root + `appendix/` | ~6 |

**Critical**: Agents tend to truncate large files (especially `index.rst` which has toctrees and copyright). Always verify line counts after agent translation. If any file is significantly smaller than expected, restore from git and re-translate manually.

### Known Agent Failure Patterns

1. **Truncation**: Agent writes only the first few lines and stops. Most common with `index.rst`.
   - *Fix*: Restore from git, translate that file manually in the main conversation.
2. **list-table last row**: Agent removes `- ` before `\-` in the last row of `.. list-table::` directives.
   - *Fix*: Check `grep -rn '^        \\-$' docs/source/` after translation. Add `- ` prefix.
3. **Missing closing delimiters**: Agent may drop `**` or `` ` `` in some lines.
   - *Fix*: Build and check warnings; fix affected lines manually.

---

## Step 3: Fix Sphinx/docutils CJK Spacing Bug

### The Problem

**docutils 0.18.1 has a bug**: When CJK (Chinese/Japanese/Korean) characters are immediately adjacent to RST inline markup delimiters (`` ` ``, `**`, `|`), Sphinx incorrectly reports:

- `Inline strong start-string without end-string` (for `**text**中文`)
- `Inline interpreted text or phrase reference start-string without end-string` (for `` `text`中文 ``)
- `Inline substitution_reference start-string without end-string` (for `|ref|中文`)

The English original has zero such warnings (only 2 duplicate-label warnings from the `copy.rst` file). All are introduced by translation because Chinese text sits next to RST markup without spaces.

### The Fix

Add a space between the closing delimiter and the following CJK character:

```
Before: **LED**代表    →  After: **LED** 代表
Before: :ref:`label`（项目）  →  After: :ref:`label` （项目）
Before: |link_xxx|（iOS）     →  After: |link_xxx| （iOS）
```

### Fix Command

```bash
find docs/source -name "*.rst" -print0 | while IFS= read -r -d '' f; do
  perl -i -CSD -pe '
    # Skip code lines (contain C++ patterns)
    unless (/\{/ || /\}/ || /;\s*$/ || /^\s*\/\// || /^\s*#define/ || /^\s*#include/) {
      # Add space after closing ** before CJK/non-ASCII char
      s/\*\*([^*]+)\*\*([\x{0080}-\x{FFFF}])/**$1** $2/g;
      # Add space after closing backtick before CJK/non-ASCII char
      s/`([^`]+)`([\x{0080}-\x{FFFF}])/`$1` $2/g;
      # Add space after closing |subst| before CJK/non-ASCII char
      s/\|([^|]+)\|([\x{0080}-\x{FFFF}])/|$1| $2/g;
    }
  ' "$f"
done
```

**Important details**:
- `-CSD` enables UTF-8 mode on STDIN/STDOUT/STDERR
- `[\x{0080}-\x{FFFF}]` matches any Unicode codepoint from U+0080 to U+FFFF (all non-ASCII)
- The `unless` guard skips lines that look like C++ code to avoid corrupting code blocks
- The regex only matches when a non-ASCII char IMMEDIATELY follows the closing delimiter (no space in between), so it won't double-add spaces

### Do NOT Add Spaces Inside `**...**`

The regex captures `([^*]+)` and preserves it with `$1`. But be careful: if a previous run incorrectly added `** text**` (space inside), the regex will preserve the leading space. If this happens, fix with:

```bash
perl -i -CSD -pe 's/\*\* ([\x{0080}-\x{FFFF}])/**$1/g' file.rst
```

### Affected Files Pattern

Files with "示例" (Example) sections are most affected — they have bullet lists of `:ref:` links with Chinese parentheses. The components and fun_projects directories have the most instances.

---

## Step 4: Verification

### Build & Check

```bash
cd docs
rm -rf build/          # MUST clean build — cached .doctree hides errors!
sphinx-build -b html source build/html 2>&1 | grep -E "WARNING:|ERROR:"
```

### Pre-Build Checks (Fast, No Sphinx Required)

```bash
# 1. No Facebook notes remain
grep -rl "Hello, welcome to the SunFounder" docs/source/ | wc -l  # → 0

# 2. All file counts match
find docs/source -name "*.rst" | wc -l  # → ~156

# 3. index.rst is intact (~74 lines after note removal, 88 original)
wc -l docs/source/index.rst

# 4. Toctrees preserved
grep -c "toctree" docs/source/index.rst  # → 2

# 5. No bare `\-` without `- ` in list-tables
grep -rn '^        \\-$' docs/source/ --include="*.rst"

# 6. No :ref: without space before Chinese parentheses
grep -rn ':ref:`[^`]*`（' docs/source/ --include="*.rst"

# 7. conf.py has correct settings
grep "^language =" docs/source/conf.py
grep "github_version" docs/source/conf.py
```

### Common Build Warnings Reference

| Warning Pattern | Root Cause | Fix |
|----------------|-----------|-----|
| `Inline strong start-string without end-string` | CJK immediately after `**` | Add space: `**text** 中文` |
| `Inline interpreted text... without end-string` | CJK immediately after `` ` `` | Add space: `` `text` 中文 `` |
| `Inline substitution_reference... without end-string` | CJK immediately after `\|` | Add space: `\|ref\| 中文` |
| `Bullet list ends without a blank line` + `two-level bullet list expected` | list-table last row missing `- ` | Add `- ` before `\-` |
| `duplicate label` | Copy file exists | Delete `... copy.rst` |
| `document isn't included in any toctree` | Orphan file | Add to toctree or delete |

---

## Complete Translation Checklist (Step by Step)

When creating a new language branch (e.g., `docs-cn`):

1. [ ] Branch from `main`, name it `docs-{lang}`
2. [ ] Update `conf.py`: `language`, `github_version`
3. [ ] Remove Facebook note block from all `.rst` files (perl command above)
4. [ ] Delete any `copy.rst` duplicate files
5. [ ] Translate all `.rst` files with parallel agents
6. [ ] Verify `index.rst` line count (~74) — re-translate if truncated
7. [ ] Fix list-table last rows: `grep -rn '^        \\-$' docs/source/`
8. [ ] Fix CJK spacing: run perl spacing script
9. [ ] Fix any `** text**` over-corrections: `perl -i -CSD -pe 's/\*\* ([\x{0080}-\x{FFFF}])/**$1/g'`
10. [ ] Clean build: `rm -rf build/ && sphinx-build -b html source build/html`
11. [ ] Fix remaining warnings one by one
12. [ ] Verify 0 WARNING, 0 ERROR in final build

---

## File Naming Conventions

| Pattern | Example |
|---------|---------|
| Component pages | `component_{name}.rst` |
| Basic projects | `{NN}_basic_{name}.rst` (zero-padded) |
| Fun projects | `{NN}_fun_{name}.rst` |
| IoT projects | `{NN}_iot_{name}.rst` |
| New feature projects | `{NN}_{name}.rst` (sub-numbers: `01_1_`, `01_2_`) |
| Video lessons | `lesson{NN}.rst` |
| Section indexes | `00_{category}_project.rst` |
