.. _basic_ws2812:

WS2812 RGB-LED-Streifen
==========================

Überblick
---------------

In dieser Lektion lernen Sie NeoPixel-LEDs und ihre Steuerung mit der FastLED-Bibliothek auf einem Arduino Uno R4 kennen. NeoPixel-LEDs werden in verschiedenen Anwendungen wie Heimdekoration, tragbaren Geräten und Eventbeleuchtung verwendet. Die FastLED-Bibliothek vereinfacht die Programmierung dieser LEDs. Hier wird eine Kette von 8 NeoPixel-LEDs an einen Arduino angeschlossen, und jede LED in der Reihe leuchtet kurz in blauer Farbe auf, bevor sie sich ausschaltet und zur nächsten LED in der Kette übergeht. Dieses einfache Beispiel kann als Grundlage für komplexere Lichtmuster oder interaktive Beleuchtungsprojekte dienen.

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
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

Verdrahtung
----------------------

.. image:: img/12-ws2812_bb.png
    :align: center

Schaltplan
-----------------------

.. image:: img/12_ws2812_schematic.png
    :align: center
    :width: 80%

Code
---------------

.. note::

    * Sie können die Datei ``12-ws2812.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\12-ws2812`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. note:: 
    Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager und suchen Sie nach **„FastLED“** und installieren Sie diese. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6c9b8c2c-6cea-4ea8-a959-e579ca98f35d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/12_basic_ws2812.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Nachdem der Code erfolgreich hochgeladen wurde, werden Sie sehen, wie jede LED in der Kette von 8 NeoPixel-LEDs nacheinander in blauer Farbe aufleuchtet. Das Programm wird diese Sequenz kontinuierlich durchlaufen, wobei jede LED ausgeschaltet wird, bevor sie zur nächsten übergeht. Mit einer kurzen Verzögerung zwischen jeder LED erscheint der Beleuchtungseffekt wie ein entlang der Kette reisender blauer Punkt.


Code-Analyse
------------------------

1. Bibliothek importieren und Konstanten einrichten

   - Import der ``FastLED``-Bibliothek, um ihre Funktionen zu nutzen.
   - Definition der Anzahl der LEDs und des Datenpins, an den sie angeschlossen sind.
   
   .. code-block:: arduino
   
      #include <FastLED.h>  // Include FastLED library
      #define NUM_LEDS 8    // Number of LEDs in the chain
      #define DATA_PIN 6    // Data pin for LED control

2. LED-Array initialisieren
   
   Erstellen eines Arrays vom Typ ``CRGB``, um die Farbinformationen jeder LED zu speichern.

   .. code-block:: arduino

      CRGB leds[NUM_LEDS];  // Array to hold LED color data

3. LEDs in Setup initialisieren

   Verwendung von ``FastLED.addLeds``, um die LEDs zu initialisieren.

   .. code-block:: arduino

      void setup() {
        FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Initialize LEDs
      }

4. LEDs in Loop steuern
   
   Durch jede LED iterieren, um sie blau zu setzen, anzuzeigen, zu löschen und dann zu verzögern.

   - Das ``leds``-Array dient als Farbpuffer für Ihren LED-Streifen. Jedes Element in diesem Array entspricht einer einzelnen LED auf Ihrem physischen Streifen, und sein Farbwert bestimmt die Farbe, die die LED anzeigen wird. Die Reihenfolge der Elemente im Array entspricht der Reihenfolge der LEDs auf dem Streifen, beginnend mit der ersten LED (die ``leds[0]`` entspricht) bis zur letzten LED. Um die Farbe einer bestimmten LED auf Ihrem Streifen zu ändern, ändern Sie einfach das entsprechende Element im ``leds``-Array. Sie können |fastled_color| verwenden oder Farben mit RGB einstellen (Grün als Beispiel, verwenden Sie ``leds[dot] = CRGB::Green`` oder ``leds[dot] = CRGB(0, 255, 0);``).

   - Die Funktion ``FastLED.show();`` aktualisiert den LED-Streifen mit neuen Farbdaten und macht Änderungen sichtbar. Es ist wie das Drücken des „Veröffentlichen“-Knopfs für Ihren LED-Streifen, nachdem Sie Änderungen und Anpassungen im Code vorgenommen haben.

   .. raw:: html

     <br/>

   .. code-block:: arduino

      void loop() {
        for (int dot = 0; dot < NUM_LEDS; dot++) {
          leds[dot] = CRGB::Blue;   // Set the current LED to blue
          FastLED.show();           // Update LEDs
          leds[dot] = CRGB::Black;  // Clear the current LED
          delay(30);                // Wait for a short period before moving to the next LED
        }
      }