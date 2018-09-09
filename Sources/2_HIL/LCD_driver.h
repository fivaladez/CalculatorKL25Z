/*
 * LCD_driver.h
 *
 *  Created on: Sep 5, 2018
 *      Author: ivan_
 */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#define BEGINING_RAW_1	(0x80u)
#define MIDDLE_RAW_1	(0x87u)
#define BEGINING_RAW_2	(0xC0u)
#define MIDDLE_RAW_2	(0xC7u)

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

uint8_t u8fSendData_LCD( uint8_t u8Possition, uint8_t *u8aDataLCD );

void vfSendDataInit_LCD( uint8_t *u8aDataLCD , uint8_t u8LenghtArray);


#endif /* LCD_DRIVER_H_ */
