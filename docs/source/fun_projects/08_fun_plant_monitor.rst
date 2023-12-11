.. _fun_plant_monitor:

植物モニター
============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/08_fun_plant_monitor.mp4"  type="video/mp4">
      お使いのブラウザではビデオタグがサポートされていません。
   </video>

このプロジェクトは、土壌の湿度が特定のしきい値以下になったときに水ポンプを起動して自動的に植物に水をやります。
さらに、LCDスクリーンに温度、湿度、土壌の湿度を表示し、ユーザーに植物の成長環境についての洞察を提供します。

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
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|
    *   - :ref:`cpn_power`
        - \-

**配線図**

.. image:: img/08_plant_monitor_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**回路図**

.. image:: img/08_plant_monitor_schematic.png
   :width: 100%
   :align: center

.. raw:: html

   <br/>

**コード**

.. note::

    * ファイル ``08_plant_monitor.ino`` を ``elite-explorer-kit-main\fun_project\08_plant_monitor`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. note::
   ライブラリをインストールするには、Arduinoライブラリマネージャーを使用し、 **「DHT sensor library」** と **「LiquidCrystal I2C」** を検索してインストールしてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/a9d6c9c7-0d7f-4dc2-84b6-9dbda15c89ae/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**どのように動作するのか？**

以下はコードの詳細な説明です：

1. ライブラリのインポートと定数/変数の定義：

   ``Wire.h``、 ``LiquidCrystal_I2C.h``、 ``DHT.h`` ライブラリをインポートします。
   DHT11、土壌湿度センサー、水ポンプに関連するピン番号やその他のパラメータを定義します。

2. ``setup()``：

   土壌湿度センサーと水ポンプに関連するピンモードを初期化します。
   最初に水ポンプをオフにします。
   LCDディスプレイを初期化し、バックライトを点灯させます。
   DHTセンサーを起動します。

3. ``loop()``：

   DHTセンサーから湿度と温度を読み取ります。
   土壌湿度センサーから土壌の湿度を読み取ります。
   LCDスクリーンに温度と湿度の値を表示し、その後画面をクリアして土壌湿度の値を表示します。
   土壌湿度に基づいて水ポンプを起動するかどうかを決定します。土壌湿度が500（設定可能なしきい値）以下の場合、1秒間水ポンプを起動します。
