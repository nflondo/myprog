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
    
    while ( s1[i]==s2[i] && s1[i] != '\0' && s2[i] != '\0' )
        ++i;
    
    if ( s1[i] == '\0' && s2[i] == '\0' )
        answer = 1; // Strings equal
    else
        answer = 0; // not equal
        
    return (answer);

} // equal strings

/*Look up a word in a dictionary*/
int lookup (struct entry dictionary[], char search[], int entries){
    //int equal_strings (char s1[], char s2[]);
    int i;
    
    for (i=0; i < entries; ++i)
        if ( equal_strings (search, dictionary[i].word) )
            return (i);
            
    return (-1);

} // lookup

main(){

    struct entry dictionary[10] =
    {{ "aardvark", "a burrowing African mammal"     },
     { "abyss", "a bottomless pit"                  },
     { "acumen", "mentally sharp; keen"             }};   
    
    char word[10];
    int entries = 3;
    int entry_number;
    //int lookup (struct entry dictionary[], char search[], int entries);

    printf("Enter word: ");
    scanf("%9s", word);
    
    entry_number = lookup (dictionary, word, entries);
    
    if ( entry_number != -1 )
        printf ("%s\n", dictionary[entry_number].definition);
    else
        printf ("Sorry, that word is not in my dictionary.\n");

} // main
