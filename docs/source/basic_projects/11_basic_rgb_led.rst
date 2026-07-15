.. _basic_rgb_led:

RGB LED
==========================

概述
---------------

在本课中，我们将使用 PWM 控制 RGB LED 闪烁出各种颜色。当向 LED 的 R、G、B 引脚设置不同的 PWM 值时，其亮度会不同。当三种不同颜色混合时，我们可以看到 RGB LED 闪烁出不同的颜色。

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_rgb_led`
        - |link_rgb_led_buy|

PWM
--------

脉冲宽度调制（PWM）是一种用数字方式获得模拟结果的技术。数字控制用于产生方波，即在开和关之间切换的信号。通过改变信号开启时间与关闭时间的比例，这种开-关模式可以模拟在全开（5V）和关（0V）之间的电压。所谓的"开启时间"的持续时间称为脉冲宽度。要获得变化的模拟值，需要改变或调制该宽度。如果以足够快的速度重复这种开-关模式，对于某些设备（例如 LED），效果如下：信号是在 0 到 5V 之间的稳定电压，控制 LED 的亮度。（请参见 Arduino 官方网站上的 PWM 描述）。

在下图中，绿线表示一个常规时间段。该持续时间或周期是 PWM 频率的倒数。换句话说，Arduino 的 PWM 频率约为 500Hz，因此绿线的间隔为 2 毫秒。

.. image:: img/11_rgbled_pwm.jpeg
   :align: center
   :width: 60%


调用 analogWrite() 的范围是 0 - 255，例如 analogWrite(255) 请求 100% 占空比（始终开启），而 analogWrite(127) 是 50% 占空比（一半时间开启）。

您会发现 PWM 值越小，转换为电压后的值就越小，LED 也会相应变暗。因此，我们可以通过控制 PWM 值来控制 LED 的亮度。



接线
----------------------

.. image:: img/11-rgb_led_bb.png
    :align: center
    :width: 70%

原理图
-----------------------

.. image:: img/11-rgb_led_schematic.png
    :align: center
    :width: 80%


代码
---------------

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\11-rgb_led`` 下的 ``11-rgb_led.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. literalinclude:: /_code/11_basic_rgb_led.ino
   :language: cpp
   :linenos:
   :caption: 11-rgb_led.ino

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/11_basic_rgb_led.mp4"  type="video/mp4">
      您的浏览器不支持视频标签。
   </video>

代码成功上传后，您将看到 RGB LED 先以红、绿、蓝循环闪烁，然后按红、橙、黄、绿、蓝、靛、紫的顺序闪烁。

代码分析
--------------------

**设置颜色**

这里使用 ``color()`` 函数来设置 RGB LED 的颜色。代码中设置为闪烁 7 种不同颜色。

您可以使用计算机上的画图工具获取 RGB 值。

1. 打开计算机上的画图工具，点击编辑颜色。

   .. image:: img/11_rgbled_color1.png
      :align: center


2. 选择一种颜色，即可看到该颜色的 RGB 值。将它们填入代码中。

   .. note::
      由于硬件和环境因素，即使使用相同的 RGB 值，在计算机屏幕上和 RGB LED 上显示的颜色可能会有所不同。

   .. image:: img/11_rgbled_color2.png
      :align: center

   .. raw:: html

      <br/>

   .. code-block:: arduino

       void loop() // 不断重复运行

       {

         // 基本颜色：

         color(255, 0, 0); // 将 RGB LED 设为红色

         delay(1000); // 延迟 1 秒

         color(0,255, 0); // 将 RGB LED 设为绿色

         delay(1000); // 延迟 1 秒

         color(0, 0, 255); // 将 RGB LED 设为蓝色

         delay(1000); // 延迟 1 秒

         // 混合颜色示例：

         color(255,0,252); // 将 RGB LED 设为红色

         delay(1000); // 延迟 1 秒

         color(237,109,0); // 将 RGB LED 设为橙色

         delay(1000); // 延迟 1 秒

         color(255,215,0); // 将 RGB LED 设为黄色

         delay(1000); // 延迟 1 秒

         ......


**color() 函数**

.. code-block:: arduino

    void color (int red, int green, int blue)
    // 颜色生成函数

    {

      analogWrite(redPin, red);

      analogWrite(greenPin, green);

      analogWrite(bluePin, blue);

    }

定义三个 unsigned char 变量 red、green 和 blue。将其值写入 ``redPin``、``greenPin`` 和 ``bluePin``。例如，color(128,0,128) 将 128 写入 ``redPin``，0 写入 ``greenPin``，128 写入 ``bluePin``。结果是 LED 闪烁紫色。

**analogWrite()** ：向引脚写入模拟值（PWM 波形）。它与模拟引脚无关，仅用于 PWM 引脚。在调用 ``analogWrite()`` 之前，无需调用 ``pinMode()`` 将引脚设置为输出。
