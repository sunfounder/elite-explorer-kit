/*
  The code reads the analog value from a photoresistor connected to pin A0 and sends the 
  value to the serial monitor. The baud rate for serial communication is set to 9600. 
  The code then waits for 10 millisecond before repeating the process.

  Board: Arduino Uno R4 
  Component: Photoresistor
*/


// Define the pin where the photoresistor is connected
const int photoresistorPin = A0;

// Initialize the serial communication at 9600 baud rate
void setup() {
  Serial.begin(9600);
}

// Main loop where the program runs
void loop() {
  // Read the analog value from the photoresistor
  int sensorValue = analogRead(photoresistorPin);
  
  // Send the sensor value to the serial monitor
  Serial.println(sensorValue);
  
  // Wait for 10 millisecond before the next loop iteration
  delay(10); 
}
