#include "aula04.h"

void printVersion(Version *v) {
    printf("Version %d.%d.%d\n", v->major, v->minor, v->build);
}

void deviceCreate(Device *dev, uint8_t battery, uint8_t signal) {
    if(battery > 100)
        dev->battery = 100;
    else
        dev->battery = battery;
    dev->signal = signal;
}
