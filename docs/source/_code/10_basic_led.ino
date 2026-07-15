/*
  The code is intended to blink an LED connected to digital pin 9 of an 
  Arduino board. The LED turns on for half a second, then turns off for 
  half a second, repeatedly.

  Board: Arduino Uno R4 
  Component: LED
*/

// Declare the pin number for the LED
const int ledPin = 9;

// Setup runs once when you press reset or power the board
void setup() {
  // Initialize the digital pin as an output
  pinMode(ledPin, OUTPUT);
}

// Loop runs continuously after setup completes
void loop() {
  digitalWrite(ledPin, HIGH); // Turn the LED on
  delay(500);                 // Pause for 500 milliseconds (half a second)
  digitalWrite(ledPin, LOW);  // Turn the LED off
  delay(500);                 // Pause for 500 milliseconds (half a second)
}

