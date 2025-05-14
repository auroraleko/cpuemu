#ifndef FUNCLIB_H
#define FUNCLIB_H

typedef struct 
{
	int val;
	int loc;
} Byte;
extern Byte bus_storage[64];

void _LOAD();
void _STORE();
void _MATH();
void _CLOCK();
void _EXIT();
void _PRINT_BUS();
void _ECHO();
void _CLEAR();
#endif
