.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _new_adc:

Analog-to-Digital Converter (ADC) (up to 14bit)
================================================

In contemporary electronic projects, accurately reading and processing analog signals is essential. Analog-to-Digital Converters (ADCs) transform analog signals into digital ones for microcontroller handling. The Arduino Uno R4 has seen significant advancements here, owing to its more powerful processor. While the previous generation, the Arduino Uno R3, had a maximum resolution of 10 bits, the ADC resolution of the Arduino Uno R4 is now 14 bits. This improvement allows for more precise values from analog signals, enhancing the refinement and accuracy of data collection and processing.

Set ADC resolution
---------------------

The standard resolution on the Arduino board is set to 10 bits (0-1023). The UNO R4 WiFi supports up to 14-bit(0-16383) resolution, providing more precise values from analog signals. To update the resolution, you only need to use the ``analogReadResolution()`` command.

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


Notes and Warnings
---------------------

When setting the ADC resolution, consider the following points:

1. **Hardware Capability Limits**: If you set the ``analogReadResolution()`` value higher than the board’s capabilities, the Arduino will only report back at its highest resolution, padding the extra bits with zeros. For example, using the Uno R4 with ``analogReadResolution(16)`` will give an approximated 16-bit number, with the first 14 bits containing the actual ADC reading and the last 2 bits padded with zeros.

2. **Lower Resolution Settings**: If you set the ``analogReadResolution()`` value lower than the board’s capabilities, the extra least significant bits read from the ADC will be discarded. This allows you to work with a simplified range if your application does not require full resolution.

Understanding these considerations will help you effectively utilize the ADC capabilities of the Arduino Uno R4, ensuring optimal performance and accuracy for your specific application.


**Reference**
- |link_analogReadResolution|
- |link_r4_minima_adc|
- |link_r4_wifi_adc|







