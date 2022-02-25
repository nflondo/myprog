// func.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

void func( int & i) // takes a reference, so 
{
    i = 73;
    printf("the value is %d: \n", i);
}

int main()
{
    int i = 47;
    puts("this is main()");
    func(i);
    printf("the value after func() is %i\n", i);
    return 0;
}