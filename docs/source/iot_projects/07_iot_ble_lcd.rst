.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _iot_Bluetooth_lcd:

Bluetooth メッセージボックス
=============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/07_iot_ble_lcd.mp4"  type="video/mp4">
      お使いのブラウザではビデオタグがサポートされていません。
   </video>

このプロジェクトは、メッセージを受信し、LCDスクリーンに表示します。

家族用のメッセージボードとして使用し、まだ出かけていない家族に鍵を持って行くことを思い出させることができます。

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**配線図**

.. image:: img/07_lightblue_lcd_bb.png
    :width: 100%
    :align: center

**回路図**

.. image:: img/07_lightblue_lcd_schematic.png
   :width: 80%
   :align: center

.. raw:: html

   <br/>

**UUIDの生成**

BLE通信において、UUIDはデバイスのユニーク性を保証し、データ交換の正確性を確保するために重要な役割を果たします。特定のアプリケーション要件に合わせて、独自のBLEサービスや特性を作成するために、UUIDをカスタマイズする必要があります。（ここでは、テキスト入力をサポートする特性を作成する必要があります。）

1. `オンラインUUIDジェネレーターツール <https://www.uuidgenerator.net/version4>`_ を使用して、UUIDの競合を避けるためにあなただけのユニークなUUIDを生成します。

2. バージョン4のUUIDを2つ生成します。

   .. image:: img/07_uuid_1.png
      :width: 70%

   .. raw:: html

      <br/><br/>

3. それらをコピーし、コードの2つのUUIDを置き換えます。

   .. code-block:: arduino
   
       #define SERVICE_UUID "uuid1"
       #define CHARACTERISTIC_UUID "uuid2"

**ライブラリのインストール**

``ArduinoBLE.h``：Bluetooth Low Energy（BLE）通信を扱うために使用されます。
``LiquidCrystal_I2C.h``：I2Cインターフェースを持つ16x2文字LCDスクリーンを制御するために使用されます。

**コードの実行**

.. note::

    * ファイル ``07_lightblue_lcd.ino`` を ``elite-explorer-kit-main\iot_project\07_lightblue_lcd`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. note:: 
      ライブラリをインストールするには、Arduinoライブラリマネージャーを使用して、 **「ArduinoBLE」** と **「LiquidCrystal I2C」** を検索し、インストールします。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/958c37c2-a897-4c4c-b6c1-0e7fea67c7b1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**操作方法**

このスケッチで作成されたサービスと特性を操作するには、LightBlue（iOSおよびAndroid用）やnRF Connect（Android用）などの汎用的なBluetooth® Low Energy中央アプリを使用する必要があります。

例として、ArduinoのLEDをBluetooth経由で制御する方法をLightBlueを使用して説明します。

1. App Store（iOS用）またはGoogle Play（Android用）からLightBlueアプリをダウンロードします。

   .. image:: img/07_lightblue.png

2. ArduinoをBluetooth経由でスマートフォンに接続

   Bluetooth設定に移動し、「UNO R4 BLE」という名前のデバイスを探します。接続します。

   .. image:: img/07_iot_ble_01.jpg
      :width: 50%

   .. raw:: html

      <br/><br/>

3. LightBlueを使用してArduinoとBluetooth経由でのインタラクション

   LightBlueを起動し、インターフェースの下部にある **Bonded** タブをタップします。ここには、スマートフォンが以前にペアリングしたBLEデバイスのリストが表示されます。 **UNO R4 BLE** を探して **CONNECT** をタップします。

   .. image:: img/07_iot_ble_02.jpg

   接続すると、Bluetoothデバイスに関する詳細情報にアクセスできます。サービスUUIDとキャラクタリスティックUUIDを見つけるために下にスクロールします。

   キャラクタリスティックをタップします。このキャラクタリスティックは読み取り可能で書き込み可能であり、読み取りと書き込みの両方が可能です。

   「Data format」セクションにスクロールしてUTF-8文字列に変更します。
   テキストボックスにテキストを入力して書き込みをクリックします。入力したメッセージがLCDに表示されます。

   .. image:: img/07_iot_ble_03.jpg


**どのように動作するのか？**

こちらがコードの主要部分とそれぞれの機能の説明です：

1. 必要なライブラリをインクルード：

   * ``ArduinoBLE.h``：BLE通信を処理するために使用されます。
   * ``Wire.h``：I2C通信のために使用されます。
   * ``LiquidCrystal_I2C.h``：I2Cインターフェースを持つ16x2文字のLCDスクリーンを制御するために使用されます。

2. BLEサービスとBLE特性を定義：

   * ``BLEService`` クラスを使用してBLEサービスを定義し、一意のUUIDを割り当てます。
   * ``BLECharacteristic`` クラスを使用してBLE特性を定義し、一意のUUIDを割り当て、読み取り（ ``BLERead`` ）と書き込み（ ``BLEWrite`` ）の権限を与えます。
   * 特性の初期値として文字配列 ``stringValue`` を作成します。

3. 16x2文字LCDスクリーン（LCD）を初期化：

   * ``LiquidCrystal_I2C`` クラスを使用してLCDを初期化し、I2Cアドレス（0x27）と行と列の数（16x2）を指定します。
   * LCDのバックライトを点灯し、画面をクリアし、カーソルを最初の行の始めに移動し、「Bluetooth LCD」と表示します。

4. ``setup()`` 関数で初期化を行う：

   * シリアル通信を初期化します。
   * BLEモジュールを初期化し、初期化に失敗した場合は無限ループに入ります。
   * BLE周辺機器のローカル名とサービスUUIDを設定します。
   * BLE特性をBLEサービスに追加します。
   * 中央デバイスが発見して接続できるようにBLEサービスをアドバタイズします。
   * LCDを初期化します。

5. ``loop()`` 関数：

   * ``BLE.central()`` を呼び出して、BLE周辺機器に中央デバイスが接続されているかどうかを確認します。中央デバイスが接続されている場合は、接続処理のロジックに入ります。
   * 接続状態で、 ``boxCharacteristic.written()`` を確認して、BLE特性にデータが書き込まれたかどうかをチェックします。
   * データが書き込まれていた場合、 ``boxCharacteristic.valueLength()`` を使用して書き込まれたデータの長さを取得し、書き込まれたデータを格納するためのバイト配列 ``buffer`` を作成します。
   * ``boxCharacteristic.readValue()`` を使用して、BLE特性から ``buffer`` にデータを読み込みます。
   * ``buffer`` の最後にヌル文字 ``「\0」`` を追加して文字列に変換します。
   * 受信したメッセージをシリアルモニタに表示し、LCDに表示します。
   * 中央デバイスが切断された後、次の中央デバイスが接続するのを待ち続けます。
