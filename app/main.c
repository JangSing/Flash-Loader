/**
 *	USB VCP for STM32F4xx example.
 *
 *	@author		Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://stm32f4-discovery.com
 *	@ide		Keil uVision
 *	@packs		STM32F4xx Keil packs version 2.2.0 or greater required
 *	@stdperiph	STM32F4xx Standard peripheral drivers version 1.4.0 or greater required
 *
 * Add line below to use this example with F429 Discovery board (in defines.h file)
 *
 * #define USE_USB_OTG_HS
 *
 * Before compile in Keil, select your target, I made some settings for different targets
*/
#include "stm32f4xx_conf.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_exti.h"
#include "usbd_cdc_core.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"
#include "usb_dcd_int.h"
#include "defines.h"
#include <string.h>

USB_OTG_CORE_HANDLE	USB_OTG_dev;

uint8_t buffChar[]={'h','e','l','l','o'};
uint8_t c;

int main(void) {
    SystemInit();
	USBD_Init(	&USB_OTG_dev,
				USB_OTG_HS_CORE_ID,
				&USR_desc,
				&USBD_CDC_cb,
				&USR_cb);

    while (1) {

    	if(VCP_get_char(&c)){
    		if(c=='`')
    			VCP_send_buffer(buffChar, 6);
    		else {
				VCP_put_char(c);
			}
    	}
    }
}


