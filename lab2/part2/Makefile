CC = gcc
CFLAGS = -Wall -g
LDLIBS = -lm

isort: isort.o

isort.o: isort.c

.PHONY: clean
clean: 
	rm -f *.o isort

.PHONY: all
all: clean isort
