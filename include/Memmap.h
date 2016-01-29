#ifndef _MEMMAP_H 
#define _MEMMAP_H

#include <stdint.h>

struct Memrange {
	uint64_t base;
	uint64_t length;
	uint32_t type;
	uint32_t acpi_attributes;
}__attribute__((packed));

void sort_mapped_memory(void);


#endif