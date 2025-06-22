#ifndef _INCLUDE_PUMP_WATER
#define _INCLUDE_PUMP_WATER

#include "SoilMoisture.hpp"
#include "display.hpp"

#define PUMP_PIN_DEVKIT 23 // PARA O ESP32DEVKIT
#define PUMP_PIN_C3 2  //ESP32 C3 SUPERMINI

void handlePump() {
    ReadMoisture();
    
    if (sensorValue <= THRESHOLD) {
        digitalWrite(PUMP_PIN_C3, HIGH);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Bomba desligada");
        delay(1000);
        //Serial.println("Solo seco → Bomba Desligada.");

    } else if (sensorValue >= THRESHOLD) {
        digitalWrite(PUMP_PIN_C3, LOW);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Ativando a bomba");
        lcd.setCursor(0,1);
        lcd.print("tung tung tung");
        delay(1000);  
        //Serial.println("Solo molhado → Ativando a bomba.");
    }
}


#endif // _INCLUDE_PUMP_WATER