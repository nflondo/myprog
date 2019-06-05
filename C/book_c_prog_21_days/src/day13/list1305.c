/* Clearing stdin of extra characters. */

#include <stdio.h>

void clear_kb(void);

int main(void)
{
     int age;
     char name[20];

     /* Prompt for user's age. */

     puts("Enter your age.");
     scanf("%d", &age);

     /* Clear stdin of any extra characters. */

     clear_kb();

     /* Now prompt for user's name. */

     puts("Enter your first name.");
     scanf("%s", name);
     /* Display the data. */

     printf("Your age is %d.\n", age);
     printf("Your name is %s.\n", name);
     
     return 0;
}

void clear_kb(void)

/* Clears stdin of any waiting characters. */
{
     char junk[80];
     fgets(junk,80,stdin);
}
