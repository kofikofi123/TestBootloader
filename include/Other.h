#ifndef _OTHER_H
#define _OTHER_H

//declarations - structures
//(eflags, eax, ecx, edx, ebx, esp, ebp, esi, edi, ds, es, gs, fs, ss)
//(cs, ss, fs, gs, es, ds, edi, esi, ebp, esp, ebx, edx, ecx, eax, eflags);
struct registers_t {
    uint16_t cs, ss, fs, gs, es, ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t eflags;
}__attribute__((packed));

//declarations - functions
//void flush_idt(void);
void flush_gdt(void);
void get_registers(struct registers_t*);

#endif