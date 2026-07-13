.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _basic_gy87_bmp180:

BMP180
==========================


Überblick
---------------

In diesem Tutorial beschäftigen wir uns mit dem GY-87 IMU-Modul und konzentrieren uns auf den BMP180-Sensor zur Messung von Temperatur, Druck und Höhe. Ideal für Anwendungen wie Wetterüberwachung und Höhenverfolgung behandelt diese Lektion die Verbindung des GY-87 mit einem Arduino Uno und die Verwendung der Adafruit BMP085-Bibliothek. Sie lernen, wie Sie den BMP180-Sensor initialisieren und dessen Daten auf dem Arduino-Seriellen Monitor auslesen können, eine entscheidende Fähigkeit für Projekte, die Umweltdaten benötigen.

Benötigte Komponenten
-------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Sie können die Komponenten auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_gy87`
        - \-


Verdrahtung
----------------------

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 75%

.. raw:: html

   <br/>


Schaltplan
-----------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%


Code
-----------

.. note::

    * Sie können die Datei ``09-gy87_bmp180.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\09-gy87_bmp180`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. note:: 
    Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **„Adafruit BMP085 Library“** und installieren Sie diese.

.. literalinclude:: /_code/09_basic_gy87_bmp180.ino
   :language: cpp
   :linenos:
   :caption: 09-gy87_bmp180.ino


Code-Analyse
------------------------

- ``initializeBMP180()``

  Initialisieren des BMP180-Sensors.

  .. code-block:: arduino

     void initializeBMP180() {
       // Start BMP180 initialization
       if (!bmp.begin()) {
         Serial.println("Could not find a valid BMP180 sensor, check wiring!");
         while (1)
           ;  // Halt if sensor not found
       }
       Serial.println("BMP180 Found!");
     }

- ``printBMP180()``

  Die vom BMP180-Sensor gelesenen Werte ausdrucken.

  .. code-block:: arduino

     void printBMP180() {
       Serial.println();
       Serial.println("BMP180 ------------");
       Serial.print("Temperature = ");
       Serial.print(bmp.readTemperature());
       Serial.println(" *C");
     
       Serial.print("Pressure = ");
       Serial.print(bmp.readPressure());
       Serial.println(" Pa");
     
       // Calculate altitude assuming 'standard' barometric
       // pressure of 1013.25 millibar = 101325 Pascal
       Serial.print("Altitude = ");
       Serial.print(bmp.readAltitude());
       Serial.println(" meters");
     
       Serial.print("Pressure at sealevel (calculated) = ");
       Serial.print(bmp.readSealevelPressure());
       Serial.println(" Pa");
       Serial.println("BMP180 ------------");
       Serial.println();
     }


