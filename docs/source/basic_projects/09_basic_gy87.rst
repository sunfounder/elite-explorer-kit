.. _basic_gy87:

GY-87 IMU module
==========================


Overview
---------------

In this lesson, you will learn about the GY-87 IMU (Inertial Measurement Unit) module and how to interface it with an Arduino Uno R4. The GY-87 is a multi-sensor module that combines three different types of sensors: MPU6050 (Accelerometer and Gyroscope), QMC5883L (Magnetometer), and BMP180 (Barometric Pressure and Temperature).

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
    :width: 90%


Install Library
-----------------------

.. note:: 
    To install the library, use the Arduino Library Manager. 
    
        - Search for **"Adafruit MPU6050"** and install

          When installing each library, please make sure to select the installation of all dependencies.
      
          .. image:: img/09-add_lib_tip.png
             :width: 80%

        - Search for **"Adafruit Unified Sensor"** and install
        - Search for **"QMC5883LCompass"** and install
        - Search for **"Adafruit BMP085 Library"** and install


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

Code for multiple sensors of GY-87 module
---------------------------------------------

.. note::

    * You can open the file ``09-gy87.ino`` under the path of ``Elite-Explorer-Kit-main\basic_project\09-gy87`` directly.
    * Or copy this code into Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/efd14082-486b-47eb-9533-8d36a36d2d88/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After the code is successfully uploaded to your Arduino Uno R4, the Serial Monitor will come to life, continuously printing out sensor data from the GY-87 IMU module. This module incorporates three individual sensors: the MPU6050 for accelerometer and gyroscope readings, the QMC5883L for magnetometer readings, and the BMP180 for barometric pressure and temperature readings.

Code Analysis
------------------------
   
#. Include Required Libraries

   Here, various libraries are included to interface with the different sensors.
   
   .. code-block:: arduino

      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>
      #include <QMC5883LCompass.h>
      #include <Adafruit_BMP085.h>

   - ``Adafruit_Sensor``: Generic sensor library, dependency for other Adafruit sensor libraries
   - ``Wire``: For I2C communication
   - ``Adafruit_MPU6050``: For interfacing with MPU6050 (Accelerometer and Gyroscope)
   - ``QMC5883LCompass``: For interfacing with  QMC5883L (Magnetometer)
   - ``Adafruit_BMP085``: For interfacing with BMP180 (Barometric Pressure and Temperature)

   .. raw:: html

      <br/>

#. Initialize Sensor Objects

   Instances of sensor objects are created to interface with them later.
   
   .. code-block:: arduino

      Adafruit_MPU6050 mpu;
      Adafruit_BMP085 bmp;
      QMC5883LCompass compass;

#. ``setup()`` Function

   The ``setup()`` function initializes the Serial communication and all the sensors.
   
   .. code-block:: arduino

      void setup() {
        // Initialize the serial communication with a baud rate of 115200
        Serial.begin(9600);
      
        // Initialize the MPU6050 sensor (accelerometer and gyroscope)
        initializeMPU6050();
      
        // Enable I2C bypass on MPU6050 to directly access the QMC5883L magnetometer
        mpu.setI2CBypass(true);
      
        // Initialize the QMC5883L magnetometer sensor
        initializeQMC5883L();
      
        // Initialize BMP180 barometric sensor
        initializeBMP180();
      }


#. ``loop()`` Function

   The ``loop()`` function continuously prints sensor data to the Serial Monitor.
   
   .. code-block:: arduino

      void loop() {
        // Print MPU6050 data
        printMPU6050();
      
        // Print QMC5883 data
        printQMC5883L();
      
        // Print BMP180 data
        printBMP180();
        delay(500);
      }
      
#. Sensor Initialization and Reading

   These are custom functions to initialize each sensor and print their readings.

   - For **MPU6050**

     .. code-block:: arduino

        void initializeMPU6050() {
          Serial.println("Adafruit MPU6050 test!");
        
          // Check if the MPU6050 sensor is detected
          if (!mpu.begin()) {
            Serial.println("Failed to find MPU6050 chip");
            while (1)
              ;  // Halt if sensor not found
          }
          Serial.println("MPU6050 Found!");
        
          // set accelerometer range to +-8G
          mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
        
          // set gyro range to +- 500 deg/s
          mpu.setGyroRange(MPU6050_RANGE_500_DEG);
        
          // set filter bandwidth to 21 Hz
          mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
        
          Serial.println("");
          delay(100);
        }



        void printMPU6050() {
        
          Serial.println();
          Serial.println("MPU6050 ------------");
        
          /* Get new sensor events with the readings */
          sensors_event_t a, g, temp;
          mpu.getEvent(&a, &g, &temp);
        
          /* Print out the values */
          Serial.print("Acceleration X: ");
          Serial.print(a.acceleration.x);
          Serial.print(", Y: ");
          Serial.print(a.acceleration.y);
          Serial.print(", Z: ");
          Serial.print(a.acceleration.z);
          Serial.println(" m/s^2");
        
          Serial.print("Rotation X: ");
          Serial.print(g.gyro.x);
          Serial.print(", Y: ");
          Serial.print(g.gyro.y);
          Serial.print(", Z: ");
          Serial.print(g.gyro.z);
          Serial.println(" rad/s");
        
          Serial.print("Temperature: ");
          Serial.print(temp.temperature);
          Serial.println(" degC");
        
          Serial.println("MPU6050 ------------");
          Serial.println();
        }
   
   - For **QMC5883L**

     .. note::
      Magnetometers must be calibrated(:ref:`basic_gy87_calibrate`) before they can be used as compasses, and must held level in use and **kept away from iron objects, magnetized materials and current carrying wires**.

     .. code-block:: arduino

        void initializeQMC5883L() {
        
          compass.init();
          
          // You should replace the code below according to your calibration results
          // compass.setCalibrationOffsets(-336.00, -179.00, 47.00);
          // compass.setCalibrationScales(1.05, 0.94, 1.02);
        
        }


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


   - For **BMP180**

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