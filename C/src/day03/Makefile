
TARGETS = list0301 list0302 list0303 list0304 list0305 list0306


all : $(TARGETS)

list0301 : list0301.c
	gcc -Wall -ggdb list0301.c -o list0301

list0302 : list0302.c
	gcc -Wall -ggdb list0302.c -o list0302

list0303 : list0303.c
	gcc -Wall -ggdb list0303.c -o list0303

list0304 : list0304.c
	gcc -Wall -ggdb list0304.c -o list0304

list0305 : list0305.c
	gcc -Wall -ggdb list0305.c -o list0305

list0306 : list0306.c
	@echo "******************************************"
	@echo "* This file generates a warning message. *"
	@echo "* It there for demonstration purposes.   *"
	@echo "******************************************"
	gcc -Wall -ggdb list0306.c -o list0306


	
clean :
	rm -f $(TARGETS) core
