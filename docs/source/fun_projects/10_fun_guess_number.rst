.. _fun_guess_number:

游戏 - 猜数字
============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/10_fun_guess_game.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

猜数字是一种有趣的聚会游戏，您和您的朋友轮流输入一个数字（0~99）。
每次输入数字后，范围会缩小，直到有玩家猜中答案。
猜中的玩家被宣布为输家并接受惩罚。
例如，如果秘密数字是 51（玩家看不到），玩家 1 输入 50，
数字范围提示变为 50~99。如果玩家 2 输入 70，数字范围变为 50~70。
如果玩家 3 输入 51，那么他就是那个不幸的人。
在这个游戏中，我们使用红外遥控器输入数字，并使用 LCD 显示结果。

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
    *   - :ref:`cpn_ir_receiver`
        - |link_receiver_buy|



**接线**

.. image:: img/10_guess_number_bb.png
    :width: 90%
    :align: center


**原理图**

.. image:: img/10_guess_number_schematic.png
   :width: 100%
   :align: center

**代码**

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\fun_project\10_guess_number`` 下的 ``10_guess_number.ino`` 文件。
    * 或者将这段代码复制到 Arduino IDE 中。

.. note::
   要安装库，请使用 Arduino 库管理器搜索 **"IRremote" ** 和 **"LiquidCrystal I2C"** 并安装它们。

.. literalinclude:: /_code/10_fun_guess_number.ino
   :language: cpp
   :linenos:
   :caption: 10_guess_number.ino



**工作原理**

1. 库导入和全局变量定义：

   导入了三个库：``Wire`` 用于 I2C 通信，``LiquidCrystal_I2C`` 用于控制 LCD 显示，以及 ``IRremote`` 用于接收来自红外遥控器的信号。
   定义了几个全局变量来存储游戏的状态和设置。

2. ``setup()``

   初始化 LCD 显示屏并打开背光。
   以 9600 的波特率初始化串行通信。
   启动红外接收器。
   调用 ``initNewValue()`` 函数设置初始游戏状态。

3. ``loop()``

   检查是否从红外遥控器接收到信号。
   解码接收到的红外信号。
   根据解码后的值（数字或命令）更新游戏状态或执行相应的操作。

4. ``initNewValue()``

   使用 ``analogRead`` 初始化随机数种子，确保每次生成不同的随机数。
   在 0 到 98 之间生成一个随机数作为幸运数字（玩家需要猜的数字）。
   重置上下限提示。
   在 LCD 上显示欢迎消息。
   重置输入的数字。

5. ``detectPoint()``

   检查玩家输入的数字与幸运数字之间的关系。
   如果输入的数字大于幸运数字，则更新上限提示。
   如果输入的数字小于幸运数字，则更新下限提示。
   如果玩家输入了正确的数字，则重置输入并返回 true。

6. ``lcdShowInput()``

   在 LCD 上显示玩家的输入以及当前的上下限提示。
   如果玩家猜对了，则显示成功消息并暂停 5 秒钟，然后重新开始游戏。
