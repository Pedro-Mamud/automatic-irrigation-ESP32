#ifndef _INCLUDE_PUMP_WATER
#define _INCLUDE_PUMP_WATER
#include "SoilMoisture.hpp"

#define PUMP_PIN 1

void handlePump() {
    // Lógica para ligar/desligar a bomba
    ReadMoisture();
    
    if (percent <= DRY_THRESHOLD) {
        digitalWrite(PUMP_PIN, HIGH);  // Liga bomba
        Serial.println("Solo seco → Ligando bomba...");

    } else if (percent >= WET_THRESHOLD) {
        digitalWrite(PUMP_PIN, LOW);   // Desliga bomba
        Serial.println("Solo molhado → Desligando bomba.");
    }
}


#endif // _INCLUDE_PUMP_WATER