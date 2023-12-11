.. _basic_audio_speaker:

オーディオモジュールとスピーカー
=================================

概要
---------------
このレッスンでは、Arduino Unoボードと一緒に使用されるオーディオモジュールとスピーカーについて学びます。これらのコンポーネントは、音楽玩具、DIYサウンドシステム、アラーム、さらには高度な楽器など、さまざまな電子アプリケーションで広く利用されています。Arduinoとオーディオモジュール、スピーカーを組み合わせることで、シンプルながら効果的なメロディープレーヤーを作成できます。

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
    *   - :ref:`cpn_audio_speaker`
        - \-


配線図
----------------------

これはモノラルアンプなので、ピン8をオーディオアンプモジュールのLまたはRピンに接続できます。

10K抵抗は、高周波ノイズを減少させ、オーディオボリュームを下げるために使用されます。DACとオーディオアンプの寄生容量とのRCローパスフィルタを形成します。このフィルタは高周波信号の振幅を減少させ、高周波ノイズを効果的に減少させます。したがって、10K抵抗を追加すると、音楽が柔らかく聞こえ、望ましくない高周波ノイズが排除されます。

.. image:: img/17-audio_bb.png
    :align: center
    :width: 100%

回路図
-----------------------

.. image:: img/17-audio_schematic.png
    :align: center
    :width: 80%


コード
---------------

.. note::

    * ファイル ``17-speaker.ino`` を ``elite-explorer-kit-main\basic_project\17-speaker`` のパスで直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/33b690b5-0be6-434d-83d7-5bfcfce3775e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
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

   * ``speakerPin`` は、スピーカーが接続されているArduinoのデジタルピンです。

   * ``melody[]`` は、演奏されるノートのシーケンスを格納する配列です。

   * ``noteDurations[]`` は、メロディーの各ノートの持続時間を格納する配列です。

   .. code-block:: arduino
   
      const int speakerPin = 8;
      int melody[] = {
        NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
      };
      int noteDurations[] = {
        4, 8, 8, 4, 4, 4, 4, 4
      };

3. メロディーの演奏：

   * ``for`` ループはメロディーの各ノートを反復処理します。

   * ``tone()`` 関数は、特定の期間にわたってスピーカーでノートを再生します。

   * ノートを区別するために、ノート間に遅延が追加されます。

   * ``noTone()`` 関数は音を停止します。

   .. code-block:: arduino
   
      void setup() {
        for (int thisNote = 0; thisNote < 8; thisNote++) {
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(speakerPin, melody[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(speakerPin);
        }
      }

4. 空のループ関数：
   メロディーはセットアップで一度だけ演奏されるため、ループ関数にはコードがありません。

5. ``melody[]`` と ``noteDurations[]`` 配列のノートや持続時間を変更して、独自のメロディーを作成することをお試しください。興味があれば、さまざまな曲を演奏するためのArduinoコードを提供するGitHubリポジトリ（ |link_arduino-songs| ）があります。そのアプローチはこのプロジェクトと異なるかもしれませんが、参考としてノートや持続時間を参照することができます。
