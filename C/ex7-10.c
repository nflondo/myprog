/* Initializes array of 10 elements, each element is equal to its subscript.  Print each element. */

#include <stdio.h>
#include <stdlib.h>
#define ADDIT 10

int arr[10], searr[10],a;

int main(void)
{
      
      for (a = 0; a < 10; a++)
      {
          arr[a]= a;
          
      }
    
      
      /* Now display the array elements 10 at a time */
      
      for (a = 0; a < 10; a++)
      {
                                  
              printf("\narr[%d]= %d", a, arr[a]);
              searr[a] = arr[a] + ADDIT; 
                        
      }
      
      for (a =0; a <10; a++){
       printf("\nsearr[%d]= %d", a, searr[a]);
      
      }
      
      /* Copy values to new array and add 10 to each value.  Print the new array values */
      
      
      
      
      return 0;
}        /* end of main(void) */
