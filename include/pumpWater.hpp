#ifndef _INCLUDE_PUMP_WATER
#define _INCLUDE_PUMP_WATER

#include "SoilMoisture.hpp"

#define PUMP_PIN 23 // PARA O DEVKIT

void handlePump() {
    // Lógica para ligar/desligar a bomba
    ReadMoisture();
    
    if (sensorValue <= THRESHOLD) {
        digitalWrite(PUMP_PIN, HIGH); 
        Serial.println("Solo seco → Bomba Desligada.");

    } else if (sensorValue >= THRESHOLD) {
        digitalWrite(PUMP_PIN, LOW);  
        Serial.println("Solo molhado → Ativando a bomba.");
    }
}


#endif // _INCLUDE_PUMP_WATER