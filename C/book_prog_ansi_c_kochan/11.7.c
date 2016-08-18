/* List traversal*/
#include <stdio.h>
main()
{
    struct entry{
          int      value;
          struct entry *next;
     };
    struct entry n1, n2, n3;
    struct entry *list_pointer = &n1;

    n1.value = 100;
    n1.next = &n2;
 
     n2.value = 200;
    n2.next = &n3;

     n3.value = 300;
    n3.next = 0;

    while ( list_pointer != 0 ){
          printf ("%i\n", list_pointer->value );
          list_pointer = list_pointer->next;
     }

}

