CC = gcc
CFLAGS = -Wall -g
LDLIBS = -lm

convert: main.o convert.o

main.o: convert.h

convert.o: convert.h

.PHONY: clean
clean:
	rm -f *.o convert

.PHONY: all
all: clean convert
