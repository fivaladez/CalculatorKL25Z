/*
 * Buttons_driver.c
 *
 *  Created on: Sep 4, 2018
 *      Author: ivan_
 */
#include "derivative.h"
#include "Buttons_driver.h"
#include "PIT_driver.h"

#define INITIAL_ID			(0x00u)

#define TIME_Button_1S			1800000
#define TIME_Button_500MS		900000
#define TIME_Button_250MS		450000
#define TIME_Button_100MS		180000

static uint8_t u8CounterID = 0;

void vfdelay_Button(uint32_t u32Time);

/*=================================================================================================================*/

eStatus_Buttons_t u8fCreateButton  (sButton_t *psButton, ePORTx_Buttons_t ePORTx,ePINx_Buttons_t ePINx)
{
	eStatus_Buttons_t u8Result = eFALSE;
			
	switch(ePORTx){
		case ePORTA:
			if(ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_4 || ePINx == ePIN_5 || ePINx == ePIN_12 || ePINx == ePIN_13)
			{
				psButton -> u8ID     = INITIAL_ID + u8CounterID;
				psButton -> ePort   = ePORTx;
				psButton -> ePin    = ePINx;
				if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
				{
					u8Result = eTRUE;
				}else u8Result = eFALSE;
					
			}else u8Result = eFALSE;
			break;
		case ePORTB: 
			if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_8 || ePINx == ePIN_9)
			{
				psButton -> u8ID   = INITIAL_ID + u8CounterID;
				psButton -> ePort = ePORTx;
				psButton -> ePin  = ePINx;
				if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
				{
					u8Result = eTRUE;
				}else u8Result = eFALSE;
			}else u8Result = eFALSE;
			break;
		case ePORTC: 
			if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
			|| ePINx == ePIN_6 || ePINx == ePIN_7 || ePINx == ePIN_8 || ePINx == ePIN_9 || ePINx == ePIN_10 || ePINx == ePIN_11 
			|| ePINx == ePIN_12 || ePINx == ePIN_13 || ePINx == ePIN_16 || ePIN_17)
			{
				psButton -> u8ID   = INITIAL_ID + u8CounterID;
				psButton -> ePort = ePORTx;
				psButton -> ePin  = ePINx;
				if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
				{
					u8Result = eTRUE;
				}else u8Result = eFALSE;
			}else u8Result = eFALSE;  
			break;
		case ePORTD: 
			if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
			|| ePINx == ePIN_6 || ePINx == ePIN_7)
			{
				psButton -> u8ID   = INITIAL_ID + u8CounterID;
				psButton -> ePort = ePORTx;
				psButton -> ePin  = ePINx;
				if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
				{
					u8Result = eTRUE;
				}else u8Result = eFALSE;
			}else u8Result = eFALSE;
			break;
		case ePORTE: 
			if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
			|| ePINx == ePIN_20 || ePINx == ePIN_21 || ePINx == ePIN_22 || ePINx == ePIN_23 || ePINx == ePIN_29 || ePINx == ePIN_30)
			{
				psButton -> u8ID   = INITIAL_ID + u8CounterID;
				psButton -> ePort = ePORTx;
				psButton -> ePin  = ePINx;
				if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
				{
					u8Result = eTRUE;
				}else u8Result = eFALSE;
			}else u8Result = eFALSE;  
			break;
		default:     u8Result = eFALSE;
		break;
	}//End switch	
	
	u8CounterID++;
	
	return u8Result;
}

eStatus_Buttons_t u8fReadButton    (sButton_t *psButton)
{
	eStatus_Buttons_t u8Result = eFALSE;
	
	if( eTRUE  == u8fReadPort_GPIO(psButton->ePort,psButton->ePin))
	{
		if(eTRUE == u8fReadPort_GPIO(psButton->ePort,psButton->ePin))
		{
			vfdelay_Button(TIME_Button_100MS);
			if(eTRUE == u8fReadPort_GPIO(psButton->ePort,psButton->ePin))
			{
				u8Result = eTRUE;
			}else u8Result = eFALSE;
			
		}else u8Result = eFALSE;
		
	}else u8Result = eFALSE;
	
	return u8Result;
}

void vfdelay_Button(uint32_t u32Time)
{
	while(u32Time--);
}


#ifndef NONBLOCKING

sPITx_t svsPITx;

eStatus_Buttons_t u8fCreateButtonNonBlocking0(sButtonNonBlocking0_t *psButton, uint8_t ePORTx,uint8_t ePINx)
{
	eStatus_Buttons_t u8Result = eFALSE;
	
	if( eREADY_PIT == u8fInit_PIT(LDVAL_1S, eCHANNEL_0_PIT, &svsPITx) )
	{
			
		switch(ePORTx){
			case ePORTA:
				if(ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_4 || ePINx == ePIN_5 || ePINx == ePIN_12 || ePINx == ePIN_13)
				{
					psButton -> u8ID     = INITIAL_ID + u8CounterID;
					psButton -> ePort   = ePORTx;
					psButton -> ePin    = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
						
				}else u8Result = eFALSE;
				break;
			case ePORTB: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_8 || ePINx == ePIN_9)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;
				break;
			case ePORTC: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
				|| ePINx == ePIN_6 || ePINx == ePIN_7 || ePINx == ePIN_8 || ePINx == ePIN_9 || ePINx == ePIN_10 || ePINx == ePIN_11 
				|| ePINx == ePIN_12 || ePINx == ePIN_13 || ePINx == ePIN_16 || ePIN_17)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;  
				break;
			case ePORTD: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
				|| ePINx == ePIN_6 || ePINx == ePIN_7)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;
				break;
			case ePORTE: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
				|| ePINx == ePIN_20 || ePINx == ePIN_21 || ePINx == ePIN_22 || ePINx == ePIN_23 || ePINx == ePIN_29 || ePINx == ePIN_30)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;  
				break;
			default:     u8Result = eFALSE;
			break;
		}//End switch	
	
	u8CounterID++;
	
	}else u8Result = eFALSE;//Else of if PIT state
	
	
	return u8Result;
}

