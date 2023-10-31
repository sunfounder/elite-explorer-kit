#define MOTOR_PIN       9   // PWM兼容引脚
#define TEMP_SENSOR_PIN A0
#define BUTTON_PIN      2
#define LED_AUTO        3
#define LED_MANUAL      4

#define TEMP_THRESHOLD  25   // 设定启动风扇的温度阈值为25°C

bool manualMode = false;
 
void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(TEMP_SENSOR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_AUTO, OUTPUT);
  pinMode(LED_MANUAL, OUTPUT);

  digitalWrite(LED_AUTO, HIGH);
  digitalWrite(LED_MANUAL, LOW);
}

void loop() {
  static bool lastButtonState = HIGH;

  bool currentButtonState = digitalRead(BUTTON_PIN);
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    manualMode = !manualMode;  // 切换模式
    if (manualMode) {
      digitalWrite(LED_AUTO, LOW);
      digitalWrite(LED_MANUAL, HIGH);
    } else {
      digitalWrite(LED_AUTO, HIGH);
      digitalWrite(LED_MANUAL, LOW);
    }
    delay(200);  // 防抖动
  }
  lastButtonState = currentButtonState;

  if (manualMode) {
    analogWrite(MOTOR_PIN, 255);  // 手动模式下，风扇全速运转
  } else {
    float voltage = analogRead(TEMP_SENSOR_PIN) * 5.0 / 1023.0;
    float temperature = voltageToTemperature(voltage);  // 转换电压为温度
    if (temperature > TEMP_THRESHOLD) {
      analogWrite(MOTOR_PIN, map(temperature, TEMP_THRESHOLD, 40, 100, 255));
    } else {
      analogWrite(MOTOR_PIN, 0);
    }
  }
}

float voltageToTemperature(float voltage) {

  // Define constants
  const float referenceResistor = 10000;  // the 'other' resistor
  const float beta = 3950;                // Beta value (Typical Value)
  const float nominalTemperature = 25;    // Nominal temperature for calculating the temperature coefficient
  const float nominalResistance = 10000;  // Resistance value at nominal temperature

  // Convert the reading to resistance
  float Rt = referenceResistor * (5.0 - voltage) / voltage;

  // Use the Beta parameter equation to calculate temperature in Kelvin
  float tempK = 1 / (((log(Rt / nominalResistance)) / beta) + (1 / (nominalTemperature + 273.15)));

  // Convert to Celsius
  float tempC = tempK - 273.15;

  // Convert to Fahrenheit
  // float tempF = tempC * 1.8 + 32;

  return tempC;
}
