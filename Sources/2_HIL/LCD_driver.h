/*
** Project: Calculator for KL25Z
** File   : LCD_driver.h
** Author : Ivan Valadez
** Date   : 6 - October - 2018
**
** Overview: Header file containing
**
** $Log$
*/
#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_
/*---------------------------------------------------------------------------
** Includes
*/
#include "derivative.h"
#include "GPIO_driver.h"
/*---------------------------------------------------------------------------
** Defines and Macros
*/
#define DATA_BITS_4 (0u)/*If different of 0, work with 8 bits, */
/*---------------------------------------------------------------------------
** Typedefs
*/
typedef enum
{
	eFILA_01_0  = 0x80u,	eFILA_01_1  = 0x81u,	eFILA_01_2  = 0x82u,	eFILA_01_3  = 0x83u,
	eFILA_01_4  = 0x84u,	eFILA_01_5  = 0x85u,	eFILA_01_6  = 0x86u,	eFILA_01_7  = 0x87u,
	eFILA_01_8  = 0x88u,	eFILA_01_9  = 0x89u,	eFILA_01_10 = 0x8Au,	eFILA_01_11 = 0x8Bu,
	eFILA_01_12 = 0x8Cu,	eFILA_01_13 = 0x8Du,	eFILA_01_14 = 0x8Eu,	eFILA_01_15 = 0x8Fu,

	eFILA_02_0  = 0xC0u,	eFILA_02_1  = 0xC1u,	eFILA_02_2  = 0xC2u,	eFILA_02_3  = 0xC3u,
	eFILA_02_4  = 0xC4u,	eFILA_02_5  = 0xC5u,	eFILA_02_6  = 0xC6u,	eFILA_02_7  = 0xC7u,
	eFILA_02_8  = 0xC8u,	eFILA_02_9  = 0xC9u,	eFILA_02_10 = 0xCAu,	eFILA_02_11 = 0xCBu,
	eFILA_02_12 = 0xCCu,	eFILA_02_13 = 0xCDu,	eFILA_02_14 = 0xCEu,	eFILA_02_15 = 0xCFu,

	eFILA_NULL = 0x00u

}ePosition_LCD_t;
typedef uint8_t u8Data_LCD_t;
typedef uint8_t u8Command_LCD_t;
typedef enum
{
	eFALSE_LCD = eFALSE_GPIO,
	eTRUE_LCD = eTRUE_GPIO

}eStatus_LCD_t;

/*---------------------------------------------------------------------------
** Data
*/
/*---------------------------------------------------------------------------
** Functions
*/

/*-------------------------------------------------------------------------*/
/*! \brief    efInit_LCD
**
** \note	  Initializes all the requirements for working with the LCD 16x2
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            NA
**
** \return               eStatus_LCD_t, A confirmation (success or fail) of internal process
*/
eStatus_LCD_t efInit_LCD( void );
/*! \brief    vfSendPosition_LCD
**
** \note	  Handles the transmission of commands to positioning the cursor
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePosition_LCD_t ePosition
**
** \return               NA
*/
void vfSendPosition_LCD ( ePosition_LCD_t ePosition );
/*! \brief    vfSendCommand_LCD
**
** \note	  Handles the transmission of commands to modify functionalities of LCD
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            u8Command_LCD_t u8Command
**
** \return               NA
*/
void vfSendCommand_LCD  ( u8Command_LCD_t u8Command );
/*! \brief    vfSendData_LCD
**
** \note	  Handles the transmission of data to LCD
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            u8Data_LCD_t u8Data
**
** \return               NA
*/
void vfSendData_LCD     ( u8Data_LCD_t u8Data );
/*! \brief    vfClear_LCD
**
** \note	  Handles the transmission of the command to clear screen of LCD
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            NA
**
** \return               NA
*/
void vfClear_LCD        ( void );
/*! \brief    vfSendMessage_LCD
**
** \note	  Handles the transmission of a chain of characters to LCD
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            char *u8pMessage
**
** \return               NA
*/
void vfSendMessage_LCD  ( char *u8Message );

#endif /* LCD_DRIVER_H_ */
