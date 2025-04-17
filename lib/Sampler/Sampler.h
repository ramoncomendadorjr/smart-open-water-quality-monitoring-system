#ifndef SAMPLER_H
#define SAMPLER_H

void initializePins();
void indicateSampling(bool on);
void fillChamber();
void flushChamber();
float readPHVoltage();
float readTurbidityVoltage();
bool analyzeSample(float ph, float turb);
void displaySamplingStatus(bool unsafe);

#endif
