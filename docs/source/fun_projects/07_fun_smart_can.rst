.. _fun_smart_can:

Smart Can
=====================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/07_fun_smartcan.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

This is an Arduino code designed to control a smart garbage can. 
When an object is within a 20-centimeter range in front of the garbage can, its lid automatically opens. 
This project utilizes an SG90 servo motor and an HC-SR04 ultrasonic distance sensor.

**Required Components**

* :ref:`uno_r4_wifi`
* :ref:`cpn_wires`
* :ref:`cpn_breadboard`
* :ref:`cpn_servo`
* :ref:`cpn_ultrasonic`

**Wiring**

.. image:: img/07_smart_trash_can_bb.png
    :width: 70%
    :align: center


**Schematic**

.. image:: img/07_smart_trash_can_schematic.png
   :width: 90%
   :align: center

**Code**

.. note::

    * You can open the file ``07_smart_trash_can.ino`` under the path of ``Elite-Explorer-Kit-main\fun_project\07_smart_trash_can`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/509f1bee-6e38-4106-bea7-9b06cdb3719f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**How it works?**

Here is a step-by-step explanation of the code:

1. Import Libraries and Define Constants/Variables:

   The ``Servo.h`` library is imported for controlling the SG90 servo motor.
   Parameters for the servo motor, ultrasonic sensor, and other required constants and variables are defined.

2. ``setup()``:

   Initialize serial communication with the computer at a baud rate of 9600.
   Configure the trigger and echo pins of the ultrasonic sensor.
   Attach the servo motor to its control pin and set its initial position to the closed angle. After setting the angle, the servo motor is detached to save power.

3. ``loop()``:

   Measure distance three times and store the values of each measurement.
   Calculate the average distance from the three measurements.
   If the average distance is less than or equal to 20 centimeters (defined distance threshold), the servo motor rotates to the open angle (0 degrees). 
   Otherwise, the servo motor returns to the closed position (90 degrees) after a one-second delay. The servo motor is detached when not in use to conserve power.

4. ``readDistance()``:

   Send a pulse to the trigger pin of the ultrasonic sensor.
   Measure the pulse width of the echo pin and calculate the distance value. 
   This calculation uses the speed of sound in the air to compute distance based on pulse time.
