/* The strdup() function. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char source[] = "The source string.";

int main(void)
{
    char *dest;

    if ( (dest = strdup(source)) == NULL)
    {
        fprintf(stderr, "Error allocating memory.\n");
        exit(1);
    }

    printf("The destination = %s\n", dest);
    return 0;
}
