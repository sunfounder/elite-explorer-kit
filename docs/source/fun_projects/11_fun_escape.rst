.. _fun_escape:

GAME - Escape
==================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/11_fun_escape_square.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

This game is called "Escape".
The player's objective is to tilt the MPU6050 sensor to move a pixel on the LED matrix and attempt to maneuver it through an opening in the matrix border (the exit).

**Required Components**

* :ref:`uno_r4_wifi`
* :ref:`cpn_wires`
* :ref:`cpn_breadboard`
* :ref:`cpn_gy87`


**Wiring**

.. image:: img/11_escape_bb.png
    :width: 80%
    :align: center


**Schematic**

.. image:: img/11_escape_schematic.png
   :width: 70%
   :align: center


**Code**

.. note::

    * You can open the file ``11_escape_square.ino`` under the path of ``Elite-Explorer-Kit-main\fun_project\11_escape_square`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/6b239445-f921-48fb-a93e-70cc7ef8afc7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**How it works?**

Here's a detailed explanation of the code:

1. Library Imports and Global Variables:

   Imported libraries include the LED matrix, Wire (for I2C communication), MPU6050 (motion sensor), and ``Adafruit_Sensor`` library.
   Initialization of MPU6050 and LED matrix objects.
   Definition of global variables such as pixelX and pixelY (pixel position), gapStart and side (start position of the gap and which side), level (game difficulty level), and more.

2. ``setup()``:

   Initialize the LED matrix and draw the matrix with the gap.
   Initialize serial communication and check if the MPU6050 sensor is starting correctly, setting its acceleration range to 2g.

3. ``loop()``:

   Periodically update the position of the pixel based on MPU6050 sensor readings.
   Periodically move the gap's position.
   Load the new pixel layout and render it on the LED matrix.
   Check if the pixel has passed through the gap. 
   If it has, delay for 1.5 seconds to display the success, increase the game difficulty, and reset the pixel's position.

4. Other Functions:

   * ``drawSquareWithGap()``: Draw an 8x8 border and create a gap within it.
   * ``createGap()``: Create a gap of length 2 on the specified side.
   * ``moveGap()``: Move the gap's position based on the current side and gapStart, changing the side when necessary.
   * ``movePixelBasedOnMPU()``: Read acceleration data from MPU6050. Move the pixel's position based on the acceleration data (resetting if the pixel goes out of bounds or into walls).
   * ``resetPixel()``: Reset the pixel's position to the center of the matrix.
   * ``checkPixelPosition()``: Check if the pixel is on the gap. If it is, increase the game's difficulty level and set the pass flag to true.
