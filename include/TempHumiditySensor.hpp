#ifndef _INCLUDE_TEMP_HUMIDITY_SENSOR_
#define _INCLUDE_TEMP_HUMIDITY_SENSOR_

#include <DHTesp.h>
#include "display.hpp"
// consedering that we will use DHT11
DHTesp dht;


#define DHT_PIN_ESP32 5
#define DHT_PIN_C3 1

void ReadHumidity() { 
    float humidity = dht.getHumidity();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Umidade: ");
    lcd.print(humidity);
    lcd.print("%");
    delay(1000);
    Serial.print("Umidade: ");
    Serial.print(humidity);
    Serial.println(" %");
    delay(2000);
}

void ReadTemperature() {
    float temp = dht.getTemperature();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("temperature: ");
    lcd.print(temp);
    lcd.print(" °C");
    delay(1000);
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" °C");
    delay(2000);
}

float temperature = 0.0;
float humidity = 0.0;

void tempAndHumidity() {
    
    TempAndHumidity data = dht.getTempAndHumidity();
    temperature = data.temperature;
    humidity = data.humidity;

    if (isnan(data.temperature) || isnan(data.humidity)) {
        Serial.println("Falha ao ler do sensor DHT!");
    } else {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Temp. ambiente: ");
        lcd.setCursor(0,1);
        lcd.print(temperature);
        lcd.print((char)223);
        lcd.print("C");
        delay(2000);


        // Serial.print("Temperatura: ");
        // Serial.print(temperature);
        // Serial.println(" °C");

        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Umidade do ar: ");
        lcd.setCursor(0,1);
        lcd.print(humidity);
        lcd.print("%");
        delay(2000);

        // Serial.print("Umidade: ");
        // Serial.print(humidity);
        // Serial.println(" %");
    }

    delay(2000);
}

#endif //_INCLUDE_TEMP_HUMIDITY_SENSOR_