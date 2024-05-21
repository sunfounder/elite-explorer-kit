.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _basic_gy87_bmp180:

BMP180
==========================


Overview
---------------

In this tutorial, we delve into the GY-87 IMU module, focusing on the BMP180 sensor for measuring temperature, pressure, and altitude. Ideal for applications like weather monitoring and altitude tracking, this lesson covers interfacing the GY-87 with an Arduino Uno and using the Adafruit BMP085 library. You'll learn how to initialize the BMP180 sensor and read its data on the Arduino Serial Monitor, a crucial skill for projects that require environmental data.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_gy87`
        - \-


Wiring
----------------------

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 75%

.. raw:: html

   <br/>


Schematic Diagram
-----------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%


Code
-----------

.. note::

    * You can open the file ``09-gy87_bmp180.ino`` under the path of ``elite-explorer-kit-main\basic_project\09-gy87_bmp180`` directly.
    * Or copy this code into Arduino IDE.

.. note:: 
    To install the library, use the Arduino Library Manager and search for **"Adafruit BMP085 Library"** and install it. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7f7347f7-e1e6-400f-b10c-02ccf300b3b9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Code Analysis
------------------------

- ``initializeBMP180()``

  Initialize the BMP180 sensor.

  .. code-block:: arduino

     void initializeBMP180() {
       // Start BMP180 initialization
       if (!bmp.begin()) {
         Serial.println("Could not find a valid BMP180 sensor, check wiring!");
         while (1)
           ;  // Halt if sensor not found
       }
       Serial.println("BMP180 Found!");
     }

- ``printBMP180()``

  Print the values ​​read by the BMP180 sensor.

  .. code-block:: arduino

     void printBMP180() {
       Serial.println();
       Serial.println("BMP180 ------------");
       Serial.print("Temperature = ");
       Serial.print(bmp.readTemperature());
       Serial.println(" *C");
     
       Serial.print("Pressure = ");
       Serial.print(bmp.readPressure());
       Serial.println(" Pa");
     
       // Calculate altitude assuming 'standard' barometric
       // pressure of 1013.25 millibar = 101325 Pascal
       Serial.print("Altitude = ");
       Serial.print(bmp.readAltitude());
       Serial.println(" meters");
     
       Serial.print("Pressure at sealevel (calculated) = ");
       Serial.print(bmp.readSealevelPressure());
       Serial.println(" Pa");
       Serial.println("BMP180 ------------");
       Serial.println();
     }


