#include <stdint.h>
#include "../include/memtools.h"


void memset(void* buffer, uint8_t value, uint32_t size){
  char* cBuffer = (char*)buffer;
  
  while (size > 0){
    *cBuffer++ = value;
    size--;
  }
  
  return;
}

void memcpy(void* buffer, const void* buffer2, uint32_t size){
  char *cBuffer = (char*)buffer, *cBuffer2 = (char*)buffer2;
  
  while (size > 0){
    *cBuffer++ = *cBuffer2++;
    size--;
  }
}

void memmove(void* buffer, void* buffer2, uint32_t size){
  char* cBuffer = (char*)buffer, *cBuffer2 = (char*)buffer2;
  
  while (size > 0){
    *cBuffer++ = *cBuffer2;
    *cBuffer2++ = 0;
    size--;
  }
}

