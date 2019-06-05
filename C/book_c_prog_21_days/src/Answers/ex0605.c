#include <stdio.h>

int main(void)
{
    int array[6], x, number;

    /* Loop 6 times or until the last entered value is 99. */
    for(x = 0; x < 6 && number != 99; x++)
    {
        puts("Enter an even value or 99 to quit:");
        scanf("%d", &number);
        while (number % 2 == 1 && number != 99)
        {
            printf("%d is not even.\nTry again\n", x);
            scanf("%d", &number);
        }
        array[x] = number;
    }

    /* Now print them out. */
    for(x = 0; x < 6 && number != 99; x++)
        printf("The value entered was %d.\n", array [x]);

    return 0;
}
