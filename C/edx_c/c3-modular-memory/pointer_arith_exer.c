#include <stdio.h>

int main() {
    int array[] = {4, 6, 12, -5, -7, 3, 1, 0, -10};
    int *ptr1, *ptr2;
    ptr1 = array+2;
    printf("ptr1: %d\n", *(ptr1+1)); // result: -5
    ptr2 = &ptr1[5]; // &ptr1 seems to pass the array, then ptr2 gets position 5
    printf("ptr2: %d\n", *(ptr2 -3)); // result: -7
}