.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _iot_mqtt_publish:

MQTTを使用したクラウドコールシステム
============================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/04_iot_mqtt_callling.mp4"  type="video/mp4">
      お使いのブラウザではビデオタグがサポートされていません。
   </video>

メッセージキューイングテレメトリートランスポート（MQTT）は、直感的なメッセージングプロトコルです。これは、インターネットオブシングス（IoT）の分野で最も広く使用されているメッセージングプロトコルでもあります。

MQTTプロトコルは、IoTデバイスがデータを交換する方法を定義します。イベント駆動型であり、Publish/Subscribeモデルを使用して相互に接続されます。送信者（パブリッシャー）と受信者（サブスクライバー）はトピックを介して通信します。デバイスは特定のトピックにメッセージを公開し、そのトピックにサブスクライブしているすべてのデバイスがメッセージを受け取ります。

このセクションでは、UNO R4、HiveMQ（無料の公開MQTTブローカーサービス）、および4つのボタンを使用してサービスベルシステムを作成します。4つのボタンのそれぞれがレストランのテーブルに対応し、顧客がボタンを押すと、HiveMQ上でどのテーブルにサービスが必要かを確認できます。

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
    *   - :ref:`cpn_button`
        - |link_button_buy|


**配線図**

.. image:: img/04_mqtt_button_bb.png
   :width: 70%
   :align: center

**回路図**

.. image:: img/04_mqtt_button_schematic.png
   :width: 50%
   :align: center

**遊び方は？**

HiveMQは、IoTデバイスへの迅速で効率的で信頼性の高いデータ転送を促進するMQTTブローカーおよびクライアントベースのメッセージングプラットフォームです。

1. Webブラウザで |link_hivemq| を開きます。

2. クライアントをデフォルトの公開プロキシに接続します。

   .. image:: img/04_mqtt_1.png

3. **Add New Topic Subscription** をクリックします。

   .. image:: img/04_mqtt_2.png

4. フォローしたいトピックを入力し、 **Subscribe** をクリックします。他のユーザーからのメッセージを受け取らないように、ここで設定したトピックがユニークであることを確認し、大文字と小文字の区別に注意してください。

   この例のコードでは、トピックを ``SunFounder MQTT Test`` と設定しました。変更がある場合は、コード内のトピックがWebページで購読したトピックと一致していることを確認してください。

   .. image:: img/04_mqtt_3.png


**ライブラリのインストール**

ライブラリをインストールするには、Arduinoライブラリマネージャーを使用し、「ArduinoMqttClient」と検索してインストールしてください。

``ArduinoMqttClient.h``：MQTT通信用に使用します。

**コードの実行**

.. note::

    * ファイル ``04_mqtt_button.ino`` を ``elite-explorer-kit-main\iot_project\04_mqtt_button`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. note::
    コード内で、SSIDとパスワードは ``arduino_secrets.h`` に格納されています。この例をアップロードする前に、自分のWiFiの認証情報でそれらを修正する必要があります。さらに、コードを共有または保存する際には、この情報を機密に保つためのセキュリティ対策を講じてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/7a4acdf8-beed-47d4-ada8-cbaab0f3477f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードを実行した後、 |link_hivemq| に戻り、ブレッドボード上のボタンのいずれかを押すと、HiveMQ上でメッセージプロンプトが表示されます。

    .. image:: img/04_mqtt_4.png
  
**どのように動作するのか？**

このコードは、Wi-Fiに接続し、MQTTプロトコルを使用してMQTTブローカーと通信するArduinoベースのプロジェクト用です。さらに、4つのボタンが押されたかどうかを検出し、対応するメッセージをMQTTブローカーに送信することができます。

コードの詳細な説明は以下の通りです：

1. **関連するライブラリを含む**：

   .. code-block:: Arduino
       
       #include <WiFiS3.h>
       #include <ArduinoMqttClient.h>

2. **機密情報を含む**：

   * ``arduino_secrets.h`` ファイルにはWi-FiネットワークのSSIDとパスワードが含まれています。
   
   .. code-block:: Arduino
       
       #include "arduino_secrets.h" 
       char ssid[] = SECRET_SSID;   
       char pass[] = SECRET_PASS;   

3. **変数の初期化**：

   * Wi-FiおよびMQTT接続を管理するための変数。
   * ボタンピンとボタンの状態を初期化します。

4. ``setup()``：

   * シリアル通信を初期化します。
   * Wi-Fiモジュールの存在をチェックし、Wi-Fiに接続を試みます。
   * ネットワークデータを印刷します。
   * MQTTブローカーへの接続を試みます。
   * MQTTトピックにサブスクライブします。
   * ボタンを入力モードに設定します。

5. ``loop()``：

   * MQTT接続をアクティブに保ちます。
   * 各ボタンが押されたかどうかをチェックし、もしそうならMQTTメッセージを送信します。

6. **その他のユーティリティ関数**：

   * ``printWifiData()``：現在接続されているWi-Fiネットワークに関する情報を印刷します。
   * ``printCurrentNet()``：現在のネットワークに関する関連データを印刷します。
   * ``printMacAddress(byte mac[])``：MACアドレスを印刷します。
   * ``onMqttMessage(int messageSize)``：MQTTブローカーからメッセージを受信したときにトリガーされるコールバック関数です。受信したメッセージのトピックと内容を印刷します。
   * ``sendButtonMessage(int buttonNumber)``：ボタンが押されたときにMQTTメッセージを送信するためにこの関数を使用します。

