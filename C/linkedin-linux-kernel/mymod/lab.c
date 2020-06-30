#include <linux/module.h>
#include <linux/sched.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

MODULE_DESCRIPTION("Ch 3 challenge: lab.c");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nefi Munoz-Calderon");

static int number = 35;
static char *myword = "initial";

module_param(number, int, S_IRUGO);
MODULE_PARM_DESC(number, "An integer variable");
module_param(myword, charp, S_IRUGO); /* charp here defines a string in the module parameter*/
MODULE_PARM_DESC(myword, "A character variable");


int my_init_module(void)
{
	printk("lab.c: my_init_module()\n");
	printk("number=%d myword=%s\n", number, myword);
	return 0;
}
void my_cleanup_module(void)
{
	printk("lab.c: my_cleanup_module()\n");
}


module_init(my_init_module);
module_exit(my_cleanup_module);
