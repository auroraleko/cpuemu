#include <stdio.h>
#include <stdlib.h>
#include "../ascii/title.h"
#include "helper.h"
#define CLEAR system("clear")

typedef void (*cmdFunc)();
typedef struct {
	char name;
	cmdFunc func;
	const char *desc;
} Map;

Map funcMap[] = {
	{"LOAD", _LOAD, ":  Loads a value from an address."},
	{"STORE", _STORE, ":  Stores a value into an address."},
	{"MATH", _MATH, ":  Performs mathematical operations on any 2 values."},
	{"CLOCK", _CLOCK, ":  Shows time and date."},
	{"EXIT", _EXIT, ":  seriously? you don't know what this does??"},
	{"HELP", _HELP, ":  self-explanatory, again..."},
	{"\0", NULL, "\0"}
};

void _HELP() {
	printf("LIST OF POSSIBLE COMMANDS:\n");
	int i=0;
	while (i<sizeof(funcMap)/sizeof(funcMap[0])) {
		printf("\n%s%s", funcMap[i].name, funcMap[i].desc);
		i++;
	} printf("\n");
}

char user[64];
void shell() {
	char input[64];
	printf("%s\n\ncpuOS ALPHA v0.0.1\n", title);
	printf("Please enter your name: ");scanf("%s", &user);
	while (1) {
		printf("%s %% ", user);scanf("%s", &input);
		int i=0;
		while (i<6) {
			if (input == funcMap[i].name) {
				funcMap[i].func();break;
			} else {
				i++;
			}
		}
	}
}
