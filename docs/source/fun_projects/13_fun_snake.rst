.. _fun_snake:

GAME - Snake
=========================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/13_fun_snake.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

This example implements the classic Snake game on an 8x12 LED matrix using the R4 Wifi board.
Players control the snake's direction using a dual-axis joystick.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

**Wiring**

.. image:: img/13_snake_bb.png
    :width: 80%
    :align: center


**Schematic**

.. image:: img/13_snake_schematic.png
   :width: 80%
   :align: center


**Code**

.. note::

    * You can open the file ``13_snake.ino`` under the path of ``elite-explorer-kit-main\fun_project\13_snake`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/df370ec5-d1b5-4ae7-b3b9-e97e0eb9a872/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**How it works?**

Here's a detailed explanation of the code:

1. Variable Definition and Initialization

   Import the ``Arduino_LED_Matrix`` library for LED matrix operations.
   matrix is an instance of the LED matrix.
   ``frame`` and ``flatFrame`` are arrays used to store and process pixel information on the screen.
   The snake is represented as an array of ``Point`` structures, where each point has an x and y coordinate.
   food represents the position of the food.
   ``direction`` is the current movement direction of the snake.

2. ``setup()`` 

   Initialize the X and Y axes of the joystick as inputs.
   Start the LED matrix.
   Initialize the snake's starting position in the center of the screen.
   Generate the initial position of the food randomly.

3. ``loop()`` 

   Determine the snake's direction based on the readings from the joystick.
   Move the snake.
   Check if the snake's head collides with the food. 
   If it does, the snake grows, and new food is generated at a new location.
   Check if the snake collides with itself. If it does, reset the game.
   Draw the current game state (snake and food positions) on the LED matrix.
   Add a delay to control the game's speed.

4. ``moveSnake()`` 

   Move each part of the snake to the position of the previous part, starting from the tail and moving to the head.
   Move the snake's head based on its direction.

5. ``generateFood()`` 

   Generate all possible food positions.
   Check if each position overlaps with any part of the snake. If it doesn't overlap, the position is considered a possible food location.
   Randomly select a possible food location.

6. ``drawFrame()`` 

   Clear the current frame.
   Draw the snake and food on the frame.
   Flatten the two-dimensional frame array into a one-dimensional array (flatFrame) and load it onto the LED matrix.
