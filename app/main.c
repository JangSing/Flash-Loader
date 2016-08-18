#include <stdlib.h>
#include "stm32f4xx_conf.h"
#include "stm32f4xx.h"
#include "usbd_cdc_core.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"
#include "usb_dcd_int.h"
#include "tlv.h"
#include "LinkedList.h"
#include "Flash.h"
#include "tlvAllocator.h"

USB_OTG_CORE_HANDLE	USB_OTG_dev;

#define noOfTlv 10

int main(void) {
  //USB initializing
  SystemInit();
  USBD_Init(  &USB_OTG_dev,
              USB_OTG_HS_CORE_ID,
              &USR_desc,
              &USBD_CDC_cb,
              &USR_cb);

  //receiverQueue
  LinkedList receiverQueue;
  linkedListInit(&receiverQueue);
  
  //senderQueue
  LinkedList senderQueue;
  linkedListInit(&senderQueue);

  //init allocator
  TlvElement tlvEle[noOfTlv]={};
  initTlvAllocator(tlvEle,noOfTlv);

  //initialize receive tlv structure
  TlvPacket buffer={};
  TlvInfo tlvRECEIVEInfo={PROCESS_READY,IDLE_RECEIVE,0,&buffer,&receiverQueue};

  //initialize flash structure
  FlashObject flashObj={READ_IDLE,NULL,0,0,NULL,&senderQueue};
  FlashInfo flashInfo={FLASH_IDLE,PROCESS_READY,NULL,tlvRECEIVEInfo.list,&flashObj};

  //initialize send tlv structure
  TlvInfo tlvSendingInfo={PROCESS_READY,TYPE1_SEND,0,flashInfo.obj->tlv,&senderQueue};
  
  while(1){
    tlvReceivePacket(&tlvRECEIVEInfo);
    tlvInterpreter(&flashInfo);
    tlvSendPacket(&tlvSendingInfo);
  }
}


