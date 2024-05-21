.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _basic_thermistor:

サーミスタ
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.27_thermistor.html#ar-thermistor

概要
-------------

このレッスンでは、サーミスタの使用方法を学びます。サーミスタは、計測機器回路の温度補正用の電子回路部品として使用できます。電流計、流量計、ガス分析装置などで使われています。また、過熱保護、非接触リレー、恒温、自動利得制御、モーター始動、時間遅延、カラーテレビの自動消磁、火災報知器、温度補償などにも使用されます。

必要なコンポーネント
-------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全てのキットを一式購入するのが便利です。こちらがリンクです：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名称	
        - このキットのアイテム数
        - リンク
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

下記のリンクから個別に購入することもできます。

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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

配線図
----------------------

この例では、アナログピンA0を使用してサーミスタの値を取得します。サーミスタの一方の端子は5Vに接続され、もう一方の端子はA0に配線されます。同時に、もう一方の端子をGNDに接続する前に10kΩの抵抗器を接続します。

.. image:: img/02-thermistor_bb.png
    :align: center
    :width: 70%

回路図
-----------------------

.. image:: img/02_thermistor_schematic.png
   :align: center
   :width: 70%

コード
-----------

.. note::

    * ``elite-explorer-kit-main\basic_project\02-thermistor`` のパスの下にある ``02-thermistor.ino`` ファイルを直接開くことができます。
    * または、このコードをArduino IDEにコピーします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/be5dbe68-b57d-41f0-9fc0-237b99acbe3f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

uno r4 ボードにコードをアップロードした後、シリアルモニターを開いて現在の温度を確認できます。

ケルビン温度は、公式 **T\ K\ =1/(ln(R\ T/R\ N)/B+1/T\ N)** を使用して計算されます。この方程式は、|link_steinhart_hart| から導出され、計算を簡素化しています。この公式に関する詳細情報は、 :ref:`cpn_thermistor` の詳細紹介ページで見ることができます。

