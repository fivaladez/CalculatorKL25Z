/*
 * UART_driver.h
 *
 *  Created on: Oct 27, 2018
 *      Author: ivan_
 */

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_


#include "derivative.h"

#define SBR		(7000u)

#define OSR		(9u)

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

eStatus_UART_t efInit_UART( ePORTx_UART_t ePORTx, eCHANNELx_UART_t eChannelx, sDATA_UART_t* spDataUART);
eStatus_UART_t efRead_UART  (sDATA_UART_t* spDataUART);
eStatus_UART_t efSend_UART (sDATA_UART_t* spDataUART, uint8_t u8UARTval);

#endif /* UART_DRIVER_H_ */
