#include "../include/Keyboard.h"
#include "../include/Irq.h"
#include "../include/ACOREFuncs.h"


void install_keyboard(void){
	install_irq(1, keyboard_event);
	return;
}


void keyboard_event(void){
	os_cli();
	os_halt();
	return;
}

