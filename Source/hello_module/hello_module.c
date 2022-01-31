/***************************************************************************//**
*  \file       hello_module.c
*
*  \details    Simple hello world driver
*
*  \author     Jawad Ahmed
*
* *******************************************************************************/
#include <linux/module.h>	 /* Needed by all modules */
#include <linux/kernel.h>	 /* Needed for KERN_INFO */
#include <linux/init.h>	 /* Needed for the macros */
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jawad Ahmed <jawad2019@namal.edu.pk>");
MODULE_DESCRIPTION("A simple hello world module for linux operating system");
MODULE_VERSION("1.0");
/*
** Module Init function
*/
static int __init hello_world_init(void)
{
    printk(KERN_INFO "Welcome to Namal\n");
    printk(KERN_INFO "Hello World This is the Simple Module\n");
    printk(KERN_INFO "Kernel Module Inserted Successfully...\n");
    return 0;
}

/*
** Module Exit function
*/
static void __exit hello_world_exit(void)
{
    printk(KERN_INFO "Kernel Module Removed Successfully...\n");
}
 
module_init(hello_world_init);
module_exit(hello_world_exit);
 

