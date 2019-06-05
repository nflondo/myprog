# Makefile for multiple targets.

CC = gcc
CFLAGS = -Wall -ggdb
TARGETS = week1 week2 week3

all : $(TARGETS)

week1 : week1.c
	$(CC) $(CFLAGS) week1.c -o week1

week2 : week2.c
	$(CC) $(CFLAGS) week2.c -o week2

week3 : week3.c
	$(CC) $(CFLAGS) week3.c -o week3

clean :
	rm -f *.o $(TARGETS)
