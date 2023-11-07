/*
  This code is designed to connect an Arduino Uno R4 WiFi board to the internet and detect 
  motion using a PIR sensor. Upon detecting motion, it sends an HTTP GET request 
  to the IFTTT web service to trigger an event named "SecurityWarning". The code handles 
  WiFi connection setup, motion detection, server communication, and provides feedback via 
  the serial monitor.

  Board: Arduino Uno R4 WiFi
  Component: PIR Motion Sensor Module
*/

#include "WiFiS3.h"           // Include the WiFiS3 library for internet connectivity
#include "arduino_secrets.h"  // Include the file containing Wi-Fi credentials

// Wi-Fi credentials are stored in arduino_secrets.h
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

int status = WL_IDLE_STATUS;
WiFiClient client;

// IFTTT server information and event name
char server[] = "maker.ifttt.com";
char event[] = "SecurityWarning";
String webRequestURL = "/trigger/" + String(event) + "/with/key/" + String(WEBHOOKS_KEY);

const int pirPin = 2;         // PIR sensor is connected to digital pin 2
bool motionDetected = false;  // Variable to track motion detection

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  // Check the status of the WiFi module
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (1)
      ;  // Infinite loop to halt further execution
  }

  // Check if the WiFi firmware is up to date
  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  // Attempt to connect to the Wi-Fi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }
  printWifiStatus();  // Print the status of the WiFi connection

  pinMode(pirPin, INPUT);
}

void loop() {
  readResponse();  // Read and print server response if available

  // Check for motion using PIR sensor
  if (digitalRead(pirPin) == HIGH) {
    if (!motionDetected) {
      Serial.println("Motion detected!");
      triggerIFTTTEvent();  // Trigger IFTTT notification
      motionDetected = true;
    }
  } else {
    motionDetected = false;
  }
}

void readResponse() {
  // Read incoming data from the WiFi connection
  uint32_t received_data_num = 0;
  while (client.available()) {
    char c = client.read();
    Serial.print(c);
    received_data_num++;
    if (received_data_num % 80 == 0) {
      Serial.println();
    }
  }
}

void triggerIFTTTEvent() {
  client.stop();  // Terminate any existing connections

  // Attempt to connect to the IFTTT server
  if (client.connect(server, 80)) {  // If the connection is successful
    Serial.println("connecting...");
    // Construct and send the HTTP GET request
    client.println("GET " + webRequestURL + " HTTP/1.1");
    client.println("Host: maker.ifttt.com");
    client.println("User-Agent: ArduinoWiFi/1.1");
    client.println("Connection: close");
    client.println();  // End of HTTP request
  } else {
    Serial.println("connection failed");  // Notify if the connection fails
  }
}

void printWifiStatus() {
  // Print the current Wi-Fi status to the serial monitor
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  long rssi = WiFi.RSSI();
  Serial.print("Signal Strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
