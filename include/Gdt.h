#ifndef _GDT_H
#define _GDT_H

#include <stdint.h>

struct GDT_descriptor {
  uint16_t limit_low;
  uint16_t base_low;
  uint8_t base_middle;
  uint8_t access;
  uint8_t flags;
  uint8_t base_high;
}__attribute__((packed));

struct GDT_pointer { 
  uint16_t size;
  uint32_t offset;
}__attribute__((packed));

void init_gdt(void);

#endif
