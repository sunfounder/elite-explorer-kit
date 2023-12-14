Mit Wi-Fi verbinden
----------------------------------------

Dieses Tutorial führt Sie durch die wesentlichen Schritte, um Ihr Arduino-Board mit einem Wi-Fi-Netzwerk zu verbinden. Sie lernen, wie Sie das Wi-Fi-Modul initialisieren, seine Firmware überprüfen und sicher einem Netzwerk mit SSID und Passwort beitreten. Sobald Sie verbunden sind, erfahren Sie, wie Sie wichtige Netzwerkinformationen wie die IP- und MAC-Adressen Ihres Geräts sowie die Signalstärke des Netzwerks direkt über die serielle Konsole überwachen. Dieses Tutorial dient sowohl als praktischer Leitfaden für die Wi-Fi-Konnektivität als auch als Einführung in die Netzwerküberwachung mit Arduino, um eine zuverlässige Wi-Fi-Verbindung herzustellen und aufrechtzuerhalten.

1. Laden Sie den Code hoch
==============================

Öffnen Sie die Datei ``01-wifi_connect.ino`` im Pfad ``elite-explorer-kit-main\r4_new_feature\01-wifi_connect`` oder kopieren Sie diesen Code in die **Arduino IDE**.

.. note:: 
      Wi-Fi® wird über die integrierte ``WiFiS3``-Bibliothek aktiviert, die mit dem Arduino UNO R4 Core geliefert wird. Die Installation des Cores installiert automatisch die ``WiFiS3``-Bibliothek.


Sie müssen auch ``arduino_secrets.h`` erstellen oder bearbeiten, ersetzen Sie ``SECRET_SSID`` und ``SECRET_PASS`` durch den Namen und das Passwort des Wi-Fi, mit dem Sie sich verbinden möchten. Die Datei sollte enthalten:

.. code:: arduino

    //arduino_secrets.h header file
    #define SECRET_SSID "yournetwork"
    #define SECRET_PASS "yourpassword"

.. raw:: html
       
   <iframe src=https://create.arduino.cc/editor/sunfounder01/a41ac638-31da-464c-b5d3-e70f2aacd29c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Öffnen Sie den seriellen Monitor, und Sie werden ähnliche Inhalte wie folgt sehen. Arduino gibt die IP- und MAC-Adressen Ihres Geräts sowie die Signalstärke des Netzwerks aus.

.. image:: img/01_1_wifi.png
    :width: 100%


2. Code-Erklärung
========================

1. Einbinden von Bibliotheken und Geheimdaten

   .. code-block:: arduino

      #include <WiFiS3.h>
      #include "arduino_secrets.h" 

   - ``WiFiS3`` ist eine Bibliothek, die Funktionen für die Wi-Fi-Konnektivität bietet. Die Installation des R4-Cores installiert automatisch die WiFiS3-Bibliothek.
   - ``arduino_secrets.h`` ist eine separate Datei, in der Sie Ihre SSID und Ihr Passwort speichern, damit sie nicht in Ihrem Hauptcode offengelegt werden. Das getrennte Speichern von Netzwerk und Passwort verringert das versehentliche Teilen von Wi-Fi-Anmeldedaten.

   .. raw:: html

      <br/>

2. Globale Variablen deklarieren

   .. code-block:: arduino

      char ssid[] = SECRET_SSID;
      char pass[] = SECRET_PASS;
      int status = WL_IDLE_STATUS;

   - ``ssid`` und ``pass`` enthalten Ihren Netzwerknamen und Ihr Passwort.
   - ``status`` speichert den aktuellen Status Ihrer Wi-Fi-Verbindung.

   .. raw:: html

      <br/>

3. Funktion ``setup()``

   Die serielle Schnittstelle wird mit einer Baudrate von 9600 initialisiert. Die Zeile ``while (!Serial);`` stellt sicher, dass das Programm wartet, bis die serielle Verbindung hergestellt ist.

   .. code-block:: arduino

      void setup() {
          //Initialize serial and wait for port to open:
          Serial.begin(9600);
          while (!Serial) {
            ; // wait for serial port to connect. Needed for native USB port only
          }
          ...
      }

   Anschließend überprüft der Code, ob das Wi-Fi-Modul verfügbar ist oder nicht. Wenn nicht, wird das Programm angehalten und jegliche weitere Ausführung gestoppt.

   .. code-block:: arduino

     ...
     // check for the WiFi module:
     if (WiFi.status() == WL_NO_MODULE) {
         Serial.println("Communication with WiFi module failed!");
         // don't continue
         while (true);
     }
     ...

   In diesem Teil des Codes überprüfen wir, ob die Firmware-Version des Uno R4 WiFi auf dem neuesten Stand ist. Wenn nicht, wird eine Aufforderung zum Upgrade angezeigt. Sie können :ref:`update_firmware` für das Firmware-Upgrade konsultieren.

   .. https://forum.arduino.cc/t/radio-module-firmware-version-0-2-0-is-now-available/1147361

   .. code-block:: arduino

      ...
      String fv = WiFi.firmwareVersion();
      if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
          Serial.println("Please upgrade the firmware");
      }
      ...

4. Funktion ``loop()``

   .. code-block:: arduino

      void loop() {
        // check the network connection once every 10 seconds:
        delay(10000);
        printCurrentNet();
      }

   - Alle 10 Sekunden wird die Funktion ``printCurrentNet()`` aufgerufen, um die aktuellen Netzwerkinformationen auszudrucken.


**Referenz**

- |link_r4_wifi|
