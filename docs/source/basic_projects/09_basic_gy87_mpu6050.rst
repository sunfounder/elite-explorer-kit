MPU6050
==========================


Overview
---------------

In this tutorial, you'll learn to interface the GY-87 IMU module with an Arduino Uno, focusing on the MPU6050 sensor. We'll cover initializing the MPU6050 and displaying its accelerometer, gyroscope, and temperature data on the Serial Monitor. This lesson is essential for projects needing motion and temperature sensing, like robotics, gesture-controlled devices, and interactive art installations.

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

    * You can open the file ``09-gy87_mpu6050.ino`` under the path of ``Elite-Explorer-Kit-main\basic_project\09-gy87_mpu6050`` directly.
    * Or copy this code into Arduino IDE.

.. note:: 
    To install the library, use the Arduino Library Manager and search for **"Adafruit MPU6050"** and install it. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f89edd5d-e6f9-4f83-979c-6c1d5da3e9d7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Code Analysis
------------------------

#. Include Libraries

   The ``Adafruit_MPU6050``, ``Adafruit_Sensor``, and ``Wire`` libraries are included for sensor interfacing and communication.

   .. code-block:: arduino

      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>

#. Initialize Sensor Object

   An object of the Adafruit_MPU6050 class is created to represent the MPU6050 sensor.

   .. code-block:: arduino

      Adafruit_MPU6050 mpu;

#. Setup Function

   Initializes serial communication and calls the function to initialize the MPU6050 sensor.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        initializeMPU6050();
      }

#. Loop Function

   Repeatedly calls the function to print MPU6050 data with a delay of 500 milliseconds between each call.

   .. code-block:: arduino

      void loop() {
        printMPU6050();
        delay(500);
      }

#. Initialize MPU6050 Function

   Checks if the MPU6050 is connected, sets accelerometer and gyro ranges, and configures the filter bandwidth.

   .. code-block:: arduino

      void initializeMPU6050() {
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

#. Print MPU6050 Data Function

   Reads and prints the acceleration, gyroscope, and temperature data from the MPU6050 to the Serial Monitor.

   .. code-block:: arduino

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
