/*
  This code controls an active buzzer connected to pin 8 on an Arduino Uno R4.
  The buzzer will be turned on for 1 second and then turned off for 1 second, continuously.
  
  Board: Arduino Uno R4 
  Component: Active Buzzer
*/

// Declare the pin where the buzzer is connected
const int buzzerPin = 8;

// Initialize the pin as an output
void setup() {
  pinMode(buzzerPin, OUTPUT);
}

// Main loop
void loop() {
  digitalWrite(buzzerPin, HIGH);  // Turn the active buzzer on
  delay(1000);                    // Wait for 1 second
  digitalWrite(buzzerPin, LOW);   // Turn the active buzzer off
  delay(1000);                    // Wait for 1 second
}
