.. _basic_audio_speaker:

Audio-Modul und Lautsprecher
==================================

Überblick
---------------

In dieser Lektion lernen Sie das Audio-Modul und den Lautsprecher in Verbindung mit einem Arduino Uno-Board kennen. Diese Komponenten werden in verschiedenen elektronischen Anwendungen eingesetzt, darunter in musikalischen Spielzeugen, DIY-Soundsystemen, Alarmen und sogar in anspruchsvollen Musikinstrumenten. Durch die Kombination eines Arduino mit einem Audio-Modul und einem Lautsprecher können Sie einen einfachen, aber effektiven Melodiespieler erstellen.

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
    *   - :ref:`cpn_audio_speaker`
        - \-


Verdrahtung
----------------------

Da es sich um einen Mono-Verstärker handelt, können Sie Pin 8 an den L- oder R-Pin des Audioverstärkermoduls anschließen.

Der 10K-Widerstand wird verwendet, um hochfrequentes Rauschen zu reduzieren und die Lautstärke zu verringern. Er bildet zusammen mit der parasitären Kapazität des DAC und des Audioverstärkers einen RC-Tiefpassfilter. Dieser Filter verringert die Amplitude von hochfrequenten Signalen und reduziert so effektiv hochfrequentes Rauschen. Daher macht das Hinzufügen des 10K-Widerstands die Musik leiser und eliminiert unerwünschtes hochfrequentes Rauschen.

.. image:: img/17-audio_bb.png
    :align: center
    :width: 100%

Schaltplan
-----------------------

.. image:: img/17-audio_schematic.png
    :align: center
    :width: 80%


Code
---------------

.. note::

    * Sie können die Datei ``17-speaker.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\17-speaker`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/33b690b5-0be6-434d-83d7-5bfcfce3775e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Sobald Sie die Codes auf das R4-Board hochgeladen haben, können Sie eine Melodie hören, die sieben Noten enthält.

Code-Analyse
------------------------

1. Einbindung der Tonhöhen-Bibliothek:
   Diese Bibliothek liefert die Frequenzwerte für verschiedene musikalische Noten und ermöglicht es Ihnen, musikalische Notation in Ihrem Code zu verwenden.

   .. note::
      Bitte platzieren Sie die Datei ``pitches.h`` im selben Verzeichnis wie den Code, um eine ordnungsgemäße Funktion zu gewährleisten. |link_pitches|

      .. image:: img/16_passive_buzzer_piches.png

   .. code-block:: arduino
       
      #include "pitches.h"

2. Definition von Konstanten und Arrays:

   * ``speakerPin`` ist der digitale Pin am Arduino, an den der Lautsprecher angeschlossen ist.

   * ``melody[]`` ist ein Array, das die Reihenfolge der zu spielenden Noten speichert.

   * ``noteDurations[]`` ist ein Array, das die Dauer jeder Note in der Melodie speichert.

   .. code-block:: arduino
   
      const int speakerPin = 8;
      int melody[] = {
        NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
      };
      int noteDurations[] = {
        4, 8, 8, 4, 4, 4, 4, 4
      };

3. Abspielen der Melodie:

   * Die ``for``-Schleife iteriert über jede Note in der Melodie.

   * Die Funktion ``tone()`` spielt eine Note auf dem Lautsprecher für eine bestimmte Dauer.

   * Zwischen den Noten wird eine Pause hinzugefügt, um sie zu unterscheiden.

   * Die Funktion ``noTone()`` stoppt den Ton.



   .. code-block:: arduino
   
      void setup() {
        for (int thisNote = 0; thisNote < 8; thisNote++) {
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(speakerPin, melody[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(speakerPin);
        }
      }

4. Leere Loop-Funktion:
   Da die Melodie nur einmal im Setup gespielt wird, gibt es keinen Code in der Loop-Funktion.

5. Experimentieren Sie frei mit der Änderung der Noten und Dauern in den Arrays ``melody[]`` und ``noteDurations[]``, um Ihre eigenen Melodien zu kreieren. Wenn Sie interessiert sind, gibt es ein GitHub-Repository (|link_arduino-songs|), das Arduino-Codes für das Spielen verschiedener Lieder bietet. Obwohl ihr Ansatz sich von diesem Projekt unterscheidet, können Sie deren Noten und Dauern als Referenz heranziehen.
