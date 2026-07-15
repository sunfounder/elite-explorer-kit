.. _basic_stepper_motor:

步进电机
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/stepper_motor_uno.html#stepper-uno

概述
---------------

在本课中，您将学习如何使用 ULN2003 驱动器和 Arduino Uno R4 控制步进电机，特别是 28BYJ-48 型号。步进电机用于各种应用，例如 3D 打印机、CNC 机床、机器人技术，甚至常见的家用电器。它们的精确控制允许进行精细的运动，使其成为需要高定位精度的项目的理想选择。

在本项目中，我们将配置 28BYJ-48 步进电机，使其以不同速度顺时针和逆时针旋转。这类步进电机通常用于自动化系统中，用于旋转物体或驱动需要精确控制的机构。例如，它们可用于自动窗帘，窗帘在特定时间或特定条件下打开或关闭。通过了解如何控制步进电机的旋转和速度，您将能够将它们整合到自己的电子项目中。

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_stepper_motor`
        - |link_stepper_motor_buy|
    *   - :ref:`cpn_power`
        - \-


接线
----------------------

.. warning::
    由于步进电机功耗较高，建议使用外部 5V 电源，而不是依赖 Arduino 供电。

    虽然可以直接从 Arduino 为步进电机供电，但不建议这样做，因为它会在电源线上产生电气噪声，可能导致 Arduino 损坏。

.. note::
    为了保护 :ref:`cpn_power` 的电池，首次使用前请将其充满电。

.. image:: img/26-stepper_motor_bb.png
    :align: center


原理图
-----------------------

.. image:: img/26_stepper_motor_schematic.png
   :align: center
   :width: 80%


代码
---------------

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\26-stepper_motor`` 下的 ``26-stepper_motor.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. literalinclude:: /_code/26_basic_stepper_motor.ino
   :language: cpp
   :linenos:
   :caption: 26-stepper_motor.ino

将代码上传到 Arduino Uno 板后，28BYJ-48 步进电机将在 ULN2003 驱动器的驱动下开始旋转。首先，电机将以 5 RPM（每分钟转数）的速度顺时针旋转一整圈。完成顺时针旋转后，电机将暂停 1 秒。

随后，电机将以 15 RPM 的较高速度逆时针旋转另一整圈。逆时针旋转后，电机将再次暂停 1 秒。只要 Arduino 保持通电，旋转和暂停循环将无限期地持续下去。



代码分析
-----------------

1. **初始化步进电机**

   .. code-block:: arduino

       #include <Stepper.h>  // 包含 Stepper 库

       #define STEPS 2038                   // 定义电机每转的步数
       Stepper stepper(STEPS, 2, 3, 4, 5);  // 初始化步进电机对象并设置引脚连接 (IN1, IN3, IN2, IN4)

   包含头文件 ``Stepper.h``，设置步数为 2038，然后使用 stepper() 函数初始化步进电机。

   ``STEPS``：电机转一圈的步数。对于此步进电机，此值为 2038。

   ``Stepper(steps, pin1, pin2, pin3, pin4)``：此函数创建一个新的 Stepper 类实例，代表连接到 Arduino 板的特定步进电机。引脚 pin1、pin2、pin3 和 pin4 对应于 ULN2003 驱动器上的 IN1、IN3、IN2 和 IN4 引脚。


2. **loop() 函数**

   .. code-block:: arduino

      void loop() {
        // 以 5 RPM 顺时针旋转
        stepper.setSpeed(5);
        stepper.step(STEPS);  // 顺时针旋转一整圈
        delay(1000);          // 等待 1 秒

        // 以 15 RPM 逆时针旋转
        stepper.setSpeed(15);
        stepper.step(-STEPS);  // 逆时针旋转一整圈
        delay(1000);           // 等待 1 秒
      }

   主程序使步进电机持续旋转，以 5 RPM 完成一整圈顺时针旋转，然后以 15 RPM 完成一整圈逆时针旋转。


   - ``setSpeed(rpms)``：设置电机速度，单位为每分钟转数（RPM）。此函数不会使电机转动，只是设置在调用 step() 时的旋转速度。

     - ``rpms``：电机旋转速度，以每分钟转数为单位 - 正数（long）

   .. raw:: html

        <br/>


   - ``step(steps)``：此函数使用最近一次调用 setSpeed() 时设置的速度，将电机旋转指定的步数。需要注意的是，此函数以阻塞方式运行，意味着它将等待电机完成运动后，才允许控制权传递到草图中的下一行。

     例如，如果您将速度设置为 1 RPM 并在具有 2038 步的电机上调用 step(2038)，则此函数将需要整整一分钟才能执行完毕。要实现更精确的控制，建议保持较高的速度，并且在每次调用 step() 时只移动几步。

     - ``steps``：要使电机旋转的步数 - 正数表示向一个方向旋转，负数表示向相反方向旋转 (int)。
