/* Write error routine that receives an error number, line number, and module name.  The routine should print
a formatted error message and then exit the program.

 /* Inputs a number and displays its square. */

 #include <stdio.h>
 #include "calc.c"
 #include "calc.h"
int print_error(int e_number, int l_number, char m_name[40]);

 int main(void)
 {
    int x;

    printf("Enter an integer value: ");
    scanf("%d", &x);
	if (x == 0){
	 print_error(12,__LINE__, __FILE__);
	}
	
    printf("\nThe square of %d is %ld.\n\n", x, sqr(x));
    return 0;
 }
int print_error(int e_number, int l_number, char m_name[40]){

 printf("The system encountered error:%d, on Line: %d, on Module:%s.  Exiting the program\n", e_number, l_number, m_name);
 exit(12);

 }
