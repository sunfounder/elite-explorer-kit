.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _basic_ws2812:

WS2812 RGB LEDs Strip
==========================

Overview
---------------

In this lesson, you will learn about NeoPixel LEDs and how to control them using the FastLED library on an Arduino Uno R4. NeoPixel LEDs are widely used in various applications like home decor, wearables, and event lighting. The FastLED library simplifies the process of programming these LEDs. Here, a chain of 8 NeoPixel LEDs is connected to an Arduino, and each LED in the sequence is lit up in blue color momentarily before turning off, moving on to the next LED in the chain. This basic example can serve as the foundation for more complex light patterns or interactive lighting projects.

Required Components
-------------------------

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

Wiring
----------------------

.. image:: img/12-ws2812_bb.png
    :align: center

Schematic Diagram
-----------------------

.. image:: img/12_ws2812_schematic.png
    :align: center
    :width: 80%

Code
---------------

.. note::

    * You can open the file ``12-ws2812.ino`` under the path of ``elite-explorer-kit-main\basic_project\12-ws2812`` directly.
    * Or copy this code into Arduino IDE.

.. note:: 
    To install the library, use the Arduino Library Manager and search for **"FastLED"** and install it. 

.. important::
    With the release of |link_fastled_3_7_0|, the FastLED library now officially supports the Arduino UNO R4. Therefore, you no longer need to manually install the development version. Simply update or install the FastLED library using the Arduino Library Manager.

.. warning::
    **[Outdated]** Since the |link_FastLED_lib| library has not officially released a version supporting Arduino R4 yet, you'll need to download :download:`the latest development code of the FastLED library <https://codeload.github.com/FastLED/FastLED/zip/refs/heads/master>` and overwrite the existing FastLED library files. For detailed instructions on how to do this, please refer to the :ref:`manual_install_lib` section. (This note will be retracted when the FastLED library officially releases an update that supports the Arduino UNO R4.)




.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6c9b8c2c-6cea-4ea8-a959-e579ca98f35d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/12_basic_ws2812.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

After the code is uploaded successfully, you will see each LED in the chain of 8 NeoPixel LEDs light up one at a time in a blue color. The program will loop through this sequence continuously, turning off each LED before moving on to the next. With a short delay between each LED, the lighting effect will appear as a traveling blue dot along the chain.


Code Analysis
------------------------

1. Import Library and Setup Constants

   - Importing the ``FastLED`` library to use its functions.
   - Defining the number of LEDs and the data pin they are connected to.
   
   .. code-block:: arduino
   
      #include <FastLED.h>  // Include FastLED library
      #define NUM_LEDS 8    // Number of LEDs in the chain
      #define DATA_PIN 6    // Data pin for LED control

2. Initialize LED Array
   
   Creating an array of ``CRGB`` type to store the color information of each LED.

   .. code-block:: arduino

      CRGB leds[NUM_LEDS];  // Array to hold LED color data

3. Initialize LEDs in Setup

   Using ``FastLED.addLeds`` to initialize the LEDs.

   .. code-block:: arduino

      void setup() {
        FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Initialize LEDs
      }

4. Control LEDs in Loop
   
   Looping through each LED to set it to blue, display it, clear it, and then delay.

   - The ``leds`` array serves as a color buffer for your LED strip. Each element in this array corresponds to an individual LED on your physical strip, and its color value determines the color that the LED will display. The order of elements in the array matches the order of LEDs on the strip, starting from the first LED (which corresponds to ``leds[0]``) through to the last LED. To change the color of a specific LED on your strip, you simply modify the corresponding element in the ``leds`` array. You can use |fastled_color| or set colors using RGB (Taking green as an example, use ``leds[dot] = CRGB::Green`` or ``leds[dot] = CRGB(0, 255, 0);``).

   - The ``FastLED.show();`` function updates the LED strip with new color data, making changes visible. It is like hitting the "publish" button for your LED strip after making edits and adjustments in the code.

   .. raw:: html

     <br/>

   .. code-block:: arduino

      void loop() {
        for (int dot = 0; dot < NUM_LEDS; dot++) {
          leds[dot] = CRGB::Blue;   // Set the current LED to blue
          FastLED.show();           // Update LEDs
          leds[dot] = CRGB::Black;  // Clear the current LED
          delay(30);                // Wait for a short period before moving to the next LED
        }
      }