#ifndef _ATAPI_H
#define _ATAPI_H

#include "Pci.h"

void atapi_init(void);

uint8_t check_status(struct Device*); //meh

#endif 