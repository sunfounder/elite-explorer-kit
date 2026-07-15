/*
  This code is for an Arduino Uno R4 board setup with an I2C LCD1602 display 
  and an Infrared (IR) Receiver. The program facilitates a guessing game where 
  a random number is generated. The user then uses an IR remote control to guess 
  this number. Feedback is provided on the LCD1602 display, and the generated 
  random number is also displayed on the Serial Monitor.

  Board: Arduino Uno R4 
  Component: I2C LCD1602 and Infrared Receiver
  Library: https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/ (LiquidCrystal I2C by Frank de Brabander)
           https://github.com/Arduino-IRremote/Arduino-IRremote (IRremote by shirriff, z3t0, ArminJo)
*/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>

const int IR_RECEIVE_PIN = 5;  // Define the pin number for the IR Sensor
String lastDecodedValue = "";  // Variable to store the last decoded value

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables for game state
int currentGuess = 0;       // Current input number
int pointValue = 0;  // Target number
int upper = 99;      // Current upper limit for guessing
int lower = 0;       // Current lower limit for guessing

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);                                     // Start serial communication at 9600 baud rate
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
  initNewValue();                                         // Initialize a new game round
}

void loop() {
  if (IrReceiver.decode()) {
    bool numberMatched = 0;
    // Serial.println(IrReceiver.decodedIRData.command);
    String num = decodeKeyValue(IrReceiver.decodedIRData.command);
    if (num != "ERROR" && num != lastDecodedValue) {
      Serial.println(num);
      lastDecodedValue = num;  // Update the last decoded value
    }

    // Handle different IR commands
    if (num == "POWER") {
      initNewValue();  // Start new game if POWER button pressed
    } else if (num == "CYCLE") {
      numberMatched = detectPoint();
      lcdShowInput(numberMatched);
    } else if (num >= "0" && num <= "9") {
      currentGuess = currentGuess * 10;
      currentGuess += num.toInt();
      if (currentGuess >= 10) {
        numberMatched = detectPoint();
      }
      lcdShowInput(numberMatched);
    }
    IrReceiver.resume();  // Enable receiving of the next value
  }
}

void initNewValue() {

  // Generate a new target number
  randomSeed(analogRead(A0));  // Seed random number generator
  pointValue = random(99);     // Generate target number

  upper = 99;
  lower = 0;

  // Display welcome message
  lcd.clear();
  lcd.print("    Welcome!");
  lcd.setCursor(0, 1);
  lcd.print("  Guess Number!");

  currentGuess = 0;

  // Output target for debugging
  Serial.print("point is ");
  Serial.println(pointValue);
}

bool detectPoint() {
  // Check if guess is correct, too high, or too low
  if (currentGuess > pointValue) {
    if (currentGuess < upper) upper = currentGuess;
  } else if (currentGuess < pointValue) {
    if (currentGuess > lower) lower = currentGuess;
  } else if (currentGuess == pointValue) {
    currentGuess = 0;
    return true;
  }
  currentGuess = 0;
  return false;
}

void lcdShowInput(bool numberMatched) {
  lcd.clear();
  if (numberMatched == 1) {
    lcd.setCursor(0, 0);
    lcd.print("The number is ");
    lcd.print(pointValue);
    lcd.setCursor(0, 1);
    lcd.print(" You've got it! ");
    delay(5000);
    initNewValue();
    return;
  }
  lcd.print("Enter number:");
  lcd.print(currentGuess);
  lcd.setCursor(0, 1);
  lcd.print(lower);
  lcd.print(" < Point < ");
  lcd.print(upper);
}


String decodeKeyValue(long irCode) {
  // Map IR codes to corresponding commands
  switch (irCode) {
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
