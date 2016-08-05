#include <stdint.h>
#include <stdlib.h>
#include "tlv.h"
#include "LinkedList.h"
#include "usbd_cdc_core.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"
#include "usb_dcd_int.h"

void tlvReceivedPacket( TlvInfo *tlvInfo,
                        TlvElement *tlvEle){
                          
  uint8_t byteReceived;
  if(VCP_get_char(&byteReceived)){
    switch(tlvInfo->state){
      case TLV_IDLE :
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
        tlvEle[tlvInfo->list.length].tlv=*(tlvInfo->ptr);
        addFirst(&tlvInfo->list, (ListElement *)(&tlvEle[tlvInfo->list.length]));
        tlvInfo->state=TLV_IDLE;
      break;
      default   :break;
    }
  }
}
