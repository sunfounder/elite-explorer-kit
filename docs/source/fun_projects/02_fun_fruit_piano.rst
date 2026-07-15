.. _fun_fruit_piano:

水果钢琴
========================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/02_fun_fruit_piano.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

这个项目是一个简单的水果钢琴，它通过 MPR121 触摸传感器读取输入，并通过 DAC 播放音乐。换句话说，我们把水果变成了键盘，只需触摸它们就能演奏音乐。

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_mpr121`
        - \-
    *   - :ref:`cpn_audio_speaker`
        - \-


**接线**

.. image:: img/02_fruit_piano_bb.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>


**原理图**

.. image:: img/02_fruit_piano_schematic.png
   :width: 100%

**代码**

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\fun_project\02_fruit_piano`` 下的 ``02_fruit_piano.ino`` 文件。
    * 或者将这段代码复制到 Arduino IDE 中。

.. note::
   要安装库，请使用 Arduino 库管理器搜索 **"Adafruit MPR121"** 并安装。

.. literalinclude:: /_code/pitches.h
   :language: cpp
   :caption: pitches.h

.. literalinclude:: /_code/02_fun_fruit_piano.ino
   :language: cpp
   :linenos:
   :caption: 02_fruit_piano.ino


**工作原理**

以下是代码的逐步说明：

1. 库和对象初始化：

   导入必要的库：``Wire`` 库（用于 I2C 通信）、``Adafruit_MPR121`` 库（用于驱动 MPR121）、``analogWave`` 库（用于生成模拟波形）和 ``pitches.h``（定义音符的频率）。
   创建 ``Adafruit_MPR121`` 和 ``analogWave`` 对象的实例。
   定义一个音符数组，用于存储每个触摸通道对应的音符。

2. ``setup()``：

   初始化串行通信并等待其启动。
   检查并初始化 MPR121；如果未找到，则在串口监视器上打印错误信息并停止执行。
   初始化 ``analogWave`` 对象，并将初始正弦波频率设置为 10Hz。

3. ``loop()``：

   读取 MPR121 当前被触摸的通道。
   遍历所有通道，检查哪个被触摸，并播放相应的音符。
   在每次迭代之间添加一个小延迟。

4. 播放音符 ``playNote()``：

   ``playNote`` 函数接收一个 ``note`` 参数，并设置 DAC 频率以播放相应的音符。
   延迟一段时间以播放音符。
   停止播放音符。
