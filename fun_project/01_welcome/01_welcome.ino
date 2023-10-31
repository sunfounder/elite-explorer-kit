#include "analogWave.h"
#include "pitches.h"

analogWave wave(DAC);

#define PIR_PIN 8

int melody[] = {
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
  NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
};

int noteCounter = 0;
int bpm = 120;
float beatDuration = 60.0 / bpm * 1000;
int divider = 0, noteDuration = 0;  // Variables to hold note duration

void setup() {
  pinMode(PIR_PIN, INPUT);  // Set PIR motion sensor pin as input
  wave.sine(10);
}

void loop() {
  int pirValue = digitalRead(PIR_PIN);  // Read the PIR sensor

  if (pirValue == HIGH) {
    playMelody();
    delay(10000);  // wait for 10 seconds before checking again to avoid repetitive playing
  }
}

void playMelody() {
  // Calculate the duration of the current note
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
}