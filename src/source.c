#include <stdio.h>
#include <stdlib.h>
#include "../ascii/title.h"
#include <uthash.h>
#define CLEAR system("clear")

typedef void (*cmdFunc)();

typedef struct {
	int val;
	int loc;
} Byte; Byte bus;

typedef struct {
	char name;
	cmdFunc func;
	UT_hash_handle hh;
} Map;

// func list;
int _LOAD() {
	int i, input;
	printf("\nADDRESS: ");scanf("%d", &input);
	i=0;
	while (i<64) {
		if (bus[i].loc == input) {
			return bus[i].val;puts("");
		} else {
			i++;
		}
	}
}

void _STORE() {
	int input_val, input_loc;
	printf("VALUE: ");scanf("%d", &input_val);
	printf("WHERE TO STORE: ");scanf("%d", &input_loc);
}
// func end list;

Map funcMap[] = {
	{"LOAD", _LOAD},
	{"STORE", _STORE},
	{"MATH", _MATH},
	{"CLOCK", _CLOCK},
	{"EXIT", _EXIT},
	{"HELP", _HELP},
	{"\0", NULL}
};

char user[64]
void shell() {
	char input[64];
	printf("%s\n\nCPUemu ALPHA v0.0.1\n", title);
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
