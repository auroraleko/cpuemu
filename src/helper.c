#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "funclib.h"

static size_t _LOAD(void) 
{
	int i;
	char input[32];

	syscall(SYS_write, STDOUT_FILENO, "\nADDRESS: 0x", 12);
	size_t scstat = syscall(SYS_read, STDIN_FILENO, input, sizeof(input)-1);
	size_t post_input = atoi(input);

	if (scstat == -1)
		return scstat;

	i=0;
	while (i<65) {
		if (bus_storage[i].loc == post_input) 
		{	
			return bus_storage[i].val;
			break;
		}
		i++;
	}
	return -1;
}

inline void _void_LOAD(void)
{
	size_t res = _LOAD();

	char buf[128];
	size_t len = snprintf(buf, sizeof(buf), "%d\n", res);

	syscall(SYS_write, STDOUT_FILENO, buf, len);
}

void _STORE(void)
{
	int i;
	char read_val[32], read_loc[32];

	syscall(SYS_write, STDOUT_FILENO, "\nVALUE: ", 8);
	syscall(SYS_read, STDIN_FILENO, read_val, sizeof(read_val)-1);
	size_t read_intVal = atoi(read_val);

	syscall(SYS_write, STDOUT_FILENO, "\nLOCATION: 0x", 13);
	syscall(SYS_read, STDIN_FILENO, read_loc, sizeof(read_loc)-1);
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

static inline int _math_HELP(int x, int y)
{
	char *helpmsg = "MATH HELP:\n	ADD\n	SUB\n	MULTIPLY\n	DIVIDE\n";
	syscall(SYS_write, STDOUT_FILENO, helpmsg, 36);
	return 0;
}

static inline int _math_ADD(int x, int y) { return x + y; }
static inline int _math_SUB(int x, int y) { return x - y; }
static inline int _math_MUL(int x, int y) { return x * y; }
static inline int _math_DIV(int x, int y) { return x / y; }

static int _MATH(void) 
{
	char errMsg[] = "Invalid Operation. Type \"HELP\" to see all operations\n";
	
	typedef int (*mInt)(int, int);
	typedef struct
	{
		char *call;
		mInt func;
	} mMap;
	
	mMap mfuncMap[]=
	{
		{"\0", NULL},
		{"HELP", _math_HELP},
		{"ADD", _math_ADD},
		{"SUB", _math_SUB},
		{"MULTIPLY", _math_MUL},
		{"DIVIDE", _math_DIV}
	};

	ssize_t mFMAP_size = sizeof(mfuncMap)/sizeof(mfuncMap[0]);

	char read_x_char[64], read_y_char[64];
	int x, y, i=0, found = 0;

	syscall(SYS_write, STDOUT_FILENO, "NUM 1: 0x", 9);
	syscall(SYS_read, STDIN_FILENO, read_x_char, sizeof(read_x_char)-1);
	int read_x = atoi(read_x_char);
	
	// take care here, it might call the loc and not the val for bus_storage[read...]

	syscall(SYS_write, STDOUT_FILENO, "\nNUM 2: 0x", 10);
	syscall(SYS_read, STDIN_FILENO, read_y_char, sizeof(read_y_char)-1);
	int read_y = atoi(read_y_char);

	char input[64];
	syscall(SYS_write, STDOUT_FILENO, "\nOPERATION: ", 12);
	syscall(SYS_read, STDIN_FILENO, input, sizeof(input)-1);

	while (i < mFMAP_size)
	{
		if (strcmp(input, mfuncMap[i].call) == 0)
		{
			char buf[256];found = 1;
			ssize_t len = snprintf(buf, sizeof(buf), "%d\n", mfuncMap[i].func(read_x, read_y));
			syscall(SYS_write, STDOUT_FILENO, buf, len);
			break;
		}
		i++;
	}
	
	if (found != 1)
		syscall(SYS_write, STDERR_FILENO, errMsg, sizeof(errMsg));
}

inline void _void_MATH(void)
{
	int res = _MATH();

	char buf[128];
	size_t len = snprintf(buf, sizeof(buf), "%d\n", res);

	syscall(SYS_write, STDOUT_FILENO, buf, len);
}

inline void _CLOCK(void) { system("timedatectl"); /*I'M NOT USING DEFINE*/ }

inline void _EXIT(void) { exit(0); /*this isn't a macro SHUT UP*/ }

void _PRINT_BUS(void)
{
	syscall(SYS_write, STDOUT_FILENO, "----- BUS MEMORY -----\n", 23);
	int i=0;
	while (i<65) {
		char buffer[128];
		size_t len = snprintf(buffer, sizeof(buffer), "[%d] LOC: 0x%d | VAL: %d\n", i, bus_storage[i].loc, bus_storage[i].val);
		syscall(SYS_write, STDOUT_FILENO, buffer, len);
		i++;
	}
	int j=0;
	while (j<24)
	{
		syscall(SYS_write, STDOUT_FILENO, "-", 1);
		j++;
	}
	syscall(SYS_write, STDOUT_FILENO, "\n", 1);
}

void _ECHO(void)
{
	syscall(SYS_write, STDOUT_FILENO, "\n : ", 4);
	char input[64] = {0};
	ssize_t n = syscall(SYS_read, STDIN_FILENO, input, sizeof(input) - 1);
	if (n > 0) {
		input[n] = '\0';
		syscall(SYS_write, STDOUT_FILENO, "\n", 1);
		syscall(SYS_write, STDOUT_FILENO, input, n);
		syscall(SYS_write, STDOUT_FILENO, "\n", 1);
	}
}

inline void _CLEAR(void) { system("clear"); /*THIS ALSO ISN'T A MACRO SHUT UP*/ }
