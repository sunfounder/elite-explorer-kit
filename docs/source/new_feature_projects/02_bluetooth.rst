.. _new_bluetooth:

Bluetooth
========================================

Ausgestattet mit dem ESP32-Modul bietet das UNO R4 WiFi-Board sowohl Bluetooth® LE als auch Bluetooth® 5-Funktionalitäten und unterstützt Geschwindigkeiten von bis zu 2 Mbps. Das ESP32-Modul kommt mit einer integrierten Trace-Antenne, was die Notwendigkeit einer externen Antenne zur Nutzung der Konnektivitätsfunktionen des Boards überflüssig macht.

.. note::
    Die Trace-Antenne im ESP32-Modul wird mit dem Bluetooth®-Modul geteilt, was bedeutet, dass Sie Bluetooth® und Wi-Fi® nicht gleichzeitig verwenden können.

Grundkonzepte von BLE
++++++++++++++++++++++++

**Bluetooth Low Energy (BLE)** ist eine energiesparende drahtlose Kommunikationstechnologie, die speziell für Kurzstreckeninteraktionen entwickelt wurde. Im Unterschied zu klassischem Bluetooth konzentriert sich BLE auf Energieeffizienz und schnelle Verbindung, was es zu einer idealen Wahl für eine Reihe von Anwendungen wie Internet-of-Things (IoT)-Geräte und Gesundheitsüberwachungsausrüstung macht.

BLE-Kommunikationen basieren auf zwei Schlüsselprotokollen: **GATT (Generic Attribute Profile)** und **GAP (Generic Access Profile)**. GATT wird für den Datenaustausch verwendet, während GAP für die Geräteerkennung und -verbindung verantwortlich ist.

.. image:: img/02_ble_relationships.png
 :width: 100%


Peripheriegeräte (typischerweise GATT-Server)
--------------------------------------------------

Im BLE-Netzwerk übertragen **peripheral devices** hauptsächlich Daten, um von zentralen Geräten (typischerweise als GATT-Clients agierend) entdeckt und darauf zugegriffen zu werden. Solche Geräte sind in der Regel Sensoren oder kleine Hardware wie Herzfrequenzmesser, Temperatursensoren oder intelligente Glühbirnen.

Im BLE-Kommunikationsmodell bieten Peripheriegeräte häufig einen oder mehrere **services** an, die jeweils eine Reihe von **Ccharacteristics** enthalten. Diese Dienste und Charakteristiken ermöglichen gemeinsam spezifische Funktionalitäten oder Anwendungsfälle, die es zentralen Geräten erlauben, relevante Daten zu lesen oder zu manipulieren.

- **Services**

  In BLE fungieren Dienste als hochrangige Abstraktionen, die verwendet werden, um verwandte Charakteristiken zu organisieren und einzukapseln. Dienste in BLE können in Standarddienste und benutzerdefinierte Dienste eingeteilt werden, abhängig von ihrer Herkunft und ihrem Zweck.

  - Standarddienste: Definiert von der Bluetooth SIG (Bluetooth Special Interest Group), sind diese für spezifische Funktionen gedacht. Zum Beispiel der Herzfrequenzdienst für Herzfrequenzmesser, der Geräteinformationsdienst, der Hersteller-, Modell- und Versionsdetails bereitstellt, und der Batteriedienst, der den Batteriestand und -status anzeigt.
  - Benutzerdefinierte Dienste: Diese werden von Entwicklern oder Geräteherstellern definiert, um die Anforderungen spezifischer Anwendungen oder Geräte zu erfüllen. Beispielsweise könnte ein Hersteller von Smart-Home-Geräten einen benutzerdefinierten Dienst definieren, um die Farbe und Helligkeit des Lichts zu steuern.

- **Characteristics**

  Charakteristiken in BLE sind die grundlegenden Dateneinheiten, die von den Peripheriegeräten bereitgestellt werden. Sie sind innerhalb eines Dienstes enthalten und definieren verschiedene Datentypen und die Operationen, die an ihnen durchgeführt werden können. Jede Charakteristik wird durch eine UUID identifiziert und hat eine Reihe von zugehörigen Attributen wie Wert, Beschreibung und Berechtigungen.

  - Berechtigungen: In BLE ist jede Charakteristik mit einem Satz von Berechtigungen verbunden, die bestimmen, ob die Charakteristik lesbar, beschreibbar oder benachrichtigungsfähig ist. Dies hilft, die Daten zu sichern und zu definieren, wie mit ihnen interagiert wird.

