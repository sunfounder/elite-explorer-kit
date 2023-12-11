.. _fun_fruit_piano:

フルーツピアノ
========================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/02_fun_fruit_piano.mp4"  type="video/mp4">
      お使いのブラウザではビデオタグがサポートされていません。
   </video>

このプロジェクトは、MPR121タッチセンサーからの入力を読み取り、DACを通じて音楽を再生するシンプルなフルーツピアノです。言い換えれば、フルーツをキーボードに変え、それらに触れるだけで音楽を演奏できるようにしました。

**必要なコンポーネント**

このプロジェクトには以下のコンポーネントが必要です。

全体のキットを購入すると便利です。こちらがリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名称	
        - このキットのアイテム数
        - リンク
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

以下のリンクから別々に購入することもできます。

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
    *   - :ref:`cpn_mpr121`
        - \-
    *   - :ref:`cpn_audio_speaker`
        - \-


**配線図**

.. image:: img/02_fruit_piano_bb.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>


**回路図**

.. image:: img/02_fruit_piano_schematic.png
   :width: 100%

**コード**

.. note::

    * ファイル ``02_fruit_piano.ino`` を ``elite-explorer-kit-main\fun_project\02_fruit_piano`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. note::
   ライブラリをインストールするには、Arduinoライブラリマネージャーを使用し、 **「Adafruit MPR121」** を検索してインストールしてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/e677c06a-7af1-4846-a507-dd69c0c50aae/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**どのように動作しますか？**

以下はコードの詳細な説明です：

1. ライブラリとオブジェクトの初期化：

   必要なライブラリをインポートします： ``Wire`` ライブラリ（I2C通信用）、 ``Adafruit_MPR121`` ライブラリ（MPR121のドライブ用）、 ``analogWave`` ライブラリ（アナログ波形の生成用）、および ``pitches.h`` （ノートの周波数を定義する）。
   ``Adafruit_MPR121`` と ``analogWave`` のオブジェクトのインスタンスを作成します。
   各タッチチャネルに対応するノートを格納するノート配列を定義します。

2. ``setup()``：

   シリアル通信を初期化し、開始を待ちます。
   MPR121をチェックし、初期化します。見つからない場合は、シリアルモニタにエラーメッセージを表示し、実行を停止します。
   ``analogWave`` オブジェクトを初期化し、最初の正弦波周波数を10Hzに設定します。

3. ``loop()``：

   MPR121の現在のタッチチャネルを読み取ります。
   すべてのチャネルを反復処理し、どれがタッチされたかをチェックし、対応するノートを演奏します。
   各反復の間にわずかな遅延を加えます。

4. ノートを演奏する ``playNote()``：

   ``playNote`` 関数は ``note`` パラメータを取り、対応するノートを演奏するためにDACの周波数を設定します。
   ノートを演奏する期間遅延を加えます。
   ノートの演奏を停止します。

