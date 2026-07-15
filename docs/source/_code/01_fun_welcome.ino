/*
  The code is for an Arduino project that plays a melody when motion is detected by 
  a PIR (Passive Infrared) motion sensor. 

  Board: Arduino Uno R4 
  Component: PIR Motion Sensor Module, Audio Module, and Speaker
*/

#include "analogWave.h"
#include "pitches.h"

analogWave wave(DAC);

#define PIR_PIN 8

int melody[] = {
  NOTE_C4, 4, NOTE_E4, 4, NOTE_G4, 4, NOTE_C5, 4, NOTE_G4, 4, NOTE_E4, 4, NOTE_C4,4
};

int noteCounter = 0;
int bpm = 60;
float beatDuration = 60.0 / bpm * 1000;
int divider = 0, noteDuration = 0;  // Variables to hold note duration

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);  // Set PIR motion sensor pin as input
  wave.sine(10);
}

void loop() {
  int pirValue = digitalRead(PIR_PIN);  // Read the PIR sensor
  Serial.println(pirValue);
  
  if (pirValue == HIGH) {
    playMelody();
    delay(5000);  // wait for 5 seconds before checking again to avoid repetitive playing
  }
}

void playMelody() {
  // Calculate the duration of the current note
  while (1) {
    divider = melody[noteCounter + 1];
    if (divider > 0) {
      // For regular notes
      noteDuration = beatDuration / divider;
    } else if (divider < 0) {
      // For dotted notes (duration increased by 50%)
      noteDuration = beatDuration / abs(divider);
      noteDuration *= 1.5;  // Increase the duration by 50% for dotted notes
    }

    // Play the note
    wave.freq(melody[noteCounter]);
    delay(noteDuration * 0.85);  // Play the note for 85% of its duration
    wave.stop();

    // Pause between notes
    delay(noteDuration * 0.15);  // Pause for 15% of the note duration

    // Increment the note counter by 2 (because each note is followed by its duration)
    noteCounter += 2;

    // Reset the counter when reaching the end of the melody
    int totalNotes = sizeof(melody) / sizeof(melody[0]);
    noteCounter = noteCounter % totalNotes;

    // Exit the loop after the melody finishes playing
    if (noteCounter == 0) {
      break;
    }
  }
}