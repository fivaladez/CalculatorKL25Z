/*
** Project: Calculator for KL25Z
** File   : PWM_driver.h
** Author : Ivan Valadez
** Date   : 06 - January - 2019
**
** Overview: C file containing the functions for using PWM pins from MCU KL25K of nxp
**
** $Log$
*/
/*---------------------------------------------------------------------------
** Includes
 */
#ifndef PWM_DRIVER_H_
#define PWM_DRIVER_H_

#include "derivative.h"
/*---------------------------------------------------------------------------
** Defines and Macros
*/
/*Yo have 2 channel for each TPM channel selected*/
#define PWM_PERIOD_52ms		52000
#define PWM_PERIOD_16ms	    43750	//	xms/(1/(21Mhz/8))
#define PWM_PERIOD_CONST	437		//(43750/100)

/*---------------------------------------------------------------------------
** Typedefs
*/
typedef enum
{
	ePORTA_PWM,
	ePORTB_PWM,
	ePORTC_PWM,
	ePORTD_PWM,
	ePORTE_PWM

}ePORTx_PWM_t;
typedef enum
{
	ePIN_0_PWM  = 0,  ePIN_1_PWM  = 1,  ePIN_2_PWM  = 2,  ePIN_3_PWM  = 3,
	ePIN_4_PWM  = 4,  ePIN_5_PWM  = 5,  ePIN_8_PWM  = 8,  ePIN_9_PWM  = 9,
	ePIN_12_PWM = 12, ePIN_13_PWM = 13, ePIN_18_PWM = 18, ePIN_19_PWM = 19,
	ePIN_20_PWM = 20, ePIN_21_PWM = 21, ePIN_22_PWM = 22, ePIN_23_PWM = 23,
	ePIN_29_PWM = 29, ePIN_30_PWM = 30, ePIN_31_PWM = 31
	    
}ePINx_PWM_t;
typedef enum
{
	eFALSE_PWM,
	eTRUE_PWM

}eStatus_PWM_t;
typedef enum 
{
	eCH0_PWM,
	eCH1_PWM,
	eCH2_PWM,
	eCH3_PWM,
	eCH4_PWM,
	eCH5_PWM
	
}eChannel_PWM_t;
typedef uint16_t u16Period_t;
typedef uint8_t u8Percent_t;
typedef uint16_t u16PeriodConst_t;
typedef struct
{
	eChannel_PWM_t   eChannel;
	ePORTx_PWM_t     ePort;
	ePINx_PWM_t      ePin;
	eStatus_PWM_t    eSatus;
	u16Period_t      u16Period;
	u16PeriodConst_t u16PeriodConst;
	u8Percent_t      u8Percent;	
	
}sDATA_PWM_t;
/*---------------------------------------------------------------------------
** Data
*/
/*---------------------------------------------------------------------------
** Prototypes Functions
*/
/*! \brief    efInit_PWM
**
** \note	 Initialization for specific port.
** 			 It calls another function to config registers
** 			 returns TRUE if the parameters are valid and the function could started correctly
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]           sDATA_PWM_t* sDATA_PWM,
** 					    ePORTx_PWM_t ePORTx,
** 					    ePINx_PWM_t ePINx,
** 					     uint16_t u16Period
**
** \return               eStatus_PWM_t eReturn
** \description
*/
eStatus_PWM_t efInit_PWM(sDATA_PWM_t* sDATA_PWM, ePORTx_PWM_t ePORTx, ePINx_PWM_t ePINx, uint16_t u16Period);
/*! \brief    vfPercentage_PWM
**
** \note	 It selects between ports and pins to assign equivalent values to percent range (0-100)%
** 			 returns TRUE if the parameters are valid and the function could started correctly
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            sDATA_PWM_t* sDATA_PWM,
** 						 uint8_t u8pPercent
** 
** \return               NA
** \description
*/
void vfPercentage_PWM(sDATA_PWM_t* sDATA_PWM, uint8_t u8pPercent);

#endif /* PWM_DRIVER_H_ */
