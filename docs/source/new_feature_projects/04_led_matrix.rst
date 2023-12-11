.. _new_led_matrix:

12x8 LED Matrix
========================================

アルドゥイーノUNO R4 WiFiには、組み込みの12x8 LEDマトリクスが付属しており、さまざまなグラフィックやアニメーションを表示したり、インターフェースとして機能したり、ゲーム体験をサポートしたりするようプログラムできます。

.. image:: img/unor4wifi.webp
    :width: 60%

このガイドでは、LEDマトリクス上に所望のパターンを表示するのを助けるための簡単な例を提供します。

アルドゥイーノでLEDマトリクスデータを保存する方法
-------------------------------------------------

LEDマトリクスを使用するには、Renesasコアと一緒にインストールされる ``Arduino_LED_Matrix`` ライブラリが必要です。

UNO R4 WiFiのLEDマトリクスライブラリは、フレームを作成し、それらを表示するためのバッファにロードすることによって動作します。フレームは通常「画像」とも呼ばれ、マトリクス上に現在表示されている内容を表します。複数の画像から成るアニメーションでは、各画像がフレームと見なされます。

UNO R4 WiFiの12x8 LEDマトリクスを制御するために、少なくとも96ビットのメモリスペースが必要です。ライブラリはこのために2つのアプローチを提供しています。

**1つのアプローチは、2次元配列を使用** し、対応するLEDがオフまたはオンかを示す0と1を使用します。各数字はLEDマトリクス上のLEDに対応します。次の配列はハート形のパターンを示しています。

