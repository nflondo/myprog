 /* Using the strncpy() function. */

 #include <stdio.h>
 #include <string.h>

 char dest[]   = "..........................";
 char source[] = "abcdefghijklmnopqrstuvwxyz";

 int main(void)
 {
     size_t n;
	 char   buffer [80];

     while (1)
     {
         puts("Enter the number of characters to copy (1-26)");
         scanf("%d", &n);

         if (n > 0 && n< 27)
             break;

         /* Clear extra characters from stdion. */
         fgets(buffer, 80, stdin);
     }

     printf("Before strncpy destination = %s\n", dest);

     strncpy(dest, source, n);

     printf("After  strncpy destination = %s\n", dest);
     return 0;
 }
