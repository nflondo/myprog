#include <stdio.h>
struct entry{
    
        int value;
        struct entry *prev;
        struct entry *next;
    };
    
/* Insert  new entry into link list*/
struct entry insert_entry (struct entry *new, struct entry *place){

    //struct entry *list_start = &n1;

     new.next = place.next;
     place.next = &new;
}
main(){    
    struct entry insert_entry (struct entry *new, struct entry *place);
    struct entry n1,n2,n3;
    struct entry *list_pointer;
    
    n1.value = 100;
    n1.next = &n2;
    
    n2.value = 200;
    n2.next = &n3;
    
    n3.value = 300;
    n3.next = 0;
    
    n1.prev = 0;
    n2.prev = &n1;
    n3.prev = &n2;
    
    //Forward
    list_pointer=&n1;
    while ( list_pointer ){
    
        printf("%i ", list_pointer->value);
        list_pointer = list_pointer->next;
    }
    printf("\n");
    // Insert new element
    struct entry n2_a;
    struct entry *p_n2_a = &n2_a;
    struct entry *p_n2 = &n2;
    
    n2_a.value = 250;
    
    insert_entry (*p_n2_a, *p_n2);    
    
    //Forward 
    list_pointer=&n1;
    while ( list_pointer ){
    
        printf("%i ", list_pointer->value);
        list_pointer = list_pointer->next;
    }
    printf("\n");
    //backward
    list_pointer = &n3;
    while ( list_pointer ){
        printf("%i ", list_pointer->value);
        list_pointer = list_pointer->prev;
    
    }
    printf("\n");
}
