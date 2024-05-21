.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _basic_irrecv:

赤外線レシーバー
==========================

.. https://docs.sunfounder.com/projects/uno-mega-kit/en/latest/uno/infrared_Receiver_uno.html#receive-uno

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/infrared_Receiver_uno.html#receive-uno

概要
------------------

赤外線レシーバーは、赤外線信号を受信し、独立して赤外線を受信し、TTLレベルと互換性のある信号を出力する部品です。通常のプラスチックパッケージのトランジスタとサイズが似ており、様々な種類の赤外線リモコンや赤外線伝送に適しています。

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
    *   - :ref:`cpn_ir_receiver`
        - |link_receiver_buy|


配線図
----------------------

.. image:: img/22-ir_receiver_bb.png
    :align: center
    :width: 80%


回路図
---------------------

.. image:: img/22_irrecv_schematic.png
    :align: center
    :width: 50%

コード
---------------

.. note::

    * ファイル ``22-ir_receiver.ino`` を ``elite-explorer-kit-main\basic_project\22-ir_receiver`` のパスで直接開くことができます。
    * または、このコードをArduino IDEにコピーする。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/92e1cb75-cda1-4fc7-9680-28e28df8dccc/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

* ここでは ``IRremote`` ライブラリを使用しています。 **Library Manager** からインストールできます。

    .. image:: img/22_irrecv_lib.png
        :align: center

.. Note::

    * リモコンの背面には、電源を遮断する透明なプラスチック片があり、リモコンを使用する前にそれを取り出してください。


コード解析
---------------------

このコードは、 ``IRremote`` ライブラリを使用して赤外線（IR）リモコンを操作するように設計されています。以下がその詳細です：

#. ライブラリを含めて定数を定義します。まず、IRremoteライブラリを含め、IRレシーバー用のピン番号を2として定義します。

   .. code-block:: cpp
 
     #include <IRremote.h>
     const int IR_RECEIVE_PIN = 2;


#. 9600のボーレートでシリアル通信を初期化し、指定されたピン（ ``IR_RECEIVE_PIN`` ）でIRレシーバーを初期化し、LEDフィードバックを有効にします（該当する場合）。

   .. code-block:: arduino

       void setup() {
           Serial.begin(9600);                                     // Start serial communication at 9600 baud rate
           IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
       }

#. ループは継続的に実行され、受信したIRリモコン信号を処理します。

   .. code-block:: arduino

      void loop() {
        // Check if there is any incoming IR signal
        if (IrReceiver.decode()) {
          // IrReceiver.printIRResultShort(&Serial);                 // Print the received data in one line
          // Serial.println(IrReceiver.decodedIRData.command, HEX);  // Print the command in hexadecimal format
          Serial.println(decodeKeyValue(IrReceiver.decodedIRData.command));  // Map and print the decoded IR signal to corresponding key value
      
          IrReceiver.resume();  // Enable receiving of the next value
        }
      }
   
   * IR信号が受信され、正常にデコードされたかをチェックします。
   * IRコマンドをデコードし、カスタム関数 ``decodeKeyValue()`` を使用して ``decodedValue`` に格納します。
   * デコードされたIR値をシリアルモニターに表示します。
   * 次の信号のIR信号受信を再開します。

   .. raw:: html

        <br/>

#. 受信したIR信号を対応するキーにマッピングするヘルパー関数

   .. image:: img/22_irrecv_key.png
      :align: center
      :width: 80%

   .. code-block:: arduino

      // Function to map received IR signals to corresponding keys
      String decodeKeyValue(long result) {
        // Each case corresponds to a specific IR command
        switch (result) {
          case 0x16:
            return "0";
          case 0xC:
            return "1";
          case 0x18:
            return "2";
          case 0x5E:
            return "3";
          case 0x8:
            return "4";
          case 0x1C:
            return "5";
          case 0x5A:
            return "6";
          case 0x42:
            return "7";
          case 0x52:
            return "8";
          case 0x4A:
            return "9";
          case 0x9:
            return "+";
          case 0x15:
            return "-";
          case 0x7:
            return "EQ";
          case 0xD:
            return "U/SD";
          case 0x19:
            return "CYCLE";
          case 0x44:
            return "PLAY/PAUSE";
          case 0x43:
            return "FORWARD";
          case 0x40:
            return "BACKWARD";
          case 0x45:
            return "POWER";
          case 0x47:
            return "MUTE";
          case 0x46:
            return "MODE";
          case 0x0:
            return "ERROR";
          default:
            return "ERROR";
        }
      }