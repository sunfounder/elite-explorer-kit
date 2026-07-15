.. _new_dac:

数模转换器 (DAC)
========================================

Arduino Uno R4 WiFi 配备了内置 DAC（数模转换器）功能。DAC 对于将数字信号转换为其模拟对应物至关重要，这一功能在音频处理、模拟信号生成以及其他需要精确模拟输出的应用中尤为重要。

Uno R4 WiFi 上的 DAC 拥有高达 12 位的分辨率，提供超越 PWM 引脚的真实模拟输出能力。

.. image:: img/07_dac.png
  :width: 70%

使用 DAC 播放音乐
++++++++++++++++++++

**电路图**

.. image:: img/07_dac_bb.png
  :width: 100%
  :align: center

**上传代码**

打开位于 ``elite-explorer-kit-main\r4_new_feature\07-dac`` 的 ``07-dac.ino`` 文件，或将以下代码粘贴到您的 Arduino IDE 中。

.. note::
    请将 ``pitches.h`` 文件放在与代码相同的目录中，以确保正常运行。

.. literalinclude:: /_code/pitches.h
   :language: cpp
   :caption: pitches.h

.. literalinclude:: /_code/07_dac.ino
   :language: cpp
   :linenos:
   :caption: 07-dac.ino

该项目利用 Arduino 和 DAC（数模转换器）播放标志性的超级马里奥兄弟主题曲。它使用一个名为 ``analogWave`` 的库来生成正弦波，以及另一个库 ``pitches.h`` 来定义音符频率。

- ``melody[]``：此数组包含要播放的音符及其持续时间。音符由预定义音高（例如 ``NOTE_E5``）表示，持续时间以节拍为单位表示（例如，4 表示四分音符）。您可以通过更改 melody[] 数组中的音符和持续时间来尝试编写自己的旋律。如果您有兴趣，GitHub 上有一个仓库（|link_arduino_songs| ），其中提供了用于播放不同歌曲的 Arduino 代码。尽管他们的方法可能与此项目不同，但您可以参考他们的音符和持续时间。（只需将相应曲目中的 ``melody[]`` 替换为此项目中的代码。）

- ``tempo``：此项目的速度设置为 200 BPM（每分钟节拍数），用于计算每个音符的持续时间。修改此值将改变歌曲的演奏速度。

- **正弦波发生器** ：``analogWave`` 库的 ``sine`` 函数初始化一个 10 Hz 的正弦波发生器，用于通过 DAC 输出音符。

- **音符持续时间** ：根据设置的速度和每个音符的节拍数，计算每个音符的持续时间。

- **播放和暂停** ：每个音符播放其计算持续时间的 85%，然后暂停 15% 以区分音符。

- **循环** ：完成旋律后，代码自动重置并重新开始播放。

这是一个演示如何使用 Arduino 和外部硬件（DAC）生成音乐的示例。它还展示了如何使用数组和循环来简化音乐播放的逻辑。


**参考**

- |link_r4_dac|
