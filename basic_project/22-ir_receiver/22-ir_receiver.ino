/*
  This Arduino receive and decode infrared (IR) signals from a remote control. It uses 
  the IRremote library to receive the IR signals and map them to corresponding keys like 
  numbers, mathematical operations, and other function keys.
  
  Board: Arduino Uno R4 
  Component: Infrared Receiver
  Library: https://github.com/Arduino-IRremote/Arduino-IRremote (IRremote by shirriff, z3t0, ArminJo)
*/

// Include the necessary libraries
#include <IRremote.h>

// Define the pin numbers for the IR receiver
const int IR_RECEIVE_PIN = 2;

void setup() {
  Serial.begin(9600);                                     // Start serial communication at 9600 baud rate
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
}

void loop() {
  // Check if there is any incoming IR signal
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);                 // Print the received data in one line
    // Serial.println(IrReceiver.decodedIRData.command, HEX);  // Print the command in hexadecimal format
    Serial.println(decodeKeyValue(IrReceiver.decodedIRData.command));  // Map and print the decoded IR signal to corresponding key value
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
    IrReceiver.resume();  // Enable receiving of the next value
  }
}

// Function to map received IR signals to corresponding keys
String decodeKeyValue(long result) {
  // Each case corresponds to a specific IR command
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