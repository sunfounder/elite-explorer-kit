.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _basic_gy87_qmc5883l:

QMC5883L
==========================

Überblick
---------------

In diesem Tutorial befassen wir uns mit dem GY-87 IMU-Modul und konzentrieren uns auf das QMC5883L-Magnetometer. Der erste Teil des Tutorials führt Sie durch die Kalibrierung des QMC5883L-Magnetometers, was für genaue Messungen des Magnetfelds unerlässlich ist. Sie lernen, wie man einen Kalibrierungssketch auf Arduino hochlädt, eine Echtzeit-Kalibrierung durchführt und diese Einstellungen in Ihren Projekten anwendet. Der zweite Teil des Tutorials behandelt die Initialisierung des MPU6050 (Beschleunigungsmesser und Gyroskop) und QMC5883L auf einem Arduino Uno unter Verwendung der Adafruit MPU6050- und QMC5883LCompass-Bibliotheken. Sie erfahren, wie man Sensordaten liest und auf dem Seriellen Monitor anzeigt, was eine grundlegende Fähigkeit für Anwendungen in Navigation, Bewegungstracking und Orientierungserkennung ist.

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
    :width: 90%

.. raw:: html

   <br/>


Schaltplan
-----------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%


Bibliothek installieren
-----------------------

.. note:: 
    Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager. 
    
        - Suchen Sie nach **„Adafruit MPU6050“** und installieren Sie

          Bei der Installation jeder Bibliothek stellen Sie bitte sicher, dass die Installation aller Abhängigkeiten ausgewählt wird.
      
          .. image:: img/09-add_lib_tip.png
             :width: 80%

        - Suchen Sie nach **„QMC5883LCompass“** und installieren Sie


.. _basic_gy87_calibrate:

QMC5883L kalibrieren
-----------------------

.. note::

    * Sie können die Datei ``09-gy87_compass_calibration.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\09-gy87_compass_calibration`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/252c7a58-3a9f-4c66-959e-f45fc19e68aa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem Sie den Code hochgeladen haben, öffnen Sie den seriellen Monitor. Befolgen Sie die Anweisungen im seriellen Monitor, um QMC5883L zu kalibrieren. Wenn Sie aufgefordert werden, den Sensor zu bewegen, wird die Kalibrierungsmethode „Achterfigur“ empfohlen. Alternativ können Sie den Sensor einfach parallel zum Boden halten und ihn im Uhrzeigersinn oder gegen den Uhrzeigersinn drehen, bis der serielle Monitor meldet, dass die Kalibrierung abgeschlossen ist.

.. image:: img/09_calibrate_qmc5883l.png
    :width: 100%
    :align: center

Sobald alle Kalibrierungsdaten gesammelt wurden, wird das Sketch Ihnen einige Codezeilen geben, die wie ``compass.setCalibrationOffsets(-375.00, -179.00, 85.00);`` und ``compass.setCalibrationScales(1.04, 0.96, 1.01);`` aussehen. Kopieren Sie diesen Code. Es ist empfehlenswert, ihn für zukünftige Referenzen zu speichern.

Bei Verwendung von QMC5883L: Öffnen Sie den Sketch Ihres Projekts und fügen Sie die kopierte Codezeile direkt unter den Aufruf ``compass.init()`` ein. So wie hier:

.. code:: arduino 

   void initializeQMC5883L() {
   
     compass.init();
   
     // You should replace the code below according to your calibration results
     compass.setCalibrationOffsets(-375.00, -179.00, 85.00);
     compass.setCalibrationScales(1.04, 0.96, 1.01);
   
   }

Code
---------------------------------------------

.. note::

   Magnetometer müssen kalibriert(:ref:`basic_gy87_calibrate`) werden, bevor sie als Kompass verwendet werden können, und müssen waagerecht gehalten und **fern von Eisenobjekten, magnetisierten Materialien und stromführenden Drähten** gehalten werden.

.. note::

    * Sie können die Datei ``09-gy87_qmc5883l.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\09-gy87_qmc5883l`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.
    * Fügen Sie den Code, den Sie aus den Kalibrierungsschritten erhalten haben, unter die Zeile ``compass.init()`` in der Funktion ``initializeQMC5883L()`` ein.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b266a18-ce7b-4330-8c10-c9f4148bb8ec/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Code-Analyse
------------------------

#. Einbinden von Bibliotheken und Initialisieren von Sensoren
   Dieser Abschnitt enthält die notwendigen Bibliotheken für die MPU6050- und QMC5883L-Sensoren und initialisiert ihre Objekte.

   .. code-block:: arduino
      
      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>
      #include <QMC5883LCompass.h>

      Adafruit_MPU6050 mpu;
      QMC5883LCompass compass;

#. Setup-Funktion

   Initialisiert die serielle Kommunikation, den MPU6050-Sensor und setzt den MPU6050 in den I2C-Bypass-Modus, um direkten Zugriff auf das QMC5883L-Magnetometer zu ermöglichen. Anschließend wird das QMC5883L-Magnetometer initialisiert.

   .. code-block:: arduino
      
      void setup() {
        // Initialize the serial communication with a baud rate of 9600
        Serial.begin(9600);
      
        // Initialize the MPU6050 sensor (accelerometer and gyroscope)
        initializeMPU6050();
      
        // Enable I2C bypass on MPU6050 to directly access the QMC5883L magnetometer
        mpu.setI2CBypass(true);
      
        // Initialize the QMC5883L magnetometer sensor
        initializeQMC5883L();
      }

#. Loop-Funktion

   Liest kontinuierlich Daten vom QMC5883L-Magnetometer und gibt sie auf dem Seriellen Monitor aus.

   .. code-block:: arduino
      
      void loop() {
        printQMC5883L();
        delay(500);
      }

#. Initialisieren der QMC5883L-Funktion

   Initialisiert und kalibriert das QMC5883L-Magnetometer. Die Kalibrierungswerte sollten auf Grundlage spezifischer Kalibrierungsdaten angepasst werden.(:ref:`basic_gy87_calibrate`)

   .. code-block:: arduino
      
      void initializeQMC5883L() {
        compass.init();
      
        // You should replace the code below according to your calibration results
        compass.setCalibrationOffsets(-549.00, -66.00, 160.00);
        compass.setCalibrationScales(0.97, 1.02, 1.02);
      }

#. QMC5883L-Daten drucken Funktion

   Diese Funktion liest die X-, Y-, Z-Werte und den Azimut des Magnetometers und druckt sie auf den Seriellen Monitor.

   .. code-block:: arduino

    void printQMC5883L() {
    
      Serial.println();
      Serial.println("QMC5883L ------------");
    
    	int x, y, z, a;
    	char myArray[3];
    	
    	compass.read();
      
    	x = compass.getX();
    	y = compass.getY();
    	z = compass.getZ();
    	
    	a = compass.getAzimuth();
    
    	compass.getDirection(myArray, a);
      
    	Serial.print("X: ");
    	Serial.print(x);
    
    	Serial.print(" Y: ");
    	Serial.print(y);
    
    	Serial.print(" Z: ");
    	Serial.print(z);
    
    	Serial.print(" Azimuth: ");
    	Serial.print(a);
    
    	Serial.print(" Direction: ");
    	Serial.print(myArray[0]);
    	Serial.print(myArray[1]);
    	Serial.println(myArray[2]);
    
      Serial.println("QMC5883L ------------");
      Serial.println();
    }
