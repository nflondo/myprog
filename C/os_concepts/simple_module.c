#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
/* structure */
struct birthday{
	int day;
	int month;
	int year;
	struct list_head list;
}

/* macros */
static LIST_HEAD(birthday_list)

struct birthday *ptr;
/* create and initalize instances of struct birthday */
struct birthday *person;

list_for_each_entry(ptr, &birthday_list, list){
	/*on each iteration ptr points to the next birthday struct*/
}

/* This function is called when the module is loaded. */
int simple_init(void)
{
	printk(KERN_INFO "Loading Module\n");
	
	person = kmalloc(sizeof(*person), GFP_KERNEL);
	person->day = 2;
	person->month = 8;
	person->year = 1995;
	INIT_LIST_HEAD(&person->list);
	/* another macro */
	list_add_tail(&person->list, &birthday_list);
	return 0;	
}

/* This function is called when the module is removed */
void simple_exit(void)
{
	printk(KERN_INFO "Removing Module\n");
	/* macro */
	list_del(struct list_head *element)
	struct birthday *ptr, *next
	
	list_for_each_entry_safe(ptr,next,&birthday_list,list){
		/* on each iteration ptr points to the next birthday struct*/
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
