.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _iot_Bluetooth_lcd:

Bluetooth-Nachrichtenbox
=============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/07_iot_ble_lcd.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Dieses Projekt empfängt Nachrichten und zeigt sie auf einem LCD-Bildschirm an.

Sie können es als Familien-Nachrichtentafel nutzen, um Familienmitglieder, die noch nicht gegangen sind, daran zu erinnern, ihre Schlüssel mitzunehmen.

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**Verdrahtung**

.. image:: img/07_lightblue_lcd_bb.png
    :width: 100%
    :align: center

**Schaltplan**

.. image:: img/07_lightblue_lcd_schematic.png
   :width: 80%
   :align: center

.. raw:: html

   <br/>

**UUID generieren**

UUIDs spielen eine entscheidende Rolle bei der BLE-Kommunikation und gewährleisten die Einzigartigkeit von Geräten sowie die Genauigkeit des Datenaustauschs zwischen ihnen. Sie müssen UUIDs anpassen, um Ihre eigenen BLE-Dienste und -Merkmale für spezifische Anforderungen zu erstellen. (Hier müssen wir ein Merkmal erstellen, das Texteingaben unterstützt.)

1. Verwenden Sie das `Online UUID Generator Tool <https://www.uuidgenerator.net/version4>`_, um UUIDs zu erstellen, die einzigartig für Sie sind, um UUID-Konflikte zu vermeiden.

2. Erzeugen Sie zwei UUIDs der Version 4.

   .. image:: img/07_uuid_1.png
      :width: 70%

   .. raw:: html

      <br/><br/>

3. Kopieren Sie sie und ersetzen Sie die beiden UUIDs in Ihrem Code.

   .. code-block:: arduino
   
       #define SERVICE_UUID "uuid1"
       #define CHARACTERISTIC_UUID "uuid2"

**Bibliothek installieren**

``ArduinoBLE.h``: Wird für die Verwaltung von Bluetooth Low Energy (BLE) Kommunikation verwendet.
``LiquidCrystal_I2C.h``: Wird verwendet, um einen 16x2-Zeichen-LCD-Bildschirm mit einer I2C-Schnittstelle zu steuern.

**Code ausführen**

