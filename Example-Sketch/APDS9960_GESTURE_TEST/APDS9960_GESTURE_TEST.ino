/*
 * OBJEX-IOT.TECH
 * SKETCH FOR ORB1T V19.0 ALPHA
 */
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  // Display Addr 
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  // Clear the buffer
  display.clearDisplay();
  display.display();

  // APDS9960 Init
  if(!apds.begin()){
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");

  //Gesture mode will be entered once proximity mode senses something close
  apds.enableProximity(true);
  apds.enableGesture(true);
}

void loop() {
  // Read gesture from ORB1T V19.0
  uint8_t gesture = apds.readGesture();
  
    if(gesture == APDS9960_DOWN){
      Serial.println("v");
      display.clearDisplay();
      display.setTextSize(1);             
      display.setTextColor(WHITE);        
      display.setCursor(0,20);             
      display.println("V - DOWN");
      display.display();
    }
    if(gesture == APDS9960_UP){
      Serial.println("^");
      display.clearDisplay();
      display.setTextSize(1);             
      display.setTextColor(WHITE);        
      display.setCursor(0,20);             
      display.println("^ - UP");
      display.display();
    }
    if(gesture == APDS9960_LEFT){
      Serial.println("<");
      display.clearDisplay();
      display.setTextSize(1);             
      display.setTextColor(WHITE);        
      display.setCursor(0,20);             
      display.println("< - LEFT");
      display.display();
    }
    if(gesture == APDS9960_RIGHT){
      Serial.println(">");
      display.clearDisplay();
      display.setTextSize(1);             
      display.setTextColor(WHITE);        
      display.setCursor(0,20);             
      display.println("> - RIGHT");
      display.display();
    }
}
