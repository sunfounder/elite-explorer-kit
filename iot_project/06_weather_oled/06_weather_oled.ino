/*
  The code fetches and shows weather information such as temperature, humidity, pressure, 
  and wind details. This information is obtained from the OpenWeatherMap API through a WiFi 
  connection. The program initially connects to the WiFi network and retrieves the current 
  time from an NTP server. It then regularly sends HTTP requests to retrieve weather data 
  from the OpenWeatherMap API. Upon receiving a JSON response, it parses the data and displays 
  both the weather information and current time on the OLED screen.

  Board: Arduino Uno R4 WiFi
  Component: OLED
  Library: https://github.com/bblanchon/ArduinoJson (ArduinoJson by Benoit Blanchon)
           0https://github.com/adafruit/Adafruit_SSD1306 (Adafruit SSD1306 by Adafruit)  
           https://github.com/adafruit/Adafruit-GFX-Library (Adafruit GFX Library by Adafruit) 
           
*/

#include "WiFiS3.h"
#include <ArduinoJson.h>  // JSON decoding library
#include "arduino_secrets.h"

// NTP client setup to get real-time data
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
#define OLED_RESET 4      // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// WiFi credentials and server information
char ssid[] = SECRET_SSID;  // your network SSID (name)
char pass[] = SECRET_PASS;  // your network password
int status = WL_IDLE_STATUS;
char server[] = "api.openweathermap.org";  // name address for OWM (using DNS)

// Timing variables to manage update intervals
unsigned long lastConnectionTime = 0;               // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 60L * 1000L;  // delay between updates, in milliseconds

// WiFi client for connecting to the API server
WiFiClient client;

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
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(5000);  // Wait 5 seconds before retrying
  }

  printWifiStatus();

  // Initialize and clear OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();

  // Initialize and clear OLED display
  timeClient.begin();
  timeClient.setTimeOffset(3600 * 8);  // Adjust for your time zone (this is +8 hour)
}

void loop() {

  read_response();
  timeClient.update();

  // Check if it's time to send a new request
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
  }
}


void read_response() {
  uint32_t received_data_num = 0;
  String payload = "";
  bool jsonDetected = false;

  // Read data from the client connection
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


void httpRequest() {
  // close any connection before send a new request.
  client.stop();

  // Construct HTTP GET request for OpenWeatherMap API
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

void printWifiStatus() {
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
  display.setTextSize(1);               // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Draw white text
  display.setCursor(0, 0);              // Start at top-left corner

  // Display Day of the Week
  String daysOfTheWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
  display.println(daysOfTheWeek[timeClient.getDay()]);

  // Display Time in HH:MM format
  display.print("Time: ");
  if (timeClient.getHours() < 10) display.print("0");  // Add leading zero for hours < 10
  display.print(timeClient.getHours());
  display.print(":");
  if (timeClient.getMinutes() < 10) display.print("0");  // Add leading zero for minutes < 10
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
