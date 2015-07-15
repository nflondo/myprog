#include <stdio.h>

int main(void)
{
    int elements [10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int new_array [10];
    int idx;
    
    for(idx = 0 ; idx < 10; idx++)
        new_array [idx] = elements [idx] + 10;

    for(idx = 0 ; idx < 10; idx++)
        printf("elements [%d] = %d\nnew_array[%d] = %d\n", 
		idx, elements [idx], idx, new_array [idx]);

    return 0;
}
