/*
 * Buttons_driver.h
 *
 *  Created on: Sep 4, 2018
 *      Author: ivan_
 */

#ifndef BUTTONS_DRIVER_H_
#define BUTTONS_DRIVER_H_

#include "GPIO_driver.h"

typedef struct 
{
	uint8_t u8ID;
	uint8_t u8Port;
	uint8_t u8Pin;
	
}sButton_t;


uint8_t u8fCreateButton(sButton_t *psButton, uint8_t u8PORTx,uint8_t u8PINx);
uint8_t u8fReadButton  (sButton_t *psButton);

#endif /* BUTTONS_DRIVER_H_ */
