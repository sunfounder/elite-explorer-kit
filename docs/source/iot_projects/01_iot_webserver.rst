简单网页服务器
===========================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/new_feature_projects/wifi.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

这个简单的 Arduino 程序旨在创建一个基本的 WiFi 网页服务器，允许用户通过网络浏览器控制 Arduino 板上 LED 的开关状态。

**运行代码**

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\iot_project\01_simple_webserver`` 下的 ``01_simple_webserver.ino`` 文件。
    * 或者将这段代码复制到 Arduino IDE 中。

.. note::
    在代码中，SSID 和密码存储在 ``arduino_secrets.h`` 中。上传此示例之前，您需要使用自己的 WiFi 凭据修改它们。此外，出于安全目的，在共享或存储代码时请确保此信息保密。

.. literalinclude:: /_code/01_iot_webserver_secrets.h
   :language: cpp
   :caption: arduino_secrets.h

.. literalinclude:: /_code/01_iot_webserver.ino
   :language: cpp
   :linenos:
   :caption: 01_simple_webserver.ino


上传代码后，您将在串口监视器中看到 IP 地址。您可以在网络浏览器中输入此 IP 地址来打开/关闭板载 LED。

.. image:: img/01_webserver.png

**工作原理**

以下是代码的说明：

1. 头文件和全局变量：

   * ``#include "WiFiS3.h"``：这包含了用于连接和管理 WiFi 的 WiFi 库。该库包含在 Arduino UNO R4 Core 中，因此无需额外安装。
   * ``#include "arduino_secrets.h"``：这包含了敏感的 WiFi 连接数据，如 SSID 和密码。
   * ``ssid``、``pass``、``keyIndex``：这些是用于 WiFi 连接的网络凭据。
   * ``led``、``status``、``server``：这些定义了 LED 引脚、WiFi 状态和网页服务器对象。

2. ``setup()``：

   * 开始串行通信。
   * 检查 WiFi 模块是否存在。
   * 检查 WiFi 模块的固件版本是否为最新。
   * 尝试连接到 WiFi 网络。
   * 启动网页服务器。
   * 打印 WiFi 状态。

3. ``loop()``：

   * 检查新的网页客户端连接。
   * 如果有客户端连接，读取其传入的 HTTP 请求。
   * 根据请求，您可以控制 LED 的开关状态。例如，如果请求是 "GET /H"，则打开 LED；如果是 "GET /L"，则关闭 LED。
   * 发送 HTTP 响应以指导用户如何控制 LED。
   * 断开客户端连接。

4. ``printWifiStatus()``：

   * 打印已连接的 WiFi SSID。
   * 打印 Arduino 板的 IP 地址。
   * 打印接收到的信号强度。
   * 说明如何在网络浏览器中查看此页面。
