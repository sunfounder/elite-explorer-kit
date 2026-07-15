.. _basic_relay:

继电器
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/relay_uno.html#relay-uno


概述
---------------

众所周知，继电器是一种设备，用于根据施加的输入信号在两个或多个点或设备之间建立连接。换句话说，继电器在控制器和设备之间提供隔离，因为设备可能使用交流电或直流电工作。然而，它们从微控制器接收信号，而微控制器使用直流电工作，因此需要继电器来桥接这一差距。当您需要用微小的电信号控制大电流或高电压时，继电器非常有用。

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
    *   - :ref:`cpn_realy`
        - |link_realy_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_diode`
        - |link_diode_buy|

接线
----------------------

.. image:: img/28-relay_bb.png
    :align: center
    :width: 90%

原理图
-----------------------

在 SunFounder Uno 板的引脚 8 上连接一个 1K 电阻（用于在晶体管导通时限制电流），然后连接到一个 NPN 晶体管，其集电极连接到继电器线圈，发射极连接到 GND；将继电器的常开触点连接到一个 LED，然后连接到 GND。因此，当引脚 8 给出高电平时，晶体管导通，从而使继电器线圈导通。然后其常开触点闭合，LED 将点亮。当引脚 8 给出低电平时，LED 将保持熄灭。

.. image:: img/28_relay_schematic.png


**续流二极管的作用** ：当电压输入从高（5V）变为低（0V）时，晶体管从饱和状态（三种工作状态：放大、饱和、截止）变为截止状态，线圈中的电流突然无处可流。此时，如果没有续流二极管，线圈两端将产生反电动势（EMF），底部为正，顶部为负，电压高于 100V。该电压加上电源在晶体管上的电压足以烧毁它。因此，续流二极管极为重要，它可以使该反电动势沿上图中箭头方向放电，从而使晶体管到 GND 的电压不高于 +5V（+0.7V）。

在本实验中，当继电器闭合时，LED 将点亮；当继电器断开时，LED 将熄灭。


代码
--------

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\28-relay`` 下的 ``28-relay.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. literalinclude:: /_code/28_basic_relay.ino
   :language: cpp
   :linenos:
   :caption: 28-relay.ino


现在，发送高电平信号，继电器将闭合，LED 将点亮；发送低电平信号，继电器将断开，LED 将熄灭。此外，您可以听到由于断开常闭触点和闭合常开触点而产生的嘀嗒声。

代码分析
-----------------

.. code-block:: arduino

   void loop() {
     digitalWrite(relayPin, HIGH);  // 打开继电器
     delay(1000);                   // 等待一秒
     digitalWrite(relayPin, LOW);   // 关闭继电器
     delay(1000);                   // 等待一秒
   }

本实验中的代码很简单。首先，将 relayPin 设置为高电平，连接到继电器的 LED 将点亮。然后将 relayPin 设置为低电平，LED 熄灭。
