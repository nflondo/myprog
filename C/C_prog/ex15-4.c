 /* displays a file to the screen */
#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 60
//#define FILENAME list1511.c
 
 int main (void){
 FILE *fp;
 char buf[BUFLEN];
 
 /* open the file */
 if( (fp = fopen("list1511.c", "r")) == NULL){
         fprintf(stderr, "Error opening file.\n");
         exit(1);
     }
	
  while ( !feof(fp) )
    {
        fgets(buf, BUFLEN, fp);
        printf("%s",buf);
    }
 
// Close the file
fclose(fp);
return 0;
}