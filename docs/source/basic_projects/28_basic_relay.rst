.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _basic_relay:

リレー
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/relay_uno.html#relay-uno


概要
---------------

リレーは、入力信号に応じて2つ以上のポイントまたはデバイス間の接続を提供するために使用されるデバイスです。言い換えると、リレーはコントローラとデバイス間の絶縁を提供します。デバイスはAC（交流）およびDC（直流）の両方で動作することがありますが、DCで動作するマイクロコントローラからの信号を受け取ります。そのため、ギャップを埋めるためにリレーが必要です。小さな電気信号で大量の電流または電圧を制御する必要がある場合には、リレーが非常に役立ちます。

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_realy`
        - |link_realy_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_diode`
        - |link_diode_buy|

配線図
----------------------

.. image:: img/28-relay_bb.png
    :align: center
    :width: 90%

回路図
-----------------------

SunFounder Unoボードのピン8に1K抵抗（トランジスタが通電時の電流制限用）を接続し、NPNトランジスタのコレクターにリレーのコイルを接続し、エミッターをGNDに接続します。リレーの通常開接点をLEDに、それからGNDに接続します。したがって、ピン8にHighレベルの信号が与えられると、トランジスタが通電し、リレーのコイルが導通します。そして、その通常開接点が閉じて、LEDが点灯します。ピン8にLowレベルが与えられると、LEDは消灯します。

.. image:: img/28_relay_schematic.png

**フリーホイールダイオードの機能**：電圧入力がHigh（5V）からLow（0V）に変わると、トランジスタは飽和状態（3つの動作条件：増幅、飽和、カットオフ）からカットオフに変わり、コイル内の電流は突然流れる場所がなくなります。この瞬間、フリーホイールダイオードがなければ、コイルの端には逆起電力（EMF）が発生し、下部が正で上部が負になり、100Vを超える電圧が発生します。この電圧とトランジスタの電源からの電圧が加わり、トランジスタを焼損させるのに十分です。したがって、フリーホイールダイオードは、図中の矢印の方向に逆起電力を放電するために非常に重要であり、トランジスタからGNDへの電圧は+5V（+0.7V）を超えません。

この実験では、リレーが閉じるとLEDが点灯し、リレーが開くとLEDが消灯します。

コード
--------

.. note::

    * ファイル ``28-relay.ino`` を ``elite-explorer-kit-main\basic_project\28-relay`` で直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/093cb26d-298d-4b36-b3be-466d813c19a9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
  

Highレベルの信号を送ると、リレーが閉じてLEDが点灯します。Lowレベルを送ると、リレーが開いてLEDが消灯します。また、通常閉接点を切り、通常開接点を閉じることによる「カチカチ」という音も聞こえます。

コード解析
-----------------

.. code-block:: arduino

   void loop() {
     digitalWrite(relayPin, HIGH);  // Turn the relay on
     delay(1000);                   // Wait for one second
     digitalWrite(relayPin, LOW);   // Turn the relay off
     delay(1000);                   // Wait for one second
   }

この実験のコードはシンプルです。最初にrelayPinをHIGHレベルに設定し、リレーに接続されたLEDが点灯します。次にrelayPinをLOWレベルに設定すると、LEDが消灯します。
