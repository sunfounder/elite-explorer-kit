.. _basic_pump:

水泵
==========================

概述
---------------

水泵也是一种电机，它通过特殊结构将电机或其他外部能量的机械能转换来输送液体。



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
    *   - :ref:`cpn_pump`
        -
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_power`
        - \-



接线
----------------------

.. note::
    为了保护 :ref:`cpn_power` 的电池，首次使用前请将其充满电。

.. image:: img/25-pump_bb.png
    :align: center
    :width: 80%

.. raw:: html

  <br/>


原理图
-----------------------

.. image:: img/25_pump_schematic.png


代码
---------------

.. note::

   * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\25-pump`` 下的 ``25-pump.ino`` 文件。
   * 或者将以下代码复制到 **Arduino IDE** 中。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8a530528-aa58-4306-acc9-01632ae5e99a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

将管道连接到水泵并放置在水盆中。代码成功上传后，水泵将启动并持续运行五秒钟。
进行本实验时，请确保电路远离水源，以防止任何潜在的短路。


代码分析
--------------------------

通过电机两侧铜片之间的电压差可以驱动电机。

.. code-block:: arduino

   digitalWrite(motorBI, HIGH);
   digitalWrite(motorFI, LOW);
