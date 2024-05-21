.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _basic_gy87_mpu6050:

MPU6050
==========================

概要
---------------

このチュートリアルでは、GY-87 IMUモジュールをArduino Unoと接続し、MPU6050センサーに焦点を当てて学びます。MPU6050の初期化と、加速度計、ジャイロスコープ、温度データをシリアルモニターに表示する方法をカバーします。このレッスンは、ロボティクス、ジェスチャー制御デバイス、インタラクティブなアートインスタレーションなど、運動と温度センシングが必要なプロジェクトに不可欠です。

必要なコンポーネント
-------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

キットを丸ごと購入すると便利です。リンクはこちらです：

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

    * ファイル ``09-gy87_mpu6050.ino`` を直接 ``elite-explorer-kit-main\basic_project\09-gy87_mpu6050`` のパスから開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. note:: 
    ライブラリをインストールするには、Arduino Library Managerを使用し、 **「Adafruit MPU6050」** を検索してインストールしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f89edd5d-e6f9-4f83-979c-6c1d5da3e9d7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


コード解析
------------------------

#. ライブラリのインクルード

   センサーのインターフェースと通信のために、 ``Adafruit_MPU6050``, ``Adafruit_Sensor``, ``Wire`` ライブラリが含まれています。

   .. code-block:: arduino

      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>

#. センサーオブジェクトの初期化

   Adafruit_MPU6050 クラスのオブジェクトを作成し、MPU6050 センサーを表します。

   .. code-block:: arduino

      Adafruit_MPU6050 mpu;

#. セットアップ関数

   シリアル通信を初期化し、MPU6050 センサーを初期化する関数を呼び出します。

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        initializeMPU6050();
      }

#. ループ関数

   MPU6050 のデータを表示する関数を繰り返し呼び出し、各呼び出しの間に 500 ミリ秒の遅延を入れます。

   .. code-block:: arduino

      void loop() {
        printMPU6050();
        delay(500);
      }

#. MPU6050 の初期化関数

   MPU6050 が接続されているかを確認し、加速度計とジャイロの範囲を設定し、フィルタの帯域幅を設定します。

   .. code-block:: arduino

      void initializeMPU6050() {
        // Check if the MPU6050 sensor is detected
        if (!mpu.begin()) {
          Serial.println("Failed to find MPU6050 chip");
          while (1)
            ;  // Halt if sensor not found
        }
        Serial.println("MPU6050 Found!");
      
        // set accelerometer range to +-8G
        mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
      
        // set gyro range to +- 500 deg/s
        mpu.setGyroRange(MPU6050_RANGE_500_DEG);
      
        // set filter bandwidth to 21 Hz
        mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
      
        Serial.println("");
        delay(100);
      }

#. MPU6050 データ表示関数

   MPU6050 から加速度、ジャイロスコープ、温度データを読み取り、シリアルモニターに表示します。

   .. code-block:: arduino

      void printMPU6050() {
      
        Serial.println();
        Serial.println("MPU6050 ------------");
      
        /* Get new sensor events with the readings */
        sensors_event_t a, g, temp;
        mpu.getEvent(&a, &g, &temp);
      
        /* Print out the values */
        Serial.print("Acceleration X: ");
        Serial.print(a.acceleration.x);
        Serial.print(", Y: ");
        Serial.print(a.acceleration.y);
        Serial.print(", Z: ");
        Serial.print(a.acceleration.z);
        Serial.println(" m/s^2");
      
        Serial.print("Rotation X: ");
        Serial.print(g.gyro.x);
        Serial.print(", Y: ");
        Serial.print(g.gyro.y);
        Serial.print(", Z: ");
        Serial.print(g.gyro.z);
        Serial.println(" rad/s");
      
        Serial.print("Temperature: ");
        Serial.print(temp.temperature);
        Serial.println(" degC");
      
        Serial.println("MPU6050 ------------");
        Serial.println();
      }
