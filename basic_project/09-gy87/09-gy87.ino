/*
  This Arduino code is designed to work with the GY-87 IMU (Inertial Measurement Unit) module, 
  which is a multi-sensor module containing three individual sensors: MPU6050 (Accelerometer and Gyroscope), 
  QMC5883L Magnetometer, and BMP180 (Barometric Pressure and Temperature). The code initializes these 
  sensors and continuously prints their readings to the Serial Monitor.
  
  Board: Arduino Uno R4
  Component: GY-87 IMU Module
  Library: https://github.com/adafruit/Adafruit_MPU6050  (Adafruit MPU6050 by Adafruit)
           https://github.com/mprograms/QMC5883LCompass  (QMC5883LCompass by MPrograms)
           https://github.com/adafruit/Adafruit-BMP085-Library  (Adafruit BMP085 Library by Adafruit)
*/

// Include required libraries
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <QMC5883LCompass.h>

// Initialize sensor objects
Adafruit_MPU6050 mpu;
Adafruit_BMP085 bmp;
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

  // Initialize BMP180 barometric sensor
  initializeBMP180();
}


void loop() {
  // Print MPU6050 data
  printMPU6050();

  // Print QMC5883L data
  printQMC5883L();

  // Print BMP180 data
  printBMP180();
  
  delay(500);
}

void initializeQMC5883L() {

  compass.init();

  // You should replace the code below according to your calibration results
  compass.setCalibrationOffsets(-458.00, -310.00, -362.00);
  compass.setCalibrationScales(0.79, 0.79, 2.19);

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

void printMPU6050() {

  Serial.println();
  Serial.println("MPU6050 ------------");

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");

  Serial.println("MPU6050 ------------");
  Serial.println();
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