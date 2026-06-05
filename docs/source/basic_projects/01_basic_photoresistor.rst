.. _basic_photoresistor:

光敏电阻
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.26_photoresistor.html

概述
---------------

在本课中，您将了解光敏电阻。光敏电阻广泛应用于许多电子产品中，例如相机测光表、时钟收音机、报警装置（作为光束探测器）、小型夜灯、户外时钟、太阳能路灯等。光敏电阻被放置在路灯中，用于控制灯的开启和关闭。环境光线照射到光敏电阻上，使路灯开启或关闭。

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

接线
----------------------

在本示例中，我们使用模拟引脚（A0）读取光敏电阻的值。光敏电阻的一个引脚连接到5V，另一个引脚连接到A0。此外，另一个引脚在连接到GND之前需要串联一个10kΩ电阻。

.. image:: img/01-photoresistor_bb.png
    :align: center
    :width: 80%

原理图
-----------------------

.. image:: img/01_photoresistor_schematic.png
    :align: center
    :width: 70%

代码
---------------

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\01-photoresistor`` 下的 ``01-photoresistor`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。



.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e6bf007e-b20d-44d0-9ef9-6d57c1ce4c3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

将代码上传到 Uno 板后，您可以打开串口监视器查看引脚的读取值。当环境光线变强时，读数会相应增加，引脚读数范围为「0」~「1023」。但根据环境条件和光敏电阻的特性，实际读数范围可能会小于理论范围。
