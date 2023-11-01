/*
  The code is an Arduino program for a touch-sensitive piano. 
  It utilizes the MPR121 capacitive touch sensor and a DAC 
  (Digital-to-Analog Converter) to produce musical notes. 
  When a particular touch channel is triggered, it plays the 
  corresponding musical note.

  Board: Arduino Uno R4 
  Component: MPR121, Audio Module, and Speaker
  Library: https://github.com/adafruit/Adafruit_MPR121 (Adafruit_MPR121 by Adafruit)
*/

#include <Wire.h>             // Include the Wire library for I2C communication
#include "Adafruit_MPR121.h"  // Include the Adafruit MPR121 library for capacitive touch sensing
#include "analogWave.h"       // Include the analogWave library for wave generation
#include "pitches.h"          // Include the pitches library that defines musical notes

// Initialize MPR121 and analogWave objects
Adafruit_MPR121 cap = Adafruit_MPR121();
analogWave wave(DAC);

// Define notes for each touch channel
int notes[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5
};

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("MPR121 Water Fruit Piano Setup");

  // Initialize MPR121 sensor
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found. Check wiring.");
    while (1);  // Halt execution if MPR121 is not found
  }
  Serial.println("MPR121 initialized.");

  wave.sine(10);  // Initialize the sine wave generator with a frequency of 10 Hz
}

void loop() {
  uint16_t touched = cap.touched();  // Read the touch state from the MPR121 sensor

  for (int i = 0; i < 12; i++) {
    if (touched & (1 << i)) {  // Check if the channel is touched
      playNote(notes[i]);      // Play the corresponding note
    }
  }

  delay(10);  // Add a small delay to reduce sensor reading frequency
}

void playNote(int note) {
  wave.freq(note);  // Set frequency for the DAC
  delay(100);       // Delay for a short period to play the note
  wave.stop();      // Stop the wave after the note is played
}
