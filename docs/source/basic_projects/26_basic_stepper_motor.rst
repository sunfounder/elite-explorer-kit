.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _basic_stepper_motor:

ステッピングモーター
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/stepper_motor_uno.html#stepper-uno

概要
---------------

このレッスンでは、28BYJ-48モデルのステッピングモーターをULN2003ドライバーとArduino Uno R4を使って制御する方法を学びます。ステッピングモーターは、3Dプリンター、CNCマシン、ロボティクス、さらには一般的な家庭用機器など、様々な用途で使用されています。その精密な制御により、複雑な動きが可能で、高い位置精度を必要とするプロジェクトに理想的です。

このプロジェクトでは、28BYJ-48ステッピングモーターを様々な速度で時計回りおよび反時計回りに回転させるように設定します。このようなステッピングモーターは、正確な制御を必要とする物体の回転やメカニズムの駆動に自動システムでよく使用されます。例えば、特定の時間や特定の条件下でカーテンが開閉する自動カーテンなどに使用できます。ステッピングモーターの回転と速度を制御する方法を理解することで、自分の電子プロジェクトに取り入れる準備が整います。

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
    *   - :ref:`cpn_stepper_motor`
        - |link_stepper_motor_buy|
    *   - :ref:`cpn_power`
        - \-


配線図
----------------------

.. warning::
    ステッピングモーターの高い消費電力のため、Arduinoに頼るのではなく、外部の5V電源を使用することをお勧めします。

    Arduinoから直接ステッピングモーターに電力を供給することも可能ですが、これはArduinoの電源ラインに電気ノイズを引き起こし、Arduinoの損傷につながる可能性があるため、お勧めしません。

.. image:: img/26-stepper_motor_bb.png
    :align: center


回路図
-----------------------

.. image:: img/26_stepper_motor_schematic.png
   :align: center
   :width: 80%


コード
---------------

.. note::

    * ファイル ``26-stepper_motor.ino`` を ``elite-explorer-kit-main\basic_project\26-stepper_motor.rst`` のパスで直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ce640f07-39a0-418a-9114-901df676ff32/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

コードのアップロード後、Arduino Unoボードに接続された28BYJ-48ステッピングモーターは、ULN2003ドライバーによって回転を始めます。最初に、モーターは時計回りに5RPM（毎分回転数）の速度で1回転します。時計回りの回転が完了すると、モーターは1秒間停止します。

その後、モーターは反時計回りに15RPMの速度で別の完全な回転をします。反時計回りの回転が終了した後、モーターは再び1秒間停止します。Arduinoに電力が供給されている限り、回転と停止のサイクルは無期限に続きます。



コード解析
-----------------

1. **ステッパーの初期化**

   .. code-block:: arduino
   
       #include <Stepper.h>  // Include the Stepper library

       #define STEPS 2038                   // Define the number of steps per revolution for the motor
       Stepper stepper(STEPS, 2, 3, 4, 5);  // Initialize stepper object and set pin connections (IN1, IN2, IN3, IN4)

   ヘッダーファイル ``Stepper.h`` をインクルードし、ステップを2038に設定してから、stepper()関数でステッパーを初期化します。

   ``STEPS``: モーターが1回転するために必要なステップ数。このステッピングモーターでは、この値は2038です。

   ``Stepper(steps, pin1, pin2, pin3, pin4)``: この関数は、Arduinoボードに接続された特定のステッピングモーターを表すStepperクラスの新しいインスタンスを作成します。ピンpin1, pin2, pin3, およびpin4は、ULN2003ドライバーのIN1, IN2, IN3, およびIN4ピンに対応しています。
   

2. **loop()関数**

   .. code-block:: arduino
   
      void loop() {
        // Rotate clockwise at 5 RPM
        stepper.setSpeed(5);
        stepper.step(STEPS);  // Rotate one full revolution clockwise
        delay(1000);          // Wait for 1 second
      
        // Rotate counter-clockwise at 15 RPM
        stepper.setSpeed(15);
        stepper.step(-STEPS);  // Rotate one full revolution counter-clockwise
        delay(1000);           // Wait for 1 second
      }
   
   メインプログラムでは、ステッピングモーターを連続的に回転させ、時計回りに5RPMで1回転、反時計回りに15RPMで1回転させます。


   - ``setSpeed(rpms)``: モーターの速度を毎分回転数（RPM）で設定します。この関数はモーターを回転させるわけではなく、step()を呼び出すときの速度を設定します。

     - ``rpms``: モーターが回転する速度（毎分回転数） - 正の数（long）
   
   .. raw::html

        <br/>

   
   - ``step(steps)``: この関数は、最後に呼び出されたsetSpeed()で設定された速度を使用して、モーターを指定されたステップ数だけ回転させます。この関数はブロッキング方式で動作することに注意が必要です。つまり、モーターがその動きを完了するまで、次の行の制御に進むまで待機します。
   
     たとえば、速度を1RPMに設定し、2038ステップのモーターに対してstep(2038)を呼び出した場合、この関数を実行するのに1分かかります。より正確な制御を実現するためには、速度を高く保ち、step()を呼び出すたびに少数のステップだけ動かすことをお勧めします。
   
     - ``steps``: モーターを回転させるステップ数 - 正の場合は一方向、負の場合は他方向（int）。



