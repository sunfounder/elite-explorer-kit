/*
  This code is used to calibrate the QMC5883L magnetometer in the gy-87 module.

  Upload this calibration sketch onto your Arduino to provide calibration for 
  your QMC5883L chip.After upload, run the serial monitor and follow the directions.
  When prompted, copy the last line into your project's actual sketch.

  Board: Arduino Uno R4
  Component: GY-87 IMU Module
  Library: https://github.com/adafruit/Adafruit_MPU6050  (Adafruit MPU6050 by Adafruit)
           https://github.com/mprograms/QMC5883LCompass  (QMC5883LCompass by MPrograms)
           https://github.com/adafruit/Adafruit-BMP085-Library  (Adafruit BMP085 Library by Adafruit)
*/

#include <Adafruit_MPU6050.h>
#include <QMC5883LCompass.h>

Adafruit_MPU6050 mpu;
QMC5883LCompass compass;

void setup() {
  Serial.begin(9600);
  
  initializeMPU6050();

  // Enable I2C bypass on MPU6050 to directly access the QMC5883L magnetometer
  mpu.setI2CBypass(true);

  compass.init();
  
  Serial.println("This will provide calibration settings for your QMC5883L chip. When prompted, move the magnetometer in all directions until the calibration is complete.");
  Serial.println("Calibration will begin in 5 seconds.");
  delay(5000);

  Serial.println("CALIBRATING. Keep moving your sensor...");
  compass.calibrate();

  Serial.println("DONE. Copy the lines below and paste it into your projects sketch.);");
  Serial.println();
  Serial.print("compass.setCalibrationOffsets(");
  Serial.print(compass.getCalibrationOffset(0));
  Serial.print(", ");
  Serial.print(compass.getCalibrationOffset(1));
  Serial.print(", ");
  Serial.print(compass.getCalibrationOffset(2));
  Serial.println(");");
  Serial.print("compass.setCalibrationScales(");
  Serial.print(compass.getCalibrationScale(0));
  Serial.print(", ");
  Serial.print(compass.getCalibrationScale(1));
  Serial.print(", ");
  Serial.print(compass.getCalibrationScale(2));
  Serial.println(");");
}

void loop() {
  delay(1000);
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