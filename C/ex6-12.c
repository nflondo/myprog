/* Inputs Integers from the keyboard storing them in an array.  Input stops when a zero is entered or when the end of array is reached.  Then display the array's largest and the smallest values */

#include <stdio.h>
#define QUIT 0

int count,temp=2;
int my_array[5];

int main(void){
 int small,big; 
  
/*while (temp != QUIT) {*/
  for (count=1; count <= 5 && temp != QUIT; count ++){
  
   printf ("Enter digit %d: ", count);
   scanf ("%d", &temp);
   my_array[count -1] = temp;
   
   }
/*} */
 
  big = my_array[0];
 for (count=0; count <5; count ++){
   
   if (my_array[count] >= big){
   big = my_array[count];
   }
  }
   
    small = my_array[0]; 
  for (count=0; count <5; count ++){
 
   if (my_array[count] <= small){
    small = my_array[count];
   }
   
  }

 printf("The biggest number in array is: %d The smallest is: %d \n", big, small);
 
 return 0;

}


