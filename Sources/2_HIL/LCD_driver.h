/*
 * LCD_driver.h
 *
 *  Created on: Sep 5, 2018
 *      Author: ivan_
 */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#include "derivative.h"
#include "GPIO_driver.h"

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

typedef enum
{
	eDATA,
	eCOMMAND,
}eInstruction_LCD_t;

typedef uint8_t u8Data_LCD_t;

typedef eStatus_GPIO_t eStatus_LCD_t;

eStatus_LCD_t efInit_LCD( void );
void vfSendPosition_LCD( ePosition_LCD_t ePosition );
void vfSendData_LCD( u8Data_LCD_t u8Data);
void vfClear_LCD(void);


#endif /* LCD_DRIVER_H_ */
