#include <stdio.h>
int main() {
    char dataType = '0';
    int numberNeeded, totalSpace;
    int B, KB, MB; 

    scanf("%c %d", &dataType, &numberNeeded);
    if(dataType == 'i'){
        totalSpace = sizeof(int) * numberNeeded;        
    } else if(dataType == 's'){
        totalSpace = sizeof(short) * numberNeeded;
    } else if(dataType == 'c'){
        totalSpace = sizeof(char) * numberNeeded;
    } else if(dataType == 'd'){
        totalSpace = sizeof(double) * numberNeeded;
    }    
    
    if (totalSpace > 1000000){
//        printf("totalspace = %d\n " ,totalSpace);
        MB = totalSpace / 1000000 ;
        printf("%d MB and ", MB);
        totalSpace -=  MB * 1000000;
  //      printf("New totalspace = %d\n " ,totalSpace);
        KB = totalSpace / 1000;
        printf("%d KB and ", KB);
        totalSpace -=  KB * 1000;        
    //    printf("last totalspace = %d\n " ,totalSpace);
        B = totalSpace;
        printf("%d B", B);

    } else if (totalSpace > 1000)
    {
       KB = totalSpace / 1000;
        printf("%d KB and ", KB);
        totalSpace -=  KB * 1000; 
        B = totalSpace;
        printf("%d B", B);  
               
    } else
    {
        B = totalSpace;
        printf("%d B", B);
    }
    return 0;
}