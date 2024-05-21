.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _iot_cherrylight:

CherryLight
===============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/05_iot_cheerlights.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

CheerLights is a global network of synchronized lights that can be controlled by anyone. Join the |link_cheerlights| LED color-changing community, which allows LEDs around the world to change colors simultaneously.  Place your LEDs in a corner of your office to remind yourself that you are not alone.

In this case, we also utilize MQTT, but instead of publishing our own messages, we subscribe to the "cheerlights" topic. This allows us to receive messages sent by others to the "cheerlights" topic and use that information to change the color of our LED strip accordingly.

**Required Components**

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Wiring**

.. image:: img/05_cheerlight_bb.png
    :width: 100%
    :align: center

**Schematic**

.. image:: img/05_cheerlight_schematic.png
    :width: 50%
    :align: center

.. raw:: html

   <br/>

**Install the Library**

To install the library, use the Arduino Library Manager and search for "ArduinoMqttClient" and "FastLED" and install them.

``ArduinoMqttClient.h``: Used for MQTT communication.

``FastLED.h``: Used to drive the RGB LED Strip.

.. warning::
    Since the |link_FastLED_lib| library has not officially released a version supporting Arduino R4 yet, you'll need to download :download:`the latest development code of the FastLED library <https://codeload.github.com/FastLED/FastLED/zip/refs/heads/master>` and overwrite the existing FastLED library files. For detailed instructions on how to do this, please refer to the :ref:`manual_install_lib` section. (This note will be retracted when the FastLED library officially releases an update that supports the Arduino UNO R4.)

**Run the Code**


.. note::

    * You can open the file ``05_cheerlight.ino`` under the path of ``elite-explorer-kit-main\iot_project\05_cheerlight`` directly.
    * Or copy this code into Arduino IDE.

.. note::
    In the code, SSID and password are stored in ``arduino_secrets.h``. Before uploading this example, you need to modify them with your own WiFi credentials. Additionally, for security purposes, ensure that this information is kept confidential when sharing or storing the code.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/9d7ad736-9725-499f-a6ea-91602120d53e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>




**Control global @CheerLights devices**

#. Join the |link_discord_server| and utilize the CheerLights bot to set the color. Simply type ``/cheerlights`` in any of the channels on the **CheerLights Discord Server** to activate the bot.

   .. image:: img/05_iot_cheerlights_1.png

#. Follow the instructions provided by the bot to set the color. This will allow you to control CheerLights devices globally.

   .. image:: img/05_iot_cheerlights_2.png

**How it works?**

Here are the main parts of the code and explanations of their functions:

1. Include the required libraries:

   * ``WiFiS3.h``: Used for handling Wi-Fi connections.
   * ``ArduinoMqttClient.h``: Used for handling MQTT connections.
   * ``FastLED.h``: Used for controlling NeoPixel LED strips.

2. Define some constants:

   * ``NUM_LEDS``: The number of LEDs on the LED strip.
   * ``DATA_PIN``: The data pin connected to Arduino for controlling the LED strip.
   * ``arduino_secrets.h``: Header file containing Wi-Fi network name and password to protect sensitive information.
   * ``broker``: Address of the MQTT server.
   * ``port``: Port of the MQTT server.
   * ``topic``: The MQTT topic to subscribe to.

3. Define some global variables:

   * ``CRGB leds[NUM_LEDS]``: An array to store LED color data.
   * ``colorName``: An array of color names supported by the CheerLights project.
   * ``colorRGB``: An array of RGB color codes corresponding to color names.

4. ``setup()`` function:

   * Initialize serial communication.
   * Check if the Wi-Fi module is present and output its firmware version.
   * Attempt to connect to the Wi-Fi network; if it fails, wait 10 seconds and retry.
   * Upon successful connection, connect to the MQTT broker (server) and subscribe to the specified topic.
   * Initialize the NeoPixel LED strip.

5. ``loop()`` function:

   * Periodically call the ``mqttClient.poll()`` function to receive MQTT messages and send MQTT keep-alive signals.
   * Add a 5-second delay to avoid continuous connection.

6. ``printWifiData()`` and ``printCurrentNet()`` functions are used to output Wi-Fi network and connection information.

7. ``printMacAddress()`` function is used to print the MAC address in hexadecimal format.

8. ``onMqttMessage()`` function is a callback function triggered when an MQTT message is received. It outputs the received topic and message content, converting the message content to lowercase. If the topic is "cheerlights," it calls the ``setColor()`` function to set the LED strip color.

9. ``setColor()`` function takes a color name as a parameter, then looks for a matching color in the ``colorName`` array. If a matching color is found, it sets the LED strip's color to the corresponding RGB value and updates the LED strip's color using the ``FastLED.show()`` function.
