#include <linux/module.h>

int symbol_function(int x) {
	if(x > 100)
		return 1;
	else if(x < 100)
		return -1;
	else
		return 0;
}

int init_module(void) {
	printk(KERN_INFO "Module A insert successfully\n");
	return 0;
}

void cleanup_module(void) {
	printk(KERN_INFO "Module A remove successfully\n");
}

EXPORT_SYMBOL(symbol_function);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andy");
MODULE_DESCRIPTION("Lab05");
