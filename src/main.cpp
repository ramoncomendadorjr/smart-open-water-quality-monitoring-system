#include <Arduino.h>


void setup(){
    Serial.begin(115200);
    Serial.println("Hello from setup");
}

void loop(){
    delay(1000);
    Serial.println("Hello from loop");
}