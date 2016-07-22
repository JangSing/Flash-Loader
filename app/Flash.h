#ifndef Flash_H
#define Flash_H
#include "tlv.h"

typedef enum{FLASH_IDLE,FLASH_READ,FLASH_PROGRAM,FLASH_ERASE}FlashState;

typedef struct{
  FlashState  state;
}FlashInfo;

#define TYPE_READ     0x10
#define TYPE_PROGRAM  0x11
#define TYPE_ERASE    0x12

void flashStateMachine(FlashInfo *flashInfo,TlvPacket *tlvPacket);

#endif // Flash_H
