#include <Arduino.h>


const int pH_pin = 36;      // pH sensor pin number
const int turb_pin = 39;    // turbidity sensor pin number

const int inletRelay = 18;  // inlet relay pin number
const int outletRelay = 19; // outlet relay pin number

const int whiteLED = 25;    // white led pin number
const int redLED = 26;      // red led pin number
const int greenLED = 27;    // green led pin number

void setup(){

    Serial.begin(115200);

    pinMode(inletRelay, OUTPUT);
    pinMode(outletRelay, OUTPUT);
    pinMode(whiteLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);

    digitalWrite(inletRelay, HIGH);     // relay OFF (active LOW)
    digitalWrite(outletRelay, HIGH);    // relay OFF (active LOW)
}

void loop(){
    
    // // inidicate sampling
    // digitalWrite(whiteLED, HIGH);

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