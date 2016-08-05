#ifndef Flash_H
#define Flash_H
#include "tlv.h"

typedef enum{FLASH_IDLE,FLASH_READ,FLASH_PROGRAM,FLASH_ERASE}FlashState;

typedef enum{ INTERPRETE_COMPLETE,
              INTERPRETE_READY,
              INTERPRETE_BUSY}Status;

typedef struct{
  FlashState  state;
  Status status;
  TlvPacket *tlv;
}FlashInfo;

#define TYPE_READ     0x10
#define TYPE_PROGRAM  0x11
#define TYPE_ERASE    0x12

void tlvInterpreter(LinkedList *list,FlashInfo *flashInfo);
Status readFlash(uint32_t address,uint8_t length);

#endif // Flash_H
