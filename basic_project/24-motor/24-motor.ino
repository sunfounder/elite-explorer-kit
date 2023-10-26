/*
  The code controls a motor using an Arduino Uno R4 and a TA6586 chip. It 
  sets the rotation direction of the motor based on the user's serial input 
  ('A' for clockwise and 'B' for anticlockwise). After performing the rotation 
  for 3 seconds, the motor is stopped.

  Board: Arduino Uno R4
  Component: Motor and TA6586 chip
*/

// Pin definitions for motor control
const int motorBI = 10;
const int motorFI = 9;

// Initialization function
void setup() {
  // Set motor control pins as OUTPUT
  pinMode(motorBI, OUTPUT);
  pinMode(motorFI, OUTPUT);
  
  // Initialize serial communication and prompt user
  Serial.begin(9600);
  Serial.println("Please input 'A' or 'B' to select the motor rotate direction.");
}

// Main loop function
void loop() {
  // Check if there is available data on the serial port
  if (Serial.available() > 0) {
    int incomingByte = Serial.read(); // Read incoming data
    
    // Determine motor direction based on user input
    switch (incomingByte) {
      case 'A':
        clockwise(255); // Rotate motor clockwise
        Serial.println("The motor rotates clockwise.");
        break;
      case 'B':
        anticlockwise(255); // Rotate motor anticlockwise
        Serial.println("The motor rotates anticlockwise.");
        break;
    }
  }
  
  delay(3000); // Wait for 3 seconds
  stopMotor(); // Stop the motor
}

// Function to rotate the motor clockwise
void clockwise(int Speed) {
  analogWrite(motorBI, 0);
  analogWrite(motorFI, Speed);
}

// Function to rotate the motor anticlockwise
void anticlockwise(int Speed) {
  analogWrite(motorBI, Speed);
  analogWrite(motorFI, 0);
}

// Function to stop the motor
void stopMotor() {
  analogWrite(motorBI, 0);
  analogWrite(motorFI, 0);
}
