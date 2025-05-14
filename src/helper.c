#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "funclib.h"

void _LOAD(void) 
{
	int i, input;
	write(STDOUT_FILENO, "\nADDRESS: ", 10);scanf("%d", &input);
	i=0;
	while (i<65) {
		if (bus_storage[i].loc == input) {
			int idkLen = snprintf(NULL, 0, "%d\n", bus_storage[i].val);
			char *valResult = malloc((idkLen + 1) * sizeof(char));
			int valLen = snprintf(valResult, idkLen + 1, "%d\n", bus_storage[i].val);
			write(STDOUT_FILENO, valResult, valLen);
			free(valResult);
			break;
		}
		i++;
	}
}

void _STORE(void) 
{
	int input_val, input_loc;
	write(STDOUT_FILENO, "\nVALUE: ", 8);scanf("%d", &input_val);
	write(STDOUT_FILENO, "\nADDRESS: ", 10);scanf("%d", &input_loc);
	for (int i = 0; i < 65; i++) {
		if (bus_storage[i].loc == input_loc) {
			bus_storage[i].val = input_val;
			return;
		}
	}
}
 
/* make math functions */

void _MATH(void) 
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

inline void _CLOCK(void) 
{
	system("timedatectl"); // I'M NOT USING #DEFINE
}

inline void _EXIT(void) { exit(0); /*this isn't a macro SHUT UP*/ }

inline void _PRINT_BUS(void)
{
	write(STDOUT_FILENO, "---- BUS MEMORY ----\n", 21);
	int i=0;
	while (i<65) {
		int idkLen = snprintf(NULL, 0, "[%d] LOC: %d | VAL: %d\n", i, bus_storage[i].loc, bus_storage[i].val);
		char *buffer = malloc((idkLen + 1) * sizeof(char));
		int len = snprintf(buffer, sizeof(buffer), "[%d] LOC: %d | VAL: %d\n", i, bus_storage[i].loc, bus_storage[i].val);
		write(STDOUT_FILENO, buffer, len);
		i++;
	}
	free(buffer)
	write(STDOUT_FILENO, "---------------------\n", 22);
}

inline void _ECHO(void)
{
	write(STDOUT_FILENO, "\n:", 2);
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
