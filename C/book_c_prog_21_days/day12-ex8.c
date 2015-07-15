/* Calculator.  Addition, Substraction, multiplication, division*/
#include <stdio.h>
#include <stdlib.h>

int myadd(int x, int y);
int mysub(int x, int y);
int mymul(int x, int y);
int mydiv(int x, int y);
void clear_kb(void);

/*Main menu asks user to choose operation, then each function handles specific operation*/

int main(void){
int myinput; 
 
 while(1){
/* char input[1];*/
  
  puts("a)Addition, s)Substraction, m)Multiplication, d)Division or q)quit");
  fflush(stdin); 
  myinput = getchar();
   /* remove extra characters from keyboard buffer */
/*  fgets(input,10,stdin);*/
 
	switch (myinput){
	    int x,y;
	    int result;
		case 'a':
		 printf("Please enter two numbers to add (separated by a space):");
		 scanf("%d %d", &x, &y);
		 result = myadd(x,y);
		 printf("The result is: %d\n", result);
		 fflush(stdin); 
		 break;
		case 's':
		 printf("Please enter two numbers to substract (separated by a space):");
		 scanf("%d %d", &x, &y);
		 result = mysub(x,y);
		 printf("The result is: %d\n", result);
		 break;
		case 'm':
		 printf("Please enter two numbers to multiply (separated by a space):");
		 scanf("%d %d", &x, &y);
		 result = mymul(x,y);
		 printf("The result is: %d\n", result);
		 break;
		case 'd':
		 printf("Please enter two numbers to divide (separated by a space):");
		 scanf("%d %d", &x, &y);
		 result = mydiv(x,y);
		 printf("The result is: %d\n", result);
		 break;
		case 'q':
		 puts("Bye bye");
		 exit(0);
		
		default: 
		 printf("Invalid optioin, try again...\n");
		 break;
		 
 	}/*switch*/

 }/*while*/

 return 0;

}

/* functioin to add */
int myadd(int x, int y){
 int result = x + y;
  return result;
}
/* functioin to substract */
int mysub(int x, int y){
 int result = (x - y);
 return result;
}
/* functioin to multiply */
int mymul(int x, int y){
 int result = (x * y);
 return result;
}
/* functioin to divide */
int mydiv(int x, int y){
 int result = (x / y);
 return result;
}
void clear_kb(void)
{
    char junk[80];
    fgets(junk, 80, stdin);
}
