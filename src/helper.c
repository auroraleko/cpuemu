#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int _LOAD() {
	int i, input;
	printf("\nADDRESS: ");scanf("%d", &input);
	i=0;
	while (i<64) {
		if (bus[i].loc == input) {
			return bus[i].val;
		} else {
			i++;
		}
	}
}

void _STORE() {
	int input_val, input_loc;
	printf("VALUE: ");scanf("%d", &input_val);
	printf("WHERE TO STORE: ");scanf("%d", &input_loc);
	int i=0;
	while (i<64) {
		if (bus[i].loc == input_loc) {
			bus[i].val = input_val;break;
		} else {
			i++;
		}
	}
}

int _MATH() {
	// math goes here, i'm not doing this yet.
}

void _CLOCK() {
	system("timedatectl");
}

void _EXIT() {
	exit(0); // this isn't a macro SHUT UP
}
