/*
  This code creates a basic Pong game using an Arduino Uno, an OLED display, 
  and buttons. Players use the buttons to control a vertical paddle and bounce 
  back a moving ball to prevent it from passing their paddle. Scoring happens 
  when the ball goes off the screen edges.

  Board: Arduino Uno R4 
  Component: OLED Display Module and Button
  Library: https://github.com/adafruit/Adafruit_SSD1306 (Adafruit SSD1306 by Adafruit)  
           https://github.com/adafruit/Adafruit-GFX-Library (Adafruit GFX Library by Adafruit) 
*/


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define UP_BUTTON 3
#define DOWN_BUTTON 2

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ball set
const unsigned long BALL_RATE = 16;
int ball_x = 64, ball_y = 32;
int ball_speed = 1; 
int8_t ball_dir_x = 1, ball_dir_y = 1;

//flash rate
unsigned long ball_update;
unsigned long paddle_update;

// paddle set
const unsigned long PADDLE_RATE = 33;
const uint8_t PADDLE_HEIGHT = 16;
const uint8_t CPU_X = 12;
int8_t cpu_y = 16;
const uint8_t PLAYER_X = 115;
int8_t player_y = 16;
int paddle_speed = 3;

// score
uint8_t player_score = 0;
uint8_t cpu_score = 0;


void setup() {
  Serial.begin(115200);

  randomSeed(analogRead(A0));
  ball_dir_x = random(0, 2) * 2 - 1;
  ball_dir_y = random(0, 2) * 2 - 1;

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();

  pinMode(UP_BUTTON, INPUT);
  pinMode(DOWN_BUTTON, INPUT);

  unsigned long start = millis();

  display.clearDisplay();
  drawCourt();

  while (millis() - start < 2000)
    ;

  displayScore();
  display.display();

  ball_update = millis();
  paddle_update = ball_update;
}

void loop() {
  bool update = false;
  unsigned long time = millis();

  static bool up_state = false;
  static bool down_state = false;

  /* check if the button pressed */
  up_state |= (digitalRead(UP_BUTTON) == LOW);
  down_state |= (digitalRead(DOWN_BUTTON) == LOW);

  /* refresh the ball */
  if (time > ball_update) {
    int new_x = ball_x + ball_dir_x * ball_speed;
    int8_t new_y = ball_y + ball_dir_y * ball_speed;

    // Check if it hits the horizontal walls.
    if (new_y <= 0 || new_y >= SCREEN_HEIGHT - 1) {
      ball_dir_y = -ball_dir_y;
      new_y += ball_dir_y + ball_dir_y * ball_speed;
      displayScore();
    }

    // Check if it hits the CPU paddle
    if (crossesCpuPaddle(ball_x, new_x, ball_y)) {
      ball_dir_x = -ball_dir_x;
      new_x = CPU_X + 1;// move the ball's position to the left edge of the paddle
      ball_speed++;     // speeds up
    }

    // Check if it hits the player paddle
    if (crossesPlayerPaddle(ball_x, new_x, ball_y)) {
      ball_dir_x = -ball_dir_x;
      new_x = PLAYER_X - 1; // move the ball's position to the right edge of the paddle
      ball_speed++;         // speeds up
    }

    // Check if it hits the vertical walls
    if (new_x <= 0 || new_x >= SCREEN_WIDTH - 1) {
      if (new_x <= 1) {
        player_score++;
      }
      if (new_x >= 126) {
        cpu_score++;
      }
      /* reset ball */
      displayScore();
      ball_speed = 1;  // reset speed
      new_x = 64; // reset position
      // new_y = 32;
      ball_dir_x = (ball_dir_x > 0) ? -1 : 1;     // reset direction
      ball_dir_y = (random(0, 2) == 0) ? 1 : -1;  // reset direction
    }

    display.drawPixel(ball_x, ball_y, BLACK);
    display.drawPixel(new_x, new_y, WHITE);
    ball_x = new_x;
    ball_y = new_y;

    ball_update += BALL_RATE; // next refresh time
    update = true;
  }

  /* refresh paddles */
  if (time > paddle_update) {
    paddle_update += PADDLE_RATE; // next refresh time

    // CPU paddle
    display.drawFastVLine(CPU_X, cpu_y, PADDLE_HEIGHT, BLACK); //clear paddle
    const uint8_t half_paddle = PADDLE_HEIGHT >> 1;
    if (cpu_y + half_paddle > ball_y) {
      cpu_y -= paddle_speed;
    }
    if (cpu_y + half_paddle < ball_y) {
      cpu_y += paddle_speed;
    }
    // constraint position
    if (cpu_y < 1) cpu_y = 1;
    if (cpu_y + PADDLE_HEIGHT > 63) cpu_y = 63 - PADDLE_HEIGHT;
    display.drawFastVLine(CPU_X, cpu_y, PADDLE_HEIGHT, WHITE); //show paddle

    // Player paddle
    display.drawFastVLine(PLAYER_X, player_y, PADDLE_HEIGHT, BLACK); //clear paddle
    if (up_state) {
      player_y -= paddle_speed;
    }
    if (down_state) {
      player_y += paddle_speed;
    }
    up_state = down_state = false;
    // constraint position
    if (player_y < 1) player_y = 1;
    if (player_y + PADDLE_HEIGHT > 63) player_y = 63 - PADDLE_HEIGHT;
    display.drawFastVLine(PLAYER_X, player_y, PADDLE_HEIGHT, WHITE); //show paddle
    update = true;
  }

  if (update)
    display.display();
}

bool crossesPlayerPaddle(uint8_t old_x, uint8_t new_x, uint8_t ball_y) {
  return old_x < PLAYER_X && new_x >= PLAYER_X && ball_y >= player_y && ball_y <= player_y + PADDLE_HEIGHT;
}

bool crossesCpuPaddle(uint8_t old_x, uint8_t new_x, uint8_t ball_y) {
  return old_x > CPU_X && new_x <= CPU_X && ball_y >= cpu_y && ball_y <= cpu_y + PADDLE_HEIGHT;
}

void drawCourt() {
  display.drawRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
}

void displayScore() {
  display.fillRect(SCREEN_WIDTH / 2 - 20, 10, 60, 10, BLACK);// clear
  
  display.setCursor(SCREEN_WIDTH / 2 - 20, 10);  
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.print(cpu_score);
  display.print(" - ");
  display.print(player_score);
}
