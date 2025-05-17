all:
	gcc ./src/main.c ./src/helper.c -o emu_shell.cpu

clean:
	rm -f ./emu_shell.cpu

debug:
	gcc -fsanitize=address -g ./src/debug/main_debug.c ./src/helper.c -o emu_shell.cpu
	./emu_shell.cpu

run:
	gcc ./src/*.c -o ./emu_shell.cpu
	./emu_shell.cpu
