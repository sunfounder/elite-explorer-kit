.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _basic_oled:

OLED
==========================

.. https://docs.sunfounder.com/projects/ultimate-sensor-kit/en/latest/components_basic/22-component_oled.html

Überblick
---------------

In dieser Lektion erfahren Sie mehr über OLED-Displays, die den SSD1306-Treiber verwenden. OLED-Displays (Organische Leuchtdioden) werden in verschiedenen elektronischen Geräten wie Smartwatches, Mobiltelefonen und sogar Fernsehern verwendet. Der SSD1306 ist ein Ein-Chip-CMOS-OLED/PLED-Treiber mit Controller für organische/polymerbasierte Leuchtdioden-Dot-Matrix-Grafikdisplaysysteme. Er bietet eine klare und deutliche visuelle Ausgabe durch organische, lichtemittierende Dioden, die bei Durchgang eines elektrischen Stroms leuchten.

Im bereitgestellten Code wird ein OLED-Display über das I2C-Protokoll mit einem Arduino-Board verbunden. Der Code verwendet die Adafruit SSD1306-Bibliothek zur Steuerung des Displays. Das Programm umfasst verschiedene Funktionalitäten wie:

1. Textanzeige: „Hello world!“ wird auf dem Bildschirm angezeigt.
2. Invertierter Text: Der Text „Hello world!“ wird in einem invertierten Farbschema dargestellt.
3. Schriftgröße: Der Text „Hello!“ wird mit einer vergrößerten Schriftgröße angezeigt.
4. Numerische Anzeige: Die Zahlen 123456789 werden angezeigt.
5. ASCII-Zeichen: Eine Reihe von ASCII-Zeichen wird angezeigt.
6. Scrollen: Text wird horizontal über das Display gescrollt.
7. Bitmap-Anzeige: Ein vordefiniertes Bitmap-Bild wird auf dem OLED-Bildschirm angezeigt.

Dieses OLED-Display kann in einer Vielzahl von Anwendungen eingesetzt werden, einschließlich digitaler Uhren, Mini-Spielkonsolen, Informationsanzeigen und so weiter. Es bietet eine großartige Möglichkeit, eine Benutzeroberfläche in kompakten und tragbaren Geräten bereitzustellen.

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
    *   - :ref:`cpn_oled`
        - |link_oled_buy|

Verdrahtung
----------------------

.. image:: img/15-oled_bb.png
    :align: center

Schaltplan
-----------------------

.. image:: img/15_oled_schematic.png
    :align: center
    :width: 70%

Code
---------------

.. note::

    * Sie können die Datei ``15-oled.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\15-oled`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

    .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **„Adafruit SSD1306“** und **„Adafruit GFX“** und installieren Sie diese. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ec580f40-78b4-42c2-af7c-bb5bc05a7c23/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/15_basic_oled.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

   <br/><br/>

Code-Analyse
------------------------

1. **Einbindung der Bibliotheken und Anfangsdefinitionen**:
   Die notwendigen Bibliotheken für die Anbindung an das OLED werden eingebunden. Anschließend werden Definitionen bezüglich der Abmessungen und der I2C-Adresse des OLEDs bereitgestellt.

   - **Adafruit SSD1306**: Diese Bibliothek wurde entwickelt, um die Anbindung des SSD1306 OLED-Displays zu unterstützen. Sie bietet Methoden zur Initialisierung des Displays, Steuerung seiner Einstellungen und Anzeige von Inhalten.
   - **Adafruit GFX-Bibliothek**: Dies ist eine Kerngrafikbibliothek zum Anzeigen von Text, Erzeugen von Farben, Zeichnen von Formen usw. auf verschiedenen Bildschirmen, einschließlich OLEDs.

   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **„Adafruit SSD1306“** und **„Adafruit GFX“** und installieren Sie diese. 

   .. code-block:: arduino
    
      #include <SPI.h>
      #include <Wire.h>
      #include <Adafruit_GFX.h>
      #include <Adafruit_SSD1306.h>

      #define SCREEN_WIDTH 128  // OLED display width, in pixels
      #define SCREEN_HEIGHT 64  // OLED display height, in pixels

      #define OLED_RESET -1
      #define SCREEN_ADDRESS 0x3C

2. **Bitmap-Daten**:
   Bitmap-Daten zur Anzeige eines benutzerdefinierten Symbols auf dem OLED-Bildschirm. Diese Daten repräsentieren ein Bild in einem Format, das das OLED interpretieren kann.

   Sie können dieses Online-Tool namens |link_image2cpp| verwenden, um Ihr Bild in ein Array umzuwandeln. 

   Das Schlüsselwort ``PROGMEM`` zeigt an, dass das Array im Programmspeicher des Arduino-Mikrocontrollers gespeichert ist. Die Speicherung von Daten im Programmspeicher (PROGMEM) anstelle des RAMs kann hilfreich sein, wenn es sich um große Datenmengen handelt, die sonst zu viel Platz im RAM einnehmen würden.

   .. code-block:: arduino

      static const unsigned char PROGMEM sunfounderIcon[] = {...};

3. **Setup-Funktion (Initialisierung und Anzeige)**:
   Die ``setup()``-Funktion initialisiert das OLED und zeigt eine Reihe von Mustern, Texten und Animationen an.

   .. code-block:: arduino

      void setup() {
         ...  // Serial initialization and OLED object initialization
         ...  // Displaying various text, numbers, and animations
      }