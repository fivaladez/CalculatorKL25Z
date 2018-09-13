/*
 * Buttons_driver.h
 *
 *  Created on: Sep 4, 2018
 *      Author: ivan_
 */

#ifndef BUTTONS_DRIVER_H_
#define BUTTONS_DRIVER_H_

#include "derivative.h"
#include "GPIO_driver.h"

#define NONBLOCKING	(0)

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

eStatus_Buttons_t efCreateButton  (sButton_t *psButton, ePORTx_Buttons_t ePORTx,ePINx_Buttons_t ePINx);
eStatus_Buttons_t efReadButton    (sButton_t *psButton);
eStatus_Buttons_t efReadButtonNonBlocking(sButton_t *psButton);

#if NONBLOCKING == 1

#include "PIT_driver.h"

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

eStatus_Buttons_t efCreateButtonNonBlocking0(sButtonNonBlocking0_t *psButton, ePORTx_Buttons_t ePORTx,ePINx_Buttons_t ePINx);
eStatus_Buttons_t efReadButtonNonBlocking0  (sButtonNonBlocking0_t *psButton);

eStatus_Buttons_t efCreateButtonNonBlocking1(sButtonNonBlocking1_t *psButton, ePORTx_Buttons_t ePORTx,ePINx_Buttons_t ePINx);
eStatus_Buttons_t efReadButtonNonBlocking1  (sButtonNonBlocking1_t *psButton);

#endif

#endif /* BUTTONS_DRIVER_H_ */
