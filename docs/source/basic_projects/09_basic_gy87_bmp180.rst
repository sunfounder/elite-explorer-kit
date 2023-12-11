.. _basic_gy87_bmp180:

BMP180
==========================

概要
---------------

このチュートリアルでは、GY-87 IMUモジュールに焦点を当て、特に気温、気圧、高度を測定するためのBMP180センサーについて詳しく解説します。天気監視や高度追跡などの用途に理想的なこのレッスンでは、GY-87をArduino Unoとインターフェースし、Adafruit BMP085ライブラリを使用する方法について紹介します。BMP180センサーを初期化し、Arduinoシリアルモニターでそのデータを読み取る方法を学ぶことができます。これは、環境データを必要とするプロジェクトにとって重要なスキルです。

必要なコンポーネント
-------------------------

このプロジェクトには、以下のコンポーネントが必要です。

全てのキットを一括で購入するのが便利です。リンクはこちらです：

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
    *   - :ref:`cpn_gy87`
        - \-


配線図
----------------------

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 75%

.. raw:: html

   <br/>


回路図
-----------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%



コード
-----------

.. note::

    * ファイル ``09-gy87_bmp180.ino`` を直接 ``elite-explorer-kit-main\basic_project\09-gy87_bmp180`` のパスから開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. note:: 
    ライブラリをインストールするには、Arduinoライブラリマネージャーを使用し、 **「Adafruit BMP085 Library」** を検索してインストールしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7f7347f7-e1e6-400f-b10c-02ccf300b3b9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


コード解析
------------------------

- ``initializeBMP180()``

  BMP180センサーの初期化。

  .. code-block:: arduino

     void initializeBMP180() {
       // Start BMP180 initialization
       if (!bmp.begin()) {
         Serial.println("Could not find a valid BMP180 sensor, check wiring!");
         while (1)
           ;  // Halt if sensor not found
       }
       Serial.println("BMP180 Found!");
     }

- ``printBMP180()``

  BMP180センサーによって読み取られた値を表示します。


  .. code-block:: arduino

     void printBMP180() {
       Serial.println();
       Serial.println("BMP180 ------------");
       Serial.print("Temperature = ");
       Serial.print(bmp.readTemperature());
       Serial.println(" *C");
     
       Serial.print("Pressure = ");
       Serial.print(bmp.readPressure());
       Serial.println(" Pa");
     
       // Calculate altitude assuming 'standard' barometric
       // pressure of 1013.25 millibar = 101325 Pascal
       Serial.print("Altitude = ");
       Serial.print(bmp.readAltitude());
       Serial.println(" meters");
     
       Serial.print("Pressure at sealevel (calculated) = ");
       Serial.print(bmp.readSealevelPressure());
       Serial.println(" Pa");
       Serial.println("BMP180 ------------");
       Serial.println();
     }


