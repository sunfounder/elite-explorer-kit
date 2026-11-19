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


Calibration
----------------------

Before reading sensor data, calibrate the IMU to make the measurements accurate.

#. Install the **SunFounder_IMU** library: open the Arduino Library Manager, search for **"SunFounder_IMU"**, and click **INSTALL** (the screenshot below shows the entry once it is installed).

   .. image:: img/09-add_lib_tip_imu.png
      :align: center

#. Open the file ``09-imu_calibration.ino`` under the path of ``elite-explorer-kit-main\basic_project\09-imu_calibration`` and upload it to your board.

#. Open the Serial Monitor and set the baud rate to **115200** and the line ending to **Both NL & CR**.

   * Type any character and press Enter to start. The Serial Monitor then shows the first orientation.
   * Place the module in the six orientations in the order they are requested: Z up, Z down, X up, X down, Y up, and Y down.
   * Keep the module completely still during each measurement, then send any character again to measure the current orientation and move on to the next one.

   .. image:: img/09_imu_cali.png
      :align: center
      :width: 90%

#. After the sixth orientation, the Serial Monitor prints the calibration constants. Copy the six lines:

   .. code-block:: text

      Calibration complete!
      Copy the following calibration data to your calibration_data.h:
      const float ACCEL_BIAS[3] = {-0.0345, 0.0192, -0.1268};
      const float ACCEL_SCALE[3] = {1.0012, 0.9987, 1.0005};
      const float GYRO_BIAS[3] = {0.4120, -0.2085, 0.0331};
      const float GYRO_SCALE[3] = {1.0000, 1.0000, 1.0000};
      const float MAG_BIAS[3] = {-212.5000, 87.2500, -341.0000};
      const float MAG_SCALE[3] = {0.9620, 1.0110, 1.0270};

   The values above are only an example; yours belong to your own module.

#. Open the file ``09-imu.ino`` under the path of ``elite-explorer-kit-main\basic_project\09-imu`` directly.

   * This sketch reads the calibration values from ``calibration_data.h``; replace the six arrays with the ones you copied.

   .. image:: img/imu_cali_data.png
      :align: center
      :width: 80%

#. Now, upload ``09-imu.ino`` to your Arduino Uno R4 board. The Serial Monitor then prints the accelerometer, gyroscope, magnetometer and barometer readings continuously.

   .. image:: img/imu_reading.png
