/*
 * PIT_driver.c
 *
 *  Created on: Sep 6, 2018
 *      Author: ivan_
 */
#include "derivative.h"
#include "PIT_driver.h"


uint8_t u8fInit_PIT(uint32_t u32Time, uint8_t u8PitChannel, sPITx_t *sPitx)
{
	uint8_t u8Return = eNOTREADY_PIT;
	
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK; /*Initialize both PIT channels*/
	
	PIT_MCR &= ~PIT_MCR_FRZ_MASK;//Enable debug function
	PIT_MCR &= ~PIT_MCR_MDIS_MASK;//Enable current clock
	
	if(eCHANNEL_0_PIT == u8PitChannel)
	{
		PIT_TCTRL0 &= ~PIT_TCTRL_TEN_MASK;//Disable PIT
		
		//lTime = [((x)/(1/21Mhz))-1]
		PIT_LDVAL0 = u32Time;
		//PIT_CVAL0; Register of only read that contains the current calue of the count
		
		u8Return = eREADY_PIT;
		
	}else if(eCHANNEL_1_PIT == u8PitChannel)
		{
			PIT_TCTRL1 &= ~PIT_TCTRL_TEN_MASK;//Disable PIT
				
			//lTime = [((x)/(1/21Mhz))-1]
			PIT_LDVAL1 = u32Time;
			//PIT_CVAL1; Register of only read that contains the current calue of the count
			
			u8Return = eREADY_PIT;
			
		}else {u8Return = eNOTREADY_PIT;}
	
	sPitx -> u32Time = u32Time;
	sPitx -> u8Channel = u8PitChannel;
	
	return u8Return;
}

uint8_t u8fRead_PIT(sPITx_t *sPitx)
{
	static uint8_t u8Return = eNOTREADY_PIT;
	
	if(eCHANNEL_0_PIT == (sPitx -> u8Channel))
	{
		if( (PIT_TFLG0 & PIT_TFLG_TIF_MASK) == PIT_TFLG_TIF_MASK)//Check the Timer Interrupt Flag
		{
			u8Return = eREADY_PIT;
			PIT_TFLG0 |= PIT_TFLG_TIF_MASK;//Clean flag writing a 1
		}else
			{
				u8Return = eNOTREADY_PIT;
			}
		
	}else if(eCHANNEL_1_PIT == (sPitx -> u8Channel))
		{
			if( (PIT_TFLG0 & PIT_TFLG_TIF_MASK) == PIT_TFLG_TIF_MASK)//Check the Timer Interrupt Flag
			{
				u8Return = eREADY_PIT;
				PIT_TFLG0 |= PIT_TFLG_TIF_MASK;//Clean flag writing a 1
			}else
				{
					u8Return = eNOTREADY_PIT;
				}
		}else u8Return = eNOTREADY_PIT;
	
	return u8Return;
}

void vfEnable_PIT(sPITx_t *sPitx)
{
	if(eCHANNEL_0_PIT == (sPitx -> u8Channel))
	{
		PIT_TCTRL0 |= PIT_TCTRL_TEN_MASK;
	}else if(eCHANNEL_1_PIT == (sPitx -> u8Channel))
		{
			PIT_TCTRL1 |= PIT_TCTRL_TEN_MASK;
		}
}

void vfDisable_PIT(sPITx_t *sPitx)
{
	if(eCHANNEL_0_PIT == (sPitx -> u8Channel))
	{
		PIT_TCTRL0 &= ~PIT_TCTRL_TEN_MASK;	
	}else if(eCHANNEL_1_PIT == (sPitx -> u8Channel))
		{
			PIT_TCTRL0 &= ~PIT_TCTRL_TEN_MASK;	
		}
}

