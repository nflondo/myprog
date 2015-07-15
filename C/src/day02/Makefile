
TARGETS = multiply list_it sizeof list0204 ex2-2 ex2-4 ex2-5

all : $(TARGETS)

multiply : multiply.c
	gcc -Wall -ggdb multiply.c -o multiply
	
list_it : list_it.c
	gcc -Wall -ggdb list_it.c -o list_it

sizeof : sizeof.c
	gcc -Wall -ggdb sizeof.c -o sizeof

list0204 : list0204.c
	gcc -Wall -ggdb list0204.c -o list0204

ex2-2 : ex2-2.c
	gcc -Wall -ggdb ex2-2.c -o ex2-2

ex2-4 : ex2-4.c
	gcc -Wall -ggdb ex2-4.c -o ex2-4

ex2-5 : ex2-5.c
	gcc -Wall -ggdb ex2-5.c -o ex2-5

	
clean :
	rm -f $(TARGETS) core
