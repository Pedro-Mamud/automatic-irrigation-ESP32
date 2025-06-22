/**
 * Project: Automatic Irrigation System with Enviroment Monitoring
 *
 * Description:  
 * This program reads soil moisture and automatically triggers a water pump
 * if the soil is dry. It also monitors the ambient temperature and humidity 
 * using DHT11 sensor.
 *
 * Author: Pedro Henrique Silveira Abdala Mamud
 * Date: 10/05/2025
 */

#include "setup.hpp"

void setup() {
  Serial.begin(9600);
  delay(1000); 

  set_up();
}

void loop() {

  handlePump();
  delay(1500);
  TempAndHumidity();


// ===================== TASKS ========================

// void taskHandlePump(void *pvParameters) {
//   while (true) {
//     handlePump(); 
//   }
// }

// void taskReadTempHumidity(void *pvParameters) {
//   while (true) {
//     tempAndHumidity();  
//     vTaskDelay(pdMS_TO_TICKS(2000)); // Espera 2s antes de próxima leitura
//   }
  }

// /*********
//   Rui Santos
//   Complete project details at https://randomnerdtutorials.com  
// *********/

// #include <LiquidCrystal_I2C.h>
// #include <Wire.h>

// #define SDA_PIN 8
// #define SCL_PIN 9

// // set the LCD number of columns and rows
// int lcdColumns = 16;
// int lcdRows = 2;

// // set LCD address, number of columns and rows
// // if you don't know your display address, run an I2C scanner sketch
// LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

// void setup(){
//   Wire.begin(SDA_PIN, SCL_PIN);
//   // initialize LCD
//   lcd.init();
//   // turn on LCD backlight                      
//   lcd.backlight();
// }

// void loop(){
//   // set cursor to first column, first row
//   lcd.setCursor(0, 0);
//   // print message
//   lcd.print("Hello, World!");
//   delay(1000);
//   // clears the display to print new message
//   lcd.clear();
//   // set cursor to first column, second row
//   lcd.setCursor(0,1);
//   lcd.print("Hello, World!");
//   delay(1000);
//   lcd.clear(); 
// }