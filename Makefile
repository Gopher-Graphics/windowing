CC ?= clang
CFLAGS +=-Wall -std=c99
AR ?= llvm-ar

SRC_H_FILES=${wildcard *.c *.h plat/*.c plat/*.h test/*.c test/*.h}

format:
	@clang-format -i ${SRC_H_FILES}

.PHONY: format
check-format:
	@clang-format --dry-run -Werror -i ${SRC_H_FILES}

build/%.o: plat/%.c
	mkdir -p ${dir $@}
	$(CC) -c -o $@ $< ${CFLAGS}

build/test/%.o: test/%.c
	mkdir -p ${dir $@}
	$(CC) -c -o $@ $< ${CFLAGS}

build/window-linux.a: build/linux.o build/x11.o build/wayland.o
	$(AR) rcs $@ $^

build/window-linux.so: build/linux.o build/x11.o build/wayland.o
	$(CC) -shared -o $@ $^ -lxcb

build/test/test-linux: build/test/test.o build/window-linux.a 
	$(CC) -o $@ $< -lxcb -Lbuild -l:window-linux.a
# build/linux.so
