/*
  This Arduino code interfaces with the GY-87 IMU  module, focusing specifically on 
  the QMC5883L magnetometer for measuring magnetic field data. It initializes the 
  QMC5883L sensor and continuously outputs its readings, including directional data, 
  to the Serial Monitor.
  
  Board: Arduino Uno R4
  Component: GY-87 IMU Module
  Library: https://github.com/adafruit/Adafruit_MPU6050  (Adafruit MPU6050 by Adafruit)
           https://github.com/mprograms/QMC5883LCompass  (QMC5883LCompass by MPrograms)
*/

// Include required libraries
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <QMC5883LCompass.h>

// Initialize sensor objects
Adafruit_MPU6050 mpu;
QMC5883LCompass compass;

void setup() {
  // Initialize the serial communication with a baud rate of 9600
  Serial.begin(9600);

  // Initialize the MPU6050 sensor (accelerometer and gyroscope)
  initializeMPU6050();

  // Enable I2C bypass on MPU6050 to directly access the QMC5883L magnetometer
  mpu.setI2CBypass(true);

  // Initialize the QMC5883L magnetometer sensor
  initializeQMC5883L();
}


void loop() {
  // Print QMC5883L data
  printQMC5883L();

  delay(500);
}

void initializeQMC5883L() {
  compass.init();

  // You should replace the code below according to your calibration results
  compass.setCalibrationOffsets(-549.00, -66.00, 160.00);
  compass.setCalibrationScales(0.97, 1.02, 1.02);
}

void printQMC5883L() {

  Serial.println();
  Serial.println("QMC5883L ------------");

  int x, y, z, a;
  char myArray[3];

  compass.read();

  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();

  a = compass.getAzimuth();

  compass.getDirection(myArray, a);

  Serial.print("X: ");
  Serial.print(x);

  Serial.print(" Y: ");
  Serial.print(y);

  Serial.print(" Z: ");
  Serial.print(z);

  Serial.print(" Azimuth: ");
  Serial.print(a);

  Serial.print(" Direction: ");
  Serial.print(myArray[0]);
  Serial.print(myArray[1]);
  Serial.println(myArray[2]);

  Serial.println("QMC5883L ------------");
  Serial.println();
}

void initializeMPU6050() {
  // Check if the MPU6050 sensor is detected
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1)
      ;  // Halt if sensor not found
  }
  Serial.println("MPU6050 Found!");

  // set accelerometer range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("");
  delay(100);
}
