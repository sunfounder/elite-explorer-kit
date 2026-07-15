/*
  This code is for controlling the brightness of an LED using a potentiometer.
  
  The code uses a potentiometer as an input device. It reads analog data from 
  the potentiometer, scales the read value from a range of 0-1023 to 0-255, 
  and then uses this scaled value to control the brightness of an LED. The raw 
  and scaled values are also printed to the serial monitor for debugging or monitoring.

  Board: Arduino Uno R4 
  Component: Potentiometer
*/

const int analogPin = 0;  // Analog input pin connected to the potentiometer
const int ledPin = 9;     // Digital output pin connected to the LED

int inputValue = 0;       // Variable to store the raw value from the potentiometer
int outputValue = 0;      // Variable to store the scaled output value

void setup() {
  Serial.begin(9600);  // Initialize serial communication with a baud rate of 9600
}

void loop() {
  inputValue = analogRead(analogPin);              // Read the analog value from the potentiometer
  Serial.print("Input: ");                         // Print "Input: " to the serial monitor
  Serial.println(inputValue);                      // Print the raw input value to the serial monitor
  
  // Map the input value from a range of 0-1023 to a range of 0-255
  outputValue = map(inputValue, 0, 1023, 0, 255);  
  
  Serial.print("Output: ");                        // Print "Output: " to the serial monitor
  Serial.println(outputValue);                     // Print the scaled output value to the serial monitor
  
  analogWrite(ledPin, outputValue);                // Control the LED brightness based on the scaled value
  delay(1000);                                     // Wait for 1 second before the next loop iteration
}
