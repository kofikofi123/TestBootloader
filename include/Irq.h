#ifndef _IRQ_H
#define _IRQ_H

#include <stdint.h>

void irq0(void);
void irq1(void);
void irq2(void);
void irq3(void);
void irq4(void);
void irq5(void);
void irq6(void);
void irq7(void);
void irq8(void);
void irq9(void);
void irq10(void);
void irq11(void);
void irq12(void);
void irq13(void);
void irq14(void);
void irq15(void);

typedef void(*irq_handler_t)(void);

void install_irq(uint16_t index, irq_handler_t handler);
void remove_irq(uint16_t index);
void mask_ireq(uint16_t index);
#endif