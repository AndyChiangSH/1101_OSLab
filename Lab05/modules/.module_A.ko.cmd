cmd_/home/andy/modules/module_A.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000  --build-id  -T ./scripts/module-common.lds -o /home/andy/modules/module_A.ko /home/andy/modules/module_A.o /home/andy/modules/module_A.mod.o;  true