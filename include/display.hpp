#ifndef _INCLUDE_DISPLAY
#define _INCLUDE_DISPLAY

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA_PIN 8
#define SCL_PIN 9
#define lcdColumns 16
#define lcdRows 2

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void displayConfig() {
  Wire.begin(SDA_PIN, SCL_PIN);
  lcd.init();                 
  lcd.backlight();
}


#endif