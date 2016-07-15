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

USB_OTG_CORE_HANDLE	USB_OTG_dev;


int main(void) {
  uint8_t byteReceived;
  //Queue Static Element
  LinkedList list;
  int counter=0;

  linkedListInit(&list);
  
  TlvPacket packet[10]={};
  tlvElement tlvEle[10]={};

  tlvEle[0].tlv=&packet[0];
  tlvEle[1].tlv=&packet[1];
  tlvEle[2].tlv=&packet[2];
  tlvEle[3].tlv=&packet[3];
  tlvEle[4].tlv=&packet[4];
  tlvEle[5].tlv=&packet[5];
  tlvEle[6].tlv=&packet[6];
  tlvEle[7].tlv=&packet[7];
  tlvEle[8].tlv=&packet[8];
  tlvEle[9].tlv=&packet[9];

  
  uint8_t buffer[258]={};
  TlvInfo tlvInfo={IDLE,0,(TlvPacket *)buffer};
  
  SystemInit();
  USBD_Init(  &USB_OTG_dev,
              USB_OTG_HS_CORE_ID,
              &USR_desc,
              &USBD_CDC_cb,
              &USR_cb);
  while(1){
    if(VCP_get_char(&byteReceived)){
      tlvStateMachine(&tlvInfo,byteReceived);
    }
    if(tlvInfo.state==VALUE_RECEIVED){
      packet[counter]=*(tlvInfo.ptr);
      queueTlv((ListElement *)(&tlvEle[counter]),&list );
      counter++;
    }
  }

}


