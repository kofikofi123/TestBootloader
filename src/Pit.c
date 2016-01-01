#include <stdint.h>
#include "../include/Pit.h"
#include "../include/Irq.h"

void install_pit(void){
	install_irq(0, pit_event);
}


void pit_event(void){
	
}