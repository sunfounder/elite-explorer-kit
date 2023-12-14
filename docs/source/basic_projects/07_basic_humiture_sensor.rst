.. _basic_humiture_sensor:

Feuchtigkeitssensor-Modul
=============================

.. https://docs.sunfounder.com/projects/3in1-kit/en/latest/basic_project/ar_dht11.html#ar-dht11

Überblick
---------------

Feuchtigkeit und Temperatur stehen von der physikalischen Größe selbst bis hin zum tatsächlichen menschlichen Leben in enger Beziehung. Die Temperatur und Feuchtigkeit der menschlichen Umgebung beeinflussen direkt die Thermoregulationsfunktion und den Wärmeübertragungseffekt des menschlichen Körpers. Dies wirkt sich weiter auf die Denkaktivität und den mentalen Zustand aus und beeinflusst somit die Effizienz unseres Lernens und Arbeitens.

Die Temperatur ist eine der sieben grundlegenden physikalischen Größen im Internationalen Einheitensystem, die verwendet wird, um den Grad der Wärme oder Kälte eines Objekts zu messen. Celsius ist eine der weltweit am häufigsten verwendeten Temperaturskalen, ausgedrückt durch das Symbol „℃“.

Feuchtigkeit ist die Konzentration von Wasserdampf in der Luft. Die relative Luftfeuchtigkeit wird im Alltag häufig verwendet und in %RH ausgedrückt. Die relative Feuchtigkeit steht in engem Zusammenhang mit der Temperatur. Bei einem bestimmten Volumen abgeschlossenen Gases gilt: Je höher die Temperatur, desto niedriger die relative Feuchtigkeit und umgekehrt.

Der DHT11, ein digitaler Temperatur- und Feuchtigkeitssensor, ist in diesem Kit enthalten. Er verwendet einen kapazitiven Feuchtigkeitssensor und ein Thermistor, um die umgebende Luft zu messen und gibt ein digitales Signal am Datenpin aus.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|



Verdrahtung
----------------------

.. image:: img/07-dht11_bb.png
    :align: center

Schaltplan
-----------------------

.. image:: img/07_humiture_schematic.png
    :align: center
    :width: 40%

Code
---------------

.. note::

    * Sie können die Datei ``07-humiture_sensor.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\07-humiture_sensor`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. note:: 
    Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **„DHT sensor library“** und installieren Sie diese.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1086b07f-9551-4fa0-a0c0-391a6465ad2e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Nachdem der Code erfolgreich hochgeladen wurde, werden Sie sehen, dass der Serielle Monitor kontinuierlich die Temperatur und Feuchtigkeit ausgibt. Während das Programm stabil läuft, werden diese beiden Werte immer genauer.

Code-Analyse
------------------------

#. Einbindung notwendiger Bibliotheken und Definition von Konstanten.
   Dieser Teil des Codes bindet die DHT-Sensorbibliothek ein und definiert die Pinnummer und den Sensortyp, die in diesem Projekt verwendet werden.

   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **„DHT sensor library“** und installieren Sie diese.

   .. code-block:: arduino
    
      #include <DHT.h>
      #define DHTPIN 2       // Define the pin used to connect the sensor
      #define DHTTYPE DHT11  // Define the sensor type

#. Erstellung eines DHT-Objekts.
   Hier erstellen wir ein DHT-Objekt mit der definierten Pinnummer und dem Sensortyp.

   .. code-block:: arduino

      DHT dht(DHTPIN, DHTTYPE);  // Create a DHT object

#. Diese Funktion wird einmal ausgeführt, wenn der Arduino startet. Wir initialisieren die serielle Kommunikation und den DHT-Sensor in dieser Funktion.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        Serial.println(F("DHT11 test!"));
        dht.begin();  // Initialize the DHT sensor
      }

#. Hauptloop.
   Die Funktion ``loop()`` wird kontinuierlich nach der Setup-Funktion ausgeführt. Hier lesen wir die Feuchtigkeits- und Temperaturwerte, berechnen den Hitzeindex und drucken diese Werte auf den seriellen Monitor. Wenn das Auslesen des Sensors fehlschlägt (NaN zurückgibt), wird eine Fehlermeldung ausgegeben.

   .. note::
    
      Der |link_heat_index| ist eine Methode, um zu messen, wie heiß es sich draußen anfühlt, indem die Lufttemperatur und die Feuchtigkeit kombiniert werden. Es wird auch als „gefühlte Lufttemperatur“ oder „scheinbare Temperatur“ bezeichnet.

   .. code-block:: arduino

      void loop() {
        delay(2000);
        float h = dht.readHumidity();
        float t = dht.readTemperature();
        float f = dht.readTemperature(true);
        if (isnan(h) || isnan(t) || isnan(f)) {
          Serial.println(F("Failed to read from DHT sensor!"));
          return;
        }
        float hif = dht.computeHeatIndex(f, h);
        float hic = dht.computeHeatIndex(t, h, false);
        Serial.print(F("Humidity: "));
        Serial.print(h);
        Serial.print(F("%  Temperature: "));
        Serial.print(t);
        Serial.print(F("°C "));
        Serial.print(f);
        Serial.print(F("°F  Heat index: "));
        Serial.print(hic);
        Serial.print(F("°C "));
        Serial.print(hif);
        Serial.println(F("°F"));
      }
