/* */

#include <stdio.h>

#define NMAX1 4
#define NMAX2 3

int arra[NMAX1] = { 1, 1, 1, 1 };
int arrb[NMAX2] = { 1, 1, 1 };
int gtotal;

int sumarrays(int a1[], int x, int b1[], int y);

int main(void){
  
gtotal = sumarrays(arra, NMAX1, arrb, NMAX2);
 printf("Result: %d\n", gtotal);

return 0;

}

int sumarrays(int a1[], int x, int b1[], int y){

int total=0, count=0;

 for (count=0; a1[count] < x; count++)
  total += a1[count];


for (count=0; b1[count]< y; count++)
  total += b1[count];

return total;

}
