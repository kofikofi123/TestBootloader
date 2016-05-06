#ifndef _ELF_H
#define _ELF_H

#include <stdint.h>

struct ELF {
    struct {
        int8_t Magic[4];
        uint8_t Class;
        uint8_t Data; 
        uint8_t Version;
        uint8_t Padding[16];
    }__attribute__((packed)) Header;
    uint16_t Type;
    uint16_t Machine
}__attribute__((packed));

void parse_elf(struct* ELF, const char*);
void confirm_elf(struct* ELF, uint8_t*);

#endif