/*
 * Leds_driver.c
 *
 *  Created on: Sep 12, 2018
 *      Author: ivan_
 */
#include "Leds_driver.h"

ePORTx_LED_t ePortRed_LED   = ePORTB;		ePINx_LED_t ePinRed_LED     = ePIN_18;
ePORTx_LED_t ePortGreen_LED = ePORTB;		ePINx_LED_t ePinGreen_LED   = ePIN_19;
ePORTx_LED_t ePortBlue_LED  = ePORTD;		ePINx_LED_t ePinBlue_LED    = ePIN_1;

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

