#ifndef _INCLUDE_TEMP_HUMIDITY_SENSOR_
#define _INCLUDE_TEMP_HUMIDITY_SENSOR_

#include <DHTesp.h>
// consedering that we will use DHT11

#define DHT_PIN 2

void ReadHumidity() { 
    float humidity = dht.getHumidity();
    Serial.print("Umidade: ");
    Serial.print(humidity);
    Serial.println(" %");
    delay(1000);
}

void ReadTemperature() {
    float temp = dht.getTemperature();
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" °C");
    delay(1000);
}

void tempAndHumidity() {
    
    TempAndHumidity data = dht.getTempAndHumidity();

    if (isnan(data.temperature) || isnan(data.humidity)) {
        Serial.println("Falha ao ler do sensor DHT!");
    } else {
        Serial.print("Temperatura: ");
        Serial.print(data.temperature);
        Serial.println(" °C");

        Serial.print("Umidade: ");
        Serial.print(data.humidity);
        Serial.println(" %");
    }

    delay(2000);
}


//LIB CODE HERE



#endif //_INCLUDE_TEMP_HUMIDITY_SENSOR_