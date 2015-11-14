#include "include/Sys.h"

int main(void){ //idk I did int argc, char* argv[], must been high

	//init_gdt();
	init_idt();
	init_pic();
	
	os_sti();
	
	install_keyboard();
	
	//os_cli();
	//os_halt();
	
	/////////////////////////////
	//init_pci();
	
	while (1){}
}
