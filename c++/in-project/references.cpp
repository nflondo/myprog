// pointers.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

int main()
{
    int x = 42;    
    int * ip = &x;
    const int & y = x; //creates a reference to x.  Its value is always the value 
        //of x don't need to dereference a reference (no *)

    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);//doesn't have to be dereferenced
    printf("The value of *ip is %d\n", *ip);

//    y = 73;//this does not change y, it changes x
    x = 73;//this does not change y, it changes x

    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);//doesn't have to be dereferenced
    printf("The value of *ip is %d\n", *ip);

    int z = 7;
    ip = &z;

    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);//doesn't have to be dereferenced
    printf("The value of *ip is %d\n", *ip);

    *ip = 103;
    printf("The value of z is %d\n", z);
    
    y = 142;
//    x = 142;

    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);//doesn't have to be dereferenced
    printf("The value of z is %d\n", z);

    return 0;
}
