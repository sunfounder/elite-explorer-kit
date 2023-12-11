.. _basic_ultrasonic_sensor:

超音波
==========================

概要
--------------------

車をバックする際、衝突を避けるために車と周囲の障害物との距離を確認します。その距離を検出する装置が超音波センサーです。この実験では、超音波がどのように距離を検出するかを学びます。

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

配線図
----------------------

.. image:: img/06-ultrasonic_module_bb.png
    :align: center
    :width: 100%

.. raw:: html

    <br/>

回路図
-----------------------

.. image:: img/06_ultrasonic_schematic.png
    :align: center
    :width: 100%


コード
--------

.. note::

    * ``elite-explorer-kit-main\basic_project\06-ultrasonic`` のパスの下にある ``06-ultrasonic.ino`` ファイルを直接開く。
    * または、このコードをArduino IDEにコピーします。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/1897efb6-fa3c-4ebc-8993-6561b24848a9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/06_basic_ultrasonic_sensor.mp4"  type="video/mp4">
      お使いのブラウザはビデオタグをサポートしていません。
   </video>

コード解析
------------------------

**1. 超音波センサーとLCD1602の初期化**

    .. code-block:: arduino
    
       #include <LiquidCrystal_I2C.h>
       
       LiquidCrystal_I2C lcd(0x27, 16, 2);  // initialize the Liquid Crystal Display object with the I2C address 0x27, 16 columns and 2 rows
       
       // Define the pin numbers for the ultrasonic sensor
       const int echoPin = 3;
       const int trigPin = 4;
       
       void setup() {
         pinMode(echoPin, INPUT);               // Set echo pin as input
         pinMode(trigPin, OUTPUT);              // Set trig pin as output
       
         lcd.init();       // initialize the LCD
         lcd.clear();      // clear the LCD display
         lcd.backlight();  // Make sure backlight is on
       
       }

**2. LCD1602で距離を表示**

    .. code-block:: arduino
    
       void loop() {
         float distance = readDistance();  // Call the function to read the sensor data and get the distance
       
         lcd.setCursor(0, 0);         //Place the cursor at Line 1, Column 1. From here the characters are to be displayed
         lcd.print("Distance:");      ////Print Distance: on the LCD
         lcd.setCursor(0, 1);         //Set the cursor at Line 1, Column 0
         lcd.print("               ");  //Here is to leave some spaces after the characters so as to clear the previous characters that may still remain.
         lcd.setCursor(7, 1);         //Set the cursor at Line 1, Column 7.
         lcd.print(distance);         // print on the LCD the value of the distance converted from the time between ping sending and receiving.
         lcd.setCursor(14, 1);        //Set the cursor at Line 1, Column 14.
         lcd.print("cm");             //print the unit "cm"
       
         delay(800);                       // Delay for 800 milliseconds before repeating the loop
       }

**3. 時間を距離に変換**

    .. code-block:: arduino

        float readDistance(){// ...}

    ここでの「PING」は、超音波センサーが超音波パルス（または「PING」）を送出し、そのエコーを待つプロセスを指します。
    
    PINGは、2マイクロ秒以上のHIGHパルスによってトリガーされます。（クリーンなHIGHパルスを保証するために、事前に短いLOWパルスを与えます。）

    .. code-block:: arduino

        digitalWrite(trigPin, LOW); 
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH); 
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW); 

    エコーピンはPINGからの信号を読み取るために使用され、その持続時間はピンの送信からオブジェクトのエコーの受信までの時間（マイクロ秒）です。以下の関数を使用して持続時間を取得します。

    .. code-block:: arduino

        pulseIn(echoPin, HIGH);

    音速は340m/sまたは29マイクロ秒/センチメートルです。

    これにより、ピンによる往復の移動距離が得られるため、障害物までの距離を取得するために2で割ります。

    .. code-block:: arduino

        float distance = pulseIn(echoPin, HIGH) / 29.00 / 2;     // Formula: (340m/s * 1us) / 2
