/* Using a pointer to call different functions. */

#include <stdio.h>

/* The function prototypes. */

void func1(int x);
void one(void);
void two(void);
void other(void);

int main(void)
{
     int a;

     for (;;)
     {
         puts("\nEnter an integer between 1 and 10, 0 to exit: ");
         scanf("%d", &a);

         if (a == 0)
             break;
         func1(a);
     }
     return 0;
}

void func1(int x)
{
     /* The pointer to function. */

     void (*ptr)(void);

     if (x == 1)
         ptr = one;
     else if (x == 2)
         ptr = two;
     else
         ptr = other;

     ptr();
}

void one(void)
{
    puts("You entered 1.");
}

void two(void)
{
    puts("You entered 2.");
}

void other(void)
{
    puts("You entered something other than 1 or 2.");
}
