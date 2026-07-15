/*
  This code is intended to control a 28BYJ-48 stepper motor using a ULN2003 driver 
  and an Arduino Uno R4. The motor is rotated in both clockwise and counter-clockwise
  directions at different speeds.

  Board: Arduino Uno R4
  Component: 28BYJ-48 Stepper Motor and ULN2003 Driver
*/

#include <Stepper.h>  // Include the Stepper library

#define STEPS 2038                   // Define the number of steps per revolution for the motor
Stepper stepper(STEPS, 2, 3, 4, 5);  // Initialize stepper object and set pin connections (IN1, IN3, IN2, IN4)

void setup() {
}

void loop() {
  // Rotate clockwise at 5 RPM
  stepper.setSpeed(5);
  stepper.step(STEPS);  // Rotate one full revolution clockwise
  delay(1000);          // Wait for 1 second

  // Rotate counter-clockwise at 15 RPM
  stepper.setSpeed(15);
  stepper.step(-STEPS);  // Rotate one full revolution counter-clockwise
  delay(1000);           // Wait for 1 second
}
