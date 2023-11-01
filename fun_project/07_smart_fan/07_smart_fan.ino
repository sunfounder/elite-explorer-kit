/*
  This code controls a DC motor fan based on temperature readings from a thermistor. 
  It includes a manual override feature using a button. In automatic mode, the fan speed 
  is controlled according to the temperature. In manual mode, the fan runs at full speed. 
  LEDs are used to indicate the current mode (auto or manual).

  Board: Arduino Uno R4 
  Component: LED, button, thermistor, and DC motor.
*/

// Pin assignments
#define MOTOR_PIN 9         // PWM compatible pin for DC motor
#define TEMP_SENSOR_PIN A0  // Analog pin for thermistor
#define BUTTON_PIN 2        // Digital pin for button
#define LED_AUTO 3          // Digital pin for AUTO mode LED
#define LED_MANUAL 4        // Digital pin for MANUAL mode LED

#define TEMP_THRESHOLD 25  // Temperature threshold for fan activation in Celsius

bool manualMode = false;

void setup() {
  // Set pin modes
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(TEMP_SENSOR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_AUTO, OUTPUT);
  pinMode(LED_MANUAL, OUTPUT);

  // Initialize LEDs
  digitalWrite(LED_AUTO, HIGH);  // Auto mode is the default
  digitalWrite(LED_MANUAL, LOW);
}

void loop() {
  static bool lastButtonState = HIGH;  // Last state of the button

  // Check for button press
  bool currentButtonState = digitalRead(BUTTON_PIN);
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    manualMode = !manualMode;  // Toggle mode
    // Update LEDs based on mode
    if (manualMode) {
      digitalWrite(LED_AUTO, LOW);
      digitalWrite(LED_MANUAL, HIGH);
    } else {
      digitalWrite(LED_AUTO, HIGH);
      digitalWrite(LED_MANUAL, LOW);
    }
    delay(200);  // Debounce delay
  }
  lastButtonState = currentButtonState;

  // Fan control logic
  if (manualMode) {
    analogWrite(MOTOR_PIN, 255);  // Full speed in manual mode
  } else {
    float voltage = analogRead(TEMP_SENSOR_PIN) * 5.0 / 1023.0;
    float temperature = voltageToTemperature(voltage);  // Convert voltage to temperature
    if (temperature > TEMP_THRESHOLD) {
      // Scale fan speed based on temperature
      analogWrite(MOTOR_PIN, map(temperature, TEMP_THRESHOLD, 40, 100, 255));
    } else {
      analogWrite(MOTOR_PIN, 0);  // Turn off the fan
    }
  }
}


// Convert voltage reading from thermistor to temperature in Celsius
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
