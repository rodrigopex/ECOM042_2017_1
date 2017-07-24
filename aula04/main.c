#include <stdio.h>
#include "aula04.h"

Device dev;
Version ver = {MAJOR, MINOR, BUILD};

#define new_DeviceCreate(battery, signal) {(battery > 100? 100 : battery), signal}
#ifdef DEBUG
#define LOG(subSys, level, msg) printf("*** LOG: %s:%d(%s) %s -> %s, %s, %s\n", __FILE__, __LINE__, __FUNCTION__, __TIMESTAMP__, #subSys, #level, msg)
#else
#define LOG(subSys, level, msg)
#endif

int main() {
    Device dev = new_DeviceCreate(25, 80);
    printVersion(&ver);
    deviceSetMaxSignal(20);
    LOG(COMM, INFO, "PASSEI AQUI!");
    printf("Device battery %d,  signal %d\n", dev.battery, dev.signal);
    return 0;
}
