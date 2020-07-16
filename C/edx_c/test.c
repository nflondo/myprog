#include <stdio.h>
int main() {
    int x=25-23;
    int y=60 * 24 * x;
    int z=60*y;
    printf("Dear Procrastinator,\n");
    printf("You still have to wait for %d days (%d minutes or %d seconds) before you can procrastinate!\n",x,y,z);
    return 0;
}