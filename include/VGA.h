#ifndef _VGA_H
#define _VGA_H

#include <stdint.h>
/*
int8_t 	map_memory(uint8_t index);
void	load_reg1(void);*/

struct Graphics_Register {
    uint8_t SetResetRegister;
    uint8_t EnableSetResetRegister;
    uint8_t CompareRegister;
    uint8_t DataRotateRegister;
    uint8_t ReadMapSelectRegister;
    uint8_t GraphicsModeRegister;
    uint8_t MiscellaneousRegister;
    uint8_t ColorDontCareRegister;
    uint8_t BitMaskRegister;
}__attribute__((packed));


void flush_graphics_register(void);



#endif