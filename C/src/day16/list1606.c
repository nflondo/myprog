 /* The strncat() function. */

 #include <stdio.h>
 #include <string.h>

 char str2[] = "abcdefghijklmnopqrstuvwxyz";

 int main(void)
 {
     char str1[27];
     int n;

     for (n=1; n< 27; n++)
     {
         strcpy(str1, "");
         strncat(str1, str2, n);
         puts(str1);
     }
	 return 0;
 }
