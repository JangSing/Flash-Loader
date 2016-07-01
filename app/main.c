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

uint8_t buffChar[]={'h','e','l','l','o'};
uint8_t c;

int main(void) {
	FLASH_Status status=FLASH_COMPLETE;
	uint32_t *ptr=ADDRESS_SECTOR_18;
    SystemInit();
	USBD_Init(	&USB_OTG_dev,
				USB_OTG_HS_CORE_ID,
				&USR_desc,
				&USBD_CDC_cb,
				&USR_cb);
	while(1){
    	if(VCP_get_char(&c)){
    		switch(c){
    		case 'v':
    			VCP_send_buffer(buffChar, 6);break;
    		case 'p':
    			FLASH_Unlock();
    			while(status==FLASH_BUSY);
    			status=FLASH_ProgramHalfWord(ADDRESS_SECTOR_18, DATA_PROGRAM);
    			while(status==FLASH_BUSY);
    			FLASH_Lock();break;
    		case 'e':
    			FLASH_Unlock();
    			while(status==FLASH_BUSY);
    			status=FLASH_EraseSector(FLASH_CR_SNB_4|FLASH_CR_SNB_2|FLASH_CR_SNB_1, FLASH_VOLTAGE_RANGE_3);
    			while(status==FLASH_BUSY);
    			FLASH_Lock();break;
    		default :break;
    		}
    	}
	}

}


