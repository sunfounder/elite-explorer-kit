/*
  This code snippet is used to control a servo motor to scan from 0 to 180 degrees 
  and then back from 180 to 0 degrees repeatedly.
  
  Board: Arduino Uno R4 (or R3)
  Component: Servo motor(SG90)
*/

#include <Servo.h>

const int servoPin = 9;  // Define the servo pin
int angle = 0;           // Initialize the angle variable to 0 degrees
Servo servo;             // Create a servo object

void setup() {
  servo.attach(servoPin);
}

void loop() {
  // scan from 0 to 180 degrees
  for (angle = 0; angle < 180; angle+=10) {
    servo.write(angle);
    delay(50);
  }
  // now scan back from 180 to 0 degrees
  for (angle = 180; angle > 0; angle-=10) {
    servo.write(angle);
    delay(50);
  }
}