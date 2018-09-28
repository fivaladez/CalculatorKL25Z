/*
 * PIT_driver.c
 *
 *  Created on: Sep 6, 2018
 *      Author: ivan_
 */

#include "PIT_driver.h"

eState_PIT_t efInit_PIT(u32Time_PIT_t u32Time_PIT, eChannelx_PIT_t eChannel_PIT, sPITx_t *sPitx)
{
	eState_PIT_t u8Return = eNOTREADY_PIT;
	
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK; /*Initialize both PIT channels*/
	
	PIT_MCR &= ~PIT_MCR_FRZ_MASK;//Enable debug function
	PIT_MCR &= ~PIT_MCR_MDIS_MASK;//Enable current clock
	
	if(eCHANNEL_0_PIT == eChannel_PIT)
	{
		PIT_TCTRL0 &= ~PIT_TCTRL_TEN_MASK;//Disable PIT
		
		//lTime = [((x)/(1/21Mhz))-1]
		PIT_LDVAL0 = u32Time_PIT;
		//PIT_CVAL0; Register of only read that contains the current calue of the count
		
		u8Return = eREADY_PIT;
		
		sPitx -> u32Time_PIT = u32Time_PIT;
		sPitx -> eChannel_PIT = eCHANNEL_0_PIT;
		sPitx -> eState_PIT = eNOTREADY_PIT;
		
	}else if(eCHANNEL_1_PIT == eChannel_PIT)
		{
			PIT_TCTRL1 &= ~PIT_TCTRL_TEN_MASK;//Disable PIT
				
			//lTime = [((x)/(1/21Mhz))-1]
			PIT_LDVAL1 = u32Time_PIT;
			//PIT_CVAL1; Register of only read that contains the current calue of the count
			
			u8Return = eREADY_PIT;
			
			sPitx -> u32Time_PIT = u32Time_PIT;
			sPitx -> eChannel_PIT = eCHANNEL_1_PIT;
			sPitx -> eState_PIT = eNOTREADY_PIT;
			
		}else {u8Return = eNOTREADY_PIT;}
	
	return u8Return;
}

eState_PIT_t efRead_PIT(sPITx_t *sPitx)
{
	
	if(eCHANNEL_0_PIT == (sPitx -> eChannel_PIT))
	{
		if( (PIT_TFLG0 & PIT_TFLG_TIF_MASK) == PIT_TFLG_TIF_MASK)//Check the Timer Interrupt Flag
		{
			sPitx -> eState_PIT = eREADY_PIT;
			PIT_TFLG0 |= PIT_TFLG_TIF_MASK;//Clean flag writing a 1
		}else
			{
				sPitx -> eState_PIT = eNOTREADY_PIT;
			}
		
	}else if(eCHANNEL_1_PIT == (sPitx -> eChannel_PIT))
		{
			if( (PIT_TFLG1 & PIT_TFLG_TIF_MASK) == PIT_TFLG_TIF_MASK)//Check the Timer Interrupt Flag
			{
				sPitx -> eState_PIT = eREADY_PIT;
				PIT_TFLG1 |= PIT_TFLG_TIF_MASK;//Clean flag writing a 1
			}else
				{
					sPitx -> eState_PIT = eNOTREADY_PIT;
				}
		}else sPitx -> eState_PIT = eNOTREADY_PIT;
	
	return sPitx -> eState_PIT;
}

void vfEnable_PIT(sPITx_t *sPitx)
{
	if(eCHANNEL_0_PIT == (sPitx -> eChannel_PIT))
	{
		PIT_TCTRL0 |= PIT_TCTRL_TEN_MASK;
	}else if(eCHANNEL_1_PIT == (sPitx -> eChannel_PIT))
		{
			PIT_TCTRL1 |= PIT_TCTRL_TEN_MASK;
		}
}

void vfDisable_PIT(sPITx_t *sPitx)
{
	if(eCHANNEL_0_PIT == (sPitx -> eChannel_PIT))
	{
		PIT_TCTRL0 &= ~PIT_TCTRL_TEN_MASK;	
	}else if(eCHANNEL_1_PIT == (sPitx -> eChannel_PIT))
		{
			PIT_TCTRL0 &= ~PIT_TCTRL_TEN_MASK;	
		}
}
