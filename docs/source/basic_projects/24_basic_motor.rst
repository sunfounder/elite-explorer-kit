.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _basic_motor:

Motor
==========================

Overview
--------

In this lesson, you will learn how to use Motor, the working principle of which is that the energized coil is forced to rotate in the magnetic field then the rotor of the motor rotates accordingly on which the pinion gear drives the engine flywheel to rotate.1

Required Components
-------------------

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
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_power`
        - \-

Wiring
----------------------

In this example, we use Power Supply Module to power the anode and cathode of breadboard.

.. note::
    To protect the :ref:`cpn_power`'s battery, please fully charge it before using it for the first time.

.. image:: img/24-motor_bb.png
    :align: center
    :width: 80%

.. raw:: html
  
  <br/> 

Schematic Diagram
-----------------

.. image:: img/24_motor_schematic.png
    :align: center
    :width: 100%

.. raw:: html
  
  <br/> 

Code
----

.. note::

    * You can open the file ``24-motor.ino`` under the path of ``elite-explorer-kit-main\basic_project\24-motor`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7376df09-204d-4698-b2a6-106e2d2f00e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After uploading the code to the UNO board, you can choose the motor's rotation direction by typing "A" or "B" in the serial monitor.


Code Analysis
--------------------------


The motor can be driven by providing a voltage difference between the copper sheets at both sides of the motor. 
Therefore, you only need to write 0 for the voltage of one side of the copper sheet and 5V for the other side. Modify the written analog signal value to adjust the direction and speed.

.. code-block:: arduino

   // Function to rotate the motor clockwise
   void clockwise(int Speed) {
     analogWrite(motorBI, 0);
     analogWrite(motorFI, Speed);
   }
   
   // Function to rotate the motor anticlockwise
   void anticlockwise(int Speed) {
     analogWrite(motorBI, Speed);
     analogWrite(motorFI, 0);
   }

In this example, Serial.Read() is used to control the direction of motor. 

When you type \'A\' in serial monitor, there calls the clockwise (255) function to make the motor rotate with the speed of 255.
Input \'B\', and the motor will rotate in reverse direction.

.. code-block:: arduino

   void loop() {
     // Check if there is available data on the serial port
     if (Serial.available() > 0) {
       int incomingByte = Serial.read(); // Read incoming data
       
       // Determine motor direction based on user input
       switch (incomingByte) {
         case 'A':
           clockwise(255); // Rotate motor clockwise
           Serial.println("The motor rotates clockwise.");
           break;
         case 'B':
           anticlockwise(255); // Rotate motor anticlockwise
           Serial.println("The motor rotates anticlockwise.");
           break;
       }
     }
     
     delay(3000); // Wait for 3 seconds
     stopMotor(); // Stop the motor
   }

