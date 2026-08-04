#pragma once

// Accel gyro and magnetometer calibration data,
// calibrate with calibrate.ino and copy the result here:
const float ACCEL_BIAS[3] = {0.0, 0.0, 0.0};
const float ACCEL_SCALE[3] = {1.0, 1.0, 1.0};
const float GYRO_BIAS[3] = {0.0, 0.0, 0.0};
const float GYRO_SCALE[3] = {1.0, 1.0, 1.0};
const float MAG_BIAS[3] = {0.0, 0.0, 0.0};
const float MAG_SCALE[3] = {1.0, 1.0, 1.0};

// Barometer pressure offset in hPa
// const float BARO_PRESSURE_OFFSET = 0.0f;
// Sealevel pressure in hPa
// const float BARO_SEALEVEL_PRESSURE = 1013.25f;
// Gravity in m/s^2
// const float GRAVITY = 9.80665f;
