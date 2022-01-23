CC = gcc
CFLAGS = -Wall -g
LDLIBS = 

mylist-test: mylist-test.o libmylist.a  

libmylist.a: mylist.o
	ar rcs libmylist.a mylist.o
	ranlib libmylist.a

mylist.o: mylist.c mylist.h

mylist-test.o: mylist-test.c mylist.h

libs: libmylist.a

.PHONY: clean
clean: 
	rm -f *.o mylist-test

.PHONY: all
all: clean mylist-test

