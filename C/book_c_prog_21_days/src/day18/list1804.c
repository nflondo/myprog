/* Using free() to release allocated dynamic memory. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 31000

int main(void)
{
     void *ptr1, *ptr2;

     /* Allocate one block. */

     ptr1 = malloc(BLOCKSIZE);

     if (ptr1 != NULL)
         printf("First allocation of %d bytes successful.\n", BLOCKSIZE);
     else
     {
         printf("Attempt to allocate %d bytes failed.\n", BLOCKSIZE);
         exit(1);
     }

     /* Try to allocate another block. */

     ptr2 = malloc(BLOCKSIZE);

     if (ptr2 != NULL)
     {
         /* If allocation successful, print message and exit. */

         printf("Second allocation of %d bytes successful.\n",
                 BLOCKSIZE);
         exit(0);
     }

     /* If not successful, free the first block and try again. */

     printf("Second attempt to allocate %d bytes failed.\n", BLOCKSIZE);
     free(ptr1);
     printf("Freeing first block.\n");

     ptr2 = malloc(BLOCKSIZE);

     if (ptr2 != NULL)
         printf("After free(), allocation of %d bytes successful.\n",
                 BLOCKSIZE);
     return 0;
}
