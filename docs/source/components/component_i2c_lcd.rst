.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_i2c_lcd1602:

I2C LCD1602
==============

.. image:: img/i2c_lcd1602.png
    :width: 800

* **GND**: Masse
* **VCC**: Spannungsversorgung, 5V.
* **SDA**: Serielle Datenleitung. Verbinden mit VCC über einen Pullup-Widerstand.
* **SCL**: Serielle Taktleitung. Verbinden mit VCC über einen Pullup-Widerstand.

Wie wir alle wissen, bereichern LCDs und andere Anzeigen zwar die Mensch-Maschine-Interaktion, teilen aber eine gemeinsame Schwäche. Wenn sie mit einem Controller verbunden sind, belegen sie mehrere IOs des Controllers, der nicht so viele externe Ports hat. Dies beschränkt auch andere Funktionen des Controllers.

Daher wurde das LCD1602 mit einem I2C-Modul entwickelt, um dieses Problem zu lösen. Das I2C-Modul hat einen eingebauten PCF8574 I2C-Chip, der I2C-Serien-Daten in parallele Daten für das LCD-Display umwandelt.

* |link_pcf8574_datasheet|

**I2C-Adresse**

Die Standardadresse ist grundsätzlich 0x27, in einigen Fällen kann sie 0x3F sein.

Nehmen wir die Standardadresse von 0x27 als Beispiel, kann die Geräteadresse geändert werden, indem die A0/A1/A2-Pads kurzgeschlossen werden; im Standardzustand ist A0/A1/A2 1, und wenn das Pad kurzgeschlossen wird, ist A0/A1/A2 0.

.. image:: img/i2c_address.jpg
    :width: 600

**Hintergrundbeleuchtung/Kontrast**

Die Hintergrundbeleuchtung kann durch einen Jumper aktiviert werden, entfernen Sie den Jumper, um die Hintergrundbeleuchtung zu deaktivieren. Das blaue Potentiometer auf der Rückseite wird verwendet, um den Kontrast (das Verhältnis der Helligkeit zwischen dem hellsten Weiß und dem dunkelsten Schwarz) einzustellen.

.. image:: img/back_lcd1602.jpg

* **Kurzschlusskappe**: Die Hintergrundbeleuchtung kann durch diese Kappe aktiviert werden, entfernen Sie diese Kappe, um die Hintergrundbeleuchtung zu deaktivieren.
* **Potentiometer**: Es wird verwendet, um den Kontrast (die Klarheit des angezeigten Textes) einzustellen, der im Uhrzeigersinn erhöht und gegen den Uhrzeigersinn verringert wird.

**Beispiel**

* :ref:`basic_i2c_lcd1602` (Grundprojekt)
* :ref:`basic_ultrasonic_sensor` (Grundprojekt)
* :ref:`fun_plant_monitor` (Spaßprojekt)
* :ref:`fun_guess_number` (Spaßprojekt)
* :ref:`iot_Bluetooth_lcd` (IoT-Projekt)

