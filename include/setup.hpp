#ifndef _INCLUDE_SETUP
#define _INCLUDE_SETUP

#include <Arduino.h>
#include "TempHumiditySensor.hpp"
#include "SoilMoisture.hpp"
#include "pumpWater.hpp"
#include "wifi.hpp"
#include "display.hpp"

// void taskHandlePump(void *pvParameters);
// void taskReadTempHumidity(void *pvParameters);

void set_up() {

  //wifiConnect();


  displayConfig();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ahla wa sahla!");
  lcd.setCursor(0,1);
  lcd.print("Salaamu aleikum");
  delay(5000);

  pinMode(PUMP_PIN_C3, OUTPUT);
  digitalWrite(PUMP_PIN_C3, HIGH);

  dht.setup(DHT_PIN_C3, DHTesp::DHT11); 
  analogSetAttenuation(ADC_11db);

  // // Criação das tasks
  // xTaskCreatePinnedToCore(
  //   taskHandlePump,         // função
  //   "Pump Control Task",    // nome
  //   2048,                   // stack size
  //   NULL,                   // parâmetros
  //   1,                      // prioridade
  //   NULL,                   // task handle
  //   1                       // core (0 ou 1)
  // );

  // xTaskCreatePinnedToCore(
  //   taskReadTempHumidity,
  //   "Temp & Humidity Task",
  //   2048,
  //   NULL,
  //   1,
  //   NULL,
  //   1
  // );
}

#endif // _INCLUDE_SETUP