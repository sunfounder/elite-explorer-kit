/*
  The code is designed for an Arduino Uno R4 WiFi to connect to a Wi-Fi network, 
  subscribe to an MQTT topic, and control a chain of NeoPixel LEDs based on messages 
  received from the MQTT broker. It listens for color commands from the cheerlights 
  topic and updates the LED colors accordingly.

  Board: Arduino Uno R4 WiFi
  Component: WS2812
  Library: https://github.com/arduino-libraries/ArduinoMqttClient (ArduinoMqttClient by Arduino)
           https://github.com/FastLED/FastLED (FastLED by Daniel Garcia)
           
*/

#include <WiFiS3.h>
#include <ArduinoMqttClient.h>
#include <FastLED.h>

#define NUM_LEDS 8  // Number of LEDs in the chain
#define DATA_PIN 6  // Data pin for LED control

#include "arduino_secrets.h"
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;    // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;  // the WiFi radio's status

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "mqtt.cheerlights.com";
int port = 1883;
const char topic[] = "cheerlights";



CRGB leds[NUM_LEDS];  // Array to hold LED color data

// Define the supported CheerLights colors and their RGB values
String colorName[] = { "red", "pink", "green", "blue", "cyan", "white", "warmwhite", "oldlace", "purple", "magenta", "yellow", "orange" };

int colorRGB[][3] = { 255, 0, 0,      // "red"
                      255, 192, 203,  // "pink"
                      0, 255, 0,      // "green"
                      0, 0, 255,      // "blue"
                      0, 255, 255,    // "cyan"
                      255, 255, 255,  // "white"
                      255, 223, 223,  // "warmwhite"
                      255, 223, 223,  // "oldlace"
                      128, 0, 128,    // "purple"
                      255, 0, 255,    // "magenta"
                      255, 255, 0,    // "yellow"
                      255, 165, 0 };  // "orange"


void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);

  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true)
      ;
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }

  // you're connected now, so print out the data:
  Serial.print("You're connected to the network");
  printCurrentNet();
  printWifiData();

  // You can provide a unique client ID, if not set the library uses Arduino-millis()
  // Each client must have a unique client ID
  // mqttClient.setId("clientId");

  // You can provide a username and password for authentication
  // mqttClient.setUsernamePassword("username", "password");

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1)
      ;
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();

  // set the message receive callback
  mqttClient.onMessage(onMqttMessage);

  Serial.print("Subscribing to topic: ");
  Serial.println(topic);
  Serial.println();

  // subscribe to a topic
  mqttClient.subscribe(topic);

  // topics can be unsubscribed using:
  // mqttClient.unsubscribe(topic);

  Serial.print("Waiting for messages on topic: ");
  Serial.println(topic);
  Serial.println();

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Initialize LEDs
}

void loop() {

  // call poll() regularly to allow the library to receive MQTT messages and
  // send MQTT keep alives which avoids being disconnected by the broker
  mqttClient.poll();

  // Add a delay to avoid constant pinging
  delay(5000);
}

void printWifiData() {
  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");

  Serial.println(ip);

  // print your MAC address:
  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  printMacAddress(mac);
}

void printCurrentNet() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the MAC address of the router you're attached to:
  byte bssid[6];
  WiFi.BSSID(bssid);
  Serial.print("BSSID: ");
  printMacAddress(bssid);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);

  // print the encryption type:
  byte encryption = WiFi.encryptionType();
  Serial.print("Encryption Type:");
  Serial.println(encryption, HEX);
  Serial.println();
}

void printMacAddress(byte mac[]) {
  for (int i = 5; i >= 0; i--) {
    if (mac[i] < 16) {
      Serial.print("0");
    }
    Serial.print(mac[i], HEX);
    if (i > 0) {
      Serial.print(":");
    }
  }
  Serial.println();
}


void onMqttMessage(int messageSize) {
  // we received a message, print out the topic and contents
  Serial.print("Received a message with topic '");
  Serial.print(mqttClient.messageTopic());
  Serial.println("'");
  Serial.print("Message length: ");
  Serial.print(messageSize);
  Serial.println(" bytes:");

  // Read the message contents into a String
  String message = mqttClient.readString();

  // Convert the received message and comparison strings to lowercase
  message.toLowerCase();

  // If a message is received on the topic, you will check this message.
  // Changes the output state according to the message
  if (String(topic) == "cheerlights") {
    Serial.print("Changing color to ");
    Serial.println(message);
    setColor(message);
  }
}

void setColor(String color) {
  // Loop through the list of colors to find the matching color
  for (int colorIndex = 0; colorIndex < 12; colorIndex++) {
    if (color == colorName[colorIndex]) {
      // Set the color of each NeoPixel on the strip
      for (int pixel = 0; pixel < NUM_LEDS; pixel++) {
        leds[pixel] = CRGB(colorRGB[colorIndex][0], colorRGB[colorIndex][1], colorRGB[colorIndex][2]);
      }
      FastLED.show();
    }
  }
}