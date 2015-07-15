/* ex2-2.c */
#include <stdio.h>
 
void display_line(void);

int main(void)
{
    display_line();
    printf("\n Sams Teach Yourself C In 21 Days!\n");
    display_line();
    printf("\n\n");
     return 0;
}

/* print asterisk line */
void display_line(void)
{
    int counter;

    for( counter = 0; counter < 34; counter++ )
        printf("*" );
}
/* end of program */
