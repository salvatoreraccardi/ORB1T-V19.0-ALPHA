/*
 * OBJEX-IOT.TECH
 * SKETCH FOR ORB1T V19.0 ALPHA
 */
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Set these to run example.
#define FIREBASE_HOST "objex-6da35.firebaseio.com"
#define FIREBASE_AUTH "Tv5qXnNZmq9fPoiMLnMdJSiyuziGIZa2aVN0PU1F"
#define WIFI_SSID "Raccardi"
#define WIFI_PASSWORD "raccardi2016"

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C

String temperature, humidity, pressure, altitude;

void conn(){
 // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void setup() {
  Serial.begin(9600);
  Serial.println(F("BME280 test"));

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  conn();
  
  // Wait calibration
  delay(500);
}

void loop() {

    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");
    temperature = String(bme.readTemperature()) + " *C";
    Firebase.setString("/Objects/01/API/Temperature", temperature);


    Serial.print("Pressure = ");
    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");
    pressure = String(bme.readPressure() / 100.0F) + " hPa";
    Firebase.setString("/Objects/01/API/Pressure", pressure);


    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");
    altitude = String(bme.readAltitude(SEALEVELPRESSURE_HPA)) + " m";
    Firebase.setString("/Objects/01/API/Altitude", altitude);


    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");
    humidity = String(bme.readHumidity()) + " %";
    Firebase.setString("/Objects/01/API/Humidity", humidity);


    Serial.println();
    delay(2000);
}
