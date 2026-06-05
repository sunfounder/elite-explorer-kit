.. _basic_servo:

舵机
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/servo_uno.html#servo-uno

概述
---------------

在本课中，您将探索 Arduino 和舵机的使用。重点介绍 Arduino Uno 和 SG90 舵机，您将学习如何编程 Arduino 来控制舵机的扫动运动。该技术对于机器人和自动化系统等各种应用至关重要。

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

接线
----------------------

.. image:: img/27-servo_bb.png
    :align: center
    :width: 70%

.. raw:: html

   <br/>

原理图
-----------------------

.. image:: img/27_servo_schematic.png
    :align: center
    :width: 60%

代码
---------------

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\27-servo`` 下的 ``27-servo.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c57ddb7a-0acb-4a64-938a-0a0abfc0ec4b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


代码分析
------------------------


1. 这里包含了 ``Servo`` 库，它允许轻松控制舵机。还定义了连接到舵机的引脚和舵机的初始角度。

   .. code-block:: arduino

      #include <Servo.h>
      const int servoPin = 9;  // 定义舵机引脚
      int angle = 0;           // 将角度变量初始化为 0 度
      Servo servo;             // 创建一个舵机对象

2. ``setup()`` 函数在 Arduino 启动时运行一次。使用 ``attach()`` 函数将舵机连接到定义的引脚。

   .. code-block:: arduino

      void setup() {
        servo.attach(servoPin);
      }

3. 主循环包含两个 ``for`` 循环。第一个循环将角度从 0 度增加到 180 度，第二个循环将角度从 180 度减小到 0 度。``servo.write(angle)`` 命令将舵机设置为指定角度。``delay(15)`` 使舵机在移动到下一个角度之前等待 15 毫秒，从而控制扫动运动的速度。

   .. code-block:: arduino

      void loop() {
        // 从 0 度扫描到 180 度
        for (angle = 0; angle < 180; angle++) {
          servo.write(angle);
          delay(15);
        }
        // 现在从 180 度扫描回 0 度
        for (angle = 180; angle > 0; angle--) {
          servo.write(angle);
          delay(15);
        }
      }