.. code-block:: arduino
   
   // Use a two-dimensional array to represent a 12x8 LED matrix.
   byte frame[8][12] = {
     { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
     { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
     { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
     { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
     { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
   };

**別のアプローチは、32ビット整数の配列を使用** してLEDマトリクスの状態を保持します。この方法はよりコンパクトですが、やや複雑です。各 ``unsigned long`` は32ビットを格納します。したがって、96個のLEDを含む12x8 LEDマトリクスの場合、少なくとも3つの ``unsigned long`` 変数が必要です。

1. 各 ``unsigned long`` は32ビットを含み、これらのビットはLEDマトリクス内の特定の部分の状態を表すと考えることができます。
2. これらの ``unsigned long`` 変数は、完全なLEDマトリクスの状態をカプセル化する配列を形成します。

以下は、12x8 LEDマトリクスを表すために3つの ``unsigned long`` 変数を使用するコードスニペットです。

.. code-block:: arduino

   // Use an array of 32-bit integers to store the LED matrix.
   unsigned long frame[] = {
     0x3184a444, // State of the first 32 LEDs
     0x42081100, // State of the next 32 LEDs
     0xa0040000  // State of the last 32 LEDs
   };

LEDの状態をより視覚化するために、これらの値をバイナリ形式に変換することができます。各ビットは、左から右へ、上から下へと順番に各LEDの状態を示します。0はオフ、1はオンを示します。

.. code-block:: arduino

   0x3184a444 -> 110001100001001010010001000100
   0x42081100 -> 1000010000010000001000100000000
   0xa0040000 -> 10100000000001000000000000000000

LEDマトリクスにパターンを表示する
-----------------------------------------

パターンが準備できたら、次のステップはこれらのデータを12x8 LEDマトリクスに送信することです。通常、これにはライブラリ関数を呼び出し、LEDの状態を含む配列または変数をこれらの関数に渡すことが含まれます。

1. 2次元配列を使用する

   2D配列に格納されたパターンを表示するには、次のコードを使用できます:
   
   .. code-block:: arduino
   
      #include <Arduino_LED_Matrix.h>
   
      ArduinoLEDMatrix matrix;
   
      // Pre-defined 2D array
      byte frame[8][12] = {
           { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
           { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
           { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
           { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
           { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
      };
   
      void setup() {
        // Initialize LED matrix
        matrix.begin();
      }
   
      void loop() {
        // Display pattern on the LED matrix
        matrix.renderBitmap(frame, 8, 12);
        delay(1000);
      }
   
   このコードでは、 ``matrix.renderBitmap(frame, 8, 12);`` 関数を使用してLEDマトリクスを表示します。ここでは、8と12はそれぞれLEDマトリクスの行と列を表します。

2. 32ビット整数の配列を使用

   ``unsigned long`` 配列に格納されたパターンを表示するには、次のコードを使用します:

   .. code-block:: arduino
   
      #include "Arduino_LED_Matrix.h"
      
      ArduinoLEDMatrix matrix;
      
      void setup() {
        matrix.begin();
      }
      
      const uint32_t heart[] = {
          0x3184a444,
          0x44042081,
          0x100a0040
      };
        
      void loop(){
        matrix.loadFrame(heart);
        delay(500);
      }
   
   この場合、LEDマトリクス上にパターンを表示するために ``matrix.loadFrame(heart)`` 関数を使用する必要があります。


Arduino LED Matrix Editor
-----------------------------------------

LEDマトリクスの状態を格納するために ``unsigned long`` 配列を使用することをお勧めします。これにより、Arduinoのメモリを節約できます。この方法は直感的でないかもしれませんが、 ``unsigned long`` 配列を生成するのに役立つ |link_led_matrix_editor| を使用することができます。

|link_led_matrix_editor| と ``Arduino_LED_Matrix`` ライブラリを使用すると、アイコンやアニメーションを簡単に作成してUNO R4 WiFiボード上に表示できます。描画し、 ``.h`` ファイルをダウンロードし、スケッチ内で ``matrix.play()`` 関数を呼び出すだけで、次のプロジェクトを簡単に構築できます。



#. LED Matrix Editorを開く

   .. image:: img/04_led_matrix_editor_1.png
     :width: 80%

#. 中央のキャンバスにパターンを描画します

   .. image:: img/04_led_matrix_editor_2.png
     :width: 80%

#. フレーム間隔をミリ秒単位で設定します

   .. image:: img/04_led_matrix_editor_3.png
     :width: 80%

#. 新しいブランクフレームを作成するか、現在のフレームからコピーして新しいフレームを作成できます。

   .. image:: img/04_led_matrix_editor_4.png
     :width: 80%

#. ``.h`` ヘッダーファイルをエクスポートします

   .. image:: img/04_led_matrix_editor_5.png
     :width: 80%

   .. image:: img/04_led_matrix_editor_6.png

   OKをクリックすると、 ``animation.h`` という名前のファイルが送信されます。


アニメーションの表示
-----------------------------------------

前のステップで、フレームとその持続時間を含む ``.h`` ファイルを取得しました。次に、それらをLEDマトリクス上に表示しましょう。

#. まず、スケッチを作成します。パス ``elite-explorer-kit-main\r4_new_feature\04-led_matrix`` の下にある ``04-led_matrix.ino`` ファイルを開くか、このコードを **Arduino IDE** にコピーできます。

   .. raw:: html

      <iframe src=https://create.arduino.cc/editor/sunfounder01/f3712371-7c3d-4a4b-bd98-f74fe43269ed/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. コードを ``elite-explorer-kit-main\r4_new_feature\04-led_matrix`` パスから使用している場合、Arduino IDEには ``animation.h`` という名前のタブがあります。これを開き、ウェブサイトから取得した .h ファイルで既存のコードを置き換えます。

   .. image:: img/04_animation_h_file.png
     :width: 80%

#. 独自のスケッチを作成した場合、ウェブページから取得した ``.h`` ファイルをスケッチと同じディレクトリにコピーする必要があります。

#. Arduino IDEで好みのコードを設定し、それをArduino UNO R4 WiFiにアップロードすると、LEDマトリクスに定義したパターンが表示されるはずです。

   .. raw:: html
   
      <video loop autoplay muted style = "max-width:100%">
         <source src="../_static/videos/new_feature_projects/led_matrix.mp4"  type="video/mp4">
         お使いのブラウザはビデオタグをサポートしていません。
      </video>

   おめでとうございます！Arduino UNO R4 WiFiの12x8 LEDマトリクスを正常にプログラムしました！


**参照**

- |link_r4_led|

**その他のプロジェクト**

* :ref:`fun_snake` （楽しいプロジェクト）




