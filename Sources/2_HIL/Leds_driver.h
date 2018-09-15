/*
 * Leds_driver.h
 *
 *  Created on: Sep 14, 2018
 *      Author: ivan_
 */

#ifndef LEDS_DRIVER_H_
#define LEDS_DRIVER_H_

#include "derivative.h"
#include "GPIO_driver.h"

typedef eStatus_GPIO_t eStates_LED_t;
typedef ePORTx_GPIO_t ePORTx_LED_t;
typedef ePINx_GPIO_t ePINx_LED_t;

typedef enum
{
	eRED,
	eGREEN,
	eBLUE
}eColors_LED_t;

eStates_LED_t efInit_LED   (eColors_LED_t eColor);
void vfTurnOn_LED  (eColors_LED_t eColor);
void vfTurnOff_LED(eColors_LED_t eColor);
void vfToggle_LED (eColors_LED_t eColor);
eStates_LED_t efRead_LED   (eColors_LED_t eColor);

#endif /* LEDS_DRIVER_H_ */
