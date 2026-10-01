CC ?= clang
CFLAGS=-Wall -std=c99

SRC_H_FILES=${wildcard *.c *.h plat/*.c plat/*.h}

format:
	@clang-format -i ${SRC_H_FILES}

build/%.o: plat/%.c
	mkdir -p ${dir $@}
	$(CC) -c -o $@ $< ${CFLAGS}

build/linux.o: plat/wayland.h plat/x11.h keycodes.h window.h

build/window-linux.so: build/linux.o build/x11.o build/wayland.o
	

# build/linux.so
