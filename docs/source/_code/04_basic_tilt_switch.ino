/*
  The code monitors the state of a tilt switch connected to an Arduino. 
  It initializes a serial communication for debugging and sets a designated 
  digital pin as an input for the tilt switch. The state of the tilt switch 
  is continuously read and sent to the serial monitor.

  Board: Arduino Uno R4 
  Component: Tilt switch
*/

const int tiltPin = 2;  // Declare and initialize the pin for the tilt switch

// Initialize the serial communication and set up the tilt switch pin as input
void setup() {
  Serial.begin(9600);       // Initialize serial communication at 9600 baud rate
  pinMode(tiltPin, INPUT);  // Set the tilt switch pin as an input
}

// Continuously monitor the tilt switch state and output it to the serial monitor
void loop() {
  int tiltState = digitalRead(tiltPin);  // Read the state of the tilt switch
  Serial.println(tiltState);             // Send the tilt switch state to the serial monitor
  delay(10);                              // Wait for 10 millisecond before the next read
}
