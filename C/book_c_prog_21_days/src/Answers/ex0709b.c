#include <stdio.h>

int main(void)
{
    int elements [10];
    int idx;
    
    for(idx = 0 ; idx < 10; idx++)
        elements [idx] = idx;

    for(idx = 0 ; idx < 10; idx++)
        printf("elements [%d] = %d\n", idx, elements [idx]);

    return 0;
}
