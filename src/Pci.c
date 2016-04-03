#include "../include/Pci.h"
#include "../include/ACOREFuncs.h"

#include <stdint.h>

//static void check_bus(void);


static uint8_t readConfigB(uint8_t bus, uint8_t device, uint8_t function, uint8_t offset);
static uint16_t readConfigW(uint8_t bus, uint8_t device, uint8_t function, uint8_t offset);
static uint32_t readConfigD(uint8_t bus, uint8_t device, uint8_t function, uint8_t offset);
static void Update(void);
static void getStatus(struct Status_t* status, uint8_t bus, uint8_t device);

void init_pci(void){
  //uint8_t boot_settings = os_get_boot_settings();
}

void getDevice(struct Device* device_t, uint8_t bus, uint8_t device){
  device_t->DeviceID = readConfigW(bus, device, 0, ENCODE_OFFSET(0, 0));
  device_t->VendorID = readConfigW(bus, device, 0, ENCODE_OFFSET(0, 1));
  device_t->Status = 
}

enum DeviecType getDeviceType(uint8_t bus, uint_t device){
  return GET_HEADER(readConfigB(bus, device, 0, ENCODE_OFFSET(12, 1)));
}




static uint32_t readConfigD(uint8_t bus, uint8_t device, uint8_t function, uint8_t offset){
  uint32_t address = ((0x80000000) | (bus << 16) | (device << 11) | (function << 8) | (offset & 0xFC));
  
  os_outd(CONFIG_ADDRESS, address);
  
  return os_ind(CONFIG_DATA);
}

static uint16_t readConfigW(uint8_t bus, uint8_t device, uint8_t function, uint8_t offset){
  uint32_t address = ((0x80000000) | (bus << 16) | (device << 11) | (function << 8) | (offset & 0xFC));
  
  os_outd(CONFIG_ADDRESS, address);
  
  return (os_inw(CONFIG_DATA) >> ((offset & 3) * 8));
}

static uint8_t readConfigB(uint8_t bus, uint8_t device, uint8_t function, uint8_t offset){
  uint32_t address = ((0x80000000) | (bus << 16) | (device << 11) | (function << 8) | (offset & 0xFC));
  
  os_outd(CONFIG_ADDRESS, address);
  
  return (os_inb(CONFIG_DATA) >> ((offset & 3) * 8));
}

static void getStatus(struct Status_t* status, uint8_t bus, uint8_t device){
  //status->   
}