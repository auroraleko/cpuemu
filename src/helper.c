#include <stdio.h>
#include <stdlib.h>
#include "funclib.h"

void _LOAD() {
	int i, input;
	printf("\nADDRESS: ");scanf("%d", &input);
	i=0;
	while (i<65) {
		if (bus_storage[i].loc == input) {
			printf("%d\n", bus_storage[i].val);break;
		} else {
			i++;
		}
	}
}

void _STORE() {
	int input_val, input_loc;
	printf("\nVALUE: ");scanf("%d", &input_val);
	printf("\nWHERE TO STORE: ");scanf("%d", &input_loc);
	for (int i = 0; i < 65; i++) {
		if (bus_storage[i].loc == input_loc) {
			bus_storage[i].val = input_val;
			return;
		}
	}
}


void _MATH() {
	printf("\nwork in progress...\n");
	// math goes here, i'm not doing this yet.
}

void _CLOCK() {
	system("timedatectl");
}

void _EXIT() {
	exit(0); // this isn't a macro SHUT UP
}

void _PRINT_BUS() {
	printf("---- BUS MEMORY ----\n");
	for (int i=0;i<65;i++) {
		printf("[%d] LOC: %d, VAL: %d\n", i, bus_storage[i].loc, bus_storage[i].val);
	}
	printf("---------------------\n");
}

void _ECHO() {
	char args[512];
	printf(": ");scanf("%s", &args);
	printf("\n%s\n", args);

}

void _CLEAR() {
	system("clear"); // THIS ALSO ISN'T A MACRO SHUT UP
}
