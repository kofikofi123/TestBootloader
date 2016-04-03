#ifndef _PCI_H
#define _PCI_H

#define CONFIG_ADDRESS 0xCF8
#define CONFIG_DATA 0xCFC
#define ENCODE_OFFSET(a, b) (a << 2) | (b & 0x03)
#define HAS_MULTIPLE_FUNCTIONS(a) (a >> 7) & 0xFF
#define GET_HEADER(a) a & 0b0111111

#include <stdint.h>

//address configuration1 format:

/*
struct Configuration1{
  uint8_t useless : 2;
  uint8_t register_number : 6;
  uint8_t function_number : 3;
  uint8_t device_number : 5;
  uint8_t bus_number : 8;
  uint8_t reserved : 7;
  uint8_t enabled_bit : 2;
}__attribute__((packed));

struct Configuration2{
  uint8_t special_cycle_enabled : 1;
  uint8_t function_number : 3;
  uint8_t key : 4;
}__attribute__((packed));


*/

struct Status_t {
  uint8_t Reserved : 3;
  uint8_t InterruptStatus : 1;
  uint8_t CapabilitiesList : 1;
  uint8_t MHz66Capable : 1;
  uint8_t Reserved : 1;
  uint8_t FastBacktoBackCapable : 1;
  uint8_t MasterDataParityError : 1;
  uint8_t DEVSELTiming : 2;
  uint8_t SignaledTargetAbort : 1;
  uint8_t RecievedTargetAbort : 1;
  uint8_t RecievedMaster
}__attribute__((packed));

struct Command_t {
  uint8_t IOSpace : 1;
  uint8_t MemorySpace : 1;
  uint8_t BusMaster : 1;
  uint8_t SpecialCycles : 1;
  uint8_t MemoryWriteInvalidateEnable : 1;
  uint8_t VGAPaletteSnoop : 1;
  uint8_t ParityErrorResponse : 1;
  uint8_t Reserved : 1;
  uint8_t SERREnabled : 1;
  uint8_t FastBacktoBackEnable : 1;
  uint8_t InteruptDisable : 1;
  uint8_t Reserved2 : 5;
}__attribute__((packed));

struct Device {
  uint8_t Bus;
  uint8_t Slot;
  uint16_t DeviceID;
  uint16_t VendorID;
  struct Status_t Status;//uint16_t Status;
  struct Command_t Command; //uint16_t Command;
  uint8_t ClassCode;
  uint8_t SubClass;
  uint8_t ProgIF;
  uint8_t RevisionID;
  uint8_t BIST;
  uint8_t HeaderType;
  uint8_t LatencyTimer;
  uint8_t CacheLineSize;
  uint32_t BAR0;
  uint32_t BAR1;
  uint32_t BAR2;
  uint32_t BAR3;
  uint32_t BAR4;
  uint32_t BAR5;
  uint32_t CISPointer;
  uint16_t SubsystemID;
  uint16_t SubsystemVendorID;
  uint32_t ROMBaseAddress;
  uint32_t Reserved : 24;
  uint8_t CapabilitesPointer;
  uint32_t Reserved2;
  uint8_t MaxLatency;
  uint8_t MinGrant;
  uint8_t InterruptPIN;
  uint8_t InterruptLine;
  void* Update; // will be hooked on first getDevice or getDevices;
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

void init_pci(void);
void getDevice(struct Device* device_t, uint8_t bus, uint8_t device);
void getDevices(struct Device** device_t, uint8_t bus, uint8_t device)
enum DeviecType getDeviceType(uint8_t bus, uint8_t device);


//uint8_t get_devices(void);


#endif
