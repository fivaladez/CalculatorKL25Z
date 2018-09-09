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
	ePORTA_GPIO,
	ePORTB_GPIO,
	ePORTC_GPIO,
	ePORTD_GPIO,
	ePORTE_GPIO
}ePORTx_GPIO_t;

typedef enum 
{
	ePIN_0_GPIO, ePIN_1_GPIO, ePIN_2_GPIO, ePIN_3_GPIO,
	ePIN_4_GPIO, ePIN_5_GPIO, ePIN_6_GPIO, ePIN_7_GPIO,
	ePIN_8_GPIO, ePIN_9_GPIO, ePIN_10_GPIO, ePIN_11_GPIO,
	ePIN_12_GPIO, ePIN_13_GPIO, ePIN_14_GPIO, ePIN_15_GPIO,
	ePIN_16_GPIO, ePIN_17_GPIO, ePIN_18_GPIO, ePIN_19_GPIO,
	ePIN_20_GPIO, ePIN_21_GPIO, ePIN_22_GPIO, ePIN_23_GPIO,
	ePIN_29_GPIO, ePIN_30_GPIO
}ePINx_GPIO_t;

typedef enum 
{
	eIN_GPIO,
	eOUT_GPIO
}eINOUT_GPIO_t;

typedef enum 
{
	eFALSE_GPIO,
	eTRUE_GPIO
}eVALUEx_GPIO_t;

uint8_t u8fInit_GPIO (uint8_t ePORTx,uint8_t ePIN,uint8_t eINOUT);

void vfSetPort_GPIO   (uint8_t bPORTx,uint8_t bPINx);
void vfClearPort_GPIO (uint8_t bPORTx,uint8_t bPINx);
void vfTogglePort_GPIO(uint8_t bPORTx,uint8_t bPINx);

uint8_t u8fReadPort_GPIO(uint8_t bPORTx,uint8_t bPINx);

void vfPassValToPort_GPIO(uint8_t u8PORTx,uint8_t u8PINx, uint8_t u8Data);

#endif /* GPIO_DRIVER_H_ */
