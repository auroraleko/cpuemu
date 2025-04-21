#ifndef HELPER_H
#define HELPER_H

typedef struct {
	int val;
	int loc;
} Byte; Byte bus[64];

int _LOAD();
void _STORE();
int _MATH();
void _CLOCK();
void _EXIT();
void _HELP();
#endif