- **UUID**

  Dienste, Charakteristiken und Beschreiber werden kollektiv als Attribute identifiziert, wobei jedes ein einzigartiges UUID besitzt. Die Bluetooth SIG hat eine Reihe von UUIDs für Standardattribute reserviert. Diese UUIDs werden im BLE-Protokoll normalerweise als 16-Bit- oder 32-Bit-Identifikatoren dargestellt, um Effizienz zu gewährleisten, anstatt der 128 Bit, die für eine vollständige UUID erforderlich wären. Zum Beispiel wird der Dienst für Geräteinformationen durch den Kurzcode 0x180A repräsentiert.



Central Devices (Typically GATT Clients)
--------------------------------------------------

**Central devices** im BLE-Netzwerk suchen nach nahegelegenen Peripheriegeräten und stellen Verbindungen her, um Daten zu erwerben oder zu steuern. Diese Geräte sind in der Regel komplexer und funktionsreicher, wie Smartphones, Tablets oder spezialisierte Gateway-Hardware. Sie sind verantwortlich für das Auffinden von Peripheriegeräten, deren Verbindung und den Zugriff oder das Abonnieren von Diensten und Charakteristiken, die von den Peripheriegeräten angeboten werden, um verschiedene Anwendungen zu bedienen oder spezifische Probleme zu lösen.

Zentrale Geräte interagieren auf folgende Weise mit Charakteristiken:

- **Lesen**: Fordert das Peripheriegerät auf, den aktuellen Wert einer Charakteristik zu senden. Dies wird häufig für Charakteristiken verwendet, die sich nicht oft ändern, wie Konfigurationseinstellungen oder Versionsnummern.
- **Schreiben**: Ändern Sie den Wert einer Charakteristik, typischerweise verwendet für befehlsähnliche Operationen, wie das Anweisen eines Peripheriegeräts, einen Motor ein- oder auszuschalten.
- **Abonnieren**: Fordert das Peripheriegerät auf, kontinuierlich aktualisierte Werte einer Charakteristik zu senden und eliminiert die Notwendigkeit für das zentrale Gerät, diese Daten wiederholt anzufordern.



Beispiel: Bluetooth-gesteuerte LED
++++++++++++++++++++++++++++++++++++++++++++++++++++++++

In diesem Beispiel fungiert das Arduino als Peripheriegerät in einem Bluetooth Low Energy (BLE)-Netzwerk. Es bietet einen benutzerdefinierten BLE-Dienst an, der zur Steuerung einer Onboard-LED entwickelt wurde. Dieser Dienst beinhaltet eine Charakteristik, die von einem zentralen Gerät, wie einem Smartphone, gelesen und beschrieben werden kann. Sobald das zentrale Gerät eine Verbindung zum Arduino herstellt, kann es den LED-Status durch Schreiben dieser Charakteristik ändern. Der serielle Monitor des Arduino zeigt Debugging-Informationen an, einschließlich des aktuellen Zustands der LED und der MAC-Adresse des verbundenen zentralen Geräts.

**Code hochladen**

Öffnen Sie die Datei „02-bluetooth.ino“, die sich unter „elite-explorer-kit-main\r4_new_feature\02-bluetooth“ befindet, oder fügen Sie den folgenden Code in Ihre Arduino IDE ein.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/44d76bb7-9f0a-4004-b3fe-9a88999c5f06/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Verbindung des Arduino R4 über Bluetooth**

Um mit den in diesem Sketch erstellten Diensten und Charakteristiken zu interagieren, sollten wir eine generische Bluetooth® Low Energy Central App wie LightBlue (verfügbar für iOS und Android) oder nRF Connect (für Android) nutzen.

Wir nehmen LightBlue als Beispiel, um zu demonstrieren, wie man die LED des Arduino über Bluetooth steuert.

1. Laden Sie die **LightBlue**-App aus dem |link_lightblue_apple| (für iOS) oder |link_lightblue_google| (für Android) herunter.

   .. image:: img/02_lightblue.png
    :width: 90%

   .. raw:: html

      <br/><br/>

2. Verbindung des Arduino mit Ihrem Smartphone über Bluetooth
   
   Gehen Sie zu Ihren Bluetooth-Einstellungen und suchen Sie das Gerät namens „UNO R4 LED“. Verbinden Sie sich damit.

   .. image:: img/02_connect.png
    :width: 90%

   .. raw:: html

      <br/>

