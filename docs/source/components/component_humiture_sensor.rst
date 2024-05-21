.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

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
