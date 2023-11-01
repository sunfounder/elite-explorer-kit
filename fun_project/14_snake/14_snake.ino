/*
  This code implements a simple Snake game using an Arduino Uno R4 and a 
  Joystick Module. The Snake moves based on joystick input, and the 
  objective is to eat randomly generated food without colliding with 
  the snake's body. The game ends if the snake collides with itself.

  Board: Arduino Uno R4 
  Component: Joystick Module
*/


#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;
byte frame[8][12];
byte flatFrame[8 * 12];  // Flattened frame for matrix.loadPixels()

// Snake variables
struct Point {
  byte x;
  byte y;
};

Point snake[100];
int snakeLength = 3;
Point food;
int direction = 0;  // 0=up, 1=right, 2=down, 3=left

void setup() {
  pinMode(A0, INPUT);  // joystick X-axis
  pinMode(A1, INPUT);  // joystick Y-axis

  // Initialize LED matrix
  matrix.begin();

  // Initialize snake at middle of screen
  snake[0] = { 6, 4 };
  snake[1] = { 6, 5 };
  snake[2] = { 6, 6 };

  // Generate initial food
  generateFood();
}

void loop() {
  // Read joystick input
  int x = analogRead(A0);
  int y = analogRead(A1);

  // Determine new direction based on joystick
  if (x > 600 && direction != 3) direction = 1;
  else if (x < 400 && direction != 1) direction = 3;
  else if (y > 600 && direction != 0) direction = 2;
  else if (y < 400 && direction != 2) direction = 0;

  // Move snake
  moveSnake();

  // Check for collision with food
  if (snake[0].x == food.x && snake[0].y == food.y) {
    snake[snakeLength] = snake[snakeLength - 1];  // Initialize the new segment
    snakeLength++;
    generateFood();
  }

  // Check for collision with self
  for (int i = 1; i < snakeLength; i++) {
    if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
      // Reset game (or end game)
      snakeLength = 3;
      snake[0] = { 6, 4 };
      snake[1] = { 6, 5 };
      snake[2] = { 6, 6 };
      direction = 0;
      generateFood();
    }
  }

  // Draw to LED matrix
  drawFrame();

  // Delay to control speed
  delay(200);
}

void moveSnake() {
  for (int i = snakeLength - 1; i > 0; i--) {
    snake[i] = snake[i - 1];
  }

  // Move the head of the snake based on the direction
  switch (direction) {
    case 0:
      snake[0].y = (snake[0].y - 1 + 8) % 8;  // Wrap around at the top and bottom edges
      break;
    case 1:
      snake[0].x = (snake[0].x + 1) % 12;  // Wrap around at the right and left edges
      break;
    case 2:
      snake[0].y = (snake[0].y + 1) % 8;  // Wrap around at the bottom and top edges
      break;
    case 3:
      snake[0].x = (snake[0].x - 1 + 12) % 12;  // Wrap around at the left and right edges
      break;
  }
}

void generateFood() {
  Point possibleLocations[8 * 12];
  int idx = 0;

  // Generate all possible locations for the food
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 12; x++) {
      bool overlap = false;

      // Check for overlap with the snake
      for (int i = 0; i < snakeLength; i++) {
        if (snake[i].x == x && snake[i].y == y) {
          overlap = true;
          break;
        }
      }

      if (!overlap) {
        possibleLocations[idx++] = { x, y };
      }
    }
  }

  // Randomly choose a location for the food from the possible locations
  int choice = random(0, idx);
  food = possibleLocations[choice];
}

void drawFrame() {
  // Clear frame
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 12; x++) {
      frame[y][x] = 0;
    }
  }

  // Draw snake
  for (int i = 0; i < snakeLength; i++) {
    frame[snake[i].y][snake[i].x] = 1;
  }

  // Draw food
  frame[food.y][food.x] = 1;

  // Flatten frame array and load into LED matrix
  int idx = 0;
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 12; x++) {
      flatFrame[idx++] = frame[y][x];
    }
  }
  matrix.loadPixels(flatFrame, 8 * 12);
  matrix.renderFrame(0);
}
