/* List traversal*/
#include <stdio.h>
struct entry{
    int      value;
    struct entry *next;
};

/* function to remove and entry from a linked list */
struct entry remove_entry (struct entry *place){
    //struct entry list_head;
    //list_head.next = &place

   //place.next = element.next ;  
}

/* Insert  new entry into link list*/
struct entry insert_entry (struct entry *new_node, struct entry *place){

     new_node->next = place->next;
     place->next = new_node;

}

main()
{

    struct entry n1, n2, n3, n4;
    struct entry *list_pointer = &n1;
    struct entry *p_n4 = &n4;
    struct entry *p_n1 = &n1;
    n1.value = 100;
    n1.next = &n2;
 
     n2.value = 200;
    n2.next = &n3;

     n3.value = 300;
    n3.next = 0;
    
    n4.value = 400;

    while ( list_pointer != 0 ){
          printf ("%i\n", list_pointer->value );
          list_pointer = list_pointer->next;
     }
     
     insert_entry(p_n4, p_n1 );
     
     list_pointer = &n1;
     printf ("After insert \n");
     while ( list_pointer != 0 ){
          printf ("%i\n", list_pointer->value );
          list_pointer = list_pointer->next;
     }

}

