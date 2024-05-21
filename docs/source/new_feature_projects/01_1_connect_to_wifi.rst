.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

Wi-Fiに接続する
=================

このチュートリアルでは、ArduinoボードをWi-Fiネットワークに接続するための基本的なステップを案内します。Wi-Fiモジュールの初期化、ファームウェアの確認、SSIDとパスワードを使用した安全なネットワークへの参加方法を学びます。接続後、シリアルコンソールからデバイスのIPやMACアドレス、ネットワークの信号強度などの重要なネットワーク情報をモニタリングする方法を発見します。このチュートリアルは、Wi-Fi接続の実用的なガイドであり、Arduinoを使用したネットワークモニタリングの導入としても役立ちます。これにより、信頼性のあるWi-Fi接続を確立し維持することができます。

1. コードをアップロードする
-----------------------------

``elite-explorer-kit-main\r4_new_feature\01-wifi_connect`` のパスの下にある ``01-wifi_connect.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーします。

.. note:: 
      Wi-Fi®サポートは、Arduino UNO R4 Coreに付属する内蔵の ``WiFiS3`` ライブラリを介して有効にされます。コアのインストール時に自動的に ``WiFiS3`` ライブラリもインストールされます。


``arduino_secrets.h`` を作成または変更し、 ``SECRET_SSID`` と ``SECRET_PASS`` を接続したいWi-Fiの名前とパスワードに置き換える必要があります。 ファイルには以下が含まれている必要があります:

.. code:: arduino

    //arduino_secrets.h header file
    #define SECRET_SSID "yournetwork"
    #define SECRET_PASS "yourpassword"

.. raw:: html
       
   <iframe src=https://create.arduino.cc/editor/sunfounder01/a41ac638-31da-464c-b5d3-e70f2aacd29c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

シリアルモニタを開くと、以下のような内容が表示されます。ArduinoはデバイスのIPとMACアドレス、ネットワークの信号強度を出力します。

.. image:: img/01_1_wifi.png
    :width: 100%


2. コードの説明
-----------------

1. ライブラリと秘密データを含める

   .. code-block:: arduino

      #include <WiFiS3.h>
      #include "arduino_secrets.h" 

   - ``WiFiS3`` はWi-Fi接続のための関数を提供するライブラリです。R4コアをインストールすると自動的にWiFiS3ライブラリがインストールされます。
   - ``arduino_secrets.h`` はメインコードにSSIDやパスワードが露出しないようにするための別のファイルです。ネットワークとパスワードを別々に保管することで、Wi-Fi資格情報の偶発的な共有を減らします。

   .. raw:: html

      <br/>

2. グローバル変数の宣言

   .. code-block:: arduino

      char ssid[] = SECRET_SSID;
      char pass[] = SECRET_PASS;
      int status = WL_IDLE_STATUS;

   - ``ssid`` と ``pass`` にはネットワーク名とパスワードが含まれます。
   - ``status`` はWi-Fi接続の現在のステータスを格納します。

   .. raw:: html

      <br/>

3. ``setup()`` 関数

   シリアルインターフェースは9600のボーレートで初期化されます。 ``while (!Serial);`` 行は、シリアル接続が確立されるまでプログラムが待機することを保証します。

   .. code-block:: arduino

      void setup() {
           //Initialize serial and wait for port to open:
          Serial.begin(9600);
          while (!Serial) {
            ; // wait for serial port to connect. Needed for native USB port only
          }
          ...
      }

   そして、コードはWi-Fiモジュールが利用可能かどうかをチェックします。利用不可の場合、プログラムは停止し、それ以上の実行を防ぎます。

   .. code-block:: arduino

     ...
     // check for the WiFi module:
     if (WiFi.status() == WL_NO_MODULE) {
         Serial.println("Communication with WiFi module failed!");
         // don't continue
         while (true);
     }
     ...

   このコードの部分では、uno R4 wifiのファームウェアバージョンが最新かどうかを確認します。最新バージョンでない場合、アップグレードの促し表示がされます。ファームウェアのアップグレードについては、 :ref:`update_firmware` を参照してください。

   .. https://forum.arduino.cc/t/radio-module-firmware-version-0-2-0-is-now-available/1147361

   .. code-block:: arduino

      ...
      String fv = WiFi.firmwareVersion();
      if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
          Serial.println("Please upgrade the firmware");
      }
      ...

4. ``loop()`` 関数

   .. code-block:: arduino

      void loop() {
        // check the network connection once every 10 seconds:
        delay(10000);
        printCurrentNet();
      }

   - 10秒ごとに ``printCurrentNet()`` 関数が呼び出され、現在のネットワークの詳細を印刷します。


**参照**

- |link_r4_wifi|
