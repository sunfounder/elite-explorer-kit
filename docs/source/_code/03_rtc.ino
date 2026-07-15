/*
  This code is for an Arduino Uno R4 board and it toggles an LED on and 
  off every 2 seconds using a Real Time Clock (RTC) for timing. It initializes 
  the RTC, sets a specific time, and establishes a periodic callback to toggle 
  the LED state. When the callback is triggered, it toggles the LED and outputs 
  a debugging message to the serial monitor.

  Board: Arduino Uno R4 
*/

// Include the RTC library
#include "RTC.h"

volatile bool irqFlag = false;  // Flag to indicate a periodic callback.
bool ledState = false;          // Current LED state: true for ON and false for OFF
const int led = LED_BUILTIN;    // Pin number for the built-in LED

void setup() {
  pinMode(led, OUTPUT);  // Configure the LED pin as output

  Serial.begin(9600);

  // Initialize the RTC
  RTC.begin();

  // Set an arbitrary time to the RTC (required for RTC.setPeriodicCallback to work)
  RTCTime mytime(30, Month::JUNE, 2023, 13, 37, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);
  RTC.setTime(mytime);

  // Set the periodic callback to trigger every 2 seconds
  if (!RTC.setPeriodicCallback(periodicCallback, Period::ONCE_EVERY_2_SEC)) {
    Serial.println("ERROR: periodic callback not set");
  }
}

void loop() {
  // Check if the periodic callback has been triggered
  if (irqFlag) {
    Serial.println("Timed CallBack");  // Output a debugging message
    ledState = !ledState;              // Toggle the LED state
    digitalWrite(led, ledState);       // Update the LED
    irqFlag = false;                   // Reset the flag
  }
}

// This is the callback function to be passed to RTC.setPeriodicCallback()
void periodicCallback() {
  // Set the flag to true to indicate the callback has been triggered
  irqFlag = true;
}