#include <Arduino.h>
#include "config.h"
#include "Sampler.h"

void setup(){

    Serial.begin(115200);
    initializePins();
}

void loop(){

    indicateSampling(true);
    fillChamber();

    float pHComputed = readPHVoltage();
    float turbComputed = readTurbidityVoltage();
    
    Serial.print("pH: ");
    Serial.print(pHComputed);
    Serial.print(" | Turbidity: ");
    Serial.println(turbComputed);

    bool isUnsafe = analyzeSample(pHComputed, turbComputed);
    displaySamplingStatus(isUnsafe);

    flushChamber();

    indicateSampling(false);

    delay(delayBetweenCycles);

    // // fill chamber
    // digitalWrite(inletRelay, LOW);
    // delay(60000);                       // TODO: modify duration
    // digitalWrite(inletRelay, HIGH);     // relay OFF

    // // obtain pH and turbidity
    // int phRaw = analogRead(pH_pin);
    // int turbRaw = analogRead(turb_pin);

    // float phVoltage = phRaw * (3.3 / 4095);
    // float turbVoltage = turbRaw * (3.3 / 4095);     // TODO: modify due to voltage dividing

    // Serial.print("pH Voltage: "); Serial.print(phVoltage);
    // Serial.print(" | Turbidity Voltage: "); Serial.println(turbVoltage);

    // // Sample logic (simple thresholds — tune as needed)
    // bool isUnsafe = (phVoltage < 1.5 || phVoltage > 2.5) || (turbVoltage > 2.5);

    // digitalWrite(redLED, isUnsafe);
    // digitalWrite(greenLED, !isUnsafe);

    // // flush chamber
    // digitalWrite(outletRelay, LOW);
    // delay(60000);                        // TODO: modify duration
    // digitalWrite(outletRelay, HIGH);     // relay OFF

    // digitalWrite(whiteLED, LOW);

    // delay(300000);                       // TODO: modify cycle duration 

    // // LED trial setup
    // digitalWrite(whiteLED, HIGH);
    // delay(1000);
    // digitalWrite(redLED, HIGH);
    // delay(1000);
    // digitalWrite(greenLED, HIGH);
    // delay(1000);
    // digitalWrite(whiteLED, LOW);
    // delay(1000);
    // digitalWrite(redLED, LOW);
    // delay(1000);
    // digitalWrite(greenLED, LOW);
    // delay(1000);

    // // pH sensor trial setup
    // int phRaw = analogRead(pH_pin);
    // float phVoltage = phRaw * (3.3 / 4095);
    // Serial.print("pH Voltage: "); Serial.print(phVoltage);
    // delay(2000);

    // // turbidity sensor trial setup
    // int turbRaw = analogRead(turb_pin);
    // float turbVoltage = turbRaw * (3.3 / 4095);     // TODO: modify due to voltage dividing
    // Serial.print("Turbidity Voltage: "); Serial.println(turbVoltage);
    // delay(2000);

    // // inlet relay trial setup
    // digitalWrite(inletRelay, LOW);
    // delay(3000);                       // TODO: modify duration
    // digitalWrite(inletRelay, HIGH);     // relay OFF
    // delay(3000); 

    // // outlet relay trial setup
    // digitalWrite(outletRelay, LOW);
    // delay(3000);                       // TODO: modify duration
    // digitalWrite(outletRelay, HIGH);     // relay OFF
    // delay(3000); 

    // // two-pump trial setup
    // digitalWrite(inletRelay, LOW);
    // delay(3000);                       // TODO: modify duration
    // digitalWrite(inletRelay, HIGH);     // relay OFF
    // delay(3000); 
    // digitalWrite(outletRelay, LOW);
    // delay(3000);                       // TODO: modify duration
    // digitalWrite(outletRelay, HIGH);     // relay OFF
    // delay(3000); 

}