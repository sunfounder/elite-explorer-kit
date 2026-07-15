.. _new_bluetooth:

蓝牙
========================================

配备 ESP32 模块的 UNO R4 WiFi 板同时提供蓝牙 LE 和蓝牙 5 功能，支持高达 2 Mbps 的速度。ESP32 模块带有集成的天线，无需外部天线即可利用板的连接功能。

.. note::
    ESP32 模块中的天线与蓝牙模块共享，这意味着您不能同时使用蓝牙和 Wi-Fi。

BLE 基本概念
++++++++++++++++++++++++

**低功耗蓝牙 (BLE)** 是一种低功耗无线通信技术，专为短距离交互而设计。与经典蓝牙不同，BLE 侧重于能效和快速连接，使其成为包括物联网 (IoT) 设备和健康监测设备在内的一系列应用的理想选择。

BLE 通信依赖于两个关键协议：**GATT（通用属性协议） ** 和 **GAP（通用访问协议）** 。GATT 用于数据交换，而 GAP 负责设备发现和连接。

.. image:: img/02_ble_relationships.png
 :width: 100%


外设设备（通常是 GATT 服务器）
--------------------------------------------------

在 BLE 网络中，**外设设备** 主要广播数据，以便被中心设备（通常充当 GATT 客户端）发现和访问。这些设备通常是传感器或小型硬件，如心率监测器、温度传感器或智能灯泡。

在 BLE 通信模型中，外设设备通常提供一个或多个 **服务 ** ，每个服务包含一组 **特性** 。这些服务和特性共同实现特定功能或用例，允许中心设备读取或操作相关数据。

- **服务**

  在 BLE 中，服务充当高级抽象，用于组织和封装相关的特性。BLE 中的服务根据其来源和目的可以分为标准服务和自定义服务。

  - 标准服务：由蓝牙 SIG（蓝牙技术联盟）定义，旨在用于特定功能。例如，用于心率监测器的心率服务、提供制造商、型号和版本信息的设备信息服务，以及指示电池电量和状态的电池服务。
  - 自定义服务：由开发者或设备制造商定义，以满足特定应用或设备的需求。例如，智能家居设备制造商可能定义一个自定义服务来控制灯光颜色和亮度。

- **特性**

  BLE 中的特性是外设设备公开的基本数据单元。它们包含在服务中，定义各种类型的数据以及可对其执行的操作。每个特性由一个 UUID 标识，并具有一组相关属性，如值、描述符和权限。

  - 权限：在 BLE 中，每个特性都关联一组权限，用于指示该特性是否可读、可写或可通知。这有助于保护数据并定义如何与数据交互。

- **UUID**

  服务、特性和描述符统称为属性，每个属性都有一个唯一的 UUID。蓝牙 SIG 为标准属性保留了一组 UUID。这些 UUID 在 BLE 协议中通常表示为 16 位或 32 位标识符以提高效率，而不是完整 UUID 所需的 128 位。例如，设备信息服务由短代码 0x180A 表示。



中心设备（通常是 GATT 客户端）
--------------------------------------------------

BLE 网络中的 **中心设备** 扫描附近的外设设备并建立连接以获取或控制数据。这些设备通常更复杂且功能更丰富，例如智能手机、平板电脑或专用网关硬件。它们负责发现外设设备、连接到它们，并访问或订阅外设提供的服务和特性，以服务于各种应用或解决特定问题。

中心设备通过以下方式与特性交互：

- **读取** ：请求外设设备发送特性的当前值。这通常用于不经常变化的特性，如配置设置或版本号。
- **写入** ：修改特性的值，通常用于类似命令的操作，如指示外设设备打开或关闭电机。
- **订阅** ：请求外设设备持续发送特性的更新值，无需中心设备重复请求此数据。



示例：蓝牙控制的 LED
++++++++++++++++++++++++++++++++++++++++++++++++++++++++

在此示例中，Arduino 充当低功耗蓝牙 (BLE) 网络中的外设设备。它提供一个自定义的 BLE 服务，旨在控制板载 LED。此服务包括一个可由中心设备（如智能手机）读写特性。一旦中心设备连接到 Arduino，它就可以通过写入此特性来更改 LED 状态。Arduino 的串口监视器显示调试信息，包括 LED 的当前状态和已连接中心设备的 MAC 地址。

**上传代码**

打开位于 ``elite-explorer-kit-main\r4_new_feature\02-bluetooth`` 的 ``02-bluetooth.ino`` 文件，或将以下代码粘贴到您的 Arduino IDE 中。

