/* Counts the number of occurrences   */
/* of each character in a file.       */
#include <stdio.h>
#include <stdlib.h>

int file_exists(char *filename);

int main(void)
{
     char source[80];
     int  ch, index;
     int  count[127];
     FILE *fp;

     /* Get the source and destination filenames. */
     fprintf(stderr, "\nEnter source file name: ");
     fscanf(stdin, "%80s", source);

     /* See that the source file exists. */
     if (!file_exists(source))
     {
         fprintf(stderr, "\n%s does not exist.\n", source);
         exit(1);
     }
     /* Open the file. */
     if ((fp = fopen(source, "rb")) == NULL)
     {
         fprintf(stderr, "\nError opening %s.\n", source);
         exit(1);
     }
     /* Zero the array elements. */
     for (index = 31; index < 127 ; index++)
         count[index] = 0;

     while ( 1 )
     {
         ch = fgetc(fp);
         /* Done if end of file */
         if (feof(fp))
             break;
         /* Count only characters between 32 and 126. */
      if (ch > 31 && ch < 127)
            count[ch]++;
      }

     /* Display the results. */
     printf("\nChar\tCount\n");
     for (index = 32; index < 127 ; index++)
        printf("[%c]\t%d\n", index, count[index]);
    /* Close the file and exit. */
    fclose(fp);
    return 0;
}

int file_exists(char *filename)
{
   /* Returns TRUE if filename exists,
    * FALSE if not. 
	*/
   FILE *fp;
   if ((fp = fopen(filename, "r")) == NULL)
       return 0;
   else
   {
       fclose(fp);
       return 1;
   }
}
