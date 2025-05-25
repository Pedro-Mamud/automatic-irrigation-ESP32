#ifndef _INCLUDE_SOIL_MOISTURE_
#define _INCLUDE_SOIL_MOISTURE_

#include <Arduino.h>

#define SOIL_SENSOR_PIN_DEVKIT 4 // D4
#define SOIL_SENSOR_PIN_C3 0
#define THRESHOLD 2000 // @TODO Change this during calibration

int sensorValue = 0;


int ReadMoisture() {

  long average = 0;
  for(int i = 0; i <= 10; i++){
    average += sensorValue = analogRead(SOIL_SENSOR_PIN_C3);
    delay(10);
  }
  
  sensorValue = average/10;

  // valores de calibração
  int wet_value = 1300;
  int dry_value = 4095;

  // garantir que o valor esteja dentro dos limites
  sensorValue = constrain(sensorValue, wet_value, dry_value);

  // converter para porcentagem (0% seco, 100% molhado)
  int umidade_percentual = map(sensorValue, wet_value, dry_value, 100, 0);
  Serial.print("UMILDADE DO SOLO: ");
  Serial.print(umidade_percentual);
  Serial.println("%");

  delay(500);
  
  return sensorValue;
}

#endif //_INCLUDE_TEMP_HUMIDITY_SENSOR_