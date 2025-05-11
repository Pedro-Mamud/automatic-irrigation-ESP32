#ifndef _INCLUDE_SOIL_MOISTURE_
#define _INCLUDE_SOIL_MOISTURE_

#include <Arduino.h>

#define SOIL_SENSOR_PIN 3 
#define THRESHOLD 123 // @TODO Change this during calibration

#define DRY_THRESHOLD 3500
#define WET_THRESHOLD 1200


int percent = 0;

int ReadMoisture() {
  int sensorValue = analogRead(SOIL_SENSOR_PIN);  // Lê valor de 0 a 4095 no ESP32
  
  if (sensorValue > THRESHOLD) {
    Serial.println("solo está molhado");
  } else {
    Serial.println("solo sec");
  }
  // ideal seria 4095 = seco e 0 = molhado, But, devemos calibrar o sistema

  percent = map(sensorValue, DRY_THRESHOLD, WET_THRESHOLD, 0, 100);
  percent = constrain(percent, 0, 100);  // Garante que fique entre 0 e 100

  delay(1000);
  
  return percent;
}



#endif //_INCLUDE_TEMP_HUMIDITY_SENSOR_