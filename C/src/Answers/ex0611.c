#include <stdio.h>

int main(void)
{
    int count, temp, total = 0;
    
    for(count = 1; count <= 10; count++)
    {
        printf("Enter integer #%d: ", count);
        scanf("%d", &temp);
        total += temp;
    }

    printf("The total is %d.\n", total);

    return 0;
}

