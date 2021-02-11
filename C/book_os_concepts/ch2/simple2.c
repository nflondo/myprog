#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/types.h>

struct birthday{
       int day;
       int month;
       int year;
       struct list_head list;
};
struct birthday *createPerson(int d, int m, int y);
/*void printList(struct birthday *start); */
//static LIST_HEAD(birthday_list);
struct birthday birthday_list;

/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");       
       static LIST_HEAD(birthday_list);
       struct birthday *person, *ptr, *next;
       //GFP_KERNEL indicates routine kernel memory allocation
       person = (struct birthday *) kmalloc(sizeof(struct birthday), GFP_KERNEL);
       person->day = 2;
       person->month =8;
       person->year = 1995;
       // INIT_LIST_HEAD initializes the list member in struct birthday
       INIT_LIST_HEAD(&person->list);
       // list_add_tail is a macro that add an instance to the end of the linked list
       list_add_tail(&person->list, &birthday_list);
       person = createPerson(1,2,1980);
       list_add_tail(&person->list, &birthday_list);
       person = createPerson(3,8,1981);
       list_add_tail(&person->list, &birthday_list);
       //list_for_each_entry macro traverses the linked list
       list_for_each_entry(ptr, &birthday_list, list){
              printk(KERN_INFO "%d %d %d\n",ptr->day, ptr->month, ptr->year);
       }

       // list_for_each_entry_safe is a macro that traverses the list but maintains
       // the value of the next pointer of the item being deleted (this is necessary
       // for preserving the structure of the list)
       /*
       list_for_each_entry_safe(ptr,next,&birthday_list,list){
              printk(KERN_INFO "Entering delete loop...\n");
              //list_del is a macro to remove element from list
              list_del(&ptr->list);
              kfree(ptr);
       }
       */
       return 0;
}

struct birthday *createPerson(int d, int m, int y){
       struct birthday *ptr;
       ptr = (struct birthday *) kmalloc(sizeof(struct birthday), GFP_KERNEL);
       ptr->day = d;
       ptr->month = m;
       ptr->year = y;
       return ptr;
}
/*
void printList(struct birthday *start){
       struct birthday *ptr = start;
       while(ptr!=NULL){
              printk(KERN_INFO "%d %d %d\n",ptr->day, ptr->month, ptr->year);
       }
}
*/
/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
    struct birthday *ptr, *next;
    
    list_for_each_entry_safe(ptr,next->list,&birthday_list,list){
        list_del(&ptr->list);
        kfree(ptr);
    } 
    return 0;
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

