/*
 * GPIO_driver.h
 *
 *  Created on: Sep 4, 2018
 *      Author: ivan_
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "derivative.h"

#define PORT_PCR_MUX_GPIO 1u

typedef enum 
{
	ePORTA,
	ePORTB,
	ePORTC,
	ePORTD,
	ePORTE
	
}ePORTx_GPIO_t;

typedef enum 
{
	ePIN_0,  ePIN_1,  ePIN_2,  ePIN_3,
	ePIN_4,  ePIN_5,  ePIN_6,  ePIN_7,
	ePIN_8,  ePIN_9,  ePIN_10, ePIN_11,
	ePIN_12, ePIN_13, ePIN_14, ePIN_15,
	ePIN_16, ePIN_17, ePIN_18, ePIN_19,
	ePIN_20, ePIN_21, ePIN_22, ePIN_23,
	ePIN_29, ePIN_30
	
}ePINx_GPIO_t;

typedef enum 
{
	eINPUT,
	eOUTPUT
	
}eInOut_GPIO_t;

typedef enum 
{
	eFALSE,
	eTRUE
	
}eStatus_GPIO_t;

eStatus_GPIO_t efInit_GPIO		(ePORTx_GPIO_t ePORTx,ePINx_GPIO_t ePINx,eInOut_GPIO_t eInOut);
void vfSetPin_GPIO        		(ePORTx_GPIO_t ePORTx,ePINx_GPIO_t ePINx);
void vfClearPin_GPIO      		(ePORTx_GPIO_t ePORTx,ePINx_GPIO_t ePINx);
void vfTogglePin_GPIO     		(ePORTx_GPIO_t ePORTx,ePINx_GPIO_t ePINx);
eStatus_GPIO_t efReadPin_GPIO   (ePORTx_GPIO_t ePORTx,ePINx_GPIO_t ePINx);
void vfWritePin_GPIO            (ePORTx_GPIO_t ePORTx,ePINx_GPIO_t ePINx, uint8_t u8Data);
void vfWritePort_GPIO           (ePORTx_GPIO_t ePORTx,                    uint8_t u8Data);


#endif /* GPIO_DRIVER_H_ */
