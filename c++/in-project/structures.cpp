#include <cstdio>

struct Mystruct {
    int i;
    double d;
    const char * s;
};

int main() {
    Mystruct s1 = { 2, 56.4, "string one"}; //initializer list
    printf("s1: %d, %f, %s\n", s1.i, s1.d, s1.s);
    s1.d = 34.56;
    printf("s1: %d, %f, %s\n", s1.i, s1.d, s1.s);
    return 0;
}


