#include <stdio.h>
/*Day of the week a particular date falls on*/

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

int day_of_week (long int n){
    int day;
    day = (n - 621049) % 7;
    
    return (day);
}

main(){
	struct date d1;
	long int n1;
	int day_number;

	printf("Enter date (mm dd yyyy): ");
	scanf("%li %li %li", &d1.month, &d1.day, &d1.year);

	n1 = calc_n (d1);
	
	day_number = day_of_week (n1);
	char *day_name[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	printf("Day of week: %s\n", day_name[day_number]);
	
}
