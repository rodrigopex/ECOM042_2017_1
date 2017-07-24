#ifndef AULA04_H
#define AULA04_H
#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t major;
    uint8_t minor;
    uint16_t build;
} Version;

typedef struct {
    uint8_t battery;
    uint8_t signal;
} Device;

void printVersion(Version *v);
void deviceCreate(Device *dev, uint8_t battery, uint8_t signal);
Device *deviceCreateP(uint8_t battery, uint8_t signal);
void deviceSetMaxSignal(uint8_t max);

#endif //AULA04_H
