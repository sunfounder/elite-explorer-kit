.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _iot_weathertime_screen:

WeatherTime スクリーン
===============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/06_iot_weather_oled.mp4"  type="video/mp4">
      お使いのブラウザではビデオタグがサポートされていません。
   </video>

このスケッチはWi-Fiネットワークに接続し、毎分OpenWeatherMapから天気データを取得し、NTPサーバーから現在時刻を取得し、OLEDスクリーンに日付、時刻、天気情報を表示します。

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_oled`
        - |link_oled_buy|

**配線図**

.. image:: img/06_weather_oled_bb.png
    :width: 100%
    :align: center

**回路図**

.. image:: img/06_weather_oled_schematic.png
    :width: 60%
    :align: center

**OpenWeather**

OpenWeather APIキーの取得

.. .|link_openweather|は、OpenWeather Ltdが所有するオンラインサービスで、API経由でグローバルな天気データを提供しています。これには、現在の天気データ、予報、ナウキャスト、歴史的天気データが任意の地理的位置に含まれます。

`OpenWeather <https://openweathermap.org/>`_ は、OpenWeather Ltdが所有するオンラインサービスで、API経由でグローバルな天気データを提供しています。これには、現在の天気データ、予報、ナウキャスト、歴史的天気データが任意の地理的位置に含まれます。


#. OpenWeatherにログインするか、アカウントを作成します。

   .. image:: img/06_owm_1.png


#. ナビゲーションバーからAPIページに移動します。

   .. image:: img/06_owm_2.png


#. **Current Weather Data** を見つけて、サブスクライブをクリックします。

   .. image:: img/06_owm_3.png


#. **Current weather and forecasts collection** の下で、適切なサービスにサブスクライブします。私たちのプロジェクトでは、Freeで十分です。

   .. image:: img/06_owm_4.png


#. **API keys** ページからキーをコピーします。

   .. image:: img/06_owm_5.png

#. それを ``arduino_secrets.h`` にコピーします。

   .. code-block:: Arduino

       #define SECRET_SSID "<SSID>"        // your network SSID (name)
       #define SECRET_PASS "<PASSWORD>"        // your network password 
       #define API_KEY "<OpenWeather_API_KEY>"
       #define LOCATION "<YOUR CITY>"

#. あなたの場所のタイムゾーンを設定します。

   スウェーデンの首都ストックホルムを例に取ります。Googleで「stockholm timezone」と検索します。

   .. image:: img/06_weather_oled_01.png 

   検索結果で、「GMT+1」を見ることができますので、以下の関数のパラメータを ``3600 * 1`` 秒に設定します。
   
   .. code-block:: Arduino

      timeClient.setTimeOffset(3600 * 1);   // Adjust for your time zone (this is +1 hour)

**ライブラリのインストール**

ライブラリをインストールするには、Arduinoライブラリマネージャーを使用し、「ArduinoMqttClient」、「FastLED」、「Adafruit GFX」、「Adafruit SSD1306」を検索してインストールします。

``ArduinoJson.h``：JSONデータ（openweathermapから取得されたデータ）を扱うために使用します。

``NTPClient.h``：リアルタイムの時間を取得するために使用します。

``Adafruit_GFX.h``、 ``Adafruit_SSD1306.h``：OLEDモジュール用に使用します。

**コードの実行**


.. note::

    * ファイル ``06_weather_oled.ino`` を ``elite-explorer-kit-main\iot_project\06_weather_oled`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. note::
    コード内で、SSIDとパスワードは ``arduino_secrets.h`` に格納されています。この例をアップロードする前に、自分のWiFiの認証情報でそれらを修正する必要があります。さらに、コードを共有または保存する際には、この情報を機密に保つためのセキュリティ対策を講じてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/5f667ac1-bb24-4681-9fa1-db19fcfdd48a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



**どのように動作するのか？**

1. ライブラリと定義:

   #. ``WiFiS3.h``：これは、特定のWiFiモジュールやボードに特有のライブラリで、WiFi接続を管理します。
   #. ``ArduinoJson.h``：このライブラリはJSONデータのデコード（およびエンコード）に使用されます。
   #. ``arduino_secrets.h``：機密データ（WiFiの認証情報など）が格納されている別のファイルです。これは、認証情報をメインコードから外しておくための良い習慣です。
   #. **NTPClient & WiFiUdp**：NTP（Network Time Protocol）サーバーから現在時刻を取得するために使用されます。
   #. **Adafruitライブラリ**：OLEDディスプレイを管理するために使用されます。
   #. **さまざまなグローバル変数**：これにはWiFiの認証情報、サーバーの詳細などが含まれ、スクリプト全体で使用されます。

2. ``setup()``:

   #. シリアル通信を初期化します。
   #. WiFiモジュールのファームウェアバージョンをチェックして印刷します。
   #. 提供されたSSIDとパスワードを使用してWiFiネットワークに接続を試みます。
   #. 接続されたWiFiのステータス（SSID、IP、信号強度）を印刷します。
   #. OLEDディスプレイを初期化します。
   #. NTPクライアントを開始して現在時刻を取得し、タイムオフセットを設定します（この場合は8時間で、特定のタイムゾーンに対応する可能性があります）。

3. ``read_response()``:

   #. サーバーからの応答を読み取り、特にJSONデータ（ ``{`` and ``}`` で示される）を探します。
   #. JSONデータが見つかった場合、データをデコードして、気温、湿度、気圧、風速、風向きなどの天気の詳細を抽出します。
   #. OLEDスクリーンに天気情報を表示する ``displayWeatherData`` 関数を呼び出します。

4. ``httpRequest()``:

   #. 既存の接続を閉じて、WiFiモジュールのソケットが空いていることを確認します。
   #. OpenWeatherMapサーバーに接続を試みます。
   #. 接続された場合、 ``LOCATION`` で定義された特定の場所（おそらく ``arduino_secrets.h`` または他の場所で定義）の天気データを取得するためにHTTP GETリクエストを送信します。
   #. リクエストが行われた時間を記録します。

5. ``loop()``:

   #. サーバーからの受信データを処理するために ``read_response`` 関数を呼び出します。
   #. NTPサーバーから時刻を更新します。
   #. 天気サーバーに別のリクエストを行う時刻かどうかをチェックします（ ``postingInterval`` に基づいて）。そうであれば、 ``httpRequest`` 関数を呼び出します。

6. ``printWifiStatus()``:

   #. 接続されているネットワークのSSID。
   #. ボードのローカルIPアドレス。
   #. 信号強度（RSSI）。

7. ``displayWeatherData()``:

   #. OLEDスクリーンをクリアします。
   #. 現在の曜日を表示します。
   #. 現在時刻をHH:MM形式で表示します。
   #. 提供された天気データ（気温、湿度、気圧、風速）を表示します。

