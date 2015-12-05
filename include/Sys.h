#ifndef _SYS_H

#include <stdint.h>

#include "Idt.h"
#include "Gdt.h"
#include "Pic.h"
#include "Pci.h"
#include "ACOREFuncs.h"
#include "Other.h"

#include "Keyboard.h"

#define KERNEL_VERSION "0.2.1" //whops
#define KERNEL_VENDOR "STICKOS"  

//Gdt.h
extern void           	init_gdt(void);

//Idt.h
extern void           	init_idt(void);

//ACOREFuncs.h
extern void           	os_cli(void);
extern void           	os_sti(void);
extern void           	os_halt(void);
extern void           	os_outb(uint16_t port, uint8_t data);
extern uint8_t        	os_inb(uint16_t port);
extern void           	os_outw(uint16_t port, uint16_t data);
extern uint16_t       	os_inw(uint16_t port);
extern void           	os_outd(uint16_t port, uint32_t data);
extern uint32_t       	os_ind(uint16_t port);
//Pic.h 
extern void 	        pic_eoi(uint8_t irq);
extern uint16_t       	pic_irr(void);
extern uint16_t       	pic_isr(void);

//Other.h
extern void   	      	flush_idt(void);
extern void 	        flush_gdt(void);


//Keyoard.h 
extern void    	      	install_keyboard(void);
extern void 	        keyboard_event(void);

//Pci.h
extern void             init_pci(uint16_t si);
extern void             getDevice(struct Device* device_t, uint8_t bus, uint8_t device);
//extern enum DeviceType  getDeviceType(uint8_t bus, uint8_t device);
#endif
