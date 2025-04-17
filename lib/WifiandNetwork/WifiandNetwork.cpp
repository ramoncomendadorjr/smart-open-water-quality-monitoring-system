#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "WifiandNetwork.h"


void connectWifi(){
    WiFi.begin(SSID, password);
    Serial.print("Connecting to WiFi");
    while(WiFi.status() != WL_CONNECTED){
        delay(1000);
        Serial.print(".");
    }
    Serial.print(" Connected!");
}

void sendToServer(float phComputed, float turbComputed){
    if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String serverURL = "http://your-server-address/api/data"; // <-- Change this
    http.begin(serverURL);
    http.addHeader("Content-Type", "application/json");

    String payload = "{\"ph_voltage\":" + String(phComputed, 2) +
                     ",\"turbidity_voltage\":" + String(turbComputed, 2) + "}";

    int httpCode = http.POST(payload);

    if (httpCode > 0) {
      String response = http.getString();
      Serial.println("Server Response: " + response);
    } else {
      Serial.print("HTTP Error: ");
      Serial.println(httpCode);
    }

    http.end();
  }
}