#include <linux/module.h>

extern int symbol_function(int);

int symbol_variable = 56;

int init_module(void) {
	printk(KERN_INFO "Module B insert successfully\n");
	printk(KERN_INFO "symbol_variable:%d\n", symbol_variable);
	printk(KERN_INFO "symbol_function(%d) = %d\n", symbol_variable, symbol_function(symbol_variable));
	return 0;
}

void cleanup_module(void) {
	printk(KERN_INFO "Module B remove successfully\n");
}

EXPORT_SYMBOL(symbol_variable);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andy");
MODULE_DESCRIPTION("Lab05");
