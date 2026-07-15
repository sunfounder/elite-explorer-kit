.. _iot_ble_home:

蓝牙环境监测器
=================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/08_iot_ble_home.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>


该项目使用通过 MIT App Inventor 创建的 Android 应用来接收和显示来自 Arduino 板的环境数据。Arduino 板从 DHT11 传感器获取数据以测量温度和湿度。数据收集完毕后，通过蓝牙传输。应用在接收到数据后将在屏幕上显示。

Android 应用将使用一个名为 |link_appinventor| 的免费网络平台构建。该项目提供了一个很好的机会来熟悉 Arduino 与智能手机的接口连接。

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
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|

**1. 搭建电路**

.. image:: img/08-bluetooth_environmental_monitor_bb.png
    :width: 80%
    :align: center

.. image:: img/08_ble_home_schematic.png
    :width: 30%
    :align: center

.. raw:: html

   <br/>

**2. 创建 Android 应用**

Android 应用将使用一个名为 |link_appinventor| 的免费网络应用程序开发。
MIT App Inventor 是 Android 开发的绝佳起点，因其直观的拖放
功能允许创建简单的应用程序。

现在，让我们开始吧。

#. 访问 |link_appinventor_login| ，点击 "online tool" 登录。您需要一个 Google 帐户来注册 MIT App Inventor。

   .. image:: img/08_ai_signup.png
       :width: 90%
       :align: center

#. 登录后，导航到 **Projects** -> **Import project (.aia) from my computer** 。然后，上传位于路径 ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor`` 下的 ``ble_environmental_monitor.aia`` 文件。

   您也可以直接在此处下载：:download:`ble_environmental_monitor.aia</_static/other/ble_environmental_monitor.aia>`

   .. image:: img/08_ai_import.png
        :align: center

#. 上传 ``.aia`` 文件后，您将在 MIT App Inventor 软件上看到该应用程序。这是一个预配置的模板。您可以在通过以下步骤熟悉 MIT App Inventor 后修改此模板。

#. 在 MIT App Inventor 中，有两个主要部分：**Designer ** 和 **Blocks** 。您可以在页面右上角在这两个部分之间切换。

   .. image:: img/08_ai_intro_1.png

#. **Designer** 允许您添加按钮、文本、屏幕，并修改应用程序的整体外观。

   .. image:: img/08_ai_intro_2.png
      :width: 100%

#. 接下来是 **Blocks** 部分。此部分允许您为应用程序创建自定义功能，您可以为应用程序 GUI 上的每个组件编程以实现所需的功能。

   .. image:: img/08_ai_intro_3.png
      :width: 100%

#. 要在智能手机上安装应用程序，请导航到 **Build** 选项卡。

   .. image:: img/08_ai_intro_4.png

   * 您可以生成一个 ``.apk`` 文件。选择此选项后，将出现一个页面，允许您选择下载 ``.apk`` 文件或扫描二维码进行安装。按照安装指南完成应用程序安装。

     您也可以在此处下载我们预编译的 APK：:download:`ble_environmental_monitor.apk</_static/other/ble_environmental_monitor.apk>`

   * 如果您希望将此应用上传到 Google Play 或其他应用市场，可以生成一个 ``.aab`` 文件。


**3. 上传代码**

#. 打开路径 ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor`` 下的 ``08-bluetooth_environmental_monitor.ino`` 文件，或将此代码复制到 **Arduino IDE** 中。

   .. note::
      要安装库，请使用 Arduino 库管理器搜索并安装 **"DHT sensor library" ** 和 **"ArduinoBLE"** 。

.. literalinclude:: /_code/08_iot_ble_home.ino
   :language: cpp
   :linenos:
   :caption: 08-bluetooth_environmental_monitor.ino

#. 选择正确的板和端口后，点击 **Upload** 按钮。

#. 打开串口监视器（设置波特率为 **9600** ）以查看调试消息。

**4. 应用和蓝牙模块连接**

确保之前创建的应用程序已安装在您的智能手机上。

#. 首先，打开智能手机上的 **Bluetooth** 。

   .. image:: img/08_app_1.png
      :width: 60%
      :align: center

