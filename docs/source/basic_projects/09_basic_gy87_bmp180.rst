.. _basic_gy87_bmp180:

BMP180
==========================


概述
---------------

在本教程中，我们将深入探讨 GY-87 IMU 模块，重点介绍用于测量温度、气压和海拔的 BMP180 传感器。本课程适用于天气预报和海拔追踪等应用，涵盖将 GY-87 与 Arduino Uno 连接以及使用 Adafruit BMP085 库的内容。您将学习如何初始化 BMP180 传感器并在 Arduino 串口监视器上读取其数据，这是需要环境数据的项目中的关键技能。

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

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\09-gy87_bmp180`` 下的 ``09-gy87_bmp180.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. note::
    要安装库，请使用 Arduino 库管理器搜索 **"Adafruit BMP085 Library"** 并安装。

.. literalinclude:: /_code/09_basic_gy87_bmp180.ino
   :language: cpp
   :linenos:
   :caption: 09-gy87_bmp180.ino


代码分析
------------------------

- ``initializeBMP180()``

  初始化 BMP180 传感器。

  .. code-block:: arduino

     void initializeBMP180() {
       // 开始 BMP180 初始化
       if (!bmp.begin()) {
         Serial.println("Could not find a valid BMP180 sensor, check wiring!");
         while (1)
           ;  // 如果未找到传感器则暂停
       }
       Serial.println("BMP180 Found!");
     }

- ``printBMP180()``

  打印 BMP180 传感器读取的值。

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

       // 计算海拔，假设'标准'大气压为 1013.25 毫巴 = 101325 帕斯卡
       Serial.print("Altitude = ");
       Serial.print(bmp.readAltitude());
       Serial.println(" meters");

       Serial.print("Pressure at sealevel (calculated) = ");
       Serial.print(bmp.readSealevelPressure());
       Serial.println(" Pa");
       Serial.println("BMP180 ------------");
       Serial.println();
     }


