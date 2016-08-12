#ifndef Flash_H
#define Flash_H
#include "tlv.h"

typedef enum{FLASH_IDLE,FLASH_READ,FLASH_PROGRAM,FLASH_ERASE,FLASH_END}FlashState;

typedef enum{ INTERPRETE_COMPLETE,
              INTERPRETE_READY,
              INTERPRETE_BUSY}Status;

typedef struct{
  FlashState  state;
  Status status;
  TlvPacket *tlv;
  LinkedList *list;
}FlashInfo;

#define TYPE_READ     0x10
#define TYPE_PROGRAM  0x11
#define TYPE_ERASE    0x12

void tlvInterpreter(FlashInfo *flashInfo);
Status readFlash(TlvPacket  *tlvPacket);

#endif // Flash_H
