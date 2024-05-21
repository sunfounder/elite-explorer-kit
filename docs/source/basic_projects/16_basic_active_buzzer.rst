.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _basic_active_buzzer:

Active Buzzer
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_active_buzzer.html#ar-beep

Overview
---------------

The active buzzer is a typical digital output device that is as easy to use as lighting up an LED!

Two types of buzzers are included in the kit. 
We need to use active buzzer. Turn them around, the sealed back (not the exposed PCB) is the one we want.

.. image:: img/16_buzzer.png
    :align: center
    :width: 70%

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
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_buzzer`
        - \-

Wiring
----------------------

.. note::
    When connecting the buzzer, make sure to check its pins. The longer pin is the anode and the shorter one is the cathode. It's important not to mix them up, as doing so will prevent the buzzer from producing any sound.

.. image:: img/16-active_buzzer_bb.png
    :align: center
    :width: 70%

Schematic Diagram
-----------------------

.. image:: img/16_active_buzzer_schematic.png
    :align: center
    :width: 80%

Code
---------------

.. note::

    * You can open the file ``16-active_buzzer.ino`` under the path of ``elite-explorer-kit-main\basic_project\16-active_buzzer`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/bde4fd5c-8848-49cd-898f-8a824c836b80/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After the code is uploaded successfully, you will hear a beep every second.