#ifndef _OTHER_H
#define _OTHER_H

//declarations - structures
struct registers_t {
    uint32_t eax, ebx, ecx, edx, esi, edi, esp;
    uint16_t ds, es, gs, bs, fs;
    uint32_t eflags;
}__attribute__((packed));

//declarations - functions
//void flush_idt(void);
void flush_gdt(void);
void get_registers(struct registers_t*);


#endif