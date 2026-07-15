/*
  This code controls a water pump using a TA6586 chip with an Arduino Uno R4.
  It turns on the pump for 5 seconds and then turns it off.

  Board: Arduino Uno R4
  Component: Water pump and TA6586 chip
*/

// Define the control pins for the TA6586 chip
const int motorBI = 9;  // Backward Input pin
const int motorFI = 10; // Forward Input pin

void setup() {
  // Configure the motor control pins as output
  pinMode(motorBI, OUTPUT);
  pinMode(motorFI, OUTPUT);

  // Turn on the water pump by setting the control pins
  digitalWrite(motorBI, HIGH);
  digitalWrite(motorFI, LOW);

  // Keep the pump on for 5 seconds
  delay(5000);

  // Turn off the water pump
  digitalWrite(motorFI, LOW);
  digitalWrite(motorBI, LOW);  // This line was missing in the original code to fully turn off the pump
}

void loop() {
  // Empty loop, no operation is done here
}
