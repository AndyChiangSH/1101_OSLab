#include <linux/module.h>

extern int symbol1;
int symbol2 = 2;

int init_module(void) {
        printk(KERN_INFO "mod2 insert! symbol1=%d, symbol2=%d", symbol1, symbol2);
        return 0;
}

void cleanup_module(void) {
        printk(KERN_INFO "mod2 remove!");
}

EXPORT_SYMBOL(symbol2);

