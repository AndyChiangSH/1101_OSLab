#include <linux/module.h>

extern int symbol_variable;

module_param(symbol_variable, int, 0);
MODULE_PARM_DESC(symbol_variable, "Variable");

int init_module(void) {
	printk(KERN_INFO "Module C insert successfully\n");
	printk(KERN_INFO "The given param is: %d\n", symbol_variable);
	
	return 0;
}

void cleanup_module(void) {
	printk(KERN_INFO "Module C remove successfully\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andy");
MODULE_DESCRIPTION("Lab05");
