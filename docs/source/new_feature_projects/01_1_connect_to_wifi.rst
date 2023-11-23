Connect to Wi-Fi
----------------------------------------

This tutorial will guide you through the essential steps to connect your Arduino board to a Wi-Fi network. You'll learn how to initialize the Wi-Fi module, verify its firmware, and securely join a network using its SSID and password. Once connected, you'll discover how to monitor important network details like your device's IP and MAC addresses, as well as the network's signal strength, directly from the serial console. This tutorial serves as both a practical guide to Wi-Fi connectivity and an introduction to network monitoring with Arduino, helping you establish and maintain a reliable Wi-Fi connection.

1. Upload the code
========================

Open the ``01-wifi_connect.ino`` file under the path of ``elite-explorer-kit-main\r4_new_feature\01-wifi_connect``, or copy this code into **Arduino IDE**.

.. note:: 
      Wi-Fi® support is enabled via the built-in ``WiFiS3`` library that is shipped with the Arduino UNO R4 Core. Installing the core automatically installs the ``WiFiS3`` library.


You still need to create or modify ``arduino_secrets.h``, replace ``SECRET_SSID`` and ``SECRET_PASS`` with the name and password of the wifi you want to connect to. The file should contain:

.. code:: arduino

    //arduino_secrets.h header file
    #define SECRET_SSID "yournetwork"
    #define SECRET_PASS "yourpassword"

.. raw:: html
       
   <iframe src=https://create.arduino.cc/editor/sunfounder01/a41ac638-31da-464c-b5d3-e70f2aacd29c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Open the serial monitor, and you will see similar content as follows. Arduino will output your device's IP and MAC addresses, as well as the network's signal strength.

.. image:: img/01_1_wifi.png
    :width: 100%


2. Code explanation
========================

1. Including Libraries and Secret Data

   .. code-block:: arduino

      #include <WiFiS3.h>
      #include "arduino_secrets.h" 

   - ``WiFiS3`` is a library that provides functions for Wi-Fi connectivity. Installing the R4 core automatically installs the WiFiS3 library.
   - ``arduino_secrets.h`` is a separate file where you keep your SSID and password so they're not exposed in your main code. Storing network and password separately reduces accidental sharing of Wi-Fi credentials.

   .. raw:: html

      <br/>

2. Declaring Global Variables

   .. code-block:: arduino

      char ssid[] = SECRET_SSID;
      char pass[] = SECRET_PASS;
      int status = WL_IDLE_STATUS;

   - ``ssid`` and ``pass`` contain your network name and password.
   - ``status`` will store the current status of your Wi-Fi connection.

   .. raw:: html

      <br/>

3. ``setup()`` Function

   The Serial interface is initialized with a baud rate of 9600. The ``while (!Serial);`` line makes sure that the program waits until the Serial connection is established.

   .. code-block:: arduino

      void setup() {
          //Initialize serial and wait for port to open:
          Serial.begin(9600);
          while (!Serial) {
            ; // wait for serial port to connect. Needed for native USB port only
          }
          ...
      }

   And then, the code checks whether the Wi-Fi module is available or not. If not, the program will halt, effectively stopping any further execution.

   .. code-block:: arduino

     ...
     // check for the WiFi module:
     if (WiFi.status() == WL_NO_MODULE) {
         Serial.println("Communication with WiFi module failed!");
         // don't continue
         while (true);
     }
     ...

   In this part of the code, we check if the firmware version of uno R4 wifi is up to date. If it is not the latest version, a prompt for upgrade will be displayed. You can refer to :ref:`update_firmware` for firmware upgrade.

   .. https://forum.arduino.cc/t/radio-module-firmware-version-0-2-0-is-now-available/1147361

   .. code-block:: arduino

      ...
      String fv = WiFi.firmwareVersion();
      if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
          Serial.println("Please upgrade the firmware");
      }
      ...

4. ``loop()`` Function

   .. code-block:: arduino

      void loop() {
        // check the network connection once every 10 seconds:
        delay(10000);
        printCurrentNet();
      }

   - Every 10 seconds, the function ``printCurrentNet()`` is called to print the current network details.


**Reference**

- |link_r4_wifi|