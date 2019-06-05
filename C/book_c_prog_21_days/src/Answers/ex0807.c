#include <stdio.h>

#define MAX1 5
#define MAX2 8

int array1[MAX1] = { 1, 2, 3, 4, 5 };
int array2[MAX2] = { 1, 2, 3, 4, 5, 6, 7, 8 };
int total;

int sumarrays(int x1[], int len_x1, int x2[], int len_x2);

int main(void)
{
   total = sumarrays(array1, MAX1, array2, MAX2);
   printf("The total is %d\n", total);
   
   return 0;
}

int sumarrays(int x1[], int len_x1, int x2[], int len_x2)
{
   
   int total = 0, count = 0;
   
   for (count = 0; count < len_x1; count++)
      total += x1[count];
   
   for (count = 0; count < len_x2; count++)
      total += x2[count];
   
   return total;
}
