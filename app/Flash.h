#ifndef Flash_H
#define Flash_H
#include "tlv.h"

typedef enum{FLASH_IDLE,FLASH_READ,FLASH_PROGRAM,FLASH_ERASE}FlashState;

typedef enum{READ_IDLE,READ_DATA,READ_END}ObjState;


              
              
typedef struct{
  ObjState    state;
  uint32_t    *address;
  uint8_t     length;
  int         index;
  TlvPacket   *tlv;
  LinkedList  *list;
}FlashObject;


typedef struct{
  FlashState  state;
  Status      status;
  TlvPacket   *tlv;
  LinkedList  *list;
  FlashObject *obj;
}FlashInfo;

#define TYPE_READ     0x10
#define TYPE_PROGRAM  0x11
#define TYPE_ERASE    0x12

void tlvInterpreter(FlashInfo *flashInfo);
Status readFlash(FlashObject *obj);

#endif // Flash_H
