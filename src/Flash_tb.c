#include <stdint.h>
#include <stdlib.h>
#include "Flash_tb.h"
#include "tlv_tb.h"

void tlvInterpreter(LinkedList *list,FlashInfo *flashInfo){
  TlvElement *deQEle;
  TlvPacket  *tlvPacket;
  if(list->tail!=NULL && flashInfo->status==INTERPRETE_READY){
    deQEle=(TlvElement *)(removeLast(list));
    flashInfo->tlv=&deQEle->tlv;
  }
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

    break;
    case FLASH_PROGRAM:

    break;
    case FLASH_ERASE:

    break;
    default   :break;
  }
}
