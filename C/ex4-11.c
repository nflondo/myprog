#include <stdio.h>

/* recursive function to take the value 3 to the power of another number.  for example, if 4 is passed, the function will return 81.*/

int mypower (int a);

int main (void){
 
 int answer,x;
 puts ("Enter a number as power of 3: ");
 scanf ("%d", &x);
 
 answer = mypower(x);
 
 printf("3 to the power %d equals %d\n",x, answer); 
 
 return 0;
} 

int mypower (int a){
 int result = 3;

  if (a < 1)
    return 1;
  else
   result *= mypower(a -1);
   
  return result;
}
