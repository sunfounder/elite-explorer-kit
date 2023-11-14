GY-87 IMU Module
==========================

The GY-87 module is equipped with three sensor chips: MPU6050, QMC5883L, and BMP180, each offering unique capabilities. The MPU6050 combines a gyroscope and an accelerometer for motion tracking, the QMC5883L serves as a magnetometer for directional sensing, and the BMP180 is used for measuring barometric pressure and temperature. These can be interfaced using the I2C protocol for effective communication with an Arduino.

These sensors are designed for seamless integration via the I2C protocol, ensuring efficient communication with platforms like Arduino. Each sensor in the GY-87 module is accessible through unique I2C addresses: MPU6050 is accessed at 0x68, QMC5883L at 0x0D, and BMP180 at 0x77.


Individual tutorials for each sensor chip:

.. toctree::
    :maxdepth: 1

    09_basic_gy87_bmp180
    09_basic_gy87_mpu6050
    09_basic_gy87_qmc5883l


.. raw:: html

   <br/>

.. **Code for of GY-87 module**

If you want to use these three chips simultaneously, here is a simple example:


.. image:: img/09-gy87_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

.. .. image:: img/09_basic_gy87_schematic.png
..     :align: center
..     :width: 90%


.. note::

    * You can open the file ``09-gy87.ino`` under the path of ``Elite-Explorer-Kit-main\basic_project\09-gy87`` directly.
    * Or copy this code into Arduino IDE.

.. note:: 
    To install the library, use the Arduino Library Manager. 
    
        - Search for **"Adafruit MPU6050"** and install

          When installing each library, please make sure to select the installation of all dependencies.
      
          .. image:: img/09-add_lib_tip.png
             :width: 80%

        - Search for **"Adafruit Unified Sensor"** and install
        - Search for **"QMC5883LCompass"** and install
        - Search for **"Adafruit BMP085 Library"** and install

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/efd14082-486b-47eb-9533-8d36a36d2d88/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. note::
   Magnetometers must be calibrated(:ref:`basic_gy87_calibrate`) before they can be used as compasses, and must held level in use and **kept away from iron objects, magnetized materials and current carrying wires**.

After the code is successfully uploaded to your Arduino Uno R4, the Serial Monitor will come to life, continuously printing out sensor data from the GY-87 IMU module. This module incorporates three individual sensors: the MPU6050 for accelerometer and gyroscope readings, the QMC5883L for magnetometer readings, and the BMP180 for barometric pressure and temperature readings.