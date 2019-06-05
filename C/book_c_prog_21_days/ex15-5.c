 /* displays a file to the screen */
#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 60
//#define FILENAME list1511.c
 
 int main (void){
 FILE *fp;
 char buf[BUFLEN];
 int count = 0;
 
 /* open the file */
 if( (fp = fopen("newtext.txt", "r")) == NULL){
         fprintf(stderr, "Error opening file.\n");
         exit(1);
     }
	
  while ( !feof(fp) )
    {
        fgetc(fp);
		count ++;
        
    }
 
// Close the file
fclose(fp);

printf("%d",count);
return 0;
}