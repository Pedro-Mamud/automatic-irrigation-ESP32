#ifndef _INCLUDE_PUMP_WATER
#define _INCLUDE_PUMP_WATER

#include "SoilMoisture.hpp"

#define PUMP_PIN_DEVKIT 23 // PARA O ESP32DEVKIT
#define PUMP_PIN_C3 2  //ESP32 C3 SUPERMINI

void handlePump() {
    ReadMoisture();
    
    if (sensorValue <= THRESHOLD) {
        digitalWrite(PUMP_PIN_C3, HIGH); 
        Serial.println("Solo seco → Bomba Desligada.");

    } else if (sensorValue >= THRESHOLD) {
        digitalWrite(PUMP_PIN_C3, LOW);  
        Serial.println("Solo molhado → Ativando a bomba.");
    }
}


#endif // _INCLUDE_PUMP_WATER