/*
Evan Petratos <ep9407@bard.edu>
12.17.2018
CMSC 226
Final Project
I worked alone on this project.
*/

#include <wiringPi.h> //C Library function used with RaspberryPi and GPIO
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>

//the LedPin number depends on the GPIO pegs used by the RaspberryPi
#define LedPinDot 0
#define LedPinDash 4

/* when using the command line, this variable will be used 
to cap the maximum length of the user-input */
#define MAX_CMD_LEN 20

//defines the fundamentals of morse code
#define Dash "-"
#define Dot "."


/* An addition between the presentation and now is 
the concept of using one led to blink when a dot is entered, 
and the other to blink when a dash is entered */
static void * dot(void) {
	pinMode(LedPinDot, OUTPUT);
	digitalWrite(LedPinDot, HIGH); //turn Led on
	delay(300); //led stays on 300 milliseconds
	digitalWrite(LedPinDot, LOW); //turn led off
	delay(300); //led stays off 300 milliseconds
}

static void * dash(void) {
	pinMode(LedPinDash, OUTPUT);
	digitalWrite(LedPinDash, HIGH); //turn led on
	delay(900); //led stays on 900 milliseconds
	digitalWrite(LedPinDash, LOW); //turn led off
	delay(300); //led stays off 300 milliseconds
}

int main(int argc, char *argv[]) {
		if(wiringPiSetup() == -1) {
			printf("wiringPi setup failed\n"); //prints fail statement
			return -1;
		}
		
		char cmdline[MAX_CMD_LEN]; //character array that will be used as standard input
		while(1) {
			pthread_t dashCodet, dotCodet; //threads for dot and dash
			int s;
			fgets(cmdline, MAX_CMD_LEN, stdin); //takes standard input from the user as a character array called cmdline

			if (cmdline == NULL || cmdline == "\n") continue; //keeps the loop going if nothing significant is entered
			if (strcmp(cmdline, "-\n") == 0) {
				printf("%s\n", Dash); //prints "-"
				s = pthread_create(&dashCodet, NULL, dashCode, NULL); //creates pthread for dash that illuminates dash led
				s = pthread_join(dashCodet, NULL);
			}
			if (strcmp(cmdline, ".\n") == 0) {
				printf("%s\n", Dot); //prints "."
				s = pthread_create(&dotCodet, NULL, dotCode, NULL); //creates pthread for dot that illuminates dot led
				s = pthread_join(dotCodet, NULL);
			}
			if (strcmp(cmdline, "exit\n") == 0) break; //type exit to end the program
		}
		return 0;
}
