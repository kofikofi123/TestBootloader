#ifndef _PCI_H
#define _PCI_H

#define CONFIG_ADDRESS 0xCF8
#define CONFIG_DATA 0xCFC
#define ENCODE_OFFSET(a, b) (a << 2) | (b & 0x03)

#include <stdint.h>


struct Device {
  uint8_t Bus;
  uint8_t Slot;
  uint16_t DeviceID;
  uint16_t VendorID;
}__attribute__((packed));
/*
struct Bus {
}__attribute__((packed));
*/

enum DeviceType {
  Device, //0
  Pci_bridge, //1
  Card_bridge //2
  //Multi; 
};

void init_pci(uint16_t si);
void getDevice(struct Device* device_t, uint8_t bus, uint8_t device);
enum DeviecType getDeviceType(uint8_t bus, uint8_t device);

uint8_t getStatus(struct Device device);


//uint8_t get_devices(void);


#endif
