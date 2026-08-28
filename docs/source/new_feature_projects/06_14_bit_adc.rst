.. _new_adc:

模数转换器 (ADC)（高达 14 位）
================================================

在当代电子项目中，准确读取和处理模拟信号至关重要。模数转换器 (ADC) 将模拟信号转换为数字信号供微控制器处理。Arduino Uno R4 在这方面取得了显著进步，这得益于其更强大的处理器。上一代 Arduino Uno R3 的最大分辨率为 10 位，而 Arduino Uno R4 的 ADC 分辨率现在为 14 位。这一改进允许从模拟信号中获取更精确的值，提高数据收集和处理的精细度和准确性。

设置 ADC 分辨率
---------------------

Arduino 板上的标准分辨率设置为 10 位 (0-1023)。UNO R4 WiFi 支持高达 14 位 (0-16383) 的分辨率，可从模拟信号中提供更精确的值。要更新分辨率，您只需使用 ``analogReadResolution()`` 命令。

.. code-block:: arduino

   void setup() {
     // open a serial connection
     Serial.begin(9600);
   }

   void loop() {
     // read the input on A0 at default resolution (10 bits)
     // and send it out the serial connection
     analogReadResolution(10);
     Serial.print("ADC 10-bit (default) : ");
     Serial.print(analogRead(A0));

     // change the resolution to 12 bits and read A0
     analogReadResolution(12);
     Serial.print(", 12-bit : ");
     Serial.print(analogRead(A0));

     // change the resolution to 14 bits and read A0
     analogReadResolution(14);
     Serial.print(", 16-bit : ");
     Serial.print(analogRead(A0));

     // change the resolution to 8 bits and read A0
     analogReadResolution(8);
     Serial.print(", 8-bit : ");
     Serial.println(analogRead(A0));

     // a little delay to not hog Serial Monitor
     delay(100);
   }


注意事项和警告
---------------------

设置 ADC 分辨率时，请考虑以下几点：

1. **硬件能力限制** ：如果您将 ``analogReadResolution()`` 值设置得高于板的能力，Arduino 将仅以其最高分辨率报告，并用零填充额外的位。例如，使用 Uno R4 并设置 ``analogReadResolution(16)`` 将给出一个近似的 16 位数字，前 14 位包含实际的 ADC 读数，最后 2 位用零填充。

2. **较低分辨率设置** ：如果您将 ``analogReadResolution()`` 值设置得低于板的能力，则从 ADC 读取的多余最低有效位将被丢弃。如果您的应用程序不需要全分辨率，这允许您使用简化范围。

理解这些注意事项将帮助您有效利用 Arduino Uno R4 的 ADC 功能，确保您的特定应用获得最佳性能和精度。


**参考**
- |link_analogReadResolution|








