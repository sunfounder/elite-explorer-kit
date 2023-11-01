/*
  The code reads the ambient light level through a photoresistor and lights up
  a certain number of LEDs based on the light level. The LEDs serve as a "light level bar."

  Board: Arduino Uno R4 
  Component: Photoresistor and LED
*/

// Constants for the number of LEDs and their pins
const int NbrLEDs = 8;
const int ledPins[] = { 5, 6, 7, 8, 9, 10, 11, 12 };

// Pin for the photoresistor
const int photocellPin = A0;

// Variables to store sensor and LED level values
int sensorValue = 0;  // value read from the sensor
int ledLevel = 0;     // sensor value converted into LED 'bars'

void setup() {
  // Initialize all LED pins as outputs
  for (int led = 0; led < NbrLEDs; led++) {
    pinMode(ledPins[led], OUTPUT);
  }
}

void loop() {
  sensorValue = analogRead(photocellPin);              // Read the ambient light level from the photoresistor
  ledLevel = map(sensorValue, 300, 1023, 0, NbrLEDs);  // Map the sensor value to the number of LEDs to be lit

  // Update the state of each LED based on the mapped value
  for (int led = 0; led < NbrLEDs; led++) {
    if (led < ledLevel) {
      digitalWrite(ledPins[led], HIGH);  // Turn ON LEDs that are below the level
    } else {
      digitalWrite(ledPins[led], LOW);  // Turn OFF LEDs that are above the level
    }
  }
}
