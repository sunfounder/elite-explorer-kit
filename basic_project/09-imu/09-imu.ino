#include "SunFounder_IMU.hpp"
#include "calibration_data.h"

#include "Wire.h"

// For Arduino UNO R4, use Wire1 as I2C bus
#define Wire Wire1
// For ESP32, you may need to set the I2C pins
// #define SDA 43
// #define SCL 44

SunFounder_IMU imu(&Wire);

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(100);
  }
  // For ESP32, you may need to set the I2C pins
  // Wire.begin(SDA, SCL);
  Wire.begin();
  imu.begin();
  imu.set_accel_bias(ACCEL_BIAS);
  imu.set_accel_scale(ACCEL_SCALE);
  imu.set_gyro_bias(GYRO_BIAS);
  imu.set_gyro_scale(GYRO_SCALE);
  imu.set_magnetometer_bias(MAG_BIAS);
  imu.set_magnetometer_scale(MAG_SCALE);

  // Change these if necessary
  // imu.set_gravity(GRAVITY);
  // imu.set_barometer_pressure_offset(BARO_PRESSURE_OFFSET);
  // imu.set_barometer_sealevel_pressure(BARO_SEALEVEL_PRESSURE);
}

void loop() {
  imu.read();
  if (imu.is_motion_sensor_found()) {
    Vector3f accel = imu.get_accel();
    Vector3f gyro = imu.get_gyro();

    Serial.print("Accel: ");
    Serial.print(accel.x);
    Serial.print(", ");
    Serial.print(accel.y);
    Serial.print(", ");
    Serial.println(accel.z);
    Serial.print("Gyro: ");
    Serial.print(gyro.x);
    Serial.print(", ");
    Serial.print(gyro.y);
    Serial.print(", ");
    Serial.println(gyro.z);
  }
  if (imu.is_magnetometer_found()) {
    Vector3f magnetometer = imu.get_magnetometer();
    float azimuth = imu.get_azimuth();
    Serial.print("Magnetometer: ");
    Serial.print(magnetometer.x);
    Serial.print(", ");
    Serial.print(magnetometer.y);
    Serial.print(", ");
    Serial.println(magnetometer.z);
    Serial.print("Azimuth: ");
    Serial.println(azimuth);
  }
  if (imu.is_barometer_found()) {
    float temperature = imu.get_temperature();
    float pressure = imu.get_pressure();
    float altitude = imu.get_altitude();

    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Pressure: ");
    Serial.println(pressure);
    Serial.print("Altitude: ");
    Serial.println(altitude);
  }
  delay(1000);
}
