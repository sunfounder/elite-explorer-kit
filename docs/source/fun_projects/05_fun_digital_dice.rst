.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _fun_digital_dice:

デジタルダイス
=======================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/05_fun_dice.mp4"  type="video/mp4">
      お使いのブラウザではビデオタグがサポートされていません。
   </video>

このコードは、74HC595 シフトレジスタと7セグメントデジタルディスプレイを使用して、サイコロを振るシミュレーションを行います。サイコロを振るシミュレーションは、直接チルトスイッチを振ることで起動します。このアクションにより、デジタルディスプレイは1から6の間のランダムな数をサイクルし、サイコロの振る動作をシミュレートします。短い間隔の後、ディスプレイは停止し、サイコロの振りの結果を意味するランダムな数を表示します。

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
    *   - :ref:`cpn_tilt_switch`
        - \-
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7segment`
        - |link_7segment_buy|

**配線図**

.. image:: img/05_dice_bb.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>

**回路図**

.. image:: img/05_digital_dice_schematic.png
   :width: 100%

**コード**

.. note::

    * ファイル ``05_digital_dice.ino`` を ``elite-explorer-kit-main\fun_project\05_digital_dice`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/ff0528b0-a10d-49e8-8916-6cb1fdfdf9a2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**どのように動作しますか？**

以下はコードの詳細な説明です：

1. 変数の初期化：

   ``dataPin``, ``clockPin``, ``latchPin``：74HC595用のピン。
   ``buttonPin``：ボタンが接続されているデジタルピン。
   ``numbers[]``：共通アノードデジタルチューブで1から6までの数を表すエンコーディングを格納する配列。

2. 揮発性変数：

   rolling：ダイスが現在ローリング中であるかどうかを示す揮発性変数。
   割り込みサービスルーチンとメインプログラムの両方でアクセスされるため、揮発性として宣言されます。

3. ``setup()``：

   関連するピンのモードを設定します。
   内部プルアップ抵抗を使用してボタンの入力モードを設定します。
   ボタンに割り込みを割り当て、ボタンの状態が変わったときにrollDice関数を呼び出します。

4. ``loop()``：

   rollingがtrueであるかどうかをチェックします。trueの場合、1から6の間のランダムな数を表示し続けます。ボタンが500ミリ秒以上押されている場合、ローリングは停止します。

5. ``rollDice()``：

   これはボタンの割り込みサービスルーチンです。ボタンが押されている（低レベル）かどうかをチェックします。もしそうなら、現在の時間を記録し、ローリングを開始します。

6. ``displayNumber()``：

   この関数はデジタルチューブに数を表示します。74HC595シフトレジスタを通じてデジタルチューブに数を送信します。
