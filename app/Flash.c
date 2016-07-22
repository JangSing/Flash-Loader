#include "Flash.h"
#include "tlv.h"

void flashStateMachine(FlashInfo *flashInfo,TlvPacket *tlvPacket){
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
