/*
** Project: Calculator for KL25Z
** File   : UART_driver.h
** Author : Ivan Valadez
** Date   : 06 - January - 2019
**
** Overview: C file containing the functions for using UART pins from MCU KL25K of nxp
**
** $Log$
*/
/*---------------------------------------------------------------------------
** Includes
*/

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

#include "derivative.h"
/*---------------------------------------------------------------------------
** Defines and Macros
*/
#define SBR		(7000u)
#define OSR		(9u)
/*---------------------------------------------------------------------------
** Typedefs
*/
typedef enum
{
	ePORTA_UART,
	ePORTC_UART,
	ePORTD_UART,
	ePORTE_UART

}ePORTx_UART_t;
typedef enum
{
	ePIN_0_UART,	ePIN_1_UART,
	ePIN_2_UART,	ePIN_3_UART,
	ePIN_4_UART,	ePIN_5_UART,
	ePIN_6_UART,	ePIN_7_UART,
	ePIN_20_UART, 	ePIN_21_UART,
	ePIN_22_UART, 	ePIN_23_UART

}ePINx_UART_t;
typedef enum
{
	eUART_0,
	eUART_1,
	eUART_2
	
}eCHANNELx_UART_t;
typedef enum
{
	eFALSE_UART,
	eTRUE_UART

}eStatus_UART_t;
typedef struct
{
	uint8_t       u8ValTxUART;
	uint8_t       u8ValRxUART;
	uint8_t		  u8Hundreds;
	uint8_t		  u8Dozens;
	uint8_t		  u8Units;
	eCHANNELx_UART_t eChannelUART;
	ePORTx_UART_t  ePortUART;
	ePINx_UART_t   ePinTxUART;
	ePINx_UART_t   ePinRxUART;
	eStatus_UART_t eSatusUART;
	
}sDATA_UART_t;
/*---------------------------------------------------------------------------
** Data
*/
/*---------------------------------------------------------------------------
** Prototypes Functions
*/
/*! \brief    efInit_UART
**
** \note	 Initialization for specific port and channel.
** 			 Returns TRUE if the parameters are valid and the function could started correctly
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_UART_t ePORTx,
** 						 eCHANNELx_UART_t eChannelx,
** 						 sDATA_UART_t* spDataUART
**
** \return               eStatus_UART_t eReturn
** \description
*/
eStatus_UART_t efInit_UART( ePORTx_UART_t ePORTx, eCHANNELx_UART_t eChannelx, sDATA_UART_t* spDataUART);
/*! \brief    efRead_UART
**
** \note	  Read the value of the UART that you create and return TRUE if there are some data recieved
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            sDATA_UART_t* spDataUART
**
** \return               eStatus_UART_t eReturn, A confirmation of data received or not
*/
eStatus_UART_t efRead_UART  (sDATA_UART_t* spDataUART);
/*! \brief    efSend_UART
**
** \note	  Send the value by UART and return TRUE if the data was succesfully sent
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            sDATA_UART_t* spDataUART, uint8_t u8UARTval
**
** \return               eStatus_UART_t eReturn, A confirmation of data sent or not
*/
eStatus_UART_t efSend_UART (sDATA_UART_t* spDataUART, uint8_t u8UARTval);

#endif /* UART_DRIVER_H_ */
