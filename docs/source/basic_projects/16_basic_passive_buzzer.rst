.. _basic_passive_buzzer:

パッシブブザー
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_tone_notone.html#ar-passive-buzzer

概要
---------------

このプロジェクトでは、パッシブブザーを振動させ、音を発生させるためにこれら2つの関数を使用します。関数 ``tone()`` は、指定された周波数（および50％のデューティサイクル）でピン上に矩形波を生成します。持続時間を指定することもできますし、 ``noTone()`` が呼び出されるまで波が続きます。
アクティブブザーと同様に、パッシブブザーも電磁誘導を利用して動作します。
違いは、パッシブブザーには自身の発振源がないため、直流信号を使用しても音を発することはありません。しかし、これによりパッシブブザーは自身の発振周波数を調整し、"ド、レ、ミ、ファ、ソ、ラ、シ"などの異なる音符を生成できます。

必要なコンポーネント
-------------------------

このプロジェクトには、以下のコンポーネントが必要です。

全セットを購入するのが便利です。こちらがリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名称	
        - このキットのアイテム数
        - リンク
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

以下のリンクから個別に購入することもできます。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - コンポーネント紹介
        - 購入リンク

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


配線図
----------------------

.. note::
    ブザーを接続する際は、ピンを確認してください。長いピンがアノード、短い方がカソードです。逆に接続するとブザーから音が出ないため、間違えないように注意が必要です。

.. image:: img/16-passive_buzzer_bb.png
    :align: center
    :width: 70%

回路図
-----------------------

.. image:: img/16_passive_buzzer_schematic.png
    :align: center
    :width: 80%

コード
---------------

.. note::

    * ファイル ``16-passive_buzzer.ino`` を ``elite-explorer-kit-main\basic_project\16-passive_buzzer`` のパスで直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7936cad2-3605-40a0-a9fc-573f934ab6b1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードをR4ボードにアップロードし終えると、7つの音符を含むメロディーが聞こえます。


コード解析
------------------------

1. pitchesライブラリのインクルード：
   このライブラリは、さまざまな音楽ノートの周波数値を提供し、コード内で音楽記譜法を使用できるようにします。

   .. note::
      正常な動作を確保するために、 ``pitches.h`` ファイルをコードと同じディレクトリに配置してください。 |link_pitches|

      .. image:: img/16_passive_buzzer_piches.png

   .. code-block:: arduino
       
      #include "pitches.h"

2. 定数と配列の定義：

   * ``buzzerPin`` は、ブザーが接続されているArduinoのデジタルピンです。

   * ``melody[]`` は、演奏されるノートのシーケンスを格納する配列です。

   * ``noteDurations[]`` は、メロディーの各ノートの持続時間を格納する配列です。

   .. code-block:: arduino
   
      const int buzzerPin = 8;
      int melody[] = {
        NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
      };
      int noteDurations[] = {
        4, 8, 8, 4, 4, 4, 4, 4
      };

3. メロディーの演奏：

   * ``for`` ループはメロディーの各ノートを反復処理します。

   * ``tone()`` 関数は、特定の期間にわたってブザーでノートを再生します。

   * ノートを区別するために、ノート間に遅延が追加されます。

   * ``noTone()`` 関数は音を停止します。

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

4. 空のループ関数：
   メロディーはセットアップで一度だけ演奏されるため、ループ関数にはコードがありません。

5. ``melody[]`` と ``noteDurations[]`` 配列のノートや持続時間を変更して、独自のメロディーを作成することをお試しください。興味があれば、さまざまな曲を演奏するためのArduinoコードを提供するGitHubリポジトリ（ |link_arduino-songs| ）があります。そのアプローチはこのプロジェクトと異なるかもしれませんが、参考としてノートや持続時間を参照することができます。
