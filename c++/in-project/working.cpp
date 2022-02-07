// working.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

int main()
{
    const int i = 7;
    printf("value of constant is %d\n", i);
    
    puts("Hello, World!");

    char s[] = "my string";  //terminated with null(0)
    printf("s is: %s\n", s);

    // char s2[] = {'m', 'y'};
    // printf("s2 is: %s\n", s2);

    // for(int i = 0; s[i] != 0; ++i){
    //     printf("char is: %c\n", s[i]);
    // }
//print array using pointers
    // for(char * cp = s; *cp != 0; ++cp){
    //     printf("char *val is: %c\n", *cp);
    // }

    int x = 42;
    int y = 7;

    printf("value is: %d\n", x < y);

    if(x > y){ // 0 = false, any non-zero = true
        puts("condition is true");
    } else {
        puts("condition is false");
    }
    int array[] = {1,2,3,4,5};
    int i2 = 0;
    while(i2 < 5){
        if( i2 == 3) break;
        printf("element %d is: %d\n", i2, array[i2]);
        ++i2;
    }
    return 0;
}
