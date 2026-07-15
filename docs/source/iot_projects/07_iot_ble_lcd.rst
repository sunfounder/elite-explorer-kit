.. _iot_Bluetooth_lcd:

蓝牙消息盒子
=============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/07_iot_ble_lcd.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

此项目接收消息并在 LCD 屏幕上显示。

您可以将其用作家庭留言板，提醒尚未出门的家人记得带钥匙。

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

**接线**

.. image:: img/07_lightblue_lcd_bb.png
    :width: 100%
    :align: center

**原理图**

.. image:: img/07_lightblue_lcd_schematic.png
   :width: 80%
   :align: center

.. raw:: html

   <br/>

**生成 UUID**

UUID 在 BLE 通信中起着至关重要的作用，确保设备的唯一性和它们之间数据交换的准确性。您需要自定义 UUID 来创建自己的 BLE 服务和特性，以满足特定的应用需求。（这里，我们需要创建一个支持文本输入的特性。）

1. 使用 `在线 UUID 生成器工具 <https://www.uuidgenerator.net/version4>`_ 创建您独有的 UUID，以避免 UUID 冲突。

2. 生成两个版本 4 的 UUID。

   .. image:: img/07_uuid_1.png
      :width: 70%

   .. raw:: html

      <br/><br/>

3. 复制它们并替换代码中的两个 UUID。

   .. code-block:: arduino

       #define SERVICE_UUID "uuid1"
       #define CHARACTERISTIC_UUID "uuid2"

**安装库**

``ArduinoBLE.h``：用于处理低功耗蓝牙 (BLE) 通信。
``LiquidCrystal_I2C.h``：用于控制带有 I2C 接口的 16x2 字符 LCD 屏幕。

**运行代码**

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\iot_project\07_lightblue_lcd`` 下的 ``07_lightblue_lcd.ino`` 文件。
    * 或者将这段代码复制到 Arduino IDE 中。

.. note::
     要安装库，请使用 Arduino 库管理器搜索并安装 **"ArduinoBLE" ** 和 **"LiquidCrystal I2C"** 。

.. literalinclude:: /_code/07_iot_ble_lcd.ino
   :language: cpp
   :linenos:
   :caption: 07_lightblue_lcd.ino


**如何操作？**

要与本 sketch 中创建的服务和特性进行交互，您应使用通用的蓝牙低功耗中心应用程序，如 LightBlue（适用于 iOS 和 Android）或 nRF Connect（适用于 Android）。

让我们以 LightBlue 为例，演示如何通过蓝牙控制 Arduino 的 LED。

1. 从 App Store（iOS）或 Google Play（Android）下载 LightBlue 应用程序。

   .. image:: img/07_lightblue.png

2. 通过蓝牙将 Arduino 与智能手机连接

   转到蓝牙设置，找到名为 "UNO R4 BLE" 的设备。连接到它。

   .. image:: img/07_iot_ble_01.jpg
      :width: 50%

   .. raw:: html

      <br/><br/>

3. 使用 LightBlue 通过蓝牙与 Arduino 交互

   启动 LightBlue，点击界面底部的 **Bonded ** 选项卡。在这里，您将看到智能手机之前配对过的 BLE 设备列表。找到 **UNO R4 BLE ** 并点击 **CONNECT** 。

   .. image:: img/07_iot_ble_02.jpg

   连接后，您将能够访问蓝牙设备的详细信息。向下滚动找到您的服务 UUID 和您的特性 UUID。

   点击该特性。您会注意到该特性既可读又可写，允许您对其进行读写。

   继续滚动到 "Data format" 部分，将其更改为 UTF-8 String。
   在文本框中输入文本并点击 write。您输入的消息将出现在 LCD 上。

   .. image:: img/07_iot_ble_03.jpg

**工作原理**

以下是代码的主要部分及其功能说明：

1. 包含所需的库：

   * ``ArduinoBLE.h``：用于处理 BLE 通信。
   * ``Wire.h``：用于 I2C 通信。
   * ``LiquidCrystal_I2C.h``：用于控制带有 I2C 接口的 16x2 字符 LCD 屏幕。

2. 定义一个 BLE 服务和一个 BLE 特性：

   * 使用 ``BLEService`` 类定义一个 BLE 服务，并为其分配一个唯一的 UUID。
   * 使用 ``BLECharacteristic`` 类定义一个 BLE 特性，为其分配一个唯一的 UUID，并赋予读（``BLERead``）和写（``BLEWrite``）权限。
   * 创建一个字符数组 ``stringValue`` 作为特性的初始值。

3. 初始化一个 16x2 字符 LCD 屏幕 (LCD)：

   * 使用 ``LiquidCrystal_I2C`` 类初始化一个 LCD，指定 I2C 地址 (0x27) 以及行数和列数 (16x2)。
   * 打开 LCD 的背光，清屏，将光标移动到第一行的起始位置，并显示 "Bluetooth LCD"。

4. 在 ``setup()`` 函数中执行初始化：

   * 初始化串行通信。
   * 初始化 BLE 模块，如果初始化失败，则进入一个无限循环。
   * 设置 BLE 外设的本地名称和服务 UUID。
   * 将 BLE 特性添加到 BLE 服务中。
   * 开始广播 BLE 服务，以便中心设备可以发现并连接到它。
   * 初始化 LCD。

5. ``loop()`` 函数：

   * 通过调用 ``BLE.central()`` 检查是否有中心设备连接到 BLE 外设。如果有中心设备连接，则进入连接处理逻辑。
   * 在连接状态下，通过检查 ``boxCharacteristic.written()`` 来检查是否已向 BLE 特性写入数据。
   * 如果已写入数据，使用 ``boxCharacteristic.valueLength()`` 获取写入数据的长度，并创建一个字节数组 ``buffer`` 来存储写入的数据。
   * 使用 ``boxCharacteristic.readValue()`` 将 BLE 特性中的数据读取到 ``buffer`` 中。
   * 在 ``buffer`` 的末尾添加一个空字符 ``'\0'``，将其转换为字符串。
   * 将接收到的消息打印到串口监视器，并在 LCD 上显示。
   * 在中心设备断开连接后，继续等待下一个中心设备连接。
