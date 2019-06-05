/* Day 13 Exercises */

#include <stdio.h>

int main(void){
	
	puts("Hello World (puts)");
	
	printf("Hello World (printf)\n");
	
	fprintf(stdout, "Hello World (fprintf)\n");
	
	fprintf(stderr, "Hello Standard Error\n");
	
	char input[30];
    scanf("%30[^*]s",input);
    printf("%s\n",input);
    
    printf("Jack asked, \"What is a backslash?\"\nJill said, \"Is is \'\\\'\"\n");
	
return 0;

};
