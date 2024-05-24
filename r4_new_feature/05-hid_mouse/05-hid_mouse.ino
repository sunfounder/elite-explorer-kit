/*
  This code is designed to control mouse cursor movement using an Arduino Uno R4.
  When the button connected to pin 7 is pressed, the mouse moves 10 units to the right.
  Uncommenting the respective sections below the main loop will change the direction of movement.

  Board: Arduino Uno R4 
*/

#include <Mouse.h>  // Include the Mouse library for mouse control

const int button = 7;  // Define the pin where the button is connected

void setup() {
  pinMode(button, INPUT);  // Set the button pin as an input
  Mouse.begin();  // Initialize mouse control
  delay(1000);  // Wait for 1 second (1000 milliseconds) for hardware initialization
}

void loop() {
  // Check if the button is pressed (HIGH)
  if (digitalRead(button) == HIGH) {
    Mouse.move(10, 0);  // Move the mouse 10 units to the right
    delay(200);  // Wait for 200 milliseconds to slow down mouse movement

    // Left
    // Mouse.move(-10, 0);  
    // delay(200);  

    // Down
    // Mouse.move(0, 10);  
    // delay(200);  

    // Up
    // Mouse.move(0, -10);  
    // delay(200);  

  }
}
