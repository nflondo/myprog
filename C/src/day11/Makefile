TARGETS = list1101 list1103 list1104 list1105 list1102 


all : $(TARGETS)

list1101 : list1101.c
	gcc -Wall -ggdb list1101.c -o list1101

list1102 : list1102.c
	@echo "******************************************************"
	@echo "* This file is supposed to generate a compile error! *"
	@echo "******************************************************"
	gcc -Wall -ggdb list1102.c -o list1102

list1103 : list1103.c
	gcc -Wall -ggdb list1103.c -o list1103

list1104 : list1104.c
	gcc -Wall -ggdb list1104.c -o list1104

list1105 : list1105.c
	gcc -Wall -ggdb list1105.c -o list1105


	
clean :
	rm -f $(TARGETS) core
