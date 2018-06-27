#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/list.h>

 

MODULE_LICENSE("GPL");

MODULE_DESCRIPTION("hello");

MODULE_AUTHOR("Liu Feipeng/roman10");

 

struct Person {

    char name[30];

    unsigned int weight;

    unsigned char gender;

    struct list_head list; /* kernel's list structure */

};

 

struct Person personList;

 

int init_module() {

    struct Person *aNewPerson, *aPerson;

    unsigned int i;

 

    printk(KERN_INFO "initialize kernel modulen");

    INIT_LIST_HEAD(&personList.list);    //or LIST_HEAD(mylist); 

 

    /* adding elements to mylist */

    for(i=0; i<5; ++i){

        aNewPerson = kmalloc(sizeof(*aNewPerson), GFP_KERNEL);

        strcpy(aNewPerson->name, "roman10");

        aNewPerson->weight = 130*i;

        aNewPerson->gender = 1;

        INIT_LIST_HEAD(&aNewPerson->list);

        /* add the new node to mylist */

        list_add_tail(&(aNewPerson->list), &(personList.list));

    }

    printk(KERN_INFO "traversing the list using list_for_each_entry()n");

    list_for_each_entry(aPerson, &personList.list, list) {

        //access the member from aPerson

        printk(KERN_INFO "Person: %s; weight: %d; gender: %sn", aPerson->name, aPerson->weight, aPerson->gender==0?"Female":"Male");

    }

    printk(KERN_INFO "n");

 

    return 0;

}

 

void cleanup_module() {

    struct Person *aPerson, *tmp;

    printk(KERN_INFO "kernel module unloaded.n");

    printk(KERN_INFO "deleting the list using list_for_each_entry_safe()n");

    list_for_each_entry_safe(aPerson, tmp, &personList.list, list){

         printk(KERN_INFO "freeing node %sn", aPerson->name);

         list_del(&aPerson->list);

         kfree(aPerson);

    }

}

module_init(init_module);
module_exit(cleanup_module);
