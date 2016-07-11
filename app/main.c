#include "stm32f4xx_conf.h"
#include "stm32f4xx.h"
#include "stm32f4xx_flash.h"
#include "stm32f4xx_flash_ramfunc.h"
#include "stm32f4xx_hal_flash_ex.h"
#include "usbd_cdc_core.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"
#include "usb_dcd_int.h"

USB_OTG_CORE_HANDLE	USB_OTG_dev;

#define ADDRESS_SECTOR_18 0x08140000
#define DATA_PROGRAM 	  0x2015

#define PROGRAM	0x10000001
#define ERASE	0x10000002
#define READ	0x10000003

typedef enum{IDLE,RECEIVE_TYPE1,RECEIVE_TYPE2,RECEIVE_LENGTH,RECEIVE_VALUE,
				FLASH_PROGRAM,FLASH_ERASE,FLASH_READ}State;



typedef struct{
	State state;
}McuTlv;

typedef struct TlvPacket TlvPacket;
struct TlvPacket {
  uint8_t type1;
  uint8_t type2;
  uint8_t length;
  int8_t  data[0];
};

uint8_t byte;
TlvPacket packet;

int main(void) {
	FLASH_Status status=FLASH_COMPLETE;
	uint32_t *ptr=ADDRESS_SECTOR_18;

	McuTlv tlv={IDLE};

    SystemInit();
	USBD_Init(	&USB_OTG_dev,
				USB_OTG_HS_CORE_ID,
				&USR_desc,
				&USBD_CDC_cb,
				&USR_cb);
	while(1){

    	switch(tlv.state){
    	case IDLE:
    		if(VCP_get_char(&byte)){
    			tlv.state=RECEIVE_TYPE1;
    		}
    		break;
    	case RECEIVE_TYPE1:
    		if(VCP_get_char(&byte)){
    			packet.type1=byte;
    			tlv.state=RECEIVE_TYPE2;
    		}
    		break;
    	case RECEIVE_TYPE2:
    		if(VCP_get_char(&byte)){
    			packet.type2=byte;
    			tlv.state=RECEIVE_LENGTH;
    		}
    		break;
    	case RECEIVE_LENGTH:
    		if(VCP_get_char(&byte)){
    		    packet.length=byte;
    		    tlv.state=RECEIVE_VALUE;
    		}
    		break;
    	case RECEIVE_VALUE:
    		if(VCP_get_char(&byte)){
    			packet.data[0]=byte;
    			if(packet.type1==PROGRAM)
    				tlv.state=FLASH_PROGRAM;
    			else if(packet.type1==ERASE)
    			    tlv.state=FLASH_ERASE;
    			else if(packet.type1==READ)
    				tlv.state=FLASH_READ;
    		}
    		break;
    	}
	}

}