.. note::

    * Sie können die Datei ``07_lightblue_lcd.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\iot_project\07_lightblue_lcd`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino-Bibliotheksmanager, um nach **„ArduinoBLE“** und **„LiquidCrystal I2C“** zu suchen und diese zu installieren.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/958c37c2-a897-4c4c-b6c1-0e7fea67c7b1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Wie funktioniert des?**

Um mit den in diesem Sketch erstellten Diensten und Merkmalen zu interagieren, sollten Sie eine generische Bluetooth® Low Energy-Zentral-App wie LightBlue (verfügbar für iOS und Android) oder nRF Connect (für Android) verwenden.

Wir verwenden LightBlue als Beispiel, um zu demonstrieren, wie man Arduino's LED über Bluetooth steuert.

1. Laden Sie die LightBlue-App aus dem App Store (für iOS) oder Google Play (für Android) herunter.

   .. image:: img/07_lightblue.png

2. Verbinden des Arduino mit Ihrem Smartphone über Bluetooth

   Gehen Sie zu Ihren Bluetooth-Einstellungen und suchen Sie das Gerät namens „UNO R4 BLE.“ Stellen Sie eine Verbindung dazu her.

   .. image:: img/07_iot_ble_01.jpg
      :width: 50%

   .. raw:: html

      <br/><br/>

3. Interaktion mit Arduino über Bluetooth mit LightBlue

   Starten Sie LightBlue und tippen Sie auf den Reiter **Bonded** unten in der Schnittstelle. Hier sehen Sie eine Liste der BLE-Geräte, mit denen Ihr Smartphone zuvor gekoppelt wurde. Finden Sie **UNO R4 BLE** und tippen Sie auf **CONNECT**.

   .. image:: img/07_iot_ble_02.jpg

   Nachdem Sie verbunden sind, erhalten Sie Zugang zu detaillierten Informationen über das Bluetooth-Gerät. Scrollen Sie nach unten, um Ihre Dienst-UUID und Ihre Charakteristik-UUID zu finden.

   Tippen Sie auf die Charakteristik. Sie werden feststellen, dass diese Charakteristik sowohl lesbar als auch beschreibbar ist, was Ihnen erlaubt, sowohl davon zu lesen als auch darauf zu schreiben.

   Scrollen Sie weiter zum Abschnitt „Datenformat“ und ändern Sie ihn auf UTF-8-String.
   Geben Sie Text in das Textfeld ein und klicken Sie auf schreiben. Die von Ihnen eingegebene Nachricht erscheint auf dem LCD.

   .. image:: img/07_iot_ble_03.jpg

**Wie funktioniert des?**

Hier sind die Hauptteile des Codes und Erklärungen ihrer Funktionen:

1. Einbinden der erforderlichen Bibliotheken:

   * ``ArduinoBLE.h``: Wird für die Handhabung von BLE-Kommunikation verwendet.
   * ``Wire.h``: Wird für I2C-Kommunikation verwendet.
   * ``LiquidCrystal_I2C.h``: Wird verwendet, um einen 16x2-Zeichen-LCD-Bildschirm mit einer I2C-Schnittstelle zu steuern.

2. Definieren eines BLE-Dienstes und einer BLE-Charakteristik:

   * Verwenden Sie die Klasse ``BLEService``, um einen BLE-Dienst zu definieren und ihm eine einzigartige UUID zuzuweisen.
   * Verwenden Sie die Klasse ``BLECharacteristic``, um eine BLE-Charakteristik zu definieren, ihr eine einzigartige UUID zuzuweisen und ihr Lese- (``BLERead``) und Schreibrechte (``BLEWrite``) zu geben.
   * Erstellen Sie ein Zeichen-Array ``stringValue`` als Anfangswert der Charakteristik.

3. Initialisieren eines 16x2-Zeichen-LCD-Bildschirms (LCD):

   * Verwenden Sie die Klasse ``LiquidCrystal_I2C``, um ein LCD zu initialisieren, indem Sie die I2C-Adresse (0x27) und die Anzahl der Zeilen und Spalten (16x2) angeben.
   * Schalten Sie die Hintergrundbeleuchtung des LCD ein, löschen Sie den Bildschirm, bewegen Sie den Cursor zum Anfang der ersten Zeile und zeigen Sie „Bluetooth LCD“ an.

4. Durchführung der Initialisierung in der Funktion ``setup()``:

   * Initialisieren der seriellen Kommunikation.
   * Initialisieren des BLE-Moduls und, falls die Initialisierung fehlschlägt, in eine unendliche Schleife eintreten.
   * Setzen des lokalen Namens und der Service-UUID für das BLE-Peripheriegerät.
   * Hinzufügen der BLE-Charakteristik zum BLE-Dienst.
   * Starten der Werbung für den BLE-Dienst, damit zentrale Geräte ihn entdecken und sich damit verbinden können.
   * Initialisieren des LCD.

5. Die Funktion ``loop()``:

   * Überprüfen, ob ein zentrales Gerät mit dem BLE-Peripheriegerät verbunden ist, indem ``BLE.central()`` aufgerufen wird. Wenn ein zentrales Gerät verbunden ist, in die Logik der Verbindungsbearbeitung eintreten.
   * Im verbundenen Zustand überprüfen, ob Daten in die BLE-Charakteristik geschrieben wurden, indem ``boxCharacteristic.written()`` überprüft wird.
   * Wenn Daten geschrieben wurden, die Länge der geschriebenen Daten mit ``boxCharacteristic.valueLength()`` ermitteln und ein Byte-Array ``buffer`` erstellen, um die geschriebenen Daten zu speichern.
   * Verwenden Sie ``boxCharacteristic.readValue()``, um Daten aus der BLE-Charakteristik in den ``buffer`` zu lesen.
   * Ein Nullzeichen ``'\0'`` an das Ende des ``buffer`` hinzufügen, um es in einen String zu konvertieren.
   * Die empfangene Nachricht auf dem seriellen Monitor ausgeben und auf dem LCD anzeigen.
   * Weiterhin auf das nächste zentrale Gerät warten, das sich verbindet, nachdem das zentrale Gerät getrennt wurde.

