.. _basic_gy87:

IMU 模块 (GY-87)
==========================

.. note:: 该套件的不同版本可能使用不同的 IMU 模块。请根据您所拥有的套件版本选择相应的教程。如果您拥有 10 轴 IMU 模块，请参阅 :ref:`basic_imu` 教程。如果您拥有 GY-87 模块，请参阅本课程。

GY-87 模块配备了三款传感器芯片：MPU6050、QMC5883L 和 BMP180，各具独特功能。MPU6050 结合了陀螺仪和加速度计用于运动追踪，QMC5883L 作为磁力计用于方向感测，BMP180 用于测量气压和温度。这些传感器可通过 I2C 协议与 Arduino 进行有效通信。

这些传感器设计用于通过 I2C 协议无缝集成，确保与 Arduino 等平台的高效通信。GY-87 模块中的每个传感器都可通过独特的 I2C 地址访问：MPU6050 的地址为 0x68，QMC5883L 的地址为 0x0D，BMP180 的地址为 0x77。


每个传感器芯片的单独教程：

.. toctree::
    :maxdepth: 1

    09_basic_gy87_bmp180
    09_basic_gy87_mpu6050
    09_basic_gy87_qmc5883l


.. raw:: html

   <br/>

.. **GY-87 模块代码**

如果您想同时使用这三款芯片，以下是一个简单示例：


.. image:: img/09-gy87_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

.. .. image:: img/09_basic_gy87_schematic.png
..     :align: center
..     :width: 90%


.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\09-gy87`` 下的 ``09-gy87.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. note::
    要安装库，请使用 Arduino 库管理器。

        - 搜索 **"Adafruit MPU6050"** 并安装

          安装每个库时，请确保选择安装所有依赖项。

          .. image:: img/09-add_lib_tip.png
             :width: 80%

        - 搜索 **"Adafruit Unified Sensor"** 并安装
        - 搜索 **"QMC5883LCompass"** 并安装
        - 搜索 **"Adafruit BMP085 Library"** 并安装

.. literalinclude:: /_code/09_basic_gy87.ino
   :language: cpp
   :linenos:
   :caption: 09-gy87.ino

.. note::
   磁力计必须经过校准(:ref:`basic_gy87_calibrate`)才能用作指南针，使用时必须保持水平，并**远离铁质物体、磁化材料和载流导线** 。

代码成功上传到您的 Arduino Uno R4 后，串口监视器将开始运行，持续打印来自 GY-87 IMU 模块的传感器数据。该模块集成了三个独立的传感器：用于加速度计和陀螺仪读数的 MPU6050、用于磁力计读数的 QMC5883L，以及用于气压和温度读数的 BMP180。
