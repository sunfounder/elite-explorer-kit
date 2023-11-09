.. _basic_joystick:

Joystick Module
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/joystick_ps2_uno.html#joystick-uno


Overview
---------------

A joystick is an input device consisting of a stick that pivots on a base and reports its angle or direction to the device it is controlling. Joysticks are often used to control video games and robots. A Joystick PS2 is used here.

Required Components
-------------------------

* :ref:`uno_r4_wifi`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_joystick`


Wiring
----------------------

.. image:: img/20-joystick_bb.png
    :align: center
    :width: 70%

Schematic Diagram
---------------------

This module has two analog outputs (corresponding to X，Y biaxial offsets). 

In this experiment, we use the Uno board to detect the moving direction of the Joystick knob.

.. image:: img/20_joystick_schematic.png
    :align: center 
    :width: 70%

Code
-------

.. note::

    * You can open the file ``20-joystick.ino`` under the path of ``Elite-Explorer-Kit-main\basic_project\20-joystick`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ac0f9910-e53e-43a3-a5ae-ec4d3a3f4aa1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Now, when you push the rocker, the coordinates of the X and Y axes displayed on the Serial Monitor will change accordingly. Pressing the button will also display the coordinate Z=0.


Code Analysis
-------------------

The code is use the serial monitor to print the value of the VRX and VRY pins of the joystick ps2.

.. code-block:: arduino

    void loop()
    {
        Serial.print("X: "); 
        Serial.print(analogRead(xPin), DEC);  // print the value of VRX in DEC
        Serial.print("|Y: ");
        Serial.print(analogRead(yPin), DEC);  // print the value of VRX in DEC
        Serial.print("|Z: ");
        Serial.println(digitalRead(swPin));  // print the value of SW
        delay(50);
    }