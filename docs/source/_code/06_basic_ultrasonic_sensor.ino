/*
  This code read the distance from an ultrasonic sensor and display it on 
  an LCD screen. It uses an Arduino Uno R4 board and a 16x2 Liquid Crystal 
  Display (LCD) connected via I2C. The ultrasonic sensor is connected to 
  pins 3 and 4 for echo and trigger, respectively.

  Board: Arduino Uno R4 
  Component: Ultrasonic Module
*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // initialize the Liquid Crystal Display object with the I2C address 0x27, 16 columns and 2 rows

// Define the pin numbers for the ultrasonic sensor
const int echoPin = 3;
const int trigPin = 4;

void setup() {
  pinMode(echoPin, INPUT);   // Set echo pin as input
  pinMode(trigPin, OUTPUT);  // Set trig pin as output

  lcd.init();       // initialize the LCD
  lcd.clear();      // clear the LCD display
  lcd.backlight();  // Make sure backlight is on
}

void loop() {
  float distance = readDistance();  // Call the function to read the sensor data and get the distance

  lcd.setCursor(0, 0);           //Place the cursor at Line 1, Column 1. From here the characters are to be displayed
  lcd.print("Distance:");        ////Print Distance: on the LCD
  lcd.setCursor(0, 1);           //Set the cursor at Line 1, Column 0
  lcd.print("               ");  //Here is to leave some spaces after the characters so as to clear the previous characters that may still remain.
  lcd.setCursor(7, 1);           //Set the cursor at Line 1, Column 7.
  lcd.print(distance);           // print on the LCD the value of the distance converted from the time between ping sending and receiving.
  lcd.setCursor(14, 1);          //Set the cursor at Line 1, Column 14.
  lcd.print("cm");               //print the unit "cm"

  delay(800);  // Delay for 800 milliseconds before repeating the loop
}

// Function to read the sensor data and calculate the distance
float readDistance() {
  digitalWrite(trigPin, LOW);   // Set trig pin to low to ensure a clean pulse
  delayMicroseconds(2);         // Delay for 2 microseconds
  digitalWrite(trigPin, HIGH);  // Send a 10 microsecond pulse by setting trig pin to high
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  // Set trig pin back to low

  // Measure the pulse width of the echo pin and calculate the distance value
  float distance = pulseIn(echoPin, HIGH) / 58.00;  // Formula: (340m/s * 1us) / 2
  return distance;
}
