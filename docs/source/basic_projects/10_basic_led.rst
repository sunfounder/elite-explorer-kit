.. _basic_led:

LED 模块
==========================

正如打印"Hello, world!"是学习编程的第一步，通过程序驱动 LED 是学习物理编程的传统入门。

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

接线
----------------------

.. image:: img/10-led_bb.png
    :align: center
    :width: 60%


原理图
-----------------------

.. image:: img/10_led_schematic.png
    :align: center
    :width: 80%


代码
---------------

.. note::

   * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\10-led`` 下的 ``10-led.ino`` 文件。
   * 或者将以下代码复制到 **Arduino IDE** 中。

.. literalinclude:: /_code/10_basic_led.ino
   :language: cpp
   :linenos:
   :caption: 10-led.ino

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/10_basic_led.mp4"  type="video/mp4">
      您的浏览器不支持视频标签。
   </video>

代码成功上传后，您将看到连接到 Arduino 板数字引脚 9 的 LED 开始闪烁。LED 将亮起半秒，然后熄灭半秒，随着程序运行不断重复此循环。

代码分析
------------------------

在这里，我们将 LED 连接到数字引脚 9，因此需要在程序开头声明一个名为 ``ledpin`` 的 ``int`` 变量，并赋值为 9。

.. code-block:: arduino

    const int ledPin = 9;


现在，在 ``setup()`` 函数中初始化引脚，需要将引脚初始化为 ``OUTPUT`` 模式。

.. code-block:: arduino

    void setup() {
        pinMode(ledPin, OUTPUT);
    }

在 ``loop()`` 中，使用 ``digitalWrite()`` 为 ledpin 提供 5V 高电平信号，这将使 LED 引脚之间产生电压差，从而点亮 LED。

.. code-block:: arduino

    digitalWrite(ledPin, HIGH);

如果将电平信号改为 LOW，ledPin 的信号将回到 0 V，从而关闭 LED。

.. code-block:: arduino

    digitalWrite(ledPin, LOW);


亮灭之间需要有一个间隔，以便人们看到变化，
因此我们使用 ``delay(1000)`` 代码让控制器暂停 1000 毫秒。

.. code-block:: arduino

    delay(1000);
