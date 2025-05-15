#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "funclib.h"

int _LOAD(void) 
{
	int i;
	char input[32];

	write(STDOUT_FILENO, "\nADDRESS: ", 10);
	size_t scstat = read(STDIN_FILENO, input, sizeof(input)-1);
	size_t post_input = atoi(input);

	if (scstat == -1)
		return scstat;

	i=0;
	while (i<65) {
		if (bus_storage[i].loc == post_input) 
		{
			char buffer[64];
			size_t len = snprintf(buffer, sizeof(buffer), "%d\n", bus_storage[i].val);
			write(STDOUT_FILENO, buffer, len);
			break;	
		}
		i++;
	}
	return -1;
}
 
void _STORE(void)
{
	int i;
	char read_val[32], read_loc[32];

	write(STDOUT_FILENO, "\nVALUE: ", 8);
	read(STDIN_FILENO, read_val, sizeof(read_val)-1);
	size_t read_intVal = atoi(read_val);

	write(STDOUT_FILENO, "\nLOCATION: ", 11);
	read(STDIN_FILENO, read_loc, sizeof(read_loc)-1);
	size_t read_intLoc = atoi(read_loc);

	i=0;
	while (i<65)
	{
		if (bus_storage[i].loc == read_intLoc)
		{
			bus_storage[i].val = read_intVal;
			break;
		}
		i++;
	}
}

// make math functions

int _MATH(void) 
{
	/*
	typedef void (*funcCall)();
	typedef struct {
		char *opName;
		funcCall opFunc;
	} Block;
	Block operationMap[] = {
		{"ADD", _MATH_ADD},
		{"SUB" _MATH_SUB},
		{"MUL", _MATH_MUL},
		{"DIV", _MATH_DIV},
		{"\0", NULL}
	}; char input[64];
	printf("OPERATION :");scanf("%s", &input);
	while (1) {
		int i=0, found = 0;
		int opSize = sizeof(operationMap)/sizeof(operationMap[0]);
		while (i<opSize) {
			if (operationMap[i].opName == input) {
				operationMap[i].opFunc();
				found = 1;break;
			}
			i++;
		}
		if (found != 1) {
			printf("OPERATION INVALID\n");
		}
	}
	*/
}

inline void _CLOCK(void) { system("timedatectl"); /*I'M NOT USING DEFINE*/ }

inline void _EXIT(void) { exit(0); /*this isn't a macro SHUT UP*/ }

void _PRINT_BUS(void)
{
	write(STDOUT_FILENO, "----- BUS MEMORY -----\n", 23);
	int i=0;
	while (i<65) {
		char buffer[128];
		size_t len = snprintf(buffer, sizeof(buffer), "[%d] LOC: 0x%d | VAL: %d\n", i, bus_storage[i].loc, bus_storage[i].val);
		write(STDOUT_FILENO, buffer, len);
		i++;
	}
	int j=0;
	while (j<24)
	{
		write(STDOUT_FILENO, "-", 1);
		j++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

inline void _ECHO(void)
{
	write(STDOUT_FILENO, "\n : ", 4);
	char input[64] = {0};
	ssize_t n = read(STDIN_FILENO, input, sizeof(input) - 1);
	if (n > 0) {
		input[n] = '\0';
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, input, n);
		write(STDOUT_FILENO, "\n", 1);
	}
}

inline void _CLEAR(void) { system("clear"); /*THIS ALSO ISN'T A MACRO SHUT UP*/ }

/*
inline void _UP(void)
{
	char buffer[1];
	fgets(buffer, 1, stdin);
	fflush(stdout);
}
*/
