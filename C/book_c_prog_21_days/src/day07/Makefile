TARGETS = expenses grades random list0704


all : $(TARGETS)

expenses : expenses.c
	gcc -Wall -ggdb expenses.c -o expenses

grades : grades.c
	gcc -Wall -ggdb grades.c -o grades

random : random.c
	gcc -Wall -ggdb random.c -o random

list0704 : list0704.c
	gcc -Wall -ggdb list0704.c -o list0704



	
clean :
	rm -f $(TARGETS) core
