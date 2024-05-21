.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _basic_i2c_lcd1602:

I2C LCD1602
==========================

.. https://docs.sunfounder.com/projects/sensorkit-v2-arduino/en/latest/lesson_1.html

概要
---------------

このレッスンでは、I2Cインターフェースを備えた液晶ディスプレイ（LCD）について学びます。この種のLCDは、デジタル時計、電子レンジ、車のダッシュボード、さらには産業機器など、さまざまな電子機器で広く使用されています。I2Cインターフェースにより、配線や接続が簡素化され、趣味愛好家やプロフェッショナルにとって便利で効率的です。

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

配線図
----------------------

.. image:: img/14-i2c_lcd_bb.png
    :align: center
    :width: 100%

回路図
-----------------------

.. image:: img/14-i2c_lcd_schematic.png
    :align: center
    :width: 80%

コード
---------------

.. note::

    * ファイル ``14-i2c_lcd.ino`` を ``elite-explorer-kit-main\basic_project\14-i2c_lcd`` のパスで直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. note:: 
    ライブラリをインストールするには、Arduinoライブラリマネージャーを使用し、 **「LiquidCrystal I2C」** を検索してインストールしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/096326ad-eccf-4d2e-be52-66f4819ca7d8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/14_basic_i2c_lcd.mp4"  type="video/mp4">
      ブラウザがビデオタグをサポートしていません。
   </video>

コードがArduinoに正常にアップロードされると、液晶ディスプレイ（LCD）には最初の行に「Hello world!」、2行目に「LCD Tutorial」というメッセージが表示されます。

.. note::
    コードをアップロードした後、LCDに文字が表示されない場合は、I2Cモジュール上のポテンショメータを回してコントラストを調整し、LCDが正しく機能するようにしてください。

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/14_basic_i2c_lcd_2.mp4"  type="video/mp4">
      ブラウザがビデオタグをサポートしていません。
   </video>

   <br/><br/>

コード解析
------------------------

1. ライブラリのインクルードとLCDの初期化：
   LiquidCrystal I2Cライブラリをインクルードして、LCDインターフェースの関数やメソッドを提供します。その後、LiquidCrystal_I2Cクラスを使用してLCDオブジェクトを作成し、I2Cアドレス、列数、行数を指定します。

   .. note:: 
      ライブラリをインストールするには、Arduinoライブラリマネージャーを使用し、 **「LiquidCrystal I2C」** を検索してインストールしてください。

   .. code-block:: arduino

      #include <LiquidCrystal_I2C.h>
      LiquidCrystal_I2C lcd(0x27, 16, 2);

2. セットアップ関数：
   ``setup()`` 関数はArduinoが起動するときに一度実行されます。この関数では、LCDが初期化され、クリアされ、バックライトが点灯します。次に、2つのメッセージがLCDに表示されます。

   .. code-block:: arduino

      void setup() {
        lcd.init();       // initialize the LCD
        lcd.clear();      // clear the LCD display
        lcd.backlight();  // Make sure backlight is on
      
        // Print a message on both lines of the LCD.
        lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
        lcd.print("Hello world!");
      
        lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
        lcd.print("LCD Tutorial");
      }