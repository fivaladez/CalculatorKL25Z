/*
** Project: Calculator for KL25Z
** File   : GPIO_driver.h
** Author : Ivan Valadez
** Date   : 10 - October - 2018
**
** Overview: Header file containing
**
** $Log$
*/
#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

/*---------------------------------------------------------------------------
** Includes
*/
#include "derivative.h"
/*---------------------------------------------------------------------------
** Defines and Macros
*/
#define PORT_PCR_MUX_GPIO 1u
/*---------------------------------------------------------------------------
** Typedefs
*/
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
	ePIN_0_GPIO,  ePIN_1_GPIO,  ePIN_2_GPIO,  ePIN_3_GPIO,
	ePIN_4_GPIO,  ePIN_5_GPIO,  ePIN_6_GPIO,  ePIN_7_GPIO,
	ePIN_8_GPIO,  ePIN_9_GPIO,  ePIN_10_GPIO, ePIN_11_GPIO,
	ePIN_12_GPIO, ePIN_13_GPIO, ePIN_14_GPIO, ePIN_15_GPIO,
	ePIN_16_GPIO, ePIN_17_GPIO, ePIN_18_GPIO, ePIN_19_GPIO,
	ePIN_20_GPIO, ePIN_21_GPIO, ePIN_22_GPIO, ePIN_23_GPIO,
	ePIN_29_GPIO, ePIN_30_GPIO

}ePINx_GPIO_t;
typedef enum
{
	eINPUT_GPIO,
	eOUTPUT_GPIO

}eInOut_GPIO_t;
typedef enum
{
	eFALSE_GPIO,
	eTRUE_GPIO

}eStatus_GPIO_t;
/*---------------------------------------------------------------------------
** Data
*/

/*---------------------------------------------------------------------------
** Functions
*/
/*-------------------------------------------------------------------------*/

/*! \brief    efInit_GPIO
**
** \note	  Initialize Clock, Port and Pin as an output or input and returns
** 			  a confirmation of success if every process was made correctly
** 			  or a confirmation of fail if the function couldn't complete the task
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 ePINx_GPIO_t ePINx,
** 						 eInOut_GPIO_t eInOut
**
** \return               eStatus_GPIO_t, A confirmation (success or fail) of internal process
*/
eStatus_GPIO_t efInit_GPIO( ePORTx_GPIO_t ePORTx, ePINx_GPIO_t ePINx, eInOut_GPIO_t eInOut );
/*! \brief    vfSetPin_GPIO
**
** \note	  Writes a logic 1 in the pin you decide
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 ePINx_GPIO_t ePINx
**
** \return          	 NA
*/
void vfSetPin_GPIO( ePORTx_GPIO_t ePORTx, ePINx_GPIO_t ePINx );
/*! \brief    vfClearPin_GPIO
**
** \note	  Writes a logic 0 in the pin you decide
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 ePINx_GPIO_t ePINx
**
** \return          	 NA
*/
void vfClearPin_GPIO( ePORTx_GPIO_t ePORTx, ePINx_GPIO_t ePINx );
/*! \brief    vfTogglePin_GPIO
**
** \note	  Toggle the value of pin you decide
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 ePINx_GPIO_t ePINx
**
** \return          	 NA
*/
void vfTogglePin_GPIO( ePORTx_GPIO_t ePORTx, ePINx_GPIO_t ePINx );
/*! \brief    efReadPin_GPIO
**
** \note	  Read the value logic of the required pin and return its status.
** 			  TRUE  = Logic 0
** 			  FALSE = Logic 1
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 ePINx_GPIO_t ePINx,
**
** \return               eStatus_GPIO_t, A confirmation (success or fail) of internal process
*/
eStatus_GPIO_t efReadPin_GPIO( ePORTx_GPIO_t ePORTx, ePINx_GPIO_t ePINx );
/*! \brief    vfWritePin_GPIO
**
** \note	  Writes a binary value (0 or 1) in the pin you decide
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 ePINx_GPIO_t ePINx,
** 						 uint8_t u8Data
**
** \return          	 NA
*/
void vfWritePin_GPIO( ePORTx_GPIO_t ePORTx, ePINx_GPIO_t ePINx, uint8_t u8Data );
/*! \brief    vfWritePort_GPIO
**
** \note	  Writes a value of a byte in the port you decide
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 uint8_t u8Data
**
** \return          	 NA
*/
void vfWritePort_GPIO( ePORTx_GPIO_t ePORTx, uint8_t u8Data );


#endif /* GPIO_DRIVER_H_ */
