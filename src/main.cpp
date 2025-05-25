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

void loop() {}

// ===================== TASKS ========================

void taskHandlePump(void *pvParameters) {
  while (true) {
    handlePump(); 
  }
}

void taskReadTempHumidity(void *pvParameters) {
  while (true) {
    tempAndHumidity();  
    vTaskDelay(pdMS_TO_TICKS(2000)); // Espera 2s antes de próxima leitura
  }
}
