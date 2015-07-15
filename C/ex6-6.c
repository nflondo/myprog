#include <stdio.h>
/* only accepts even values until number 99 is entered or until 6 even values have been entered.  Put them in an array*/

 int print_values(int array);
 
int main (void){
 int val, count;
 int even[6];

 
 for (count =0; val !=99 && count < 6; count ++){
  
  puts ("enter even value:");
  scanf("%d", &val);
  while ( val % 2 != 0 && val !=99){
  puts ("Number is not even, please enter even value:");
  scanf("%d", &val);
  }
  if (val % 2 ==0){
  even[count]=val;
  }
 }
 
 for (count =0; count < 6 ; count ++){
  printf("%d\t", even[count]);
 }
 
return 0;
}

 
