.. _fun_access:

Access Control System
======================================

The primary function of this code is to perform user authentication using an RFID module. 
If the authentication is successful, it controls a stepper motor to open the door and emits a sound through a buzzer to indicate the authentication result. 
If the authentication fails, the door will not open.

You can open the serial monitor to view the ID of your RFID card and re-config the password in this code.

**Required Components**

* :ref:`uno_r4_wifi`
* :ref:`cpn_wires`
* :ref:`cpn_breadboard`
* :ref:`cpn_mfrc522`
* :ref:`cpn_stepper_motor`
* :ref:`cpn_buzzer`

**Wiring**

.. image:: img/10_access_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Schematic**

.. image:: img/10_access_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Code**

.. note::

    * You can open the file ``10_access_control_system.ino`` under the path of ``Elite-Explorer-Kit-main\fun_project10_access_control_system`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/3486dd4e-a76e-478f-b5a4-a86281f7f374/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**How it works?**

Below is a step-by-step explanation of the code:

1. **Include Library Files**: You have included three library files: ``rfid1.h``, ``Stepper.h``, and ``Wire.h``. These libraries are used to communicate with the RFID module, stepper motor, and for I2C communication.

2. **Constant Definitions**: You have defined some constants, including ``ID_LEN`` (length of the ID), ``stepsPerRevolution`` (steps per revolution for the stepper motor), ``rolePerMinute`` (stepper motor's speed), as well as the four stepper motor pins (IN1, IN2, IN3, IN4), buzzer pin (``buzPin``), and variables related to authentication.

3. **Variable Definitions**: You've defined variables such as an array to store the read user ID (``userIdRead``), authenticated user ID (``userId``), and a boolean variable (``approved``) to indicate successful authentication.

4. **Object Instantiation**: You've created instances of two objects: ``RFID1 rfid`` and ``Stepper stepper`` for interacting with the RFID module and stepper motor, respectively.

5. ``setup()``: In the ``setup()`` function, you initialize the stepper motor's speed, set the buzzer pin as an output, and initialize the RFID module.

6. ``loop()``: In the ``loop()`` function, your main logic runs. If ``approved`` is 0 (indicating not authenticated yet), it calls the ``rfidRead()`` function to read data from the RFID module and then clears the ``userIdRead`` array. If ``approved`` is 1 (indicating successful authentication), it calls the ``openDoor()`` function to open the door and resets ``approved`` to 0.

7. ``beep()``: This function controls the buzzer sound based on the ``duration`` and ``frequency`` parameters provided.

8. ``verifyPrint()``: This function produces different buzzer sounds based on the ``result`` parameter to indicate whether authentication was successful.

9. ``openDoor()``: This function controls the stepper motor to open the door to a certain angle (``doorStep``) and then waits for a period before closing the door.

10. ``rfidRead()``: This function reads data from the RFID module, first calling ``getId()`` to get the user ID and then ``idVerify()`` to verify if the user ID matches the authenticated ID.

11. ``getId()``: This function retrieves the user ID from the RFID module and stores it in the ``userIdRead`` array. It emits a beep if reading fails.

12. ``idVerify()``: This function verifies if the user ID matches the authenticated ID and produces a sound indicating successful or failed authentication.
