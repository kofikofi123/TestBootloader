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

struct Sequencer_Register { 
    uint8_t ResetRegister;
    uint8_t ClockingModeRegister;
    uint8_t MapMaskRegister;
    uint8_t CharacterMapSelectRegister;
    uint8_t SequencerMemoryModeRegister;
}__attribute__((packed));

struct CRTC_Register {
    uint8_t HorizontalTotalRegister;
    uint8_t EndHorizontalDisplayRegister;
    uint8_t StartHorizontalBlankingRegister;
    uint8_t EndHorizontalBlankingRegister;
    uint8_t StartHorizontalRetraceRegister;
    uint8_t EndHorizontalRetraceRegister;
    uint8_t VerticalTotalRegister;
    uint8_t OverflowRegister;
    uint8_t PresetRowScanRegister;
    uint8_t MaximumScanLineRegister;
    uint8_t CursorStartRegister;
    uint8_t CursorEndRegister;
    uint8_t VerticalRetraceStartRegister;
    uint8_t VerticalRetraceEndRegister;
    uint8_t VerticalDisplayEndRegister;
    uint8_t OffsetRegister;
    uint8_t UnderlineLocationRegister;
    uint8_t StartVerticalBlankingRegister;
    uint8_t EndVerticalBlankingRegister;
    uint8_t CRTCModeControlRegister;
    uint8_t LineCompareRegister;
}__attribute__((packed));

struct External_Register {
    uint8_t MiscellaneousOutputRegister;
    uint8_t FeatureControlRegister;
    uint8_t InputStatusRegister0;
    uint8_t InputStatusRegister2;
}__attribute__((packed));

struct VGARegisters {
    struct Graphics_Register graphics;
    struct Sequencer_Register sequencer;
    struct CRTC_Register crtc;
    struct External_Register external; // special
    
}__attribute__((packed));

void write_indexbased_registers(void*, uint16_t, uint16_t, uint16_t);
void read_indexbased_registers(void*, uint16_t, uint16_t, uint16_t);
void write_external_register(struct External_Register*);
void read_external_register(struct External_Register*);
void read_vga_registers(struct VGARegisters*);

#endif