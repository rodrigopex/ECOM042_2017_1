#include "aula04.h"

static uint8_t maxSignal;

void deviceSetMaxSignal(uint8_t max) {
    maxSignal = max;
}

void deviceCreate(Device *dev, uint8_t battery, uint8_t signal) {
    dev->battery = (battery > 100? 100 : battery);
    dev->signal = (signal > maxSignal? maxSignal: signal);
}

void printVersion(Version *v) {
    printf("Version %d.%d.%d\n", v->major, v->minor, v->build);
}

Device *deviceCreateP(uint8_t battery, uint8_t signal) {
    Device dev = {.battery=battery, .signal=signal};
    return &dev;
}


