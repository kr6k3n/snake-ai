CC=gcc
src = $(wildcard ./src/*.c)
_obj = $(src:.c=.o)
obj = $(_obj:/src/=/obj/)

LIBS = -lm 

nn: $(obj)
	$(CC) -g $^ -o $@ $(LIBS)
run:
	./nn

.PHONY: clean
clean:
	rm -f $(obj) nn

routine: clean nn run
