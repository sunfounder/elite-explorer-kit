.. _basic_gy87:

QMC5883L
==========================

Overview
---------------

In this tutorial, we will explore the GY-87 IMU module, focusing on its QMC5883L magnetometer. The first part of the tutorial guides you through calibrating the QMC5883L magnetometer, which is essential for accurate magnetic field measurements. You will learn how to upload a calibration sketch to Arduino, perform real-time calibration, and apply these settings in your projects. The second part of the tutorial covers initializing the MPU6050 (accelerometer and gyroscope) and QMC5883L on an Arduino Uno using the Adafruit MPU6050 and QMC5883LCompass libraries. You will learn how to read and display sensor data on the Serial Monitor, which is a fundamental skill for applications in navigation, motion tracking, and orientation detection.

Required Components
-------------------------

* :ref:`uno_r4_wifi`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_gy87`

Wiring
----------------------

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 90%

.. raw:: html

   <br/>


Schematic Diagram
-----------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%


Install Library
-----------------------

.. note:: 
    To install the library, use the Arduino Library Manager. 
    
        - Search for **"Adafruit MPU6050"** and install

          When installing each library, please make sure to select the installation of all dependencies.
      
          .. image:: img/09-add_lib_tip.png
             :width: 80%

        - Search for **"QMC5883LCompass"** and install


.. _basic_gy87_calibrate:

Calibrate QMC5883L
-----------------------

.. note::

    * You can open the file ``09-gy87_compass_calibration.ino`` under the path of ``Elite-Explorer-Kit-main\basic_project\09-gy87_compass_calibration`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/252c7a58-3a9f-4c66-959e-f45fc19e68aa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After uploading the code, open the serial monitor. Follow the instructions in the serial monitor to calibrate QMC5883L. When prompted to move the sensor, it is recommended to use Figure 8 calibration method. Alternatively, simply keep the sensor parallel to the ground and rotate it clockwise or counterclockwise until the serial monitor prompts that calibration is complete.

.. image:: img/09_calibrate_qmc5883l.png
    :width: 100%
    :align: center

Once all calibration data has been collected, the sketch will tell provide you with some code that will look like ``compass.setCalibrationOffsets(-375.00, -179.00, 85.00);`` and ``compass.setCalibrationScales(1.04, 0.96, 1.01);``. Copy this code. You may want to save it for future reference.

When using QMC5883L: Open your project's sketch and paste the line of code you copied directly below the ``compass.init()`` call. Just like this:

.. code:: arduino 

   void initializeQMC5883L() {
   
     compass.init();
   
     // You should replace the code below according to your calibration results
     compass.setCalibrationOffsets(-375.00, -179.00, 85.00);
     compass.setCalibrationScales(1.04, 0.96, 1.01);
   
   }

Code
---------------------------------------------

.. note::

   Magnetometers must be calibrated(:ref:`basic_gy87_calibrate`) before they can be used as compasses, and must held level in use and **kept away from iron objects, magnetized materials and current carrying wires**.

.. note::

    * You can open the file ``09-gy87_qmc5883l.ino`` under the path of ``Elite-Explorer-Kit-main\basic_project\09-gy87_qmc5883l`` directly.
    * Or copy this code into Arduino IDE.
    * Put the code obtained from the calibration steps below the line of code ``compass.init()`` in the function ``initializeQMC5883L()``.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b266a18-ce7b-4330-8c10-c9f4148bb8ec/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Code Analysis
------------------------


#. Include Libraries and Initialize Sensors
   This section includes the necessary libraries for the MPU6050 and QMC5883L sensors and initializes their objects.

   .. code-block:: arduino
      
      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>
      #include <QMC5883LCompass.h>

      Adafruit_MPU6050 mpu;
      QMC5883LCompass compass;

#. Setup Function

   Initializes serial communication, the MPU6050 sensor, and sets the MPU6050 to I2C bypass mode to allow direct access to the QMC5883L magnetometer. Then, it initializes the QMC5883L magnetometer.

   .. code-block:: arduino
      
      void setup() {
        // Initialize the serial communication with a baud rate of 9600
        Serial.begin(9600);
      
        // Initialize the MPU6050 sensor (accelerometer and gyroscope)
        initializeMPU6050();
      
        // Enable I2C bypass on MPU6050 to directly access the QMC5883L magnetometer
        mpu.setI2CBypass(true);
      
        // Initialize the QMC5883L magnetometer sensor
        initializeQMC5883L();
      }

#. Loop Function

   Continuously reads data from the QMC5883L magnetometer and prints it to the Serial Monitor.

   .. code-block:: arduino
      
      void loop() {
        printQMC5883L();
        delay(500);
      }

#. Initialize QMC5883L Function

   Initializes and calibrates the QMC5883L magnetometer. The calibration values should be adjusted based on specific calibration data.(:ref:`basic_gy87_calibrate`)

   .. code-block:: arduino
      
      void initializeQMC5883L() {
        compass.init();
      
        // You should replace the code below according to your calibration results
        compass.setCalibrationOffsets(-549.00, -66.00, 160.00);
        compass.setCalibrationScales(0.97, 1.02, 1.02);
      }

#. Print QMC5883L Data Function

   This function reads the magnetometer's X, Y, Z values, and azimuth, then prints them to the Serial Monitor.

   .. code-block:: arduino

    void printQMC5883L() {
    
      Serial.println();
      Serial.println("QMC5883L ------------");
    
    	int x, y, z, a;
    	char myArray[3];
    	
    	compass.read();
      
    	x = compass.getX();
    	y = compass.getY();
    	z = compass.getZ();
    	
    	a = compass.getAzimuth();
    
    	compass.getDirection(myArray, a);
      
    	Serial.print("X: ");
    	Serial.print(x);
    
    	Serial.print(" Y: ");
    	Serial.print(y);
    
    	Serial.print(" Z: ");
    	Serial.print(z);
    
    	Serial.print(" Azimuth: ");
    	Serial.print(a);
    
    	Serial.print(" Direction: ");
    	Serial.print(myArray[0]);
    	Serial.print(myArray[1]);
    	Serial.println(myArray[2]);
    
      Serial.println("QMC5883L ------------");
      Serial.println();
    }
