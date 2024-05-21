.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _iot_security_system_ifttt:

IFTTTを使用したセキュリティシステム
============================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/03_iot_security_alert.mp4"  type="video/mp4">
      お使いのブラウザではビデオタグがサポートされていません。
   </video>

このプロジェクトでは、PIRセンサーを使用して侵入者や家に入ってくる野良動物を検出するセキュリティデバイスを作成します。侵入が発生した場合、メールアラートを受け取ります。

基本的なサービスとしてWebhooksを利用します。UNO R4からIFTTTのサービスへPOSTリクエストが送信されます。

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**配線図**

.. image:: img/03-ifttt_pir_bb.png
    :width: 90%
    :align: center


**回路図**

.. image:: img/03-ifttt_pir_schematic.png
   :width: 50%
   :align: center

**IFTTTの設定**

IFTTTは、さまざまなデータサービスを連携する方法を提供する無料のサービスです。

ウェブフック（カスタムURL）をIFTTTに送信して応答するAppletを作成し、その後メールを送信します。

IFTTTで以下の手順に従ってください。

1. |link_ifttt| にアクセスしてログインまたはアカウントを作成します。

   .. image:: img/03_ifttt_1.png
       :width: 90%

2. **Create** をクリックします。

   .. image:: img/03_ifttt_2.png
       :width: 90%

3. **If This** イベントを追加します。

   .. image:: img/03_ifttt_3.png
       :width: 70%

4. **Webhooks** を検索します。

   .. image:: img/03_ifttt_4.png
       :width: 70%

5. **Receive a web request** を選択します。

   .. image:: img/03_ifttt_5.png
       :width: 90%

6. イベント名（例：SecurityWarning）を入力し、 **Create trigger** をクリックします。

   .. image:: img/03_ifttt_6.png
       :width: 70%

7. **Then That** イベントを追加します。

   .. image:: img/03_ifttt_7.png
       :width: 70%

8. Emailを検索します。

   .. image:: img/03_ifttt_8.png
       :width: 80%

9. **Send me an email** を選択します。

   .. image:: img/03_ifttt_9.png
       :width: 80%

10. **Subject** と **Body** を入力し、 **Create action** をクリックします。

   .. image:: img/03_ifttt_10.png
       :width: 70%

11. **Continue** をクリックして設定を完了します。

   .. image:: img/03_ifttt_11.png
       :width: 70%

12. 必要に応じてタイトル名を調整します。

   .. image:: img/03_ifttt_12.png
       :width: 80%

13. Appletの詳細ページに自動的にリダイレクトされます。ここで、Appletが現在接続されていることが確認でき、スイッチを切り替えて有効/無効にすることができます。

   .. image:: img/03_ifttt_13.png
       :width: 70%

14. IFTTT Appletを作成したので、デバイスがIFTTTにアクセスするために必要なWebhooksキーも必要です。これは、 |link_webhooks| から取得できます。

   .. image:: img/03_ifttt_14.png

15. Webhooksキーを「arduino_secrets.h」にコピーし、SSIDとパスワードを入力してください。

    .. code-block:: arduino
    
        #define SECRET_SSID "your_ssid"        // your network SSID (name)
        #define SECRET_PASS "your_password"        // your network password (used for WPA, or as a key for WEP)
        #define WEBHOOKS_KEY "your_key"

**コードの実行**

.. note::

    * ファイル ``03_ifttt_pir.ino`` を ``elite-explorer-kit-main\iot_project\03_ifttt_pir`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. note::
    コード内で、SSIDとパスワードは ``arduino_secrets.h`` に格納されています。この例をアップロードする前に、自分のWiFiの認証情報でそれらを修正する必要があります。さらに、コードを共有または保存する際には、この情報を機密に保つためのセキュリティ対策を講じてください。

.. warning::
   メールボックスが溢れるのを防ぐため、このプロジェクトのコードを実行する前に :ref:`cpn_pir` をデバッグしてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/adec1608-4642-4469-bdf4-8dc3e3e4ce4d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**どのように動作するのか？**

1. 必要なライブラリとヘッダーファイルを含みます：

   * ``「WiFiS3.h」``: Wi-Fi接続の管理に使用します。
   * ``「arduino_secrets.h」``: Wi-Fiネットワーク名とパスワードなどの機密情報を含みます。

2. グローバル変数と定数を定義します：

   * ``ssid``: Wi-Fiネットワークの名前。
   * ``pass``: Wi-Fiネットワークのパスワード。
   * ``status``: Wi-Fi接続の状態。
   * ``client``: Wi-Fiサーバーとの通信に使用するクライアント。
   * ``server``: IFTTT Webhookサーバーのアドレス。
   * ``event``: IFTTT Webhookイベントの名前。
   * ``webRequestURL``: HTTPリクエストを送信するための構築されたURL。Webhookイベント名とキーを含みます。
   * ``pirPin``: PIRセンサーが接続されているデジタルピン。
   * ``motionDetected``: 動き検出を追跡するフラグ変数。

3. ``setup()`` 関数：

   * シリアル通信を初期化します。
   * Wi-Fiモジュールの存在をチェックし、そのファームウェアバージョンを出力します。
   * Wi-Fiネットワークに接続を試み、失敗した場合は再試行します。
   * PIRセンサーが接続されているピンを入力モードに設定します。

4. ``readResponse()`` 関数：

   * IFTTTサーバーからのHTTP応答データを読み取り、シリアルコンソールに印刷します。

5. ``loop()`` 関数：

   * ``readResponse()`` 関数を呼び出してHTTP応答データを読み取ります。
   * PIRセンサーを使用して動きをチェックします。動きが検出され、以前に検出されていない場合：
       * コンソールに「動きを検出！」と印刷します。
       * ``triggerIFTTTEvent()`` 関数を呼び出し、IFTTTサーバーにHTTPリクエストを送信し、Webhookイベントをトリガーします。
       * ``motionDetected`` フラグを ``true`` に設定して、動きが検出されたことを示します。
   * 動きが検出されない場合は、 ``motionDetected`` フラグを ``false`` に設定します。

6. ``triggerIFTTTEvent()`` 関数：

   * IFTTTサーバーとの接続を確立します。
   * HTTP GETリクエストを送信し、WebhookイベントのURLと他のHTTPヘッダーを含みます。

7. ``printWifiStatus()`` 関数：

   * 接続されているWi-Fiネットワークに関する情報をシリアルコンソールに出力します。これにはSSID、IPアドレス、信号強度（RSSI）が含まれます。

