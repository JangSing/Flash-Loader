#include <stdint.h>
#include <stdlib.h>
#include "tlv.h"
#include "LinkedList.h"
#include "tlvAllocator.h"
#include "usbd_cdc_core.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"
#include "usb_dcd_int.h"

void tlvReceivePacket( TlvInfo *tlvInfo){

  uint8_t byteReceive;
  TlvElement *tlvEle;
  if(VCP_get_char(&byteReceive)){
    switch(tlvInfo->state){
      case IDLE_RECEIVE :
        tlvInfo->ptr->type1=byteReceive;
        tlvInfo->state=TYPE1_RECEIVE;
      break;
      case TYPE1_RECEIVE:
        tlvInfo->ptr->type2=byteReceive;
        tlvInfo->state=TYPE2_RECEIVE;
      break;
      case TYPE2_RECEIVE:
        tlvInfo->ptr->length=byteReceive;
        tlvInfo->state=LENGTH_RECEIVE;
      break;
      case LENGTH_RECEIVE:
        tlvInfo->ptr->data[tlvInfo->index]=byteReceive;

        (tlvInfo->index)++;
        if(tlvInfo->index != tlvInfo->ptr->length)
          tlvInfo->state=LENGTH_RECEIVE;
        else
          tlvInfo->state=VALUE_RECEIVE;
      break;
      case VALUE_RECEIVE:
        //formation of the tlv packet
        tlvInfo->index=0;
        tlvEle=(TlvElement *)(allocateTlv());
        tlvEle->tlv=*(tlvInfo->ptr);
        addFirst(tlvInfo->list, (ListElement *)(tlvEle));
        tlvInfo->state=IDLE_RECEIVE;
      break;
      default   :break;
    }
  }
}

void tlvSendPacket(TlvInfo *tlvInfo){
  TlvElement *deQEle;
  TlvPacket  *tlvPacket;
  LinkedList *senderQueue=tlvInfo->list;
  
  if(senderQueue->tail!=NULL && tlvInfo->status==PROCESS_READY){
    deQEle=(TlvElement *)(removeLast(senderQueue));
    tlvInfo->ptr=&deQEle->tlv;
  }
  if(tlvInfo->ptr!=NULL){
    tlvInfo->status=PROCESS_BUSY;
    tlvPacket=tlvInfo->ptr;
    switch(tlvInfo->state){
      case TYPE1_SEND:
        VCP_put_char(tlvPacket->type1);
        tlvInfo->state=TYPE2_SEND;
      break;
      case TYPE2_SEND:
        VCP_put_char(tlvPacket->type2);
        tlvInfo->state=LENGTH_SEND;
      break;
      case LENGTH_SEND:
        VCP_put_char(tlvPacket->length);
        tlvInfo->state=VALUE_SEND;
      break;
      case VALUE_SEND:
        VCP_put_char(tlvPacket->data[tlvInfo->index]);
        tlvInfo->index++;
        if(tlvInfo->index==tlvPacket->length){
          tlvInfo->state=TYPE1_SEND;
          tlvInfo->index=0;
        }
      break;
      default: break;
    }
  }
}










