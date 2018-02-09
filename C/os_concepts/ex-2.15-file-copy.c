#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 100

int main(void)
{
	char buf[BUFSIZE];
    char file_source[60];
    /*char target_file[81];*/
    FILE *fp;
	
	printf("Name of source file: ");
    fgets(file_source,60,stdin);
    file_source[strlen(file_source)-1] = 0;
	
    puts("Made it to pass fgets");
    /* open the file for readin */
    if ( (fp = fopen(file_source, "r")) == NULL )
    {
        fprintf(stderr, "Error opening the file.\n");
        exit(1);
    }
    
    /* if end of file not reached, read a line and display it. */
    while ( !feof(fp))
    {
        fgets(buf, BUFSIZE, fp);
        printf("%s", buf);
    }
    
    fclose(fp);      
        
/*    
    printf("Name of target file: ");
    scanf("%s", target_file);
    
    printf("You entered: %s and %s\n", source_file, target_file);
*/	
    return 0;
}
