# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))


# -- Project information -----------------------------------------------------
import sphinx_rtd_theme
import time

project = 'SunFounder Elite Explorer Kit'
copyright = f'{time.localtime().tm_year}, SunFounder'
author = 'www.sunfounder.com'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = ['sphinx.ext.autosectionlabel'
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_static_path = ['_static']
html_theme = 'sphinx_rtd_theme'
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]


# SunFounder logo

html_js_files = [
   'https://ezblock.cc/readDocFile/custom.js',
    './lang.js', # new
]
html_css_files = [
   'https://ezblock.cc/readDocFile/custom.css',
]

#### RTD+

# html_js_files = [
#     'https://ezblock.cc/readDocFile/custom.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/ace.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/ext-language_tools.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/theme-chrome.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/mode-python.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/mode-sh.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/monokai.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/xterm.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/FitAddon.js',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/js/readTheDocIndex.js',

# ]
# html_css_files = [
#     'https://ezblock.cc/readDocFile/custom.css',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/css/index.css',
#     'https://ezblock.cc/readDocFile/readTheDoc/src/css/xterm.css',
# ]



# Multi-language

language = 'en' # Before running make html, set the language.
locale_dirs = ['locale/'] # .po files for other languages are placed in the locale/ folder.

gettext_compact = False # Support for generating the contents of the folders inside source/ into other languages.



# open link in a new window

