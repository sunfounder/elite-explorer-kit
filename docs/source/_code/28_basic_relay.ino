/*
  This code controls a relay connected to an Arduino Uno R4 board.
  It toggles the state of the relay on and off every second.

  Board: Arduino Uno R4 
  Component: Relay
*/

const int relayPin = 8;  // the base of the transistor attach to

void setup() {
  pinMode(relayPin, OUTPUT);  // Initialize the relayPin as an output
}

void loop() {
  digitalWrite(relayPin, HIGH);  // Turn the relay on
  delay(1000);                   // Wait for one second
  digitalWrite(relayPin, LOW);   // Turn the relay off
  delay(1000);                   // Wait for one second
}
