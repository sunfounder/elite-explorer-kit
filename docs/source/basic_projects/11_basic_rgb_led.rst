.. _basic_rgb_led:

RGB-LED
==========================

Überblick
---------------

In dieser Lektion werden wir PWM nutzen, um eine RGB-LED verschiedene Farben anzeigen zu lassen. Wenn unterschiedliche PWM-Werte an den R-, G- und B-Pins der LED eingestellt werden, ändert sich deren Helligkeit. Wenn die drei verschiedenen Farben gemischt werden, können wir sehen, dass die RGB-LED unterschiedliche Farben aufleuchten lässt.

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
    *   - :ref:`cpn_rgb_led`
        - |link_rgb_led_buy|

PWM
--------

Pulsweitenmodulation oder PWM ist eine Technik, um analoge Ergebnisse mit digitalen Mitteln zu erzielen. Digitale Steuerung wird verwendet, um eine Rechteckwelle zu erzeugen, ein Signal, das zwischen Ein und Aus geschaltet wird. Dieses Ein-Aus-Muster kann Spannungen zwischen voll Ein (5 Volt) und Aus (0 Volt) simulieren, indem der Anteil der Zeit, in der das Signal eingeschaltet ist, im Vergleich zur Zeit, in der das Signal ausgeschaltet ist, verändert wird. Die Dauer der „Eins-Zeit“ wird als Pulsbreite bezeichnet. Um unterschiedliche analoge Werte zu erhalten, ändern oder modulieren Sie diese Breite. Wenn Sie dieses Ein-Aus-Muster schnell genug mit einem Gerät wiederholen, z.B. einer LED, wäre es so: Das Signal ist eine konstante Spannung zwischen 0 und 5V, die die Helligkeit der LED steuert. (Siehe die PWM-Beschreibung auf der offiziellen Website von Arduino).

In der untenstehenden Grafik repräsentieren die grünen Linien einen regelmäßigen Zeitraum. Diese Dauer oder Periode ist das Inverse der PWM-Frequenz. Mit anderen Worten, bei einer PWM-Frequenz von etwa 500Hz würde jede grüne Linie 2 Millisekunden messen.

.. image:: img/11_rgbled_pwm.jpeg
   :align: center
   :width: 60%


Ein Aufruf von analogWrite() erfolgt auf einer Skala von 0 - 255, so dass analogWrite(255) einen 100%igen Tastgrad (immer eingeschaltet) anfordert und analogWrite(127) einen 50%igen Tastgrad (die Hälfte der Zeit eingeschaltet) ist, zum Beispiel. 

Sie werden feststellen, dass je kleiner der PWM-Wert ist, desto geringer wird der Wert sein, nachdem er in Spannung umgewandelt wurde. Dann wird die LED entsprechend dunkler. Daher können wir die Helligkeit der LED steuern, indem wir den PWM-Wert kontrollieren.



Verdrahtung
----------------------

.. image:: img/11-rgb_led_bb.png
    :align: center
    :width: 70%

Schaltplan
-----------------------

.. image:: img/11-rgb_led_schematic.png
    :align: center
    :width: 80%


Code
---------------

.. note::

    * Sie können die Datei ``11-rgb_led.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\11-rgb_led`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/71dc53ac-adc6-4c4d-8d92-1dfffd1d0f7f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/11_basic_rgb_led.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Nachdem der Code erfolgreich hochgeladen wurde, werden Sie beobachten, dass die RGB-LED zunächst in einem kreisförmigen Muster in Rot, Grün und Blau blinkt. Dann wird sie in der Reihenfolge Rot, Orange, Gelb, Grün, Blau, Indigo und Lila blinken.


Code-Analyse
--------------------

**Farbe einstellen**

Hier verwenden wir die Funktion ``color()``, um die Farbe der RGB-LED einzustellen. Im
Code wird sie so eingestellt, dass sie 7 verschiedene Farben blinkt.

Sie können das Malprogramm auf Ihrem Computer verwenden, um den RGB-Wert zu erhalten.

1. Öffnen Sie das Malprogramm auf Ihrem Computer und klicken Sie auf Farben bearbeiten.

   .. image:: img/11_rgbled_color1.png
      :align: center


2. Wählen Sie eine Farbe aus, dann können Sie den RGB-Wert dieser Farbe sehen. Füllen Sie sie im Code aus.
   
   .. note:: 
      Aufgrund von Hardware- und Umweltfaktoren können die Farben auf Computerbildschirmen und RGB-LEDs variieren, auch wenn dieselben RGB-Werte verwendet werden.

   .. image:: img/11_rgbled_color2.png
      :align: center

   .. raw:: html

      <br/>
   
   .. code-block:: arduino
   
       void loop() // run over and over again
   
       {
   
         // Basic colors:
   
         color(255, 0, 0); // turn the RGB LED red
   
         delay(1000); // delay for 1 second
   
         color(0,255, 0); // turn the RGB LED green
   
         delay(1000); // delay for 1 second
   
         color(0, 0, 255); // turn the RGB LED blue
   
         delay(1000); // delay for 1 second
   
         // Example blended colors:
   
         color(255,0,252); // turn the RGB LED red
   
         delay(1000); // delay for 1 second
   
         color(237,109,0); // turn the RGB LED orange
   
         delay(1000); // delay for 1 second
   
         color(255,215,0); // turn the RGB LED yellow
   
         ......
   
   
**color() Funktion**

.. code-block:: arduino

    void color (int red, int green, int blue)
    // the color generating function

    {

      analogWrite(redPin, red);

      analogWrite(greenPin, green);

      analogWrite(bluePin, blue);

    }

Definieren Sie drei unsigned char Variablen, rot, grün und blau. Schreiben Sie deren Werte in ``redPin``, ``greenPin`` und ``bluePin``. Zum Beispiel erzeugt color(128,0,128) das Schreiben von 128 an ``redPin``, 0 an ``greenPin`` und 128 an ``bluePin``. Das Ergebnis ist dann das Blinken der LED in Lila.

**analogWrite()**: Schreibt einen analogen Wert (PWM-Welle) an einen Pin. Es hat nichts mit einem analogen Pin zu tun, sondern ist nur für PWM-Pins gedacht. Sie müssen nicht zuerst die Funktion ``pinMode()`` aufrufen, um den Pin als Ausgang zu setzen, bevor Sie ``analogWrite()`` aufrufen.
