#ifndef _INCLUDE_SOIL_MOISTURE_
#define _INCLUDE_SOIL_MOISTURE_

#include <Arduino.h>

#define SOIL_SENSOR_PIN 3 
#define THRESHOLD 123 // @TODO Change this during calibration

int ReadMoisture() {
  int sensorValue = analogRead(SOIL_SENSOR_PIN);  // Lê valor de 0 a 4095 no ESP32
  
  if (sensorValue > THRESHOLD) {
    Serial.println("solo está molhado");
  } else {
    Serial.println("solo sec");
  }
  // ideal seria 4095 = seco e 0 = molhado, But, devemos calibrar o sistema

  
  // Ajustar os valores com base na calibração real do sensor:
  int dryValue = 3500;     // Valor típico para solo seco (ex: no ar)
  int wetValue = 1200;     // Valor típico para solo muito molhado

  int percent = map(sensorValue, dryValue, wetValue, 0, 100);
  percent = constrain(percent, 0, 100);  // Garante que fique entre 0 e 100

  delay(1000);
  
  return percent;
}



#endif //_INCLUDE_TEMP_HUMIDITY_SENSOR_