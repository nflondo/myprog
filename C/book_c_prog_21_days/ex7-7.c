/* puts random numbers into a two dimensional array that is 5 by 4.  Print values on columns onscreen */

#include <stdio.h>
#include <stdlib.h>

int main(void){
 
 int stuff[5][4];
 
for (int x=0; x < 5; x ++ ){
  for (int y=0; y < 4; y ++){
   stuff[x][y] = rand();
   }  
 }  
   
 for (int a=0; a < 5; a ++ ){
  for (int b=0; b < 4; b ++){
    printf ("%20d\t\n", stuff[a][b]);

   }
  }  
   
return 0;


}
