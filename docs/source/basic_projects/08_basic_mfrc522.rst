.. _basic_mfrc522:

RFID-RC522モジュール
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.35_rfid-rc522_module.html

概要
-------------

このレッスンでは、RFIDモジュールの使用方法を学びます。RFIDはRadio Frequency Identificationの略で、その原理はリーダーとラベル間の非接触データ通信によってターゲットを識別することにあります。RFIDの応用範囲は広く、動物チップ、イモビライザー、アクセスコントロール、駐車場管理、生産チェーンの自動化、資材管理などが含まれます。

必要なコンポーネント
-------------------------

このプロジェクトでは、以下のコンポーネントが必要です。

全体のキットを購入すると便利です。以下がリンクです:

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_mfrc522`
        - |link_mfrc522_rfid_buy|

配線図
---------------------

この例では、RFIDをブレッドボードに挿入します。RFIDの3.3Vを3.3Vに、GNDをGNDに、RSTをピン2に、SDAをピン6に、SCKをピン5に、MOSIをピン4に、MISOをピン3に、IRQをピン7に接続します。

.. image:: img/08-rfid_bb.png
   :align: center

回路図
-------------------------

.. image:: img/08_mfrc522_schematic.png
   :align: center
   :width: 70%

コード
-----------

.. note::

    * ``elite-explorer-kit-main\basic_project\08-mfrc522`` のパスの下にあるファイル ``08-mfrc522.ino`` を直接開くことができます。
    * ここでは ``RFID1`` ライブラリが使用されています。このライブラリは ``elite-explorer-kit-main/library/`` ディレクトリにありますが、こちら :download:`RFID1.zip </_static/RFID1.zip>` からダウンロードすることもできます。インストール方法については :ref:`manual_install_lib` を参照してください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9a4e9be9-78f5-4bf0-8b44-ca6e44092dc1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

unoボードにコードをアップロードすると、RFIDカード（秘密の鍵）をRFIDリーダーに近づけることができます。モジュールはカード情報を読み取り、シリアルモニターに表示します。


コード解析
-------------------

このモジュールの機能は ``rfid1.h`` というライブラリに含まれています。

.. code-block:: arduino

    #include <rfid1.h>

**ライブラリの関数:**

.. code-block:: arduino

    RFID1 rfid;

Arduinoに接続された特定のRFIDモジュールを表すrfid1クラスの新しいインスタンスを作成します。

.. code-block:: arduino

    void begin(IRQ_PIN,SCK_PIN,MOSI_PIN,MISO_PIN,SDA_PIN,RST_PIN)

ピンの設定です。

* ``IRQ_PIN,SCK_PIN,MOSI_PIN,MISO_PIN``: SPI通信に使用されるピン。
* ``SDA_PIN``: 同期データアダプター。
* ``RST_PIN``: リセットに使用されるピン。

.. code-block:: arduino

    void init()

RFIDを初期化します。

.. code-block:: arduino

    uchar request(uchar reqMode, uchar *TagType);

カードを検索し、カードタイプを読み取ります。この関数はRFIDの現在の読み取り状態を返し、成功した場合はMI_OKを返します。

* ``reqMode``: 検索方法。PICC_REQIDLは0x26コマンドビットを定義しています（アンテナエリア内のスリープモードでないカードを検索します）。
* ``*TagType``: カードタイプを格納するために使用され、4バイトの値が可能です（例: 0x0400）。

.. code-block:: arduino

    char * readCardType(uchar *TagType)

この関数は ``*tagType`` の4桁の16進数を特定のカードタイプにデコードし、文字列を返します。0x0400を渡した場合は「MFOne-S50」が返されます。

.. code-block:: arduino

    uchar anticoll(uchar *serNum);

衝突を防ぎ、カードのシリアル番号を読み取ります。この関数はRFIDの現在の読み取り状態を返し、成功した場合はMI_OKを返します。

* ``*serNum``: カードシリアル番号を格納するために使用され、4バイトのカードシリアル番号を返します。5番目のバイトは再チェックバイトです（例: 私の磁気カードIDは5AE4C955）。
