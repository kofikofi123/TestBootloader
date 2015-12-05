#include "include/Sys.h"

int main(void){

	init_idt();
	
	*(volatile char*)0xB8000 = 0x43;
	
	
	init_pic();
	
	install_keyboard();
	
	os_sti();
	
	
	
	/////////////////////////////
	//init_pci();
	
	while (1){}
}
