#ifndef _PIC_H
#define _PIC_H

#define PIC1_COMMAND 0x20 
#define PIC1_DATA 0x21 
#define PIC2_COMMAND 0xA0
#define PIC2_DATA 0xA1
#define PIC_EOI 0x20 

#include <stdint.h>

void init_pic(void);
void pic_EOI(uint8_t irq);
uint16_t pic_irr(void);
uint16_t pic_isr(void);



#endif