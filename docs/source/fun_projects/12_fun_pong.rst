.. _fun_pong:

GAME - Pong
=================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/12_fun_pong.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

This is a simple Pong game designed using an OLED display and an Arduino board.
In the Pong game, players compete against the computer, controlling a vertical paddle to bounce back a bouncing ball. 
The goal is to prevent the ball from passing your paddle's edge, or else the opponent scores.

The game mechanics can be divided into the following parts:

1. Ball Movement - The ball moves along its current direction at a set speed. Whenever the ball collides with a paddle, its speed increases, making the game more challenging.

2. Paddle Movement - Used to block the ball's movement, the paddle can move up or down. Players control their own paddle using buttons, while the computer's paddle automatically follows the ball's position.

3. Scoring - Whenever the ball goes beyond the left or right edge of the screen, the corresponding player or CPU scores.

**Required Components**

* :ref:`uno_r4_wifi`
* :ref:`cpn_wires`
* :ref:`cpn_breadboard`
* :ref:`cpn_oled`
* :ref:`cpn_button`


**Wiring**

.. image:: img/12_pong_bb.png
    :width: 100%
    :align: center


**Schematic**

.. image:: img/12_pong_schematic.png
    :width: 100%
    :align: center

**Code**

.. note::

    * You can open the file ``12_pong_oled.ino`` under the path of ``Elite-Explorer-Kit-main\fun_project\12_pong_oled`` directly.
    * Or copy this code into Arduino IDE.

.. note::
   To install the library, use the Arduino Library Manager and search for **“Adafruit SSD1306”** and **“Adafruit GFX”** and install them.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/86dbb549-d425-4f42-8b5b-28d486e3f7f8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**How it works?**

The program structure can be divided into the following five parts:

1. Import Necessary Libraries - Used to control the OLED screen and read button inputs.

2. Define Constants and Global Variables:

   Definitions for OLED screen width and height.
   Definitions for buttons and OLED reset pins.
   Position, speed, size, and direction of the ball and paddles.
   Scores for player and CPU.

3. Initialization:

   Initialize serial communication, the OLED screen, and display the initial interface.
   Set buttons as inputs and connect pull-up resistors.
   Draw the playing field.

4. Main Loop:

   Read button states.
   Move the ball based on the set refresh rate.
   Detect collisions between the ball and paddles or walls, adjusting the ball's direction and speed accordingly.
   Update the screen with scores based on scoring events.
   Refresh paddle positions.

5. Additional Functions:

   ``crossesPlayerPaddle`` and ``crossesCpuPaddle`` - Used to detect whether the ball collides with the player's or CPU's paddle.
   
   ``drawCourt`` - Draws the playing field on the OLED screen.

   ``displayScore`` - Displays the player's and CPU's scores on the screen.
