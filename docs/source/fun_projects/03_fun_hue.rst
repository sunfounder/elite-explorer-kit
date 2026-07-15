.. _fun_hue:

HueDial 调色器
========================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/03_fun_huedial.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

此示例根据旋转电位器的位置控制 RGB LED 的颜色。
电位器的不同位置对应不同的 HUE 值，然后这些值被转换为 RGB 颜色值，从而使 RGB LED 改变颜色。

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_rgb_led`
        - |link_rgb_led_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**接线**

.. image:: img/03_hue_dial_bb.png
    :width: 70%
    :align: center

.. raw:: html

   <br/>

**原理图**

.. image:: img/03_hue_schematic.png
   :width: 80%
   :align: center


**代码**

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\fun_project\03_huedial`` 下的 ``03_huedial.ino`` 文件。
    * 或者将这段代码复制到 Arduino IDE 中。

.. literalinclude:: /_code/03_fun_hue.ino
   :language: cpp
   :linenos:
   :caption: 03_HueDial.ino

**工作原理**

以下是代码的详细说明：

1. 全局变量定义：

   ``redPin``、``greenPin`` 和 ``bluePin``：这些定义了连接到红色、绿色和蓝色 LED 的 PWM 引脚。
   ``KNOB_PIN``：定义连接到旋转电位器的模拟输入引脚。

2. ``setup()``：

   将 RGB LED 的引脚设置为输出。
   默认情况下，模拟引脚被设置为输入，因此无需设置电位器引脚的输入模式。

3. ``loop()``：

   读取旋转电位器的值。该值的范围是 0 到 1023。
   将电位器的值归一化到 0-1 的范围。
   将归一化后的值转换为 0-360 范围的 HUE 值。
   将 HUE 值转换为 RGB 值。
   使用这些 RGB 值更新 LED 的颜色。

4. ``setColor()``：

   使用 ``analogWrite()`` 函数为每个 LED 引脚设置适当的 PWM 值，以设置 RGB LED 的颜色。

5. ``HUEtoRGB()``：

   此函数使用 HSL 到 RGB 的转换方法将 HUE 值转换为 RGB 值，但仅关注 HUE 分量，将饱和度和亮度保持在 100%。
   该算法分为 6 个阶段，每个阶段覆盖 60 度。
   它为每个 HUE 阶段计算 RGB 值，然后将这些值缩放到 0-255 的范围，这是 ``analogWrite()`` 函数所期望的范围。
