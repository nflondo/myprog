#include <stdio.h>

#define MAX1 5
#define MAX2 8

int array1[MAX1] = { 1, 2, 3, 4, 5 };
int array2[MAX1] = { 10, 20, 30, 40, 50 };
int array3[MAX1];
int total;

int addrrays(int x1[], int x2[], int len_x);

int main(void)
{
   total = addrrays(array1, array2, MAX1);
   
   return 0;
}

int addrrays(int x1[], int x2[], int len_x)
{
   
   int count = 0;
   
   for (count = 0; count < len_x; count++){
      array3[count] = x1[count] + x2[count];
      printf("%d + %d = %d\n",  x1[count], x2[count], array3[count]);
   }  
   
   return 0;
}
