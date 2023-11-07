/*
  This code is designed for an Arduino Uno R4 board to read temperature and humidity data 
  from a DHT11 sensor. It then transmits this data via Bluetooth Low Energy (BLE) to a connected 
  device. The code uses the DHT library for reading sensor data and the ArduinoBLE library for 
  Bluetooth communication. The BLE service and characteristics are set up according to the 
  specifications of the Bluetooth SIG for environmental sensing. Additionally, the code includes 
  functions for managing BLE connection and disconnection events, as well as a debug function 
  that prints sensor data to the serial monitor.

  Board: Arduino Uno R4 
  Component: DHT11
  Library: https://github.com/adafruit/DHT-sensor-library  (DHT sensor library by Adafruit)
           https://www.arduino.cc/reference/en/libraries/arduinoble/ (ArduinoBLE by Arduino)
*/


#include <DHT.h>
#include <ArduinoBLE.h>

#define DHTPIN 11      // Define the pin used to connect the sensor
#define DHTTYPE DHT11  // Define the sensor type

// Define UUIDs for BLE Environmental Sensing Service and Characteristics as per Bluetooth SIG specifications
// https://bitbucket.org/bluetooth-SIG/public/src/8a7ea26ae56d43e6fea88693232a01a78e28213e/assigned_numbers/uuids/service_uuids.yaml#lines-104:105
BLEService environmentalSensingService("181A");
// https://bitbucket.org/bluetooth-SIG/public/src/8a7ea26ae56d43e6fea88693232a01a78e28213e/assigned_numbers/uuids/characteristic_uuids.yaml#lines-299:303
BLEShortCharacteristic temperatureCharacteristic("2A6E", BLERead | BLENotify);
BLEUnsignedShortCharacteristic humidityCharacteristic("2A6F", BLERead | BLENotify);

DHT dht(DHTPIN, DHTTYPE);  // Create a DHT object

unsigned long lastUpdateTime = 0;           // Timestamp of last sensor data update
const unsigned long updateInterval = 5000;  // Sensor data update interval (ms)

void setup() {

  Serial.begin(9600);  // Initialize serial communication at 9600 baud
  dht.begin();         // Initialize DHT sensor

  // Initialize BLE, halt if initialization fails
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1)
      ;
  }

  setupBle();  // Setup BLE service and characteristics
}

void loop() {

  BLE.poll();  // Poll for BLE events

  // Check if it's time to update sensor data
  if (lastUpdateTime == 0 || millis() - lastUpdateTime > updateInterval) {
    float humidity = dht.readHumidity();        // Read humidity
    float temperature = dht.readTemperature();  // Read temperature

    // Check if any reads failed and exit early (to try again).
    if (isnan(humidity) || isnan(temperature)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }

    // Debug: print sensor data to serial monitor
    printDHT(humidity, temperature);

    // Update BLE characteristics with new sensor data
    temperatureCharacteristic.writeValue(round(temperature * 100.0));
    humidityCharacteristic.writeValue(round(humidity * 100.0));

    lastUpdateTime = millis();  // Update timestamp
  }
}

void printDHT(float h, float t) {
  // Print humidity and temperature data to serial monitor
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
}

void setupBle() {
  // Set advertised local name and service UUID:
  BLE.setLocalName("UNO R4 Home");
  BLE.setAdvertisedService(environmentalSensingService);

  // Add characteristics to the service
  environmentalSensingService.addCharacteristic(temperatureCharacteristic);
  environmentalSensingService.addCharacteristic(humidityCharacteristic);

  // Add service
  BLE.addService(environmentalSensingService);

  // Set initial characteristic values
  temperatureCharacteristic.writeValue(0);
  humidityCharacteristic.writeValue(0);

  // Set BLE event handlers for connection and disconnection
  BLE.setEventHandler(BLEConnected, blePeripheralConnectHandler);
  BLE.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);

  // Start advertising
  BLE.advertise();
}

void blePeripheralConnectHandler(BLEDevice central) {
  // Handle BLE peripheral connect event
  digitalWrite(LED_BUILTIN, HIGH);  // Turn on built-in LED
  Serial.print(F("Connected to central: "));
  Serial.println(central.address());
}

void blePeripheralDisconnectHandler(BLEDevice central) {
  // Handle BLE peripheral disconnect event
  digitalWrite(LED_BUILTIN, LOW);  // Turn off built-in LED
  Serial.print(F("Disconnected from central: "));
  Serial.println(central.address());
}
