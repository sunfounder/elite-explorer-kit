/*
  The code is designed for an Arduino Uno R4 WiFi to establish a connection with 
  both a Wi-Fi network and an MQTT broker. It constantly monitors the status of 
  four buttons that are connected to digital inputs. Whenever a button is pressed, 
  it sends a message to a specific MQTT topic. Additionally, the code incorporates 
  functions for displaying Wi-Fi network information and managing received MQTT 
  messages.

  Board: Arduino Uno R4 WiFi
  Component: Button
  Library: https://github.com/arduino-libraries/ArduinoMqttClient (ArduinoMqttClient by Arduino)
*/

#include <WiFiS3.h>
#include <ArduinoMqttClient.h>

#include "arduino_secrets.h"
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;    // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;  // the WiFi radio's status

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "broker.hivemq.com";
int port = 1883;
const char topic[] = "SunFounder MQTT Test";

//init buttons & states
const int buttonPins[4] = { 2, 3, 4, 5 };
bool previousButtonStates[4] = { false, false, false, false };

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

    // wait 5 seconds for connection:
    delay(5000);
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

  // set button pins as INPUT_PULLUP
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    previousButtonStates[i] = digitalRead(buttonPins[i]);
  }
}

void loop() {

  // call poll() regularly to allow the library to receive MQTT messages and
  // send MQTT keep alives which avoids being disconnected by the broker
  mqttClient.poll();

  // Check button status
  for (int i = 0; i < 4; i++) {
    bool currentButtonState = digitalRead(buttonPins[i]);

    // If the button is pressed and its previous state was not pressed.
    if (!currentButtonState && previousButtonStates[i]) {
      sendButtonMessage(i + 1);  // The message that the send button has been pressed.
    }

    previousButtonStates[i] = currentButtonState;  // Update button status
  }

  // Add a delay to avoid constant pinging
  delay(50);
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

  Serial.print("Message to me: ");
  Serial.println(message);

  Serial.println();
}

void sendButtonMessage(int buttonNumber) {
  String message = "Button " + String(buttonNumber) + " was pressed.";

  Serial.println(message);

  mqttClient.beginMessage(topic);
  mqttClient.print(message);
  mqttClient.endMessage();
}
