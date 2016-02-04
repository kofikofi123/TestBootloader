#include "include/Sys.h"

int kernel_main(void){
	//__asm__ volatile("pushad");
	
	init_gdt();
	init_idt();
	init_pic();
	
	install_keyboard();
	//install_timer();
	
	os_sti();
	
	//__asm__ volatile("popad");
	//kernel_sleep()
	//sort_mapped_memory();
	
	while (1){
	    os_halt();
	}
}

