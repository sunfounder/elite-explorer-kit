.. _cpn_power:

電源モジュール
=====================

.. note::
    :ref:`cpn_power` を保護するために、初めて使用する前に完全に充電してください。

Arduino UNOボードの正常な動作を大幅に妨げるような大電流でコンポーネントを駆動する必要がある場合、このモジュールでコンポーネントに別々に電力を供給し、安全かつ安定して動作させます。

ブレッドボードに差し込んで電力を供給できます。3.3Vおよび5Vの電圧を提供し、付属のジャンパーキャップを介して接続できます。

.. image:: img/power_supply_new.png
    :width: 95%
    :align: center

.. raw:: html

    <br/>

**特徴と仕様**

* 電源入力: USB Type-C, 5V
* 出力電圧: 5V, 3.3V（ジャンパーを介して調整可能。0V、3.3V、および5Vの設定）
* 出力電流: 5V/1.5A、3.3V/1A
* ON-OFFスイッチあり
* 二つの独立チャンネル
* 基板上のベルグオスヘッダーでGND、5V、3.3V出力
* USB（Type-C）出力あり
* USB（Type-A）入力あり
* 基板上のLED: 充電指示灯CHG、電源指示灯PWR
* バッテリー: 3.7V 14500リチウムイオン電池、500mAh
* 寸法: 52mm x 32mm (長さ x 幅)


**例**

* :ref:`basic_motor` (基本プロジェクト)
* :ref:`basic_pump` (基本プロジェクト)
* :ref:`basic_stepper_motor` (基本プロジェクト)
* :ref:`fun_smart_fan` (楽しいプロジェクト)
* :ref:`fun_plant_monitor` (楽しいプロジェクト)
* :ref:`fun_access` (楽しいプロジェクト)
* :ref:`fun_pong` (楽しいプロジェクト)

