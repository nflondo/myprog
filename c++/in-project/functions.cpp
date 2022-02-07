#include <cstdio>

int func(int i, const char * s){
    printf("this is a func(%i, %s)\n", i, s); 
    return i * 2;   
}

int main(){
    puts("this is main()");
    int x = func(34, "string passed");
    printf("x is %d\n", x);
    return 0;
}