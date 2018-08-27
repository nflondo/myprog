/* 
 * Collatz conjecture.  
 * 
 */
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2){
		fprintf(stderr, "No number typed on the command line.\n");
		return (EXIT_FAILURE);
	}
	pid_t pid;
	int result=0;
	int number = atoi(argv[1]);  // converts string to int
	if (number < 0){
		fprintf(stderr, "***Error, negative number.\n");
		return (EXIT_FAILURE);
	}
	pid = fork();
	
	if (pid == 0) {
		printf("%d ", number);
		while(number != 1){			
			if (number % 2 == 0)
				number = number/2;
			else 
				number = 3 * number + 1;
			
			printf("%d ", number);
		}		
	}
	else if (pid > 0){		
		wait(NULL); 
		printf("child complete.\n");
	}		
		
	return 0;	
}
