.. _iot_projects:

IoT 项目
====================

Elite Explorer 套件利用 Arduino UNO R4 WiFi 板上内置的 ESP32-S3 WiFi 和蓝牙模块，实现了各种简单有趣的 IoT 项目。WiFi 连接使您可以将 Arduino 连接到互联网和云平台进行 IoT 实验。而蓝牙则提供了短距离无线通信能力。

通过 WiFi，您可以构建诸如：用于远程控制 LED 的简单网页服务器、与 Arduino IoT Cloud 交互以监测传感器、使用 PIR 传感器通过 IFTTT 创建安全警报，以及使用 MQTT 制作基于云的呼叫系统等项目。我们提供了逐步指南来实现这些及其他联网 IoT 项目。

蓝牙功能可实现本地无线项目，例如在 LCD 屏幕上交换消息、在智能手机应用上监测来自传感器的温度和湿度数据。

.. toctree::
   :maxdepth: 1

   01_iot_webserver
   02_iot_arduino_iot_cloud
   03_iot_security_alert
   04_iot_mqtt_callling
   05_iot_cheerlights
   06_iot_weather_oled
   07_iot_ble_lcd
   08_iot_ble_home
