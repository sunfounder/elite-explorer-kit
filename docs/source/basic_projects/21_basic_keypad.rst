.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _basic_keypad:

Keypad
==========================

.. https://docs.sunfounder.com/projects/vincent-kit-de/en/latest/arduino/2.19_keypad.html#ar-keypad

Overview
-------------

In this lesson, you will learn to use Keypad. Keypad can be applied into various kinds of devices, including mobile phone, fax machine, microwave oven and so on. It is commonly used in user input.

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
    *   - :ref:`cpn_keypad`
        - |link_keypad_buy|

Wiring
----------------------

.. image:: img/21-keypad_bb.png
    :align: center

Schematic Diagram
----------------------

.. image:: img/21_keypad_schematic.png
   :align: center
   :width: 70%

Code
-----------


.. note::

    * You can open the file ``21-keypad.ino`` under the path of ``elite-explorer-kit-main\basic_project\21-keypad`` directly.
    * To install the library, use the Arduino Library Manager and search for **"Adafruit Keypad"** and install it. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/25fd4116-92d4-4ee4-b3ba-6707f4334629/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After uploading the codes to the UNO board, on the serial monitor, you can see the value of the key currently pressed on the Keypad.

Code Analysis
-------------------

1. Including the Library

   We start by including the ``Adafruit_Keypad`` library, which allows us to easily interface with the keypad.

   .. code-block:: arduino

     #include "Adafruit_Keypad.h"

   .. note::

      * To install the library, use the Arduino Library Manager and search for **"Adafruit Keypad"** and install it. 


2. Keypad Configuration

   .. code-block:: arduino

     const byte ROWS = 4;
     const byte COLS = 4;
     char keys[ROWS][COLS] = {
       { '1', '2', '3', 'A' },
       { '4', '5', '6', 'B' },
       { '7', '8', '9', 'C' },
       { '*', '0', '#', 'D' }
     };
     byte rowPins[ROWS] = { 2, 3, 4, 5 };
     byte colPins[COLS] = { 8, 9, 10, 11 };

   - The ``ROWS`` and ``COLS`` constants define the dimensions of the keypad. 
   - ``keys`` is a 2D array storing the label for each button on the keypad.
   - ``rowPins`` and ``colPins`` are arrays that store the Arduino pins connected to the keypad rows and columns.

   .. raw:: html

      <br/>


3. Initialize Keypad

   Create an instance of ``Adafruit_Keypad`` called ``myKeypad`` and initialize it.

   .. code-block:: arduino

     Adafruit_Keypad myKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

4. setup() Function

   Initialize Serial communication and the custom keypad.

   .. code-block:: arduino

     void setup() {
       Serial.begin(9600);
       myKeypad.begin();
     }

5. Main Loop

   Check for key events and display them in the Serial Monitor.

   .. code-block:: arduino

     void loop() {
       myKeypad.tick();
       while (myKeypad.available()) {
         keypadEvent e = myKeypad.read();
         Serial.print((char)e.bit.KEY);
         if (e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed");
         else if (e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");
       }
       delay(10);
     }

