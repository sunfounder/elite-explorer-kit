.. _basic_photoresistor:

フォトレジスタ
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.26_photoresistor.html

概要
---------------

このレッスンでは、フォトレジスタについて学びます。フォトレジスタは、カメラメーター、クロックラジオ、アラーム装置（ビーム検出器として）、小型ナイトライト、屋外時計、ソーラー街路灯など、多くの電子製品に応用されています。フォトレジスタは、街灯に取り付けられ、灯りの点灯を制御します。周囲の光がフォトレジスタに当たると、街灯が点灯または消灯します。

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

配線図
----------------------

この例では、アナログピン（A0）を使用してフォトレジスタの値を読み取ります。フォトレジスタの一方の端子は5Vに接続され、もう一方の端子はA0に配線されます。さらに、もう一方の端子をGNDに接続する前に10kΩの抵抗が必要です。

.. image:: img/01-photoresistor_bb.png
    :align: center
    :width: 80%

回路図
-----------------------

.. image:: img/01_photoresistor_schematic.png
    :align: center
    :width: 70%

コード
---------------

.. note::

    * ``elite-explorer-kit-main\basic_project\01-photoresistor`` のパスの下にある ``01-photoresistor`` ファイルを直接開くことができます。
    * または、このコードをArduino IDEにコピーします。




.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e6bf007e-b20d-44d0-9ef9-6d57c1ce4c3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードをボードにアップロードした後、シリアルモニターを開いてピンの読み取り値を確認できます。周囲の光が強くなると、読み取り値もそれに応じて増加します。ピンの読み取り範囲は「0」〜「1023」です。しかし、環境条件やフォトレジスタの特性により、実際の読み取り範囲は理論的な範囲よりも小さくなる場合があります。
