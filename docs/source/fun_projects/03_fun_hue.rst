.. _fun_hue:

HueDial
========================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/03_fun_huedial.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Dieses Beispiel steuert die Farbe einer RGB-LED basierend auf der Position eines Drehknopfs.
Verschiedene Positionen des Knopfs entsprechen verschiedenen HUE-Werten, die dann in RGB-Farbwerte übersetzt werden, was zu einer Farbänderung der RGB-LED führt.

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
    *   - :ref:`cpn_rgb_led`
        - |link_rgb_led_buy|
    *   - :ref:`potentiometer`
        - |link_potentiometer_buy|

**Verdrahtung**

.. image:: img/03_hue_dial_bb.png
    :width: 70%
    :align: center

.. raw:: html

   <br/>

**Schaltplan**

.. image:: img/03_hue_schematic.png
   :width: 80%
   :align: center


**Code**

.. note::

    * Sie können die Datei ``03_huedial.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\fun_project\03_huedial`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/0ad800d4-77bb-454f-8976-a078da71ec35/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Wie funktioniert das?**

Hier ist eine detaillierte Erklärung des Codes:

1. Globale Variablendefinitionen:

   ``redPin``, ``greenPin`` und ``bluePin``: Diese definieren die PWM-Pins, die jeweils mit den roten, grünen und blauen LEDs verbunden sind.
   ``KNOB_PIN``: Definiert den analogen Eingangspin, der mit dem Drehknopf verbunden ist.

2. ``setup()``:

   Stellen Sie die Pins für die RGB-LED als Ausgang ein.
   Standardmäßig sind analoge Pins als Eingänge gesetzt, daher ist es nicht notwendig, den Eingangsmodus für den Pin des Knopfes einzustellen.

3. ``loop()``:

   Lesen Sie den Wert des Drehknopfs. Dieser Wert reicht von 0 bis 1023.
   Normalisieren Sie den Wert des Knopfs auf einen Bereich von 0-1.
   Konvertieren Sie den normalisierten Wert in einen HUE-Wert im Bereich von 0-360.
   Konvertieren Sie den HUE-Wert in RGB-Werte.
   Aktualisieren Sie die Farbe der LED mit diesen RGB-Werten.

4. ``setColor()``:

   Setzen Sie die passenden PWM-Werte für jeden LED-Pin mit der Funktion ``analogWrite()``, um die Farbe der RGB-LED einzustellen.

5. ``HUEtoRGB()``:

   Diese Funktion konvertiert HUE-Werte in RGB-Werte mit der HSL-zu-RGB-Konvertierungsmethode, konzentriert sich jedoch nur auf die HUE-Komponente und hält Sättigung und Helligkeit bei 100%.
   Der Algorithmus ist in 6 Stufen unterteilt, wobei jede 60 Grad abdeckt.
   Es berechnet RGB-Werte für jede HUE-Stufe und skaliert dann diese Werte auf einen Bereich von 0-255, was der erwarteten Spanne für die Funktion ``analogWrite()`` entspricht.

