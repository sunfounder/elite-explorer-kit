.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _new_led_matrix:

12x8 LED-Matrix
========================================

Das Arduino UNO R4 WiFi ist mit einer integrierten 12x8 LED-Matrix ausgestattet, die so programmiert werden kann, dass sie eine Vielzahl von Grafiken, Animationen darstellt, als Schnittstelle dient oder sogar Spielerlebnisse ermöglicht.

.. image:: img/unor4wifi.webp
    :width: 60%

In diesem Leitfaden bieten wir ein einfaches Beispiel, um Ihnen zu helfen, Ihr gewünschtes Muster auf der LED-Matrix anzuzeigen.

Speicherung von LED-Matrix-Daten in Arduino
-----------------------------------------------

Um die LED-Matrix zu nutzen, benötigen Sie die Bibliothek ``Arduino_LED_Matrix``, die zusammen mit dem Renesas-Kern installiert wird.

Die LED-Matrix-Bibliothek für das UNO R4 WiFi funktioniert, indem sie Frames in einen Puffer erstellt und lädt, um sie anzuzeigen. Ein Frame, auch bekannt als „Bild“, stellt dar, was aktuell auf der Matrix angezeigt wird. In einer Animation, die aus mehreren Bildern besteht, wird jedes Bild als Frame betrachtet.

Um die 12x8 LED-Matrix auf dem UNO R4 WiFi zu steuern, werden mindestens 96 Bit Speicherplatz benötigt. Die Bibliothek bietet dafür zwei Ansätze.

**Ein Ansatz verwendet ein zweidimensionales Array**, mit Nullen und Einsen, um darzustellen, ob die entsprechende LED aus oder an ist. Jede Zahl entspricht einer LED auf der LED-Matrix. Das folgende Array veranschaulicht ein herzförmiges Muster.

