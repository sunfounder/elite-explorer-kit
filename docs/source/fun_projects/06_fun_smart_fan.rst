.. _fun_smart_fan:

Smart Fan
=================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/06_fun_smartfan.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

This Arduino project automatically adjusts the fan's speed to maintain the temperature within a suitable range.
Additionally, users can enter manual mode through a button to operate the fan at maximum speed.

**Required Components**

* :ref:`uno_r4_wifi`
* :ref:`cpn_wires`
* :ref:`cpn_breadboard`
* :ref:`cpn_button`
* :ref:`cpn_led`
* :ref:`cpn_resistor`
* :ref:`cpn_thermistor`
* :ref:`cpn_motor`
* :ref:`cpn_ta6586`
* :ref:`cpn_power`

**Wiring**

.. image:: img/06_smart_fan_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Schematic**

.. image:: img/06_smart_fan_schematic.png
   :width: 80%
   :align: center

**Code**

.. note::

    * You can open the file ``06_smart_fan.ino`` under the path of ``Elite-Explorer-Kit-main\fun_project\06_smart_fan`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/ba484912-14d6-4125-83a0-73a107904144/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**How it works?**

Here is a step-by-step explanation of the code:

1. Constants and Variable Definitions:

   Use ``#define`` to define the pins for various hardware connections.
   ``TEMP_THRESHOLD`` is defined as 25°C, which is the temperature threshold to start the fan.
   ``manualMode``: A boolean variable that indicates whether it is in manual mode.

2. ``setup()``:

   Set the mode for relevant pins (output, input, input with pull-up).
   Initially set to automatic mode, so ``LED_AUTO`` is lit while ``LED_MANUAL`` is off.

3. ``loop()``:

   Monitor the button's state. When the button is pressed, it toggles the mode and changes the LED's status.
   In manual mode, the fan operates at maximum speed.
   In automatic mode, the code first reads the voltage value from the temperature sensor and converts it to a temperature value. 
   If the temperature exceeds the threshold, the fan's speed is adjusted based on the temperature.

4. ``voltageToTemperature()``:

   This is an auxiliary function used to convert the voltage value from the temperature sensor into a temperature value (in Celsius).
   The function uses the standard formula for a thermistor to estimate the temperature.
   The return value is in degrees Celsius.
