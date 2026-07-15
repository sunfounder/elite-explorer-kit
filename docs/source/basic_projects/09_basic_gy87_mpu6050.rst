.. _basic_gy87_mpu6050:

MPU6050
==========================


概述
---------------

在本教程中，您将学习如何将 GY-87 IMU 模块与 Arduino Uno 连接，重点介绍 MPU6050 传感器。我们将介绍初始化 MPU6050 并在串口监视器上显示其加速度计、陀螺仪和温度数据的内容。本课程对于需要运动和温度传感的项目（如机器人技术、手势控制设备和互动艺术装置）至关重要。

所需元件
-------------------------

本项目中，我们需要以下元件。

购买整套套件会更加方便，以下是链接：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名称
        - 套件所含项目
        - 链接
    *   - Elite Explorer 套件
        - 300+
        - |link_Elite_Explorer_kit|

您也可以从以下链接单独购买。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - 元件介绍
        - 购买链接

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_gy87`
        - \-

接线
----------------------

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 75%

.. raw:: html

   <br/>


原理图
-----------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%


代码
-----------

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\09-gy87_mpu6050`` 下的 ``09-gy87_mpu6050.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. note::
    要安装库，请使用 Arduino 库管理器搜索 **"Adafruit MPU6050"** 并安装。

.. literalinclude:: /_code/09_basic_gy87_mpu6050.ino
   :language: cpp
   :linenos:
   :caption: 09-gy87_mpu6050.ino


代码分析
------------------------

#. 包含库

   包含了 ``Adafruit_MPU6050``、``Adafruit_Sensor`` 和 ``Wire`` 库，用于传感器接口和通信。

   .. code-block:: arduino

      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>

#. 初始化传感器对象

   创建 Adafruit_MPU6050 类的一个对象，用于表示 MPU6050 传感器。

   .. code-block:: arduino

      Adafruit_MPU6050 mpu;

#. 设置函数

   初始化串口通信并调用函数初始化 MPU6050 传感器。

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        initializeMPU6050();
      }

#. 循环函数

   重复调用函数打印 MPU6050 数据，每次调用之间延迟 500 毫秒。

   .. code-block:: arduino

      void loop() {
        printMPU6050();
        delay(500);
      }

#. 初始化 MPU6050 函数

   检查 MPU6050 是否已连接，设置加速度计和陀螺仪范围，并配置滤波器带宽。

   .. code-block:: arduino

      void initializeMPU6050() {
        // 检查是否检测到 MPU6050 传感器
        if (!mpu.begin()) {
          Serial.println("Failed to find MPU6050 chip");
          while (1)
            ;  // 如果未找到传感器则暂停
        }
        Serial.println("MPU6050 Found!");

        // 设置加速度计范围为 +-8G
        mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

        // 设置陀螺仪范围为 +- 500 deg/s
        mpu.setGyroRange(MPU6050_RANGE_500_DEG);

        // 设置滤波器带宽为 21 Hz
        mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

        Serial.println("");
        delay(100);
      }

#. 打印 MPU6050 数据函数

   从 MPU6050 读取加速度、陀螺仪和温度数据并打印到串口监视器。

   .. code-block:: arduino

      void printMPU6050() {

        Serial.println();
        Serial.println("MPU6050 ------------");

        /* 获取新的传感器事件读数 */
        sensors_event_t a, g, temp;
        mpu.getEvent(&a, &g, &temp);

        /* 打印数值 */
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
