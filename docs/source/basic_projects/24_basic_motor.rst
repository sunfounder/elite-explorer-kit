.. _basic_motor:

电机
==========================

概述
--------

在本课中，您将学习如何使用电机，其工作原理是通电线圈在磁场中受力旋转，电机的转子随之转动，小齿轮驱动发动机飞轮旋转。

所需元件
-------------------

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

        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_power`
        - \-

接线
----------------------

在本示例中，我们使用电源模块为面包板的正极和负极供电。

.. note::
    电机在运行过程中需要更多电力，因此使用时请保持电源模块连接到充电线。

.. image:: img/24-motor_bb.png
    :align: center
    :width: 90%

.. raw:: html

  <br/>

原理图
-----------------

.. image:: img/24_motor_schematic.png
    :align: center
    :width: 100%

.. raw:: html

  <br/>

代码
----

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\24-motor`` 下的 ``24-motor.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7376df09-204d-4698-b2a6-106e2d2f00e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

将代码上传到 UNO 板后，您可以通过在串口监视器中输入"A"或"B"来选择电机的旋转方向。


代码分析
--------------------------


通过在电机两侧的铜片之间提供电压差，可以驱动电机。
因此，只需将一侧铜片的电压写为 0，另一侧写为 5V。修改写入的模拟信号值以调整方向和速度。

.. code-block:: arduino

   // 顺时针旋转电机的函数
   void clockwise(int Speed) {
     analogWrite(motorBI, 0);
     analogWrite(motorFI, Speed);
   }

   // 逆时针旋转电机的函数
   void anticlockwise(int Speed) {
     analogWrite(motorBI, Speed);
     analogWrite(motorFI, 0);
   }

在此示例中，使用 Serial.Read() 来控制电机方向。

当您在串口监视器中输入 'A' 时，调用 clockwise (255) 函数使电机以速度 255 旋转。
输入 'B'，电机将反向旋转。

.. code-block:: arduino

   void loop() {
     // 检查串口是否有可用数据
     if (Serial.available() > 0) {
       int incomingByte = Serial.read(); // 读取传入数据

       // 根据用户输入确定电机方向
       switch (incomingByte) {
         case 'A':
           clockwise(255); // 顺时针旋转电机
           Serial.println("电机顺时针旋转。");
           break;
         case 'B':
           anticlockwise(255); // 逆时针旋转电机
           Serial.println("电机逆时针旋转。");
           break;
       }
     }

     delay(3000); // 等待 3 秒
     stopMotor(); // 停止电机
   }
