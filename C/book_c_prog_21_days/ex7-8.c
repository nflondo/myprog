/* random.c-single dimensional array of type short.  Print the average of the 1,000 variables before printing the individual values */

#include <stdio.h>
#include <stdlib.h>

short random_array[1000], avg;
int a,b;
int total =0;


int main(void)
{
      /* Fill the array with random numbers. The C library */
      /* function rand() returns a random number. Use one */
      /* for loop for each array subscript. */

      for (a = 0; a < 1000; a++)
      {
          random_array[a]= rand();
          total =+ random_array[a];
      }
    
      avg = total/1000;
      
      printf ("Average is: %d", avg);
      
      /* Now display the array elements 10 at a time */
      
      for (a = 0; a < 1000; a++)
      {
                                  
              printf("\nrandom_array[%d]= ", a);
              printf("%d", random_array[a]);
             
             if (a % 10 ==0 && a > 0){
              printf("\nPress Enter to continue, CTRL-C to quit.");
              getchar();              
            }
      }
      return 0;
}        /* end of main(void) */
