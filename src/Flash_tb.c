#include <stdint.h>
#include <stdlib.h>
#include "Flash_tb.h"
#include "tlv_tb.h"

void tlvInterpreter(FlashInfo *flashInfo){
  TlvElement *deQEle;
  TlvPacket  *tlvPacket;
  if(flashInfo->list->tail!=NULL && flashInfo->status==PROCESS_READY){
    deQEle=(TlvElement *)(removeLast(flashInfo->list));
    flashInfo->tlv=&deQEle->tlv;
  }
  if(flashInfo->tlv!=NULL){
    flashInfo->status=PROCESS_BUSY;
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
        flashInfo->obj->tlv=tlvPacket;
        flashInfo->status=readFlash(flashInfo->obj);
        if(flashInfo->status==PROCESS_COMPLETE){
          flashInfo->state=FLASH_IDLE;
          flashInfo->status=PROCESS_READY;
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

Status readFlash(FlashObject *obj){
  int i;
  switch(obj->state){
    case READ_IDLE:
      obj->address=(uint32_t *)(*(uint32_t *)(&obj->tlv->data[0]));
      obj->length=obj->tlv->data[4];
      obj->state=READ_DATA;
    break;
    
    case READ_DATA:
      i=obj->index;
    
      obj->tlv->data[5+4*i]=*(obj->address+i)>>0;
      obj->tlv->data[6+4*i]=*(obj->address+i)>>8;
      obj->tlv->data[7+4*i]=*(obj->address+i)>>16;
      obj->tlv->data[8+4*i]=*(obj->address+i)>>24;
      if(obj->index!=obj->length){
        obj->index++;
        return PROCESS_BUSY;
      }
      else{
        return PROCESS_COMPLETE;
      }
    break;
    
    default   :break;

  }
  
}