3. Interaktion mit dem Arduino über Bluetooth mit LightBlue

   Starten Sie LightBlue und tippen Sie auf den Tab **Bonded** unten in der Schnittstelle. Hier sehen Sie eine Liste der BLE-Geräte, mit denen Ihr Smartphone zuvor gekoppelt wurde. Suchen Sie nach **UNO R4 LED** und tippen Sie auf **CONNECT**.

   .. image:: img/02_lightblue_1.png
    :width: 90%

   Einmal verbunden, erhalten Sie Zugriff auf detaillierte Informationen über das Bluetooth-Gerät „UNO R4 LED“. Scrollen Sie nach unten, um „ledService (**19B10000-E8F2-537E-4F6C-D104768A1214**)“ und „switchCharacteristic (**19B10001-E8F2-537E-4F6C-D104768A1214**)“ zu finden.

   Tippen Sie auf die Charakteristik 19B10001-E8F2-537E-4F6C-D104768A1214. Sie werden feststellen, dass diese Charakteristik sowohl lesbar als auch beschreibbar ist, sodass Sie sowohl von ihr lesen als auch auf sie schreiben können.
  
   .. image:: img/02_lightblue_2.png
    :width: 90%

   Scrollen Sie weiter zum Abschnitt **WRITTEN VALUES**. Geben Sie **„1“** in das Textfeld ein, um den Charakteristikwert auf 1 zu setzen, was die **eingebaute LED des Arduino R4 einschaltet**.

   .. image:: img/02_lightblue_3.png
    :width: 90%

   Ebenso können Sie diesen Wert auf **„0“** setzen, um die **eingebaute LED auszuschalten**.

   .. image:: img/02_lightblue_4.png
    :width: 90%



**Code-Erklärung**

#. BLE und LED initialisieren

   .. note::
      Beim Definieren von Diensten und Charakteristiken müssen wir UUIDs verwenden, um sie zu identifizieren. Um UUID-Konflikte zu vermeiden und die Nutzung für Sie zu erleichtern, können Sie das UUID-Generierungstool unter |link_uuid_gen_tool| verwenden.

   .. code-block:: arduino
   
      #include <ArduinoBLE.h>
      BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); // Bluetooth® Low Energy LED Service
      BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);
      const int ledPin = LED_BUILTIN; // pin to use for the LED

   - Die ArduinoBLE-Bibliothek einbinden.
   - Den BLE-Dienst und die Charakteristik definieren.
   - Den eingebauten LED-Pin mit ``ledPin`` zuweisen.

   .. raw:: html

      <br/>

#. Funktion ``setup()``

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);
        while (!Serial);
        pinMode(ledPin, OUTPUT);
        if (!BLE.begin()) {
          Serial.println("starting Bluetooth® Low Energy module failed!");
          while (1);
        }
        BLE.setLocalName("UNO R4 LED");
        BLE.setAdvertisedService(ledService);
        ledService.addCharacteristic(switchCharacteristic);
        BLE.addService(ledService);
        switchCharacteristic.writeValue(0);
        BLE.advertise();
        Serial.println("BLE LED Peripheral");
      }

   - Serielle Kommunikation initialisieren.
   - Den LED-Pin als Ausgang setzen.
   - BLE initialisieren und den Dienst sowie die Charakteristiken hinzufügen.
   - BLE-Werbung starten.

   .. raw:: html

      <br/>

#. ``loop()`` Function

   .. code-block:: arduino
   
      void loop() {
        BLEDevice central = BLE.central();
        if (central) {
          Serial.print("Connected to central: ");
          Serial.println(central.address());
          while (central.connected()) {
            if (switchCharacteristic.written()) {
              if (switchCharacteristic.value()) {
                Serial.println("LED on");
                digitalWrite(ledPin, HIGH);
              } else {
                Serial.println("LED off");
                digitalWrite(ledPin, LOW);
              }
            }
          }
          Serial.print("Disconnected from central: ");
          Serial.println(central.address());
        }
      }
   
   - Auf Verbindungen von BLE-Zentralgeräten lauschen.
   - Wenn ein Zentralgerät verbunden ist, den Charakteristikwert lesen, um die LED zu steuern. Wenn ein Wert ungleich 0 empfangen wird, die LED einschalten. Wenn 0 empfangen wird, die LED ausschalten.

**Referenz**

- |link_r4_bluetooth|
