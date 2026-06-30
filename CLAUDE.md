# Arduino Elite Explorer Kit — Documentation

Sphinx-based RST documentation project for the Arduino Elite Explorer Kit.

## Build

```bash
cd docs
./make.bat html    # Windows
# or
make html           # macOS/Linux
```

Output: `docs/build/html/`

## Terminology

- **Power Pack** — The rechargeable power module (`cpn_power`). In copy, always refer to it as "Power Pack", never "14500 battery" or "battery".
  - In `:ref:`cpn_power`` role references: use "Power Pack" (e.g. `:ref:`cpn_power`'s Power Pack`)
  - In spec lists: `Battery: 3.7V Power Pack, 500mAh`
- "battery" is only used when referring to other components (button cells, RTC backup, general electrical principles, etc.) — never for the kit's power module.

## Project structure

```
docs/source/
├── appendix/           # Appendix (I2C scanner, firmware update)
├── arduino_start/      # Getting started guides
├── basic_projects/     # 29 basic component projects
├── components/         # Component reference pages
├── fun_projects/       # Fun/creative projects
├── iot_projects/       # IoT cloud projects
├── new_feature_projects/ # UNO R4 WiFi specific features
├── video_lesson/       # Video lesson pages
├── conf.py             # Sphinx configuration
└── index.rst           # Root toctree
```
