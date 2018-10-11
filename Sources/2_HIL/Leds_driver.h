/*
** Project: Calculator for KL25Z
** File   : Leds_driver.h
** Author : Ivan Valadez
** Date   : 6 - October - 2018
**
** Overview: Header file containing
**
** $Log$
*/
#ifndef LEDS_DRIVER_H_
#define LEDS_DRIVER_H_
/*---------------------------------------------------------------------------
** Includes
*/
#include "derivative.h"
#include "GPIO_driver.h"
/*---------------------------------------------------------------------------
** Defines and Macros
*/
/*---------------------------------------------------------------------------
** Typedefs
*/
typedef eStatus_GPIO_t eStates_LED_t;
typedef ePORTx_GPIO_t ePORTx_LED_t;
typedef ePINx_GPIO_t ePINx_LED_t;
typedef enum
{
	eRED,
	eGREEN,
	eBLUE
}eColors_LED_t;
/*---------------------------------------------------------------------------
** Data
*/
/*---------------------------------------------------------------------------
** Functions
*/
/*-------------------------------------------------------------------------*/
/*! \brief    efInit_LED
**
** \note	  Initializes all the requirements for working with leds on board KL25Z
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            NA
**
** \return               eStatus_LCD_t, A confirmation (success or fail) of internal process
*/
eStates_LED_t efInit_LED   (eColors_LED_t eColor);
/*! \brief    vfTurnOn_LED
**
** \note	  Turn on the required led
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            eColors_LED_t eColor
**
** \return               NA
*/
void vfTurnOn_LED  (eColors_LED_t eColor);
/*! \brief    vfTurnOff_LED
**
** \note	  Turn off the required led
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            eColors_LED_t eColor
**
** \return               NA
*/
void vfTurnOff_LED(eColors_LED_t eColor);
/*! \brief    vfToggle_LED
**
** \note	  Change the state of the required led
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            eColors_LED_t eColor
**
** \return               NA
*/
void vfToggle_LED (eColors_LED_t eColor);
/*! \brief    efRead_LED
**
** \note	  Read the current state of the required led
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            eColors_LED_t eColor
**
** \return               eStates_LED_t, A confirmation (success or fail) if active or inactive
*/
eStates_LED_t efRead_LED   (eColors_LED_t eColor);

#endif /* LEDS_DRIVER_H_ */
