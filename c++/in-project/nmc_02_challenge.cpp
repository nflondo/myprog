// 02_challenge.cpp by Bill Weinman [bw.org]
// updated 2020-07-12
#include <cstdio>

const char string[] = "This is a null-terminated string.";

int main()
{
    int count = 0;
    for( const char * p = string; *p; ++p)
         ++count;
    
    printf("The number of characters is: %d\n", count);

    return 0;
}

