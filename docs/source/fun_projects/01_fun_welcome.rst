.. _fun_welcome:

ウェルカム
========================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/01_fun_welcome.mp4"  type="video/mp4">
      お使いのブラウザではビデオタグがサポートされていません。
   </video>

このプロジェクトでは、PIRセンサーを使用して人の存在を検出し、スピーカーを使用してコンビニエンスストアの入口のドアベルに似たドアベルをシミュレートします。
歩行者がPIRセンサーの範囲内に現れると、スピーカーが鳴り、ドアベルを模倣します。

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|
    *   - :ref:`cpn_audio_speaker`
        - \-


**配線図**

.. image:: img/01_welcome_bb.png
    :width: 90%
    :align: center

.. raw:: html

   <br/>

**回路図**

.. image:: img/01_welcome_schematic.png
   :width: 100%

**コード**

.. note::

    * ファイル ``01_welcome.ino`` を ``elite-explorer-kit-main\fun_project\01_welcome`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/b9791d5d-169d-4603-9fc3-8081138811fa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



**どのように動作しますか？**

以下はコードの詳細な説明です：

1. ヘッダーファイルのインクルード：

   ``analogWave.h`` と ``pitches.h`` という二つのヘッダーファイルをインクルードします。 ``analogWave.h`` ファイルには ``analogWave`` クラスの定義が含まれており、 ``pitches.h`` には音楽ノートの定義が含まれています。

2. オブジェクトのインスタンス化と定数の定義：

   ``analogWave`` クラスを使用して ``wave`` オブジェクトを作成し、PIRセンサーに接続されたピンとして ``PIR_PIN`` を2として定義します。

3. メロディ配列：

   ``melody`` 配列は、音楽的なメロディを定義し、各ノートにはその持続時間を表す数が続きます。
   負の数は点付きのノートを表し（持続時間を50％増加）、符点をつけます。

4. グローバル変数：

   関数間でデータを共有するためのグローバル変数を定義します。

5. ``setup()``：

   ``PIR_PIN`` を入力として初期化し、 ``wave.sine(10)`` を使用して正弦波の周波数を10Hzに設定します。

6. ``loop()``：

   PIRセンサーの値を継続的に監視します。
   人の存在が検出されると（pirValueがHIGHの場合）、 ``playMelody()`` 関数を呼び出してメロディを演奏し、メロディの反復的な再生を防ぐために10秒待ちます。

7. ``playMelody()``：

   この関数は ``melody`` 配列のデータに基づいて各ノートの持続時間を計算し、対応するノートを演奏します。ノート間には短い一時停止があります。
   この関数は ``wave.freq()`` を使用して波形の周波数を設定し、 ``delay()`` 関数を使用してノートとノート間の一時停止の持続時間を制御します。

   注意：このコードを実行する前に、 ``pitches.h`` ヘッダーファイルが実際に存在することを確認してください。

