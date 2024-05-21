.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _basic_mpr121:

MPR121
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.24_mpr121_module.html#ar-mpr121


概要
---------------

このレッスンでは、MPR121の使用方法を学びます。プロジェクトに多くのタッチスイッチを追加したい場合に適しています。MPR121の電極は導体で延長できます。ワイヤーをバナナに接続すれば、バナナをタッチスイッチに変えることができ、フルーツピアノのようなプロジェクトを実現できます。

必要なコンポーネント
-------------------------

このプロジェクトには、以下のコンポーネントが必要です。

全セットを購入するのが便利です。こちらがリンクです：

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_mpr121`
        - \-

配線図
----------------------

この例では、MPR121をブレッドボードに挿入します。MPR121のGNDをGNDに、3.3Vを3V3に、IRQをデジタルピン2に、SCLをピンSCL(A5)に、SDAをピンSDA(A4)に接続します。タッチセンシング用の12個の電極があります。

.. note::
    MPR121は3.3Vで動作します。5Vではありません。

.. image:: img/23-mpr121_bb.png
    :align: center
    :width: 70%

回路図
----------------------

.. image:: img/23_mpr121_schematic.png
   :align: center
   :width: 70%

コード
--------

.. note::

    * ファイル ``23-mpr121.ino`` を ``elite-explorer-kit-main\basic_project\23-mpr121`` のパスで直接開くことができます。
    * ここでは ``Adafruit MPR121`` ライブラリを使用しています。 **Library Manager** からインストールできます。

        .. image:: img/22_mpr121_lib.png
            :align: center

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/de0aa390-de85-43ab-87f7-f380c67c65e8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

UNOボードにコードをアップロードした後、MPR121のピン「1」と「0」のタッチ状態が12ビットのブール配列に記録されます。この配列はシリアルモニターに表示されます。


コード解析
--------------------
このコードは、MPR121タッチセンサーの通信と操作を容易にします。タッチ電極の状態を検出し、タッチされたり解放されたりした電極に関する情報をシリアルインターフェースに出力することができます。詳細なセンサーデータが必要な場合は、関連するコードのコメントを外すことができます。

コードの分析は以下の通りです：

#. ライブラリのインポート：

   .. code-block:: arduino

       #include <Wire.h>
       #include "Adafruit_MPR121.h"

   * ``Wire.h``：I2C通信用。
   * ``Adafruit_MPR121.h``：AdafruitのMPR121ライブラリで、MPR121タッチセンサーの操作に使用します。

#. ``_BV`` マクロの定義：

   .. code-block:: arduino

       #ifndef _BV
       #define _BV(bit) (1 << (bit)) 
       #endif
   
   ``_BV(bit)`` は、指定されたビットを対応するバイナリ値に変換するマクロを定義します。これは1 << bitに似ています。

#. ``Adafruit_MPR121`` クラスインスタンスの初期化：

   .. code-block:: arduino

       Adafruit_MPR121 cap = Adafruit_MPR121();

   ``Adafruit_MPR121`` クラスのインスタンスを ``cap`` として作成します。 ``cap`` オブジェクトは、MPR121タッチセンサーとの通信および操作に使用されます。

#. ``setup()`` 関数：

   9600ボーレートでシリアル通信を初期化し、デフォルトのI2Cアドレス0x5AでMPR121タッチセンサーを初期化します。初期化に失敗した場合は、エラーメッセージを出力し、無限ループに入ります。

   .. code-block:: arduino

       void setup() {
           Serial.begin(9600);
           
           while (!Serial) { // needed to keep leonardo/micro from starting too fast!
               delay(10);
           }
           
           Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
           
           // Default address is 0x5A, if tied to 3.3V its 0x5B
           // If tied to SDA its 0x5C and if SCL then 0x5D
           if (!cap.begin(0x5A)) {
               Serial.println("MPR121 not found, check wiring?");
               while (1);
           }
           Serial.println("MPR121 found!");
       }

#. ``loop()`` 関数：

   * 現在のタッチ状態を取得し、16ビットの整数として返します。


     .. code-block:: arduino

         currtouched = cap.touched();

   * 12個の電極（0から11までの番号）の状態を反復処理します。

     .. code-block:: arduino

         for (uint8_t i=0; i<12; i++) {
            // it if *is* touched and *wasnt* touched before, alert!
             if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
                 Serial.print(i); Serial.println(" touched");
             }
             // if it *was* touched and now *isnt*, alert!
             if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
                 Serial.print(i); Serial.println(" released");
             }
         }

     * もし電極がタッチされ、以前にタッチされていなかった場合、「x touched」と出力します。ここで、xは電極の番号です。
     * もし電極が以前タッチされていたが、現在タッチされていない場合、「x released」と出力します。

   * ``lasttouched`` を更新し、次の反復で比較するための現在のタッチ状態を格納します。

     .. code-block:: arduino

         lasttouched = currtouched;

   * デバッグ情報（オプションのセクション）：

     .. code-block:: arduino

         // debugging info, what
         Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(cap.touched(), HEX);
         Serial.print("Filt: ");
         for (uint8_t i=0; i<12; i++) {
             Serial.print(cap.filteredData(i)); Serial.print("\t");
         }
         Serial.println();
         Serial.print("Base: ");
         for (uint8_t i=0; i<12; i++) {
             Serial.print(cap.baselineData(i)); Serial.print("\t");
         }
         Serial.println();
         
         // put a delay so it isn't overwhelming
         delay(100);
