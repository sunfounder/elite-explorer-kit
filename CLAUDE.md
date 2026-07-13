# Arduino Elite Explorer Kit — Documentation

Sphinx-based RST documentation project for the Arduino Elite Explorer Kit.

## Multi-language branches

The GitHub repo `sunfounder/elite-explorer-kit` has one branch per language. The **`docs` branch (English) is the single authoritative source**. All other language branches are translations derived from `docs` and must follow its structure, constraints, and conventions.

| Branch | Language | Role |
|---|---|---|
| `docs` | English | **Authoritative source — all changes originate here** |
| `docs-cn` | 中文 | Translation of `docs` |
| `docs-de` | Deutsch | Translation of `docs` |
| `docs-es` | Español | Translation of `docs` |
| `docs-fr` | Français | Translation of `docs` |
| `docs-it` | Italiano | Translation of `docs` |
| `docs-ja` | 日本語 | Translation of `docs` |

`main` is the code branch (`.ino` / `.h` source files).

### Rules

1. **All changes happen on `docs` first.** Structural changes (RST files, `.. literalinclude::` directives, scripts) must be made on the English `docs` branch before being propagated to translation branches.
2. **This CLAUDE.md is the single project specification.** Translation branches must follow the same rules — there is no per-language CLAUDE.md override.
3. **`_code/` is shared.** All branches download `.ino` and `.h` files from `main`. Code is language-agnostic; only the surrounding documentation text is translated.
4. **Scripts run on `docs`.** `download_code.py`, `convert_iframes.py`, and `check_sync_parity.py` operate on the `docs` branch. When propagating to a translation branch, the same scripts should be run to sync RST structure (replacing iframes, checking parity, etc.).

## Sync Protocol: `docs` → Other Languages

When `docs` is updated, every other language branch must be brought into parity.
The check-list for each translation branch:

1. **File existence**: every `.rst` file under `docs/source/` that exists in `docs`
   (excluding `_code/` and `build/`) must also exist in the translation branch.
2. **Toctrees**: every `.. toctree::` directive must list the same entries in the same order.
3. **Section structure**: headings, sub-headings, `.. note::`, `.. warning::`,
   `.. code-block::`, `.. literalinclude::`, `.. list-table::` directives must match
   present-for-present.
4. **Images & videos**: image paths and `.. raw:: html` embeds are shared across
   languages — do NOT change paths during translation. Add new images to the same
   relative paths as `docs`.
5. **RST anchors**: labels like `.. _basic_moisture:` must be identical across all
   languages (they are used for cross-references).
6. **Heading underlines**: `===` / `---` / `~~~` must be longer than the heading text
   (translations tend to be longer than English).
7. **Inline markup + CJK**: `**bold**`, `` `code` ``, `|subref|` followed by a CJK
   letter or `（` need a `\ ` escape (see Inline Markup and CJK Characters below).

The only thing that should differ between `docs` and a translation branch is the
human-language prose.

## RST Heading Conventions

This is a hard rule for ALL rst files:

> **The underline (`===`, `---`, `~~~`, `^^^`) on the line immediately below a heading
> MUST be longer than the heading text itself.**

```
✅ Good:
A Very Long Section Title
==========================

✅ Good:
Short Title
------------

❌ Bad:
A Very Long Section Title
=========================

❌ Bad:
Short Title
-----------
```

### Heading hierarchy in use

| Level | Character | Used for |
|-------|-----------|----------|
| 1     | `=` | Document / chapter title |
| 2     | `-` | Section within a document |
| 3+    | `~` or `^` | Sub-sections (if needed) |

## RST Style Rules

### Code blocks

Always specify the language:
```rst
.. code-block:: cpp

.. code-block:: bash

.. code-block:: python
```

For Arduino sketches included from `_code/`, use `.. literalinclude::` which already
declares `:language: cpp`.

### Cross-references

Use `:ref:` with anchor labels defined via `.. _label_name:`:
```rst
:ref:`basic_moisture`
```
Labels must be identical across all language branches.

### Images

Images are stored in section-specific `img/` directories. Paths are shared across
languages — do NOT rename or translate image paths.
```rst
.. image:: img/03-soil_moisture_bb.png
    :align: center
    :width: 80%
```

### Videos / iframes

Embedded via `.. raw:: html` with iframe — copy verbatim from `docs` to translation
branches.

### Community ad note

Most RST files start with a `.. note::` block containing the SunFounder Facebook
community ad. Translate the ad into the target language. Do not add or remove ads
to force alignment between branches — minor cosmetic differences on these blocks
are acceptable.

### Inline Markup and CJK Characters

RST inline markup — `**bold**`, `` `code` ``, `|substitution|` — requires the
**closing delimiter** to be immediately followed by **whitespace, punctuation, or
end-of-line**. When translating to Chinese or Japanese, this rule is frequently
broken because:

- CJK characters are **letters**, not punctuation — they do NOT count as valid
  terminators
- Full-width punctuation like `，` `。` `：` `、` `）` IS recognized, but `（`
  (full-width left paren) may NOT be recognized by all RST parsers

**Patterns that need `\ ` (backslash-escaped space) after the closing delimiter:**

| Pattern | Fix | Example |
|---------|-----|---------|
| `**text**CJK` | `**text**\ CJK` | `**not**compatible` → `**not**\ compatible` |
| `**text**（` | `**text**\ （` | `**Piper**（offline）` → `**Piper**\ （offline）` |
| `` `code`CJK `` | `` `code`\ CJK `` | same pattern |
| `|subref|CJK` | `|subref|\ CJK` | same pattern |
| `|subref|（` | `|subref|\ （` | `|link_xxx|（说明）` → `|link_xxx|\ （说明）` |

**Patterns that are safe (no fix needed):**

