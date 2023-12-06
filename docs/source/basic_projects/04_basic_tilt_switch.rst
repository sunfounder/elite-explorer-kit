.. _basic_tilt_switch:

Tilt Switch
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.17_tilt_switch.html#ar-tilt

Overview
---------------

In this lesson, you will learn about tilt switch. Tilt switch can be used to detect whether objects tilt, which is of great value in practical applications. It can be used to judge the tilt of bridges, buildings, transmission line tower and so on, so it has an important guiding function in carrying out maintenance work.

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
    *   - :ref:`cpn_tilt_switch`
        - \-

Fritzing Circuit
---------------------

In this example, digital pin 2 is used to read the signal of Tilt
Switch.

.. image:: img/04-tilt_switch_bb.png
   :align: center
   :width: 85%

Schematic Diagram
-----------------------

.. image:: img/04_tilt_switch_schematic.png
   :align: center
   :width: 70%


Code
----------

.. note::

    * You can open the file ``04-tilt_switch.ino`` under the path of ``elite-explorer-kit-main\basic_project\04-tilt_switch`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d85d75d9-e491-424c-93be-95e1f4e99549/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Once the codes are uploaded to the uno r4 board, you can open the serial monitor to view the pin readings. The readings will display either "1" or "0" depending on whether the Tilt Switch is in a vertical position (with the internal metal ball making contact with the Wire Pins) or tilted.