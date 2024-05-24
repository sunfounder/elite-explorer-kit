/*
  This code demonstrates how to change and read the ADC resolution using an Arduino Uno R4.
  It initializes a serial connection and reads the analog input on pin A0 at different resolutions
  (10-bit, 12-bit, 14-bit, and 8-bit), printing the results to the Serial Monitor for comparison.

  Board: Arduino Uno R4
*/

void setup() {
  // open a serial connection
  Serial.begin(9600);
}

void loop() {
  // read the input on A0 at default resolution (10 bits)
  // and send it out the serial connection
  analogReadResolution(10);
  Serial.print("ADC 10-bit (default) : ");
  Serial.print(analogRead(A0));

  // change the resolution to 12 bits and read A0
  analogReadResolution(12);
  Serial.print(", 12-bit : ");
  Serial.print(analogRead(A0));

  // change the resolution to 14 bits and read A0
  analogReadResolution(14);
  Serial.print(", 16-bit : ");
  Serial.print(analogRead(A0));

  // change the resolution to 8 bits and read A0
  analogReadResolution(8);
  Serial.print(", 8-bit : ");
  Serial.println(analogRead(A0));

  // a little delay to not hog Serial Monitor
  delay(100);
}