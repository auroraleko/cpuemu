#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ascii/title.h"
#include "funclib.h"
#define CLEAR system("clear")

Byte bus_storage[64];
typedef void (*cmdFunc)();
typedef int (*cmdintReturn)();
typedef struct {
	char *name;
	cmdFunc func;
	const char *desc;
} Map;

Map funcMap[] = {
	{"LOAD", _LOAD, "Loads a value from an address."},
	{"STORE", _STORE, "Stores a value into an address."},
	{"MATH", _MATH, "Performs mathematical operations on any 2 values."},
	{"CLOCK", _CLOCK, "Shows time and date."},
	{"EXIT", _EXIT, "seriously? you don't know what this does??"},
	{"HELP", _HELP, "self-explanatory, again..."},
	{"PRINT_BUS", _PRINT_BUS, "prints the entire bus."},
	{"\0", NULL, "\0"}
};

int funcSize = sizeof(funcMap)/sizeof(funcMap[0].name);

void _HELP() {
	printf("LIST OF POSSIBLE COMMANDS:\n");
	int i=0;
	while (i<funcSize) {
		printf("\n     %s : %s", funcMap[i].name, funcMap[i].desc);
		i++;
	} printf("\n");
}

char user[64];
void shell() {
	CLEAR;char input[64];
	printf("%s\n\ncpuOS ALPHA v0.0.1\n", title);
	printf("Please enter your name: ");scanf("%s", &user);
	while (1) {
		printf("\n%s%% ", user);scanf("%s", &input);
		int i=0;
		while (i<funcSize) {
			if (i>funcSize) {
				i=0;break;
			} if (strcmp(input, funcMap[i].name) == 0) {
				funcMap[i].func();break;
			} else {
				i++;
			}
		}
	}
}

int main() {
	int i=0;
	while (i<65) {
		bus_storage[i].loc = i;
		i++;
	} shell();
	return 0;
}
