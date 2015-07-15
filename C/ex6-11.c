/* Inputs two floating-point values from the keyboard and then displays their product */

#include <stdio.h>

int count,temp, total=0;

int main(void){
 
 for (count=1; count <= 10; count ++){
  
   printf ("Enter digit %d: ", count);
   scanf ("%d", &temp);
   total += temp;
 
 }

 printf("The total is %d.\n", total);
 
 return 0;

}


