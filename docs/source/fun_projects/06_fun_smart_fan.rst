.. _fun_smart_fan:

智能风扇
=================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/06_fun_smartfan.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

这个 Arduino 项目会自动调节风扇速度，以将温度维持在合适的范围内。
此外，用户可以通过按钮进入手动模式，使风扇以最大速度运行。

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_power`
        - \-


**接线**

.. note::
    电机在工作时需要更多电力，因此在使用时请保持电源模块连接到充电电缆。

.. image:: img/06_smart_fan_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**原理图**

.. image:: img/06_smart_fan_schematic.png
   :width: 80%
   :align: center

**代码**

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\fun_project\06_smart_fan`` 下的 ``06_smart_fan.ino`` 文件。
    * 或者将这段代码复制到 Arduino IDE 中。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/ba484912-14d6-4125-83a0-73a107904144/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**工作原理**

以下是代码的逐步说明：

1. 常量和变量定义：

   使用 ``#define`` 定义各种硬件连接的引脚。
   ``TEMP_THRESHOLD`` 定义为 25°C，这是启动风扇的温度阈值。
   ``manualMode``：一个布尔变量，指示是否处于手动模式。

2. ``setup()``：

   设置相关引脚的模式（输出、输入、上拉输入）。
   初始设置为自动模式，因此 ``LED_AUTO`` 点亮，而 ``LED_MANUAL`` 熄灭。

3. ``loop()``：

   监测按钮的状态。当按钮被按下时，切换模式并更改 LED 的状态。
   在手动模式下，风扇以最大速度运行。
   在自动模式下，代码首先读取温度传感器的电压值并将其转换为温度值。
   如果温度超过阈值，则根据温度调整风扇的速度。

4. ``voltageToTemperature()``：

   这是一个辅助函数，用于将温度传感器的电压值转换为温度值（摄氏度）。
   该函数使用热敏电阻的标准公式来估算温度。
   返回值以摄氏度为单位。
