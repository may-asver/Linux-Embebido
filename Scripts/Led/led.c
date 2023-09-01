#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
   while(1) {
        int randomData = open("/dev/urandom", O_RDONLY);
        if (randomData < 0) {
            printf("Error al abrir el archivo /dev/urandom");
            exit(1);
        }
        char myRandomData;
        ssize_t result = read(randomData, &myRandomData, sizeof myRandomData);
        if (result < 0) {
            printf("Error al leer el archivo /dev/urandom");
            exit(1);
        }
        close(randomData);

        FILE *outputFile = fopen("/sys/class/leds/gpio-led/brightness", "w");
        if (outputFile == NULL) {
            printf("Error al abrir el archivo /sys/class/leds/gpio-led/brightness");
            exit(1);
        }
        if (myRandomData > 128) {
            fputs("1", outputFile);
        } else {
            fputs("0", outputFile);
        }
        fclose(outputFile);
        fflush(outputFile);
        sleep(1);
    }
    return 0;
}

