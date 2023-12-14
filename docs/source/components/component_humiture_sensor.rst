.. _cpn_dht11:

Feuchtigkeitssensor-Modul
=============================

Der digitale Temperatur- und Feuchtigkeitssensor DHT11 ist ein Verbundsensor, der einen kalibrierten digitalen Signalausgang für Temperatur und Feuchtigkeit enthält.
Die Technologie von speziellen digitalen Modulsammlungen und die Temperatur- und Feuchtigkeitserfassungstechnologie werden angewandt, um sicherzustellen, dass das Produkt eine hohe Zuverlässigkeit und ausgezeichnete Langzeitstabilität aufweist.

Nur drei Pins stehen zur Verwendung bereit: VCC, GND und DATA.
Der Kommunikationsprozess beginnt damit, dass die DATA-Leitung Startsignale an DHT11 sendet, und DHT11 empfängt die Signale und gibt ein Antwortsignal zurück.
Dann empfängt der Host das Antwortsignal und beginnt, 40-Bit-Feuchtigkeitsdaten zu empfangen (8-Bit-Feuchtigkeit ganz + 8-Bit-Feuchtigkeit Dezimal + 8-Bit-Temperatur ganz + 8-Bit-Temperatur Dezimal + 8-Bit-Prüfsumme).

.. image:: img/Dht11.png

* |link_dht11_datasheet|

**Beispiel**

* :ref:`basic_humiture_sensor` (Grundprojekt)
* :ref:`fun_plant_monitor` (Spaßprojekt)
* :ref:`iot_arduino_cloud` (IoT-Projekt)
* :ref:`iot_ble_home` (IoT-Projekt)
