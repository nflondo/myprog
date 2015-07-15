/* Demonstrates pointer arithmetic with pointers */
/* to multidimensional arrays. */
#
 #include <stdio.h>

int multi[2][4];

int main(void)
{
    printf("The value of (multi) = %lu\n", 
                 (unsigned long)multi);
    printf("The value of (multi + 1) = %lu\n", 
	             (unsigned long)(multi+1));
    printf("The address of multi[1] = %lu\n", 
	             (unsigned long)&multi[1]);
    return 0;
}
