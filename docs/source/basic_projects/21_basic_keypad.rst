.. _basic_keypad:

键盘
==========================

.. https://docs.sunfounder.com/projects/vincent-kit-de/en/latest/arduino/2.19_keypad.html#ar-keypad

概述
-------------

在本课中，您将学习使用键盘。键盘可应用于各种设备，包括手机、传真机、微波炉等。它常用于用户输入。

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
    *   - :ref:`cpn_keypad`
        - |link_keypad_buy|

接线
----------------------

.. image:: img/21-keypad_bb.png
    :align: center

原理图
----------------------

.. image:: img/21_keypad_schematic.png
   :align: center
   :width: 70%

代码
-----------


.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\21-keypad`` 下的 ``21-keypad.ino`` 文件。
    * 要安装库，请使用 Arduino 库管理器搜索 **"Adafruit Keypad"** 并安装。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/25fd4116-92d4-4ee4-b3ba-6707f4334629/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

将代码上传到 UNO 板后，在串口监视器中，您可以看到键盘上当前按下的键的值。

代码分析
-------------------

1. 包含库

   首先包含 ``Adafruit_Keypad`` 库，这使我们能够轻松地与键盘交互。

   .. code-block:: arduino

     #include "Adafruit_Keypad.h"

   .. note::

      * 要安装库，请使用 Arduino 库管理器搜索 **"Adafruit Keypad"** 并安装。


2. 键盘配置

   .. code-block:: arduino

     const byte ROWS = 4;
     const byte COLS = 4;
     char keys[ROWS][COLS] = {
       { '1', '2', '3', 'A' },
       { '4', '5', '6', 'B' },
       { '7', '8', '9', 'C' },
       { '*', '0', '#', 'D' }
     };
     byte rowPins[ROWS] = { 2, 3, 4, 5 };
     byte colPins[COLS] = { 8, 9, 10, 11 };

   - ``ROWS`` 和 ``COLS`` 常量定义了键盘的尺寸。
   - ``keys`` 是一个二维数组，存储键盘上每个按钮的标签。
   - ``rowPins`` 和 ``colPins`` 是存储连接到键盘行和列的 Arduino 引脚的数组。

   .. raw:: html

      <br/>


3. 初始化键盘

   创建一个名为 ``myKeypad`` 的 ``Adafruit_Keypad`` 实例并初始化它。

   .. code-block:: arduino

     Adafruit_Keypad myKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

4. setup() 函数

   初始化串口通信和自定义键盘。

   .. code-block:: arduino

     void setup() {
       Serial.begin(9600);
       myKeypad.begin();
     }

5. 主循环

   检查按键事件并在串口监视器中显示它们。

   .. code-block:: arduino

     void loop() {
       myKeypad.tick();
       while (myKeypad.available()) {
         keypadEvent e = myKeypad.read();
         Serial.print((char)e.bit.KEY);
         if (e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed");
         else if (e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");
       }
       delay(10);
     }
