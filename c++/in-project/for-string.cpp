#include <cstdio>

int main(){
    char s[] = "my string";

    for(char * p = s; *p; ++p){ //while *P (value) is not zero
        printf("char is: %c \n", *p);
    }

    return 0;
}