#include "include/Sys.h"

int kernel_main(void){
    struct registers_t registers;
    
    get_registers(&registers);
    
	init_gdt();
	init_idt();
	init_pic();
	
	install_keyboard();
	//install_timer();
	
	os_sti();
	
	while (1){}
}

