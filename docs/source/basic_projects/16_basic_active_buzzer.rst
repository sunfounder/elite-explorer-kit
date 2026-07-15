.. _basic_active_buzzer:

有源蜂鸣器
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_active_buzzer.html#ar-beep

概述
---------------

有源蜂鸣器是一种典型的数字输出设备，使用起来和点亮 LED 一样简单！

本套件包含两种类型的蜂鸣器。我们需要使用有源蜂鸣器。将它们翻过来，背面密封（不是裸露的 PCB）的那个就是我们需要的。

.. image:: img/16_buzzer.png
    :align: center
    :width: 70%

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
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_buzzer`
        - \-

接线
----------------------

.. note::
    连接蜂鸣器时，请务必检查其引脚。较长的引脚是阳极，较短的是阴极。不要弄反，否则蜂鸣器不会发出声音。

.. image:: img/16-active_buzzer_bb.png
    :align: center
    :width: 70%

原理图
-----------------------

.. image:: img/16_active_buzzer_schematic.png
    :align: center
    :width: 80%

代码
---------------

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\16-active_buzzer`` 下的 ``16-active_buzzer.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. literalinclude:: /_code/16_basic_active_buzzer.ino
   :language: cpp
   :linenos:
   :caption: 16-active_buzzer.ino

代码成功上传后，您将每秒听到一声蜂鸣。
