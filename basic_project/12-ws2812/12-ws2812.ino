/*
  The code controls a chain of 8 NeoPixel LEDs using the FastLED library. It 
  lights up each LED in the chain one at a time, in a blue color, with a small 
  delay between each LED. After lighting up an LED, it turns it off ("Black") 
  before moving to the next one.
  
  Board: Arduino Uno R4
  Component: WS2812 RGB LEDs Strip
  Library: https://github.com/FastLED/FastLED  (FastLED by Daniel Garcia)
*/

#include <FastLED.h>  // Include FastLED library
#define NUM_LEDS 8    // Number of LEDs in the chain
#define DATA_PIN 6    // Data pin for LED control

CRGB leds[NUM_LEDS];  // Array to hold LED color data
  
void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Initialize LEDs
}

void loop() {
  // Loop through each LED and set it to blue
  for (int dot = 0; dot < NUM_LEDS; dot++) {
    leds[dot] = CRGB::Blue;   // Set the current LED to blue
    FastLED.show();           // Update LEDs
    leds[dot] = CRGB::Black;  // Clear the current LED
    delay(30);                // Wait for a short period before moving to the next LED
  }
}
