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
/*****************************************************************************
**                                                                          **
** 																	        **
** 																	        **
** 														                    **
** 														                    **
** 		   															        **
**                                                                          **
*****************************************************************************/
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
