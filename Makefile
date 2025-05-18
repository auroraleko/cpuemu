all:
	gcc -v -O2 -Wall ./src/*.c -o emu_shell.cpu

clean:
	rm -f ./emu_shell.cpu

debug:
	gcc -Wall -Werror -O2 -fsanitize=address -g ./src/debug/main_debug.c ./src/helper.c -o emu_shell.cpu
	./emu_shell.cpu

run:
	gcc -Wall -O2 ./src/*.c -o ./emu_shell.cpu
	./emu_shell.cpu
