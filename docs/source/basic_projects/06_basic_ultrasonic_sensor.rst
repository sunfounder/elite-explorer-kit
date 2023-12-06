.. _basic_ultrasonic_sensor:

Ultrasonic
==========================

Overview
--------------------

When you are reversing, you will see the distance between the car and the surrounding obstacles to avoid collision. The device for detecting the distance is an ultrasonic sensor. In this experiment, you will learn how the ultrasonic wave detects the distance.

Required Components
-------------------------

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|


Wiring
----------------------

.. image:: img/06-ultrasonic_module_bb.png
    :align: center
    :width: 100%

.. raw:: html

    <br/>

Schematic Diagram
-----------------------

.. image:: img/06_ultrasonic_schematic.png
    :align: center
    :width: 100%


Code
--------

.. note::

    * You can open the file ``06-ultrasonic.ino`` under the path of ``elite-explorer-kit-main\basic_project\06-ultrasonic`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/1897efb6-fa3c-4ebc-8993-6561b24848a9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/06_basic_ultrasonic_sensor.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Code Analysis
------------------------

**1. Initialize the ultrasonic sensor and LCD1602**

    .. code-block:: arduino
    
       #include <LiquidCrystal_I2C.h>
       
       LiquidCrystal_I2C lcd(0x27, 16, 2);  // initialize the Liquid Crystal Display object with the I2C address 0x27, 16 columns and 2 rows
       
       // Define the pin numbers for the ultrasonic sensor
       const int echoPin = 3;
       const int trigPin = 4;
       
       void setup() {
         pinMode(echoPin, INPUT);               // Set echo pin as input
         pinMode(trigPin, OUTPUT);              // Set trig pin as output
       
         lcd.init();       // initialize the LCD
         lcd.clear();      // clear the LCD display
         lcd.backlight();  // Make sure backlight is on
       
       }

**2. Display the distance on the LCD1602**

    .. code-block:: arduino
    
       void loop() {
         float distance = readDistance();  // Call the function to read the sensor data and get the distance
       
         lcd.setCursor(0, 0);         //Place the cursor at Line 1, Column 1. From here the characters are to be displayed
         lcd.print("Distance:");      ////Print Distance: on the LCD
         lcd.setCursor(0, 1);         //Set the cursor at Line 1, Column 0
         lcd.print("               ");  //Here is to leave some spaces after the characters so as to clear the previous characters that may still remain.
         lcd.setCursor(7, 1);         //Set the cursor at Line 1, Column 7.
         lcd.print(distance);         // print on the LCD the value of the distance converted from the time between ping sending and receiving.
         lcd.setCursor(14, 1);        //Set the cursor at Line 1, Column 14.
         lcd.print("cm");             //print the unit "cm"
       
         delay(800);                       // Delay for 800 milliseconds before repeating the loop
       }

**3. Convert the time to distance**

    .. code-block:: arduino

        float readDistance(){// ...}

    Here, "PING" refers to the process where the ultrasonic sensor sends out an ultrasonic pulse (or "ping") and then waits for its echo.
    
    PING is triggered by a HIGH pulse of 2 or more microseconds. (Give a short LOW pulse beforehand to ensure a clean HIGH pulse.)

    .. code-block:: arduino

        digitalWrite(trigPin, LOW); 
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH); 
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW); 

    The echo pin is used to read signal from PING, a HIGH pulse whose duration is the time (in microseconds) from the sending of the ping to the reception of echo of the object. We use the following function to obtain the duration.

    .. code-block:: arduino

        pulseIn(echoPin, HIGH);

    The speed of sound is 340 m/s or 29 microseconds per centimeter.

    This gives the distance travelled by the ping, outbound and return, so we divide by 2 to get the distance of the obstacle.

    .. code-block:: arduino

        float distance = pulseIn(echoPin, HIGH) / 29.00 / 2;     // Formula: (340m/s * 1us) / 2