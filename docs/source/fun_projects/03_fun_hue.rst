.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _fun_hue:

HueDial
========================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/03_fun_huedial.mp4"  type="video/mp4">
      お使いのブラウザではビデオタグがサポートされていません。
   </video>

この例では、回転ノブの位置に基づいてRGB LEDの色を制御します。
ノブの異なる位置は異なるHUE値に対応し、これらはRGB色値に変換され、RGB LEDの色が変わります。

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_rgb_led`
        - |link_rgb_led_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**配線図**

.. image:: img/03_hue_dial_bb.png
    :width: 70%
    :align: center

.. raw:: html

   <br/>

**回路図**

.. image:: img/03_hue_schematic.png
   :width: 80%
   :align: center


**コード**

.. note::

    * ファイル ``03_huedial.ino`` を ``elite-explorer-kit-main\fun_project\03_huedial`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/0ad800d4-77bb-454f-8976-a078da71ec35/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**どのように動作しますか？**

以下はコードの詳細な説明です：

1. グローバル変数の定義：

   ``redPin``, ``greenPin``, ``bluePin``：それぞれ赤、緑、青のLEDに接続されたPWMピンを定義します。
   ``KNOB_PIN``：回転ノブに接続されたアナログ入力ピンを定義します。

2. ``setup()``：

   RGB LEDのピンを出力として設定します。
   アナログピンはデフォルトで入力として設定されているので、ノブのピンの入力モードを設定する必要はありません。

3. ``loop()``：

   回転ノブの値を読み取ります。この値は0から1023の範囲です。
   ノブの値を0-1の範囲に正規化します。
   正規化された値を0-360の範囲のHUE値に変換します。
   HUE値をRGB値に変換します。
   これらのRGB値を使用してLEDの色を更新します。

4. ``setColor()``：

   RGB LEDの色を設定するために、各LEDピンに対して ``analogWrite()`` 関数を使用して適切なPWM値を設定します。

5. ``HUEtoRGB()``：

   この関数はHUE値をRGB値に変換します。これはHSLからRGBへの変換方法を使用しますが、彩度と明るさを100%に保ちながらHUEコンポーネントにのみ焦点を当てます。
   アルゴリズムは6段階に分けられ、それぞれ60度をカバーしています。
   各HUE段階のRGB値を計算し、それらの値を ``analogWrite()`` 関数に対して期待される0-255の範囲にスケーリングします。

