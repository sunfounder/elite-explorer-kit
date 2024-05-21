.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _basic_moisture:

Soil Moisture
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_moisture.html

Overview
---------------

In the agricultural industry, crops cannot directly acquire inorganic elements from the soil. Instead, water present in the soil acts as a solvent to dissolve these elements.

Crops absorb moisture from the soil through their root system to obtain nutrients and facilitate growth.

During the growth and development of crops, there are varying requirements for soil temperature. Hence, it is necessary to use a soil moisture sensor.

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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

Wiring
----------------------

.. image:: img/03-soil_moisture_bb.png
    :align: center
    :width: 80%

Schematic Diagram
-----------------------

.. image:: img/03_moisture_schematic.webp
    :align: center
    :width: 70%

Code
---------------

.. note::

    * Open the ``03-moisture.ino`` file under the path of ``elite-explorer-kit-main\basic_project\03-moisture``.
    * Or copy this code into **Arduino IDE**.
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c585dd77-2e8a-4839-a908-d22e1d6e93aa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Once the code is successfully uploaded, the serial monitor will print out the soil moisture value.

By inserting the module into the soil and watering it, the value of the soil moisture sensor will become smaller.