#ifndef _MEMTOOLS_H
#define _MEMTOOLS_H

#include <stdint.h>

void memset(void* buffer, uint8_t value, uint32_t size);
void memcpy(void* buffer, const void* buffer2, uint32_t size);
void memmove(void* buffer, void* buffer2, uint32_t size);


#endif
