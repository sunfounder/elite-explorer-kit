.. _fun_guess_number:

GAME - Guess Number
============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/10_fun_guess_game.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Guessing Numbers is an entertaining party game where you and your friends take turns entering a number (0~99). 
The range becomes narrower with each number input until a player correctly guesses the answer. 
The player who guesses correctly is declared the loser and subjected to a penalty. 
For instance, if the secret number is 51, which the players cannot see, and player 1 inputs 50, 
the number range prompt changes to 50~99. If player 2 inputs 70, the number range becomes 50~70. 
If player 3 inputs 51, they are the unlucky one. 
In this game, we use an IR Remote Controller to input numbers and an LCD to display outcomes.

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_ir_receiver`
        - |link_receiver_buy|



**Wiring**

.. image:: img/10_guess_number_bb.png
    :width: 90%
    :align: center


**Schematic**

.. image:: img/10_guess_number_schematic.png
   :width: 100%
   :align: center

**Code**

.. note::

    * You can open the file ``10_guess_number.ino`` under the path of ``elite-explorer-kit-main\fun_project\10_guess_number`` directly.
    * Or copy this code into Arduino IDE.

.. note::
   To install the library, use the Arduino Library Manager and search for **"IRremote"** and **"LiquidCrystal I2C"** and install them.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/935cd2e8-23e1-4af8-bdf5-94ac00f10e8b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



**How it works?**

1. Library Imports and Global Variable Definitions:

   Three libraries are imported: ``Wire`` for I2C communication, ``LiquidCrystal_I2C`` for controlling the LCD display, and ``IRremote`` for receiving signals from the infrared remote controller.
   Several global variables are defined to store the game's state and settings.

2. ``setup()`` 

   Initialize the LCD display and turn on the backlight.
   Initialize serial communication with a baud rate of 9600.
   Start the infrared receiver.
   Call the ``initNewValue()`` function to set the initial game state.

3. ``loop()`` 

   Check if a signal is received from the infrared remote controller.
   Decode the received infrared signal.
   Update the game state or perform corresponding actions based on the decoded value (number or command).

4. ``initNewValue()`` 

   Use ``analogRead`` to initialize the random number seed, ensuring different random numbers are generated each time.
   Generate a random number between 0 and 98 as the lucky number (the number players need to guess).
   Reset upper and lower limit prompts.
   Display a welcome message on the LCD.
   Reset the input number.

5. ``detectPoint()`` 

   Check the relationship between the player's input number and the lucky number.
   If the input number is greater than the lucky number, update the upper limit prompt.
   If the input number is smaller than the lucky number, update the lower limit prompt.
   If the player inputs the correct number, reset the input and return true.

6. ``lcdShowInput()`` 

   Display the player's input and the current upper and lower limit prompts on the LCD.
   If the player guesses correctly, display a success message and pause for 5 seconds before restarting the game.
