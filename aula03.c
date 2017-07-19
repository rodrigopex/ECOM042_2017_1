#include <stdio.h>
#include <stdint.h>


typedef struct {
    uint8_t major;
    uint8_t minor;
    uint16_t build;
} Version;

void printVersion(Version *v) {
    printf("Version %d.%d.%d\n", v->major, v->minor, v->build);
}

int main() {
    Version v = {MAJOR, MINOR, BUILD};
    printVersion(&v);

    return 0;
}

