#ifndef _SYS_H

#define _SYS_H

#include <stdint.h>

//core
#include "Idt.h"
#include "Gdt.h"
#include "Pic.h"
#include "Pci.h"
#include "ACOREFuncs.h"
#include "Pit.h"
#include "Other.h"
#include "Memmap.h"

//core drivers
#include "Keyboard.h"

//etc 
#define KERNEL_VERSION "0.2.4"
#define KERNEL_BUILDNUMBER 10 // decided to add a build number
#define KERNEL_VENDOR "STICKOS"  
#define KERNEL_AUTHORS "kofikofi123;Jonathan;Customality"

//Jonathan and Customality helped me also 

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
extern void            	os_cpuid(void);
extern uint8_t			os_cpuid_supported(void);

//Pic.h   
extern void 	        pic_eoi(uint8_t irq);
extern uint16_t       	pic_irr(void);
extern uint16_t       	pic_isr(void);
extern void 			mask_irq(uint8_t irq, uint8_t value);

//Other.h
//  void   	      	flush_idt(void);
extern void 	        flush_gdt(void);
extern void            	get_registers(struct registers_t*);



//Keyoard.h 
extern void    	    	install_keyboard(void);
extern void 	    	keyboard_event(void);

//Pci.h
extern void             init_pci(void);
extern void             getDevice(struct Device* device_t, uint8_t bus, uint8_t device);
extern void             getDevices(struct Device** device_t, uint8_t bus, uint8_t device);
extern enum             DeviceType getDeviceType(uint8_t bus, uint8_t device);

/*Terminal.h - Decrepit 
void 			init_textmode(void);
void 			clear_screen(void);
void 			print_char(const char character);
void 			print_string(const char* string);
void 			print_number(uint32_t number);
*/
//Pit.h
extern void           	install_pit(void);
extern void           	pit_event(void);
extern void           	reloadRegister(uint8_t channel, uint8_t mode, uint16_t reload_value);

//Memmap
extern void 			sort_mapped_memory(void);
#endif
