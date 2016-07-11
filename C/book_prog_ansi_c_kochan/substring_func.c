/* extracts a portion of a character string */
char substring (char source[], start, count, char result[]){
    int i, j;
    for ( i = start, j = 0; j <= count; ++i, ++j )
    {
        if (source[i] == '\0')
            break;
        else
            result[j]=source[i];    
    
    } 
    result[ j+1 ]= '\0';
    
    return (result);
}

/* Determine if one character string exists inside another string*/
char find_string (char source[], char findme[]){

    int i, location;
    
    while ( source[i] != '\0' )
    {
        if (source[i] == findme[i])
        {
            location = i;
            if (findme[i] == '\0')
                return 1;  // complete string found
            else 
                return 0; // not complete string found
         }       
    ++i;
    }