rst_epilog = """

.. |link_german_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/elite-explorer-kit/de/latest/" target="_blank">Deutsch Online-Kurs</a>

.. |link_jp_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/elite-explorer-kit/ja/latest/" target="_blank">日本語オンライン教材</a>

.. |link_en_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/elite-explorer-kit/en/latest/" target="_blank">English Online-tutorials</a>


    


.. |link_download_arduino| raw:: html

    <a href="https://www.arduino.cc/en/software" target="_blank">Arduino IDE 2.x Download Page</a>

.. |link_install_arduino_linux| raw:: html

    <a href="https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux" target="_blank"> Installing the Arduino IDE 2 - Linux </a>

.. |link_install_arduino_lib| raw:: html

    <a href="https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-installing-a-library" target="_blank"> Installing libraries in Arduino IDE 2</a>
    
.. |link_ascii| raw:: html

    <a href="https://www.asciitable.com/" target="_blank">ASCII table of characters</a>

.. |link_led_matrix_editor| raw:: html

    <a href="https://ledmatrix-editor.arduino.cc/" target="_blank">Arduino LED Matrix Editor</a>

.. |link_arduino_songs| raw:: html

    <a href="https://github.com/robsoncouto/arduino-songs" target="_blank">robsoncouto/arduino-songs</a>

.. |link_lightblue_apple| raw:: html

    <a href="https://apps.apple.com/us/app/lightblue/id557428110" target="_blank">App Store</a>

.. |link_lightblue_google| raw:: html

    <a href="https://play.google.com/store/apps/details?id=com.punchthrough.lightblueexplorer" target="_blank">Google Play</a>

.. |link_uuid_gen_tool| raw:: html

    <a href="https://www.uuidgenerator.net/version4" target="_blank">uuidgenerator</a>

.. |link_steinhart_hart| raw:: html

    <a href="https://en.wikipedia.org/wiki/Steinhart%E2%80%93Hart_equation" target="_blank">Steinhart-Hart equation</a>
    
.. |link_heat_index| raw:: html

    <a href="https://en.wikipedia.org/wiki/Heat_index" target="_blank">heat index</a>

.. |link_image2cpp| raw:: html

    <a href="http://javl.github.io/image2cpp/" target="_blank">image2cpp</a>

.. |link_arduino-songs| raw:: html

    <a href="https://github.com/robsoncouto/arduino-songs" target="_blank">robsoncouto/arduino-songs</a>    

.. |fastled_color| raw:: html

    <a href="https://github.com/FastLED/FastLED/blob/bb23d6df297cdd0afeec5b7c38628f6d684648e9/src/pixeltypes.h#L662-L823" target="_blank">predefined colors</a> 

.. |link_r4_wifi_datasheet| raw:: html

    <a href="https://docs.arduino.cc/resources/datasheets/ABX00087-datasheet.pdf" target="_blank">Arduino UNO R4 WiFi Datasheet</a> 

.. |link_r4_wifi_schematic| raw:: html

    <a href="https://docs.arduino.cc/resources/schematics/ABX00087-schematics.pdf" target="_blank">Arduino UNO R4 WiFi Schematic</a> 

.. |link_r4_Wifi_doc| raw:: html

    <a href="https://docs.arduino.cc/hardware/uno-r4-wifi" target="_blank">Arduino UNO R4 WiFi Documentation</a> 

.. |link_r4_Wifi_cheatsheet| raw:: html

    <a href="https://docs.arduino.cc/tutorials/uno-r4-wifi/cheat-sheet" target="_blank">Arduino UNO R4 WiFi Cheat Sheet</a> 

.. |link_r4_usb_mouse| raw:: html

    <a href="https://www.arduino.cc/reference/en/language/functions/usb/mouse/" target="_blank">Arduino Reference - Mouse</a> 

.. |link_r4_usb_keyboard| raw:: html

    <a href="https://www.arduino.cc/reference/en/language/functions/usb/keyboard/" target="_blank">Arduino Reference - Keyboard</a> 

.. |link_r4_usb_hid| raw:: html

    <a href="https://docs.arduino.cc/tutorials/uno-r4-wifi/usb-hid" target="_blank">Arduino UNO R4 WiFi USB HID</a> 

.. |link_r4_dac| raw:: html

    <a href="https://docs.arduino.cc/tutorials/uno-r4-wifi/dac" target="_blank">Arduino UNO R4 WiFi Digital-to-Analog Converter (DAC)</a> 

.. |link_r4_led| raw:: html

    <a href="https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix" target="_blank">Using the Arduino UNO R4 WiFi LED Matrix</a> 

.. |link_r4_rtc| raw:: html

    <a href="https://docs.arduino.cc/tutorials/uno-r4-wifi/rtc" target="_blank">Arduino UNO R4 WiFi Real-Time Clock</a> 

.. |link_r4_bluetooth| raw:: html

    <a href="https://www.arduino.cc/reference/en/libraries/arduinoble/" target="_blank">Arduino Reference - ArduinoBLE</a> 

.. |link_r4_wifi| raw:: html

    <a href="https://docs.arduino.cc/tutorials/uno-r4-wifi/wifi-examples" target="_blank">UNO R4 WiFi Network Examples</a> 

.. |link_update_firmware| raw:: html

    <a href="https://forum.arduino.cc/t/radio-module-firmware-version-0-2-0-is-now-available/1147361#updating-the-firmware-on-your-board-1" target="_blank">Updating the Firmware on Your Board</a> 

.. |link_appinventor| raw:: html

    <a href="http://appinventor.mit.edu/" target="_blank">MIT App Inventor</a>

.. |link_appinventor_login| raw:: html

    <a href="http://appinventor.mit.edu/explore/get-started" target="_blank">Get Started with MIT App Inventor</a>

.. |link_sig_environmental_sensing| raw:: html

    <a href="https://bitbucket.org/bluetooth-SIG/public/src/8a7ea26ae56d43e6fea88693232a01a78e28213e/assigned_numbers/uuids/service_uuids.yaml#lines-104:105" target="_blank">environmentalSensingService</a>

.. |link_sig_temperature_humidity| raw:: html

    <a href="https://bitbucket.org/bluetooth-SIG/public/src/8a7ea26ae56d43e6fea88693232a01a78e28213e/assigned_numbers/uuids/characteristic_uuids.yaml#lines-299:304" target="_blank">temperature and humidity</a>

.. |link_bluetooth_sig| raw:: html

    <a href="https://www.bluetooth.com/specifications/assigned-numbers/" target="_blank">Bluetooth SIG</a>

.. |link_github_elite| raw:: html

    <a href="https://github.com/sunfounder/Elite-Explorer-Kit" target="_blank">SunFounder Elite Explorer Kit - GitHub</a>

.. |link_pitches| raw:: html

    <a href="https://github.com/sunfounder/Elite-Explorer-Kit/blob/main/basic_project/16-passive_buzzer/pitches.h" target="_blank">pitches.h</a>

.. |link_ifttt| raw:: html

    <a href="https://ifttt.com/explore" target="_blank">IFTTT</a>

.. |link_webhooks| raw:: html

    <a href="https://ifttt.com/maker_webhooks/settings" target="_blank">Webhooks Settings</a>

.. |link_hivemq| raw:: html

    <a href="http://www.hivemq.com/demos/websocket-client/" target="_blank">HiveMQ Web Client</a>

.. |link_cheerlights| raw:: html

    <a href="https://twitter.com/cheerlights" target="_blank">@CheerLights - Twitter</a>

.. |link_discord_server| raw:: html

    <a href="https://discord.com/invite/G7Q5UjDT7K" target="_blank">Discord Server</a>

.. |link_breadboard_tutorials| raw:: html

    <a href="https://www.sciencebuddies.org/science-fair-projects/references/how-to-use-a-breadboard" target="_blank">How to Use a Breadboard - Science Buddies</a>

.. |link_s8050_datasheet| raw:: html

    <a href="https://datasheet4u.com/datasheet-pdf/WeitronTechnology/S8050/pdf.php?id=576670" target="_blank">S8050 Transistor Datasheet</a>

.. |link_s8550_datasheet| raw:: html

    <a href="https://www.mouser.com/datasheet/2/149/SS8550-118608.pdf" target="_blank">S8550 Transistor Datasheet</a>

.. |link_general_purpose_diode| raw:: html

    <a href="https://en.wikipedia.org/wiki/1N400x_general-purpose_diode" target="_blank">1N400x general-purpose diode - Wikipedia</a>

.. |link_zener_diode| raw:: html

    <a href="https://en.wikipedia.org/wiki/Zener_diode" target="_blank">Zener diode - Wikipedia</a>

.. |link_led_wiki| raw:: html

    <a href="https://en.wikipedia.org/wiki/Light-emitting_diode" target="_blank">LED - Wikipedia</a>

.. |link_ws2812b_datasheet| raw:: html

    <a href="https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" target="_blank">WS2812B Datasheet</a>

.. |link_pcf8574_datasheet| raw:: html

    <a href="https://www.ti.com/lit/ds/symlink/pcf8574.pdf" target="_blank">PCF8574 Datasheet</a>

.. |link_buzzer_wiki| raw:: html

    <a href="https://en.wikipedia.org/wiki/Buzzer" target="_blank">Buzzer - Wikipedia</a>

.. |link_potentiometer_wiki| raw:: html

    <a href="https://en.wikipedia.org/wiki/Potentiometer" target="_blank">Potentiometer - Wikipedia</a>

.. |link_mpr121_datasheet| raw:: html

    <a href="https://cdn-shop.adafruit.com/datasheets/MPR121.pdf" target="_blank">MPR121 Datasheet</a>

.. |link_photoresistor_wiki| raw:: html

    <a href="https://en.wikipedia.org/wiki/Photoresistor" target="_blank">Photoresistor - Wikipedia</a>

.. |link_thermistor_wikipedia| raw:: html

    <a href="https://en.wikipedia.org/wiki/Thermistor" target="_blank">Thermistor - Wikipedia</a>

.. |link_sw520d_datasheet| raw:: html

    <a href="https://www.tme.com/Document/f1e6cedd8cb7feeb250b353b6213ec6c/SW-520D.pdf" target="_blank">SW520D Tilt Switch Datasheet</a>

.. |link_dht11_datasheet| raw:: html

    <a href="https://components101.com/sites/default/files/component_datasheet/DHT11-Temperature-Sensor.pdf" target="_blank">DHT11 Datasheet</a>

.. |link_74hc595_datasheet| raw:: html

    <a href="https://www.ti.com/lit/ds/symlink/cd74hc595.pdf?ts=1617341564801" target="_blank">74HC595 Datasheet</a>

.. |link_FastLED_lib| raw:: html

    <a href="https://github.com/FastLED/FastLED" target="_blank">FastLED</a>

"""




