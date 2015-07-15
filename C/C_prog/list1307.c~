/* Demonstrates some uses of scanf(). */

#include <stdio.h>



int main(void)
{
     int i1, i2;
     long l1;

     double d1;
     char buf1[80], buf2[80];

     /* Using the l modifier to enter long integers and doubles.*/

     puts("Enter an integer and a floating point number.");
     scanf("%ld %lf", &l1, &d1);
     printf("\nYou entered %ld and %f.\n",l1, d1);
     puts("The scanf() format string used the l modifier to store");
     puts("your input in a type long and a type double.\n");

     fflush(stdin);

     /* Use field width to split input. */

     puts("Enter a 5 digit integer (for example, 54321).");
     scanf("%2d%3d", &i1, &i2);

     printf("\nYou entered %d and %d.\n", i1, i2);
     puts("Note how the field width specifier in the scanf() format");
     puts("string split your input into two values.\n");

     fflush(stdin);

     /* Using an excluded space to split a line of input into */
     /* two strings at the space. */

     puts("Enter your first and last names separated by a space.");
     scanf("%[^ ]%s", buf1, buf2);
     printf("\nYour first name is %s\n", buf1);
     printf("Your last name is %s\n", buf2);
     puts("Note how [^ ] in the scanf() format string, by excluding");
     puts("the space character, caused the input to be split.");
    
     return 0;
}
