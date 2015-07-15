#include <stdio.h>

int main(void)
{
    int elements [10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int idx;
    
    for(idx = 0 ; idx < 10; idx++)
    {
        printf("elements [%d] = %d\n", idx, elements [idx]);
    }

    return 0;
}
