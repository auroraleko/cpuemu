#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "../ascii/title.h"
#include "../db/junk.h"
#include "funclib.h"
#define CLEAR system("clear")

Byte bus_storage[65];
typedef void (*callFunc)(void);
typedef struct
{
	char *name;
	callFunc func;
	const char *desc;
} Map;

static inline void _HELP(void);
Map funcMap[]= 
{
	{"LOAD", _void_LOAD, "Loads a value from an address."},
	{"STORE", _STORE, "Stores a value into an address."},
	{"MATH",  _void_MATH, "Performs arithmetic operations on any 2 values."},
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
	syscall(SYS_write, STDOUT_FILENO, "LIST OF POSSIBLE COMMANDS:\n", 27);
	int i=0;
	while (i<funcSize) {
		char buffer[256];
		int len = snprintf(buffer, sizeof(buffer), "\n    %s : %s", funcMap[i].name, funcMap[i].desc);
		syscall(SYS_write, STDOUT_FILENO, buffer, len);
		usleep(50000);i++;
	}
	syscall(SYS_write, STDOUT_FILENO, "\n", 1);
}

char user[64];

static void shell(void) 
{
	CLEAR;char args[512];
	char startBuf[1531];
	int startLen = snprintf(startBuf, sizeof(startBuf), "%s\nemuSHELL %s\n", title, ver);
	syscall(SYS_write, STDOUT_FILENO, startBuf, startLen);
	syscall(SYS_write, STDOUT_FILENO, "Please enter your name: ", 24);
	syscall(SYS_read, STDIN_FILENO, user, sizeof(user)-1);
	if (strcmp(user, "debugpls") == 0) {
		system("gcc -fsanitize=address -g ./src/main.c ./src/helper.c -o emu_shell.cpu;echo \"Debug Mode Activated.\"");system("sleep 1;./emu_shell.cpu");
	}
	while (1) {
		char shellBuffer[64];
		int shellLen = snprintf(shellBuffer, sizeof(shellBuffer), "\n%s%% ", user);
		syscall(SYS_write, STDOUT_FILENO, shellBuffer, shellLen);
		ssize_t argch = syscall(SYS_read, STDIN_FILENO, args, sizeof(args) - 1);
		args[argch] = '\0';
		if (argch > 0 && args[argch - 1] == '\n') args[argch - 1] = '\0';
		int i=0, found = 0;
		while (i<funcSize) 
		{
			if (strcmp(args, funcMap[i].name) == 0) 
			{
   				funcMap[i].func();
				found = 1;
				break;
  			}
		i++;
		}
		if (found == 0)
		{	
			char buf[256];
			int len = snprintf(buf, sizeof(buf), "%s: Invalid Command\n", args);
			syscall(SYS_write, STDERR_FILENO, buf, len);
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

