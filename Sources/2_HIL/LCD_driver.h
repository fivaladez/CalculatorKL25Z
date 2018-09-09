/*
 * LCD_driver.h
 *
 *  Created on: Sep 5, 2018
 *      Author: ivan_
 */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#define BEGINING_RAW_1	(0x80u)
#define END_RAW_1		(0x8Fu)
#define BEGINING_RAW_2	(0xC0u)
#define END_RAW_2		(0xCFu)

typedef enum
{
	eINSTRUCTION,
	eSEND_DATA
}eCode_LCD_t;

typedef enum
{
	eNOTREADY_LCD,
	eREADY_LCD
}eStatus_LCD_t;

uint8_t u8fInit_LCD( void );

uint8_t u8fSendData_LCD( uint8_t *u8aDataLCD , uint8_t u8LengthArray , uint8_t u8StartPossition);

void vfClear_LCD(void);


#endif /* LCD_DRIVER_H_ */
