"""
Batch convert iframe embeds to ``.. literalinclude::`` directives in RST files.

Run this AFTER ``download_code.py`` has downloaded the .ino files.
"""
import os
import re
import glob

DOCS_SOURCE = os.path.join(os.path.dirname(__file__), "source")

# ---------------------------------------------------------------------------
# Mapping: RST filename stem -> (local_code_key, caption_filename)
#
# Most files have a 1:1 mapping.  Files marked with an asterisk (*) have
# MULTIPLE iframes and need special handling (see MULTI_IFRAME_FILES below).
# ---------------------------------------------------------------------------

SINGLE_MAP = {
    # ==================== basic_projects ====================
    "02_basic_thermistor":           ("02_basic_thermistor",           "02-thermistor.ino"),
    "03_basic_moisture":             ("03_basic_moisture",             "03-moisture.ino"),
    "04_basic_tilt_switch":          ("04_basic_tilt_switch",          "04-tilt_switch.ino"),
    "05_basic_pir":                  ("05_basic_pir",                  "05-pir_motion_sensor.ino"),
    "06_basic_ultrasonic_sensor":    ("06_basic_ultrasonic_sensor",    "06-ultrasonic.ino"),
    "07_basic_humiture_sensor":      ("07_basic_humiture_sensor",      "07-humiture_sensor.ino"),
    "08_basic_mfrc522":              ("08_basic_mfrc522",              "08-mfrc522.ino"),
    "09_basic_gy87":                 ("09_basic_gy87",                 "09-gy87.ino"),
    "09_basic_gy87_bmp180":          ("09_basic_gy87_bmp180",          "09-gy87_bmp180.ino"),
    "09_basic_gy87_mpu6050":         ("09_basic_gy87_mpu6050",         "09-gy87_mpu6050.ino"),
    # "09_basic_gy87_qmc5883l" — handled separately (2 iframes)
    "10_basic_led":                  ("10_basic_led",                  "10-led.ino"),
    "11_basic_rgb_led":              ("11_basic_rgb_led",              "11-rgb_led.ino"),
    "12_basic_ws2812":               ("12_basic_ws2812",               "12-ws2812.ino"),
    "13_basic_7_segment":            ("13_basic_7_segment",            "13-7_segment.ino"),
    "14_basic_i2c_lcd":              ("14_basic_i2c_lcd",              "14-i2c_lcd.ino"),
    "15_basic_oled":                 ("15_basic_oled",                 "15-oled.ino"),
    "16_basic_active_buzzer":        ("16_basic_active_buzzer",        "16-active_buzzer.ino"),
    "16_basic_passive_buzzer":       ("16_basic_passive_buzzer",       "16-passive_buzzer.ino"),
    "17_basic_audio_speaker":        ("17_basic_audio_speaker",        "17-speaker.ino"),
    "18_basic_button":               ("18_basic_button",               "18-button.ino"),
    "19_basic_potentiometer":        ("19_basic_potentiometer",        "19-potentiometer.ino"),
    "20_basic_joystick":             ("20_basic_joystick",             "20-joystick.ino"),
    "21_basic_keypad":               ("21_basic_keypad",               "21-keypad.ino"),
    "22_basic_irrecv":               ("22_basic_irrecv",               "22-ir_receiver.ino"),
    "23_basic_mpr121_module":        ("23_basic_mpr121_module",        "23-mpr121.ino"),
    "24_basic_motor":                ("24_basic_motor",                "24-motor.ino"),
    "25_basic_pump":                 ("25_basic_pump",                 "25-pump.ino"),
    "26_basic_stepper_motor":        ("26_basic_stepper_motor",        "26-stepper_motor.ino"),
    "27_basic_servo":                ("27_basic_servo",                "27-servo.ino"),
    "28_basic_relay":                ("28_basic_relay",                "28-relay.ino"),
    "29_basic_74hc595":              ("29_basic_74hc595",              "29-74hc595.ino"),

    # ==================== fun_projects ====================
    "01_fun_welcome":                ("01_fun_welcome",                "01_welcome.ino"),
    "02_fun_fruit_piano":            ("02_fun_fruit_piano",            "02_fruit_piano.ino"),
    "03_fun_hue":                    ("03_fun_hue",                    "03_HueDial.ino"),
    "04_fun_light_array":            ("04_fun_light_array",            "04_light_sensitive_array.ino"),
    "05_fun_digital_dice":           ("05_fun_digital_dice",           "05_digital_dice.ino"),
    "07_fun_smart_can":              ("07_fun_smart_can",              "07_smart_trash_can.ino"),
    "08_fun_plant_monitor":          ("08_fun_plant_monitor",          "08_plant_monitor.ino"),
    "09_fun_access":                 ("09_fun_access",                 "09_access_control_system.ino"),
    "10_fun_guess_number":           ("10_fun_guess_number",           "10_guess_number.ino"),
    "11_fun_escape":                 ("11_fun_escape",                 "11_escape_square.ino"),
    "12_fun_pong":                   ("12_fun_pong",                   "12_pong_oled.ino"),
    "13_fun_snake":                  ("13_fun_snake",                  "13_snake.ino"),

    # ==================== iot_projects ====================
    "03_iot_security_alert":         ("03_iot_security_alert",         "03_ifttt_pir.ino"),
    "04_iot_mqtt_callling":          ("04_iot_mqtt_callling",          "04_mqtt_button.ino"),
    "05_iot_cheerlights":            ("05_iot_cheerlights",            "05_cheerlight.ino"),
    "06_iot_weather_oled":           ("06_iot_weather_oled",           "06_weather_oled.ino"),
    "07_iot_ble_lcd":                ("07_iot_ble_lcd",                "07_lightblue_lcd.ino"),
    "08_iot_ble_home":               ("08_iot_ble_home",               "08-bluetooth_environmental_monitor.ino"),

    # ==================== new_feature_projects ====================
    "01_1_connect_to_wifi":          ("01_1_connect_to_wifi",          "01-wifi_connect.ino"),
    "01_2_ap":                       ("01_2_ap",                       "01-wifi_ap.ino"),
    "02_bluetooth":                  ("02_bluetooth",                  "02-bluetooth.ino"),
    "03_rtc":                        ("03_rtc",                        "03-rtc.ino"),
    "04_led_matrix":                 ("04_led_matrix",                 "04-led_matrix.ino"),
    # "05_hid" — handled separately (2 iframes)
    "07_dac":                        ("07_dac",                        "07-dac.ino"),
}

