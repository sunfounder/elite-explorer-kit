"""
Download Arduino .ino code files from the Elite Explorer Kit GitHub repository
before the Sphinx build, so they can be included via ``.. literalinclude::``.

Usage:
    python download_code.py

The script downloads each .ino file into ``source/_code/``.
"""
import os
import urllib.request
import sys

# Base URL for raw content on GitHub
BASE_URL = "https://raw.githubusercontent.com/sunfounder/Elite-Explorer-Kit/main"

# Directory where downloaded .ino files will be stored (relative to this script)
LOCAL_DIR = os.path.join(os.path.dirname(__file__), "source", "_code")

# ---------------------------------------------------------------------------
# Mapping: local_key -> github_repo_path
#
# local_key is the RST filename stem (without .rst), used as the local .ino
# filename and as the argument to ``.. literalinclude:: /_code/<key>.ino``.
# ---------------------------------------------------------------------------

PROJECTS = {
    # ======================== basic_projects ================================

    "01_basic_photoresistor":        "basic_project/01-photoresistor/01-photoresistor.ino",
    "02_basic_thermistor":           "basic_project/02-thermistor/02-thermistor.ino",
    "03_basic_moisture":             "basic_project/03-moisture/03-moisture.ino",
    "04_basic_tilt_switch":          "basic_project/04-tilt_switch/04-tilt_switch.ino",
    "05_basic_pir":                  "basic_project/05-pir_motion_sensor/05-pir_motion_sensor.ino",
    "06_basic_ultrasonic_sensor":    "basic_project/06-ultrasonic/06-ultrasonic.ino",
    "07_basic_humiture_sensor":      "basic_project/07-humiture_sensor/07-humiture_sensor.ino",
    "08_basic_mfrc522":              "basic_project/08-mfrc522/08-mfrc522.ino",
    "09_basic_gy87":                 "basic_project/09-gy87/09-gy87.ino",
    "09_basic_gy87_bmp180":          "basic_project/09-gy87_bmp180/09-gy87_bmp180.ino",
    "09_basic_gy87_mpu6050":         "basic_project/09-gy87_mpu6050/09-gy87_mpu6050.ino",
    "09_basic_gy87_qmc5883l":        "basic_project/09-gy87_qmc5883l/09-gy87_qmc5883l.ino",
    "09_basic_gy87_qmc5883l_calib":  "basic_project/09-gy87_compass_calibration/09-gy87_compass_calibration.ino",
    "10_basic_led":                  "basic_project/10-led/10-led.ino",
    "11_basic_rgb_led":              "basic_project/11-rgb_led/11-rgb_led.ino",
    "12_basic_ws2812":               "basic_project/12-ws2812/12-ws2812.ino",
    "13_basic_7_segment":            "basic_project/13-7_segment/13-7_segment.ino",
    "14_basic_i2c_lcd":              "basic_project/14-i2c_lcd/14-i2c_lcd.ino",
    "15_basic_oled":                 "basic_project/15-oled/15-oled.ino",
    "16_basic_active_buzzer":        "basic_project/16-active_buzzer/16-active_buzzer.ino",
    "16_basic_passive_buzzer":       "basic_project/16-passive_buzzer/16-passive_buzzer.ino",
    "17_basic_audio_speaker":        "basic_project/17-speaker/17-speaker.ino",
    "18_basic_button":               "basic_project/18-button/18-button.ino",
    "19_basic_potentiometer":        "basic_project/19-potentiometer/19-potentiometer.ino",
    "20_basic_joystick":             "basic_project/20-joystick/20-joystick.ino",
    "21_basic_keypad":               "basic_project/21-keypad/21-keypad.ino",
    "22_basic_irrecv":               "basic_project/22-ir_receiver/22-ir_receiver.ino",
    "23_basic_mpr121_module":        "basic_project/23-mpr121/23-mpr121.ino",
    "24_basic_motor":                "basic_project/24-motor/24-motor.ino",
    "25_basic_pump":                 "basic_project/25-pump/25-pump.ino",
    "26_basic_stepper_motor":        "basic_project/26-stepper_motor.rst/26-stepper_motor.rst.ino",
    "27_basic_servo":                "basic_project/27-servo/27-servo.ino",
    "28_basic_relay":                "basic_project/28-relay/28-relay.ino",
    "29_basic_74hc595":              "basic_project/29-74hc595/29-74hc595.ino",

    # ======================== fun_projects ==================================

    "01_fun_welcome":                "fun_project/01_welcome/01_welcome.ino",
    "02_fun_fruit_piano":            "fun_project/02_fruit_piano/02_fruit_piano.ino",
    "03_fun_hue":                    "fun_project/03_HueDial/03_HueDial.ino",
    "04_fun_light_array":            "fun_project/04_light_sensitive_array/04_light_sensitive_array.ino",
    "05_fun_digital_dice":           "fun_project/05_digital_dice/05_digital_dice.ino",
    "06_fun_smart_fan":              "fun_project/06_smart_fan/06_smart_fan.ino",
    "07_fun_smart_can":              "fun_project/07_smart_trash_can/07_smart_trash_can.ino",
    "08_fun_plant_monitor":          "fun_project/08_plant_monitor/08_plant_monitor.ino",
    "09_fun_access":                 "fun_project/09_access_control_system/09_access_control_system.ino",
    "10_fun_guess_number":           "fun_project/10_guess_number/10_guess_number.ino",
    "11_fun_escape":                 "fun_project/11_escape_square/11_escape_square.ino",
    "12_fun_pong":                   "fun_project/12_pong_oled/12_pong_oled.ino",
    "13_fun_snake":                  "fun_project/13_snake/13_snake.ino",

    # ======================== iot_projects ==================================

    "01_iot_webserver":              "iot_project/01_simple_webserver/01_simple_webserver.ino",
    "03_iot_security_alert":         "iot_project/03_ifttt_pir/03_ifttt_pir.ino",
    "04_iot_mqtt_callling":          "iot_project/04_mqtt_button/04_mqtt_button.ino",
    "05_iot_cheerlights":            "iot_project/05_cheerlight/05_cheerlight.ino",
    "06_iot_weather_oled":           "iot_project/06_weather_oled/06_weather_oled.ino",
    "07_iot_ble_lcd":                "iot_project/07_lightblue_lcd/07_lightblue_lcd.ino",
    "08_iot_ble_home":               "iot_project/08-bluetooth_environmental_monitor/08-bluetooth_environmental_monitor.ino",

    # ======================== new_feature_projects ==========================

    "01_1_connect_to_wifi":          "r4_new_feature/01-wifi_connect/01-wifi_connect.ino",
    "01_2_ap":                       "r4_new_feature/01-wifi_ap/01-wifi_ap.ino",
    "02_bluetooth":                  "r4_new_feature/02-bluetooth/02-bluetooth.ino",
    "03_rtc":                        "r4_new_feature/03-rtc/03-rtc.ino",
    "04_led_matrix":                 "r4_new_feature/04-led_matrix/04-led_matrix.ino",
    "05_hid_mouse":                  "r4_new_feature/05-hid_mouse/05-hid_mouse.ino",
    "05_hid_keyboard":               "r4_new_feature/05-hid_keyboard/05-hid_keyboard.ino",
    "07_dac":                        "r4_new_feature/07-dac/07-dac.ino",

    # ======================== header files (.h) ==============================
    # pitches.h — identical across all projects, download one copy
    "pitches":                       "basic_project/16-passive_buzzer/pitches.h",

    # arduino_secrets.h — each project has different keys
    "01_iot_webserver_secrets":      "iot_project/01_simple_webserver/arduino_secrets.h",
    "03_iot_security_alert_secrets": "iot_project/03_ifttt_pir/arduino_secrets.h",
    "04_iot_mqtt_callling_secrets":  "iot_project/04_mqtt_button/arduino_secrets.h",
    "05_iot_cheerlights_secrets":    "iot_project/05_cheerlight/arduino_secrets.h",
    "06_iot_weather_oled_secrets":   "iot_project/06_weather_oled/arduino_secrets.h",
    "01_1_connect_to_wifi_secrets":  "r4_new_feature/01-wifi_connect/arduino_secrets.h",
    "01_2_ap_secrets":               "r4_new_feature/01-wifi_ap/arduino_secrets.h",
}


