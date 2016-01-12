#include "include/Sys.h"

int kernel_main(void){
    //si should have the adress the the memory struture
    
    
    
	init_gdt();
	init_idt();
	init_pic();
	
	install_keyboard();
	//install_timer();
	
	os_sti();
	
	while (1){}
}

