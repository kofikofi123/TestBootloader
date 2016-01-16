#include "../include/Keyboard.h"
#include "../include/Irq.h"
#include "../include/ACOREFuncs.h"


void install_keyboard(void){
	install_irq(1, keyboard_event);
	return;
}

void reset_cpu(){//test
    while((os_inb(0x64) & 0b00000010) != 0b00000010);
    
    os_outb(0x64, 0xFE);
}
void keyboard_event(void){
    reset_cpu();
	return;
}

