/*  In this problem you will continue developing the data feature which you 
started implementing in the previous problem. You will implement a "tomorrow" 
feature in the C programming language via a function called "advanceDay()". 
The function advanceDay() should take as input a date (stored in a struct date) 
and return the date of the following day. You do not have to take into account 
leap years (although you may if you wish to). That is, it is okay for your 
function to always return March 1 as the day following February 28, no matter 
the year.

You are provided with a familiar date structure definition, a main function as 
well as the function prototypes for the readDate(), printDate(), and advanceDate()
 functions. Do not modify any of the given code. Simply add your function 
 definitions underneath the main() function. For the readDate() and printDate() 
 functions you may simply copy and paste the code you developed in the previous 
 task.

My note: I heard in order to modify structure you have to pass a pointer to it.
In this case, struct today is not being modified?

*/
#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

/* add your function definitions here */
void readDate(struct date * datePtr){
    scanf("%d %d %d", &datePtr->year, &datePtr->month, &datePtr->day);// & is 
    // needed so scanf can write into it
}

void printDate(struct date d){
    // Print integer with a width of 2 and leading zeros for items with less than
    // two digits using the format specifier %02d
    printf("%02d/%02d/%d\n", d.month, d.day, d.year);    
}

struct date advanceDay(struct date mydate){    
    
    if (mydate.month == 2 && mydate.day == 28){
        mydate.day = 1;
        mydate.month += 1;
    } else if (mydate.day == 30 && (mydate.month == 4 || mydate.month == 6 || mydate.month == 9 || mydate.month == 11)){
        mydate.day = 1;
        mydate.month += 1;
    } else if (mydate.day == 31 && mydate.month == 12){
        mydate.day = 1;
        mydate.month = 1; 
        mydate.year += 1;
    } else if (mydate.day == 31){
        mydate.day = 1;
        mydate.month += 1;
    } else{
        mydate.day += 1;
    }

    /*if (mydate.day == 31){
        mydate.day = 1;
        mydate.month += 1;
    } else{
        mydate.day += 1;
    }
    */
    return mydate;
}