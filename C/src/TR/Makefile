
TARGETS = print_it find_nbr coder count_ch mortgage

all : $(TARGETS)

print_it : print_it.c
	gcc -Wall -ggdb print_it.c -o print_it

find_nbr : find_nbr.c
	gcc -Wall -ggdb find_nbr.c -o find_nbr

coder : coder.c
	gcc -Wall -ggdb coder.c -o coder

count_ch : count_ch.c
	gcc -Wall -ggdb count_ch.c -o count_ch

mortgage : mortgage.c
	gcc -Wall -ggdb mortgage.c -lm -o mortgage
	
clean :
	rm -f $(TARGETS) core
