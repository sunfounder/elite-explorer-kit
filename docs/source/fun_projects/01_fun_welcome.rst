.. _fun_welcome:

Welcome
========================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/01_fun_welcome.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

In this project, we will use a PIR sensor to detect human presence and a speaker to simulate a doorbell, similar to the entrance doorbells in convenience stores.
When a pedestrian appears within the range of the PIR sensor, the speaker will ring, mimicking a doorbell.

**Required Components**

* :ref:`uno_r4_wifi`
* :ref:`cpn_wires`
* :ref:`cpn_breadboard`
* :ref:`cpn_pir`
* :ref:`cpn_audio_speaker`

**Wiring**

.. image:: img/01_welcome_bb.png
    :width: 90%
    :align: center

.. raw:: html

   <br/>

**Schematic**

.. image:: img/01_welcome_schematic.png
   :width: 100%

**Code**

.. note::

    * You can open the file ``01_welcome.ino`` under the path of ``elite-explorer-kit-main\fun_project\01_welcome`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/b9791d5d-169d-4603-9fc3-8081138811fa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



**How it works?**

Here is a step-by-step explanation of the code:

1. Include Header Files:

   Include two header files, ``analogWave.h`` and ``pitches.h``. The ``analogWave.h`` file contains the definition of the ``analogWave`` class, while ``pitches.h`` contains the definitions of musical notes.

2. Instantiate Objects and Define Constants:

   Create a ``wave`` object using the ``analogWave`` class and define ``PIR_PIN`` as 2, which is the pin connected to the PIR sensor.

3. Melody Array:

   The ``melody`` array defines a musical melody, with each note followed by a number representing its duration. 
   Negative numbers represent dotted notes (increasing the duration by 50%).

4. Global Variables:

   Define some global variables for sharing data between functions.

5. ``setup()``:

   Initialize ``PIR_PIN`` as an input and set the frequency of the sine wave to 10 Hz using ``wave.sine(10)``.

6. ``loop()``:

   Continuously monitor the value of the PIR sensor.
   If human presence is detected (pirValue is HIGH), call the ``playMelody()`` function to play the melody and wait for 10 seconds to prevent repetitive playback of the melody.

7. ``playMelody()``:

   This function calculates the duration of each note based on the data in the ``melody`` array and plays the corresponding note. There is a brief pause between notes.
   The function sets the frequency of the waveform using ``wave.freq()`` and controls the duration of the notes and pauses between notes using the ``delay()`` function.

   Note: Ensure that the ``pitches.h`` header file indeed exists before running this code.
