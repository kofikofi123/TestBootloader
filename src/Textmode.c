#include "../include/Textmode.h"
#include "../include/VGA.h"


VGARegisters vga_regs;


void init_textmode(void){
    flush_vga_registers(&vga_regs, 9, 0x3CE, 0x3CF);
    write_vga_registers(&vga_regs, 9, 0x3CE, 0x3CF);
    return;
}