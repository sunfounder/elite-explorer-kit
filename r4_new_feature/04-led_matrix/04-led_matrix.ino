/*
  This code displays a predefined animation on an LED matrix using 
  the Arduino Uno R4 board. It initializes the ArduinoLEDMatrix library, 
  loads an animation sequence from an external file called "animation.h", 
  and plays it on the LED matrix.

  Board: Arduino Uno R4 WiFI
*/

// include the LED Matrix library from the Uno R4 core:
#include "Arduino_LED_Matrix.h"

//include the "animation.h" header file that stores the frames for the animation 
#include "animation.h"

// make an instance of the library:
ArduinoLEDMatrix matrix;

void setup() {
  //load frames from the animation.h file
  matrix.loadSequence(animation);

  // start the matrix
  matrix.begin();

  //play the animation on the matrix
  matrix.play(true);
}

void loop() {

}
