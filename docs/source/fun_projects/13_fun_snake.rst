.. _fun_snake:

ゲーム - スネーク
=========================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/13_fun_snake.mp4"  type="video/mp4">
      お使いのブラウザーはビデオタグをサポートしていません。
   </video>

この例では、R4 Wifiボードを使用して8x12のLEDマトリックス上でクラシックなスネークゲームを実装しています。
プレイヤーは二軸ジョイスティックを使ってスネークの方向を制御します。

**必要なコンポーネント**

このプロジェクトでは、以下のコンポーネントが必要です。

一式を購入するのが便利です。こちらがリンクです：

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

**配線図**

.. image:: img/13_snake_bb.png
    :width: 80%
    :align: center


**回路図**

.. image:: img/13_snake_schematic.png
   :width: 80%
   :align: center


**コード**

.. note::

    * ファイル ``13_snake.inoo`` は、パス ``elite-explorer-kit-main\fun_project\13_snakeo`` で直接開けます。
    * または、このコードをArduino IDEにコピーしてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/df370ec5-d1b5-4ae7-b3b9-e97e0eb9a872/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**どのように動作するのか？**

コードの詳細な説明はこちらです：

1. 変数の定義と初期化

   LEDマトリックス操作のための ``Arduino_LED_Matrix`` ライブラリをインポートします。
   matrixはLEDマトリックスのインスタンスです。
   ``frame`` と ``flatFrame`` は、画面上のピクセル情報を格納・処理するための配列です。
   スネークは、各ポイントがx座標とy座標を持つ ``Point`` 構造体の配列として表されます。
   foodは食べ物の位置を表します。
   ``direction`` はスネークの現在の移動方向です。

2. ``setup()`` 

   ジョイスティックのX軸とY軸を入力として初期化します。
   LEDマトリックスを起動します。
   スネークの開始位置を画面の中央で初期化します。
   食べ物の初期位置をランダムに生成します。

3. ``loop()`` 

   ジョイスティックからの読み取りに基づいてスネークの方向を決定します。
   スネークを移動させます。
   スネークの頭が食べ物に衝突するかどうかを確認します。
   衝突した場合、スネークは成長し、新しい位置に新しい食べ物が生成されます。
   スネークが自分自身と衝突するかどうかを確認します。衝突した場合、ゲームをリセットします。
   LEDマトリックス上に現在のゲーム状態（スネークと食べ物の位置）を描きます。
   ゲームの速度を制御するために遅延を加えます。

4. ``moveSnake()`` 

   尾から頭にかけて、スネークの各部分を前の部分の位置に移動させます。
   その方向に基づいてスネークの頭を移動させます。

5. ``generateFood()`` 

   可能なすべての食べ物の位置を生成します。
   各位置がスネークのいずれかの部分と重なっていないかを確認します。重なっていない場合、その位置は可能な食べ物の位置とみなされます。
   可能な食べ物の位置をランダムに選択します。

6. ``drawFrame()`` 

   現在のフレームをクリアします。
   スネークと食べ物をフレーム上に描きます。
   2次元のフレーム配列を1次元の配列（flatFrame）に平坦化し、LEDマトリックスにロードします。

