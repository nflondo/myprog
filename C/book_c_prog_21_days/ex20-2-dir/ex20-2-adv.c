/* Write error routine that receives an error number, line number, and module name.  The routine should print
a formatted error message and then exit the program.

  Inputs a number and displays its square. */

 #include <stdio.h>
 #include <string.h>
 #include "calc.c"
 #include "calc.h"
int print_error(char e_number, int l_number, char m_name[40]);

 int main(void)
 {
    char response[10];
	
    printf("Enter a string: ");
    scanf("%s",response);
	if (strcmp(response, "0")==0){
	 print_error(0,__LINE__, __FILE__);
	}
	if (strcmp(response, "1")==0){
	 printf("found string 1\n");
	 print_error("1",__LINE__, __FILE__);
	}
	
    //printf("\nThe square of %d is %ld.\n\n", x, sqr(x));
    return 0;
 }
int print_error(char e_number, int l_number, char m_name[40]){
  FILE *fp;
  char *filename = "errors.txt";
  char buffer[80];
  char *mode = "r";
  char *loc;

if ( (fp = fopen( filename, mode )) != NULL )
{
            
    while(fgets(buffer, 80, fp) != NULL){
		//buffer[strlen(buffer)-1] = 0; // strip newline char
		loc = strstr(buffer,(char *)e_number);
		if (loc == NULL)
		printf("The character %s was not found\n", buffer);
		else{
		printf("The system encountered error:%s, on Line: %d, on Module:%s.  Exiting the program\n", buffer, l_number, m_name);
		exit(loc);
		
		//if((strstr(buffer,e_number)) != NULL){
		// printf ("Found a match\n");
		}
		
	}
	
}
else{
            fprintf(stderr, "\nError opening file %s in mode %s.\n",       filename, mode);  
exit(1);
return 1;			
 }
 
 //printf("The system encountered error:%d, on Line: %d, on Module:%s.  Exiting the program\n", e_number, l_number, m_name);
 //exit(12);

 fclose(fp);
 return 0;
 }