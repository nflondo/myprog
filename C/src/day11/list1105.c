/* Demonstrates local variables within blocks. */

#include <stdio.h>

int main(void)
{
    /* Define a variable local to main(void). */

    int count = 0;

    printf("\nOutside the block, count = %d", count);

    /* Start a block. */
    {
      /* Define a variable local to the block. */

      int count = 999;
      printf("\nWithin the block, count = %d", count);
    }

    printf("\nOutside the block again, count = %d\n", count);
    return 0;
}
