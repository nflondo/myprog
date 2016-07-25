/*Dictionary look up program*/
/****************************/
#include <stdio.h>

struct entry{
    char word[10];
    char definition[50];
};

/* Function to determine if two strings are equal */
int equal_strings (char s1[], char s2[]){
    int i=0, answer;
    
    while ( s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' )
        ++i;
    
    if ( s1[i] == '\0' && s2[i] = '\0' )
        answer = 1; // Strings equal
    else
        answer = 0; // not equal
        
    return (answer);

} // equal strings
