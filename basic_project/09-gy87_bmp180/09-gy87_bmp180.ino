/*
  This Arduino code interfaces with the GY-87 IMU (Inertial Measurement Unit) module, 
  specifically using the BMP180 sensor for measuring temperature, pressure, and 
  calculating altitude. It initializes the BMP180 sensor and continuously outputs its 
  readings to the Serial Monitor.
  
  Board: Arduino Uno R4
  Component: GY-87 IMU Module
  Library: https://github.com/adafruit/Adafruit-BMP085-Library  (Adafruit BMP085 Library by Adafruit)
*/

// Include required libraries
#include <Adafruit_BMP085.h>

// Initialize sensor objects
Adafruit_BMP085 bmp;

void setup() {
  // Initialize the serial communication with a baud rate of 9600
  Serial.begin(9600);

  // Initialize BMP180 barometric sensor
  initializeBMP180();
}

void loop() {
  // Print BMP180 data
  printBMP180();

  delay(500);
}

void initializeBMP180() {
  // Start BMP180 initialization
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP180 sensor, check wiring!");
    while (1)
      ;  // Halt if sensor not found
  }
  Serial.println("BMP180 Found!");
}

void printBMP180() {
  Serial.println();
  Serial.println("BMP180 ------------");
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  // Calculate altitude assuming 'standard' barometric
  // pressure of 1013.25 millibar = 101325 Pascal
  Serial.print("Altitude = ");
  Serial.print(bmp.readAltitude());
  Serial.println(" meters");

  Serial.print("Pressure at sealevel (calculated) = ");
  Serial.print(bmp.readSealevelPressure());
  Serial.println(" Pa");
  Serial.println("BMP180 ------------");
  Serial.println();
}