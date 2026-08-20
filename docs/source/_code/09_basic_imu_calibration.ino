#include "SunFounder_IMU.hpp"
#include "Wire.h"

// For Arduino UNO R4, use Wire1 as the I2C bus.
#define Wire Wire1

// For ESP32, you may need to set the I2C pins.
// #define SDA 43
// #define SCL 44

SunFounder_IMU imu(&Wire);

const char *FACES[] = {
  "Z face up",
  "Z face down",
  "X face up",
  "X face down",
  "Y face up",
  "Y face down"
};

const int FACES_COUNT = 6;
const int SAMPLE_COUNT = 100;
const int SETTLING_TIME_MS = 500;
const int SAMPLE_INTERVAL_MS = 10;

float accel_means[FACES_COUNT][3];
float gyro_means[FACES_COUNT][3];
float magnetometer_means[FACES_COUNT][3];

enum CalibrationState {
  WAIT_FOR_START,
  WAIT_FOR_FACE,
  CALIBRATION_FINISHED
};

CalibrationState calibration_state = WAIT_FOR_START;
int current_face = 0;

void clear_serial_input() {
  while (Serial.available()) {
    Serial.read();
  }
}

void show_face_prompt() {
  Serial.println();
  Serial.println("=================");
  Serial.print("*  ");
  Serial.println(FACES[current_face]);
  Serial.println("=================");
  Serial.print("Place the device with ");
  Serial.print(FACES[current_face]);
  Serial.println(".");
  Serial.println("Keep it completely still during measurement.");
  Serial.println();
  Serial.println("When you are ready, send any character to continue.");
}

void read_current_face() {
  double accel_total[3] = {0.0, 0.0, 0.0};
  double gyro_total[3] = {0.0, 0.0, 0.0};
  double magnetometer_total[3] = {0.0, 0.0, 0.0};

  Serial.println();
  Serial.println("Keep the device still...");
  delay(SETTLING_TIME_MS);

  Serial.print("Reading data: ");

  for (int sample = 0; sample < SAMPLE_COUNT; sample++) {
    imu.read(true);

    accel_total[0] += imu.get_accel().x;
    accel_total[1] += imu.get_accel().y;
    accel_total[2] += imu.get_accel().z;

    gyro_total[0] += imu.get_gyro().x;
    gyro_total[1] += imu.get_gyro().y;
    gyro_total[2] += imu.get_gyro().z;

    magnetometer_total[0] += imu.get_magnetometer().x;
    magnetometer_total[1] += imu.get_magnetometer().y;
    magnetometer_total[2] += imu.get_magnetometer().z;

    if ((sample + 1) % 10 == 0) {
      Serial.print("=");
    }

    delay(SAMPLE_INTERVAL_MS);
  }

  for (int axis = 0; axis < 3; axis++) {
    accel_means[current_face][axis] =
        accel_total[axis] / SAMPLE_COUNT;
    gyro_means[current_face][axis] =
        gyro_total[axis] / SAMPLE_COUNT;
    magnetometer_means[current_face][axis] =
        magnetometer_total[axis] / SAMPLE_COUNT;
  }

  Serial.println();
  Serial.println("Reading complete.");
}

void find_axis_min_max(float means_data[][3],
                       float axis_min[3],
                       float axis_max[3]) {
  for (int axis = 0; axis < 3; axis++) {
    axis_min[axis] = means_data[0][axis];
    axis_max[axis] = means_data[0][axis];

    for (int face = 1; face < FACES_COUNT; face++) {
      if (means_data[face][axis] < axis_min[axis]) {
        axis_min[axis] = means_data[face][axis];
      }

      if (means_data[face][axis] > axis_max[axis]) {
        axis_max[axis] = means_data[face][axis];
      }
    }
  }
}

void calculate_accel_calibration(float bias[3], float scale[3]) {
  float axis_min[3];
  float axis_max[3];

  find_axis_min_max(accel_means, axis_min, axis_max);

  for (int axis = 0; axis < 3; axis++) {
    float range = axis_max[axis] - axis_min[axis];

    bias[axis] = (axis_max[axis] + axis_min[axis]) / 2.0f;

    if (fabs(range) < 0.1f) {
      // A valid six-face accelerometer range should be close to 2 g.
      // Keep a safe value if one face was measured incorrectly.
      scale[axis] = 1.0f;
    } else {
      scale[axis] = 2.0f / range;
    }
  }
}

