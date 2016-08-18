#include <stdint.h>
#include <stdlib.h>
#include "Flash.h"
#include "tlv.h"
#include "tlvAllocator.h"


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
          freeTlv(flashInfo->tlv);
          flashInfo->tlv=NULL;
          flashInfo->state=FLASH_IDLE;
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
  TlvElement *tlvEle;
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
      if(obj->index!=obj->length)
        obj->index++;
      else
        obj->state=READ_END;
      return PROCESS_BUSY;
    break;
    
    case READ_END:
      tlvEle=(TlvElement *)(allocateTlv());
      tlvEle->tlv=*(obj->tlv);
      addFirst(obj->list, (ListElement *)(tlvEle));
      obj->state=READ_IDLE;
      return PROCESS_READY;
    break;
    default   :break;

  }
  return PROCESS_ERROR;
}
