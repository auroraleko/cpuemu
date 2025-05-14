#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../ascii/title.h"
#include "../db/junk.h"
#include "funclib.h"
#define CLEAR system("clear")

Byte bus_storage[65];
typedef void (*cmdFunc)();
typedef struct
{
	char *name;
	cmdFunc func;
	const char *desc;
} Map;

static inline void _HELP(void);

Map funcMap[]= 
{
	{"LOAD", _LOAD, "Loads a value from an address."},
	{"STORE", _STORE, "Stores a value into an address."},
	{"MATH", _MATH, "Performs arithmetic operations on any 2 values."},
	{"CLOCK", _CLOCK, "Shows time and date."},
	{"EXIT", _EXIT, "seriously? you don't know what this does??"},
	{"HELP", _HELP, "self-explanatory, again..."},
	{"PRINT_BUS", _PRINT_BUS, "prints the entire bus."},
	{"ECHO", _ECHO, "Echoes whatever you put after it. Use \"_\" or something instead of space."},
	{"CLEAR", _CLEAR, "clears your screen"},
	{"\0", NULL, "\0"}
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
		scanf("%s", &args);
		int i=0;int found = 0;
		while (i<funcSize) {
			if (strcmp(args, funcMap[i].name) == 0) {
				funcMap[i].func();
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
