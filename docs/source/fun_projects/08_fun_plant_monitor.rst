.. _fun_plant_monitor:

Plant Monitor
============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/08_fun_plant_monitor.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

This project automatically waters plants by activating a water pump when the soil humidity falls below a specific threshold.
Additionally, it displays temperature, humidity, and soil moisture on an LCD screen, providing users with insights into the plant's growth environment.

**Required Components**

* :ref:`uno_r4_wifi`
* :ref:`cpn_wires`
* :ref:`cpn_breadboard`
* :ref:`cpn_i2c_lcd1602`
* :ref:`cpn_pump`
* :ref:`cpn_ta6586`
* :ref:`cpn_soil_moisture`
* :ref:`cpn_dht11`
* :ref:`cpn_power`

**Wiring**

.. image:: img/08_plant_monitor_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Schematic**

.. image:: img/08_plant_monitor_schematic.png
   :width: 100%
   :align: center

.. raw:: html

   <br/>

**Code**

.. note::

    * You can open the file ``08_plant_monitor.ino`` under the path of ``Elite-Explorer-Kit-main\fun_project\08_plant_monitor`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/a9d6c9c7-0d7f-4dc2-84b6-9dbda15c89ae/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**How it works?**

Here is a detailed explanation of the code:

1. Library Inclusions and Constants/Variables:

   Import ``Wire.h``, ``LiquidCrystal_I2C.h``, and ``DHT.h`` libraries.
   Define pin numbers and other parameters related to DHT11, soil moisture sensor, and the water pump.

2. ``setup()``:

   Initialize the pin modes related to the soil moisture sensor and the water pump.
   Turn off the water pump initially.
   Initialize the LCD display and turn on the backlight.
   Start the DHT sensor.

3. ``loop()``:

   Read humidity and temperature from the DHT sensor.
   Read soil moisture from the soil moisture sensor.
   Display temperature and humidity values on the LCD screen, then clear the screen and display the soil moisture value.
   Determine whether to activate the water pump based on soil moisture. If the soil moisture is below 500 (a configurable threshold), activate the water pump for 1 second.
