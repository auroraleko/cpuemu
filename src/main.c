// cpuOS Copyright 2025 Aurora Leko
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ascii/title.h"
#include "funclib.h"
#define CLEAR system("clear")

Byte bus_storage[64];
typedef void (*cmdFunc)();
typedef struct {
	char *name;
	cmdFunc func;
	const char *desc;
} Map;

Map funcMap[] = {
	{"LOAD", _LOAD, "Loads a value from an address."},
	{"STORE", _STORE, "Stores a value into an address."},
	{"MATH", _MATH, "Performs arithmetic operations on any 2 values."},
	{"CLOCK", _CLOCK, "Shows time and date."},
	{"EXIT", _EXIT, "seriously? you don't know what this does??"},
	{"HELP", _HELP, "self-explanatory, again..."},
	{"PRINT_BUS", _PRINT_BUS, "prints the entire bus."},
	{"\0", NULL, "\0"}
};

size_t funcSize = sizeof(funcMap)/sizeof(funcMap[0]);

void _HELP() {
	printf("LIST OF POSSIBLE COMMANDS:\n");
	int i=0;
	while (i<funcSize) {
		printf("\n     %s : %s", funcMap[i].name, funcMap[i].desc);
		i++;
	}
	printf("\n");
}

char user[64];
void shell() {
	CLEAR;char args[64];
	printf("%s\n\ncpuOS ALPHA v0.0.1 2025 Copyright Aurora Leko\n", title);
	printf("Please enter your name: ");scanf("%s", &user);
	if (strcmp(user, "debugpls") == 0) {
		system("gcc -fsanitize=address -g ./src/main.c ./src/helper.c -o cpuemu.os;echo \"Debug Mode Activated.\"");system("sleep 1;./cpuemu.os");
	}
	while (1) {
		printf("\n%s%% ", user);scanf("%s", &args);
		int i=0;
		while (i<funcSize) {
			if (strcmp(args, funcMap[i].name) == 0) {
				funcMap[i].func();
				break;
			}
			i++;	
		}
	}
}

int main() {
	int i=0;
	while (i<64) {
		bus_storage[i].loc = i;
		i++;
	} shell();
	return 0;
}
