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


int main(void) {
  uint8_t byteReceived;
  int counter=0;

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
  TlvElement tlvEle[10]={};

  TlvElement *deQEle=NULL;

  //initialize tlv structure
  uint8_t buffer[DATA_SIZE]={};
  TlvInfo tlvInfo={TLV_IDLE,0,(TlvPacket *)buffer};

  FlashInfo flashInfo={FLASH_IDLE};


  while(1){

    if(VCP_get_char(&byteReceived)){
      tlvStateMachine(&tlvInfo,byteReceived);
    }

    if(tlvInfo.state==VALUE_RECEIVED){
      tlvEle[counter].tlv=*(tlvInfo.ptr);
      enQueue(&list, (ListElement *)(&tlvEle[counter]));
      counter++;
    }
    if(list.tail!=NULL && deQEle==NULL){
      deQEle=(TlvElement *)(deQueue(&list));
    }

    if(deQEle!=NULL){
      flashStateMachine(&flashInfo,&(deQEle->tlv));
    }

  }

}


