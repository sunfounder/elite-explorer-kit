.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _basic_mfrc522:

RFID-RC522 Modul
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.35_rfid-rc522_module.html

Überblick
-------------

In dieser Lektion lernen Sie, wie man ein RFID-Modul verwendet. RFID steht für Radiofrequenz-Identifikation. Sein Funktionsprinzip beinhaltet die kontaktlose Datenkommunikation zwischen dem Lesegerät und dem Etikett zur Identifizierung des Ziels. Die Anwendungen von RFID sind umfangreich, einschließlich Tierchips, Wegfahrsperren, Zugangskontrollen, Parksteuerung, Automatisierung von Produktionsketten, Materialmanagement und vieles mehr.

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
    *   - :ref:`cpn_mfrc522`
        - |link_mfrc522_rfid_buy|

Verdrahtung
---------------------

In diesem Beispiel stecken wir das RFID in das Breadboard. Verbinden Sie die 3.3V des RFID mit 3.3V, GND mit GND, RST mit Pin 2, SDA mit Pin 6, SCK mit Pin 5, MOSI mit Pin 4, MISO mit Pin 3 und IRQ mit Pin 7.

.. image:: img/08-rfid_bb.png
   :align: center

Schaltplan
-------------------------

.. image:: img/08_mfrc522_schematic.png
   :align: center
   :width: 70%

Code
-----------

.. note::

    * Sie können die Datei ``08-mfrc522.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\08-mfrc522`` öffnen.
    * Hier wird die ``RFID1`` Bibliothek verwendet. Die Bibliothek finden Sie im Verzeichnis ``elite-explorer-kit-main/library/``, oder Sie können hier :download:`RFID1.zip </_static/RFID1.zip>` herunterladen. Eine Anleitung zur Installation finden Sie unter :ref:`manual_install_lib`.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9a4e9be9-78f5-4bf0-8b44-ca6e44092dc1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem die Codes auf das Uno-Board hochgeladen wurden, können Sie Ihre RFID-Karte (geheimer Schlüssel) in die Nähe des RFID-Lesegeräts bringen. Das Modul wird die Karteninformationen lesen und dann auf dem seriellen Monitor ausgeben.


Code-Analyse
-------------------

Die Funktionen des Moduls sind in der Bibliothek ``rfid1.h`` enthalten.

.. code-block:: arduino

    #include <rfid1.h>

**Bibliotheksfunktionen:**

.. code-block:: arduino

    RFID1 rfid;

Erstellen einer neuen Instanz der Klasse rfid1, die ein bestimmtes
RFID-Modul repräsentiert, welches an Ihr Arduino angeschlossen ist.

.. code-block:: arduino

    void begin(IRQ_PIN,SCK_PIN,MOSI_PIN,MISO_PIN,SDA_PIN,RST_PIN)

Pin-Konfiguration.

* ``IRQ_PIN,SCK_PIN,MOSI_PIN,MISO_PIN``: die Pins, die für die SPI-Kommunikation verwendet werden.
* ``SDA_PIN``: Synchroner Datenadapter.
* ``RST_PIN``: Die Pins, die für den Reset verwendet werden.

.. code-block:: arduino

    void init()

Initialisieren des RFID.

.. code-block:: arduino

    uchar request(uchar reqMode, uchar *TagType);

Kartensuche und Kartentyp lesen, die Funktion gibt den aktuellen Lesezustand des RFID zurück und MI_OK, wenn erfolgreich.

* ``reqMode``: Suchmethoden. PICC_REQIDL ist definiert als 0x26 Befehlsbits (Suchen der Karten, die nicht im Schlafmodus im Antennenbereich sind).
* ``*TagType``: Wird verwendet, um den Kartentyp zu speichern, und sein Wert kann 4 Byte betragen (z.B. 0x0400).

.. code-block:: arduino

    char * readCardType(uchar *TagType)

Diese Funktion decodiert die vierstellige Hexadezimalzahl von ``*tagType``
in den spezifischen Kartentyp und gibt einen String zurück. Wenn 0x0400 übergeben wird,
wird „MFOne-S50“ zurückgegeben.

.. code-block:: arduino

    uchar anticoll(uchar *serNum);

Konfliktvermeidung und Lesen der Karten-Seriennummer. Die Funktion gibt
den aktuellen Lesestatus des RFID zurück. Sie gibt MI_OK zurück, wenn
erfolgreich.

* ``*serNum``: Wird verwendet, um die Karten-Seriennummer zu speichern, und gibt die 4-Byte-Karten-Seriennummer zurück. Das 5. Byte ist das Recheck-Byte (z.B. meine Magnetkarten-ID ist 5AE4C955).

