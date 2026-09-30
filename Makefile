CC ?= clang
CFLAGS=-Wall



build/%.o: plat/%.c
	mkdir -p ${dir $@}
	$(CC) -c -o $@ $< ${CFLAGS}

build/linux.o: plat/wayland.h plat/x11.h keycodes.h window.h

# build/linux.so
