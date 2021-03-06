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
    
/*remove_string removes a specified number of characters from a char string*/
char remove_string (char source[], int start, int count){

    int i, j;
    for ( i = start, j = 0; j <= count; ++i, ++j )
    {
        if (source[i] == '\0')
            break;
        else
            source[i]='\0';  // Deleting array element    
    
    } 
    result[ j+1 ]= '\0';
    
    return (result);

}

/*insert one char string into another*/
char insert_string (char source[], char stringtoinsert[], int position){
    int j=0;
    while ( source[position] != '\0' ){
        source[position]=stringtoinsert[j]
        ++position;
        ++j;
    }
    return (source);
}

