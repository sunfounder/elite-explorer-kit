.. _basic_moisture:

土壌湿度
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_moisture.html

概要
---------------

農業業界では、作物は土壌から無機元素を直接取得することはできません。代わりに、土壌内の水が溶媒として働き、これらの元素を溶かします。

作物は根系を通じて土壌から水分を吸収し、栄養を得て成長を促進します。

作物の成長と発達の過程では、土壌温度に対する要求が異なります。したがって、土壌湿度センサーの使用が必要です。

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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

配線図
----------------------

.. image:: img/03-soil_moisture_bb.png
    :align: center
    :width: 80%

回路図
-----------------------

.. image:: img/03_moisture_schematic.webp
    :align: center
    :width: 70%

コード
---------------

.. note::

    * ``elite-explorer-kit-main\basic_project\03-moisture`` のパスの下にある ``03-moisture.ino`` ファイルを開く。
    * または、このコードを **Arduino IDE** にコピーします。
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c585dd77-2e8a-4839-a908-d22e1d6e93aa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
コードが正常にアップロードされると、シリアルモニターに土壌の湿度値が表示されます。

センサーを土壌に挿入し、水をやると、土壌湿度センサーの値が小さくなります。
