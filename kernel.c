#include "include/Sys.h"

int kernel_main(void){
	//__asm__("pushad");
	init_gdt();
	init_idt();
	init_pic();
	
	install_keyboard();
	//install_timer();
	
	os_sti();
	
	/*{
		const char* test1 = "kofi was here kofi";
		const char* test2 = "kofi";
		
		int32_t temp = string_find(test1, test2, 0, STRING_END); >kofi 
		int32_t temp2 = string_find(test1, test2, 4, STRING_END); >kofi
		uint32_t temp3 = string_len(test1); > length of test1 
		
	}*/
	
	while (1){
	    os_halt();
	}
}

