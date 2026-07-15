.. _iot_cheerlights:

CheerLights
===============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/05_iot_cheerlights.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

CheerLights 是一个全球性的同步灯光网络，任何人都可以控制它。加入 |link_cheerlights| LED 变色社区，让世界各地的 LED 同时改变颜色。将您的 LED 放在办公室的角落，提醒自己您并不孤单。

在这种情况下，我们也使用 MQTT，但不是发布我们自己的消息，而是订阅 "cheerlights" 主题。这使我们能够接收其他人发送到 "cheerlights" 主题的消息，并使用该信息相应地更改 LED 灯带的颜色。

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**接线**

.. image:: img/05_cheerlight_bb.png
    :width: 100%
    :align: center

**原理图**

.. image:: img/05_cheerlight_schematic.png
    :width: 50%
    :align: center

.. raw:: html

   <br/>

**安装库**

要安装库，请使用 Arduino 库管理器搜索 "ArduinoMqttClient" 和 "FastLED" 并安装它们。

``ArduinoMqttClient.h``：用于 MQTT 通信。

``FastLED.h``：用于驱动 RGB LED 灯带。

.. important::
    随着 |link_fastled_3_7_0| 的发布，FastLED 库现已正式支持 Arduino UNO R4。因此，您不再需要手动安装开发版本。只需使用 Arduino 库管理器更新或安装 FastLED 库即可。

.. warning::
    **[已过时]** 由于 |link_FastLED_lib| 库尚未正式发布支持 Arduino R4 的版本，您需要下载 :download:`FastLED 库最新的开发代码 <https://codeload.github.com/FastLED/FastLED/zip/refs/heads/master>` 并覆盖现有的 FastLED 库文件。有关如何执行此操作的详细说明，请参阅 :ref:`manual_install_lib` 部分。（当 FastLED 库正式发布支持 Arduino UNO R4 的更新时，此说明将被删除。）

**运行代码**


.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\iot_project\05_cheerlight`` 下的 ``05_cheerlight.ino`` 文件。
    * 或者将这段代码复制到 Arduino IDE 中。

.. note::
    在代码中，SSID 和密码存储在 ``arduino_secrets.h`` 中。上传此示例之前，您需要使用自己的 WiFi 凭据修改它们。此外，出于安全目的，在共享或存储代码时请确保此信息保密。

.. literalinclude:: /_code/05_iot_cheerlights_secrets.h
   :language: cpp
   :caption: arduino_secrets.h

.. literalinclude:: /_code/05_iot_cheerlights.ino
   :language: cpp
   :linenos:
   :caption: 05_cheerlight.ino




**控制全球 @CheerLights 设备**

#. 加入 |link_discord_server| 并使用 CheerLights 机器人设置颜色。只需在 **CheerLights Discord Server** 的任何频道中输入 ``/cheerlights`` 即可激活机器人。

   .. image:: img/05_iot_cheerlights_1.png

#. 按照机器人提供的说明设置颜色。这将使您能够全局控制 CheerLights 设备。

   .. image:: img/05_iot_cheerlights_2.png

**工作原理**

以下是代码的主要部分及其功能说明：

1. 包含所需的库：

   * ``WiFiS3.h``：用于处理 Wi-Fi 连接。
   * ``ArduinoMqttClient.h``：用于处理 MQTT 连接。
   * ``FastLED.h``：用于控制 NeoPixel LED 灯带。

2. 定义一些常量：

   * ``NUM_LEDS``：LED 灯带上的 LED 数量。
   * ``DATA_PIN``：连接到 Arduino 用于控制 LED 灯带的数据引脚。
   * ``arduino_secrets.h``：包含 Wi-Fi 网络名称和密码的头文件，以保护敏感信息。
   * ``broker``：MQTT 服务器的地址。
   * ``port``：MQTT 服务器的端口。
   * ``topic``：要订阅的 MQTT 主题。

3. 定义一些全局变量：

   * ``CRGB leds[NUM_LEDS]``：用于存储 LED 颜色数据的数组。
   * ``colorName``：CheerLights 项目支持的颜色名称数组。
   * ``colorRGB``：与颜色名称对应的 RGB 颜色代码数组。

4. ``setup()`` 函数：

   * 初始化串行通信。
   * 检查 Wi-Fi 模块是否存在并输出其固件版本。
   * 尝试连接到 Wi-Fi 网络；如果失败，等待 10 秒后重试。
   * 连接成功后，连接到 MQTT 代理（服务器）并订阅指定的主题。
   * 初始化 NeoPixel LED 灯带。

5. ``loop()`` 函数：

   * 定期调用 ``mqttClient.poll()`` 函数以接收 MQTT 消息并发送 MQTT 保持活动信号。
   * 添加 5 秒延迟以避免持续连接。

6. ``printWifiData()`` 和 ``printCurrentNet()`` 函数用于输出 Wi-Fi 网络和连接信息。

7. ``printMacAddress()`` 函数用于以十六进制格式打印 MAC 地址。

8. ``onMqttMessage()`` 函数是当接收到 MQTT 消息时触发的回调函数。它输出接收到的主题和消息内容，并将消息内容转换为小写。如果主题是 "cheerlights"，则调用 ``setColor()`` 函数设置 LED 灯带颜色。

9. ``setColor()`` 函数接受一个颜色名称作为参数，然后在 ``colorName`` 数组中查找匹配的颜色。如果找到匹配的颜色，则将 LED 灯带的颜色设置为相应的 RGB 值，并使用 ``FastLED.show()`` 函数更新 LED 灯带的颜色。
