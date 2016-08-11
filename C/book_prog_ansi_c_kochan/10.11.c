#include <stdio.h>
/*Function to convert string to an integer*/
int string_to_integer (char string[]){
    int i, integer_value, result = 0;
    
    for ( i = 0; string[i] >= '0' && string[i] <= '9'; ++i ){
    
        if ( string[i] == '-' ){
        integer_value = string[i] - '0';
        integer_value = integer_value * (-1);
        result = result * 10 + integer_value;
        //result = result * (-1);
        }
        else  {  
        integer_value = string[i] - '0';
        result = result * 10 + integer_value;

        }
    } // for
    
    return (result);
} // string_to_integer

main(){
    printf ("%i\n", string_to_integer("-245"));
    printf ("%i\n", string_to_integer("100") + 25);
    printf ("%i\n", string_to_integer("-13x5"));
}

