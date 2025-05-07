all:
	gcc ./src/main.c ./src/helper.c -o emu_os.cpu
	./emu_os.cpu

clean:
	rm -f ./emu_os.cpu

debug:
	gcc -fsanitize=address -g ./src/debug/main_debug.c ./src/helper.c -o emu_os.cpu
	./emu_os.cpu
