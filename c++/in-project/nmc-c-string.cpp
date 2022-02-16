// c-strings.cpp by Bill Weinman <http://bw.org/>
// updated 2020-07-05
#include <cstdio>

int main() {
    const char * cstring = 
    "String" 
    " another string"; //string is immutable, so needs const
    
    puts(cstring);
    
    for(int i = 0; cstring[i]; i++) {
        printf("%d: %c\n", i, cstring[i]);
    }
    return 0;
}