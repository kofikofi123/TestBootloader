#ifndef _IDT_H
#define _IDT_H

#include "Irq.h"
#include <stdint.h>

struct IDT_pointer {
  uint16_t size;
  uint32_t offset;
}__attribute__((packed));
//0x001006E0
//E0 06 08 00 00 8E 01 00
//0x1006E0
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
//push ds 
//push es 
//push gs
//push fs
//push ss
//latr~~
//popad
//add esp, 4 
//iret
//( edi, esi, ebp, esp, ebx, edx, ecx, eax, vendor_code, error_code, eip, eflags)
struct Interrupt_parameters {
	uint16_t ss, fs, gs, es, ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint16_t vendor_code, error_code;
	uint32_t eip;
	uint32_t eflags;
}__attribute__((packed));


void init_idt(void);

#endif
