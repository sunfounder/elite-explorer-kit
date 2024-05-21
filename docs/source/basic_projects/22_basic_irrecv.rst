.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _basic_irrecv:

Infrarot-Empfänger
==========================

.. https://docs.sunfounder.com/projects/uno-mega-kit/en/latest/uno/infrared_Receiver_uno.html#receive-uno

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/infrared_Receiver_uno.html#receive-uno


Überblick
------------------

Ein Infrarot-Empfänger ist eine Komponente, die Infrarotsignale empfängt und unabhängig Infrarotstrahlen empfangen und Signale ausgeben kann, die mit TTL-Pegel kompatibel sind. Er ähnelt in der Größe einem normalen, in Kunststoff verpackten Transistor und eignet sich für alle Arten von Infrarot-Fernbedienungen und Infrarot-Übertragungen.

Benötigte Komponenten
-------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_ir_receiver`
        - |link_receiver_buy|


Verdrahtung
----------------------

.. image:: img/22-ir_receiver_bb.png
    :align: center
    :width: 80%


Schaltplan
---------------------

.. image:: img/22_irrecv_schematic.png
    :align: center
    :width: 50%

Code
---------------

.. note::

    * Sie können die Datei ``22-ir_receiver.ino`` direkt im Pfad ``elite-explorer-kit-main\basic_project\22-ir_receiver`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/92e1cb75-cda1-4fc7-9680-28e28df8dccc/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

* Hier wird die ``IRremote`` Bibliothek verwendet, die Sie über den **Library Manager** installieren können.

    .. image:: img/22_irrecv_lib.png
        :align: center

.. Note::

    * An der Rückseite der Fernbedienung befindet sich ein transparentes Kunststoffteil, um die Stromzufuhr zu unterbrechen. Ziehen Sie es heraus, bevor Sie die Fernbedienung benutzen.


Code-Analyse
---------------------

Dieser Code ist für die Verwendung mit einer Infrarot (IR) Fernbedienung und der ``IRremote`` Bibliothek konzipiert. Hier ist die Aufschlüsselung:

#. Einbinden der Bibliothek und Definieren von Konstanten. Zunächst wird die IRremote Bibliothek eingebunden, und die Pinnummer für den IR-Empfänger wird als 2 definiert.

   .. code-block:: cpp
 
     #include <IRremote.h>
     const int IR_RECEIVE_PIN = 2;


#. Initialisiert die serielle Kommunikation mit einer Baudrate von 9600. Initialisiert den IR-Empfänger am angegebenen Pin (``IR_RECEIVE_PIN``) und aktiviert die LED-Rückmeldung (falls zutreffend).

   .. code-block:: arduino

       void setup() {
           Serial.begin(9600);                                     // Start serial communication at 9600 baud rate
           IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
       }

#. Die Schleife läuft kontinuierlich, um eingehende IR-Fernbedienungssignale zu verarbeiten.

   .. code-block:: arduino

      void loop() {
        // Check if there is any incoming IR signal
        if (IrReceiver.decode()) {
          // IrReceiver.printIRResultShort(&Serial);                 // Print the received data in one line
          // Serial.println(IrReceiver.decodedIRData.command, HEX);  // Print the command in hexadecimal format
          Serial.println(decodeKeyValue(IrReceiver.decodedIRData.command));  // Map and print the decoded IR signal to corresponding key value
      
          IrReceiver.resume();  // Enable receiving of the next value
        }
      }
   
   * Überprüft, ob ein IR-Signal empfangen und erfolgreich decodiert wurde.
   * Decodiert den IR-Befehl und speichert ihn in ``decodedValue`` mit einer benutzerdefinierten Funktion ``decodeKeyValue()``.
   * Druckt den decodierten IR-Wert auf den seriellen Monitor.
   * Setzt den IR-Signalempfang für das nächste Signal fort.

   .. raw:: html

        <br/>

#. Hilfsfunktion, um empfangene IR-Signale den entsprechenden Tasten zuzuordnen

   .. image:: img/22_irrecv_key.png
      :align: center
      :width: 80%

   .. code-block:: arduino

      // Function to map received IR signals to corresponding keys
      String decodeKeyValue(long result) {
        // Each case corresponds to a specific IR command
        switch (result) {
          case 0x16:
            return "0";
          case 0xC:
            return "1";
          case 0x18:
            return "2";
          case 0x5E:
            return "3";
          case 0x8:
            return "4";
          case 0x1C:
            return "5";
          case 0x5A:
            return "6";
          case 0x42:
            return "7";
          case 0x52:
            return "8";
          case 0x4A:
            return "9";
          case 0x9:
            return "+";
          case 0x15:
            return "-";
          case 0x7:
            return "EQ";
          case 0xD:
            return "U/SD";
          case 0x19:
            return "CYCLE";
          case 0x44:
            return "PLAY/PAUSE";
          case 0x43:
            return "FORWARD";
          case 0x40:
            return "BACKWARD";
          case 0x45:
            return "POWER";
          case 0x47:
            return "MUTE";
          case 0x46:
            return "MODE";
          case 0x0:
            return "ERROR";
          default:
            return "ERROR";
        }
      }