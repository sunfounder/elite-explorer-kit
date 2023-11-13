.. _cpn_dht11:

Humiture Sensor Module
=============================

The digital temperature and humidity sensor DHT11 is a composite sensor that contains a calibrated digital signal output of temperature and humidity. 
The technology of a dedicated digital modules collection and the temperature and humidity sensing technology are applied to ensure that the product has high reliability and excellent long-term stability.


Only three pins are available for use: VCC, GND, and DATA. 
The communication process begins with the DATA line sending start signals to DHT11, and DHT11 receives the signals and returns an answer signal. 
Then the host receives the answer signal and begins to receive 40-bit humiture data (8-bit humidity integer + 8-bit humidity decimal + 8-bit temperature integer + 8-bit temperature decimal + 8-bit checksum).

.. image:: img/Dht11.png


* |link_dht11_datasheet|

**Example**

* :ref:`basic_humiture_sensor` (Basic Project)
* :ref:`fun_plant_monitor` (Fun Project)
* :ref:`iot_arduino_cloud` (IoT Project)
* :ref:`iot_ble_home` (IoT Project)