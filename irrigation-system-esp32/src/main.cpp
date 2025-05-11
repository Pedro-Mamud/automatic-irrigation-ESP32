#include <Arduino.h>
#include "TempHumiditySensor.hpp"
#include "SoilMoisture.hpp"


void setup() {
  Serial.begin(9600);
  delay(1000);  // Aguarda inicialização da serial

  analogSetAttenuation(ADC_11db);  // set the ADC attenuation to 11 dB (up to ~3.3V input
}

void loop() {
  ReadMoisture();


}
