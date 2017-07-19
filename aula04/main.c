#include <stdio.h>
#include "aula04.h"

Device dev;
Version ver = {MAJOR, MINOR, BUILD};

extern uint8_t maxSignal;

int main() {
    printVersion(&ver);
    deviceSetMaxSignal(20);
    maxSignal = 10;
    deviceCreate(&dev, 45, 50);
    printf("Device battery %d,  signal %d\n", dev.battery, dev.signal);

    return 0;
}
