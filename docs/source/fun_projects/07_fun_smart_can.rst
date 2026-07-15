.. _fun_smart_can:

智能垃圾桶
=====================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/07_fun_smartcan.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

这是一个用于控制智能垃圾桶的 Arduino 代码。
当物体在垃圾桶前方 20 厘米范围内时，其盖子会自动打开。
该项目使用了 SG90 舵机电机和 HC-SR04 超声波距离传感器。

**所需元件**

在这个项目中，我们需要以下元件。

购买整套套件会更方便，以下是链接：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名称
        - 套件所含项目
        - 链接
    *   - Elite Explorer 套件
        - 300+
        - |link_Elite_Explorer_kit|

您也可以从下面的链接单独购买。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - 元件介绍
        - 购买链接

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

**接线**

.. image:: img/07_smart_trash_can_bb.png
    :width: 70%
    :align: center


**原理图**

.. image:: img/07_smart_trash_can_schematic.png
   :width: 90%
   :align: center

**代码**

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\fun_project\07_smart_trash_can`` 下的 ``07_smart_trash_can.ino`` 文件。
    * 或者将这段代码复制到 Arduino IDE 中。

.. literalinclude:: /_code/07_fun_smart_can.ino
   :language: cpp
   :linenos:
   :caption: 07_smart_trash_can.ino


**工作原理**

以下是代码的逐步说明：

1. 导入库并定义常量/变量：

   导入 ``Servo.h`` 库用于控制 SG90 舵机电机。
   定义了舵机电机、超声波传感器以及其他所需常量和变量的参数。

2. ``setup()``：

   以 9600 的波特率初始化与计算机的串行通信。
   配置超声波传感器的触发和回波引脚。
   将舵机电机连接到其控制引脚，并将其初始位置设置为关闭角度。设置角度后，断开舵机电机的连接以节省电力。

3. ``loop()``：

   测量距离三次并存储每次测量的值。
   计算三次测量的平均距离。
   如果平均距离小于或等于 20 厘米（定义的距离阈值），则舵机电机旋转到打开角度（0 度）。
   否则，舵机电机在延迟一秒钟后返回到关闭位置（90 度）。不使用时断开舵机电机的连接以节省电力。

4. ``readDistance()``：

   向超声波传感器的触发引脚发送一个脉冲。
   测量回波引脚的脉冲宽度并计算距离值。
   此计算使用空气中的声速根据脉冲时间计算距离。
