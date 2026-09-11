
// Required libraries
//#include <Arduino.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Fonts/FreeMono12pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>

#define OLED_RESET -1 
#define SCREEN_ADDRESS 0x3C 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Create: Center Text
byte hori, verti;
int16_t x, y;
uint16_t w, h;


// Main Function *************************************
void setup() {
  Serial.begin(9600);

  delay(500);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("failed to start SSD1306 OLED"));
    while(1);
  }

  // Adafruit Logo
  oled.display();

  delay(2000);

  // clear
  oled.clearDisplay();

  // Output: Text
  oled.setTextSize(1.5);
  //oled.setFont(&FreeMono12pt7b);
  oled.setTextColor(WHITE);

  oled.getTextBounds("HELLO", 0, 0, &x, &y, &w, &h);
  hori = (SCREEN_WIDTH - w)/2;
  
  oled.setCursor(hori, 10);
  //oled.setTextWrap(true);
  oled.println("HELLO");
  oled.display();

  delay(500);

  // Output: Text
  oled.setFont(&FreeSansBold9pt7b);
  oled.setTextSize(1);

  oled.getTextBounds("MYCROMARS", 0, 0, &x, &y, &w, &h);
  hori = (SCREEN_WIDTH - w)/2;
  verti = (SCREEN_HEIGHT - h)/2;
  
  oled.setCursor(hori, verti+15);
  //oled.setTextWrap(true);
  oled.println("MYCROMARS");
  oled.display();


 

}

void loop() {
  

}