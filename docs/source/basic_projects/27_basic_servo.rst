.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _basic_servo:

サーボ
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/servo_uno.html#servo-uno

概要
---------------

このレッスンでは、Arduinoとサーボモーターの使用について学びます。Arduino UnoとSG90サーボモーターに焦点を当て、Arduinoをプログラミングしてサーボのスイープ動作を制御する方法を学びます。この技術は、ロボティクスや自動システムなど、さまざまな用途で重要です。

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

配線図
----------------------

.. image:: img/27-servo_bb.png
    :align: center
    :width: 70%

.. raw:: html

   <br/>

回路図
-----------------------

.. image:: img/27_servo_schematic.png
    :align: center
    :width: 60%

コード
---------------

.. note::

    * ファイル ``27-servo.ino`` を ``elite-explorer-kit-main\basic_project\27-servo`` で直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c57ddb7a-0acb-4a64-938a-0a0abfc0ec4b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


コード解析
------------------------


1. ここでは、サーボモーターを簡単に制御するための ``Servo`` ライブラリが含まれています。サーボに接続されたピンとサーボの初期角度も定義されています。

   .. code-block:: arduino

      #include <Servo.h>
      const int servoPin = 9;  // Define the servo pin
      int angle = 0;           // Initialize the angle variable to 0 degrees
      Servo servo;             // Create a servo object

2. ``setup()`` 関数はArduinoが起動するときに一度実行されます。 ``attach()`` 関数を使用して、定義されたピンにサーボを接続します。

   .. code-block:: arduino

      void setup() {
        servo.attach(servoPin);
      }

3. メインループには2つの ``for`` ループがあります。最初のループは角度を0度から180度に増加させ、2番目のループは角度を180度から0度に減少させます。 ``servo.write(angle)`` コマンドは、指定された角度にサーボを設定します。 ``delay(15)`` により、サーボは次の角度に移動する前に15ミリ秒待機し、スキャン動作の速度を制御します。


   .. code-block:: arduino

      void loop() {
        // scan from 0 to 180 degrees
        for (angle = 0; angle < 180; angle++) {
          servo.write(angle);
          delay(15);
        }
        // now scan back from 180 to 0 degrees
        for (angle = 180; angle > 0; angle--) {
          servo.write(angle);
          delay(15);
        }
      }