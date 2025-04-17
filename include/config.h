#ifndef CONFIG_H
#define CONFIG_H

const int pH_pin = 36;      // pH sensor pin number
const int turb_pin = 39;    // turbidity sensor pin number

const int inletRelay = 18;  // inlet relay pin number
const int outletRelay = 19; // outlet relay pin number

const int whiteLED = 25;    // white led pin number
const int redLED = 26;      // red led pin number
const int greenLED = 27;    // green led pin number

const int fillDuration = 60000;
const int flushDuration = 60000;
const int delayBetweenCycles = 300000;

#endif