/*
  The code implements a Bluetooth Low Energy (BLE) peripheral using an Arduino Uno R4 WiFi 
  board. It advertises a BLE service with a custom UUID and a characteristic that can be read 
  and written to. A Liquid Crystal Display (LCD) with an I2C interface is used to display the 
  message when the BLE central device writes to the characteristic. 

  Board: Arduino Uno R4 WiFI
  Component: Liquid Crystal Display 1602 with I2C Interface
  Library: https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/ (LiquidCrystal I2C by Frank de Brabander)
           https://www.arduino.cc/reference/en/libraries/arduinoble/ (ArduinoBLE by Arduino)
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoBLE.h>

#define SERVICE_UUID "19B10002-E8AA-548E-4F6C-D104768A1214"
#define CHARACTERISTIC_UUID "19B10003-E8AA-548E-4F6C-D104768A1214"

// Define a BLE service with a UUID
BLEService boxService(SERVICE_UUID);

// Define a BLE characteristic with a UUID and properties
char *stringValue = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
BLECharacteristic boxCharacteristic(CHARACTERISTIC_UUID, BLERead | BLEWrite, stringValue);

// Initialize a 16x2 LCD using I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1)
      ;
  }

  // Set advertised local name and service UUID:
  BLE.setLocalName("UNO R4 BLE");
  BLE.setAdvertisedService(boxService);
  // Add characteristics to the service
  boxService.addCharacteristic(boxCharacteristic);

  // Add service
  BLE.addService(boxService);

  // Start advertising
  BLE.advertise();
  Serial.println("BLE Peripheral");

  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bluetooth LCD");
}

void loop() {
  BLEDevice central = BLE.central();
  if (central) {  // If a central device is connected
    Serial.print("Connected to central: ");
    Serial.println(central.address());

    while (central.connected()) {                      // While the central device is connected
      if (boxCharacteristic.written()) {               // Check if the characteristic has been written
        int length = boxCharacteristic.valueLength();  // Get the length of the written value
        byte buffer[length + 1];                       // Create a buffer to store the value
        boxCharacteristic.readValue(buffer, length);   // Read the value into the buffer
        buffer[length] = '\0';                         // Null-terminate the buffer to treat it as a string
        Serial.print("Characteristic event, written: ");
        Serial.print((char *)buffer);

        // Print the received message to the LCD
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Message:       ");
        lcd.setCursor(0, 1);
        lcd.print((char *)buffer);
      }
    }
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}
