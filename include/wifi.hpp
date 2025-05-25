#ifndef _WIFI_HPP_
#define _WIFI_HPP_

#include <WiFi.h>
#include <WebServer.h>
#include "setup.hpp"

const char* ssid = "APARTAMENTOS";
const char* password = "pousada9988";

// Conecta no Wi-Fi
void wifiConnect() {
    WiFi.begin(ssid, password);
    Serial.println("Conectando ao WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(200);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("Conectado ao WiFi!");
    Serial.println("IP: " + WiFi.localIP().toString());
   
}

#endif // _WIFI_HPP_