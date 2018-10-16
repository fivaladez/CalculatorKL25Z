/*
 * ADC_driver.h
 *
 *  Created on: Oct 11, 2018
 *      Author: ivan_
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "derivative.h"

#define ADC_CHANNEL a
/*#define ADC_CHANNEL b*/
/*This Driver ONLY works for single ended ADC channel*/
/*This driver also works only with pins in port E from MCU KL25Z*/
typedef enum
{
	ePORTA_ADC,
	ePORTB_ADC,
	ePORTC_ADC,
	ePORTD_ADC,
	ePORTE_ADC

}ePORTx_ADC_t;
typedef enum
{
	ePIN_20_ADC,	ePIN_21_ADC,
	ePIN_22_ADC,	ePIN_23_ADC

}ePINx_ADC_t;
typedef enum
{
	eFALSE_ADC,
	eTRUE_ADC

}eStatus_ADC_t;
typedef struct
{
	uint8_t       u8ValADC;
	uint16_t	  u16Percent;
	uint8_t		  u8Hundreds;
	uint8_t		  u8Dozens;
	uint8_t		  u8Units;
	ePORTx_ADC_t  ePortADC;
	ePINx_ADC_t   ePinADC;
	eStatus_ADC_t eSatusADC;
	
}sDATA_ADC_t;

eStatus_ADC_t efInit_ADC( ePORTx_ADC_t ePORTx, ePINx_ADC_t ePINx, sDATA_ADC_t* spDataADC);
eStatus_ADC_t efRead_ADC(sDATA_ADC_t* spDataADC);

#endif /* ADC_DRIVER_H_ */
