#include <stdint.h>
#include <stdlib.h>
#include "tlv.h"

void tlvStateMachine(TlvInfo *tlvInfo,uint8_t byteReceived){
  switch(tlvInfo->state){
    case IDLE :
      tlvInfo->ptr->type1=byteReceived;
      tlvInfo->state=TYPE1_RECEIVED;
    break;
    case TYPE1_RECEIVED:
      tlvInfo->ptr->type2=byteReceived;
      tlvInfo->state=TYPE2_RECEIVED;
    break;
    case TYPE2_RECEIVED:
      tlvInfo->ptr->length=byteReceived;
      tlvInfo->state=LENGTH_RECEIVED;
    break;
    case LENGTH_RECEIVED:
      tlvInfo->ptr->data[tlvInfo->index]=byteReceived;
      (tlvInfo->index)++;
      if(tlvInfo->index != tlvInfo->ptr->length)
        tlvInfo->state=LENGTH_RECEIVED;
      else
        tlvInfo->state=VALUE_RECEIVED;
    break;
    case VALUE_RECEIVED:
      tlvInfo->index=0;
      tlvInfo->state=IDLE;
    break;
    default   :break;
  }
}
