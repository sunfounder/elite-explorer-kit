.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _fun_escape:

ゲーム - 脱出
==================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/11_fun_escape_square.mp4"  type="video/mp4">
      お使いのブラウザーはビデオタグをサポートしていません。
   </video>

このゲームは「脱出」と呼ばれています。
プレイヤーの目的は、MPU6050センサーを傾けてLEDマトリックス上でピクセルを動かし、マトリックスの境界にある開口部（出口）を通過させることです。

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
    *   - :ref:`cpn_gy87`
        - \-


**配線図**

.. image:: img/11_escape_bb.png
    :width: 80%
    :align: center


**回路図**

.. image:: img/11_escape_schematic.png
   :width: 70%
   :align: center


**コード**

.. note::

    * ファイル ``11_escape_square.ino`` は、パス ``elite-explorer-kit-main\fun_project\11_escape_square`` で直接開けます。
    * または、このコードをArduino IDEにコピーしてください。

.. note::
   ライブラリをインストールするには、Arduinoライブラリマネージャーで **「Adafruit MPU6050」** を検索し、インストールしてください。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/6b239445-f921-48fb-a93e-70cc7ef8afc7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**どのように動作するのか？**

コードの詳細な説明はこちらです：

1. ライブラリのインポートとグローバル変数：

   LEDマトリックス、Wire（I2C通信用）、MPU6050（モーションセンサー）、および ``Adafruit_Sensor`` ライブラリをインポートします。
   MPU6050とLEDマトリックスオブジェクトを初期化します。
   pixelXやpixelY（ピクセルの位置）、gapStartやside（ギャップの開始位置とその側面）、level（ゲームの難易度レベル）などのグローバル変数を定義します。

2. ``setup()``：

   LEDマトリックスを初期化し、ギャップ付きのマトリックスを描きます。
   シリアル通信を初期化し、MPU6050センサーが正しく起動しているか確認し、加速度範囲を2gに設定します。

3. ``loop()``：

   MPU6050センサーの読み取りに基づいてピクセルの位置を定期的に更新します。
   ギャップの位置を定期的に移動させます。
   新しいピクセルのレイアウトを読み込み、LEDマトリックスにレンダリングします。
   ピクセルがギャップを通過したかどうかを確認します。
   通過した場合、成功を表示するために1.5秒間遅延させ、ゲームの難易度を上げ、ピクセルの位置をリセットします。

4. その他の関数：

   * ``drawSquareWithGap()``：8x8の境界を描き、その中にギャップを作成します。
   * ``createGap()``：指定された側に長さ2のギャップを作成します。
   * ``moveGap()``：現在の側面とgapStartに基づいてギャップの位置を移動させ、必要に応じて側面を変更します。
   * ``movePixelBasedOnMPU()``：MPU6050から加速度データを読み取ります。加速度データに基づいてピクセルの位置を移動させます（ピクセルが境界外や壁に当たった場合はリセット）。
   * ``resetPixel()``：ピクセルの位置をマトリックスの中心にリセットします。
   * ``checkPixelPosition()``：ピクセルがギャップ上にあるかどうかを確認します。もしそうなら、ゲームの難易度レベルを上げ、パスフラグをtrueに設定します。

