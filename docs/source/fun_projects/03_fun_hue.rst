.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _fun_hue:

HueDial
========================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/03_fun_huedial.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

This example controls the color of an RGB LED based on the position of a rotary knob. 
Different positions of the knob correspond to different HUE values, which are then translated into RGB color values, resulting in a color change for the RGB LED.

**Required Components**

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
    *   - :ref:`cpn_rgb_led`
        - |link_rgb_led_buy|
    *   - :ref:`potentiometer`
        - |link_potentiometer_buy|

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

    * You can open the file ``03_huedial.ino`` under the path of ``elite-explorer-kit-main\fun_project\03_huedial`` directly.
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
