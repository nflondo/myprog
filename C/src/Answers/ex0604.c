#include <stdio.h>

int main(void)
{
    int x;

    puts("Enter an even value:");
    scanf("%d", &x);
    while (x % 2 != 0)
    {
        printf("%d is not even.\nTry again\n", x);
        scanf("%d", &x);
    }

    printf("The value entered was %d.\n", x);

    return 0;
}
