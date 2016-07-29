#include <stdint.h>
#include "stm32f4xx_flash.h"
#include "stm32f4xx_flash_ramfunc.h"
#include "Flash.h"
#include "tlv.h"

void flashStateMachine(FlashInfo *flashInfo,TlvPacket *tlvPacket){

  FLASH_Status status=FLASH_COMPLETE;
  FLASH_Unlock();
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
  FLASH_Lock();
}
