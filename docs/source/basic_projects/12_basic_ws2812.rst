.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _basic_ws2812:

WS2812 RGB LEDストリップ
==========================

概要
---------------

このレッスンでは、NeoPixel LEDとその制御方法について学びます。制御にはArduino Uno R4上でFastLEDライブラリを使用します。NeoPixel LEDは、家庭の装飾、ウェアラブル、イベント照明など様々なアプリケーションで広く使用されています。FastLEDライブラリはこれらのLEDのプログラミングを簡素化します。ここでは、8個のNeoPixel LEDをArduinoに接続し、各LEDが青色で一時的に点灯し、次のLEDに移る前に消灯します。この基本的な例は、より複雑な光パターンやインタラクティブな照明プロジェクトの基礎として役立ちます。

必要なコンポーネント
-------------------------

このプロジェクトには以下のコンポーネントが必要です。

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
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

配線図
----------------------

.. image:: img/12-ws2812_bb.png
    :align: center

回路図
-----------------------

.. image:: img/12_ws2812_schematic.png
    :align: center
    :width: 80%

コード
---------------

.. note::

    * ファイル ``12-ws2812.ino`` を ``elite-explorer-kit-main\basic_project\12-ws2812`` のパスで直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. note:: 
    ライブラリをインストールするには、Arduinoライブラリマネージャーを使用し、 **「FastLED」** を検索してインストールしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6c9b8c2c-6cea-4ea8-a959-e579ca98f35d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/12_basic_ws2812.mp4"  type="video/mp4">
      ブラウザがビデオタグをサポートしていません。
   </video>

コードが正常にアップロードされると、8個のNeoPixel LEDのチェーンの各LEDが青色で一つずつ点灯する様子が見られます。プログラムはこのシーケンスを繰り返し、次のLEDに移る前に各LEDを消灯します。各LED間に短い遅延を設けることで、チェーンに沿って移動する青い点の照明効果が現れます。

コード解析
------------------------

1. ライブラリのインポートと定数の設定

   - ``FastLED`` ライブラリをインポートして、その機能を使用します。
   - LEDの数と接続されているデータピンを定義します。
   
   .. code-block:: arduino
   
      #include <FastLED.h>  // Include FastLED library
      #define NUM_LEDS 8    // Number of LEDs in the chain
      #define DATA_PIN 6    // Data pin for LED control

2. LED配列の初期化
   
   各LEDの色情報を格納するための ``CRGB`` 型の配列を作成します。

   .. code-block:: arduino

      CRGB leds[NUM_LEDS];  // Array to hold LED color data

3. セットアップ内でのLEDの初期化

   ``FastLED.addLeds`` を使用してLEDを初期化します。

   .. code-block:: arduino

      void setup() {
        FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Initialize LEDs
      }

4. ループ内でのLEDの制御
   
   各LEDを青色に設定し、表示し、クリアし、遅延させるループ。

   - ``leds`` 配列はLEDストリップのカラーバッファとして機能します。この配列の各要素は物理的なストリップ上の個々のLEDに対応し、その色の値がLEDが表示する色を決定します。配列内の要素の順序はストリップ上のLEDの順序に一致し、最初のLED（ ``leds[0]`` に対応）から最後のLEDまでです。ストリップ上の特定のLEDの色を変更するには、 ``leds`` 配列内の対応する要素を変更します。 |fastled_color| を使用するか、RGBで色を設定できます（例として緑色を使用する場合、 ``leds[dot] = CRGB::Green`` または ``leds[dot] = CRGB(0, 255, 0);`` を使用します）。

   - ``FastLED.show();`` 関数は新しい色データでLEDストリップを更新し、変更を可視化します。これは、コードで編集や調整を行った後、LEDストリップの「公開」ボタンを押すようなものです。


   .. raw:: html

     <br/>

   .. code-block:: arduino

      void loop() {
        for (int dot = 0; dot < NUM_LEDS; dot++) {
          leds[dot] = CRGB::Blue;   // Set the current LED to blue
          FastLED.show();           // Update LEDs
          leds[dot] = CRGB::Black;  // Clear the current LED
          delay(30);                // Wait for a short period before moving to the next LED
        }
      }