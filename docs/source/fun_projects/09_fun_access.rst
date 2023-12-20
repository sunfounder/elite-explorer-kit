.. _fun_access:

Access Control System
======================================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/09_fun_access.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

The primary function of this code is to perform user authentication using an RFID module. 
If the authentication is successful, it controls a stepper motor to open the door and emits a sound through a buzzer to indicate the authentication result. 
If the authentication fails, the door will not open.

You can open the serial monitor to view the ID of your RFID card and re-config the password in this code.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_mfrc522`
        - |link_mfrc522_rfid_buy|
    *   - :ref:`cpn_stepper_motor`
        - |link_stepper_motor_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_power`
        - \-


**Wiring**

.. note::
    To protect the :ref:`cpn_power`'s battery, please fully charge it before using it for the first time.

.. image:: img/09_access_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Schematic**

.. image:: img/09_access_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Code**

.. note::

    * You can open the file ``09_access_control_system.ino`` under the path of ``elite-explorer-kit-main\fun_project09_access_control_system`` directly.
    * Or copy this code into Arduino IDE.

.. note::

    * The ``RFID1`` library is used here. The library can be found in the ``elite-explorer-kit-main/library/`` directory, or you can click here :download:`RFID1.zip </_static/RFID1.zip>` to download it. Refer to :ref:`manual_install_lib` for a tutorial on how to install it.

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
