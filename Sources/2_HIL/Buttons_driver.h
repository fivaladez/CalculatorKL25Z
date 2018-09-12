/*
 * Buttons_driver.h
 *
 *  Created on: Sep 4, 2018
 *      Author: ivan_
 */

#ifndef BUTTONS_DRIVER_H_
#define BUTTONS_DRIVER_H_

#include "GPIO_driver.h"

#define NONBLOCKING

typedef ePINx_GPIO_t   ePINx_Buttons_t;
typedef ePORTx_GPIO_t  ePORTx_Buttons_t;
typedef eStatus_GPIO_t eStatus_Buttons_t;
typedef eInOut_GPIO_t  eInOut_Buttons_t;

typedef struct 
{
	uint8_t 		 u8ID;
	ePORTx_Buttons_t ePort;
	ePINx_Buttons_t  ePin;
	
}sButton_t;

eStatus_Buttons_t u8fCreateButton  (sButton_t *psButton, ePORTx_Buttons_t ePORTx,ePINx_Buttons_t ePINx);
eStatus_Buttons_t u8fReadButton    (sButton_t *psButton);

#ifndef NONBLOCKING

typedef enum
{
	eSTATE_READ_1,
	eSTATE_WAIT_2,
	eSTATE_READ_3
	
}eState_Buttons_t;

typedef struct 
{
	uint8_t 		 u8ID;
	ePORTx_Buttons_t ePort;
	ePINx_Buttons_t  ePin;
	eState_Buttons_t eState;
	
}sButtonNonBlocking0_t;

typedef struct 
{
	uint8_t 		 u8ID;
	ePORTx_Buttons_t ePort;
	ePINx_Buttons_t  ePin;
	eState_Buttons_t eState;
	
}sButtonNonBlocking1_t;

eStatus_Buttons_t u8fCreateButtonNonBlocking0(sButtonNonBlocking0_t *psButton, ePORTx_Buttons_t ePORTx,ePINx_Buttons_t ePINx);
eStatus_Buttons_t u8fReadButtonNonBlocking0  (sButtonNonBlocking0_t *psButton);

eStatus_Buttons_t u8fCreateButtonNonBlocking1(sButtonNonBlocking1_t *psButton, ePORTx_Buttons_t ePORTx,ePINx_Buttons_t ePINx);
eStatus_Buttons_t u8fReadButtonNonBlocking1  (sButtonNonBlocking1_t *psButton);

#endif

#endif /* BUTTONS_DRIVER_H_ */
