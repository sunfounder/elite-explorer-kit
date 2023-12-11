.. _basic_motor:

モーター
==========================

概要
--------

このレッスンでは、モーターの使用方法を学びます。モーターの動作原理は、通電されたコイルが磁場内で強制的に回転し、その結果モーターのローターが回転し、ピニオンギアがエンジンのフライホイールを回転させることです。

必要なコンポーネント
---------------------

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
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_power`
        - \-

配線図
----------------------

この例では、パワーサプライモジュールを使用してブレッドボードの陽極と陰極に電力を供給します。

.. image:: img/24-motor_bb.png
    :align: center
    :width: 80%

.. raw:: html
  
  <br/> 

回路図
-----------------

.. image:: img/24_motor_schematic.png
    :align: center
    :width: 100%

.. raw:: html
  
  <br/> 

コード
---------

.. note::

    * ファイル ``24-motor.ino`` を ``elite-explorer-kit-main\basic_project\24-motor`` のパスで直接開くことができます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7376df09-204d-4698-b2a6-106e2d2f00e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

UNOボードにコードをアップロードした後、シリアルモニターで「A」または「B」と入力することで、モーターの回転方向を選択できます。


コード解析
--------------------------

モーターは、モーターの両側の銅板間に電圧差を与えることで駆動できます。
したがって、銅板の一方の側の電圧を0V、もう一方の側を5Vに設定するだけで済みます。書かれたアナログ信号値を変更することで、方向と速度を調整できます。

.. code-block:: arduino

   // Function to rotate the motor clockwise
   void clockwise(int Speed) {
     analogWrite(motorBI, 0);
     analogWrite(motorFI, Speed);
   }
   
   // Function to rotate the motor anticlockwise
   void anticlockwise(int Speed) {
     analogWrite(motorBI, Speed);
     analogWrite(motorFI, 0);
   }

この例では、Serial.Read()を使用してモーターの方向を制御しています。

シリアルモニターで「A」と入力すると、clockwise(255)関数が呼び出され、モーターが255の速度で回転します。
「B」と入力すると、モーターは逆方向に回転します。

.. code-block:: arduino

   void loop() {
     // Check if there is available data on the serial port
     if (Serial.available() > 0) {
       int incomingByte = Serial.read(); // Read incoming data
       
       // Determine motor direction based on user input
       switch (incomingByte) {
         case 'A':
           clockwise(255); // Rotate motor clockwise
           Serial.println("The motor rotates clockwise.");
           break;
         case 'B':
           anticlockwise(255); // Rotate motor anticlockwise
           Serial.println("The motor rotates anticlockwise.");
           break;
       }
     }
     
     delay(3000); // Wait for 3 seconds
     stopMotor(); // Stop the motor
   }

