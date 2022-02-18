//
#include <cstdio>
#include <cstdint>

void printp(uint32_t *p) {
    printf("pointer address is: %p, value is: %d\n", p, *p);
}

int main(){
    uint32_t arr[5] = { 1, 2, 3, 4, 5};
    uint32_t *p = arr;
    printp(p++);
    printp(p++);
    printp(p++);

    return 0;
}