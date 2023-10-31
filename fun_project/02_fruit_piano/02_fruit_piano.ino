#include <Wire.h>
#include "Adafruit_MPR121.h"
#include "analogWave.h"
#include "pitches.h"

// 初始化MPR121对象和analogWave对象
Adafruit_MPR121 cap = Adafruit_MPR121();
analogWave wave(DAC); 

// 定义每个触摸通道对应的音符
int notes[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, 
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5
};

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("MPR121 Water Fruit Piano Setup");

  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found. Check wiring.");
    while (1);
  }
  Serial.println("MPR121 initialized.");
  
  wave.sine(10);  // Initialize the sine wave generator with a frequency of 10 Hz
}

void loop() {
  uint16_t touched = cap.touched();

  for (int i = 0; i < 12; i++) {
    if (touched & (1 << i)) {  // 如果该通道被触摸
      playNote(notes[i]);  // 播放相应的音符
    }
  }
  
  delay(10);  // 延迟以避免过多的读取
}

void playNote(int note) {
  wave.freq(note);  // Set frequency for the DAC
  delay(100);       // Delay for a short period to play the note
  wave.stop();      // Stop the wave after the note is played
}