| Pattern | Reason |
|---------|--------|
| `**text**：` | Full-width colon is punctuation |
| `**text**，` | Full-width comma is punctuation |
| `**text**。` | Full-width period is punctuation |
| `**text**、` | Full-width enumeration comma is punctuation |
| `**text**）` | Full-width right paren is punctuation |

**Post-translation check-list for each file:**
1. Search for `**` followed by a CJK letter or `（` → add `\ ` escape
2. Search for `` ` `` followed by a CJK letter or `（` → add `\ ` escape
3. Search for `|xxx|` followed by a CJK letter or `（` → add `\ ` escape
4. Do NOT add `\ ` after punctuation characters (`：，。、）`)

## conf.py — Per-Branch Settings

The only line that MUST differ between language branches in `source/conf.py` is:
```python
language = 'XX'
```

Everything else (extensions, html_theme, html_context, rst_epilog links, etc.) stays
identical to `docs`. The `rst_epilog` contains replacement strings like
`|link_sf_facebook|` and `|link_Elite_Explorer_kit|` — these HTML links point to
language-specific resources but the substitution names remain the same across branches.

## Build

```bash
cd docs
./make.bat html    # Windows
# or
make html           # macOS/Linux
```

Output: `docs/build/html/`. **Never read, edit, or commit anything under `docs/build/`** —
that folder is build output only.

## Terminology

- **Power Pack** — The rechargeable power module (`cpn_power`). In copy, always refer to it as "Power Pack", never "14500 battery" or "battery".
  - In `:ref:`cpn_power`` role references: use "Power Pack" (e.g. `:ref:`cpn_power`'s Power Pack`)
  - In spec lists: `Battery: 3.7V Power Pack, 500mAh`
- "battery" is only used when referring to other components (button cells, RTC backup, general electrical principles, etc.) — never for the kit's power module.

## Code syncing from GitHub

The docs use `.. literalinclude::` to show Arduino code inline. The source of truth is the GitHub repo `sunfounder/Elite-Explorer-Kit`. Three scripts in `docs/` manage this pipeline:

### Workflow

```bash
cd docs
python download_code.py        # Step 1: Download .ino + .h files from GitHub → source/_code/
python convert_iframes.py      # Step 2: Replace Arduino Cloud iframes with .. literalinclude::
python check_sync_parity.py    # Step 3: Validate structure, check for issues
```

Always run them in this order. Step 3 validates everything is in sync — run with `--fix` to auto-repair indentation issues.

### download_code.py

Downloads `.ino` and `.h` files from `sunfounder/Elite-Explorer-Kit/main` into `source/_code/`. Maps ~70 files across four project groups. Header files (`.h`) are downloaded alongside `.ino` files for projects that need them:

- **`pitches.h`** — Note-frequency definitions. Downloaded once, shared by 5 projects: `16_basic_passive_buzzer`, `17_basic_audio_speaker`, `01_fun_welcome`, `02_fun_fruit_piano`, `07_dac`.
- **`arduino_secrets.h`** — WiFi credential templates. Each IoT/WiFi project has its own variant (different `#define` keys per project). Downloaded per-project for 7 files: `01_iot_webserver`, `03_iot_security_alert`, `04_iot_mqtt_callling`, `05_iot_cheerlights`, `06_iot_weather_oled`, `01_1_connect_to_wifi`, `01_2_ap`.

When adding a new project to the docs:
1. Add its GitHub path to the `PROJECTS` dict in `download_code.py`
2. If the `.ino` `#include`s a `.h` file, add that `.h` to `PROJECTS` too
3. Run `download_code.py` to fetch it
4. Add `.. literalinclude:: /_code/<key>.ino` (and `/_code/<key>.h` if applicable) to the RST file

### convert_iframes.py

Batch-converts `<iframe src=https://create.arduino.cc/editor/sunfounder01/...>` embeds into `.. literalinclude::` directives. Two mappings:
- `SINGLE_MAP` — One iframe → one literalinclude (most files)
- `MULTI_MAP` — Multiple iframes in one RST (e.g., `09_basic_gy87_qmc5883l` has 2, `05_hid` has 2). Matches by UUID fragment.

**Important:** `make_literalinclude()` always outputs at zero indent. Never indent `.. literalinclude::` — RST directives must be at top level, not nested inside `.. note::` or `.. warning::` blocks.

### check_sync_parity.py

Self-check tool that validates a single language branch independently (no English source required). Runs 7 checks:
1. Remaining Arduino Cloud iframes
2. literalinclude paths pointing to missing _code/ files
3. Unused _code/ files (downloaded but never referenced)
4. Heading underline >= heading text length
5. Orphan RST files (not in any toctree)
6. Broken toctree references
7. Indented / merged literalinclude blocks

Run `python check_sync_parity.py --fix` to auto-repair check #7 (de-indent blocks, split merged lines, add blank line spacing).

## Project structure

```
docs/
├── download_code.py            # Download .ino/.h from GitHub
├── convert_iframes.py          # Replace Arduino Cloud iframes
├── check_sync_parity.py        # Validate sync parity, --fix for auto-repair
├── make.bat                    # Windows build script
└── source/
    ├── _code/                  # Downloaded .ino and .h files
    ├── appendix/               # Appendix (I2C scanner, firmware update)
    ├── arduino_start/          # Getting started guides
    ├── basic_projects/         # 29 basic component projects
    ├── components/             # Component reference pages
    ├── fun_projects/           # Fun/creative projects
    ├── iot_projects/           # IoT cloud projects
    ├── new_feature_projects/   # UNO R4 WiFi specific features
    ├── video_lesson/           # Video lesson pages
    ├── conf.py                 # Sphinx configuration
    └── index.rst               # Root toctree
```
