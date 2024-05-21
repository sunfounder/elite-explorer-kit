.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _new_rtc:

Real-Time Clock
========================================

The RTC (Real-Time Clock) is integrated into the UNO R4 WiFi's microcontroller (RA4M1). The RTC is an autonomous clock module capable of operating even when the main power supply is disconnected, thanks to a backup power source such as a battery. This makes the RTC incredibly versatile for various applications like scheduling timed tasks in home automation systems or time-stamping individual data points in data logging applications.

.. note::
    The UNO R4 WiFi has a VRTC pin that maintains the onboard RTC's operation even when the board loses power. To utilize this feature, apply a voltage between 1.6 and 3.6 V to the VRTC pin.



Scheduled Repetitive Tasks
++++++++++++++++++++++++++++++++++++++++++++

In certain use-cases, you may need to execute specific tasks at regular intervals. To establish periodic interrupts, you'll first need to initialize a periodic callback function. Below is an Arduino code example that uses a periodic interrupt to blink an LED every 2 seconds.


**Upload the Code**

Open the ``03-rtc.ino`` file located at ``elite-explorer-kit-main\r4_new_feature\03-rtc``, or paste the following code into your Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/48777cc6-f8a5-4646-b221-36c883ed5a62/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Code Explanation**

1. Initializing Components and Libraries

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
   
   - ``#include "RTC.h"``: Includes the RTC library.
   - ``volatile bool irqFlag = false;``: Declares a volatile boolean flag. ``volatile`` ensures that the variable can be safely accessed or modified by an interrupt. For more details on ``volatile``, refer to `Arduino volatile documentation <https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/>`_.
   - ``bool ledState = false;``: Declares a boolean to keep track of the LED state.
   - ``const int led = LED_BUILTIN;``: Declares a constant for the built-in LED pin.
   - ``pinMode(led, OUTPUT);``: Sets the LED pin as an output.
   - ``Serial.begin(9600);``: Initializes serial communication at 9600 baud rate.
   - ``RTC.begin();``: Initializes the RTC.

   .. raw:: html
    
        <br/>

2. Setting Up the Real-Time Clock

   .. code-block:: arduino
   
     RTCTime mytime(30, Month::JUNE, 2023, 13, 37, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);
     RTC.setTime(mytime);
   
   - ``RTCTime mytime(...);``: Creates an ``RTCTime`` object and initializes it with a specific date and time.
   - ``RTC.setTime(mytime);``: Sets the RTC with the initialized time.
   
   Setting and Checking Periodic Callback
   
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
   
   - ``RTC.setPeriodicCallback(...);``: Sets a periodic callback to trigger every 2 seconds.The period can be specified using the following enumerations:

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

   - ``void loop() {...}``: Checks if the callback has been triggered. If so, toggles the LED state.
   - ``void periodicCallback() {...}``: The callback function sets ``irqFlag = true`` when triggered.


**Reference**

- |link_r4_rtc|