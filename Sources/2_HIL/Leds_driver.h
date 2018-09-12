/*
 * Leds_driver.h
 *
 *  Created on: Sep 12, 2018
 *      Author: ivan_
 */

#ifndef LEDS_DRIVER_H_
#define LEDS_DRIVER_H_

#include "derivative.h"
#include "GPIO_driver.h"

typedef enum
{
	eNOTREADY_LED,
	eREADY_LED
}eStates_LED_t;

typedef enum
{
	eRED,
	eGREEN,
	eBLUE
}eColors_LED_t;

uint8_t u8fInit_LED   (eColors_LED_t eColor);
uint8_t u8fTurnOn_LED (eColors_LED_t eColor);
uint8_t u8fTurnOff_LED(eColors_LED_t eColor);
uint8_t u8fToggle_LED (eColors_LED_t eColor);
uint8_t u8fRead_LED   (eColors_LED_t eColor);
 
#endif /* LEDS_DRIVER_H_ */
