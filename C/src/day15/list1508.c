/* Demonstrates the remove() function. */

#include <stdio.h>

int main(void)
{
     char filename[80];

     printf("Enter the filename to delete: ");
     fgets(filename,60,stdin);
     filename[strlen(filename)-1] = 0;

     if ( remove(filename) == 0)
         printf("The file %s has been deleted.\n", filename);
     else
         fprintf(stderr, "Error deleting the file %s.\n", filename);
     return 0;
}
