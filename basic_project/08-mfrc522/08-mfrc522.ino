/*
  The code is designed for an Arduino system to interface with an RFID-RC522 Module 
  using the "RFID1" library. It initializes the RFID module and continuously scans for 
  RFID cards. When a card is detected, the code prints the card type and its 4-byte 
  serial number to the serial monitor.
  
  Board: Arduino Uno R4
  Component: RFID-RC522 Module
  Library: 
*/

#include "rfid1.h"  // Include RFID1 library
RFID1 rfid;         // Create an instance of the RFID1 class

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud
  // Initialize the RFID reader with pin configuration
  rfid.begin(7, 5, 4, 3, 6, 2);  // IRQ_PIN, SCK_PIN, MOSI_PIN, MISO_PIN, SDA_PIN, RST_PIN
  delay(100);                    // Delay for 100 milliseconds
  rfid.init();                   // Initialize the RFID module
}

void loop() {
  uchar status;        // Status variable to hold the state of RFID functions
  uchar str[MAX_LEN];  // Create an array to hold the RFID card data; maximum length is 16

  // Search for an RFID card and get its type
  status = rfid.request(PICC_REQIDL, str);
  if (status != MI_OK) {
    return;  // If no card is found, return to the beginning of loop()
  }
  Serial.print("Card type: ");
  Serial.println(rfid.readCardType(str));  // Print the card type to the serial monitor

  // Prevent RFID card collision and get the 4-byte serial number of the card
  status = rfid.anticoll(str);
  if (status == MI_OK) {
    Serial.print("The card's number is: ");
    int IDlen = 4;  // Length of the card's serial number
    for (int i = 0; i < IDlen; i++) {
      Serial.print(str[i], HEX);  // Print each byte of the card's serial number
    }
    Serial.println();
    Serial.println();  // Print an empty line for better readability
  }

  delay(500);   // Delay for 500 milliseconds
  rfid.halt();  // Put the card into sleep mode
}
