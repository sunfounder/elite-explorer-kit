.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _iot_ble_home:

Bluetooth環境モニター
=====================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/08_iot_ble_home.mp4"  type="video/mp4">
      お使いのブラウザーはビデオタグをサポートしていません。
   </video>


このプロジェクトでは、MITアップインベンターで作成されたAndroidアプリを使用して、Arduinoボードからの環境データを受信し表示します。ArduinoボードはDHT11センサーから温度と湿度のデータを取得します。データが収集されると、Bluetoothを介して送信されます。アプリはデータを受信すると、画面上に表示します。

Androidアプリケーションは、 |link_appinventor| という無料のWebベースプラットフォームを利用して構築されます。このプロジェクトは、Arduinoとスマートフォンのインターフェースに慣れる絶好の機会を提供します。


**必要なコンポーネント**

このプロジェクトでは、以下のコンポーネントが必要です。

全てのキットを一括購入するのが便利です。こちらがリンクです:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名称	
        - このキットのアイテム数
        - リンク
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

また、以下のリンクから個別に購入することもできます。

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
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|

**1. 回路を組む**

.. image:: img/08-bluetooth_environmental_monitor_bb.png
    :width: 80%
    :align: center

.. image:: img/08_ble_home_schematic.png
    :width: 30%
    :align: center

.. raw:: html

   <br/>

**2. Androidアプリを作成する**

Androidアプリケーションは、 |link_appinventor| という無料のウェブアプリケーションを使用して開発されます。
MITアップインベンターは、直感的なドラッグアンドドロップ機能により、簡易なアプリケーションを作成するための優れたスタートポイントとして機能します。

さあ、始めましょう。

#. |link_appinventor_login| にアクセスし、「オンラインツール」をクリックしてログインします。MITアップインベンターに登録するためにはGoogleアカウントが必要です。

   .. image:: img/08_ai_signup.png
       :width: 90%
       :align: center

#. ログインしたら、 **Projects** -> **Import project (.aia) from my computer** に進みます。その後、 ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor`` のパスにある ``ble_environmental_monitor.aia`` ファイルをアップロードします。

   また、こちらから直接ダウンロードもできます: :download:`ble_environmental_monitor.aia</_static/other/ble_environmental_monitor.aia>`

   .. image:: img/08_ai_import.png
        :align: center

#. ``.aia`` ファイルをアップロードすると、MITアップインベンターソフトウェア上にアプリケーションが表示されます。これは事前に設定されたテンプレートです。MITアップインベンターに慣れた後、このテンプレートを変更することができます。

#. MITアップインベンターには、主に **Designer** と **Blocks** の2つのセクションがあります。ページの右上隅でこれらのセクション間を切り替えることができます。

   .. image:: img/08_ai_intro_1.png

#. **Designer** では、ボタン、テキスト、スクリーンを追加したり、アプリケーションの全体的な見た目を変更したりすることができます。

   .. image:: img/08_ai_intro_2.png
      :width: 100%
   
#. 次に、 **Blocks** セクションがあります。このセクションでは、アプリのGUI上の各コンポーネントにカスタム機能を作成し、望ましい機能を実現することができます。

   .. image:: img/08_ai_intro_3.png
      :width: 100%

#. スマートフォンにアプリケーションをインストールするには、 **Build** タブに移動します。

   .. image:: img/08_ai_intro_4.png

   * ``.apk`` ファイルを生成できます。このオプションを選択すると、 ``.apk`` ファイルをダウンロードするか、QRコードをスキャンしてインストールするかを選択するページが表示されます。インストールガイドに従ってアプリケーションのインストールを完了してください。

     こちらから事前にコンパイルされたAPKもダウンロードできます: :download:`ble_environmental_monitor.apk</_static/other/ble_environmental_monitor.apk>`

   * このアプリをGoogle Playや他のアプリマーケットにアップロードしたい場合は、 ``.aab`` ファイルを生成できます。


**3. コードをアップロードする**

#. ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor`` のパスにある ``08-bluetooth_environmental_monitor.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーします。
   
   .. note:: 
      ライブラリをインストールするには、Arduinoライブラリマネージャーを使用して、 **「DHT sensor library」** と **「ArduinoBLE」** を検索し、インストールします。

   .. raw:: html
       
      <iframe src=https://create.arduino.cc/editor/sunfounder01/53fd4af4-dcc6-439d-b52f-2f94f17c1263/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. 正しいボードとポートを選択したら、 **Upload** ボタンをクリックします。

#. シリアルモニター（ボーレートは **9600** に設定）を開き、デバッグメッセージを確認します。

**4. アプリとBluetoothモジュールの接続**

先に作成したアプリケーションがスマートフォンにインストールされていることを確認します。

