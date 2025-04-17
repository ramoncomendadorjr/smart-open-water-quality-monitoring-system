#ifndef WIFIANDNETWORK_H
#define WIFIANDNETWORK_H

const char* SSID = "your_wifi";
const char* password = "password";


void connectWifi();
void sendToServer(float pHComputed, float turbComputed);

#endif