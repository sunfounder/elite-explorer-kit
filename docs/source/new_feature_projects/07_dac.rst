.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _new_dac:

Digital-to-Analog Converter (DAC)
========================================

The Arduino Uno R4 WiFi comes equipped with a built-in DAC (Digital-to-Analog Converter) feature. A DAC is crucial for converting digital signals into their analog counterparts, a functionality that's particularly vital in applications like audio processing, analog signal generation, and other scenarios requiring precise analog output.

The DAC on the Uno R4 WiFi boasts up to 12-bit resolution, delivering true analog output capabilities that outperform those of PWM pins.

.. image:: img/05_dac.png
  :width: 70%

Play Music with DAC
++++++++++++++++++++

**Circuit Diagram**

.. image:: img/05_dac_bb.png
  :width: 100%
  :align: center

**Upload the Code**

Open the ``07-dac.ino`` file located at ``elite-explorer-kit-main\r4_new_feature\07-dac``, or paste the following code into your Arduino IDE.

.. note:: 
    Please place the ``pitches.h`` file in the same directory as the code to ensure proper functioning.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/93e0379e-1d2d-4d9c-a603-42b3335e8e05/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

This project leverages the Arduino and DAC (Digital-to-Analog Converter) to play the iconic Super Mario Bros theme song. It utilizes a library called ``analogWave`` for sine wave generation and another library, ``pitches.h``, for defining note frequencies.

- ``melody[]``: This array contains the notes to be played along with their durations. Notes are represented by predefined pitches (e.g., ``NOTE_E5``), and durations are represented in terms of beats (e.g., 4 signifies a quarter note). You can try composing your own melody by changing the notes and durations in the melody[] array. If you are interested, there is a repository on GitHub (|link_arduino_songs|) that provides Arduino code for playing different songs. Although their approach may be different from this project, you can refer to their notes and durations. (Simply replace the ``melody[]`` in the corresponding track with the code in this project.)

- ``tempo`` : The tempo for this project is set at 200 BPM (Beats Per Minute), which is used to calculate the duration of each note. Modifying this value will change the speed of the song's performance.

- **Sine Wave Generator**: The ``analogWave`` library's ``sine`` function initializes a 10 Hz sine wave generator, which is used for outputting the notes via DAC.

- **Note Duration**: Based on the set tempo and the beat count for each note, the duration for each note is calculated.

- **Play and Pause**: Each note plays for 85% of its calculated duration, followed by a 15% pause to distinguish between notes.

- **Loop**: Upon completing the melody, the code automatically resets and starts playing again.

This is an example that demonstrates how to use Arduino and external hardware (DAC) to generate music. It also shows how to use arrays and loops to simplify the logic of music playback.


**Reference**

- |link_r4_dac|