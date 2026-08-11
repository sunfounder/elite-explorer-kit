.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _basic_imu:

IMU Module (10-Axis)
==========================

.. note:: Different versions of this kit may use different IMU modules. Please select the appropriate tutorial based on the version of the kit you have. If you have a 10-axis IMU module, please refer to this tutorial. If you have a GY-87 module, please refer to :ref:`basic_gy87`.

The 10-Axis IMU (Inertial Measurement Unit) module combines multiple sensors to provide comprehensive motion and environmental data. It integrates a barometric pressure sensor (SPL06_001) for altitude measurement, a 6-axis motion sensor (SH3001) for acceleration and rotation, and a 3-axis magnetometer (QMC6310) for compass heading. This sophisticated module is ideal for robotics, navigation systems, and motion-tracking applications.





Fritzing Circuit
----------------------------------

.. image:: img/imu_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

.. .. image:: img/09_basic_gy87_schematic.png
..     :align: center
..     :width: 90%


Install library
---------------------------------

To install the library, use the Arduino Library Manager. 

   - Search for **"SunFounder_IMU"** and install


      .. image:: img/09-add_lib_tip_imu.png



Calibration
----------------------

Before using the IMU module, it is recommended to perform calibration to ensure the accuracy of sensor data. The following are the calibration steps:

* Open the file ``09-imu_calibration.ino`` under the path of ``elite-explorer-kit-main\basic_project\09-imu_calibration`` directly.

After running this code, open the Serial Monitor and you will see the sensor data output. It is typically in the following format:

.. code-block:: text

   const float ACCEL_BIAS[3] = {0.0, 0.0, 0.0};
   const float ACCEL_SCALE[3] = {1.0, 1.0, 1.0};
   const float GYRO_BIAS[3] = {0.0, 0.0, 0.0};
   const float GYRO_SCALE[3] = {1.0, 1.0, 1.0};
   const float MAG_BIAS[3] = {0.0, 0.0, 0.0};
   const float MAG_SCALE[3] = {1.0, 1.0, 1.0};

Copy this data.

Run the Code
----------------------


Open the file ``09-imu.ino`` under the path of ``elite-explorer-kit-main\basic_project\09-imu`` directly.

Go to the ``calibration_data.h`` page in the project, paste the data you just copied into the ``calibration_data.h`` file, replacing the original data.

.. image:: img/imu_cali_data.png
   :width: 80%

Switch back to the ``09-imu.ino`` page and upload the code to your Arduino Uno R4 board.

.. literalinclude:: /_code/09_basic_imu.ino
   :language: cpp
   :linenos:
   :caption: 09-imu.ino

After the code is successfully uploaded to your Arduino Uno R4, the Serial Monitor will come to life, continuously printing out sensor data from the 10-Axis IMU module. 

.. image:: img/imu_reading.png
