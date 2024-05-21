.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _basic_i2c_lcd1602:

I2C LCD1602
==========================

.. https://docs.sunfounder.com/projects/sensorkit-v2-arduino/en/latest/lesson_1.html

Überblick
---------------

In dieser Lektion erfahren Sie mehr über Flüssigkristallanzeigen (LCDs) mit einer I2C-Schnittstelle. Diese Art von LCDs wird in einer Vielzahl elektronischer Geräte verwendet, wie in Digitaluhren, Mikrowellenöfen, Armaturenbrettern in Autos und sogar in industriellen Geräten. Die I2C-Schnittstelle vereinfacht die Verkabelung und die Verbindungen, was sie sowohl für Hobbyisten als auch für Profis bequemer und effizienter macht.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

Verdrahtung
----------------------

.. image:: img/14-i2c_lcd_bb.png
    :align: center
    :width: 100%

Schaltplan
-----------------------

.. image:: img/14-i2c_lcd_schematic.png
    :align: center
    :width: 80%

Code
---------------

.. note::

    * Sie können die Datei ``14-i2c_lcd.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\14-i2c_lcd`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. note:: 
    Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **„LiquidCrystal I2C“** und installieren Sie diese. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/096326ad-eccf-4d2e-be52-66f4819ca7d8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/14_basic_i2c_lcd.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Nachdem der Code erfolgreich auf den Arduino hochgeladen wurde, zeigt das Liquid Crystal Display (LCD) die Nachricht „Hello world!“ in der ersten Zeile und „LCD Tutorial“ in der zweiten Zeile an.

.. note::
    Wenn das LCD nach dem Hochladen des Codes keine Zeichen anzeigt, können Sie den Kontrast einstellen, indem Sie das Potentiometer am I2C-Modul drehen, bis das LCD korrekt funktioniert.

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/14_basic_i2c_lcd_2.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

   <br/><br/>

Code-Analyse
------------------------

1. Bibliothekseinbindung und LCD-Initialisierung:
   Die LiquidCrystal I2C-Bibliothek wird eingebunden, um Funktionen und Methoden für die LCD-Schnittstelle bereitzustellen. Danach wird ein LCD-Objekt mit der Klasse LiquidCrystal_I2C erstellt, wobei die I2C-Adresse, die Anzahl der Spalten und die Anzahl der Zeilen angegeben werden.

   .. note:: 
      Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **„LiquidCrystal I2C“** und installieren Sie diese.  

   .. code-block:: arduino

      #include <LiquidCrystal_I2C.h>
      LiquidCrystal_I2C lcd(0x27, 16, 2);

2. Setup-Funktion:
   Die ``setup()``-Funktion wird einmal ausgeführt, wenn der Arduino startet. In dieser Funktion wird das LCD initialisiert, gelöscht und die Hintergrundbeleuchtung eingeschaltet. Anschließend werden zwei Nachrichten auf dem LCD angezeigt.

   .. code-block:: arduino

      void setup() {
        lcd.init();       // initialize the LCD
        lcd.clear();      // clear the LCD display
        lcd.backlight();  // Make sure backlight is on
      
        // Print a message on both lines of the LCD.
        lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
        lcd.print("Hello world!");
      
        lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
        lcd.print("LCD Tutorial");
      }