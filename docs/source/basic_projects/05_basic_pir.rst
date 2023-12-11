.. _basic_pir:

PIR動作センサーモジュール
==========================

.. https://docs.sunfounder.com/projects/kepler-kit/en/latest/cproject/ar_pir.html#ar-pir

概要
---------------

このレッスンでは、PIR動作センサーモジュールについて学びます。パッシブ赤外線（PIR）動作センサーは、動きを検出するセンサーです。セキュリティシステムや自動照明システムで一般的に使用されています。このセンサーには、赤外線を検出する2つのスロットがあります。人などの物体がセンサーの前を通過すると、赤外線の量の変化を検出し、出力信号をトリガーします。

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

配線図
----------------------

.. image:: img/05-pir_bb.png
   :align: center
   :width: 100%


回路図
-----------------------

.. image:: img/05-pir_schematic.png
   :align: center
   :width: 50%


コード
---------------

.. note::

    * ``elite-explorer-kit-main\basic_project\05-pir_motion_sensor`` のパスの下にある ``05-pir_motion_sensor.ino`` ファイルを直接開く。
    * または、このコードをArduino IDEにコピーします。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d9fc9198-1538-413d-b501-2cddc8d7cfe6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードをArduino Unoボードにアップロードした後、シリアルモニターを開いてセンサーの出力を観察できます。PIR（パッシブ赤外線）動作センサーが動きを検出すると、シリアルモニターに「Somebody here!」と表示され、動きが検出されたことを示します。動きが検出されない場合は、「Monitoring...」と表示されます。

PIRセンサーは、検出されたか検出されていないかに応じて、デジタルHIGHまたはLOWの信号を出力します。アナログセンサーが値の範囲を提供するのとは異なり、このPIRセンサーからのデジタル出力は、HIGH（通常「1」と表される）かLOW（通常「0」と表される）のいずれかになります。

PIRセンサーの特性や環境条件に基づいて、実際の感度や検出範囲が異なる場合があるため、特定のニーズに合わせてセンサーを調整することが推奨されます。
