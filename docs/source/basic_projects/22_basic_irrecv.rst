.. _basic_irrecv:

红外接收器
==========================

.. https://docs.sunfounder.com/projects/uno-mega-kit/en/latest/uno/infrared_Receiver_uno.html#receive-uno

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/infrared_Receiver_uno.html#receive-uno


概述
------------------

红外接收器是一种接收红外信号的元件，可以独立接收红外线并输出与 TTL 电平兼容的信号。其大小与普通塑料封装晶体管相似，适用于各种红外遥控和红外传输。

所需元件
-------------------------

本项目中，我们需要以下元件。

购买整套套件会更加方便，以下是链接：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名称
        - 套件所含项目
        - 链接
    *   - Elite Explorer 套件
        - 300+
        - |link_Elite_Explorer_kit|

您也可以从以下链接单独购买。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - 元件介绍
        - 购买链接

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_ir_receiver`
        - |link_receiver_buy|



接线
----------------------

.. image:: img/22-ir_receiver_bb.png
    :align: center
    :width: 80%


原理图
---------------------

.. image:: img/22_irrecv_schematic.png
    :align: center
    :width: 50%

代码
---------------

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\basic_project\22-ir_receiver`` 下的 ``22-ir_receiver.ino`` 文件。
    * 或者将以下代码复制到 Arduino IDE 中。

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/92e1cb75-cda1-4fc7-9680-28e28df8dccc/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

* 这里使用 ``IRremote`` 库，您可以从 **库管理器** 安装它。

    .. image:: img/22_irrecv_lib.png
        :align: center

.. Note::

    * 遥控器背面有一个透明塑料片用于切断电源，使用遥控器前请将其拔出。


代码分析
---------------------

此代码设计用于与红外（IR）遥控器配合使用，采用 ``IRremote`` 库。以下是分析：

#. 包含库并定义常量。首先包含 IRremote 库，并将红外接收器的引脚号定义为 2。

   .. code-block:: cpp

     #include <IRremote.h>
     const int IR_RECEIVE_PIN = 2;


#. 以 9600 波特率初始化串口通信。在指定引脚（``IR_RECEIVE_PIN``）上初始化红外接收器，并启用 LED 反馈（如果适用）。

   .. code-block:: arduino

       void setup() {
           Serial.begin(9600);                                     // 开始串口通信，波特率为 9600
           IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // 启动红外接收器
       }

#. 循环持续运行以处理传入的红外遥控信号。

   .. code-block:: arduino

      void loop() {
        // 检查是否有任何传入的红外信号
        if (IrReceiver.decode()) {
          // IrReceiver.printIRResultShort(&Serial);                 // 打印接收到的数据（单行）
          // Serial.println(IrReceiver.decodedIRData.command, HEX);  // 以十六进制格式打印命令
          Serial.println(decodeKeyValue(IrReceiver.decodedIRData.command));  // 映射并打印解码后的红外信号对应的键值

          IrReceiver.resume();  // 启用接收下一个值
        }
      }

   * 检查是否接收并成功解码了红外信号。
   * 使用自定义 ``decodeKeyValue()`` 函数解码红外命令并存储在 ``decodedValue`` 中。
   * 将解码后的红外值打印到串口监视器。
   * 恢复红外信号接收以准备接收下一个信号。

   .. raw:: html

        <br/>

#. 将接收到的红外信号映射到相应按键的辅助函数

   .. image:: img/22_irrecv_key.png
      :align: center
      :width: 80%

   .. code-block:: arduino

      // 将接收到的红外信号映射到相应按键的函数
      String decodeKeyValue(long result) {
        // 每个 case 对应一个特定的红外命令
        switch (result) {
          case 0x16:
            return "0";
          case 0xC:
            return "1";
          case 0x18:
            return "2";
          case 0x5E:
            return "3";
          case 0x8:
            return "4";
          case 0x1C:
            return "5";
          case 0x5A:
            return "6";
          case 0x42:
            return "7";
          case 0x52:
            return "8";
          case 0x4A:
            return "9";
          case 0x9:
            return "+";
          case 0x15:
            return "-";
          case 0x7:
            return "EQ";
          case 0xD:
            return "U/SD";
          case 0x19:
            return "CYCLE";
          case 0x44:
            return "PLAY/PAUSE";
          case 0x43:
            return "FORWARD";
          case 0x40:
            return "BACKWARD";
          case 0x45:
            return "POWER";
          case 0x47:
            return "MUTE";
          case 0x46:
            return "MODE";
          case 0x0:
            return "ERROR";
          default:
            return "ERROR";
        }
      }
