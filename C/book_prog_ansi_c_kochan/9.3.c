#include <stdio.h>
/*Calculated number of days elapsed between 2 dates*/

struct date
{
	int month;
	int day;
	int year;
};

long int calc_n(struct date mydate){
	long int n;

	if (mydate.month <= 2)
	{
		mydate.year = mydate.year -1 ;
		mydate.month = mydate.month + 13 ;
	}
	else
		mydate.month = mydate.month + 1	;

	n = (1461 * mydate.year) / 4 + (153 * mydate.month) / 5 + mydate.day ;

	return (n); 

}

main(){
	struct date d1, d2;
	long int n1, n2;

	printf("Enter first date (mm dd yyyy): ");
	scanf("%li %li %li", &d1.month, &d1.day, &d1.year);

	n1 = calc_n (d1);
	//printf("N1 = %li\n", n1 );

	printf("Enter second date (mm dd yyyy): ");
	scanf("%li %li %li", &d2.month, &d2.day, &d2.year);
	n2 = calc_n (d2);
	//printf("N1 = %li\n", n1 );

	printf("Difference is: %li\n", n2 - n1);
}
