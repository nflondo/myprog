#include <stdio.h>
int main(void) {
    //! showMemory(start=65520)
    int array[] = {6, 2, -4, 8, 5, 1};
    int *ptr, *ptr2;
    
    printf("Array contains %d, %d, ... , %d\n", array[0], array[1], array[5]);
    printf("These are stored at %p, %p, ..., %p\n", &array[0], &array[1], &array[5]);
    // array equals &array[0]
    ptr = array;
    ptr2 = &array[0]; // same thing as line above
    
    *ptr = 10; 
    *(ptr + 1) = 5; // this assign value 5 to array[1]
    *(ptr + 2) = -1; // this assign value to array[2]
    
    *array = 3; // this assign value to array[0]
    *(array + 1) = 10; // this assign value to array[1]
    *(array + 2) = 99; // this assign value to array[2]
    
    ptr++; // next place/int in the array
    *ptr = 7;
    
    ptr += 3;
    *ptr = 8;

    int numbers[] = {4, -1, 8, 3, 0, -11};
    printf("numbers %p\n", *numbers);
    printf("numbers + 4: %d\n", *numbers + 4);

    int numbers2[] = {4, -1, 8, 3, 0, -11};
    printf("numbers[10] %d\n", numbers2[10]);

    int numbers3[] = {4, -1, 8, 3, 0, -11};
    int *ptr3;
    ptr3 = numbers3 + 2;
    ptr3++;
    printf("ptr3: %d\n", *ptr3);

    return 0;
}