.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

Arduinoプログラムの構造
===========================

新しいスケッチファイルを見てみましょう。いくつかのコード行がありますが、実際には「空の」スケッチです。
このスケッチを開発ボードにアップロードしても何も起こりません。

.. code-block:: C

    void setup() {
    // put your setup code here, to run once:

    }

    void loop() {
    // put your main code here, to run repeatedly:

    }

``setup()`` と ``loop()`` を削除し、スケッチを本当の ``blank`` のファイルにすると、検証に合格しないことがわかります。
これらは人間の骨格に相当し、欠かせないものです。

スケッチ中には、 ``setup()`` が最初に実行され、その中のコード（ ``{}`` の中）はボードが電源投入またはリセットされた後に一度だけ実行されます。
``loop()`` はメイン機能の記述に使用され、 ``setup()`` の実行後にループで実行されるコードを書きます。

setup()とloop()をより理解するために、4つのスケッチを使用してみましょう。それらの目的は、ArduinoのオンボードLEDを点滅させることです。各実験を順番に実行し、それぞれの具体的な効果を記録してください。

* スケッチ1：オンボードLEDを連続して点滅させます。

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

* スケッチ2：オンボードLEDを一度だけ点滅させます。

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // put your main code here, to run repeatedly:
    }

* スケッチ3：オンボードLEDを一度ゆっくり点滅させ、その後速く点滅させます。

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* スケッチ4：エラーを報告します。

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // put your main code here, to run repeatedly:
    }    

これらのスケッチを使って、 ``setup-loop`` のいくつかの特徴をまとめることができます。

* ``loop()`` は、ボードに電源が投入された後、繰り返し実行されます。
* ``setup()`` は、ボードに電源が投入された後、一度だけ実行されます。
* ボードに電源が投入された後、最初に ``setup()`` が実行され、その後に ``loop()`` が実行されます。
* コードは、 ``setup()`` または ``loop()`` の ``{}`` の範囲内に記述する必要があります。枠外に記述するとエラーになります。

.. note::  
    ``digitalWrite(13,HIGH)`` などの文は、オンボードLEDを制御するために使用されます。これらの使用方法については、後の章で詳しく説明します。

