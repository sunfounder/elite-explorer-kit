.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _basic_servo:

Servo
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/servo_uno.html#servo-uno

Overview
---------------

In this lesson, you will explore the use of Arduino and Servo Motors. Focusing on the Arduino Uno and the SG90 servo motor, you'll learn how to program the Arduino to control the servo's sweeping motion. This technique is essential in various applications like robotics and automated systems.

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

Wiring
----------------------

.. image:: img/27-servo_bb.png
    :align: center
    :width: 70%

.. raw:: html

   <br/>

Schematic Diagram
-----------------------

.. image:: img/27_servo_schematic.png
    :align: center
    :width: 60%

Code
---------------

.. note::

    * You can open the file ``27-servo.ino`` under the path of ``elite-explorer-kit-main\basic_project\27-servo`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c57ddb7a-0acb-4a64-938a-0a0abfc0ec4b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Code Analysis
------------------------


1. Here, the ``Servo`` library is included which allows for easy control of the servo motor. The pin connected to the servo and the initial angle of the servo are also defined.

   .. code-block:: arduino

      #include <Servo.h>
      const int servoPin = 9;  // Define the servo pin
      int angle = 0;           // Initialize the angle variable to 0 degrees
      Servo servo;             // Create a servo object

2. The ``setup()`` function runs once when the Arduino starts. The servo is attached to the defined pin using the ``attach()`` function.

   .. code-block:: arduino

      void setup() {
        servo.attach(servoPin);
      }

3. The main loop has two ``for`` loops. The first loop increases the angle from 0 to 180 degrees, and the second loop decreases the angle from 180 to 0 degrees. The ``servo.write(angle)`` command sets the servo to the specified angle. The ``delay(15)`` causes the servo to wait for 15 milliseconds before moving to the next angle, controlling the speed of the scanning movement.

   .. code-block:: arduino

      void loop() {
        // scan from 0 to 180 degrees
        for (angle = 0; angle < 180; angle++) {
          servo.write(angle);
          delay(15);
        }
        // now scan back from 180 to 0 degrees
        for (angle = 180; angle > 0; angle--) {
          servo.write(angle);
          delay(15);
        }
      }