#ifndef _IDT_H
#define _IDT_H

#include "Irq.h"
#include <stdint.h>

struct IDT_pointer {
  uint16_t size;
  uint32_t offset;
}__attribute__((packed));

struct IDT_descriptor {
  uint16_t offset_low;
  uint16_t selector;
  uint8_t zero;
  uint8_t type;
  uint16_t offset_high;
}__attribute__((packed));


//push EFLAGS
//push CS 
//push EIP
//push ERROR_CODE
//push VENDOR_CODE
//pushad
//latr
//popad
//add esp, 
struct Interrupt_parameters {
	uint16_t ss, gs, fs, es, ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint16_t vendor_code, error_code;
	uint32_t eip;
	uint16_t cs;
	uint32_t eflags;
}__attribute__((packed));


extern irq_handler_t irqs[15];

void init_idt(void);

#endif
