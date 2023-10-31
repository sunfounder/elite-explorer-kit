#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 4     
#define DHTTYPE DHT11 
#define SOIL_MOISTURE_PIN A0
#define WATER_PUMP_PIN 8

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup() {
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  pinMode(WATER_PUMP_PIN, OUTPUT);
  digitalWrite(WATER_PUMP_PIN, LOW);
  
  lcd.init();                      
  lcd.backlight();
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  int soilMoisture = analogRead(SOIL_MOISTURE_PIN);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(temperature) + "C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: " + String(humidity) + "%");

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture: ");
  lcd.setCursor(0, 1);
  lcd.print(String(soilMoisture));

  if (soilMoisture > 650) {  
    digitalWrite(WATER_PUMP_PIN, HIGH);
    delay(1000);  
    digitalWrite(WATER_PUMP_PIN, LOW);
  }

  delay(2000);
}
