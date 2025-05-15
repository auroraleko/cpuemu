#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../ascii/title.h"
#include "../db/junk.h"
#include "funclib.h"
#define CLEAR system("clear")

Byte bus_storage[65];
typedef void (*voidFunc)();
typedef int (*intFunc)();
typedef struct
{
	char *name;
	voidFunc voidFunc;
	intFunc intFunc;
	const char *desc;
} Map;

static inline void _HELP(void);
Map funcMap[]= 
{
	{"LOAD", NULL, _LOAD, "Loads a value from an address."},
	{"STORE", _STORE, NULL, "Stores a value into an address."},
	{"MATH", NULL, _MATH, "Performs arithmetic operations on any 2 values."},
	{"CLOCK", _CLOCK, NULL, "Shows time and date."},
	{"EXIT", _EXIT, NULL, "seriously? you don't know what this does??"},
	{"HELP", _HELP, NULL, "self-explanatory, again..."},
	{"PRINT_BUS", _PRINT_BUS, NULL, "prints the entire bus."},
	{"ECHO", _ECHO, NULL, "Echoes whatever you put after it. Use \"_\" or something instead of space."},
	{"CLEAR", _CLEAR, NULL, "clears your screen"},
	{"\0", NULL, NULL, "\0"}
};

size_t funcSize = sizeof(funcMap)/sizeof(funcMap[0]);

void _HELP(void) 
{
	write(STDOUT_FILENO, "LIST OF POSSIBLE COMMANDS:\n", 27);
	int i=0;
	while (i<funcSize) {
		char buffer[256];
		int len = snprintf(buffer, sizeof(buffer), "\n    %s : %s", funcMap[i].name, funcMap[i].desc);
		write(STDOUT_FILENO, buffer, len);
		usleep(50000);i++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

char user[64];

static void shell(void) 
{
	CLEAR;char args[512];
	char startBuf[1531];
	int startLen = snprintf(startBuf, sizeof(startBuf), "%s\nemuSHELL %s\n", title, ver);
	write(STDOUT_FILENO, startBuf, startLen);
	write(STDOUT_FILENO, "Please enter your name: ", 24);scanf("%s", &user);
	if (strcmp(user, "debugpls") == 0) {
		system("gcc -fsanitize=address -g ./src/main.c ./src/helper.c -o emu_shell.cpu;echo \"Debug Mode Activated.\"");system("sleep 1;./emu_shell.cpu");
	}
	while (1) {
		char shellBuffer[64];
		int shellLen = snprintf(shellBuffer, sizeof(shellBuffer), "\n%s%% ", user);
		write(STDOUT_FILENO, shellBuffer, shellLen);
		scanf("%s", &args); // fix this lmfao
		int i=0, found = 0;
		while (i<funcSize) {
			if (strcmp(args, funcMap[i].name) == 0) {
  				if (funcMap[i].voidFunc != NULL) {
   					funcMap[i].voidFunc();
					} else {
     					funcMap[i].intFunc();
  				}
   			found = 1;
	  			break;
			}
		i++;
		}
		if (found == 0) {
			write(STDERR_FILENO, "Invalid Command.\n", 17);
		}
	}
}

int main(void) {
	int i=0;
	while (i<65) {
		bus_storage[i].loc = i;
		i++;
	} shell();
	return 0;
}