.. literalinclude:: /_code/02_bluetooth.ino
   :language: cpp
   :linenos:
   :caption: 02-bluetooth.ino


**通过蓝牙连接 Arduino R4**

要与本 sketch 中创建的服务和特性进行交互，我们应使用通用的低功耗蓝牙中心应用程序，如 LightBlue（适用于 iOS 和 Android）或 nRF Connect（适用于 Android）。

让我们以 LightBlue 为例，演示如何通过蓝牙控制 Arduino 的 LED。

1. 从 |link_lightblue_apple| （iOS）或 |link_lightblue_google| （Android）下载 **LightBlue** 应用程序。

   .. image:: img/02_lightblue.png
    :width: 90%

   .. raw:: html

      <br/><br/>

2. 通过蓝牙将 Arduino 与智能手机连接

   导航到蓝牙设置，找到名为 "UNO R4 LED" 的设备。继续连接到它。

   .. image:: img/02_connect.png
    :width: 90%

   .. raw:: html

      <br/>

3. 使用 LightBlue 通过蓝牙与 Arduino 交互

   启动 LightBlue，点击界面底部的 **Bonded ** 选项卡。在这里，您将看到智能手机之前配对过的 BLE 设备列表。找到 **UNO R4 LED ** 并点击 **CONNECT** 。

   .. image:: img/02_lightblue_1.png
    :width: 90%

   连接后，您将能够访问 "UNO R4 LED" 蓝牙设备的详细信息。向下滚动找到 "ledService (**19B10000-E8F2-537E-4F6C-D104768A1214**)" 和 "switchCharacteristic (**19B10001-E8F2-537E-4F6C-D104768A1214**)"。

   点击 19B10001-E8F2-537E-4F6C-D104768A1214 特性。您会注意到该特性既可读又可写，允许您对其进行读写。

   .. image:: img/02_lightblue_2.png
    :width: 90%

   继续滚动到 **WRITTEN VALUES ** 部分。在文本框中输入 '**1**' 将特性值设置为 1，这将 ** 打开 Arduino R4 的板载 LED**。

   .. image:: img/02_lightblue_3.png
    :width: 90%

   类似地，您可以将此值设置为 '**0**' 来 ** 关闭板载 LED**。

   .. image:: img/02_lightblue_4.png
    :width: 90%



**代码说明**

#. 初始化 BLE 和 LED

   .. note::
      定义服务和特性时，我们需要使用 UUID 来标识它们。为避免 UUID 冲突并方便使用，您可以使用 |link_uuid_gen_tool| 的 UUID 生成工具。

   .. code-block:: arduino

      #include <ArduinoBLE.h>
      BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); // Bluetooth Low Energy LED Service
      BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);
      const int ledPin = LED_BUILTIN; // pin to use for the LED

   - 包含 ArduinoBLE 库。
   - 定义 BLE 服务和特性。
   - 将内置 LED 引脚分配给 ``ledPin``。

   .. raw:: html

      <br/>

#. ``setup()`` 函数

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        while (!Serial);
        pinMode(ledPin, OUTPUT);
        if (!BLE.begin()) {
          Serial.println("starting Bluetooth Low Energy module failed!");
          while (1);
        }
        BLE.setLocalName("UNO R4 LED");
        BLE.setAdvertisedService(ledService);
        ledService.addCharacteristic(switchCharacteristic);
        BLE.addService(ledService);
        switchCharacteristic.writeValue(0);
        BLE.advertise();
        Serial.println("BLE LED Peripheral");
      }

   - 初始化串行通信。
   - 将 LED 引脚设置为输出。
   - 初始化 BLE 并添加服务和特性。
   - 开始 BLE 广播。

   .. raw:: html

      <br/>

#. ``loop()`` 函数

   .. code-block:: arduino

      void loop() {
        BLEDevice central = BLE.central();
        if (central) {
          Serial.print("Connected to central: ");
          Serial.println(central.address());
          while (central.connected()) {
            if (switchCharacteristic.written()) {
              if (switchCharacteristic.value()) {
                Serial.println("LED on");
                digitalWrite(ledPin, HIGH);
              } else {
                Serial.println("LED off");
                digitalWrite(ledPin, LOW);
              }
            }
          }
          Serial.print("Disconnected from central: ");
          Serial.println(central.address());
        }
      }


   - 监听 BLE 中心设备连接。
   - 如果中心设备已连接，读取特性值以控制 LED。如果接收到非 0 值，则打开 LED。如果接收到 0，则关闭 LED。


**参考**

- |link_r4_bluetooth|
