#include "../include/ACOREFuncs.h"
#include <stdint.h>


inline void os_halt(void){
  __asm__("hlt");
  return;
}

inline void os_cli(void){
  __asm__("cli");
  return;
}

inline void os_sti(void){
  __asm__("sti");
  return;
}

inline void os_io_wait(void){
		 __asm__("jmp f1\n"
				 "f1: jmp f2\n"
				 "f2: ");
	return;
}

inline void os_outb(uint16_t port, uint8_t data){
  __asm__("out dx, al"
          :
          : "d" (port), "a" (data));
  return;
}


inline uint8_t os_inb(uint16_t port){
  uint8_t temp = 0;
  __asm__("in al, dx"
          : "=a" (temp)
		  : "d" (port));
  return temp;
}

inline void os_outw(uint16_t port, uint16_t data){
	__asm__("out dx, ax"
			:
			: "d" (port), "a" (data));
	return;
}

uint16_t os_inw(uint16_t port){
	uint16_t temp = 0;
	__asm__("in ax, dx"
			: "=a" (temp)
			: "d" (port));
	return temp;
	
}
inline void os_outd(uint16_t port, uint32_t data){
	__asm__("out dx, eax"
			:
			: "d" (port), "a" (data));
	return;
}

inline uint32_t  os_ind(uint16_t port){
	uint32_t temp = 0;
	__asm__("in eax, dx"
			: "=a" (temp)
			: "d" (port));
	return temp;
}

inline void os_cpuid(void){
  __asm__("cpuid");
  return;
}