/* Using type void pointers. */

#include <stdio.h>

void half(void *x, char type);

int main(void)
{
    /* Initialize one variable of each type. */

    int i = 20;
    long l = 100000;
    float f = 12.456;
    double d = 123.044444;

    /* Display their initial values. */

    printf("%d\n", i);
    printf("%ld\n", l);
    printf("%f\n", f);
    printf("%f\n\n", d);

    /* Call half() for each variable. */

    half(&i, 'i');
    half(&l, 'l');
    half(&d, 'd');
    half(&f, 'f');

    /* Display their new values. */
    printf("%d\n", i);
    printf("%ld\n", l);
    printf("%f\n", f);
    printf("%f\n", d);
    return 0;
}

void half(void *x, char type)
{
    /* Depending on the value of type, cast the */
    /* pointer x appropriately and divide by 2. */

    switch (type)
    {
        case 'i':
            {
            *((int *)x) /= 2;
            break;
            }
        case 'l':
            {
            *((long *)x) /= 2;
            break;
            }
        case 'f':
            {
            *((float *)x) /= 2;
            break;
            }
        case 'd':
            {
            *((double *)x) /= 2;
            break;
            }
    }
}
