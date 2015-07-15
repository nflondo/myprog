/* Initializes array of 10 elements, each element is equal to its subscript.  Print each element. */

#include <stdio.h>
#include <stdlib.h>

int arr[10],a;

int main(void)
{
      
      for (a = 0; a < 10; a++)
      {
          arr[a]= a;
          
      }
    
      
      /* Now display the array elements 10 at a time */
      
      for (a = 0; a < 10; a++)
      {
                                  
              printf("\nrandom_array[%d]= %d", a, arr[a]);

                        
      }
      return 0;
}        /* end of main(void) */
