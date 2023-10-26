/*
  The Arduino code is designed to measure soil moisture using a soil moisture sensor 
  connected to analog pin A0. The sensor's readings are sent to the Serial Monitor 
  and are updated every 100 milliseconds.

  Board: Arduino Uno R4 
  Component: Soil moisture sensor
*/

const int sensorPin = A0;  // Define the analog pin for reading the soil moisture sensor

// Initialize Serial communication for debugging and data visualization
void setup() {
  Serial.begin(9600);  // Set the baud rate to 9600 for the Serial Monitor
}

// Main loop where the program runs
void loop() {
  int sensorValue = analogRead(sensorPin);  // Read the sensor value from the defined analog pin
  Serial.println(sensorValue);              // Print the sensor value to the Serial Monitor
  delay(100);                                // Wait for 10 milliseconds before the next iteration
}
