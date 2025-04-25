all:
	gcc ./src/main.c ./src/helper.c -o cpuemu.os
	./cpuemu.os

clean:
	rm -f cpuemu.os

debug:
	gcc -fsanitize=address -g ./src/debug/main_debug.c ./src/helper.c -o cpuemu.os
	./cpuemu.os

# the debug is so outdated ill repair it when i will when it becomes inconvenient to me

