#ifndef _ACOREFUNCS_H
#define _ACOREFUNCS_H

#include <stdint.h>

void      os_halt(void);
void      os_cli(void);
void      os_sti(void);
void      os_io_wait(void);
void      os_outb(uint16_t port, uint8_t data);
uint8_t   os_inb(uint16_t port);
void      os_outw(uint16_t port, uint16_t data);
uint16_t  os_inw(uint16_t port);
void      os_outd(uint16_t port, uint32_t data);
uint32_t  os_ind(uint16_t port);

#endif
