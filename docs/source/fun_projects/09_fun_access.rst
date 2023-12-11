.. _fun_access:

アクセスコントロールシステム
======================================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/09_fun_access.mp4"  type="video/mp4">
      お使いのブラウザではビデオタグがサポートされていません。
   </video>

このコードの主な機能は、RFIDモジュールを使用したユーザー認証の実行です。
認証に成功すると、ステップモーターを制御してドアを開け、ブザーを鳴らして認証結果を示します。
認証に失敗した場合、ドアは開きません。

シリアルモニターを開いてRFIDカードのIDを表示し、このコードでパスワードを再設定することができます。

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
    *   - :ref:`cpn_mfrc522`
        - |link_mfrc522_rfid_buy|
    *   - :ref:`cpn_stepper_motor`
        - |link_stepper_motor_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_power`
        - \-


**配線図**

.. image:: img/09_access_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**回路図**

.. image:: img/09_access_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**コード**

.. note::

    * ファイル ``09_access_control_system.ino`` を ``elite-explorer-kit-main\fun_project09_access_control_system`` のパスから直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. note::

    * ここでは ``RFID1`` ライブラリを使用しています。このライブラリは ``elite-explorer-kit-main/library/`` ディレクトリで見つけることができます。または、ここをクリックしてダウンロードしてください :download:`RFID1.zip </_static/RFID1.zip>`。インストール方法については、 :ref:`manual_install_lib` を参照してください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/3486dd4e-a76e-478f-b5a4-a86281f7f374/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**どのように動作するのか？**

以下はコードのステップバイステップの説明です：

1. **Include Library Files**: 三つのライブラリファイル ``rfid1.h``、 ``Stepper.h``、 ``Wire.h`` をインクルードしました。これらのライブラリは、RFIDモジュール、ステップモーター、およびI2C通信との通信に使用されます。

2. **Constant Definitions**: いくつかの定数を定義しています。これには、 ``ID_LEN`` （IDの長さ）、 ``stepsPerRevolution`` （ステップモーターの1回転あたりのステップ数）、 ``rolePerMinute`` （ステップモーターの速度）、さらにステップモーターの四つのピン（IN1、IN2、IN3、IN4）、ブザーピン（ ``buzPin`` ）、認証に関連する変数が含まれます。

3. **Variable Definitions**: 読み取ったユーザーIDを格納するための配列（ ``userIdRead`` ）、認証されたユーザーID（ ``userId`` ）、成功した認証を示すブール変数（ ``approved`` ）などの変数を定義しました。

4. **Object Instantiation**: RFIDモジュールとステップモーターとのやり取りに使う二つのオブジェクト ``RFID1 rfid`` と ``Stepper stepper`` のインスタンスを作成しました。

5. ``setup()``: ``setup()`` 関数では、ステップモーターの速度を初期化し、ブザーピンを出力として設定し、RFIDモジュールを初期化します。

6. ``loop()``: ``loop()`` 関数では、メインロジックが実行されます。 ``approved`` が0（まだ認証されていないことを示す）の場合、RFIDモジュールからデータを読み取るために ``rfidRead()`` 関数を呼び出し、その後 ``userIdRead`` 配列をクリアします。 ``approved`` が1（認証に成功したことを示す）の場合、ドアを開けるために ``openDoor()`` 関数を呼び出し、 ``approved`` を0にリセットします。

7. ``beep()``: この関数は、与えられた ``duration`` と ``frequency`` パラメータに基づいてブザー音を制御します。

8. ``verifyPrint()``: この関数は、 ``result`` パラメータに基づいて異なるブザー音を出し、認証が成功したかどうかを示します。

9. ``openDoor()``: この関数は、ステップモーターを制御して、特定の角度（ ``doorStep`` ）までドアを開け、一定期間待ってからドアを閉じます。

10. ``rfidRead()``: この関数はRFIDモジュールからデータを読み取り、まず ``getId()`` を呼び出してユーザーIDを取得し、次に ``idVerify()`` を呼び出してユーザーIDが認証されたIDと一致するかどうかを確認します。

11. ``getId()``: この関数はRFIDモジュールからユーザーIDを取得し、 ``userIdRead`` 配列に格納します。読み取りに失敗した場合、ビープ音が鳴ります。

12. ``idVerify()``: この関数はユーザーIDが認証されたIDと一致するかどうかを確認し、成功または失敗した認証を示す音を出します。
