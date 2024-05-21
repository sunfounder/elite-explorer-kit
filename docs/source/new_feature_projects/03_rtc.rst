.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _new_rtc:

リアルタイムクロック
========================================

UNO R4 WiFiのマイクロコントローラー（RA4M1）にはRTC（リアルタイムクロック）が統合されています。RTCは、バッテリーなどのバックアップ電源によって、メインの電源が切断されていても動作することができる自律的な時計モジュールです。これにより、RTCは、家庭用オートメーションシステムでのタイムスケジュールされたタスクの実行や、データログ記録アプリケーションでのデータポイントのタイムスタンプ付けなど、様々なアプリケーションで非常に柔軟に使用できます。

.. note::
    UNO R4 WiFiには、ボードが電源を失ってもオンボードRTCの動作を維持するVRTCピンがあります。この機能を利用するためには、VRTCピンに1.6Vから3.6Vの電圧を適用してください。



定期的な繰り返しタスク
++++++++++++++++++++++++++++++++++++++++++++

特定のユースケースでは、定期的に特定のタスクを実行する必要があります。周期的な割り込みを設定するためには、まず周期的なコールバック関数を初期化する必要があります。以下は、周期的な割り込みを使用して2秒ごとにLEDを点滅させるArduinoコードの例です。


**コードのアップロード**

``03-rtc.ino`` ファイルを ``elite-explorer-kit-main\r4_new_feature\03-rtc`` で開くか、以下のコードをArduino IDEに貼り付けてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/48777cc6-f8a5-4646-b221-36c883ed5a62/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**コードの説明**

1. コンポーネントとライブラリの初期化

   .. code-block:: arduino
   
     #include "RTC.h"
     volatile bool irqFlag = false;
     bool ledState = false;
     const int led = LED_BUILTIN;
   
     void setup() {
       pinMode(led, OUTPUT);
       Serial.begin(9600);
       RTC.begin();
     }
   
   - ``#include "RTC.h"``: RTCライブラリを含めます。
   - ``volatile bool irqFlag = false;``: ボライルなブール型フラグを宣言します。 ``volatile`` は、割り込みによって安全に変数にアクセスまたは変更できることを保証します。 ``volatile`` の詳細については、 `Arduinoのvolatileドキュメント <https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/>`_ を参照してください。
   - ``bool ledState = false;``: LEDの状態を追跡するためのブール型を宣言します。
   - ``const int led = LED_BUILTIN;``: 内蔵LEDピンのための定数を宣言します。
   - ``pinMode(led, OUTPUT);``: LEDピンを出力に設定します。
   - ``Serial.begin(9600);``: シリアル通信を9600ボーで初期化します。
   - ``RTC.begin();``: RTCを初期化します。

   .. raw:: html
    
        <br/>

2. リアルタイムクロックの設定

   .. code-block:: arduino
   
     RTCTime mytime(30, Month::JUNE, 2023, 13, 37, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);
     RTC.setTime(mytime);
   
   - ``RTCTime mytime(...);``: 特定の日付と時刻で初期化された ``RTCTime`` オブジェクトを作成します。
   - ``RTC.setTime(mytime);``: 初期化された時刻でRTCを設定します。
   
   定期的なコールバックの設定と確認
   
   .. code-block:: arduino
   
     if (!RTC.setPeriodicCallback(periodicCallback, Period::ONCE_EVERY_2_SEC)) {
       Serial.println("ERROR: periodic callback not set");
     }
   
     void loop() {
       if (irqFlag) {
         Serial.println("Timed CallBack");
         ledState = !ledState;
         digitalWrite(led, ledState);
         irqFlag = false;
       }
     }
   
     void periodicCallback() {
       irqFlag = true;
     }
   
   - ``RTC.setPeriodicCallback(...);``: 2秒ごとにトリガーされる定期的なコールバックを設定します。期間は以下の列挙で指定できます：

      - ``ONCE_EVERY_2_SEC``
      - ``ONCE_EVERY_1_SEC``
      - ``N2_TIMES_EVERY_SEC``
      - ``N4_TIMES_EVERY_SEC``
      - ``N8_TIMES_EVERY_SEC``
      - ``N16_TIMES_EVERY_SEC``
      - ``N32_TIMES_EVERY_SEC``
      - ``N64_TIMES_EVERY_SEC``
      - ``N128_TIMES_EVERY_SEC``
      - ``N256_TIMES_EVERY_SEC``

   - ``void loop() {...}``: コールバックがトリガーされたかどうかを確認します。トリガーされていれば、LEDの状態をトグルします。
   - ``void periodicCallback() {...}``: トリガーされたときに``irqFlag = true``を設定するコールバック関数です。


**参照**

- |link_r4_rtc|