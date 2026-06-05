.. _fun_plant_monitor:

植物监测器
============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/08_fun_plant_monitor.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

该项目通过当土壤湿度低于特定阈值时启动水泵来自动给植物浇水。
此外，它还在 LCD 屏幕上显示温度、湿度和土壤湿度，让用户了解植物的生长环境。

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|
    *   - :ref:`cpn_power`
        - \-


**接线**

.. note::
    为了保护 :ref:`cpn_power` 的电池，首次使用前请将其充满电。

.. image:: img/08_plant_monitor_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**原理图**

.. image:: img/08_plant_monitor_schematic.png
   :width: 100%
   :align: center

.. raw:: html

   <br/>

**代码**

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\fun_project\08_plant_monitor`` 下的 ``08_plant_monitor.ino`` 文件。
    * 或者将这段代码复制到 Arduino IDE 中。

.. note::
   要安装库，请使用 Arduino 库管理器搜索 **"DHT sensor library" ** 和 **"LiquidCrystal I2C"** 并安装它们。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/a9d6c9c7-0d7f-4dc2-84b6-9dbda15c89ae/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**工作原理**

以下是代码的详细说明：

1. 库包含和常量/变量：

   导入 ``Wire.h``、``LiquidCrystal_I2C.h`` 和 ``DHT.h`` 库。
   定义与 DHT11、土壤湿度传感器和水泵相关的引脚编号和其他参数。

2. ``setup()``：

   初始化与土壤湿度传感器和水泵相关的引脚模式。
   初始关闭水泵。
   初始化 LCD 显示屏并打开背光。
   启动 DHT 传感器。

3. ``loop()``：

   从 DHT 传感器读取湿度和温度。
   从土壤湿度传感器读取土壤湿度。
   在 LCD 屏幕上显示温度和湿度值，然后清屏并显示土壤湿度值。
   根据土壤湿度决定是否启动水泵。如果土壤湿度低于 500（可配置阈值），则启动水泵 1 秒钟。