void calculate_gyro_calibration(float bias[3], float scale[3]) {
  // The gyroscope remains still during all six measurements.
  // Its average reading is the zero-rate bias.
  for (int axis = 0; axis < 3; axis++) {
    double total = 0.0;

    for (int face = 0; face < FACES_COUNT; face++) {
      total += gyro_means[face][axis];
    }

    bias[axis] = total / FACES_COUNT;

    // Static six-face measurements cannot determine gyroscope sensitivity.
    scale[axis] = 1.0f;
  }
}

void calculate_mag_calibration(float bias[3], float scale[3]) {
  float axis_min[3];
  float axis_max[3];
  float half_range[3];

  find_axis_min_max(magnetometer_means, axis_min, axis_max);

  for (int axis = 0; axis < 3; axis++) {
    bias[axis] = (axis_max[axis] + axis_min[axis]) / 2.0f;
    half_range[axis] =
        fabs(axis_max[axis] - axis_min[axis]) / 2.0f;
  }

  // Use the average radius as the common target. This preserves the
  // magnetic-field magnitude while compensating for axis sensitivity.
  float average_half_range =
      (half_range[0] + half_range[1] + half_range[2]) / 3.0f;

  for (int axis = 0; axis < 3; axis++) {
    if (half_range[axis] < 0.001f || average_half_range < 0.001f) {
      scale[axis] = 1.0f;
    } else {
      scale[axis] = average_half_range / half_range[axis];
    }
  }
}

void print_float_array(const char *name, const float values[3]) {
  Serial.print("const float ");
  Serial.print(name);
  Serial.print("[3] = {");
  Serial.print(values[0], 4);
  Serial.print(", ");
  Serial.print(values[1], 4);
  Serial.print(", ");
  Serial.print(values[2], 4);
  Serial.println("};");
}

void print_calibration_results() {
  float accel_bias[3];
  float accel_scale[3];
  float gyro_bias[3];
  float gyro_scale[3];
  float magnetometer_bias[3];
  float magnetometer_scale[3];

  calculate_accel_calibration(accel_bias, accel_scale);
  calculate_gyro_calibration(gyro_bias, gyro_scale);
  calculate_mag_calibration(magnetometer_bias, magnetometer_scale);

  Serial.println();
  Serial.println("Calibration complete!");
  Serial.println(
      "Copy the following calibration data to your calibration_data.h:");

  print_float_array("ACCEL_BIAS", accel_bias);
  print_float_array("ACCEL_SCALE", accel_scale);
  print_float_array("GYRO_BIAS", gyro_bias);
  print_float_array("GYRO_SCALE", gyro_scale);
  print_float_array("MAG_BIAS", magnetometer_bias);
  print_float_array("MAG_SCALE", magnetometer_scale);

  Serial.println();
  Serial.println("Important:");
  Serial.println("- The gyroscope is calibrated for bias only. Its scale remains 1.0.");
  Serial.println("- Keep the device away from magnets and large metal objects during calibration.");
  Serial.println();
  Serial.println("To calibrate again, click Stop, then click Run.");
}

void setup() {
  Serial.begin(115200);

  while (!Serial) {
    delay(100);
  }

  Wire.begin();
  imu.begin();

  // App Lab may not display messages printed during setup().
  // The first Serial Monitor input displays the first instruction.
}

void loop() {
  if (!Serial.available()) {
    delay(50);
    return;
  }

  clear_serial_input();

  if (calibration_state == WAIT_FOR_START) {
    Serial.println("IMU initialized successfully.");
    Serial.println("Starting calibration process...");

    current_face = 0;
    show_face_prompt();

    calibration_state = WAIT_FOR_FACE;
    return;
  }

  if (calibration_state == WAIT_FOR_FACE) {
    read_current_face();
    current_face++;

    if (current_face < FACES_COUNT) {
      show_face_prompt();
    } else {
      print_calibration_results();
      calibration_state = CALIBRATION_FINISHED;
    }

    return;
  }

  Serial.println();
  Serial.println("Calibration is already complete.");
  Serial.println("Restart the app to run the calibration again.");
}
