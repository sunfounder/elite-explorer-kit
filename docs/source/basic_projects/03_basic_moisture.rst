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

* :ref:`uno_r4_wifi`
* :ref:`cpn_wires`
* :ref:`cpn_soil_moisture`

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

    * Open the ``03-moisture.ino`` file under the path of ``Elite-Explorer-Kit-main\basic_project\03-moisture``.
    * Or copy this code into **Arduino IDE**.
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c585dd77-2e8a-4839-a908-d22e1d6e93aa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Once the code is successfully uploaded, the serial monitor will print out the soil moisture value.

By inserting the module into the soil and watering it, the value of the soil moisture sensor will become smaller.