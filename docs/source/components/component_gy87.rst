.. _cpn_gy87:

GY-87 IMU module
============================

.. image:: img/gy87.png
    :align: center
    :width: 40%

The GY-87 sensor module is a high-precision, 10-axis (10DOF) module capable of measuring acceleration, angular velocity, and magnetic field strength across three axes: x, y, and z. It consists of three main sensors: MPU6050, QMC5883L, and BMP180, and communicates via the I2C protocol.

The GY-87 sensor module is based on three sensors:

1. **MPU6050**: This is a 6-axis accelerometer and gyroscope that can measure acceleration and angular velocity in three axes x, y, and z.
2. **QMC5883L**: This is a 3-axis digital compass that can measure the strength of the magnetic field in three axes x, y, and z.
3. **BMP180**: This is a barometric temperature and pressure sensor that can measure atmospheric pressure and temperature.

The MPU6050 measures acceleration and angular velocity in three axes x, y, and z. The QMC5883L measures the strength of the magnetic field in three axes x, y, and z. The BMP180 measures atmospheric pressure and temperature. The data from these sensors are combined to provide accurate information about the orientation of the module in space.

The GY-87 sensor module is commonly used in applications such as drones, robotics, and other projects that require accurate orientation information. It is compatible with Arduino boards and can be easily interfaced with them using the I2C communication protocol.

.. image:: img/GY-87-SCH.jpg
    :align: center
    :width: 100%

.. raw:: html

    <br/>

**Example**

* :ref:`basic_gy87_bmp180` (Basic Project)
* :ref:`basic_gy87_mpu6050` (Basic Project)
* :ref:`basic_gy87_qmc5883l` (Basic Project)
* :ref:`fun_escape` (Fun Project)
