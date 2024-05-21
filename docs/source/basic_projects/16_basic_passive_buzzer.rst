.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _basic_passive_buzzer:

Passive Buzzer
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_tone_notone.html#ar-passive-buzzer


Overview
---------------

In this project, use these two functions to make the passive buzzer vibrate and produce sound. The function ``tone()`` generates a square wave with a specified frequency (and 50% duty cycle) on a pin. A duration can be specified, or the wave continues until ``noTone()`` is called.
Similar to the active buzzer, the passive buzzer also utilizes electromagnetic induction to operate.
The difference is that a passive buzzer does not have its own oscillating source, so it will not emit sound if DC signals are used.However, this allows the passive buzzer to adjust its own oscillation frequency and produce different notes such as "do, re, mi, fa, sol, la, ti".

Required Components
-------------------------

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|


Wiring
----------------------

.. note::
    When connecting the buzzer, make sure to check its pins. The longer pin is the anode and the shorter one is the cathode. It's important not to mix them up, as doing so will prevent the buzzer from producing any sound.

.. image:: img/16-passive_buzzer_bb.png
    :align: center
    :width: 70%

Schematic Diagram
-----------------------

.. image:: img/16_passive_buzzer_schematic.png
    :align: center
    :width: 80%

Code
---------------

.. note::

    * You can open the file ``16-passive_buzzer.ino`` under the path of ``elite-explorer-kit-main\basic_project\16-passive_buzzer`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7936cad2-3605-40a0-a9fc-573f934ab6b1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
At the time when you finish uploading the codes to the R4 board, you can hear a melody containing seven notes. 

Code Analysis
------------------------

1. Including the pitches library:
   This library provides the frequency values for various musical notes, allowing you to use musical notation in your code.

   .. note::
      Please place the ``pitches.h`` file in the same directory as the code to ensure proper functioning. |link_pitches|

      .. image:: img/16_passive_buzzer_piches.png

   .. code-block:: arduino
       
      #include "pitches.h"

2. Defining constants and arrays:

   * ``buzzerPin`` is the digital pin on the Arduino where the buzzer is connected.

   * ``melody[]`` is an array that stores the sequence of notes to be played.

   * ``noteDurations[]`` is an array that stores the duration of each note in the melody.

   .. code-block:: arduino
   
      const int buzzerPin = 8;
      int melody[] = {
        NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
      };
      int noteDurations[] = {
        4, 8, 8, 4, 4, 4, 4, 4
      };

3. Playing the melody:

   * The ``for`` loop iterates over each note in the melody.

   * The ``tone()`` function plays a note on the buzzer for a specific duration.

   * A delay is added between notes to distinguish them.

   * The ``noTone()`` function stops the sound.



   .. code-block:: arduino
   
      void setup() {
        for (int thisNote = 0; thisNote < 8; thisNote++) {
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(buzzerPin, melody[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(buzzerPin);
        }
      }

4. Empty loop function:
   Since the melody is played only once in the setup, there's no code in the loop function.

5. Feel free to experiment with altering the notes and durations in the ``melody[]`` and ``noteDurations[]`` arrays to create your own melodies. If you're interested, there is a GitHub repository (|link_arduino-songs|) that offers Arduino code for playing various songs. While their approach may differ from this project, you can consult their notes and durations for reference.