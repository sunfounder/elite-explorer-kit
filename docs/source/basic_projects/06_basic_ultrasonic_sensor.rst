.. _basic_ultrasonic_sensor:

超声波传感器
==========================

概述
--------------------

当您倒车时，会看到汽车与周围障碍物之间的距离以避免碰撞。用于检测距离的装置就是超声波传感器。在本实验中，您将学习超声波如何检测距离。

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|


接线
----------------------

.. image:: img/06-ultrasonic_module_bb.png
    :align: center
    :width: 100%

.. raw:: html

    <br/>

原理图
-----------------------

.. image:: img/06_ultrasonic_schematic.png
    :align: center
    :width: 100%


代码
--------

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\06-ultrasonic`` 下的 ``06-ultrasonic.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. literalinclude:: /_code/06_basic_ultrasonic_sensor.ino
   :language: cpp
   :linenos:
   :caption: 06-ultrasonic.ino

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/06_basic_ultrasonic_sensor.mp4"  type="video/mp4">
      您的浏览器不支持视频标签。
   </video>

代码分析
------------------------

**1. 初始化超声波传感器和 LCD1602**

    .. code-block:: arduino

       #include <LiquidCrystal_I2C.h>

       LiquidCrystal_I2C lcd(0x27, 16, 2);  // 初始化 Liquid Crystal Display 对象，I2C 地址为 0x27，16 列 2 行

       // 定义超声波传感器的引脚编号
       const int echoPin = 3;
       const int trigPin = 4;

       void setup() {
         pinMode(echoPin, INPUT);               // 将 echo 引脚设置为输入
         pinMode(trigPin, OUTPUT);              // 将 trig 引脚设置为输出

         lcd.init();       // 初始化 LCD
         lcd.clear();      // 清除 LCD 显示
         lcd.backlight();  // 确保背光亮起

       }

**2. 在 LCD1602 上显示距离**

    .. code-block:: arduino

       void loop() {
         float distance = readDistance();  // 调用函数读取传感器数据并获取距离

         lcd.setCursor(0, 0);         // 将光标置于第 1 行第 1 列。从此处开始显示字符
         lcd.print("Distance:");      // 在 LCD 上打印 Distance:
         lcd.setCursor(0, 1);         // 将光标置于第 1 行第 0 列
         lcd.print("               ");  // 在字符后留出一些空格，以清除可能残留的前一个字符
         lcd.setCursor(7, 1);         // 将光标置于第 1 行第 7 列
         lcd.print(distance);         // 在 LCD 上打印从发送和接收 ping 之间转换的距离值
         lcd.setCursor(14, 1);        // 将光标置于第 1 行第 14 列
         lcd.print("cm");             // 打印单位 "cm"

         delay(800);                       // 延迟 800 毫秒后重复循环
       }

**3. 将时间转换为距离**

    .. code-block:: arduino

        float readDistance(){// ...}

    这里，"PING" 指的是超声波传感器发送超声波脉冲（或 "ping"）然后等待其回波的过程。

    PING 由一个 2 微秒或更长的高电平脉冲触发（先给出一个短暂的低电平脉冲以确保干净的高电平脉冲）。

    .. code-block:: arduino

        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

    echo 引脚用于读取 PING 信号，一个高电平脉冲，其持续时间是从发送 ping 到接收到物体回波的时间（以微秒为单位）。我们使用以下函数获取持续时间。

    .. code-block:: arduino

        pulseIn(echoPin, HIGH);

    声速为 340 m/s，即每厘米 29 微秒。

    这给出了 ping 传播的距离，包括去程和回程，因此我们除以 2 来得到障碍物的距离。

    .. code-block:: arduino

        float distance = pulseIn(echoPin, HIGH) / 29.00 / 2;     // 公式：(340m/s * 1us) / 2
