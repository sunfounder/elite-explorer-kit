.. _basic_oled:

OLED
==========================

.. https://docs.sunfounder.com/projects/ultimate-sensor-kit/en/latest/components_basic/22-component_oled.html

概述
---------------

在本课中，您将了解使用 SSD1306 驱动的 OLED 显示屏。OLED（有机发光二极管）显示屏广泛应用于各种电子设备，如智能手表、手机，甚至电视机。SSD1306 是一款单芯片 CMOS OLED/PLED 驱动器，带有控制器，适用于有机/聚合物发光二极管点阵图形显示系统。它通过有机材料制成的二极管（当电流通过时会发光）提供清晰锐利的视觉输出。

在提供的代码中，OLED 显示屏通过 I2C 协议与 Arduino 板连接。代码使用 Adafruit SSD1306 库来控制显示屏。该程序涵盖了各种功能，例如：

1. 显示文本：在屏幕上打印 "Hello world!"。
2. 反转文本：以反转颜色方案显示 "Hello world!"。
3. 字体大小：以增大的字体大小显示 "Hello!"。
4. 数字显示：显示数字 123456789。
5. ASCII 字符：显示一组 ASCII 字符。
6. 滚动：文本在显示屏上水平滚动。
7. 位图显示：在 OLED 屏幕上显示预定义的位图图像。

此 OLED 显示屏可用于多种应用，包括数字时钟、迷你游戏机、信息显示屏等。它为紧凑型便携设备提供用户界面的一种绝佳方式。


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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_oled`
        - |link_oled_buy|

接线
----------------------

.. image:: img/15-oled_bb.png
    :align: center

原理图
-----------------------

.. image:: img/15_oled_schematic.png
    :align: center
    :width: 70%

代码
---------------

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\15-oled`` 下的 ``15-oled.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

    .. note::
      要安装库，请使用 Arduino 库管理器搜索 **"Adafruit SSD1306" ** 和 **"Adafruit GFX"** 并安装。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ec580f40-78b4-42c2-af7c-bb5bc05a7c23/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/15_basic_oled.mp4"  type="video/mp4">
      您的浏览器不支持视频标签。
   </video>

   <br/><br/>


代码分析
------------------------

1. **包含库和初始定义** ：
   包含与 OLED 接口所需的库。然后提供有关 OLED 尺寸和 I2C 地址的定义。

   - **Adafruit SSD1306** ：该库旨在帮助 SSD1306 OLED 显示屏的接口连接。它提供了初始化显示、控制设置和显示内容的方法。
   - **Adafruit GFX 库** ：这是一个核心图形库，用于在包括 OLED 在内的各种屏幕上显示文本、生成颜色、绘制形状等。

   .. note::
      要安装库，请使用 Arduino 库管理器搜索 **"Adafruit SSD1306" ** 和 **"Adafruit GFX"** 并安装。

   .. code-block:: arduino

      #include <SPI.h>
      #include <Wire.h>
      #include <Adafruit_GFX.h>
      #include <Adafruit_SSD1306.h>

      #define SCREEN_WIDTH 128  // OLED 显示宽度，以像素为单位
      #define SCREEN_HEIGHT 64  // OLED 显示高度，以像素为单位

      #define OLED_RESET -1
      #define SCREEN_ADDRESS 0x3C

2. **位图数据** ：
   用于在 OLED 屏幕上显示自定义图标的位图数据。这些数据以 OLED 可以解释的格式表示图像。

   您可以使用名为 |link_image2cpp| 的在线工具将图像转换为数组。

   ``PROGMEM`` 关键字表示该数组存储在 Arduino 微控制器的程序存储器中。将数据存储在程序存储器（PROGMEM）而不是 RAM 中，对于大量数据非常有用，否则这些数据会占用过多的 RAM 空间。

   .. code-block:: arduino

      static const unsigned char PROGMEM sunfounderIcon[] = {...};

3. **设置函数（初始化和显示）** ：
   ``setup()`` 函数初始化 OLED 并显示一系列图案、文本和动画。

   .. code-block:: arduino

      void setup() {
         ...  // 串口初始化和 OLED 对象初始化
         ...  // 显示各种文本、数字和动画
      }
