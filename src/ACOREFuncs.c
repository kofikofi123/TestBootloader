#include "../include/ACOREFuncs.h"
#include <stdint.h>

#define CPUID_ENABLED 0 
#define CPUID_DISABLED -1

static uint32_t os_eflags(void);
static void os_eflags_push(uint32_t eflags);
//static int8_t os_cpuid_enabled(void);

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

inline uint16_t os_inw(uint16_t port){
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


inline uint32_t os_get_boot_settings(void){
	return *(uint32_t*)(0x7C00); //not ready
}

int8_t os_cpuid(uint32_t* eax, uint32_t* ebx, uint32_t* ecx, uint32_t* edx){
    if (os_cpuid_supported() == CPUID_DISABLED){
        return CPUID_DISABLED;
    }
    
    __asm__("cpuid"
            : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx)
            : "a" (*eax));
    return CPUID_ENABLED;
}

int8_t os_cpuid_supported(void){
    uint32_t eflags = os_eflags();
    
    eflags |= 0x200000;
    
    os_eflags_push(eflags);
    eflags = os_eflags();
    
    if ((eflags & 0x200000) == 0x20000){
        return CPUID_ENABLED;
    }
    return CPUID_DISABLED;
}

static inline uint32_t os_eflags(void){
    uint32_t temp = 0;
    
    __asm__("pushfd\npop eax"
            : "=a" (temp));
            
    return temp;
}
static inline void os_eflags_push(uint32_t eax){
    __asm__("push eax\npopfd"
            :
            : "a" (eax));
}