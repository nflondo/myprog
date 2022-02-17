// Library Catalog Card.  Shows how to use structure and strings/chars in it.
#include <cstdio>

struct CatalogCard {
    const char * title;
    const char * author;
    const char * publisher;
    const char * subject;
    const char * isbn;
    const char * oclc;
    short int ddc1; //Dewey decimal 2341.45 part one
    short int ddc2; //part 2
    short int year_pub;
    short int year_acq;
    short int quantity;
};

int main(){
    CatalogCard lc1 = {
        "The CGI Book", "William E. Weinman", "New Riders",
        "CGI (Computer Network Protocol)",
        "1562055712 9781562055714", "477166381",
        510, 78, 1996, 1997, 2
    };

    printf("Title: %s\n", lc1.title);
    printf("Author: %s\n", lc1.author);
    printf("Publisher: %s\n", lc1.publisher);
    printf("Subject: %s\n", lc1.subject);
    printf("ISBN: %s\n", lc1.isbn);
    printf("WorldCat (OCLC): %s\n", lc1.oclc);
    printf("Dewey Decimal: %d.%d\n", lc1.ddc1, lc1.ddc2);
    printf("Year Published: %d\n", lc1.year_pub);
    printf("Year acquired: %d\n", lc1.year_acq);
    printf("Quantity: %d\n", lc1.quantity);
    return 0;
}