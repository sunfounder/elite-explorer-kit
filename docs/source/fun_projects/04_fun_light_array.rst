.. _fun_light_array:

Light-sensitive Array
==========================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/04_fun_lightarray.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

This program converts the readings from a light-dependent resistor into a corresponding number of illuminated LED lights, creating a simple indicator of light brightness.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|


**Wiring**

.. image:: img/04_light_sensitive_array_bb.png
    :width: 70%
    :align: center

.. raw:: html

   <br/>

**Schematic**

.. image:: img/04_light_sensitive_array_schematic.png
   :width: 60%

**Code**

.. note::

    * You can open the file ``04_light_sensitive_array.ino`` under the path of ``elite-explorer-kit-main\fun_project\04_light_sensitive_array`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/9da7af57-c002-41a0-bc84-372e91885d52/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**How it works?**

Here's a step-by-step explanation of the code:

1. Constant and Variable Definitions:

   ``NbrLEDs``: Defines the presence of 8 LEDs.
   ``ledPins[]``: LEDs are connected to Arduino pins 5 to 12.
   ``photocellPin``: The photoresistor is connected to Arduino's A0 pin.
   ``sensorValue``: This variable stores the value read from the photoresistor.
   ``ledLevel``: This variable stores the number of LEDs based on the sensorValue conversion.

2. ``setup()``:

   Configures pins 5 to 12 as output to drive the LEDs.

3. ``loop()``:

   Reads the analog value of the photoresistor from pin A0, typically ranging from 0 to 1023.
   Uses the map function to map the photoresistor's value from the range 300-1023 to the range 0-8.
   This means that if the reading from the light-dependent resistor is 300, no LEDs will be lit;
   if the reading is 1023 or higher, all 8 LEDs will be lit.
   
   The subsequent for loop checks each LED. If its index is less than ledLevel,
   the LED will be turned on; otherwise, it will be turned off.
