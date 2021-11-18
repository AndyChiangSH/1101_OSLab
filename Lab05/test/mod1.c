#include <linux/module.h>

extern int symbol2;
int symbol1 = 1;

int init_module(void) {
	printk(KERN_INFO "mod1 insert! symbol1=%d, symbol2=%d", symbol1, symbol2);
	return 0;
}

void cleanup_module(void) {
	printk(KERN_INFO "mod1 remove!");
}

EXPORT_SYMBOL(symbol1);
