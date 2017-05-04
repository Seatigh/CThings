CC = gcc
CFLAGS = -std=c99 -Wall -ggdb

LIB = linkedlist.c stack.c

all:
	@ $(CC) $(CFLAGS) test.c $(LIB) -o test.o

clean:
	@ rm -rf *.o core
