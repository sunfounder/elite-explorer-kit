.. _basic_active_buzzer:

アクティブブザー
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_active_buzzer.html#ar-beep

概要
---------------

アクティブブザーは、LEDを点灯させるのと同じくらい簡単に使用できる典型的なデジタル出力デバイスです！

キットには2種類のブザーが含まれています。
アクティブブザーを使用する必要があります。裏返してみると、密閉された背面（露出したPCBではない方）が私たちが使用するものです。

.. image:: img/16_buzzer.png
    :align: center
    :width: 70%

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
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_buzzer`
        - \-

配線図
----------------------

.. note::
    ブザーを接続する際は、ピンを確認してください。長いピンがアノード、短い方がカソードです。逆に接続するとブザーから音が出ないため、間違えないように注意が必要です。

.. image:: img/16-active_buzzer_bb.png
    :align: center
    :width: 70%

回路図
-----------------------

.. image:: img/16_active_buzzer_schematic.png
    :align: center
    :width: 80%

コード
---------------

.. note::

    * ファイル ``16-active_buzzer.ino`` を ``elite-explorer-kit-main\basic_project\16-active_buzzer`` のパスで直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/bde4fd5c-8848-49cd-898f-8a824c836b80/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードが正常にアップロードされると、1秒ごとにビープ音が聞こえます。
