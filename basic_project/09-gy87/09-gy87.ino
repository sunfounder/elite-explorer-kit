/*
  This Arduino code is designed to work with the GY-87 IMU (Inertial Measurement Unit) module, 
  which is a multi-sensor module containing three individual sensors: MPU6050 (Accelerometer and Gyroscope), 
  HMC5883L (Magnetometer), and BMP180 (Barometric Pressure and Temperature). The code initializes these 
  sensors and continuously prints their readings to the Serial Monitor.
  
  Board: Arduino Uno R4
  Component: GY-87 IMU Module
  Library: https://github.com/adafruit/Adafruit_MPU6050  (Adafruit MPU6050 by Adafruit)
           https://github.com/adafruit/Adafruit_HMC5883_Unified  (Adafruit HMC5883 Unified by Adafruit)
           https://github.com/adafruit/Adafruit-BMP085-Library  (Adafruit BMP085 Library by Adafruit)
*/

// Include required libraries
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_HMC5883_U.h>
#include <Adafruit_BMP085.h>

// Initialize sensor objects
Adafruit_MPU6050 mpu;
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
Adafruit_BMP085 bmp;

void setup() {
  // Initialize the serial communication with a baud rate of 115200
  Serial.begin(115200);

  // Initialize the MPU6050 sensor (accelerometer and gyroscope)
  initializeMPU6050();

  // Enable I2C bypass on MPU6050 to directly access the HMC5883L magnetometer
  mpu.setI2CBypass(true);

  // Initialize the HMC5883L magnetometer sensor
  initializeHMC5883L();

  // Initialize BMP180 barometric sensor
  // initializeBMP180();
}


void loop() {
  // Print MPU6050 data
  printMPU6050();
  delay(500);

  // Print HMC5883L data
  printHMC5883L();
  delay(500);

  // Print BMP180 data
  // printBMP180();
  // delay(500);
}


void initializeHMC5883L() {
  Serial.println("HMC5883L Magnetometer Test");

  // Check if HMC5883L is detected
  if (!mag.begin()) {
    Serial.println("Ooops, no HMC5883L detected ... Check your wiring!");
    while (1);  // Halt if sensor not found
  }

  // Print HMC5883L details
  sensor_t sensor;
  mag.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print("Sensor:       ");
  Serial.println(sensor.name);
  Serial.print("Driver Ver:   ");
  Serial.println(sensor.version);
  Serial.print("Unique ID:    ");
  Serial.println(sensor.sensor_id);
  Serial.print("Max Value:    ");
  Serial.print(sensor.max_value);
  Serial.println(" uT");
  Serial.print("Min Value:    ");
  Serial.print(sensor.min_value);
  Serial.println(" uT");
  Serial.print("Resolution:   ");
  Serial.print(sensor.resolution);
  Serial.println(" uT");
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}

void printHMC5883L() {

  Serial.println();
  Serial.println("HMC5883L ------------");

  /* Get a new sensor event */
  sensors_event_t event;
  mag.getEvent(&event);

  /* Display the results (magnetic vector values are in micro-Tesla (uT)) */
  Serial.print("X: ");
  Serial.print(event.magnetic.x);
  Serial.print("  ");
  Serial.print("Y: ");
  Serial.print(event.magnetic.y);
  Serial.print("  ");
  Serial.print("Z: ");
  Serial.print(event.magnetic.z);
  Serial.print("  ");
  Serial.println("uT");

  // Hold the module so that Z is pointing 'up' and you can measure the heading with x&y
  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  float heading = atan2(event.magnetic.y, event.magnetic.x);

  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: -13* 2' W, which is ~13 Degrees, or (which we need) 0.22 radians
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  float declinationAngle = 0.22;
  heading += declinationAngle;

  // Correct for when signs are reversed.
  if (heading < 0)
    heading += 2 * PI;

  // Check for wrap due to addition of declination.
  if (heading > 2 * PI)
    heading -= 2 * PI;

  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180 / M_PI;

  Serial.print("Heading (degrees): ");
  Serial.println(headingDegrees);

  Serial.println("HMC5883L ------------");
  Serial.println();
}

void initializeMPU6050() {
  Serial.println("Adafruit MPU6050 test!");

  // Check if the MPU6050 sensor is detected
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1);  // Halt if sensor not found
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
    while (1);  // Halt if sensor not found
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