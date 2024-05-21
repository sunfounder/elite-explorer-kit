.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _fun_smart_can:

スマートゴミ箱
=====================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/07_fun_smartcan.mp4"  type="video/mp4">
      お使いのブラウザではビデオタグがサポートされていません。
   </video>

これは、スマートゴミ箱を制御するために設計されたArduinoのコードです。
物体がゴミ箱の前面20センチメートル以内にあると、その蓋が自動的に開きます。
このプロジェクトでは、SG90サーボモーターとHC-SR04超音波距離センサーを利用しています。

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

**配線図**

.. image:: img/07_smart_trash_can_bb.png
    :width: 70%
    :align: center


**回路図**

.. image:: img/07_smart_trash_can_schematic.png
   :width: 90%
   :align: center

**コード**

.. note::

    * ファイル ``07_smart_trash_can.ino`` を ``elite-explorer-kit-main\fun_project\07_smart_trash_can`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/509f1bee-6e38-4106-bea7-9b06cdb3719f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**どのように動作するのか？**

以下はコードのステップバイステップの説明です：

1. ライブラリのインポートと定数/変数の定義：

   SG90サーボモーターを制御するために ``Servo.h`` ライブラリをインポートします。
   サーボモーター、超音波センサー、その他必要な定数や変数のパラメータを定義します。

2. ``setup()``：

   コンピュータとのシリアル通信を9600ボーのボーレートで初期化します。
   超音波センサーのトリガーピンとエコーピンを設定します。
   サーボモーターを制御ピンに接続し、初期位置を閉じた角度に設定します。角度を設定した後、電力を節約するためにサーボモーターを取り外します。

3. ``loop()``：

   3回距離を測定し、各測定値を保存します。
   3回の測定から平均距離を計算します。
   平均距離が20センチメートル（定義された距離しきい値）以下の場合、サーボモーターは開角度（0度）に回転します。
   それ以外の場合、1秒の遅延の後、サーボモーターは閉じた位置（90度）に戻ります。使用していないときは電力を節約するためにサーボモーターを取り外します。

4. ``readDistance()``：

   超音波センサーのトリガーピンにパルスを送信します。
   エコーピンのパルス幅を測定し、距離値を計算します。
   この計算では、空気中の音速を使用してパルス時間に基づいて距離を計算します。
