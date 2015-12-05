#include "../include/Gdt.h"
#include "../include/Other.h"
#include <stdint.h>

struct GDT_pointer gdtp;
struct GDT_descriptor gdtd[3];

static void encode_gdt(uint8_t index, uint32_t base, uint32_t limit, uint8_t access, uint8_t flag);

void init_gdt(void){
	encode_gdt(0, 0, 0, 0, 0); //null descriptor
	encode_gdt(1, 0, 0x000FFFFF, 0x9A, 0xC0);
	encode_gdt(2, 0, 0x000FFFFF, 0x92, 0xC0);
	//todo: make userspace code and data segments and maybe add in stack and extra for graphics
	//not done
	  
	gdtp.size = sizeof(gdtd) - 1;
	gdtp.offset = (unsigned)&gdtd[0];
	  
	flush_gdt();

}

static void encode_gdt(uint8_t index, uint32_t base, uint32_t limit, uint8_t access, uint8_t flag){
	gdtd[index].limit_low = (limit & 0xFFFF);
	gdtd[index].base_low = (base & 0xFFFF);
	gdtd[index].base_middle = ((base >> 16) & 0xFF);
	gdtd[index].access = access;
	gdtd[index].flags = ((flag & 0xF0) | ((limit >> 16) & 0xFF));
	gdtd[index].base_high = ((base >> 24) & 0xFF);
	
	return;
}
