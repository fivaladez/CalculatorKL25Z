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

typedef enum 
{
	ePORTA,
	ePORTB,
	ePORTC,
	ePORTD,
	ePORTE
}ePORTx_t;

typedef enum 
{
	ePIN_0, ePIN_1, ePIN_2, ePIN_3,
	ePIN_4, ePIN_5, ePIN_6, ePIN_7,
	ePIN_8, ePIN_9, ePIN_10, ePIN_11,
	ePIN_12, ePIN_13, ePIN_14, ePIN_15,
	ePIN_16, ePIN_17, ePIN_18, ePIN_19,
	ePIN_20, ePIN_21, ePIN_22, ePIN_23,
	ePIN_29, ePIN_30
}ePINx_t;

typedef enum 
{
	eIN,
	eOUT
}eINOUT_t;

typedef enum 
{
	eFALSE,
	eTRUE
}eVALUEx_t;

typedef enum
{
	eSTATE_READ_1,
	eSTATE_WAIT_2,
	eSTATE_READ_3
}eDebouncerx_t;

uint8_t u8fCreateButton(sButton_t *psButton, uint8_t u8PORTx,uint8_t u8PINx);
uint8_t u8fReadButton  (sButton_t *psButton);

#endif /* BUTTONS_DRIVER_H_ */
