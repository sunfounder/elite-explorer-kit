.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _basic_led:

LEDモジュール
==========================

プログラミングの学習で「Hello, world!」を出力するのが最初のステップであるように、プログラムを使ってLEDを駆動させることは、物理的プログラミングを学ぶ上での伝統的な導入部です。

必要なコンポーネント
-------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全てのキットを購入するのが便利です。リンクはこちらです：

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

配線図
----------------------

.. image:: img/10-led_bb.png
    :align: center
    :width: 60%


回路図
-----------------------

.. image:: img/10_led_schematic.png
    :align: center
    :width: 80%


コード
---------------

.. note::

   * ``elite-explorer-kit-main\basic_project\10-led`` のパスにある ``10-led.ino`` ファイルを開くことができます。
   * または、このコードを **Arduino IDE** にコピーします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2d23289e-ebd1-49e9-b11f-b1bbc1f192c1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/10_basic_led.mp4"  type="video/mp4">
      ブラウザはビデオタグをサポートしていません。
   </video>

コードが正常にアップロードされると、Arduinoボードのデジタルピン9に接続されたLEDが点滅し始めます。LEDは0.5秒間点灯し、その後0.5秒間消灯し、プログラムが実行される間、このサイクルを繰り返します。

コード解析
------------------------

ここでは、LEDをデジタルピン9に接続しているので、プログラムの最初に ``int`` 変数として ``ledpin`` という名前を宣言し、9の値を割り当てる必要があります。

.. code-block:: arduino

    const int ledPin = 9;

``setup()`` 関数でピンを初期化する必要があります。ここでピンを ``OUTPUT`` モードに初期化します。

.. code-block:: arduino

    void setup() {
        pinMode(ledPin, OUTPUT);
    }

``loop()`` では、 ``digitalWrite()`` を使用してledpinに5Vのハイレベル信号を提供し、LEDピン間の電圧差によりLEDを点灯させます。

.. code-block:: arduino

    digitalWrite(ledPin, HIGH);

レベル信号をLOWに変更すると、ledPinの信号が0Vに戻り、LEDが消灯します。

.. code-block:: arduino

    digitalWrite(ledPin, LOW);

点灯と消灯の間には、人が変化を見るための間隔が必要です。そのため、コントローラーが1000ms間何もしないように ``delay(1000)`` コードを使用します。

.. code-block:: arduino

    delay(1000);   
