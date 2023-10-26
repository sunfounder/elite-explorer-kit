/*
  The code reads temperature data from a thermistor connected to analog pin A0 on an Arduino board. 
  It calculates the temperature in both Celsius and Fahrenheit using the Steinhart-Hart equation and 
  prints the results to the Serial Monitor. The code uses a pull-up resistor and the thermistor's 
  beta value for the calculations.

  Board: Arduino Uno R4 
  Component: Thermistor
*/

const int analogPin = A0;   // Analog pin where the thermistor is connected
const int beta = 3950;      // Beta value of the thermistor
const int resistance = 10;  // Value of the pull-up resistor in kΩ

void setup() {
  Serial.begin(9600);  // Initialize Serial communication at 9600 baud rate
}

void loop() {
  // Read the analog value from the thermistor
  int analogValue = analogRead(analogPin);

  // Calculate temperature in Celsius using the Steinhart-Hart equation
  float tempC = beta / (log((1025.0 * resistance / analogValue - resistance) / resistance) + beta / 298.0) - 273.0;

  // Convert the temperature to Fahrenheit
  float tempF = 1.8 * tempC + 32.0;

  // Print temperature in Celsius to the Serial Monitor
  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.println(" degree Celsius");

  // Print temperature in Fahrenheit to the Serial Monitor
  Serial.print("Temp: ");
  Serial.print(tempF);
  Serial.println(" degree Fahrenheit");

  delay(200);  // Pause for 200 milliseconds before the next reading
}
