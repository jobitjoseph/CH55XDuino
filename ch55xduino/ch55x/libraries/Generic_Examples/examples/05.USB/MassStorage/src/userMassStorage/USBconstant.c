#include "USBconstant.h"


//Device descriptor
__code uint8_t DevDesc[] = {
    0x12,0x01,
    0x10,0x01,  //USB spec release number in BCD format, USB1.1 (0x10, 0x01).
    0x00,0x00,0x00, //bDeviceClass, bDeviceSubClass, bDeviceProtocol
    DEFAULT_ENDP0_SIZE, //bNumConfigurations
    0x09,0x12,0x5E,0xC5, // VID PID 
    0x01,0x01,  //version
    0x01,0x02,0x03, //bString
    0x01    //bNumConfigurations
};

__code uint16_t DevDescLen = sizeof(DevDesc);

__code uint8_t CfgDesc[] ={
    // Configuration Descriptor
    9,                    // Length of the descriptor
    0x02,                 // Type: Configuration Descriptor
    // Total length of this and following descriptors
    sizeof(CfgDesc) & 0xff,sizeof(CfgDesc) >> 8,
    1,                    // Number of interfaces
    0x01,                 // Value used to select this configuration
    0x00,                 // Index of corresponding string descriptor
    0x80,                 // Attributes, D7 must be 1, D6 Self-powered, D5 Remote Wakeup, D4-D0=0
    0x32,                 // Max current drawn by device, in units of 2mA
    
    // Descriptor of Mass Storage interface
    9,                    // bLength: Interface Descriptor size
    0x04,                 // bDescriptorType:
    // Interface descriptor type
    0x00,                 // bInterfaceNumber: Number of Interface
    0x00,                 // bAlternateSetting: Alternate setting
    0x02,                 // bNumEndpoints
    0x08,                 // bInterfaceClass: MASS STORAGE Class
    0x06,                 // bInterfaceSubClass : SCSI transparent
    0x50,                 // nInterfaceProtocol
    0,                    // iInterface:
    // 18
    7,                    //Endpoint descriptor length = 7
    0x05,                 //Endpoint descriptor type
    0x81,                 //Endpoint address (IN, address 1)
    0x02,                 //Bulk endpoint type
    0x40,                 //Maximum packet size (64 bytes)
    0x00,
    0x00,                 //Polling interval in milliseconds
    // 25
    0x07,                 //Endpoint descriptor length = 7
    0x05,                 //Endpoint descriptor type
    0x01,                 //Endpoint address (OUT, address 2)
    0x02,                 //Bulk endpoint type
    0x40,                 //Maximum packet size (64 bytes)
    0x00,
    0x00                  //Polling interval in milliseconds

};

__code uint16_t CfgDescLen = sizeof(CfgDesc);

//String Descriptors
__code uint8_t LangDes[]={0x04,0x03,0x09,0x04};           //Language Descriptor
__code uint16_t LangDesLen = sizeof(LangDes);
__code uint8_t SerDes[]={                                 //Serial String Descriptor
    0x0C,0x03,
    'C',0x00,'H',0x00,'5',0x00,'5',0x00,'x',0x00
};
__code uint16_t SerDesLen = sizeof(SerDes);
__code uint8_t Prod_Des[]={                                //Produce String Descriptor
    0x1E,0x03,
    'C',0x00,'H',0x00,'5',0x00,'5',0x00,'x',0x00,'d',0x00,
    'u',0x00,'i',0x00,'n',0x00,'o',0x00,
    ' ',0x00,'M',0x00,'S',0x00,'D',0x00
};
__code uint16_t Prod_DesLen = sizeof(Prod_Des);

__code uint8_t Manuf_Des[]={
    0x0E,0x03,
    'D',0x00,'e',0x00,'q',0x00,'i',0x00,'n',0x00,'g',0x00,
};
__code uint16_t Manuf_DesLen = sizeof(Manuf_Des);
