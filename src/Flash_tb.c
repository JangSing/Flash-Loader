#include <stdint.h>
#include <stdlib.h>
#include "Flash_tb.h"
#include "tlv_tb.h"

void tlvInterpreter(FlashInfo *flashInfo){
  TlvElement *deQEle=NULL;
  TlvPacket  *tlvPacket;
  if(flashInfo->list->tail!=NULL && flashInfo->status==INTERPRETE_READY){
    deQEle=(TlvElement *)(removeLast(flashInfo->list));
    flashInfo->tlv=&deQEle->tlv;
  }
  if(flashInfo->tlv!=NULL){
    flashInfo->status=INTERPRETE_BUSY;
    tlvPacket=flashInfo->tlv;
    switch(flashInfo->state){
      case FLASH_IDLE:
        if(tlvPacket->type1==TYPE_READ)
          flashInfo->state=FLASH_READ;
        else if(tlvPacket->type1==TYPE_PROGRAM)
          flashInfo->state=FLASH_PROGRAM;
        else if(tlvPacket->type1==TYPE_ERASE)
          flashInfo->state=FLASH_ERASE;
      break;
      case FLASH_READ:
        flashInfo->status=readFlash(tlvPacket);
        if(flashInfo->status==INTERPRETE_COMPLETE){
          flashInfo->state=FLASH_IDLE;
          flashInfo->status=INTERPRETE_READY;
        }
      break;
      case FLASH_PROGRAM:

      break;
      case FLASH_ERASE:

      break;
      default   :break;
    }
  }
}

Status readFlash(TlvPacket  *tlvPacket){
  uint32_t *address=(uint32_t *)(*(uint32_t *)(&tlvPacket->data[0]));
  uint8_t length=tlvPacket->data[4];



  return INTERPRETE_COMPLETE;
}