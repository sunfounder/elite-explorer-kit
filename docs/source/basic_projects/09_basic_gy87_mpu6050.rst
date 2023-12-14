.. _basic_gy87_mpu6050:

MPU6050
==========================

Überblick
---------------

In diesem Tutorial lernen Sie, das GY-87 IMU-Modul mit einem Arduino Uno zu verbinden, wobei der Fokus auf dem MPU6050-Sensor liegt. Wir behandeln die Initialisierung des MPU6050 und die Anzeige seiner Beschleunigungs-, Gyroskop- und Temperaturdaten auf dem Seriellen Monitor. Diese Lektion ist unerlässlich für Projekte, die Bewegungs- und Temperatursensoren benötigen, wie Robotik, gestengesteuerte Geräte und interaktive Kunstinstallationen.

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

    * Sie können die Datei ``09-gy87_mpu6050.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\09-gy87_mpu6050`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. note:: 
    Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **„Adafruit MPU6050“** und installieren Sie diese.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f89edd5d-e6f9-4f83-979c-6c1d5da3e9d7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Code-Analyse
------------------------

#. Einbinden von Bibliotheken

   Die Bibliotheken ``Adafruit_MPU6050``, ``Adafruit_Sensor`` und ``Wire`` werden für die Sensorschnittstelle und Kommunikation eingebunden.

   .. code-block:: arduino

      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>

#. Initialisieren des Sensorobjekts

   Ein Objekt der Klasse Adafruit_MPU6050 wird erstellt, um den MPU6050-Sensor darzustellen.

   .. code-block:: arduino

      Adafruit_MPU6050 mpu;

#. Setup-Funktion

   Initialisiert die serielle Kommunikation und ruft die Funktion zur Initialisierung des MPU6050-Sensors auf.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        initializeMPU6050();
      }

#. Loop-Funktion

   Ruft wiederholt die Funktion auf, um MPU6050-Daten mit einer Verzögerung von 500 Millisekunden zwischen jedem Aufruf zu drucken.

   .. code-block:: arduino

      void loop() {
        printMPU6050();
        delay(500);
      }

#. Initialisieren der MPU6050-Funktion

   Überprüft, ob der MPU6050 angeschlossen ist, stellt Beschleunigungsmesser- und Gyro-Bereiche ein und konfiguriert die Filterbandbreite.

   .. code-block:: arduino

      void initializeMPU6050() {
        // Check if the MPU6050 sensor is detected
        if (!mpu.begin()) {
          Serial.println("Failed to find MPU6050 chip");
          while (1)
            ;  // Halt if sensor not found
        }
        Serial.println("MPU6050 Found!");
      
        // set accelerometer range to +-8G
        mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
      
        // set gyro range to +- 500 deg/s
        mpu.setGyroRange(MPU6050_RANGE_500_DEG);
      
        // set filter bandwidth to 21 Hz
        mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
      
        Serial.println("");
        delay(100);
      }

#. MPU6050-Daten drucken Funktion

   Liest und druckt die Beschleunigungs-, Gyroskop- und Temperaturdaten des MPU6050 auf den Seriellen Monitor.

   .. code-block:: arduino

      void printMPU6050() {
      
        Serial.println();
        Serial.println("MPU6050 ------------");
      
        /* Get new sensor events with the readings */
        sensors_event_t a, g, temp;
        mpu.getEvent(&a, &g, &temp);
      
        /* Print out the values */
        Serial.print("Acceleration X: ");
        Serial.print(a.acceleration.x);
        Serial.print(", Y: ");
        Serial.print(a.acceleration.y);
        Serial.print(", Z: ");
        Serial.print(a.acceleration.z);
        Serial.println(" m/s^2");
      
        Serial.print("Rotation X: ");
        Serial.print(g.gyro.x);
        Serial.print(", Y: ");
        Serial.print(g.gyro.y);
        Serial.print(", Z: ");
        Serial.print(g.gyro.z);
        Serial.println(" rad/s");
      
        Serial.print("Temperature: ");
        Serial.print(temp.temperature);
        Serial.println(" degC");
      
        Serial.println("MPU6050 ------------");
        Serial.println();
      }
