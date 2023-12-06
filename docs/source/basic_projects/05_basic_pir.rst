.. _basic_pir:

PIR Motion Sensor Module
==========================

.. https://docs.sunfounder.com/projects/kepler-kit/en/latest/cproject/ar_pir.html#ar-pir


Overview
---------------

In this lesson, you will learn about PIR motion sensor module. The Passive Infrared(PIR) Motion Sensor is a sensor that detects motion. It is commonly used in security systems and automatic lighting systems. The sensor has two slots that detect infrared radiation. When an object, such as a person, passes in front of the sensor, it detects a change in the amount of infrared radiation and triggers an output signal.


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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

Wiring
----------------------

.. image:: img/05-pir_bb.png
   :align: center
   :width: 100%


Schematic Diagram
-----------------------

.. image:: img/05-pir_schematic.png
   :align: center
   :width: 50%


Code
---------------

.. note::

    * You can open the file ``05-pir_motion_sensor.ino`` under the path of ``elite-explorer-kit-main\basic_project\05-pir_motion_sensor`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d9fc9198-1538-413d-b501-2cddc8d7cfe6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After uploading the code to the Arduino Uno board, you can open the serial monitor to observe the sensor's output. When the PIR (passive infrared) motion sensor detects movement, the serial monitor will display the message "Somebody here!" to indicate that motion has been detected. If no motion is detected, the message "Monitoring..." will be shown instead.

The PIR sensor outputs a digital HIGH or LOW signal, corresponding to detected or undetected motion, respectively. Unlike an analog sensor that provides a range of values, the digital output from this PIR sensor will either be HIGH (typically represented as '1') or LOW (typically represented as '0').

Note that the actual sensitivity and range of detection can vary based on the PIR sensor's characteristics and the environmental conditions. Therefore, it is advisable to calibrate the sensor according to your specific needs.