.. code-block:: arduino
   
   // Use a two-dimensional array to represent a 12x8 LED matrix.
   byte frame[8][12] = {
     { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
     { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
     { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
     { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
     { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
   };

**Ein anderer Ansatz verwendet ein Array aus 32-Bit-Ganzzahlen**, um den Status der LED-Matrix zu verwalten. Diese Methode ist kompakter, aber etwas komplexer. Jedes ``unsigned long`` speichert 32 Bit. Daher benötigen Sie für eine 12x8 LED-Matrix, die 96 LEDs enthält, mindestens drei ``unsigned long`` Variablen.

1. Jedes ``unsigned long`` enthält 32 Bits, und Sie können diese Bits als den Zustand eines bestimmten Teils in einer LED-Matrix betrachten.
2. Diese ``unsigned long`` Variablen bilden ein Array, das den gesamten Zustand der LED-Matrix umfasst.

Hier ist ein Code-Snippet, das drei ``unsigned long`` Variablen verwendet, um eine 12x8 LED-Matrix darzustellen.

.. code-block:: arduino

   // Use an array of 32-bit integers to store the LED matrix.
   unsigned long frame[] = {
     0x3184a444, // State of the first 32 LEDs
     0x42081100, // State of the next 32 LEDs
     0xa0040000  // State of the last 32 LEDs
   };

Um die LED-Zustände besser zu visualisieren, können diese Werte in eine Binärform umgewandelt werden, wobei jedes Bit sequenziell den Zustand jeder LED von links nach rechts und von oben nach unten darstellt. Eine 0 zeigt an, dass sie aus ist, und eine 1, dass sie an ist.

.. code-block:: arduino

   0x3184a444 -> 110001100001001010010001000100
   0x42081100 -> 1000010000010000001000100000000
   0xa0040000 -> 10100000000001000000000000000000

Anzeigemuster auf der LED-Matrix
-----------------------------------------

Sobald Ihr Muster fertig ist, besteht der nächste Schritt darin, diese Daten auf die 12x8 LED-Matrix zu übertragen. Dies beinhaltet normalerweise das Aufrufen von Bibliotheksfunktionen und das Übergeben des Arrays oder der Variablen, die die LED-Zustände enthalten, an diese Funktionen.

1. Verwendung eines zweidimensionalen Arrays

   Um das Muster, das in einem 2D-Array gespeichert ist, anzuzeigen, können Sie den folgenden Code verwenden:
   
   .. code-block:: arduino
   
      #include <Arduino_LED_Matrix.h>
   
      ArduinoLEDMatrix matrix;
   
      // Pre-defined 2D array
      byte frame[8][12] = {
           { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
           { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
           { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
           { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
           { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
      };
   
      void setup() {
        // Initialize LED matrix
        matrix.begin();
      }
   
      void loop() {
        // Display pattern on the LED matrix
        matrix.renderBitmap(frame, 8, 12);
        delay(1000);
      }
   
   In diesem Code verwenden wir die Funktion ``matrix.renderBitmap(frame, 8, 12);``, um die LED-Matrix anzuzeigen. Hierbei stehen 8 und 12 jeweils für die Zeilen und Spalten der LED-Matrix.

2. Verwendung eines Arrays aus 32-Bit-Ganzzahlen
   
   Um das in einem Array von ``unsigned long`` gespeicherte Muster anzuzeigen, verwenden Sie den folgenden Code:
   
   .. code-block:: arduino
   
      #include "Arduino_LED_Matrix.h"
      
      ArduinoLEDMatrix matrix;
      
      void setup() {
        matrix.begin();
      }
      
      const uint32_t heart[] = {
          0x3184a444,
          0x44042081,
          0x100a0040
      };
        
      void loop(){
        matrix.loadFrame(heart);
        delay(500);
      }
   
   In diesem Fall müssen wir die Funktion ``matrix.loadFrame(heart)`` verwenden, um das Muster auf der LED-Matrix anzuzeigen.


Arduino LED-Matrix-Editor
-----------------------------------------

Ich empfehle, ein Array aus ``unsigned long`` zu verwenden, um den Zustand der LED-Matrix zu speichern, da es Speicherplatz auf dem Arduino spart. Obwohl diese Methode vielleicht nicht sehr intuitiv ist, können Sie den |link_led_matrix_editor| als Hilfsmittel verwenden, der Ihnen hilft, ein Array aus ``unsigned long`` zu generieren.

Mit dem |link_led_matrix_editor| und der Bibliothek ``Arduino_LED_Matrix`` können Sie bequem Symbole oder Animationen erstellen und auf dem UNO R4 WiFi-Board anzeigen. Alles, was Sie tun müssen, ist zu zeichnen, die ``.h``-Datei herunterzuladen und die Funktion ``matrix.play()`` in Ihrem Sketch aufzurufen, um Ihr nächstes Projekt einfach zu realisieren.


#. Öffnen Sie den LED-Matrix-Editor

   .. image:: img/04_led_matrix_editor_1.png
     :width: 80%

#. Zeichnen Sie Ihr Muster auf die zentrale Leinwand

   .. image:: img/04_led_matrix_editor_2.png
     :width: 80%

#. Stellen Sie das Frame-Intervall in Millisekunden ein

   .. image:: img/04_led_matrix_editor_3.png
     :width: 80%

#. Sie können einen neuen leeren Frame erstellen oder einen neuen Frame aus dem aktuellen Frame kopieren und erstellen.

   .. image:: img/04_led_matrix_editor_4.png
     :width: 80%

#. Exportieren Sie die ``.h``-Headerdatei

   .. image:: img/04_led_matrix_editor_5.png
     :width: 80%

   .. image:: img/04_led_matrix_editor_6.png

   Nachdem Sie auf OK geklickt haben, erhalten Sie eine Datei mit dem Namen ``animation.h``.


Animationen Anzeigen
-----------------------------------------

In den vorherigen Schritten haben wir eine ``.h``-Datei erhalten, die eine Reihe von Frames zusammen mit ihren Dauern speichert. Als Nächstes lassen Sie uns diese auf der LED-Matrix anzeigen.

#. Erstellen Sie zuerst einen Sketch. Sie können entweder die Datei ``04-led_matrix.ino`` öffnen, die sich unter dem Pfad ``elite-explorer-kit-main\r4_new_feature\04-led_matrix`` befindet, oder diesen Code in die **Arduino IDE** kopieren.

   .. raw:: html

      <iframe src=https://create.arduino.cc/editor/sunfounder01/f3712371-7c3d-4a4b-bd98-f74fe43269ed/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Wenn Sie den Code vom Pfad ``elite-explorer-kit-main\r4_new_feature\04-led_matrix`` verwenden, finden Sie in der Arduino IDE einen Tab namens ``animation.h``. Öffnen Sie diesen und ersetzen Sie den vorhandenen Code durch die .h-Datei, die Sie von der Webseite erhalten haben.

   .. image:: img/04_animation_h_file.png
     :width: 80%

#. Wenn Sie Ihren eigenen Sketch erstellt haben, müssen Sie die von der Webseite erhaltene ``.h``-Datei in dasselbe Verzeichnis Ihres Sketches kopieren.

#. Nachdem Sie Ihren bevorzugten Code in der Arduino IDE eingerichtet und auf Ihr Arduino UNO R4 WiFi hochgeladen haben, sollte Ihre LED-Matrix nun das von Ihnen definierte Muster anzeigen.

   .. raw:: html
   
      <video loop autoplay muted style = "max-width:100%">
         <source src="../_static/videos/new_feature_projects/led_matrix.mp4"  type="video/mp4">
         Ihr Browser unterstützt das Video-Tag nicht.
      </video>

   Herzlichen Glückwunsch! Sie haben erfolgreich die 12x8 LED-Matrix Ihres Arduino UNO R4 WiFi programmiert!


**Referenz**

- |link_r4_led|

**Weitere Projekte**

* :ref:`fun_snake` (Spaßprojekt)
