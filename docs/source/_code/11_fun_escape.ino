/*
  The code utilizes an Arduino Uno and a GY-87 IMU module to create the "Escape" game. 
  The goal is for the player to tilt the MPU6050 sensor, which controls the movement 
  of a pixel on the LED matrix. The objective is to guide the pixel through an opening 
  in the border of the matrix (the exit). Each successful passage through the opening 
  raises the game level.

  Board: Arduino Uno R4 
  Component: GY-87 IMU module
  Library: https://github.com/adafruit/Adafruit_MPU6050  (Adafruit MPU6050 by Adafruit)
*/

// Include necessary libraries
#include "Arduino_LED_Matrix.h"
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Create instances of sensor and matrix
Adafruit_MPU6050 mpu;
ArduinoLEDMatrix matrix;
byte frame[8][12];

int gapStart = 0;
int side = 0;  // 0: top, 1: right, 2: bottom, 3: left

int pixelX = 4;  // Initial position of the pixel in the center
int pixelY = 3;
int level =0;
bool pass = false;

unsigned long gapLastUpdate = 0;
unsigned long pixelLastUpdate = 0;

void setup() {
  //init matrix
  matrix.begin();
  drawSquareWithGap();
  matrix.loadPixels((uint8_t*)frame, 8 * 12);
  matrix.renderFrame(0);

  //init mpu6050
  Serial.begin(9600);
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
}

void loop() {
  // movePixelBasedOnMPU();
  // moveGap();

  unsigned long currentMillis = millis();
  
  if (currentMillis - pixelLastUpdate >= 200) {
    movePixelBasedOnMPU();
    checkPixelPosition();
    pixelLastUpdate = currentMillis;
  }
  
  if (currentMillis - gapLastUpdate >= 1020-level*100) {
    moveGap();
    gapLastUpdate = currentMillis;
  }
  
  matrix.loadPixels((uint8_t*)frame, 8 * 12);
  matrix.renderFrame(0);
  if (pass){
    delay(1500); //delay for show
    pass=false;
    resetPixel();
  }
}




void drawSquareWithGap() {
  memset(frame, 0, 8 * 12);  // Clear the frame

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i == 0 || i == 7 || j == 0 || j == 7) {
        frame[i][j] = 1;  // Set border pixel
      }
    }
  }

  createGap();

  // Redraw the pixel after drawing the square and gap
  frame[pixelY][pixelX] = 1;
}

void createGap() {
  switch (side) {
    case 0:  // top
      frame[0][gapStart] = 0;
      frame[0][gapStart + 1] = 0;
      // frame[0][gapStart + 2] = 0;
      break;
    case 1:  // right
      frame[gapStart][7] = 0;
      frame[gapStart + 1][7] = 0;
      // frame[gapStart + 2][7] = 0;
      break;
    case 2:  // bottom
      frame[7][7 - gapStart] = 0;
      frame[7][6 - gapStart] = 0;
      // frame[7][5 - gapStart] = 0;
      break;
    case 3:  // left
      frame[7 - gapStart][0] = 0;
      frame[6 - gapStart][0] = 0;
      // frame[5 - gapStart][0] = 0;
      break;
  }
}

void moveGap() {
  gapStart++;

  if (side == 0 && gapStart > 5) {
    gapStart = 0;
    side = 1;
  } else if (side == 1 && gapStart > 5) {
    gapStart = 0;
    side = 2;
  } else if (side == 2 && gapStart > 5) {
    gapStart = 0;
    side = 3;
  } else if (side == 3 && gapStart > 5) {
    gapStart = 0;
    side = 0;
  }

  drawSquareWithGap();  // Redraw the square with the moved gap
}


void movePixelBasedOnMPU() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  frame[pixelY][pixelX] = 0;  // Clear current pixel

  if (a.acceleration.x > 1.0) {
    // pixelY++;
    pixelY--;
  } else if (a.acceleration.x < -1.0) {
    // pixelY--;
    pixelY++;
  }

  if (a.acceleration.y > 1.0) {
    pixelX--;
  } else if (a.acceleration.y < -1.0) {
    pixelX++;
  }

  if (pixelX > 7 || pixelX < 0 || pixelY > 7 || pixelY < 0 || frame[pixelY][pixelX] == 1) {
    resetPixel();
  } else {
    frame[pixelY][pixelX] = 1;
  }
}

void resetPixel() {
  pixelX = 4;
  pixelY = 3;
  frame[pixelY][pixelX] = 1;
}

void checkPixelPosition() {
  bool isOnGap = false;

  // Check if the pixel is on the gap
  switch (side) {
    case 0: // top
      if (pixelY == 0 && pixelX >= gapStart && pixelX <= gapStart + 2) isOnGap = true;
      break;
    case 1: // right
      if (pixelX == 7 && pixelY >= gapStart && pixelY <= gapStart + 2) isOnGap = true;
      break;
    case 2: // bottom
      if (pixelY == 7 && pixelX >= 5 - gapStart && pixelX <= 7 - gapStart) isOnGap = true;
      break;
    case 3: // left
      if (pixelX == 0 && pixelY >= 5 - gapStart && pixelY <= 7 - gapStart) isOnGap = true;
      break;
  }

  if (isOnGap) {
    if (level<=10){ level++;}
    else {level=0;}
    pass = true;
  } 

  // Optionally, you can print out the level for debugging
  // Serial.println("Level: " + String(level));
}
