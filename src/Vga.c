#include <stdint.h>
#include "../include/ACOREFuncs.h"
#include "../include/VGA.h"
/*
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
	
}*/

void write_indexbased_registers(void* registers, uint16_t num_registers, uint16_t address_port, uint16_t data_port){
    uint8_t* casted = (uint8_t*)registers;
    for (uint16_t x = 0; x < num_registers; x++){
        os_outw(address_port, x);
        os_io_wait();
        os_outb(data_port, *casted++);
        //do checking later if this actually works
    }
}

void flush_indexbased_registers(void* registers, uint16_t num_registers, uint16_t address_port, uint16_t data_por){
    uint8_t* casted = (uint8_t*)registers;
    for (uint16_t x = 0; x < num_registers; x++){
        os_outw(address_port, x);
        os_io_wait();
        *casted++ = os_inb(data_port);
    }
}