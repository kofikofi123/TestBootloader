#include <stdint.h>
#include "../include/ACOREFuncs.h"
#include "../include/VGA.h"

int8_t vga_map_memory(uint8_t index){//haven't actually tested this
	//RAM enabled bit setting
	uint8_t reg = os_inb(0x3CC);
	reg |= 2;
	os_outb(0x3C2, reg);
	
	if ((os_inb(0x3CC) & 2) != 2){
		return -1;
	}
	
	//Memory map
	os_outb(0x3CE, 0x06);
	os_io_wait();
	reg = os_inb(0x3CE);
	os_io_wait();
	reg = reg | (index << 2);
	os_outb(0x3CE, reg);
	
	
	if ((os_inb(0x3CE) & 12) != 2){
		return -1;
	}
	return 1;
}


void load_reg1(void){
	
}