eStatus_Buttons_t u8fCreateButtonNonBlocking1(sButtonNonBlocking1_t *psButton, uint8_t ePORTx,uint8_t ePINx)
{
	eStatus_Buttons_t u8Result = eFALSE;
	
	if( eREADY_PIT == u8fInit_PIT(LDVAL_1S, eCHANNEL_1_PIT, &svsPITx) )
	{
			
		switch(ePORTx){
			case ePORTA:
				if(ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_4 || ePINx == ePIN_5 || ePINx == ePIN_12 || ePINx == ePIN_13)
				{
					psButton -> u8ID     = INITIAL_ID + u8CounterID;
					psButton -> ePort   = ePORTx;
					psButton -> ePin    = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
						
				}else u8Result = eFALSE;
				break;
			case ePORTB: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_8 || ePINx == ePIN_9)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;
				break;
			case ePORTC: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
				|| ePINx == ePIN_6 || ePINx == ePIN_7 || ePINx == ePIN_8 || ePINx == ePIN_9 || ePINx == ePIN_10 || ePINx == ePIN_11 
				|| ePINx == ePIN_12 || ePINx == ePIN_13 || ePINx == ePIN_16 || ePIN_17)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;  
				break;
			case ePORTD: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
				|| ePINx == ePIN_6 || ePINx == ePIN_7)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;
				break;
			case ePORTE: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
				|| ePINx == ePIN_20 || ePINx == ePIN_21 || ePINx == ePIN_22 || ePINx == ePIN_23 || ePINx == ePIN_29 || ePINx == ePIN_30)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;  
				break;
			default:     u8Result = eFALSE;
			break;
		}//End switch	
	
	u8CounterID++;
	
	}else u8Result = eFALSE;//Else of if PIT state
	
	
	return u8Result;
}

eStatus_Buttons_t u8fReadButtonNonBlocking0(sButtonNonBlocking0_t *psButton)
{
	eStatus_Buttons_t u8Result = eFALSE;
	eState_Buttons_t eStateReadButton = psButton -> eState;
	
	switch(eStateReadButton)
	{
	case eSTATE_READ_1: 
		if(eTRUE == u8fReadPort_GPIO(psButton->ePort,psButton->ePin))
		{
			u8Result = eFALSE;
			eStateReadButton = eSTATE_WAIT_2;
			vfDisable_PIT(&svsPITx);
			vfEnable_PIT(&svsPITx);
		}else
			{
				u8Result = eFALSE;
				eStateReadButton = eSTATE_READ_1;
				vfDisable_PIT(&svsPITx);
			}
		break;
	case eSTATE_WAIT_2:
		if( eREADY_PIT == u8fRead_PIT(&svsPITx) )
		{
			u8Result = eFALSE;
			eStateReadButton = eSTATE_READ_3;
			vfDisable_PIT(&svsPITx);
		}else 
			{
				u8Result = eFALSE;
				eStateReadButton = eSTATE_WAIT_2;
			}
		
		break;
	case eSTATE_READ_3:
		if(eTRUE == u8fReadPort_GPIO(psButton->ePort,psButton->ePin))
		{
			u8Result = eTRUE;
			eStateReadButton = eSTATE_READ_1;
		}else
			{
				u8Result = eFALSE;
				eStateReadButton = eSTATE_READ_1;
			}
		break;
	default: 
		u8Result = eFALSE;
		eStateReadButton = eSTATE_READ_1;
		break;
	
	}//End of switch
	
	psButton -> eState  = eStateReadButton;
	
	return u8Result;
}

eStatus_Buttons_t u8fReadButtonNonBlocking1(sButtonNonBlocking1_t *psButton)
{
	eStatus_Buttons_t u8Result = eFALSE;
	eState_Buttons_t eStateReadButton = psButton -> eState;
	
	switch(eStateReadButton)
	{
	case eSTATE_READ_1: 
		if(eTRUE == u8fReadPort_GPIO(psButton->ePort,psButton->ePin))
		{
			u8Result = eFALSE;
			eStateReadButton = eSTATE_WAIT_2;
			vfDisable_PIT(&svsPITx);
			vfEnable_PIT(&svsPITx);
		}else
			{
				u8Result = eFALSE;
				eStateReadButton = eSTATE_READ_1;
				vfDisable_PIT(&svsPITx);
			}
		break;
	case eSTATE_WAIT_2:
		if( eREADY_PIT == u8fRead_PIT(&svsPITx) )
		{
			u8Result = eFALSE;
			eStateReadButton = eSTATE_READ_3;
			vfDisable_PIT(&svsPITx);
		}else 
			{
				u8Result = eFALSE;
				eStateReadButton = eSTATE_WAIT_2;
			}
		
		break;
	case eSTATE_READ_3:
		if(eTRUE == u8fReadPort_GPIO(psButton->ePort,psButton->ePin))
		{
			u8Result = eTRUE;
			eStateReadButton = eSTATE_READ_1;
		}else
			{
				u8Result = eFALSE;
				eStateReadButton = eSTATE_READ_1;
			}
		break;
	default: 
		u8Result = eFALSE;
		eStateReadButton = eSTATE_READ_1;
		break;
	
	}//End of switch
	
	psButton -> eState  = eStateReadButton;
	
	return u8Result;
}

#endif