# Purchase links of components

rst_epilog += """
 
.. |link_Elite_Explorer_kit| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-elite-explorer-kit-with-official-arduino-uno-r4-wifi" target="_blank">Elite Explorer Kit</a>

    


.. |link_Uno_R3_buy| raw:: html

    <a href="https://www.sunfounder.com/products/arduino-unor3-control-board" target="_blank">BUY</a>

.. |link_esp8266_buy| raw:: html

    <a href="https://www.sunfounder.com/products/esp01-esp-01s-programmer-adapter-serial-high-speed-esp8266-ch340g-usb-to-esp8266-serial-wireless-wifi-developent-board" target="_blank">BUY</a>

.. |link_picow_buy| raw:: html

    <a href="https://www.sunfounder.com/products/raspberry-pi-pico-w" target="_blank">BUY</a>
    
.. |link_led_buy| raw:: html

    <a href="https://www.sunfounder.com/products/500pcs-5-colors-x-100pcs-5mm-leds-with-white-red-yellow-green-blue-colors-kit-box" target="_blank">BUY</a>

.. |link_resistor_buy| raw:: html

    <a href="https://www.sunfounder.com/products/1-4w-resistor-assortment-kit-40-values-400pcs" target="_blank">BUY</a>

.. |link_wires_buy| raw:: html

    <a href="https://www.sunfounder.com/products/560pcs-jumper-wire-kit-with-14-lengths" target="_blank">BUY</a>

.. |link_breadboard_buy| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-breadboard-kit" target="_blank">BUY</a>

.. |link_rgb_led_buy| raw:: html

    <a href="https://www.sunfounder.com/products/100pcs-5mm-4-pin-rgb-common-cathode-led" target="_blank">BUY</a>

.. |link_button_buy| raw:: html

    <a href="https://www.sunfounder.com/products/100pcs-6x6x5-mm-miniature-push-button" target="_blank">BUY</a>

.. |link_capacitor_buy| raw:: html

    <a href="https://www.sunfounder.com/products/ceramic-capacitor-assortment-kit-set-of-600-small-assorted-capacitors" target="_blank">BUY</a>

.. |link_potentiometer_buy| raw:: html

    <a href="https://www.sunfounder.com/products/10pcs-10k-ohm-trim-potentiometer-breadboard" target="_blank">BUY</a>

.. |link_photoresistor_buy| raw:: html

    <a href="https://www.sunfounder.com/products/100pcs-photoresistor-photo-light-sensitive-resistor-5516" target="_blank">BUY</a>

.. |link_thermistor_buy| raw:: html

    <a href="https://www.sunfounder.com/products/50pcs-ntc-thermistor-mf11-103-10k-ohm" target="_blank">BUY</a>

.. |link_transistor_buy| raw:: html

    <a href="https://www.sunfounder.com/products/10-values-200pcs-power-supply-general-transistor-npn-pnp-assortment-kit-bc337-bc327-2n2222-2n2907-2n3904-2n3906-s8050-s8550-a1015-c1815-set" target="_blank">BUY</a>

.. |link_relay_buy| raw:: html

    <a href="https://www.sunfounder.com/products/10pcs-srs-05vdc-sl-c-5v-relay-coil-spdt-6-pin-pcb-electromagnetic-power-relay" target="_blank">BUY</a>

.. |link_passive_buzzer_buy| raw:: html

    <a href="https://www.sunfounder.com/products/20pcs-3-5v-2-terminals-passive-buzzer" target="_blank">BUY</a>

.. |link_ws2812_buy| raw:: html

    <a href="https://www.sunfounder.com/products/2pcs-8-bit-ws2812b-rgb-led-strip-5050smd-individual-addressable-60pixels-m" target="_blank">BUY</a>

.. |link_i2clcd1602_buy| raw:: html

    <a href="https://www.sunfounder.com/products/i2c-lcd1602-module" target="_blank">BUY</a>

.. |link_motor_buy| raw:: html

    <a href="https://www.sunfounder.com/products/5pcs-1-5v-6v-type-miniature-dc-motors" target="_blank">BUY</a>

.. |link_servo_buy| raw:: html

    <a href="https://www.sunfounder.com/products/sg90-micro-digital-servo" target="_blank">BUY</a>

.. |link_keypad_buy| raw:: html

    <a href="https://www.sunfounder.com/products/membrane-switch-keypad" target="_blank">BUY</a>

.. |link_74hc595_buy| raw:: html

    <a href="https://www.sunfounder.com/products/10-pcs-ic-74hc595-74595-sn74hc595n-8-bit-shift-register-dip-16" target="_blank">BUY</a>

.. |link_7segment_buy| raw:: html

    <a href="https://www.sunfounder.com/products/30pcs-0-56-7-segment-led" target="_blank">BUY</a>

.. |link_ultrasonic_buy| raw:: html

    <a href="https://www.sunfounder.com/products/5pcs-hc-sr04-ultrasonic-module-distance-sensor" target="_blank">BUY</a>

.. |link_dht22_buy| raw:: html

    <a href="https://www.sunfounder.com/products/dht22-am2302-digital-temperature-and-humidity-sensor" target="_blank">BUY</a>

.. |link_receiver_buy| raw:: html

    <a href="https://www.sunfounder.com/products/infrared-receiver-module" target="_blank">BUY</a>

.. |link_rfid_buy| raw:: html

    <a href="https://www.sunfounder.com/products/rfid-kit-blue" target="_blank">BUY</a>

.. |link_pir_buy| raw:: html

    <a href="https://www.sunfounder.com/products/hcsr501-infrared-sensor?_pos=1&_sid=2bd5fd3cc&_ss=r" target="_blank">BUY</a>

.. |link_gpio_board_buy| raw:: html

    <a href="https://www.sunfounder.com/products/t-shape-gpio-extension-board" target="_blank">BUY</a>

.. |link_led_matrix_buy| raw:: html

    <a href="https://www.sunfounder.com/products/aceirmc-4pcs-max7219-dot-matrix-display-module-single-chip-control-led-module-diy-kit-for-arduino-with-5pin-line" target="_blank">BUY</a>

.. |link_diode_buy| raw:: html

    <a href="https://www.sunfounder.com/products/100pcs-1n4007-4007-1a-1000v-do-41-high-quality-rectifier-diode-in4007-1n4007" target="_blank">BUY</a>

.. |link_touch_buy| raw:: html

    <a href="https://www.sunfounder.com/products/ttp223-touch-sensor-module" target="_blank">BUY</a>

.. |link_slide_switch_buy| raw:: html

    <a href="https://www.sunfounder.com/products/10pcs-high-knob-3-pin-2-position-breadboard-friendly-spdt-slide-switch" target="_blank">BUY</a>    

.. |link_rotary_encoder_buy| raw:: html

    <a href="https://www.sunfounder.com/products/rotary-encoder-module" target="_blank">BUY</a>

.. |link_humiture_buy| raw:: html

    <a href="https://www.sunfounder.com/products/humiture-sensor-module" target="_blank">BUY</a>

.. |link_reed_switch_buy| raw:: html

    <a href="https://www.sunfounder.com/products/reed-switch-module" target="_blank">BUY</a>

.. |link_obstacle_avoidance_buy| raw:: html

    <a href="https://www.sunfounder.com/products/obstacle-avoidance-sensor" target="_blank">BUY</a>

.. |link_mpu6050_buy| raw:: html

    <a href="https://www.sunfounder.com/products/3pcs-gy-521-mpu-6050-mpu6050-3-axis-accelerometer-gyroscope-module-6-dof-6-axis-accelerometer-gyroscope-sensor-module-16-bit-ad-converter-data-output-iic-i2c-for-arduino" target="_blank">BUY</a>
    
.. |link_mfrc522_rfid_buy| raw:: html

    <a href="https://www.sunfounder.com/products/rfid-kit-blue" target="_blank">BUY</a>

.. |link_camera_buy| raw:: html

    <a href="https://www.sunfounder.com/products/5mp-1080p-camera" target="_blank">BUY</a>   

.. |link_track_buy| raw:: html

    <a href="https://www.sunfounder.com/products/tracking-sensor-module" target="_blank">BUY</a>       

.. |link_soil_moisture_buy| raw:: html

    <a href="https://www.sunfounder.com/products/capacitive-soil-moisture-sensor-module?_pos=1&_sid=73e23dc8a&_ss=r" target="_blank">BUY</a>       

.. |link_l298n_buy| raw:: html

    <a href="https://www.sunfounder.com/products/l298n-motor-driver-board" target="_blank">BUY</a>

.. |link_oled_buy| raw:: html

    <a href="https://www.sunfounder.com/products/0-96-oled-display-module-ssd1306-128x64-blue-display" target="_blank">BUY</a>   

.. |link_joystick_buy| raw:: html

    <a href="https://www.sunfounder.com/products/dual-axis-button-joystick-module-ps2-game" target="_blank">BUY</a>      

.. |link_stepper_motor_buy| raw:: html

    <a href="https://www.sunfounder.com/products/dc-5v-stepper-motor-28byj-48-uln2003-drive-module-5-line-4-phase" target="_blank">BUY</a>      

.. |link_realy_buy| raw:: html

    <a href="https://www.sunfounder.com/products/10pcs-srs-05vdc-sl-c-5v-relay-coil-spdt-6-pin-pcb-electromagnetic-power-relay" target="_blank">BUY</a>   

"""
