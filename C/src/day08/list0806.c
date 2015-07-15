/* Passing arguments by value and by reference.

*/ #include <stdio.h>

void by_value(int a, int b, int c);
void by_ref(int *a, int *b, int *c);

int main(void)
{
    int x = 2, y = 4, z = 6;

    printf("Before calling by_value(), x = %d, y = %d, z = %d.\n",
        x, y, z);

    by_value(x, y, z);

    printf("After calling by_value(), x = %d, y = %d, z = %d.\n",
        x, y, z);

    by_ref(&x, &y, &z);

    printf("After calling by_ref(), x = %d, y = %d, z = %d.\n",
        x, y, z);
    return 0;
}

void by_value(int a, int b, int c)
{
    a = 0;
    b = 0;
    c = 0;
}

void by_ref(int *a, int *b, int *c)
{
    *a = 0;
    *b = 0;
    *c = 0;
}
