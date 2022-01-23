CC = gcc
INCLUDES = -I ../part1
CFLAGS = -Wall -g $(INCLUDES) 
LDFLAGS = -L ../part1
LDLIBS = -lmylist  

revecho: revecho.o

revecho.o: revecho.c

.PHONY: clean
clean: 
	rm -f *.o revecho

.PHONY: all
all: clean revecho
