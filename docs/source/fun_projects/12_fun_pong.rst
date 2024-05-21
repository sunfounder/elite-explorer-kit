.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _fun_pong:

ゲーム - ポン
=================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/12_fun_pong.mp4"  type="video/mp4">
      お使いのブラウザーはビデオタグをサポートしていません。
   </video>

これは、OLEDディスプレイとArduinoボードを使用して設計されたシンプルなポンゲームです。
ポンゲームでは、プレイヤーはコンピュータと対戦し、垂直なパドルを操作して跳ね返るボールを跳ね返します。
目標は、ボールを自分のパドルの端を越えさせないようにすることで、さもなければ相手に得点されます。

ゲームのメカニズムは以下のパーツに分けられます：

1. ボールの動き - ボールは現在の方向に沿って設定された速度で動きます。ボールがパドルに衝突するたびに、その速度が増加し、ゲームがより難しくなります。

2. パドルの動き - ボールの動きをブロックするために使用されるパドルは、上または下に動かすことができます。プレイヤーはボタンを使用して自分のパドルを操作し、コンピュータのパドルは自動的にボールの位置に従います。

3. スコアリング - ボールが画面の左または右端を越えるたびに、対応するプレイヤーまたはCPUが得点します。

**必要なコンポーネント**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入するのが便利です。こちらがリンクです：

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
    *   - :ref:`cpn_oled`
        - |link_oled_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_power`
        - \-


**配線図**

.. image:: img/12_pong_bb.png
    :width: 100%
    :align: center


**回路図**

.. image:: img/12_pong_schematic.png
    :width: 100%
    :align: center

**コード**

.. note::

    * ファイル ``12_pong_oled.ino`` は、パス ``elite-explorer-kit-main\fun_project\12_pong_oled`` で直接開けます。
    * または、このコードをArduino IDEにコピーしてください。

.. note::
   ライブラリをインストールするには、Arduinoライブラリマネージャーで **「Adafruit SSD1306」** と **「Adafruit GFX」** を検索し、インストールしてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/86dbb549-d425-4f42-8b5b-28d486e3f7f8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**どのように動作するのか？**

プログラムの構造は以下の5つの部分に分けられます：

1. 必要なライブラリのインポート - OLEDスクリーンの制御とボタン入力の読み取りに使用されます。

2. 定数とグローバル変数の定義：

   OLEDスクリーンの幅と高さの定義。
   ボタンとOLEDリセットピンの定義。
   ボールとパドルの位置、速度、サイズ、方向。
   プレイヤーとCPUのスコア。

3. 初期化：

   シリアル通信、OLEDスクリーンを初期化し、初期インターフェースを表示します。
   ボタンを入力として設定し、プルアップ抵抗器を接続します。
   プレイングフィールドを描きます。

4. メインループ：

   ボタンの状態を読み取ります。
   設定されたリフレッシュレートに基づいてボールを動かします。
   ボールとパドルまたは壁との衝突を検出し、ボールの方向と速度をそれに応じて調整します。
   得点イベントに基づいてスクリーン上のスコアを更新します。
   パドルの位置をリフレッシュします。

5. 追加の関数：

   ``crossesPlayerPaddle`` と ``crossesCpuPaddle`` - ボールがプレイヤーのパドルまたはCPUのパドルと衝突するかどうかを検出するために使用されます。
   
   ``drawCourt`` - OLEDスクリーン上にプレイングフィールドを描きます。

   ``displayScore`` - 画面上にプレイヤーとCPUのスコアを表示します。

