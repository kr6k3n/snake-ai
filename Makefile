CC=gcc -g3 #-fsanitize=address
src = $(wildcard ./src/*.c)
obj = $(src:.c=.o)
undefine CFLAGS
undefine CPPFLAGS

LIBS = -lm -lncurses

nn: $(obj)
	$(CC) $^ -o $@  $(LIBS)
run:
	./nn

.PHONY: clean
clean:
	rm -f $(obj) nn

all: clean nn
