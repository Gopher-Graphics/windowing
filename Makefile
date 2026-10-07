CC ?= clang
CFLAGS=-Wall -std=c99 -DUNICODE -D_UNICODE

SRC_H_FILES=${wildcard *.c *.h plat/*.c plat/*.h}

format:
	@clang-format -i ${SRC_H_FILES}

build/%.o: plat/%.c
	mkdir -p ${dir $@}
	$(CC) -c -o $@ $< ${CFLAGS}

build/window-linux.so: build/linux.o
	$(CC) -shared -o $@ $^

build/window-win32.dll: build/win32.o
	$(CC) -shared -o $@ $^
