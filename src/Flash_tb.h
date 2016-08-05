#ifndef Flash_H
#define Flash_H
#include "tlv_tb.h"

typedef enum{FLASH_IDLE,FLASH_READ,FLASH_PROGRAM,FLASH_ERASE}FlashState;

typedef enum{ INTERPRETE_COMPLETE,
              INTERPRETE_READY,
              INTERPRETE_BUSY}InrepreterStatus;

typedef struct{
  FlashState  state;
  InrepreterStatus status;
  TlvPacket *tlv;
}FlashInfo;

#define TYPE_READ     0x10
#define TYPE_PROGRAM  0x11
#define TYPE_ERASE    0x12

void tlvInterpreter(LinkedList *list,FlashInfo *flashInfo);

#endif // Flash_H
