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
#include "tm_stm32f4_usb_vcp.h"
#include "tm_stm32f4_disco.h"
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

volatile uint32_t ticker, downTicker;


int main(void) {
    uint8_t c;
    /* System Init */
    SystemInit();
    /* Initialize USB VCP */
    TM_USB_VCP_Init();

    while (1) {
    	if (500 == ticker){
    		GPIOG->BSRRH = GPIO_Pin_14;
    	}
    	else if (1000 == ticker)
    	{
    		ticker = 0;
    		GPIOG->BSRRL = GPIO_Pin_14;
    	}
    }
}


