 /* Inputs a number and displays its square. */

 #include <stdio.h>
 #include "calc.h"

 int main(void)
 {
    int x;

    printf("Enter an integer value: ");
    scanf("%d", &x);
    printf("\nThe square of %d is %ld.\n\n", x, sqr(x));
    return 0;
 }
