.. _new_rtc:

实时时钟
========================================

RTC（实时时钟）集成在 UNO R4 WiFi 的微控制器 (RA4M1) 中。RTC 是一个自主时钟模块，即使在主电源断开的情况下也能运行，这得益于备用电源（如电池）。这使得 RTC 在各种应用中非常通用，例如在家庭自动化系统中安排定时任务或在数据记录应用中为单个数据点添加时间戳。

.. note::
    UNO R4 WiFi 有一个 VRTC 引脚，即使板断电也能保持板载 RTC 的运行。要使用此功能，请在 VRTC 引脚上施加 1.6 到 3.6 V 的电压。



定时重复任务
++++++++++++++++++++++++++++++++++++++++++++

在某些用例中，您可能需要定期执行特定任务。要建立周期性中断，您首先需要初始化一个周期性回调函数。以下是一个 Arduino 代码示例，使用周期性中断每 2 秒闪烁一次 LED。


**上传代码**

打开位于 ``elite-explorer-kit-main\r4_new_feature\03-rtc`` 的 ``03-rtc.ino`` 文件，或将以下代码粘贴到您的 Arduino IDE 中。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/48777cc6-f8a5-4646-b221-36c883ed5a62/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**代码说明**

1. 初始化组件和库

   .. code-block:: arduino

     #include "RTC.h"
     volatile bool irqFlag = false;
     bool ledState = false;
     const int led = LED_BUILTIN;

     void setup() {
       pinMode(led, OUTPUT);
       Serial.begin(9600);
       RTC.begin();
     }

   - ``#include "RTC.h"``：包含 RTC 库。
   - ``volatile bool irqFlag = false;``：声明一个易失性布尔标志。``volatile`` 确保变量可以被中断安全地访问或修改。有关 ``volatile`` 的更多详细信息，请参阅 `Arduino volatile 文档 <https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/>`_。
   - ``bool ledState = false;``：声明一个布尔值来跟踪 LED 状态。
   - ``const int led = LED_BUILTIN;``：声明内置 LED 引脚的常量。
   - ``pinMode(led, OUTPUT);``：将 LED 引脚设置为输出。
   - ``Serial.begin(9600);``：以 9600 波特率初始化串行通信。
   - ``RTC.begin();``：初始化 RTC。

   .. raw:: html

        <br/>

2. 设置实时时钟

   .. code-block:: arduino

     RTCTime mytime(30, Month::JUNE, 2023, 13, 37, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);
     RTC.setTime(mytime);

   - ``RTCTime mytime(...);``：创建一个 ``RTCTime`` 对象并用特定的日期和时间初始化它。
   - ``RTC.setTime(mytime);``：用初始化的时间设置 RTC。

   设置和检查周期性回调

   .. code-block:: arduino

     if (!RTC.setPeriodicCallback(periodicCallback, Period::ONCE_EVERY_2_SEC)) {
       Serial.println("ERROR: periodic callback not set");
     }

     void loop() {
       if (irqFlag) {
         Serial.println("Timed CallBack");
         ledState = !ledState;
         digitalWrite(led, ledState);
         irqFlag = false;
       }
     }

     void periodicCallback() {
       irqFlag = true;
     }

   - ``RTC.setPeriodicCallback(...);``：设置一个每 2 秒触发的周期性回调。周期可以使用以下枚举指定：

      - ``ONCE_EVERY_2_SEC``
      - ``ONCE_EVERY_1_SEC``
      - ``N2_TIMES_EVERY_SEC``
      - ``N4_TIMES_EVERY_SEC``
      - ``N8_TIMES_EVERY_SEC``
      - ``N16_TIMES_EVERY_SEC``
      - ``N32_TIMES_EVERY_SEC``
      - ``N64_TIMES_EVERY_SEC``
      - ``N128_TIMES_EVERY_SEC``
      - ``N256_TIMES_EVERY_SEC``

   - ``void loop() {...}``：检查回调是否已被触发。如果是，则切换 LED 状态。
   - ``void periodicCallback() {...}``：回调函数在被触发时将 ``irqFlag`` 设置为 ``true``。


**参考**

- |link_r4_rtc|
