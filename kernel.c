#include "include/Sys.h"

int kernel_main(void){
  __asm__ volatile("pushad");
	
	init_gdt();
  init_idt();
	init_pic();
	
	install_keyboard();
	//install_timer();
	
	os_sti();
	
	__asm__ volatile("popad");
	/*
	struct registers_t registers;
	
	get_registers(&registers);
	
	unsigned char* mem_check = (unsigned char*)(register.esi & 0xFFFF);
	*/
	
	while (1){
	    os_halt();
	}
}

