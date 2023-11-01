/*
  This code is for an Arduino Uno R4 board setup with an I2C LCD1602 display 
  and an Infrared (IR) Receiver. The program facilitates a guessing game where 
  a random number is generated. The user then uses an IR remote control to guess 
  this number. Feedback is provided on the LCD1602 display, and the generated 
  random number is also displayed on the Serial Monitor.

  Board: Arduino Uno R4 
  Component: I2C LCD1602 and Infrared Receiver
*/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>

const int IR_RECEIVE_PIN = 5;  // Define the pin number for the IR Sensor
String lastDecodedValue = "";  // Variable to store the last decoded value

const long interval = 1000;

unsigned long previousMillis = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);


int count = 0;      /*Input Number Value*/
int pointValue = 0; /*The Random Lucky Point*/
int upper = 99;     /*Upper Limit Tips*/
int lower = 0;      /*Lower Limit Tips*/

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);                                     // Start serial communication at 9600 baud rate
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
  initNewValue();
}

void loop() {
  if (IrReceiver.decode()) {
    bool result = 0;
    // Serial.println(IrReceiver.decodedIRData.command);
    String num = decodeKeyValue(IrReceiver.decodedIRData.command);
    if (num != "ERROR" && num != lastDecodedValue) {
      Serial.println(num);
      lastDecodedValue = num;  // Update the last decoded value
    }

    if (num == "POWER") {
      initNewValue();
    } else if (num == "CYCLE") {
      result = detectPoint();
      lcdShowInput(result);
    } else if (num >= "0" && num <= "9") {
      count = count * 10;
      count += num.toInt();
      if (count >= 10) {
        result = detectPoint();
      }
      lcdShowInput(result);
    }
    IrReceiver.resume();  // Enable receiving of the next value
  }
}

void initNewValue() {
  randomSeed(analogRead(A0));
  pointValue = random(99);
  upper = 99;
  lower = 0;
  lcd.clear();
  lcd.print("    Welcome!");
  lcd.setCursor(0, 1);
  lcd.print("  Guess Number!");
  count = 0;
  Serial.print("point is ");
  Serial.println(pointValue);
}

bool detectPoint() {
  if (count > pointValue) {
    if (count < upper) upper = count;
  } else if (count < pointValue) {
    if (count > lower) lower = count;
  } else if (count == pointValue) {
    count = 0;
    return 1;
  }
  count = 0;
  return 0;
}

void lcdShowInput(bool result) {
  lcd.clear();
  if (result == 1) {
    lcd.setCursor(0, 1);
    lcd.print(" You've got it! ");
    delay(5000);
    initNewValue();
    return;
  }
  lcd.print("Enter number:");
  lcd.print(count);
  lcd.setCursor(0, 1);
  lcd.print(lower);
  lcd.print(" < Point < ");
  lcd.print(upper);
}


String decodeKeyValue(long result)
{
  switch(result){
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
    default :
      return "ERROR";
    }
}
