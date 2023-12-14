.. _iot_ble_home:

Bluetooth-Umweltmonitor
=================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/08_iot_ble_home.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>


Dieses Projekt verwendet eine Android-App, die mit MIT App Inventor erstellt wurde, um Umweltdaten von einem Arduino-Board zu empfangen und anzuzeigen. Das Arduino-Board holt Daten von einem DHT11-Sensor, um Temperatur und Feuchtigkeit zu messen. Sobald die Daten gesammelt sind, werden sie über Bluetooth übertragen. Die App zeigt die Daten auf dem Bildschirm an, sobald sie empfangen werden.

Die Android-Anwendung wird unter Verwendung einer kostenlosen webbasierten Plattform namens |link_appinventor| erstellt. Das Projekt bietet eine ausgezeichnete Gelegenheit, sich mit der Schnittstelle zwischen einem Arduino und einem Smartphone vertraut zu machen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Sie können sie auch separat über die untenstehenden Links kaufen.

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

**1. Bauen Sie den Schaltkreis**

.. image:: img/08-bluetooth_environmental_monitor_bb.png
    :width: 80%
    :align: center

.. image:: img/08_ble_home_schematic.png
    :width: 30%
    :align: center

.. raw:: html

   <br/>

**2. Erstellen Sie die Android-App**

Die Android-Anwendung wird unter Verwendung einer kostenlosen Webanwendung namens |link_appinventor| entwickelt. 
MIT App Inventor dient als ausgezeichneter Einstiegspunkt für die Android-Entwicklung, dank seiner intuitiven Drag-and-Drop-Funktionen, die die Erstellung einfacher Anwendungen ermöglichen.

Lassen Sie uns beginnen.

#. Gehen Sie zu |link_appinventor_login| und klicken Sie auf „Online-Tool“, um sich anzumelden. Sie benötigen ein Google-Konto, um sich bei MIT App Inventor zu registrieren.

   .. image:: img/08_ai_signup.png
       :width: 90%
       :align: center

#. Nach dem Einloggen navigieren Sie zu **Projects** -> **Import project (.aia) from my computer**. Laden Sie anschließend die Datei ``ble_environmental_monitor.aia`` hoch, die sich im Pfad ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor`` befindet.

   Sie können sie auch direkt hier herunterladen: :download:`ble_environmental_monitor.aia</_static/other/ble_environmental_monitor.aia>`

   .. image:: img/08_ai_import.png
        :align: center

#. Nach dem Hochladen der ``.aia``-Datei sehen Sie die Anwendung in der MIT App Inventor-Software. Dies ist eine vorkonfigurierte Vorlage. Sie können diese Vorlage ändern, nachdem Sie sich mit MIT App Inventor vertraut gemacht haben, indem Sie die folgenden Schritte befolgen.

#. In MIT App Inventor haben Sie 2 Hauptbereiche: den **Designer** und die **Blocks**. Sie können zwischen diesen beiden Bereichen in der oberen rechten Ecke der Seite wechseln.

   .. image:: img/08_ai_intro_1.png

#. Der **Designer** ermöglicht es Ihnen, Buttons, Text, Bildschirme hinzuzufügen und das Gesamtaussehen Ihrer Anwendung zu ändern.

   .. image:: img/08_ai_intro_2.png
      :width: 100%
   
#. Als Nächstes gibt es den Bereich **Blocks**. Dieser Abschnitt ermöglicht es Ihnen, benutzerdefinierte Funktionalitäten für Ihre App zu erstellen, indem Sie jedes Element in der grafischen Benutzeroberfläche der App programmieren, um die gewünschten Funktionen zu erreichen.

   .. image:: img/08_ai_intro_3.png
      :width: 100%

#. Um die Anwendung auf einem Smartphone zu installieren, navigieren Sie zum Reiter **Build**.

   .. image:: img/08_ai_intro_4.png

   * Sie können eine ``.apk``-Datei erstellen. Nachdem Sie diese Option ausgewählt haben, erscheint eine Seite, auf der Sie zwischen dem Herunterladen einer ``.apk``-Datei oder dem Scannen eines QR-Codes für die Installation wählen können. Folgen Sie der Installationsanleitung, um die Installation der Anwendung abzuschließen.

     Sie können auch unsere vorab kompilierte APK hier herunterladen: :download:`ble_environmental_monitor.apk</_static/other/ble_environmental_monitor.apk>`

   * Wenn Sie diese App auf Google Play oder einem anderen App-Marktplatz hochladen möchten, können Sie eine ``.aab``-Datei generieren.


**3. Code hochladen**

#. Öffnen Sie die Datei ``08-bluetooth_environmental_monitor.ino`` unter dem Pfad ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor``, oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino-Bibliotheksmanager, um nach **„DHT sensor library“** und **„ArduinoBLE“** zu suchen und diese zu installieren.

   .. raw:: html
       
      <iframe src=https://create.arduino.cc/editor/sunfounder01/53fd4af4-dcc6-439d-b52f-2f94f17c1263/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nachdem Sie das richtige Board und den richtigen Port ausgewählt haben, klicken Sie auf die Schaltfläche **Hochladen**.

#. Öffnen Sie den Seriellen Monitor (Baudrate auf **9600** einstellen), um Debug-Nachrichten zu sehen. 

**4. App- und Bluetooth-Modul-Verbindung**

Stellen Sie sicher, dass die zuvor erstellte Anwendung auf Ihrem Smartphone installiert ist.

