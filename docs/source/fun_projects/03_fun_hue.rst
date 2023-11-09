.. _fun_hue:

HueDial
========================================

This example controls the color of an RGB LED based on the position of a rotary knob. 
Different positions of the knob correspond to different HUE values, which are then translated into RGB color values, resulting in a color change for the RGB LED.

**Required Components**

* :ref:`uno_r4_wifi`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_breadboard`
* :ref:`cpn_rgb_led`
* :ref:`potentiometer`

**Wiring**

.. image:: img/03_hue_dial_bb.png
    :width: 70%
    :align: center

.. raw:: html

   <br/>

**Schematic**

.. image:: img/03_hue_schematic.png
   :width: 80%
   :align: center


**Code**

.. note::

    * You can open the file ``03_huedial.ino`` under the path of ``Elite-Explorer-Kit-main\fun_project\03_huedial`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/0ad800d4-77bb-454f-8976-a078da71ec35/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**How it works?**

Here's a detailed explanation of the code:

1. Global Variable Definitions:

   ``redPin``, ``greenPin``, and ``bluePin``: These define the PWM pins connected to the red, green, and blue LEDs, respectively.
   ``KNOB_PIN``: Defines the analog input pin connected to the rotary knob.

2. ``setup()``:

   Set the pins for the RGB LED as output.
   By default, analog pins are set as inputs, so there's no need to set the input mode for the knob's pin.

3. ``loop()``:

   Read the value of the rotary knob. This value ranges from 0 to 1023.
   Normalize the knob's value to a range of 0-1.
   Convert the normalized value to a HUE value ranging from 0-360.
   Convert the HUE value to RGB values.
   Update the LED's color using these RGB values.

4. ``setColor()``:

   Set the appropriate PWM values for each LED pin using the ``analogWrite()`` function to set the color of the RGB LED.

5. ``HUEtoRGB()``:

   This function converts HUE values to RGB values using the HSL to RGB conversion method but focuses only on the HUE component, keeping saturation and brightness at 100%.
   The algorithm is divided into 6 stages, each covering 60 degrees.
   It calculates RGB values for each HUE stage and then scales these values to a range of 0-255, which is the expected range for the ``analogWrite()`` function.
