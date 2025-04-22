all:
	gcc ./src/main.c ./src/helper.c -o cpuemu.os

clean:
	rm -f cpuemu.os
