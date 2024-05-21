.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _fun_smart_fan:

スマートファン
=================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/06_fun_smartfan.mp4"  type="video/mp4">
      お使いのブラウザではビデオタグがサポートされていません。
   </video>

このArduinoプロジェクトでは、ファンの速度が自動的に調整され、温度を適切な範囲内に保ちます。
また、ユーザーはボタンを通じて手動モードに入り、ファンを最大速度で操作できます。

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_power`
        - \-

**配線図**

.. image:: img/06_smart_fan_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**回路図**

.. image:: img/06_smart_fan_schematic.png
   :width: 80%
   :align: center

**コード**

.. note::

    * ファイル ``06_smart_fan.ino`` を ``elite-explorer-kit-main\fun_project\06_smart_fan`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/ba484912-14d6-4125-83a0-73a107904144/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**どのように動作しますか？**

以下はコードのステップバイステップの説明です：

1. 定数と変数の定義：

   様々なハードウェア接続用のピンを定義するために ``#define`` を使用します。
   ``TEMP_THRESHOLD`` は25°Cと定義され、これはファンを起動する温度のしきい値です。
   ``manualMode``：手動モードかどうかを示すブール変数。

2. ``setup()``：

   関連するピンのモード（出力、入力、プルアップ付き入力）を設定します。
   初期状態は自動モードなので、 ``LED_AUTO`` が点灯し、 ``LED_MANUAL`` は消灯しています。

3. ``loop()``：

   ボタンの状態を監視します。ボタンが押されると、モードが切り替わり、LEDの状態が変わります。
   手動モードでは、ファンは最大速度で稼働します。
   自動モードでは、まず温度センサーからの電圧値を読み取り、それを温度値に変換します。
   温度がしきい値を超えると、ファンの速度は温度に基づいて調整されます。

4. ``voltageToTemperature()``：

   温度センサーからの電圧値を摂氏の温度値に変換するための補助関数です。
   この関数は、サーミスタの標準式を使用して温度を推定します。
   戻り値は摂氏です。
