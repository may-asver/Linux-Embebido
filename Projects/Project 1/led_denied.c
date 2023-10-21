/*
	Script to turn on green LED on voicehat card (PICO-PI-IMX8).

	Authors:
	Jonathan Lopez
	Maya Aguirre

	Date: 20/10/2023
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define FILENAME "/sys/class/leds/pca995x:red1/brightness" // File to change brightness
#define BRIGHTNESS "100"
#define TIME 3 // 10 miliseconds


void writeFile (char * brightness) {
	FILE *file = fopen(FILENAME, "w");
	if (file == NULL) {
	   perror("Error opening file");
	}
	fputs(brightness, file);
	fclose(file);
	fflush(file);
}

int main () {
    	// Turn on
    	writeFile(BRIGHTNESS);
    	sleep(TIME);
    	// Turn off
    	writeFile("0");
    return 0;
}

