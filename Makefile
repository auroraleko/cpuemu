all:
	as --64 src/main.s -o ./main.o
	gcc -O2 -Wall src/helper.c main.o -o emu_shell.cpu
	rm ./*.o

clean:
	rm -f ./emu_shell.cpu

debug:
	gcc -Wall -Werror -O2 -fsanitize=address -g ./src/debug/main_debug.c ./src/helper.c -o emu_shell.cpu
	./emu_shell.cpu

run:
	as --64 src/main.s -o ./main.o
	gcc -O2 -Wall src/helper.c main.o -o emu_shell.cpu
	rm ./*.o
	./emu_shell.cpu
