# Makefile for Listing 20.5
CC = gcc
CFLAGS = -Wall -ggdb  #All warnings and debugging

list2005 : list2005.o calc.o
	$(CC) list2005.o calc.o -o list2005

list2005.o : list2005.c calc.h
	$(CC) $(CFLAGS) -c list2005.c

calc.o : calc.c calc.h
	$(CC) $(CFLAGS) -c calc.c

clean :
	rm -f *.o
