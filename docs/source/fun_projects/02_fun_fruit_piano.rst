.. _fun_fruit_piano:

Fruit Piano
========================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/02_fun_fruit_piano.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

This project is a simple fruit piano that reads input from an MPR121 touch sensor and plays music through a DAC. In other words, we've turned fruits into a keyboard, allowing you to play music by simply touching them.

**Required Components**

* :ref:`uno_r4_wifi`
* :ref:`cpn_wires`
* :ref:`cpn_breadboard`
* :ref:`cpn_mpr121`
* :ref:`cpn_audio_speaker`

**Wiring**

.. image:: img/02_fruit_piano_bb.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>


**Schematic**

.. image:: img/02_fruit_piano_schematic.png
   :width: 100%

**Code**

.. note::

    * You can open the file ``02_fruit_piano.ino`` under the path of ``Elite-Explorer-Kit-main\fun_project\02_fruit_piano`` directly.
    * Or copy this code into Arduino IDE.

.. note::
   To install the library, use the Arduino Library Manager and search for **“Adafruit MPR121”** and install it.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/e677c06a-7af1-4846-a507-dd69c0c50aae/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**How it works?**

Here's a step-by-step explanation of the code:

1. Library and Object Initialization:

   Import the necessary libraries: ``Wire`` library (for I2C communication), ``Adafruit_MPR121`` library (for driving the MPR121), ``analogWave`` library (for generating analog waveforms), and ``pitches.h`` (which defines the frequencies of notes).
   Create instances of ``Adafruit_MPR121`` and ``analogWave`` objects.
   Define a notes array to store the note corresponding to each touch channel.

2. ``setup()``:

   Initialize Serial communication and wait for it to start.
   Check and initialize the MPR121; if not found, print an error message on the serial monitor and halt execution.
   Initialize the ``analogWave`` object and set the initial sine wave frequency to 10Hz.

3. ``loop()``:

   Read the currently touched channels of the MPR121.
   Iterate through all channels, check which one is touched, and play the corresponding note.
   Add a small delay between each iteration.

4. Play Note ``playNote()``:

   The ``playNote`` function takes a ``note`` parameter and sets the DAC frequency to play the corresponding note.
   Delay for a period to play the note.
   Stop playing the note.
