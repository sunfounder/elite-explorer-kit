.. _basic_button:

ボタン
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/controlling_led_by_button_uno.html#button-uno

概要
----------------

このレッスンでは、Arduinoを使用してボタンでLEDを制御する方法について学びます。ボタンとLEDは、リモコン、懐中電灯、インタラクティブインスタレーションなど、さまざまな電子デバイスにおいて基本的なコンポーネントです。このセットアップでは、ボタンを入力デバイスとして使用し、LEDの状態を制御します。

ボタンはArduino Uno R4ボードのピン12に、LEDはピン13に接続されています。ボタンが押されると、Arduinoに信号が送られ、LEDが点灯します。逆に、ボタンが放されると、LEDが消えます。このシンプルだが効果的なメカニズムは、ホームオートメーションシステム、インタラクティブディスプレイなど、より複雑なプロジェクトの基礎となることができます。

このレッスンを終えるころには、ボタンからの入力を読み取り、それを使用してLEDを制御する方法を理解し、Arduinoの入出力操作に関する基本的な理解を得ることができます。

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
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|


配線図
----------------------

.. image:: img/18-button_bb.png
    :align: center
    :width: 70%


回路図
------------------------

ボタンの一方の端をピン12に接続し、プルダウン抵抗と0.1uF（104）のコンデンサー（ボタンが動作する際にジッターを排除し、安定したレベルを出力するため）と接続します。抵抗の他端をGNDに、ボタンの他端のピンの一つを5Vに接続します。ボタンを押すと、ピン12は5V（HIGH）になり、同時にピン13（LEDが組み込まれている）をHighに設定します。次にボタンを放すと（ピン12がLOWに変わる）、ピン13はLowになります。そのため、ボタンを押して放すたびに、LEDが交互に点灯し消えるのが見られます。

.. image:: img/18_button_schematic.png
    :align: center
    :width: 70%


コード
---------------

.. note::

    * ファイル ``18-button.ino`` を ``elite-explorer-kit-main\basic_project\18-button`` のパスで直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a710eb54-9447-4542-ac98-c9a7e1ec4256/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


コード解析
-------------------

#. 定数と変数の定義

   このセグメントでは、ボタンとLEDのピン番号が定義されます。また、 ``buttonState`` 変数が宣言され、ボタンの現在の状態を保持します。
 
   .. code-block:: arduino
 
     const int buttonPin = 12;
     const int ledPin = 13;
     int buttonState = 0;

#. セットアップ関数

   ``setup()`` 関数は、Arduinoボードが起動するときに一度実行されます。ボタンとLEDのピンモードは、 ``pinMode`` 関数を使用して設定されます。
 
   .. code-block:: arduino
 
     void setup() {
       pinMode(buttonPin, INPUT);
       pinMode(ledPin, OUTPUT);
     }

#. メインループ

   ``loop()`` 関数は繰り返し実行されます。このループ内で、 ``digitalRead()`` 関数を使用してボタンの状態を読み取ります。ボタンが押されているかどうかに応じて、LEDを点灯または消灯します。

 
   .. code-block:: arduino
 
     void loop() {
       buttonState = digitalRead(buttonPin);
       if (buttonState == HIGH) {
         digitalWrite(ledPin, HIGH);
       } else {
         digitalWrite(ledPin, LOW);
       }
     }