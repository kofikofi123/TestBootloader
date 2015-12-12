#include "../include/Pic.h"
#include "../include/ACOREFuncs.h"
#include "../include/Irq.h"
#include <stdint.h>


static void pic_remap(uint8_t offset, uint8_t offset2);


void init_pic(void){
	pic_remap(0x20, 0x28);
	os_outb(PIC1_DATA, ~(0b00000011));
	os_outb(PIC2_DATA, 0xFF);
	return;
}

void mask_irq(uint8_t irq, uint8_t value){
	uint8_t pic = PIC1_DATA;
	
	if (irq > 7){
		pic = PIC2_DATA;
	}
	
	os_outb(pic, value);
	return;
}

void pic_eoi(uint8_t irq){
	if (irq > 7)
		os_outb(PIC2_COMMAND, PIC_EOI);
	os_outb(PIC1_COMMAND, PIC_EOI);
	return;
}

static void pic_remap(uint8_t offset, uint8_t offset2){
	os_outb(PIC1_COMMAND, 0x11);
	os_io_wait();
	os_outb(PIC2_COMMAND, 0x11);
	os_io_wait();
	os_outb(PIC1_DATA, offset);
	os_io_wait();
	os_outb(PIC2_DATA, offset2);
	os_io_wait();
	os_outb(PIC1_DATA, 4);
	os_io_wait();
	os_outb(PIC2_DATA, 2);
	os_io_wait();
	os_outb(PIC1_DATA, 0x01);
	os_io_wait();
	os_outb(PIC2_DATA, 0x01);
	
	return;
}

uint16_t pic_irr(void){
	os_outb(PIC1_COMMAND, PIC_IRR);
	os_io_wait();
	os_outb(PIC2_COMMAND, PIC_IRR);
	os_io_wait();
	
	return ((os_inb(PIC2_DATA) << 8) | os_inb(PIC1_DATA));
}

uint16_t pic_isr(void){
	os_outb(PIC1_COMMAND, PIC_ISR);
	os_io_wait();
	os_outb(PIC2_COMMAND, PIC_ISR);
	os_io_wait();
	
	return ((os_inb(PIC2_DATA) << 8) | os_inb(PIC1_DATA));
}
