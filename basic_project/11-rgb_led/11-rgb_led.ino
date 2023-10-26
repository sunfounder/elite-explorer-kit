/*
  The code controls an RGB LED connected to an Arduino. It cycles through 
  a sequence of colors by adjusting the intensity of the red, green, and blue 
  LEDs. The function color(int red, int green, int blue) is used to set the 
  color of the RGB LED.
  
  Board: Arduino Uno R4 
  Component: RGB LED
*/

// Define pin numbers for the RGB LED
const int redPin = 11;     // Red pin connected to digital pin 11
const int greenPin = 10;   // Green pin connected to digital pin 10
const int bluePin = 9;     // Blue pin connected to digital pin 9

// Initialization function
void setup() { 
  // Set RGB LED pins as output
  pinMode(redPin, OUTPUT);   
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT);  
}    

// Main loop function
void loop() {    
  // Cycle through basic colors
  color(255, 0, 0);  // Red
  delay(1000);       // Wait for 1 second
  color(0, 255, 0);  // Green
  delay(1000);       // Wait for 1 second
  color(0, 0, 255);  // Blue
  delay(1000);       // Wait for 1 second

  // Cycle through blended colors
  color(255, 0, 252);  // Magenta
  delay(1000);         // Wait for 1 second
  color(237, 109, 0);  // Orange
  delay(1000);         // Wait for 1 second
  color(255, 215, 0);  // Yellow
  delay(1000);         // Wait for 1 second
  color(34, 139, 34);  // Forest Green
  delay(1000);         // Wait for 1 second
  color(0, 112, 255);  // Light Blue
  delay(1000);         // Wait for 1 second
  color(0, 46, 90);    // Indigo
  delay(1000);         // Wait for 1 second
  color(128, 0, 128);  // Purple
  delay(1000);         // Wait for 1 second
}     

// Function to set the RGB LED color
void color(int red, int green, int blue) {    
  // Write analog values to the RGB pins
  analogWrite(redPin, red);   
  analogWrite(greenPin, green); 
  analogWrite(bluePin, blue); 
}
