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
