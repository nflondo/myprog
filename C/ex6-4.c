#include <stdio.h>
/* only accepts even values */

int main (void){
 int val;
 do{
 puts ("enter even value:");
 scanf("%d", &val);
 }
 while (val % 2 != 0 );
 
  printf("value is %d\n", val);
return 0;
}
