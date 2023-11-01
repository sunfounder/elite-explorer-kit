.. _basic_i2c_lcd1602:

I2C LCD1602
==========================

.. https://docs.sunfounder.com/projects/sensorkit-v2-arduino/en/latest/lesson_1.html

Overview
---------------

In this lesson, you will learn about Liquid Crystal Displays (LCDs) with an I2C interface. These types of LCDs are widely used in a variety of electronic devices, such as digital clocks, microwave ovens, car dashboards, and even industrial equipment. The I2C interface simplifies the wiring and connections, making it more convenient and efficient for hobbyists and professionals alike.

Required Components
-------------------------

* :ref:`uno_r4_wifi`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_i2c_lcd1602`

Wiring
----------------------

.. image:: img/14-i2c_lcd_bb.png
    :align: center
    :width: 100%

Schematic Diagram
-----------------------

.. image:: img/14-i2c_lcd_schematic.png
    :align: center
    :width: 80%

Code
---------------

.. note::

    * You can open the file ``14-i2c_lcd.ino`` under the path of ``Elite-Explorer-Kit-main\basic_project\14-i2c_lcd`` directly.
    * Or copy this code into Arduino IDE.

.. note:: 
    To install the library, use the Arduino Library Manager and search for **"LiquidCrystal I2C"** and install it. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/096326ad-eccf-4d2e-be52-66f4819ca7d8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


After the code is uploaded successfully to the Arduino, the Liquid Crystal Display (LCD) will show the message "Hello world!" on its first line and "LCD Tutorial" on its second line.

Code Analysis
------------------------

1. Library Inclusion and LCD Initialization:
   The LiquidCrystal I2C library is included to provide functions and methods for LCD interfacing. Following that, an LCD object is created using the LiquidCrystal_I2C class, specifying the I2C address, number of columns, and number of rows.

   .. note:: 
      To install the library, use the Arduino Library Manager and search for **"LiquidCrystal I2C"** and install it.  

   .. code-block:: arduino

      #include <LiquidCrystal_I2C.h>
      LiquidCrystal_I2C lcd(0x27, 16, 2);

2. Setup Function:
   The ``setup()`` function is executed once when the Arduino starts. In this function, the LCD is initialized, cleared, and the backlight is turned on. Then, two messages are displayed on the LCD.

   .. code-block:: arduino

      void setup() {
        lcd.init();       // initialize the LCD
        lcd.clear();      // clear the LCD display
        lcd.backlight();  // Make sure backlight is on
      
        // Print a message on both lines of the LCD.
        lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
        lcd.print("Hello world!");
      
        lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
        lcd.print("LCD Tutorial");
      }