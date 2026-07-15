.. _basic_humiture_sensor:

温湿度传感器模块
==========================

.. https://docs.sunfounder.com/projects/3in1-kit/en/latest/basic_project/ar_dht11.html#ar-dht11

概述
---------------

湿度和温度从物理量本身到人们的实际生活都密切相关。
人类环境的温度和湿度会直接影响人体的体温调节功能和热传递效果。
这将进一步影响思维活动和精神状态，从而影响我们的学习和工作效率。

温度是国际单位制中七个基本物理量之一，用于衡量物体的冷热程度。
摄氏度是世界上较为常用的温标之一，用符号"℃"表示。

湿度是空气中水蒸气的浓度。
生活中常用相对湿度，以 %RH 表示。相对湿度与温度密切相关。
对于一定体积的密封气体，温度越高，相对湿度越低；温度越低，相对湿度越高。

本套件提供了 dht11 数字温湿度传感器。它使用电容式湿度传感器和热敏电阻来测量周围空气，并在数据引脚上输出数字信号。

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
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|



接线
----------------------

.. image:: img/07-dht11_bb.png
    :align: center

原理图
-----------------------

.. image:: img/07_humiture_schematic.png
    :align: center
    :width: 40%

代码
---------------

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\07-humiture_sensor`` 下的 ``07-humiture_sensor.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. note::
    要安装库，请使用 Arduino 库管理器搜索 **"DHT sensor library"** 并安装。

.. literalinclude:: /_code/07_basic_humiture_sensor.ino
   :language: cpp
   :linenos:
   :caption: 07-humiture_sensor.ino


代码成功上传后，您将看到串口监视器持续打印出温度和湿度，随着程序稳定运行，这两个值将变得越来越准确。

代码分析
------------------------

#. 包含必要的库并定义常量。
   这部分代码包含了 DHT 传感器库，并定义了本项目所使用的引脚编号和传感器类型。

   .. note::
      要安装库，请使用 Arduino 库管理器搜索 **"DHT sensor library"** 并安装。

   .. code-block:: arduino

      #include <DHT.h>
      #define DHTPIN 11       // 定义连接传感器的引脚
      #define DHTTYPE DHT11  // 定义传感器类型

#. 创建 DHT 对象。
   这里我们使用定义的引脚编号和传感器类型创建一个 DHT 对象。

   .. code-block:: arduino

      DHT dht(DHTPIN, DHTTYPE);  // 创建一个 DHT 对象

#. 此函数在 Arduino 启动时执行一次。我们在此函数中初始化串口通信和 DHT 传感器。

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        Serial.println(F("DHT11 test!"));
        dht.begin();  // 初始化 DHT 传感器
      }

#. 主循环。
   ``loop()`` 函数在 setup 函数之后持续运行。在这里，我们读取湿度和温度值，计算炎热指数，并将这些值打印到串口监视器。如果传感器读取失败（返回 NaN），则会打印一条错误消息。

   .. note::

      |link_heat_index| 是一种通过结合空气温度和湿度来衡量户外炎热程度的方法，也称为"体感温度"或"表观温度"。

   .. code-block:: arduino

      void loop() {
        delay(2000);
        float h = dht.readHumidity();
        float t = dht.readTemperature();
        float f = dht.readTemperature(true);
        if (isnan(h) || isnan(t) || isnan(f)) {
          Serial.println(F("Failed to read from DHT sensor!"));
          return;
        }
        float hif = dht.computeHeatIndex(f, h);
        float hic = dht.computeHeatIndex(t, h, false);
        Serial.print(F("Humidity: "));
        Serial.print(h);
        Serial.print(F("%  Temperature: "));
        Serial.print(t);
        Serial.print(F("°C "));
        Serial.print(f);
        Serial.print(F("°F  Heat index: "));
        Serial.print(hic);
        Serial.print(F("°C "));
        Serial.print(hif);
        Serial.println(F("°F"));
      }
