#include <stdio.h>
void swap(int *,int *);
int main() {
     //! showMemory(start=65520)
     int a = 9;
     int b = 1;
     swap(&a,&b);
     printf("%d %d\n",a,b);
    return 0;
}
void swap(int * a, int * b){
    int tmp = * a; // assign the value of a to tmp
    * a = * b;  // swapping the values of the variables
    * b = tmp; // assign the value of tmp to b var
}