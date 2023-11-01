.. _basic_ws2812:

WS2812 RGB LEDs Strip
==========================


.. https://docs.sunfounder.com/projects/euler-kit/en/latest/cproject/ar_neopixel.html#ar-neopixel

Overview
---------------

In this lesson, you will learn about NeoPixel LEDs and how to control them using the FastLED library on an Arduino Uno R4. NeoPixel LEDs are widely used in various applications like home decor, wearables, and event lighting. The FastLED library simplifies the process of programming these LEDs. Here, a chain of 8 NeoPixel LEDs is connected to an Arduino, and each LED in the sequence is lit up in blue color momentarily before turning off, moving on to the next LED in the chain. This basic example can serve as the foundation for more complex light patterns or interactive lighting projects.

Required Components
-------------------------

* :ref:`uno_r4_wifi`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_ws2812`

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

    * You can open the file ``12-ws2812.ino`` under the path of ``Elite-Explorer-Kit-main\basic_project\12-ws2812`` directly.
    * Or copy this code into Arduino IDE.

.. note:: 
    To install the library, use the Arduino Library Manager and search for **"FastLED"** and install it. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6c9b8c2c-6cea-4ea8-a959-e579ca98f35d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

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