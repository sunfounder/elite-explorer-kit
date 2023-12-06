.. _basic_button:

Button
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/controlling_led_by_button_uno.html#button-uno


Overview
----------------

In this lesson, you will learn about controlling an LED using a button with Arduino. Buttons and LEDs are fundamental components in a wide range of electronic devices, such as remote controls, flashlights, and interactive installations. In this setup, a button is used as an input device to control the state of an LED, which serves as an output device.

The button is connected to pin 12 on the Arduino Uno R4 board, and the LED is connected to pin 13. When the button is pressed, a signal is sent to the Arduino, triggering the LED to turn on. Conversely, when the button is released, the LED turns off. This simple yet effective mechanism can be the basis for more complex projects, such as home automation systems, interactive displays, and much more.

By the end of this lesson, you will understand how to read input from a button and use it to control an LED, thereby gaining a foundational understanding of input/output operations with Arduino.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|


Wiring
----------------------

.. image:: img/18-button_bb.png
    :align: center
    :width: 70%


Schematic Diagram
------------------------

Connect one end of the buttons to pin 12 which connects with a pull-down resistor and a 0.1uF (104) capacitor (to eliminate jitter and output a stable level when the button is working). Connect the other end of the resistor to GND and one of the pins at the other end of the button to 5V. When the button is pressed, pin 12 is 5V (HIGH) and set pin 13 (integrated with an LED) as High at the same time. Then release the button (pin 12 changes to LOW) and pin 13 is Low. So we will see the LED lights up and goes out alternately as the button is pressed and released.

.. image:: img/18_button_schematic.png
    :align: center
    :width: 70%


Code
---------------

.. note::

    * You can open the file ``18-button.ino`` under the path of ``elite-explorer-kit-main\basic_project\18-button`` directly.
    * Or copy this code into Arduino IDE.




.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a710eb54-9447-4542-ac98-c9a7e1ec4256/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    


Code Analysis
-------------------

#. Define Constants and Variables

   In this segment, the pin numbers for the button and the LED are defined. Also, a variable ``buttonState`` is declared to hold the current state of the button.
 
   .. code-block:: arduino
 
     const int buttonPin = 12;
     const int ledPin = 13;
     int buttonState = 0;

#. Setup Function

   The ``setup()`` function runs once when the Arduino board starts. The pin modes for the button and the LED are set using the ``pinMode`` function.
 
   .. code-block:: arduino
 
     void setup() {
       pinMode(buttonPin, INPUT);
       pinMode(ledPin, OUTPUT);
     }

#. Main Loop

   The ``loop()`` function runs repeatedly. Inside this loop, the ``digitalRead()`` function is used to read the state of the button. Depending on whether the button is pressed or not, the LED is turned on or off.
 
   .. code-block:: arduino
 
     void loop() {
       buttonState = digitalRead(buttonPin);
       if (buttonState == HIGH) {
         digitalWrite(ledPin, HIGH);
       } else {
         digitalWrite(ledPin, LOW);
       }
     }