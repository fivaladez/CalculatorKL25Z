/*
** Project: Calculator for KL25Z
** File   : ADC_driver.c
** Author : Ivan Valadez
** Date   : 06 - January - 2019
**
** Overview: C file containing the functions for using ADC pins from MCU KL25K of nxp
**
** $Log$
*/
/*---------------------------------------------------------------------------
** Includes
 */
#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "derivative.h"
/*---------------------------------------------------------------------------
** Defines and Macros
*/
#define ADC_CHANNEL a
/*#define ADC_CHANNEL b*/
/*This Driver ONLY works for single ended ADC channel*/
/*---------------------------------------------------------------------------
** Typedefs
*/
typedef enum
{
	ePORTB_ADC,
	ePORTC_ADC,
	ePORTD_ADC,
	ePORTE_ADC

}ePORTx_ADC_t;
typedef enum
{
	ePIN_0_ADC,	 ePIN_1_ADC,
	ePIN_2_ADC,	 ePIN_3_ADC,
	ePIN_5_ADC,	 ePIN_6_ADC,
	ePIN_20_ADC, ePIN_21_ADC,
	ePIN_22_ADC, ePIN_23_ADC

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
/*---------------------------------------------------------------------------
** Data
*/
/*---------------------------------------------------------------------------
** Prototypes Functions
*/
/*! \brief    efInit_ADC
**
** \note	 Initialization for specific port.
** 			 It calls another function to config registers
** 			 returns TRUE if the parameters are valid and the function could started correctly
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_ADC_t ePORTx,
** 						 ePINx_ADC_t ePINx,
** 						 sDATA_ADC_t* spDataADC
**
** \return               eStatus_ADC_t eReturn
** \description
*/
eStatus_ADC_t efInit_ADC( ePORTx_ADC_t ePORTx, ePINx_ADC_t ePINx, sDATA_ADC_t* spDataADC);
/*! \brief    efRead_ADC
**
** \note	  Read the value of the ADC. Also read and clean flags if needed
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            sDATA_ADC_t* spDataADC
**
** \return               eStatus_ADC_t eReturn , A confirmation of data read or not
*/
eStatus_ADC_t efRead_ADC(sDATA_ADC_t* spDataADC);

#endif /* ADC_DRIVER_H_ */
