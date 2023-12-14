.. _fun_digital_dice:

Digitaler Würfel
=======================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/05_fun_dice.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Dieser Code ist darauf ausgelegt, einen rollenden Würfel mit einem 74HC595-Schieberegister und einer 7-Segment-Digitalanzeige zu simulieren. Die Würfelwurfsimulation wird durch direktes Schütteln des Neigungsschalters aktiviert. Bei dieser Aktion durchläuft die digitale Anzeige zufällige Zahlen zwischen 1 und 6, was das Rollen eines Würfels simuliert. Nach einer kurzen Pause stoppt die Anzeige und zeigt eine zufällige Zahl an, die das Ergebnis des Würfelwurfs darstellt.

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

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_tilt_switch`
        - \-
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7segment`
        - |link_7segment_buy|

**Verkabelung**

.. image:: img/05_dice_bb.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>

**Schaltplan**

.. image:: img/05_digital_dice_schematic.png
   :width: 100%

**Code**

.. note::

    * Sie können die Datei ``05_digital_dice.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\fun_project\05_digital_dice`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/ff0528b0-a10d-49e8-8916-6cb1fdfdf9a2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Wie funktioniert das?**

Hier ist eine detaillierte Erklärung des Codes:

1. Initialisierung von Variablen:

   ``dataPin``, ``clockPin``, ``latchPin``: Pins für den 74HC595.
   ``buttonPin``: Der digitale Pin, an den der Knopf angeschlossen ist.
   ``numbers[]``: Ein Array, um die Kodierung zu speichern, die Zahlen 1 bis 6 auf einer gemeinsamen Anoden-Digitalröhre darstellt.

2. Flüchtige Variablen:

   rolling: Dies ist eine flüchtige Variable, die angibt, ob der Würfel gerade rollt. 
   Sie wird als flüchtig deklariert, da sie sowohl in der Interrupt-Service-Routine als auch im Hauptprogramm verwendet wird.

3. ``setup()``:

   Setzen Sie die Modi für die relevanten Pins.
   Stellen Sie den Eingangsmodus für den Knopf unter Verwendung des internen Pull-Up-Widerstands ein.
   Weisen Sie dem Knopf einen Interrupt zu, der die Funktion rollDice aufruft, wenn sich der Zustand des Knopfes ändert.

4. ``loop()``:

   Es wird überprüft, ob rolling wahr ist. Wenn ja, wird weiterhin eine zufällige Zahl zwischen 1 und 6 angezeigt. Wenn der Knopf länger als 500 Millisekunden gedrückt wurde, stoppt das Rollen.

5. ``rollDice()``:

   Dies ist die Interrupt-Service-Routine für den Knopf. Es wird überprüft, ob der Knopf gedrückt ist (niedriges Niveau). Wenn ja, wird die aktuelle Zeit aufgezeichnet und das Rollen beginnt.

6. ``displayNumber()``:

   Diese Funktion zeigt eine Zahl auf der Digitalröhre an. Sie sendet die Zahl über den 74HC595-Schieberegister an die Digitalröhre.

