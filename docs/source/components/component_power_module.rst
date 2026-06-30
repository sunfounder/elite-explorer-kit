.. _cpn_power:

电源模块
=====================

.. note::
    为了保护:ref:`cpn_power` 的电池，首次使用前请将其充满电。

当我们需要大电流来驱动某个元件时，这会严重干扰Arduino UNO板的正常工作。因此，我们通过此模块单独为元件供电，使其安全稳定地运行。

您只需将其插入面包板即可供电。它提供3.3V和5V的电压，您可以通过附带的跳线帽进行选择。

.. image:: img/power_supply_new.png
    :width: 95%
    :align: center

.. raw:: html

    <br/>

**特性与规格**

* 充电输入：USB Type-C, 5V
* 输出电压：5V, 3.3V（通过跳线可配置为0V、3.3V和5V）
* 输出电流：5V/1.5A, 3.3V/1A
* 带ON-OFF开关
* 双独立通道
* USB（Type-A）输出可用
* 电池：3.7V 电池, 500mAh
* 尺寸：52mm x 32mm x 24mm（长 x 宽 x 高）


**示例**

* :ref:`basic_motor` （基础项目）
* :ref:`basic_pump` （基础项目）
* :ref:`basic_stepper_motor` （基础项目）
* :ref:`fun_smart_fan` （趣味项目）
* :ref:`fun_plant_monitor` （趣味项目）
* :ref:`fun_access` （趣味项目）
* :ref:`fun_pong` （趣味项目）