#. Schalten Sie zunächst das **Bluetooth** auf Ihrem Smartphone ein.

   .. image:: img/08_app_1.png
      :width: 60%
      :align: center

#. Öffnen Sie nun die neu installierte **Environmental Monitor**-APP.

   .. image:: img/08_app_2.png
      :width: 25%
      :align: center

#. Wenn Sie diese App zum ersten Mal öffnen, erscheinen nacheinander zwei Autorisierungsaufforderungen. Dies sind die Berechtigungen, die für die Verwendung von Bluetooth erforderlich sind.

   .. image:: img/08_app_3.png
      :width: 100%
      :align: center

   .. raw:: html

      <br/>

#. In der App klicken Sie auf die Schaltfläche **Connect**, um eine Verbindung zwischen der App und dem Bluetooth-Modul herzustellen.

   .. image:: img/08_app_4.png
      :width: 55%
      :align: center

#. Diese Seite zeigt eine Liste aller gekoppelten Bluetooth-Geräte an. Wählen Sie die Option ``xx.xx.xx.xx.xx.xx UNO R4 Home`` aus der Liste. Der Name jedes Geräts ist neben seiner MAC-Adresse aufgeführt.

   .. image:: img/08_app_5.png
      :width: 60%
      :align: center
   
   .. raw:: html

      <br/>

#. Wenn Sie auf der oben gezeigten Seite keine Geräte sehen, können Sie versuchen, den Standort-Schalter des Geräts einzuschalten (einige Android-Systemversionen bündeln den Standort-Schalter mit der Bluetooth-Funktion).

   .. image:: img/08_app_6.png
      :width: 60%
      :align: center

   .. raw:: html

      <br/>

#. Nach einer erfolgreichen Verbindung werden Sie zur Hauptseite umgeleitet, auf der Temperatur und Luftfeuchtigkeit angezeigt werden.

   .. image:: img/08_app_7.png
      :width: 60%
      :align: center

**5. Code-Erklärung**

1. Importieren von Bibliotheken und Definieren von Konstanten

   - Importieren Sie die erforderlichen Bibliotheken und definieren Sie Konstanten für den DHT-Sensor-Pin und -Typ.

   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino-Bibliotheksmanager, um nach **„DHT sensor library“** und **„ArduinoBLE“** zu suchen und diese zu installieren.

   .. code-block:: arduino
   
       #include <DHT.h>
       #include <ArduinoBLE.h>
       #define DHTPIN 11
       #define DHTTYPE DHT11

2. Initialisierung von BLE-Diensten und -Merkmale

   - Definieren Sie die UUIDs für BLE Environmental Sensing Service und Merkmale. Wir verwenden die von |link_bluetooth_sig| bereitgestellten vordefinierten UUIDs. Der |link_sig_environmental_sensing| wird ``0x181A`` zugewiesen, während ``0x2A6E`` und ``0x2A6F`` für |link_sig_temperature_humidity| reserviert sind.

   .. code-block:: arduino
   
       BLEService environmentalSensingService("181A");
       BLEShortCharacteristic temperatureCharacteristic("2A6E", BLERead | BLENotify);
       BLEUnsignedShortCharacteristic humidityCharacteristic("2A6F", BLERead | BLENotify);

3. Setup-Funktion

   - Initialisieren Sie die serielle Kommunikation, den DHT-Sensor und BLE.

   .. code-block:: arduino
   
       void setup() {
         Serial.begin(9600);
         dht.begin();
         if (!BLE.begin()) {
           Serial.println("starting Bluetooth® Low Energy module failed!");
           while (1)
             ;
         }
         setupBle();
       }

4. Haupt-Schleife

   - Abfragen von BLE-Ereignissen und regelmäßiges Aktualisieren der Sensordaten.

   - Die Zeile ``millis() - lastUpdateTime > updateInterval`` stellt sicher, dass die Sensordaten alle updateInterval Millisekunden aktualisiert werden.

   .. code-block:: arduino
   
       void loop() {
         BLE.poll();
         if (millis() - lastUpdateTime > updateInterval) {
           // Read sensor data and update BLE characteristics
         }
       }

5. BLE- und Debug-Funktionen

   Funktionen für das Einrichten von BLE, das Drucken von Debug-Informationen und das Verwalten von BLE-Ereignissen.

   .. code-block:: arduino
   
       void printDHT(float h, float t) { /* ... */ }
       void setupBle() { /* ... */ }
       void blePeripheralConnectHandler(BLEDevice central) { /* ... */ }
       void blePeripheralDisconnectHandler(BLEDevice central) { /* ... */ }

   - ``printDHT(float h, float t)``: Wird verwendet, um die vom DHT11 gelesenen Temperatur- und Feuchtigkeitsdaten auf dem seriellen Monitor auszudrucken. Diese Funktion dient zu Debugging-Zwecken.

   - ``setupBle()``: Initialisiert Bluetooth, einschließlich der Einstellung des Sendenamens, der Merkmale und Dienste.

   - ``blePeripheralConnectHandler(BLEDevice central)`` und ``blePeripheralDisconnectHandler(BLEDevice central)``: Diese Funktionen behandeln Ereignisse, wenn Bluetooth sich verbindet oder trennt. Wenn ein Gerät erfolgreich über Bluetooth mit dem UNO R4 verbunden ist, leuchtet die LED an Bord. Wenn das Gerät die Verbindung trennt, schaltet sich die LED aus.
