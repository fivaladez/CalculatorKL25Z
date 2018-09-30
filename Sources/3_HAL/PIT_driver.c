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
	
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK; /* 1° Initialize both PIT channels*/
	
	PIT_MCR &= ~PIT_MCR_MDIS_MASK;	/*	Clock for standard PIT timers is enabled	*/
	//PIT_MCR &= ~PIT_MCR_FRZ_MASK;	/*	Timers continue to run in Debug mode.	*/
	PIT_MCR &= ~PIT_MCR_FRZ_MASK;	/*	Timers are stopped in Debug mode.	*/
	
	if(eCHANNEL_0_PIT == eChannel_PIT)
	{
		PIT_TCTRL0 &= ~PIT_TCTRL_CHN_MASK;	/*	Timer is not chained	*/
		PIT_TCTRL0 &= ~PIT_TCTRL_TEN_MASK;	/*	Timer n is disabled.	*/
		
#if INTERRUPTS_ENABLE == 0
		PIT_TCTRL0 &= ~PIT_TCTRL_TIE_MASK;	/*	Interrupt requests from Timer n are disabled*/
#else 
		PIT_TCTRL0 |= PIT_TCTRL_TIE_MASK;	/*	Interrupt will be requested whenever TIF is set.*/
#endif

		/*	lTime = [((x)/(1/21Mhz))-1]	*/
		PIT_LDVAL0 = u32Time_PIT;			/*	Timer Start Value	*/
		//PIT_CVAL0; 						/*	Current Timer Value	*/
		
		u8Return = eREADY_PIT;
		
		sPitx -> u32Time_PIT = u32Time_PIT;
		sPitx -> eChannel_PIT = eCHANNEL_0_PIT;
		sPitx ->  eState_PIT = eNOTREADY_PIT;
		
	}else if(eCHANNEL_1_PIT == eChannel_PIT)
		{
			
			PIT_TCTRL1 &= ~PIT_TCTRL_CHN_MASK;	
			PIT_TCTRL1 &= ~PIT_TCTRL_TEN_MASK;
			
#if INTERRUPTS_ENABLE == 0
			PIT_TCTRL1 &= ~PIT_TCTRL_TIE_MASK;	/*	Interrupt requests from Timer n are disabled*/
#else 
			PIT_TCTRL1 |= PIT_TCTRL_TIE_MASK;	/*	Interrupt will be requested whenever TIF is set.*/
#endif
			
			//lTime = [((x)/(1/21Mhz))-1]
			PIT_LDVAL1 = u32Time_PIT;
			
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
		/*Check Timer Interrupt Flag is different of zero, 1*/
		if( PIT_TFLG0 & PIT_TFLG_TIF_MASK )
		{
			sPitx -> eState_PIT = eREADY_PIT;
			
			/*	Writing 1 to this flag clears it	*/
			PIT_TFLG0 |= PIT_TFLG_TIF_MASK;	/*	Timer Interrupt Flag	*/
		}else
			{
				sPitx -> eState_PIT = eNOTREADY_PIT;
			}
		
	}else if(eCHANNEL_1_PIT == (sPitx -> eChannel_PIT))
		{
			if( PIT_TFLG1 & PIT_TFLG_TIF_MASK )
			{
				sPitx -> eState_PIT = eREADY_PIT;
				PIT_TFLG1 |= PIT_TFLG_TIF_MASK;
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

#if INTERRUPTS_ENABLE == 0
#else
void vfPIT_IRQHandler (void)
{
	/*Check Timer Interrupt Flag is different of zero, 1*/
	if( PIT_TFLG0 & PIT_TFLG_TIF_MASK )
	{		
		PIT_TFLG0 |= PIT_TFLG_TIF_MASK;	/*	Clean Timer Interrupt Flag	*/
	}else if( PIT_TFLG1 & PIT_TFLG_TIF_MASK )
	{
		PIT_TFLG1 |= PIT_TFLG_TIF_MASK;
	}
			
}
#endif
