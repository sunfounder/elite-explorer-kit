#include <Stepper.h>

const int stepsPerRevolution = 2048;
const int rolePerMinute = 8;
const int IN1 = 11;
const int IN2 = 10;
const int IN3 = 9;
const int IN4 = 8;

Stepper stepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

int workPosition = 0;
int restPosition = 512;
unsigned long previousMillis = 0;
// const long workInterval = 25 * 60 * 1000; // 25min
// const long restInterval = 5 * 60 * 1000; // 5min
const long workInterval = 10 * 1 * 1000; // 10s for test
const long restInterval = 5 * 1 * 1000; // 5s for test

enum TimerState { STOPPED, WORK, REST } state;
const int buzzerPin = 2;
const int buttonPin = 3;  // 按键连接到引脚3
const int ledPin = 4;     // LED连接到引脚4
bool timerStarted = false;

void setup() {
  stepper.setSpeed(rolePerMinute);
  state = STOPPED;
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // 设置内部上拉电阻
  pinMode(ledPin, OUTPUT);
  stepper.step(1024);
}

void loop() {
  unsigned long currentMillis = millis();

  // 检查按键是否被按下，启动计时器
  if (digitalRead(buttonPin) == LOW && !timerStarted) {
    timerStarted = true;
    state = WORK;
    previousMillis = currentMillis;
  }

  switch (state) {
    case WORK:
      digitalWrite(ledPin, HIGH);  // 开启LED
      if (currentMillis - previousMillis >= workInterval) {
        stepper.step(restPosition - workPosition);
        previousMillis = currentMillis;
        state = REST;
        tone(buzzerPin, 1000, 1000);
      }
      break;

    case REST:
      digitalWrite(ledPin, LOW);  // 关闭LED
      if (currentMillis - previousMillis >= restInterval) {
        stepper.step(workPosition - restPosition);
        previousMillis = currentMillis;
        /* No need to re-press the button */
        // state = WORK;

        /* Need to press the button again */
        timerStarted = false;
        state = STOPPED;
        
        tone(buzzerPin, 1000, 1000);
      }
      break;

    default:
      digitalWrite(ledPin, LOW);  // 确保在STOPPED状态时LED是关闭的
      break;
  }
}
