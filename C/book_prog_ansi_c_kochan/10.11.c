#include <stdio.h>
/*Function to convert string to an integer*/
int string_to_integer (char string[]){
    int i=0, integer_value, result = 0;
    int flag = 0;
    
    if ( string[i] == '-' ){
        flag = 1;
        i = 1;
    }
        
    while ( string[i] >= '0' && string[i] <= '9'){
    
        integer_value = string[i] - '0';
        result = result * 10 + integer_value;
        ++i;
        
    } 
    
    if ( flag )
        result = -result;
        
    return (result);
} // string_to_integer

main(){
    printf ("%i\n", string_to_integer("-245"));
    printf ("%i\n", string_to_integer("100") + 25);
    printf ("%i\n", string_to_integer("-13x5"));
}

