/* Reading formatted file data with fscanf(). */
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
     char input[40];;
     FILE *fp;

     if ( (fp = fopen("inputfile.txt", "r")) == NULL)
     {
         fprintf(stderr, "Error opening file.\n");
         exit(1);
     }

     fscanf(fp, "%s", &input);
     printf("The values are: %s \n",
             input);

     fclose(fp);
     return 0;
}
