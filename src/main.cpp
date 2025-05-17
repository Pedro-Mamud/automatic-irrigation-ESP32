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


#include <Arduino.h>
#include "TempHumiditySensor.hpp"
#include "SoilMoisture.hpp"
#include "pumpWater.hpp"

//DHTesp dht;

void setup() {
  Serial.begin(9600);
  delay(1000);  // Aguarda inicialização da serial

  // Pump water
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, HIGH);  // Bomba desligada inicialmente

  // DHT11 Sensor
  dht.setup(DHT_PIN, DHTesp::DHT11); //initial setup for DHT11

  // Moisture Sensor
  analogSetAttenuation(ADC_11db);  // set the ADC attenuation to 11 dB (up to ~3.3V input
}

void loop() {
  handlePump(); // handling the pump
  delay(2000);
  ReadTemperature(); // read enviroment temperature
  ReadHumidity(); // read enviroment Humidity
  
}


