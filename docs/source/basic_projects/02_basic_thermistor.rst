.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _basic_thermistor:

Thermistor
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.27_thermistor.html#ar-thermistor

Overview
-------------

In this lesson, you will learn how to use thermistor. Thermistor can be used as electronic circuit components for temperature compensation of instrument circuits. In the current meter, flowmeter, gas analyzer, and other devices. It can also be used for overheating protection, contactless relay, constant temperature, automatic gain control, motor start, time delay, color TV automatic degaussing, fire alarm and temperature compensation.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

Wiring
----------------------

In this example, we use the analog pin A0 to get the value of Thermistor. One pin of thermistor is connected to 5V, and the other is wired up to A0. At the same time, a 10kΩ resistor is connected with the other pin before connecting to GND.

.. image:: img/02-thermistor_bb.png
    :align: center
    :width: 70%

Schematic Diagram
-----------------------

.. image:: img/02_thermistor_schematic.png
   :align: center
   :width: 70%

Code
-----------

.. note::

    * You can open the file ``02-thermistor.ino`` under the path of ``elite-explorer-kit-main\basic_project\02-thermistor`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/be5dbe68-b57d-41f0-9fc0-237b99acbe3f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After uploading the code to the uno r4 board, you can open the serial monitor to check the current temperature. 

The Kelvin temperature is calculated using the formula **T\ K\ =1/(ln(R\ T/R\ N)/B+1/T\ N)**. This equation is derived from the |link_steinhart_hart| and simplifies calculations. You can also find more information about this formula on the detailed introduction page of the :ref:`cpn_thermistor`.

