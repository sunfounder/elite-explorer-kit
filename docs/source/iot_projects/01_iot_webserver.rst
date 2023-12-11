シンプルなWebサーバー
===========================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/new_feature_projects/wifi.mp4"  type="video/mp4">
      お使いのブラウザではビデオタグがサポートされていません。
   </video>

このシンプルなArduinoプログラムは、基本的なWiFiウェブサーバーを作成するように設計されており、ユーザーはウェブブラウザを介してArduinoボード上のLEDのオンとオフを制御できます。

**コードの実行**

.. note::

    * ファイル ``01_simple_webserver.ino`` を ``elite-explorer-kit-main\iot_project\01_simple_webserver`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. note::
    コード内で、SSIDとパスワードは ``arduino_secrets.h`` に格納されています。この例をアップロードする前に、自分のWiFiの認証情報でそれらを修正する必要があります。さらに、コードを共有または保存する際には、この情報を機密に保つためのセキュリティ対策を講じてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/7ed8f58d-2ed8-4dc9-82cb-7e49b6977ea1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


コードをアップロードした後、シリアルモニタでIPアドレスを確認できます。このIPアドレスをウェブブラウザに入力することで、オンボードLEDをオン/オフに切り替えることができます。

.. image:: img/01_webserver.png

**どのように動作するのか？**

以下はコードの説明です：

1. ヘッダーファイルとグローバル変数：

   * ``#include 「WiFiS3.h」``：WiFi接続および管理のためのWiFiライブラリを含みます。このライブラリはArduino UNO R4 Coreに含まれているので、追加のインストールは必要ありません。
   * ``#include 「arduino_secrets.h」``：SSIDやパスワードなどの機密WiFi接続データを含みます。
   * ``ssid``, ``pass``, ``keyIndex``：WiFi接続に使用されるネットワーク認証情報です。
   * ``led``, ``status``, ``server``：LEDピン、WiFiステータス、ウェブサーバーオブジェクトを定義します。

2. ``setup()``：

   * シリアル通信を開始します。
   * WiFiモジュールの存在を確認します。
   * WiFiモジュールのファームウェアバージョンが最新であるかを確認します。
   * WiFiネットワークに接続を試みます。
   * ウェブサーバーを開始します。
   * WiFiステータスを印刷します。

3. ``loop()``：

   * 新しいウェブクライアント接続をチェックします。
   * クライアント接続がある場合は、そのHTTPリクエストを読み取ります。
   * リクエストに基づいて、LEDのオン/オフ状態を制御します。たとえば、リクエストが「GET /H」の場合はLEDをオンにし、「GET /L」の場合はオフにします。
   * HTTPレスポンスを送信して、LEDの制御方法をユーザーに指示します。
   * クライアントを切断します。

4. ``printWifiStatus()``：

   * 接続されているWiFi SSIDを印刷します。
   * ArduinoボードのIPアドレスを印刷します。
   * 受信した信号強度を印刷します。
   * ウェブブラウザでこのページを表示する方法を説明します。

