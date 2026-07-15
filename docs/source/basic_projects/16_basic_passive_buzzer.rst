.. _basic_passive_buzzer:

无源蜂鸣器
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_tone_notone.html#ar-passive-buzzer


概述
---------------

在本项目中，使用这两个函数使无源蜂鸣器振动并产生声音。函数 ``tone()`` 在引脚上生成指定频率（和 50% 占空比）的方波。可以指定持续时间，或者波形持续到调用 ``noTone()`` 为止。
与有源蜂鸣器类似，无源蜂鸣器也利用电磁感应原理工作。
不同之处在于，无源蜂鸣器没有自己的振荡源，因此如果使用直流信号，它不会发出声音。然而，这使得无源蜂鸣器可以调整自身的振荡频率，并产生不同的音符，如"do、re、mi、fa、sol、la、ti"。

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|



接线
----------------------

.. note::
    连接蜂鸣器时，请务必检查其引脚。较长的引脚是阳极，较短的是阴极。不要弄反，否则蜂鸣器不会发出声音。

.. image:: img/16-passive_buzzer_bb.png
    :align: center
    :width: 70%

原理图
-----------------------

.. image:: img/16_passive_buzzer_schematic.png
    :align: center
    :width: 80%

代码
---------------

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\16-passive_buzzer`` 下的 ``16-passive_buzzer.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. literalinclude:: /_code/pitches.h
   :language: cpp
   :caption: pitches.h

.. literalinclude:: /_code/16_basic_passive_buzzer.ino
   :language: cpp
   :linenos:
   :caption: 16-passive_buzzer.ino

将代码上传到 R4 板后，您可以听到包含七个音符的旋律。

代码分析
------------------------

1. 包含 pitches 库：
   该库提供了各种音符的频率值，使您可以在代码中使用音符记法。

   .. note::
      请将 ``pitches.h`` 文件放在与代码相同的目录中，以确保正常运行。|link_pitches|

      .. image:: img/16_passive_buzzer_piches.png

   .. code-block:: arduino

      #include "pitches.h"

2. 定义常量和数组：

   * ``buzzerPin`` 是 Arduino 上连接蜂鸣器的数字引脚。

   * ``melody[]`` 是一个存储要播放的音符序列的数组。

   * ``noteDurations[]`` 是一个存储旋律中每个音符时长的数组。

   .. code-block:: arduino

      const int buzzerPin = 8;
      int melody[] = {
        NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
      };
      int noteDurations[] = {
        4, 8, 8, 4, 4, 4, 4, 4
      };

3. 播放旋律：

   * ``for`` 循环遍历旋律中的每个音符。

   * ``tone()`` 函数在蜂鸣器上以特定时长播放一个音符。

   * 在音符之间添加延迟以区分它们。

   * ``noTone()`` 函数停止声音。

   .. code-block:: arduino

      void setup() {
        for (int thisNote = 0; thisNote < 8; thisNote++) {
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(buzzerPin, melody[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(buzzerPin);
        }
      }

4. 空的 loop 函数：
   由于旋律仅在 setup 中播放一次，因此 loop 函数中没有代码。

5. 随意尝试更改 ``melody[]`` 和 ``noteDurations[]`` 数组中的音符和时长，创建您自己的旋律。如果您有兴趣，有一个 GitHub 仓库 (|link_arduino-songs|) 提供了播放各种歌曲的 Arduino 代码。虽然他们的方法可能与此项目不同，但您可以参考他们的音符和时长。
