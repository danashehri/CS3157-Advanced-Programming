CC = gcc
CFLAGS = -Wall -g
LDLIBS = -lm

twecho: twecho.o

twecho.o: twecho.c

.PHONY: clean
clean: 
	rm -f *.o twecho

.PHONY: all
all: clean twecho
