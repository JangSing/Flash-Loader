#include <stdint.h>
#include <stdlib.h>
#include "stm32f4xx_flash.h"
#include "stm32f4xx_flash_ramfunc.h"
#include "Flash.h"
#include "tlv.h"

void tlvInterpreter(LinkedList *list,FlashInfo *flashInfo){
  TlvElement *deQEle=NULL;
  TlvPacket  *tlvPacket;
  if(list->tail!=NULL && flashInfo->tlv==NULL){
    deQEle=(TlvElement *)(removeLast(list));
    flashInfo->tlv=&deQEle->tlv;
  }
  if(flashInfo->tlv!=NULL){
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
        flashInfo->status=readFlash(*(uint32_t *)(&tlvPacket->data[0]),tlvPacket->data[4]);
      break;
      case FLASH_PROGRAM:

      break;
      case FLASH_ERASE:

      break;
      default   :break;
    }
  }
}

Status readFlash(uint32_t address,uint8_t length){
  
  
  
}
