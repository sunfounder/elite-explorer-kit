.. _cpn_power:

Power Supply Module
=====================

.. note::
    To protect the :ref:`cpn_power`'s battery, please fully charge it before using it for the first time.

When we need a large current to drive a component, which will severely interfere with the normal work of Arduino UNO board. Therefore, we separately supply power for the component by this module to make it run safely and steadily.

You can just plug it in the breadboard to supply power. It provides a voltage of 3.3V and 5V, and you can connect either via a jumper cap included.

.. image:: img/power_supply_new.png
    :width: 95%
    :align: center

.. raw:: html

    <br/>

**Features and specifications**

* Charge Input: USB Type-C, 5V
* Output Voltage: 5V, 3.3V (adjustable via jumpers. 0V, 3.3V, and 5V configuration)
* Output Current: 5V/1.5A, 3.3V/1A
* ON-OFF Switch Available
* Two Independent Channel
* USB (Type-A) Output Available
* Battery: 3.7V 14500 Lithium-ion Battery, 500mAh
* Dimension: 52mm x 32mm x 24mm (L x W x H)


**Example**

* :ref:`basic_motor` (Basic Project)
* :ref:`basic_pump` (Basic Project)
* :ref:`basic_stepper_motor` (Basic Project)
* :ref:`fun_smart_fan` (Fun Project)
* :ref:`fun_plant_monitor` (Fun Project)
* :ref:`fun_access` (Fun Project)
* :ref:`fun_pong` (Fun Project)

