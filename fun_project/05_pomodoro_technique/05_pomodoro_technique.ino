/*
  This code simulates a Pomodoro timer. Moves a stepper motor between two positions 
  based on a timer.The timer starts when the button is pressed. A buzzer and LED 
  indicate state changes.

  Board: Arduino Uno R4 
  Component: Stepper motor, buzzer, LED, and button
*/

#include <Stepper.h>

// Stepper motor and speed settings
const int stepsPerRevolution = 2048;
const int rolePerMinute = 8;
const int IN1 = 11;
const int IN2 = 10;
const int IN3 = 9;
const int IN4 = 8;
Stepper stepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

// Positions for the stepper motor
int workPosition = 0;
int restPosition = 512;

// Timer settings
unsigned long previousMillis = 0;
// const long workInterval = 25 * 60 * 1000; // 25min
// const long restInterval = 5 * 60 * 1000; // 5min
const long workInterval = 10 * 1 * 1000;  // 10s for test
const long restInterval = 5 * 1 * 1000;   // 5s for test

// State management
enum TimerState { STOPPED, WORK, REST } state;
const int buzzerPin = 2;
const int buttonPin = 3;
const int ledPin = 4;
bool timerStarted = false;

void setup() {
  stepper.setSpeed(rolePerMinute);
  state = STOPPED;
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Enable internal pull-up resistor
  pinMode(ledPin, OUTPUT);
  stepper.step(1024);
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if the button is pressed to start the timer
  if (digitalRead(buttonPin) == LOW && !timerStarted) {
    timerStarted = true;
    state = WORK;
    previousMillis = currentMillis;
  }

  // State machine for work/rest cycles
  switch (state) {
    case WORK:
      digitalWrite(ledPin, HIGH);  // Turn ON the LED
      if (currentMillis - previousMillis >= workInterval) {
        stepper.step(restPosition - workPosition);
        previousMillis = currentMillis;
        state = REST;
        tone(buzzerPin, 1000, 1000);  // Sound the buzzer
      }
      break;

    case REST:
      digitalWrite(ledPin, LOW);  // Turn OFF the LED
      if (currentMillis - previousMillis >= restInterval) {
        stepper.step(workPosition - restPosition);
        previousMillis = currentMillis;
        /* No need to re-press the button */
        // state = WORK;

        /* Need to press the button again */
        timerStarted = false;  // Reset the timer
        state = STOPPED;
        tone(buzzerPin, 1000, 1000);  // Sound the buzzer
      }
      break;

    default:
      digitalWrite(ledPin, LOW);  // Ensure the LED is OFF when stopped
      break;
  }
}
