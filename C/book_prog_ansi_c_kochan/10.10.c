/*Dictionary look up program #2*/
/****************************/
#include <stdio.h>

struct entry{
    char word[10];
    char definition[50];
};

/* Function to compare two char strings */
int compare_strings (char s1[], char s2[])
{
    int i=0, answer;
    
    while ( s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' )
        ++i;
    
    if ( s1[i] < s2[i] )
        answer = -1;    /* s1 < s2 */
    else if ( s1[i] == s2[i] )
        answer =0;      // s1 == s2
    else
        answer =1;      // s1 > s2
        
    return (answer);
    
}

/* Function to look up a word inside a dictionary */
int lookup (struct entry dictionary[], char search[], int entries)
{
    int low=0;
    int high = entries -1;
    int mid, result;

    while ( low <= high )
    {
        mid = (low + high) / 2;
        result = compare_strings (dictionary[mid].word, search);
        
        if ( result == -1 )
            low = mid + 1;
        else if ( result == 1 )
            high = mid -1;
        else
            return (mid);  /* found it */
    }
    retun (-1); // not found
}
struct entry dictionary_sort (struct entry dictionary[], struct entry tempdict[]){
    int i = 0;
//    struct entry tempdict[6];
    while ( dictionary[i].word != '\0' ){
        if ( dictionary[i].word > dictionary[i+1].word )
        {
            dictionary[i].word = tempdict[i].word;
            dictionary[i].word = dictionary[i+1].word;
            tempdict[i] = dictionary [i+1].word;
        } // if
     ++i;
    } // while    
    
    return (dictionary);
}

main(){
    struct entry dictionary[6] = 
        {{ "aardvark",  "a burrowing African mammal"    },
         { "cat",     "domestic feline"                 },
         { "abyss",     "a bottomless pit"              },
         { "bee",    "flying insect with stings"        },
         { "addle",     "to become confused"            }};

    int entries = 4;
    char word[10];
    int entry_number, i;
    
    
    for (i = 0; i < entries; ++i){
        printf ("%s\n", dictionary[i].word);    
    }
    //printf ("Enter word:  ");
    //scanf ("%9s", word);   
    
    //entry_number = lookup (dictionary, word, entries);
    
    //if ( entry_number != -1 )
      //  printf ("%s\n", dictionary[entry_number].definition);
    //else
      //  printf ("Sorry, that word is not in the dictionary.\n");
    
} // end main