# ---------------------------------------------------------------------------
# Files with MULTIPLE iframes: (rst_stem, [(iframe_url_fragment, (key, caption)), ...])
# The script will match each iframe by its URL fragment (the UUID portion).
# ---------------------------------------------------------------------------
MULTI_MAP = {
    "09_basic_gy87_qmc5883l": [
        # Order: compass calibration first, then qmc5883l reading
        ("8b266a18", ("09_basic_gy87_qmc5883l_calib", "09-gy87_compass_calibration.ino")),
        ("252c7a58", ("09_basic_gy87_qmc5883l",        "09-gy87_qmc5883l.ino")),
    ],
    "05_hid": [
        # Order: mouse first, then keyboard
        ("4b72e0f4", ("05_hid_mouse",    "05-hid_mouse.ino")),
        ("2a5b61d3", ("05_hid_keyboard", "05-hid_keyboard.ino")),
    ],
}

# Regex to match an iframe block
IFRAME_RE = re.compile(
    r'\.\. raw:: html\s*\n\s*\n'
    r'(\s*)<iframe src=https://create\.arduino\.cc/editor/sunfounder01/'
    r'([a-f0-9-]+)/preview\?embed[^>]*></iframe>',
    re.MULTILINE
)


def make_literalinclude(key, caption, indent=""):
    """Build the literalinclude directive block (always at top level)."""
    return (
        f".. literalinclude:: /_code/{key}.ino\n"
        f"   :language: cpp\n"
        f"   :linenos:\n"
        f"   :caption: {caption}"
    )


def convert_single(filepath, stem):
    """Convert a single-iframe RST file."""
    key, caption = SINGLE_MAP[stem]

    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    matches = IFRAME_RE.findall(content)
    if not matches:
        print(f"  [SKIP] {stem} — no iframe found (already converted?)")
        return False

    if len(matches) > 1:
        print(f"  [WARN] {stem} — has {len(matches)} iframes but not in MULTI_MAP!")
        return False

    indent, uuid = matches[0]
    new_block = make_literalinclude(key, caption, indent)

    new_content = IFRAME_RE.sub(new_block, content, count=1)

    with open(filepath, "w", encoding="utf-8") as f:
        f.write(new_content)

    print(f"  [OK] {stem} -> {key}.ino")
    return True


def convert_multi(filepath, stem):
    """Convert an RST file with multiple iframes."""
    mappings = MULTI_MAP[stem]

    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    matches = IFRAME_RE.findall(content)
    if len(matches) != len(mappings):
        print(f"  [WARN] {stem} — expected {len(mappings)} iframes, found {len(matches)}")
        return False

    for (indent, uuid), (uuid_frag, (key, caption)) in zip(matches, mappings):
        if uuid_frag not in uuid:
            print(f"  [WARN] {stem} — UUID mismatch: expected fragment {uuid_frag}")
            continue
        # Replace one at a time
        pattern = re.compile(
            r'(\.\. raw:: html\s*\n\s*\n'
            + re.escape(indent)
            + r'<iframe src=https://create\.arduino\.cc/editor/sunfounder01/'
            + re.escape(uuid)
            + r'/preview\?embed[^>]*></iframe>)',
            re.MULTILINE
        )
        replacement = make_literalinclude(key, caption, indent)
        content = pattern.sub(replacement, content, count=1)
        print(f"  [OK] {stem} -> {key}.ino")

    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)

    return True


def main():
    # Collect all RST files
    rst_files = glob.glob(os.path.join(DOCS_SOURCE, "**", "*.rst"), recursive=True)

    single_count = 0
    multi_count = 0

    for filepath in sorted(rst_files):
        stem = os.path.splitext(os.path.basename(filepath))[0]

        if stem in MULTI_MAP:
            print(f"\n[MULTI] {stem}")
            if convert_multi(filepath, stem):
                multi_count += 1
        elif stem in SINGLE_MAP:
            print(f"\n[SINGLE] {stem}")
            if convert_single(filepath, stem):
                single_count += 1

    print(f"\n{'='*60}")
    print(f"Converted: {single_count} single + {multi_count} multi = {single_count + multi_count} files")
    print("Done.")


if __name__ == "__main__":
    main()
