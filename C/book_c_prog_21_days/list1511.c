 /* Demonstration of temporary filenames. */

 #include <stdio.h>

 int main(void)
 {
     char buffer[10], *c;

     /* Get a temporary name in the defined buffer. */

     tmpnam(buffer);

     /* Get another name, this time in the function's */
     /* internal buffer. */

     c = tmpnam(NULL);

     /* Display the names. */

     printf("Temporary name 1: %s\n", buffer);
     printf("Temporary name 2: %s\n", c);
	 
	 return 0;
}
