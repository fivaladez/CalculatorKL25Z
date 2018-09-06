/*
 * GPIO_driver.h
 *
 *  Created on: Sep 4, 2018
 *      Author: ivan_
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#define PORT_PCR_MUX_GPIO 1u

#define RED_LED   PTB18
#define GREEN_LED PTB19
#define BLUE_LED  PTD13


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
}ePORTx_PIN_t;

typedef enum 
{
	eIN,
	eOUT
}ePINx_INOUT_t;

typedef enum 
{
	eFALSE,
	eTRUE
}ePINx_VALUE_t;

uint8_t u8fInit_GPIO (uint8_t ePORTx,uint8_t ePIN,uint8_t eINOUT);

void vfSetPort_GPIO   (uint8_t bPORTx,uint8_t bPINx);
void vfClearPort_GPIO (uint8_t bPORTx,uint8_t bPINx);
void vfTogglePort_GPIO(uint8_t bPORTx,uint8_t bPINx);

uint8_t u8fReadPort_GPIO(uint8_t bPORTx,uint8_t bPINx);

#endif /* GPIO_DRIVER_H_ */
