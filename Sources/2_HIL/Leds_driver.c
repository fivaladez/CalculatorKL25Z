/*
** Project: Calculator for KL25Z
** File   : Leds_driver.c
** Author : Ivan Valadez
** Date   : 6 - October - 2018
**
** Overview: C file containing
**
** $Log$
*/
/*---------------------------------------------------------------------------
** Includes
*/
#include "Leds_driver.h"
/*---------------------------------------------------------------------------
** Defines and Macros
*/
/*---------------------------------------------------------------------------
** Typedefs
*/
typedef ePORTx_GPIO_t ePORTx_LED_t;
typedef ePINx_GPIO_t  ePINx_LED_t;
/*---------------------------------------------------------------------------
** Data
*/
/* You MUST check the ports and pins of your MCU because these are
 * for the KL25Z */
ePORTx_LED_t ePortRed_LED   = ePORTB_GPIO;	ePINx_LED_t ePinRed_LED     = ePIN_18_GPIO;
ePORTx_LED_t ePortGreen_LED = ePORTB_GPIO;	ePINx_LED_t ePinGreen_LED   = ePIN_19_GPIO;
ePORTx_LED_t ePortBlue_LED  = ePORTD_GPIO;	ePINx_LED_t ePinBlue_LED    = ePIN_1_GPIO;
/*---------------------------------------------------------------------------
** Functions
*/
/*-------------------------------------------------------------------------*/
/*! \brief    efInit_LED
**
** \note	  Initializes requirements leds on board KL25Z.
** 			  Compare wich led you want to use and then call a function of initialization
** 			  from GPIO_driver.h and its value of return will be the value of return of efInit_LED
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            NA
**
** \return               eStatus_LCD_t, A confirmation (success or fail) of internal process
*/
eStatus_LED_t efInit_LED   (eColors_LED_t eColor)
{
	eStatus_LED_t eReturn = eFALSE_LED;
	switch(eColor)
	{
	case eRED_LED:
		if((eStatus_GPIO_t)eTRUE_LED == efInit_GPIO(ePortRed_LED ,ePinRed_LED, eOUTPUT_GPIO))
		{
			eReturn = eTRUE_LED;
		}else eReturn = eFALSE_LED;
		break;
	case eGREEN_LED:
		if((eStatus_GPIO_t)eTRUE_LED == efInit_GPIO(ePortGreen_LED ,ePinGreen_LED, eOUTPUT_GPIO))
		{
			eReturn = eTRUE_LED;
		}else eReturn = eFALSE_LED;
		break;
	case eBLUE_LED:
		if((eStatus_GPIO_t)eTRUE_LED == efInit_GPIO(ePortBlue_LED ,ePinBlue_LED, eOUTPUT_GPIO))
		{
			eReturn = eTRUE_LED;
		}else eReturn = eFALSE_LED;
		break;
	default:
		break;
	}//End of switch

	return eReturn;
}
/*! \brief    vfTurnOn_LED
**
** \note	  Turn on the required led calling the function clear from
** 			  GPIO_driver.h
** 			  This is because leds on KL25Z turn on with a logic 0
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            eColors_LED_t eColor
**
** \return               NA
*/
void vfTurnOn_LED (eColors_LED_t eColor)
{
	switch(eColor)
	{
	case eRED_LED:
		vfClearPin_GPIO(ePortRed_LED ,ePinRed_LED);
		break;
	case eGREEN_LED:
		vfClearPin_GPIO(ePortGreen_LED ,ePinGreen_LED);
		break;
	case eBLUE_LED:
		vfClearPin_GPIO(ePortBlue_LED ,ePinBlue_LED);
		break;
	default:
		break;
	}//End of switch
}
/*! \brief    vfTurnOff_LED
**
** \note	  Turn off the required led calling the function set from
** 			  GPIO_driver.h
** 			  This is because leds on KL25Z turn off with a logic 1
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            eColors_LED_t eColor
**
** \return               NA
*/
void vfTurnOff_LED(eColors_LED_t eColor)
{
	switch(eColor)
	{
	case eRED_LED:
		vfSetPin_GPIO(ePortRed_LED ,ePinRed_LED);
		break;
	case eGREEN_LED:
		vfSetPin_GPIO(ePortGreen_LED ,ePinGreen_LED);
		break;
	case eBLUE_LED:
		vfSetPin_GPIO(ePortBlue_LED ,ePinBlue_LED);
		break;
	default:
		break;
	}//End of switch
}
/*! \brief    vfToggle_LED
**
** \note	  Change the state of the required led calling the function
** 			  Toggle from GPIO_driver.h
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            eColors_LED_t eColor
**
** \return               NA
*/
void vfToggle_LED (eColors_LED_t eColor)
{
	switch(eColor)
	{
	case eRED_LED:
		vfTogglePin_GPIO(ePortRed_LED ,ePinRed_LED);
		break;
	case eGREEN_LED:
		vfTogglePin_GPIO(ePortGreen_LED ,ePinGreen_LED);
		break;
	case eBLUE_LED:
		vfTogglePin_GPIO(ePortBlue_LED ,ePinBlue_LED);
		break;
	default:
		break;
	}//End of switch
}
/*! \brief    efRead_LED
**
** \note	  Read the current state of the required led calling a function
** 			  Read from GPIO_driver.h
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            eColors_LED_t eColor
**
** \return               eStatus_LED_t, A confirmation (success or fail) if active or inactive
*/
eStatus_LED_t efRead_LED   (eColors_LED_t eColor)
{
	eStatus_LED_t eReturn = eFALSE_LED;

	switch(eColor)
	{
	case eRED_LED:
		if( (eStatus_GPIO_t)eTRUE_LED == efReadPin_GPIO(ePortRed_LED ,ePinRed_LED))
		{
			eReturn = eTRUE_LED;
		}else eReturn = eFALSE_LED;
		break;
	case eGREEN_LED:
		if( (eStatus_GPIO_t)eTRUE_LED == efReadPin_GPIO(ePortGreen_LED ,ePinGreen_LED))
		{
			eReturn = eTRUE_LED;
		}else eReturn = eFALSE_LED;
		break;
	case eBLUE_LED:
		if( (eStatus_GPIO_t)eTRUE_LED == efReadPin_GPIO(ePortBlue_LED ,ePinBlue_LED))
		{
			eReturn = eTRUE_LED;
		}else eReturn = eFALSE_LED;
		break;
	default: eReturn = eFALSE_LED;
		break;
	}//End of switch

	return eReturn;
}
