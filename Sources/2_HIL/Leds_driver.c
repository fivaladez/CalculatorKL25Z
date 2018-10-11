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
/*---------------------------------------------------------------------------
** Data
*/
/* You MUST check the ports and pins of your MCU because these are
 * for the KL25Z */
ePORTx_LED_t ePortRed_LED   = ePORTB;	ePINx_LED_t ePinRed_LED     = ePIN_18;
ePORTx_LED_t ePortGreen_LED = ePORTB;	ePINx_LED_t ePinGreen_LED   = ePIN_19;
ePORTx_LED_t ePortBlue_LED  = ePORTD;	ePINx_LED_t ePinBlue_LED    = ePIN_1;
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
eStates_LED_t efInit_LED   (eColors_LED_t eColor)
{
	eStates_LED_t eReturn = eFALSE;
	switch(eColor)
	{
	case eRED:
		if(eTRUE == efInit_GPIO(ePortRed_LED ,ePinRed_LED, eOUTPUT))
		{
			eReturn = eTRUE;
		}else eReturn = eFALSE;
		break;
	case eGREEN:
		if(eTRUE == efInit_GPIO(ePortGreen_LED ,ePinGreen_LED, eOUTPUT))
		{
			eReturn = eTRUE;
		}else eReturn = eFALSE;
		break;
	case eBLUE:
		if(eTRUE == efInit_GPIO(ePortBlue_LED ,ePinBlue_LED, eOUTPUT))
		{
			eReturn = eTRUE;
		}else eReturn = eFALSE;
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
	case eRED:
		vfClearPin_GPIO(ePortRed_LED ,ePinRed_LED);
		break;
	case eGREEN:
		vfClearPin_GPIO(ePortGreen_LED ,ePinGreen_LED);
		break;
	case eBLUE:
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
	case eRED:
		vfSetPin_GPIO(ePortRed_LED ,ePinRed_LED);
		break;
	case eGREEN:
		vfSetPin_GPIO(ePortGreen_LED ,ePinGreen_LED);
		break;
	case eBLUE:
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
	case eRED:
		vfTogglePin_GPIO(ePortRed_LED ,ePinRed_LED);
		break;
	case eGREEN:
		vfTogglePin_GPIO(ePortGreen_LED ,ePinGreen_LED);
		break;
	case eBLUE:
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
** \return               eStates_LED_t, A confirmation (success or fail) if active or inactive
*/
eStates_LED_t efRead_LED   (eColors_LED_t eColor)
{
	eStates_LED_t eReturn = eFALSE;

	switch(eColor)
	{
	case eRED:
		if( eTRUE == efReadPin_GPIO(ePortRed_LED ,ePinRed_LED))
		{
			eReturn = eTRUE;
		}else eReturn = eFALSE;
		break;
	case eGREEN:
		if( eTRUE == efReadPin_GPIO(ePortGreen_LED ,ePinGreen_LED))
		{
			eReturn = eTRUE;
		}else eReturn = eFALSE;
		break;
	case eBLUE:
		if( eTRUE == efReadPin_GPIO(ePortBlue_LED ,ePinBlue_LED))
		{
			eReturn = eTRUE;
		}else eReturn = eFALSE;
		break;
	default: eReturn = eFALSE;
		break;
	}//End of switch

	return eReturn;
}