def download():
    os.makedirs(LOCAL_DIR, exist_ok=True)

    success = 0
    failed = []

    for key, repo_path in PROJECTS.items():
        url = f"{BASE_URL}/{repo_path}"
        ext = os.path.splitext(repo_path)[1]  # .ino or .h
        local_path = os.path.join(LOCAL_DIR, f"{key}{ext}")

        try:
            print(f"  [{key}] -> {url}")
            urllib.request.urlretrieve(url, local_path)
            success += 1
        except urllib.error.HTTPError as e:
            print(f"  [FAILED] {key}: HTTP {e.code} — {url}")
            failed.append((key, f"HTTP {e.code}"))
        except Exception as e:
            print(f"  [FAILED] {key}: {e}")
            failed.append((key, str(e)))

    print(f"\n{'='*60}")
    print(f"Downloaded: {success}/{len(PROJECTS)}")
    if failed:
        print(f"Failed ({len(failed)}):")
        for key, reason in failed:
            print(f"  - {key}: {reason}")
    else:
        print("All files downloaded successfully.")
    print(f"Files saved to: {LOCAL_DIR}")

    return len(failed) == 0


if __name__ == "__main__":
    print("Downloading Arduino code from GitHub...\n")
    ok = download()
    sys.exit(0 if ok else 1)
