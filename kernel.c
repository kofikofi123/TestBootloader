#include "include/Sys.h"

int kernel_main(void){
    
	init_gdt();
	init_idt();
	init_pic();
	
	install_keyboard();
	//install_timer();
	
	os_sti();
	
	
    struct registers_t registers;
    
    //get_registers(&registers);
	
	while (1){
	    os_halt();
	}
}

