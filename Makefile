all:
	gcc ./src/main.c ./src/helper.c -o cpuemu.os
	./cpuemu.os

clean:
	rm -f cpuemu.os
