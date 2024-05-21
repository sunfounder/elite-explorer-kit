.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _basic_oled:

OLED
==========================

.. https://docs.sunfounder.com/projects/ultimate-sensor-kit/en/latest/components_basic/22-component_oled.html

概要
---------------

このレッスンでは、SSD1306ドライバーを使用したOLEDディスプレイについて学びます。OLED（有機発光ダイオード）ディスプレイは、スマートウォッチ、携帯電話、さらにはテレビなど、さまざまな電子機器で広く使用されています。SSD1306は、有機／ポリマー発光ダイオードのドットマトリックスグラフィックディスプレイシステム用のシングルチップCMOS OLED/PLEDドライバー兼コントローラーです。電流が流れると発光する有機物質ベースのダイオードを使用し、クリアで鮮明なビジュアル出力を提供します。

提供されたコードでは、ArduinoボードとI2Cプロトコルを介してOLEDディスプレイがインターフェースされます。コードはAdafruit SSD1306ライブラリを使用してディスプレイを制御します。プログラムは、以下のようなさまざまな機能をカバーしています：

1. テキストの表示：「Hello world!」が画面に表示されます。
2. 反転テキスト：「Hello world!」が反転した色の配色で表示されます。
3. フォントサイズ：「Hello!」が拡大されたフォントサイズで表示されます。
4. 数字の表示：123456789が表示されます。
5. ASCII文字：一連のASCII文字が表示されます。
6. スクロール：テキストがディスプレイを横切ってスクロールします。
7. ビットマップ表示：事前定義されたビットマップ画像がOLED画面に表示されます。

このOLEDディスプレイは、デジタル時計、ミニゲームコンソール、情報表示など、さまざまなアプリケーションで使用できます。コンパクトでポータブルなデバイスでユーザーインターフェイスを提供するための素晴らしい方法です。

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
    *   - :ref:`cpn_oled`
        - |link_oled_buy|

配線図
----------------------

.. image:: img/15-oled_bb.png
    :align: center

回路図
-----------------------

.. image:: img/15_oled_schematic.png
    :align: center
    :width: 70%

コード
---------------

.. note::

    * ファイル ``15-oled.ino`` を ``elite-explorer-kit-main\basic_project\15-oled`` のパスで直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

    .. note:: 
      ライブラリをインストールするには、Arduinoライブラリマネージャーを使用し、 **「Adafruit SSD1306」** と **「Adafruit GFX」** を検索してインストールしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ec580f40-78b4-42c2-af7c-bb5bc05a7c23/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/15_basic_oled.mp4"  type="video/mp4">
      ブラウザがビデオタグをサポートしていません。
   </video>

   <br/><br/>


コード解析
------------------------

1. **ライブラリのインクルードと初期定義**:
   OLEDとのインターフェースに必要なライブラリを含めます。その後、OLEDの寸法とI2Cアドレスに関する定義が提供されます。

   - **Adafruit SSD1306**: このライブラリはSSD1306 OLEDディスプレイのインターフェースに役立つように設計されています。ディスプレイの初期化、設定の制御、コンテンツの表示などの方法を提供します。
   - **Adafruit GFXライブラリ**: これは、OLEDを含むさまざまな画面でテキストを表示したり、色を生成したり、図形を描画するためのコアグラフィックスライブラリです。

   .. note:: 
      ライブラリをインストールするには、Arduinoライブラリマネージャーを使用し、 **「Adafruit SSD1306」** と **「Adafruit GFX」** を検索してインストールしてください。

   .. code-block:: arduino
    
      #include <SPI.h>
      #include <Wire.h>
      #include <Adafruit_GFX.h>
      #include <Adafruit_SSD1306.h>

      #define SCREEN_WIDTH 128  // OLED display width, in pixels
      #define SCREEN_HEIGHT 64  // OLED display height, in pixels

      #define OLED_RESET -1
      #define SCREEN_ADDRESS 0x3C

2. **ビットマップデータ**:
   OLED画面にカスタムアイコンを表示するためのビットマップデータです。このデータは、OLEDが解釈できる形式でイメージを表しています。

   画像を配列に変換できるオンラインツール |link_image2cpp| を使用できます。

   ``PROGMEM`` キーワードは、配列がArduinoマイクロコントローラのプログラムメモリに格納されていることを示しています。大量のデータがRAMを大量に消費する場合に、プログラムメモリ(PROGMEM)にデータを格納すると有用です。

   .. code-block:: arduino

      static const unsigned char PROGMEM sunfounderIcon[] = {...};

3. **セットアップ関数（初期化と表示）**:
   ``setup()`` 関数はOLEDを初期化し、一連のパターン、テキスト、アニメーションを表示します。

   .. code-block:: arduino

      void setup() {
         ...  // Serial initialization and OLED object initialization
         ...  // Displaying various text, numbers, and animations
      }