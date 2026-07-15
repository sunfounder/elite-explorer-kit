.. _basic_potentiometer:

电位器
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/controlling_an_led_by_potentiometer_uno.html


概述
--------------------

在本课中，让我们看看如何通过电位器改变 LED 的亮度，并在串口监视器中接收电位器的数据以查看其值的变化。

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|



接线
----------------------

.. image:: img/19-potentiometer_bb.png
    :align: center
    :width: 70%

原理图
---------------------------

在本实验中，电位器用作分压器，即将其三个引脚都连接设备。将电位器的中间引脚连接到 A0，另外两个引脚分别连接到 5V 和 GND。因此，电位器的电压为 0-5V。旋转电位器的旋钮，A0 引脚的电压将发生变化。然后通过控制板中的 AD 转换器将该电压转换为数字值（0-1024）。通过编程，我们可以使用转换后的数字值来控制控制板上 LED 的亮度。

.. image:: img/19_potentiometer_schematic.png
   :align: center
   :width: 70%

代码
---------------

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\19-potentiometer`` 下的 ``19-potentiometer.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. literalinclude:: /_code/19_basic_potentiometer.ino
   :language: cpp
   :linenos:
   :caption: 19-potentiometer.ino

将代码上传到 Uno 板后，您可以打开串口监视器观察电位器的读取值。当您旋转电位器旋钮时，读取值将相应变化。来自电位器的原始模拟读数范围为 \(0\) 到 \(1023\)。同时，代码将此值缩放至 \(0\) 到 \(255\) 的范围，该值也会显示在串口监视器上。这个缩放后的值用于控制连接 LED 的亮度。LED 将根据缩放后的值变得更亮或更暗。值得注意的是，虽然电位器的理论范围为 \(0\) 到 \(1023\)，但由于硬件公差，实际范围可能略有不同。

代码分析
---------------

#. 初始化和设置（设置引脚模式并初始化串口通信）

   在进入主循环之前，我们定义使用的引脚并初始化串口通信。

   .. code-block:: arduino

      const int analogPin = 0;  // 连接到电位器的模拟输入引脚
      const int ledPin = 9;     // 连接到 LED 的数字输出引脚

      void setup() {
        Serial.begin(9600);  // 初始化串口通信，波特率为 9600
      }

#. 读取模拟输入（从电位器获取数据）

   在此部分中，我们从电位器读取模拟数据并将其打印到串口监视器。

   .. code-block:: arduino

        inputValue = analogRead(analogPin);  // 读取电位器的模拟值
        Serial.print("Input: ");             // 在串口监视器上打印 "Input: "
        Serial.println(inputValue);          // 在串口监视器上打印原始输入值

#. 映射和缩放（转换电位器数据）

   我们将来自电位器的原始数据（范围为 0-1023）缩放到新的范围 0-255。

   ``map(value, fromLow, fromHigh, toLow, toHigh)`` 用于将数字从一个范围转换到另一个范围。例如，如果值在 ``fromLow`` 和 ``fromHigh`` 范围内，它将被转换为 ``toLow`` 和 ``toHigh`` 范围内的相应值，保持两个范围之间的比例关系。

   在这种情况下，由于 LED 引脚（引脚 9）的范围为 0-255，我们需要将 0-1023 范围内的值映射到相同的 0-255 范围。

   .. code-block:: arduino

      outputValue = map(inputValue, 0, 1023, 0, 255);  // 将输入值映射到新的范围

#. 控制 LED 和串口输出

   最后，我们根据缩放后的值控制 LED 的亮度，并打印缩放后的值以供监视。

   .. code-block:: arduino

      Serial.print("Output: ");                        // 在串口监视器上打印 "Output: "
      Serial.println(outputValue);                     // 在串口监视器上打印缩放后的输出值
      analogWrite(ledPin, outputValue);                // 根据缩放后的值控制 LED 亮度
      delay(1000);
