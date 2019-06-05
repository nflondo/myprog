/* Demonstrates a structure that has array members. */

#include <stdio.h>

/* Define and declare a structure to hold the data. */
/* It contains one float variable and two char arrays. */

struct data{
     float amount;
     char fname[30];
     char lname[30];
} rec;

int main(void)
{
     /* Input the data from the keyboard. */

     printf("Enter the donor's first and last names,\n");
     printf("separated by a space: ");
     scanf("%s %s", rec.fname, rec.lname);

     printf("\nEnter the donation amount: ");
     scanf("%f", &rec.amount);

     /* Display the information. */
     /* Note: %.2f specifies a floating point value */
     /* to be displayed with two digits to the right */
     /* of the decimal point. */

     /* Display the data on the screen. */

     printf("\nDonor %s %s gave $%.2f.\n", rec.fname, rec.lname,
             rec.amount);

     return 0;
}
