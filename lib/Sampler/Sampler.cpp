#include <Arduino.h>
#include "config.h"
#include "Sampler.h"

void initializePins(){
    pinMode(inletRelay, OUTPUT);
    pinMode(outletRelay, OUTPUT);
    pinMode(whiteLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);

    digitalWrite(inletRelay, HIGH);     // relay OFF (active LOW)
    digitalWrite(outletRelay, HIGH);    // relay OFF (active LOW)
}

void indicateSampling(bool on){
    digitalWrite(whiteLED, on ? HIGH : LOW);
}

void fillChamber(){
    digitalWrite(inletRelay, LOW);
    delay(fillDuration);                      // TODO: modify duration
    digitalWrite(inletRelay, HIGH);           // relay OFF
}

void flushChamber(){
    digitalWrite(outletRelay, LOW);
    delay(flushDuration);                     // TODO: modify duration
    digitalWrite(outletRelay, HIGH);          // relay OFF
}

float readPHVoltage(){
    int phRaw = analogRead(pH_pin);
    // float precomputedPH = insert formula after calibration here               
    return phRaw * (3.3 / 4095);
}

float readTurbidityVoltage(){
    int turbRaw = analogRead(turb_pin);
    return turbRaw * (3.3 / 4095) * (3 / 2);
}

bool analyzeSample(float ph, float turb){
    return (ph < 1.5 || ph > 2.5) || (turb > 2.5);      // TODO: modify ranges
}

void displaySamplingStatus(bool unsafe){
    digitalWrite(redLED, unsafe);
    digitalWrite(greenLED, !unsafe);
}