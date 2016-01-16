#include "../include/Keyboard.h"
#include "../include/Irq.h"
#include "../include/ACOREFuncs.h"

static int* test = (int*)0xB8000;

void install_keyboard(void){
	install_irq(1, keyboard_event);
	return;
}


void keyboard_event(void){
	*test = 0x07690748; //test lol
	test += 4;
	return;
}

