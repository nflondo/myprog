/* Passing a pointer to a function as an argument. */

#include <stdio.h>

/* The function prototypes. The function func1() takes as */
/* its one argument a pointer to a function that takes no */
/* arguments and has no return value. */

void func1(void (*p)(void));
void one(void);
void two(void);
void other(void);

int main(void)
{
     /* The pointer to a function. */

     void (*ptr)(void);
     int  a;

     for (;;)
     {
         puts("\nEnter an integer between 1 and 10, 0 to exit: ");
         scanf("%d", &a);

         if (a == 0)
             break;
         else if (a == 1)
             ptr = one;
         else if (a == 2)
             ptr = two;
         else
             ptr = other;
         func1(ptr);
     }
     return 0;
}

void func1(void (*p)(void))
{
     p();
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
