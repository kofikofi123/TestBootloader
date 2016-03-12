#include "../include/Textmode.h"
#include "../include/VGA.h"


VGARegisters vga_regs;


void init_textmode(void){ //init text mode
    flush_indexbased_registers(&vga_regs.Graphics_Register, 9, 0x3CE, 0x3CF);
    flush_indexbased_registers(&vga_regs.Sequencer_Register, 9, 0x3C4, 0x3C5);
    
    
    return;
}