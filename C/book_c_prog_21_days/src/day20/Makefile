# Makefile for multiple targets.

CC = gcc
CFLAGS = -Wall -ggdb
TARGETS = list2001 list2003 list2004 list2005

all : $(TARGETS)

list2001 : list2001.c
	$(CC) $(CFLAGS) list2001.c -o list2001

list2003 : list2003.c
	$(CC) $(CFLAGS) list2003.c -o list2003

list2004 : list2004.c
	$(CC) $(CFLAGS) list2004.c -o list2004

list2005 : list2005.o calc.o
	$(CC) list2005.o calc.o -o list2005

list2005.o : list2005.c calc.h
	$(CC) $(CFLAGS) -c list2005.c

calc.o : calc.c calc.h
	$(CC) $(CFLAGS) -c calc.c

clean :
	rm -f *.o $(TARGETS)
