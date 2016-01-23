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

//core drivers
#include "Keyboard.h"

//etc 
#define KERNEL_VERSION "0.2.4"
#define KERNEL_BUILDNUMBER 1 // decided to add a build number
#define KERNEL_VENDOR "STICKOS"  
#define KERNEL_AUTHORS "kofikofi123;Jonathan;Customailty"

//Jonathan and Customailty helped me also 

//Gdt.h
void           	init_gdt(void);

//Idt.h
void           	init_idt(void);

//ACOREFuncs.h
void           	os_cli(void);
void           	os_sti(void);
void           	os_halt(void);
void           	os_outb(uint16_t port, uint8_t data);
uint8_t        	os_inb(uint16_t port);
void           	os_outw(uint16_t port, uint16_t data);
uint16_t       	os_inw(uint16_t port);
void           	os_outd(uint16_t port, uint32_t data);
uint32_t       	os_ind(uint16_t port);
void            os_cpuid(void);
uint8_t         os_cpuid_supported(void);
//Pic.h   
void 	          pic_eoi(uint8_t irq);
uint16_t       	pic_irr(void);
uint16_t       	pic_isr(void);
void 			      mask_irq(uint8_t irq, uint8_t value);

//Other.h
//  void   	      	flush_idt(void);
void 	          flush_gdt(void);
void            get_registers(struct registers_t*);



//Keyoard.h 
void    	      install_keyboard(void);
void 	          keyboard_event(void);

//Pci.h
void            init_pci(uint16_t si);
void            getDevice(struct Device* device_t, uint8_t bus, uint8_t device);

/*Terminal.h - Decrepit 
void 			init_textmode(void);
void 			clear_screen(void);
void 			print_char(const char character);
void 			print_string(const char* string);
void 			print_number(uint32_t number);
*/
//Pit.h
void            install_pit(void);
void            pit_event(void);
void            reloadRegister(uint8_t channel, uint8_t mode, uint16_t reload_value);

//enum DeviceType  getDeviceType(uint8_t bus, uint8_t device);
#endif
