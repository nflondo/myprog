#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/list.h>
/* structure */
struct birthday{
	int day;
	int month;
	int year;
	struct list_head list;
}

struct birthday birthday_list;

/* This function is called when the module is loaded. */
int simple_init(void)
{
	struct birthday *person, *ptr;
	unsigned int i;
	printk(KERN_INFO "Loading simple Module\n");
	static LIST_HEAD(birthday_list)	
	for(i=0; i<5; ++i){
		person = kmalloc(sizeof(*person), GFP_KERNEL);
		person->day = 2;
		person->month = 8;
		person->year = 1995;
		INIT_LIST_HEAD(&person->list);
		/* another macro */
		list_add_tail(&(&person->list), &(birthday_list.list));
	}
	printk(KERN_INFO "Traversing the list using list_for_each_entry()n");
	list_for_each_entry(ptr, &birthday_list.list, list){
	//access the member from ptr
	/* on each iteration ptr points to the next birthday struct*/
      printk(KERN_INFO "day: %d; month: %d; year: &dn", ptr->day, ptr->month, ptr->year);
  
	}
	printk(KERN_INFO "n");
	return 0;	
}

/* This function is called when the module is removed */
void simple_exit(void)
{
	printk(KERN_INFO "Removing simple Module\n");
	struct birthday *ptr, *next
	
	list_for_each_entry_safe(ptr,next,&birthday_list.list,list){
		/* on each iteration ptr points to the next birthday struct*/
		printk(KERN_INFO "freeing node %dn", ptr->day);
		list_del(&ptr->list);
		kfree(ptr);
	}
	return 0;
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
