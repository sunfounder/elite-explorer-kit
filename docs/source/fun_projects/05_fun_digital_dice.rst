.. _fun_digital_dice:

Digital Dice
=======================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/05_fun_dice.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

This code is designed to simulate a rolling dice using a 74HC595 shift register and a 7-segment digital display. The dice roll simulation is activated by directly shaking the tilt switch. Upon this action, the digital display cycles through random numbers between 1 and 6, simulating the rolling of a dice. After a brief interval, the display stops, showing a random number that signifies the outcome of the dice roll.

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
    *   - :ref:`cpn_tilt_switch`
        - \-
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7segment`
        - |link_7segment_buy|

**Wiring**

.. image:: img/05_dice_bb.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>

**Schematic**

.. image:: img/05_digital_dice_schematic.png
   :width: 100%

**Code**

.. note::

    * You can open the file ``05_digital_dice.ino`` under the path of ``elite-explorer-kit-main\fun_project\05_digital_dice`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/ff0528b0-a10d-49e8-8916-6cb1fdfdf9a2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**How it works?**

Here's a detailed explanation of the code:

1. Initialization of variables:

   ``dataPin``, ``clockPin``, ``latchPin``: Pins for the 74HC595.
   ``buttonPin``: The digital pin where the button is connected.
   ``numbers[]``: An array to store the encoding representing numbers 1 through 6 on a common anode digital tube.

2. Volatile variables:

   rolling: This is a volatile variable indicating whether the dice is currently rolling. 
   It's declared as volatile since it's accessed both in the interrupt service routine and the main program.

3. ``setup()``:

   Set the modes for the relevant pins.
   Set the input mode for the button using the internal pull-up resistor.
   Assign an interrupt to the button, which calls the rollDice function when the button's state changes.

4. ``loop()``:

   It checks if rolling is true. If it is, it continues to display a random number between 1 and 6. If the button has been pressed for more than 500 milliseconds, the rolling stops.

5. ``rollDice()``:

   This is the interrupt service routine for the button. It checks if the button is pressed (low level). If it is, the current time is recorded and the rolling begins.

6. ``displayNumber()``:

   This function displays a number on the digital tube. It sends the number to the digital tube through the 74HC595 shift register.