#. まず、スマートフォンで **Bluetooth** をオンにします。

   .. image:: img/08_app_1.png
      :width: 60%
      :align: center

#. 次に、新しくインストールされた **Environmental Monitor** アプリを開きます。

   .. image:: img/08_app_2.png
      :width: 25%
      :align: center

#. このアプリを初めて開くと、Bluetoothの使用に必要な許可を求める2つのプロンプトが連続して表示されます。

   .. image:: img/08_app_3.png
      :width: 100%
      :align: center

   .. raw:: html

      <br/>

#. アプリ内で **Connect** ボタンをクリックし、アプリとBluetoothモジュール間の接続を確立します。

   .. image:: img/08_app_4.png
      :width: 55%
      :align: center

#. このページには、すべてのペアリングされたBluetoothデバイスのリストが表示されます。リストから ``xx.xx.xx.xx.xx.xx UNO R4 Home`` オプションを選択します。各デバイスの名前はMACアドレスの隣にリストされています。

   .. image:: img/08_app_5.png
      :width: 60%
      :align: center
   
   .. raw:: html

      <br/>

#. 上記のページにデバイスが表示されない場合は、デバイスの位置情報スイッチをオンにしてみてください（一部のAndroidシステムバージョンでは、Bluetooth機能と位置情報スイッチが統合されています）。

   .. image:: img/08_app_6.png
      :width: 60%
      :align: center

   .. raw:: html

      <br/>

#. 接続が成功すると、メインページにリダイレクトされ、そこで温度と湿度が表示されます。

   .. image:: img/08_app_7.png
      :width: 60%
      :align: center

**5. コードの説明**

1. ライブラリのインポートと定数の定義

   - 必要なライブラリをインポートし、DHTセンサーピンとタイプに関する定数を定義します。

   .. note:: 
      ライブラリをインストールするには、Arduinoライブラリマネージャーを使用して、 **「DHT sensor library」** と **「ArduinoBLE」** を検索し、インストールします。

   .. code-block:: arduino
   
       #include <DHT.h>
       #include <ArduinoBLE.h>
       #define DHTPIN 11
       #define DHTTYPE DHT11

2. BLEサービスと特性の初期化

   - BLE環境センシングサービスと特性のUUIDを定義します。 |link_bluetooth_sig| によって提供された事前定義されたUUIDを使用しています。 |link_sig_environmental_sensing| には ``0x181A`` が割り当てられ、それぞれ ``0x2A6E`` と ``0x2A6F`` は |link_sig_temperature_humidity| 用に予約されています。

   .. code-block:: arduino
   
       BLEService environmentalSensingService("181A");
       BLEShortCharacteristic temperatureCharacteristic("2A6E", BLERead | BLENotify);
       BLEUnsignedShortCharacteristic humidityCharacteristic("2A6F", BLERead | BLENotify);

3. Setup関数

   - シリアル通信、DHTセンサー、BLEを初期化します。

   .. code-block:: arduino
   
       void setup() {
         Serial.begin(9600);
         dht.begin();
         if (!BLE.begin()) {
           Serial.println("starting Bluetooth® Low Energy module failed!");
           while (1)
             ;
         }
         setupBle();
       }

4. メインループ

   - BLEイベントをポーリングし、定期的にセンサーデータを更新します。

   - ``millis() - lastUpdateTime > updateInterval`` の行は、センサーデータがupdateIntervalミリ秒ごとに更新されることを保証します。

   .. code-block:: arduino
   
       void loop() {
         BLE.poll();
         if (millis() - lastUpdateTime > updateInterval) {
           // Read sensor data and update BLE characteristics
         }
       }

5. BLEおよびデバッグ関数

   BLEを設定し、デバッグ情報を出力し、BLEイベントを管理するための関数。

   .. code-block:: arduino
   
       void printDHT(float h, float t) { /* ... */ }
       void setupBle() { /* ... */ }
       void blePeripheralConnectHandler(BLEDevice central) { /* ... */ }
       void blePeripheralDisconnectHandler(BLEDevice central) { /* ... */ }

   - ``printDHT(float h, float t)``: DHT11によって読み取られた温度と湿度のデータをシリアルモニターに出力するために使用されます。この関数はデバッグ目的のためです。

   - ``setupBle()``: ブロードキャスト名、特性、およびサービスを設定を含むBluetoothを初期化します。

   - ``blePeripheralConnectHandler(BLEDevice central)`` および ``blePeripheralDisconnectHandler(BLEDevice central)``: これらの関数は、Bluetoothが接続または切断されたときのイベントを処理します。デバイスがUNO R4とBluetooth経由で正常に接続すると、オンボードLEDが点灯します。デバイスが切断されると、LEDが消灯します。
