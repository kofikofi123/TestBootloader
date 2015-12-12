#include "include/Sys.h"

int main(void){

	init_gdt();
	init_idt();
	init_pic();
	
	install_keyboard();
	
	os_sti();
	/////////////////////////////
	//init_pci();
	
	while (1){}
}
