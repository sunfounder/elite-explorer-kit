.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

スケッチの記述ルール
================================

友人に「電気をつけて」と頼む時、「電気をつけてください」とも「ライトオン、ブロ」とも言えます。どんな口調でも構いません。


しかし、Arduinoボードに何かをさせたい場合は、Arduinoプログラムの記述ルールに従ってコマンドを入力する必要があります。

この章では、Arduino言語の基本ルールについて説明し、自然言語をコードに翻訳する方法を理解するのに役立ちます。

もちろん、これは慣れるまで時間がかかるプロセスであり、初心者にとっては最もエラーが発生しやすい部分ですので、何度も間違えることがあっても大丈夫です。何度か試してみてください。


セミコロン ``;``
------------------

手紙を書く時、文の終わりにピリオドを打つように、Arduino言語では ``;`` を使ってボードにコマンドの終わりを伝える必要があります。

よく知られている「onboard LED blinking」の例を見てみましょう。正常なスケッチは以下のようになります。

例:

.. code-block:: C

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

次に、以下の2つのスケッチを見て、実行する前にArduinoが正しく認識できるかどうかを推測してみましょう。

スケッチA:

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

スケッチB:

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

結果は、 **スケッチA** がエラーを報告し、 **スケッチB** が実行されます。

* **スケッチA** のエラーは ``;`` がなく、見た目は正常ですが、Arduinoは読み取れません。
* **スケッチB** は人間に反するように見えますが、実際にはArduinoプログラムではインデント、改行、空白は存在しないため、Arduinoコンパイラには例と同じように見えます。

しかし、 **スケッチB** のようにコードを書かないでください。通常、コードを書いて見るのは自然な人間ですので、自分自身を困らせないでください。


中括弧 ``{}``
------------------

``{}`` はArduinoプログラミング言語の主要な構成要素であり、必ずペアで現れる必要があります。
より良いプログラミングの慣習は、左の中括弧をタイプした直後に右の中括弧を挿入し、カーソルを中括弧の間に移動して文を挿入することです。



コメント ``//``
---------------

コメントはコンパイラが無視するスケッチの部分です。通常、プログラムの動作を他の人に伝えるために使用されます。

コードの行に隣接するスラッシュを2つ書くと、その行の終わりまでのすべてがコンパイラによって無視されます。

新しいスケッチを作成すると、2つのコメントが付いてきますが、これらのコメントを削除しても、スケッチには何の影響もありません。

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // put your setup code here, to run once:

    }

    void loop() {
        // put your main code here, to run repeatedly:

    }

プログラミングではコメントが非常に役立ちます。以下にその一般的な使用例を挙げます。

* 使用例A：自分自身や他人に、このコードのセクションが何をするかを伝えます。

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); //Set pin 13 to output mode, it controls the onboard LED
    }

    void loop() {
        digitalWrite(13,HIGH); // Activate the onboard LED by setting pin 13 high
        delay(500); // Status quo for 500 ms
        digitalWrite(13,LOW); // Turn off the onboard LED
        delay(500);// Status quo for 500 ms
    }

* 使用例B：いくつかの文を一時的に無効にする（削除せずに）し、使用する際にコメントを外します。これにより、再度書く必要がなくなります。これはコードのデバッグやプログラムのエラーを特定する際に非常に便利です。


.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);
        // digitalWrite(13,HIGH);
        // delay(1000);
        // digitalWrite(13,LOW);
        // delay(1000);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

.. note:: 
    ショートカットキー ``Ctrl+/`` を使用して、コードのコメントの付け外しを迅速に行うことができます。

コメント ``/**/``
------------------

``//`` と同様のコメントです。このタイプのコメントは複数行にわたることができ、コンパイラが ``/*`` を読み込むと、 ``*/`` に遭遇するまで続くすべてを無視します。

例1：

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Blink */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        The following code will blink the onboard LED
        You can modify the number in delay() to change the blinking frequency
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }


``#define``
--------------

これはC++での便利なツールです。

.. code-block:: C

    #define identifier token-string

コンパイラは ``identifier`` を読み込むときに自動的に ``token-string`` に置き換えます。これは通常、定数の定義に使用されます。

例として、defineを使用したスケッチを以下に示します。これによりコードの可読性が向上します。

.. code-block:: C
    :emphasize-lines: 1,2

    #define ONBOARD_LED 13
    #define DELAY_TIME 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
        delay(DELAY_TIME); 
        digitalWrite(ONBOARD_LED,LOW); 
        delay(DELAY_TIME);
    }

コンパイラにとって、実際は以下のように見えます。

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

``identifier`` は置き換えられてプログラム内には存在しません。
したがって、使用する際にはいくつかの注意点があります。

1. ``token-string`` は手動でのみ変更でき、プログラム内の算術で他の値に変換することはできません。

2. ``;`` などの記号の使用を避けること。例えば、

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

コンパイラは以下のように認識し、エラーが報告されます。

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
       pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    ``#define`` の命名規則としては、変数との混同を避けるために ``identifier`` を大文字にすることが一般的です。
