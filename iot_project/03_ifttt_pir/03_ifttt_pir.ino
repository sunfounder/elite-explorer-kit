#include "WiFiS3.h"
#include "arduino_secrets.h" 

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
int keyIndex = 0;
int status = WL_IDLE_STATUS;
WiFiClient client;

char server[] = "maker.ifttt.com";
char event[] = "SecurityWarning";
String webRequestURL = "/trigger/" + String(event) + "/with/key/" + String(WEBHOOKS_KEY);

// unsigned long lastConnectionTime = 0;
// const unsigned long postingInterval = 10L * 1000L;

const int pirPin = 2;  // Connect the PIR sensor to digital pin 2
bool motionDetected = false;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }
  printWifiStatus();

  pinMode(pirPin, INPUT);
}

void read_request() {
  uint32_t received_data_num = 0;
  while (client.available()) {
    char c = client.read();
    Serial.print(c);
    received_data_num++;
    if (received_data_num % 80 == 0) {
    }
  }
}

void loop() {
  read_request();

  // Check for motion using PIR sensor
  if (digitalRead(pirPin) == HIGH) {
    if (!motionDetected) {
      Serial.println("Motion detected!");
      httpRequest(); // Trigger IFTTT notification

      motionDetected = true;
    }
  } else {
    motionDetected = false;
  }
}

void httpRequest() {
  client.stop();

  if (client.connect(server, 80)) {
    Serial.println("connecting...");
    client.println("GET " + webRequestURL + " HTTP/1.1");
    client.println("Host: maker.ifttt.com");
    client.println("User-Agent: ArduinoWiFi/1.1");
    client.println("Connection: close");
    client.println();
    // lastConnectionTime = millis();
  } else {
    Serial.println("connection failed");
  }
}

void printWifiStatus() {
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
