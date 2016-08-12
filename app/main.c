#include <stdlib.h>
#include "stm32f4xx_conf.h"
#include "stm32f4xx.h"
#include "stm32f4xx_flash.h"
#include "stm32f4xx_flash_ramfunc.h"
#include "usbd_cdc_core.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"
#include "usb_dcd_int.h"
#include "tlv.h"
#include "LinkedList.h"
#include "Flash.h"

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

  //initializing linked list
  LinkedList list;
  linkedListInit(&list);

  //create buffer for each tlv element
  TlvElement tlvEle[noOfTlv]={};
  initTlvAllocator(tlvEle,noOfTlv);


  //initialize tlv structure
  TlvPacket buffer={};
  TlvInfo tlvReceivedInfo={TLV_IDLE,0,&buffer,list};

  FlashInfo flashInfo={FLASH_IDLE,INTERPRETE_READY,NULL,&tlvReceivedInfo.list};
  while(1){
    tlvReceivedPacket(&tlvReceivedInfo,tlvEle);
    tlvInterpreter(&flashInfo);
  }
}


