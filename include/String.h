//String.h, will possibly move it somewhere else 


#ifndef _STRING_H
#define _STRING_H

#include <stdint.h>

#define STRING_END -1
#define STRING_NOMATCH -2

int32_t string_find(const char*, const char*, uint32_t, uint32_t);
uint32_t string_len(const char*);

#endif