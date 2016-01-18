#include <stdint.h>
#include "../include/ACOREFuncs.h"
#include "../include/Pit.h"
#include "../include/Irq.h"

uint16_t reload_value;

void install_pit(void){
	install_irq(0, pit_event);
	reload_value = 5;
	return;
}

void reloadRegister(uint8_t channel, uint8_t mode, uint16_t reload_value){
    os_outb(0x43, FORMATWRITEOP(channel, 0, mode, 0));
    os_io_wait();
    os_outb(0x40, reload_value & 0xFF);
    os_io_wait();
    os_outb(0x40, (reload_value >> 8) & 0xFF);
    return;
}


void pit_event(void){
	//pit event
	return;
}