
#include "WiFiS3.h"
#include <ArduinoJson.h>  // JSON decoding library

#include "arduino_secrets.h"

// get real time
#include <NTPClient.h>
#include <WiFiUdp.h>
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");  // NTP server

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET 4  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;  // your network SSID (name)
char pass[] = SECRET_PASS;  // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;           // your network key index number (needed only for WEP)

int status = WL_IDLE_STATUS;
char server[] = "api.openweathermap.org";  // name address for OWM (using DNS)

unsigned long lastConnectionTime = 0;            // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 60L * 1000L; // delay between updates, in milliseconds

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;

/* -------------------------------------------------------------------------- */
void setup() {
  /* -------------------------------------------------------------------------- */
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
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }

  printWifiStatus();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();  
  display.clearDisplay();

  timeClient.begin();
  timeClient.setTimeOffset(3600*8);  // Adjust for your time zone (this is +8 hour)

}

/* just wrap the received data up to 80 columns in the serial print*/
/* -------------------------------------------------------------------------- */
void read_response() {
  /* -------------------------------------------------------------------------- */
  uint32_t received_data_num = 0;
  String payload = "";
  bool jsonDetected = false;
  while (client.available()) {
    /* actual data reception */
    char c = client.read();
    if ('{' == c) {
      jsonDetected = true;
    }
    if (jsonDetected) {
      payload += c;
    }
    received_data_num++;
  }
  if (jsonDetected) {
    /* print data to serial port */
    // Serial.print("data num : ");
    // Serial.println(received_data_num);
    // Serial.print("data : ");
    // Serial.println(payload);
    DynamicJsonDocument root(1024);
    DeserializationError error = deserializeJson(root, payload);
    if (error) {
      Serial.print("Deserialization failed with code: ");
      Serial.println(error.c_str());
      return;
    }

    float temp = (float)(root["main"]["temp"]) - 273.15;        // get temperature in °C
    int humidity = root["main"]["humidity"];                    // get humidity in %
    float pressure = (float)(root["main"]["pressure"]) / 1000;  // get pressure in bar
    float wind_speed = root["wind"]["speed"];                   // get wind speed in m/s
    int wind_degree = root["wind"]["deg"];                      // get wind degree in °

    // // print data
    // Serial.println("Temperature= " + String(temp) + " °C");
    // Serial.println("Humidity = " + String(humidity) + " %");
    // Serial.println("Pressure = " + String(pressure) + " bar");
    // Serial.println("Wind speed = " + String(wind_speed) + " m/s");
    // Serial.println("Wind degree = " + String(wind_degree) + " °");
    displayWeatherData(temp, humidity, pressure, wind_speed);
  }
}

// this method makes a HTTP connection to the server:
/* -------------------------------------------------------------------------- */
void httpRequest() {
/* -------------------------------------------------------------------------- */  
  // close any connection before send a new request.
  // This will free the socket on the NINA module
  client.stop();

  // if there's a successful connection:
  String httpRequest = "";
  httpRequest += "GET /data/2.5/weather?q=" LOCATION "&APPID=" API_KEY " HTTP/1.1";

  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.println(httpRequest);
    client.println("Host: api.openweathermap.org");
    client.println("Connection: close");
    client.println();
    // note the time that the connection was made:
    lastConnectionTime = millis();
  } else {
    // if you couldn't make a connection:
    Serial.println("connection failed");
  }
}

/* -------------------------------------------------------------------------- */
void loop() {
  /* -------------------------------------------------------------------------- */
  read_response();
  timeClient.update();
   
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
  }
}

/* -------------------------------------------------------------------------- */
void printWifiStatus() {
  /* -------------------------------------------------------------------------- */
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

void displayWeatherData(float temp, int humidity, float pressure, float wind_speed) {
    display.clearDisplay();
    display.setTextSize(1);      // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE); // Draw white text
    display.setCursor(0, 0);     // Start at top-left corner

    // Display Day of the Week
    String daysOfTheWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    display.println(daysOfTheWeek[timeClient.getDay()]);

    // Display Time in HH:MM format
    display.print("Time: ");
    if(timeClient.getHours() < 10) display.print("0"); // Add leading zero for hours < 10
    display.print(timeClient.getHours());
    display.print(":");
    if(timeClient.getMinutes() < 10) display.print("0"); // Add leading zero for minutes < 10
    display.println(timeClient.getMinutes());


    display.print("Temp: ");
    display.print(temp);
    display.println(" C");
    
    display.print("Humidity: ");
    display.print(humidity);
    display.println(" %");
    
    display.print("Pressure: ");
    display.print(pressure);
    display.println(" bar");
    
    display.print("Wind: ");
    display.print(wind_speed);
    display.println(" m/s");

    display.display();
}
