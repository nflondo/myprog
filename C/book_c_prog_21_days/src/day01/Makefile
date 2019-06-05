
TARGETS = hello hello2

all : $(TARGETS)

hello : hello.c
	gcc -Wall -ggdb hello.c -o hello
	
	
hello2 : hello2.c
	gcc -Wall -ggdb hello2.c -o hello2
	
clean :
	rm -f $(TARGETS) core