#. 现在打开新安装的 **Environmental Monitor** 应用。

   .. image:: img/08_app_2.png
      :width: 25%
      :align: center

#. 首次打开此应用时，会连续弹出两个授权提示。这些是使用蓝牙所需的权限。

   .. image:: img/08_app_3.png
      :width: 100%
      :align: center

   .. raw:: html

      <br/>

#. 在应用中，点击 **Connect** 按钮以建立应用与蓝牙模块之间的连接。

   .. image:: img/08_app_4.png
      :width: 55%
      :align: center

#. 此页面显示所有已配对的蓝牙设备列表。从列表中选择 ``xx.xx.xx.xx.xx.xx UNO R4 Home`` 选项。每个设备的名称列在其 MAC 地址旁边。

   .. image:: img/08_app_5.png
      :width: 60%
      :align: center

   .. raw:: html

      <br/>

#. 如果在上面显示的页面上没有看到任何设备，您可以尝试打开设备的位置开关（某些 Android 系统版本将位置开关与蓝牙功能捆绑在一起）。

   .. image:: img/08_app_6.png
      :width: 60%
      :align: center

   .. raw:: html

      <br/>

#. 连接成功后，您将被重定向到主页面，该页面将显示温度和湿度。

   .. image:: img/08_app_7.png
      :width: 60%
      :align: center

**5. 代码说明**

1. 导入库和定义常量

   - 导入所需的库并定义 DHT 传感器引脚和类型的常量。

   .. note::
      要安装库，请使用 Arduino 库管理器搜索并安装 **"DHT sensor library" ** 和 **"ArduinoBLE"** 。

   .. code-block:: arduino

       #include <DHT.h>
       #include <ArduinoBLE.h>
       #define DHTPIN 11
       #define DHTTYPE DHT11

2. 初始化 BLE 服务和特性

   - 定义 BLE 环境检测服务和特性的 UUID。我们使用的是由 |link_bluetooth_sig| 提供的预定义 UUID。|link_sig_environmental_sensing| 分配为 ``0x181A``，而 ``0x2A6E`` 和 ``0x2A6F`` 分别保留用于 |link_sig_temperature_humidity| 。

   .. code-block:: arduino

       BLEService environmentalSensingService("181A");
       BLEShortCharacteristic temperatureCharacteristic("2A6E", BLERead | BLENotify);
       BLEUnsignedShortCharacteristic humidityCharacteristic("2A6F", BLERead | BLENotify);

3. 设置函数

   - 初始化串行通信、DHT 传感器和 BLE。

   .. code-block:: arduino

       void setup() {
         Serial.begin(9600);
         dht.begin();
         if (!BLE.begin()) {
           Serial.println("starting Bluetooth® Low Energy module failed!");
           while (1)
             ;
         }
         setupBle();
       }

4. 主循环

   - 轮询 BLE 事件并定期更新传感器数据。

   - ``millis() - lastUpdateTime > updateInterval`` 行确保传感器数据每 updateInterval 毫秒更新一次。

   .. code-block:: arduino

       void loop() {
         BLE.poll();
         if (millis() - lastUpdateTime > updateInterval) {
           // Read sensor data and update BLE characteristics
         }
       }

5. BLE 和调试函数

   用于设置 BLE、打印调试信息和管理 BLE 事件的函数。

   .. code-block:: arduino

       void printDHT(float h, float t) { /* ... */ }
       void setupBle() { /* ... */ }
       void blePeripheralConnectHandler(BLEDevice central) { /* ... */ }
       void blePeripheralDisconnectHandler(BLEDevice central) { /* ... */ }

   - ``printDHT(float h, float t)``：用于在串口监视器上打印 DHT11 读取的温度和湿度数据。此函数用于调试目的。

   - ``setupBle()``：初始化蓝牙，包括设置广播名称、特性和服务。

   - ``blePeripheralConnectHandler(BLEDevice central)`` 和 ``blePeripheralDisconnectHandler(BLEDevice central)``：这些函数处理蓝牙连接或断开连接的事件。当设备通过蓝牙与 UNO R4 成功连接时，板载 LED 点亮。当设备断开连接时，LED 熄灭。
