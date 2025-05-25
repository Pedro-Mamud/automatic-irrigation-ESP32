#ifndef _INCLUDE_TEMP_HUMIDITY_SENSOR_
#define _INCLUDE_TEMP_HUMIDITY_SENSOR_

#include <DHTesp.h>
// consedering that we will use DHT11
DHTesp dht;


#define DHT_PIN_ESP32 5
#define DHT_PIN_C3 1

void ReadHumidity() { 
    float humidity = dht.getHumidity();
    Serial.print("Umidade: ");
    Serial.print(humidity);
    Serial.println(" %");
    delay(2000);
}

void ReadTemperature() {
    float temp = dht.getTemperature();
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
        Serial.print("Temperatura: ");
        Serial.print(temperature);
        Serial.println(" °C");

        Serial.print("Umidade: ");
        Serial.print(humidity);
        Serial.println(" %");
    }

    delay(2000);
}


//LIB CODE HERE



#endif //_INCLUDE_TEMP_HUMIDITY_SENSOR_