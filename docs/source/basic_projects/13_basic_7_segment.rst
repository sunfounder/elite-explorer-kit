.. _basic_7segment:

7セグメントディスプレイ
==========================

.. https://docs.sunfounder.com/projects/uno-mega-kit/en/latest/uno/7_segment_display_uno.html#segmeng-uno


概要
-------------------

7セグメントディスプレイは、数字や文字を表示できる装置です。7つのLEDが並列に接続されて構成されています。ディスプレイ上のピンを電源に接続し、関連するピンを有効にすることで、対応するLEDセグメントが点灯し、異なる文字/数字を表示できます。このレッスンでは、特定の文字を表示する方法を学びます。

必要なコンポーネント
------------------------

このプロジェクトには以下のコンポーネントが必要です。

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
    *   - :ref:`cpn_7segment`
        - |link_7segment_buy|

配線図
----------------------

.. image:: img/13-7_segment_display_bb.png
    :align: center
    :width: 70%


回路図
------------------------

この実験では、7セグメントディスプレイのa-gの各ピンをそれぞれ1000オームの電流制限抵抗に接続し、その後4-11ピンに接続します。GNDはGNDに接続します。プログラミングにより、4-11ピンの一つまたは複数をHighレベルに設定して、対応するLED（複数可）を点灯させます。

.. image:: img/13-7_segment_display_schematic.png
    :align: center
    :width: 80%

コード
---------------

.. note::

    * ファイル ``13-7_segment.ino`` を ``elite-explorer-kit-main\basic_project\13-7_segment`` のパスで直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ce9857dc-6285-45cd-9918-e35b0b135836/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/13_basic_7_segment.mp4"  type="video/mp4">
      ブラウザがビデオタグをサポートしていません。
   </video>

   <br/><br/>

コード解析
----------------------

この実験のコードは少し長いかもしれませんが、構文はシンプルです。見てみましょう。

**loop()内で関数を呼び出す**

.. code-block:: arduino

   digital_1(); //diaplay 1 to the 7-segment

   delay(1000); //wait for a second

   digital_2(); //diaplay 2 to the 7-segment

   delay(1000); //wait for a second

   digital_3(); //diaplay 3 to the 7-segment

   delay(1000); //wait for a second

   digital_4(); //diaplay 4 to the 7-segment


これらの関数をloop()に呼び出すことで、7セグメントが0-Fを表示します。以下に関数の例を示します。 ``digital_2()`` を例にとります：

**digital_2()の詳細な分析**

.. code-block:: arduino

   void digital_2()  //diaplay 2 to the 7-segment
   {
     turnOffAllSegments();
     digitalWrite(a, HIGH);
     digitalWrite(b, HIGH);
     digitalWrite(g, HIGH);
     digitalWrite(e, HIGH);
     digitalWrite(d, HIGH);
   }

.. image:: img/13_7segment.jpeg
   :align: center

まず、7セグメントディスプレイで数字の **2** がどのように表示されるかを理解する必要があります。これは、a、b、d、e、gのセグメントに電力を供給することで実現されます。プログラミングでは、これらのセグメントに接続されたピンをHighレベルに設定し、cとfはLowレベルに設定します。まず、 ``turnOffAllSegments()`` 関数を使用してすべてのセグメントを消灯し、その後必要なセグメントを点灯させます。

この部分を実行すると、7セグメントは **2** を表示します。他の文字の表示も同様です。表示上、大文字の **B** と **D** は、それぞれ **8** と **0** と同じに見えるため、小文字で表示されます。
