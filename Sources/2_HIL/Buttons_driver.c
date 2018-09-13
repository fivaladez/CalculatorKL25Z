/*
 * Buttons_driver.c
 *
 *  Created on: Sep 4, 2018
 *      Author: ivan_
 */
#include "Buttons_driver.h"

#define INITIAL_ID			(0x00u)

#define TIME_Button_1S			1800000
#define TIME_Button_500MS		900000
#define TIME_Button_250MS		450000
#define TIME_Button_100MS		180000

static uint8_t u8CounterID = 0;

void vfdelay_Button(uint32_t u32Time);

/*=================================================================================================================*/

eStatus_Buttons_t efCreateButton  (sButton_t *psButton, ePORTx_Buttons_t ePORTx,ePINx_Buttons_t ePINx)
{
	eStatus_Buttons_t eResult = eFALSE;
			
	switch(ePORTx){
		case ePORTA:
			if(ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_4 || ePINx == ePIN_5 || ePINx == ePIN_12 || ePINx == ePIN_13)
			{
				psButton -> u8ID     = INITIAL_ID + u8CounterID;
				psButton -> ePort   = ePORTx;
				psButton -> ePin    = ePINx;
				if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
				{
					eResult = eTRUE;
				}else eResult = eFALSE;
					
			}else eResult = eFALSE;
			break;
		case ePORTB: 
			if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_8 || ePINx == ePIN_9)
			{
				psButton -> u8ID   = INITIAL_ID + u8CounterID;
				psButton -> ePort = ePORTx;
				psButton -> ePin  = ePINx;
				if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
				{
					eResult = eTRUE;
				}else eResult = eFALSE;
			}else eResult = eFALSE;
			break;
		case ePORTC: 
			if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
			|| ePINx == ePIN_6 || ePINx == ePIN_7 || ePINx == ePIN_8 || ePINx == ePIN_9 || ePINx == ePIN_10 || ePINx == ePIN_11 
			|| ePINx == ePIN_12 || ePINx == ePIN_13 || ePINx == ePIN_16 || ePIN_17)
			{
				psButton -> u8ID   = INITIAL_ID + u8CounterID;
				psButton -> ePort = ePORTx;
				psButton -> ePin  = ePINx;
				if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
				{
					eResult = eTRUE;
				}else eResult = eFALSE;
			}else eResult = eFALSE;  
			break;
		case ePORTD: 
			if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
			|| ePINx == ePIN_6 || ePINx == ePIN_7)
			{
				psButton -> u8ID   = INITIAL_ID + u8CounterID;
				psButton -> ePort = ePORTx;
				psButton -> ePin  = ePINx;
				if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
				{
					eResult = eTRUE;
				}else eResult = eFALSE;
			}else eResult = eFALSE;
			break;
		case ePORTE: 
			if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
			|| ePINx == ePIN_20 || ePINx == ePIN_21 || ePINx == ePIN_22 || ePINx == ePIN_23 || ePINx == ePIN_29 || ePINx == ePIN_30)
			{
				psButton -> u8ID   = INITIAL_ID + u8CounterID;
				psButton -> ePort = ePORTx;
				psButton -> ePin  = ePINx;
				if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
				{
					eResult = eTRUE;
				}else eResult = eFALSE;
			}else eResult = eFALSE;  
			break;
		default:     eResult = eFALSE;
		break;
	}//End switch	
	
	u8CounterID++;
	
	return eResult;
}

eStatus_Buttons_t efReadButton    (sButton_t *psButton)
{
	eStatus_Buttons_t eResult = eFALSE;
	
	if( eTRUE  == efReadPort_GPIO(psButton->ePort,psButton->ePin))
	{
		if(eTRUE == efReadPort_GPIO(psButton->ePort,psButton->ePin))
		{
			vfdelay_Button(TIME_Button_100MS);
			if(eTRUE == efReadPort_GPIO(psButton->ePort,psButton->ePin))
			{
				eResult = eTRUE;
			}else eResult = eFALSE;
			
		}else eResult = eFALSE;
		
	}else eResult = eFALSE;
	
	return eResult;
}

void vfdelay_Button(uint32_t u32Time)
{
	while(u32Time--);
}


#ifndef NONBLOCKING

sPITx_t svsPITx;

eStatus_Buttons_t efCreateButtonNonBlocking0(sButtonNonBlocking0_t *psButton, uint8_t ePORTx,uint8_t ePINx)
{
	eStatus_Buttons_t eResult = eFALSE;
	
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
					if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						eResult = eTRUE;
					}else eResult = eFALSE;
						
				}else eResult = eFALSE;
				break;
			case ePORTB: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_8 || ePINx == ePIN_9)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						eResult = eTRUE;
					}else eResult = eFALSE;
				}else eResult = eFALSE;
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
					if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						eResult = eTRUE;
					}else eResult = eFALSE;
				}else eResult = eFALSE;  
				break;
			case ePORTD: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
				|| ePINx == ePIN_6 || ePINx == ePIN_7)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						eResult = eTRUE;
					}else eResult = eFALSE;
				}else eResult = eFALSE;
				break;
			case ePORTE: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
				|| ePINx == ePIN_20 || ePINx == ePIN_21 || ePINx == ePIN_22 || ePINx == ePIN_23 || ePINx == ePIN_29 || ePINx == ePIN_30)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						eResult = eTRUE;
					}else eResult = eFALSE;
				}else eResult = eFALSE;  
				break;
			default:     eResult = eFALSE;
			break;
		}//End switch	
	
	u8CounterID++;
	
	}else eResult = eFALSE;//Else of if PIT state
	
	
	return eResult;
}

eStatus_Buttons_t efCreateButtonNonBlocking1(sButtonNonBlocking1_t *psButton, uint8_t ePORTx,uint8_t ePINx)
{
	eStatus_Buttons_t eResult = eFALSE;
	
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
					if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						eResult = eTRUE;
					}else eResult = eFALSE;
						
				}else eResult = eFALSE;
				break;
			case ePORTB: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_8 || ePINx == ePIN_9)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						eResult = eTRUE;
					}else eResult = eFALSE;
				}else eResult = eFALSE;
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
					if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						eResult = eTRUE;
					}else eResult = eFALSE;
				}else eResult = eFALSE;  
				break;
			case ePORTD: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
				|| ePINx == ePIN_6 || ePINx == ePIN_7)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						eResult = eTRUE;
					}else eResult = eFALSE;
				}else eResult = eFALSE;
				break;
			case ePORTE: 
				if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
				|| ePINx == ePIN_20 || ePINx == ePIN_21 || ePINx == ePIN_22 || ePINx == ePIN_23 || ePINx == ePIN_29 || ePINx == ePIN_30)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> ePort = ePORTx;
					psButton -> ePin  = ePINx;
					psButton -> eState  = eSTATE_READ_1;
					if(eTRUE == efInit_GPIO(psButton -> ePort, psButton -> ePin, eINPUT))
					{
						eResult = eTRUE;
					}else eResult = eFALSE;
				}else eResult = eFALSE;  
				break;
			default:     eResult = eFALSE;
			break;
		}//End switch	
	
	u8CounterID++;
	
	}else eResult = eFALSE;//Else of if PIT state
	
	
	return eResult;
}

eStatus_Buttons_t efReadButtonNonBlocking0(sButtonNonBlocking0_t *psButton)
{
	eStatus_Buttons_t eResult = eFALSE;
	eState_Buttons_t eStateReadButton = psButton -> eState;
	
	switch(eStateReadButton)
	{
	case eSTATE_READ_1: 
		if(eTRUE == efReadPort_GPIO(psButton->ePort,psButton->ePin))
		{
			eResult = eFALSE;
			eStateReadButton = eSTATE_WAIT_2;
			vfDisable_PIT(&svsPITx);
			vfEnable_PIT(&svsPITx);
		}else
			{
				eResult = eFALSE;
				eStateReadButton = eSTATE_READ_1;
				vfDisable_PIT(&svsPITx);
			}
		break;
	case eSTATE_WAIT_2:
		if( eREADY_PIT == u8fRead_PIT(&svsPITx) )
		{
			eResult = eFALSE;
			eStateReadButton = eSTATE_READ_3;
			vfDisable_PIT(&svsPITx);
		}else 
			{
				eResult = eFALSE;
				eStateReadButton = eSTATE_WAIT_2;
			}
		
		break;
	case eSTATE_READ_3:
		if(eTRUE == efReadPort_GPIO(psButton->ePort,psButton->ePin))
		{
			eResult = eTRUE;
			eStateReadButton = eSTATE_READ_1;
		}else
			{
				eResult = eFALSE;
				eStateReadButton = eSTATE_READ_1;
			}
		break;
	default: 
		eResult = eFALSE;
		eStateReadButton = eSTATE_READ_1;
		break;
	
	}//End of switch
	
	psButton -> eState  = eStateReadButton;
	
	return eResult;
}

eStatus_Buttons_t efReadButtonNonBlocking1(sButtonNonBlocking1_t *psButton)
{
	eStatus_Buttons_t eResult = eFALSE;
	eState_Buttons_t eStateReadButton = psButton -> eState;
	
	switch(eStateReadButton)
	{
	case eSTATE_READ_1: 
		if(eTRUE == efReadPort_GPIO(psButton->ePort,psButton->ePin))
		{
			eResult = eFALSE;
			eStateReadButton = eSTATE_WAIT_2;
			vfDisable_PIT(&svsPITx);
			vfEnable_PIT(&svsPITx);
		}else
			{
				eResult = eFALSE;
				eStateReadButton = eSTATE_READ_1;
				vfDisable_PIT(&svsPITx);
			}
		break;
	case eSTATE_WAIT_2:
		if( eREADY_PIT == u8fRead_PIT(&svsPITx) )
		{
			eResult = eFALSE;
			eStateReadButton = eSTATE_READ_3;
			vfDisable_PIT(&svsPITx);
		}else 
			{
				eResult = eFALSE;
				eStateReadButton = eSTATE_WAIT_2;
			}
		
		break;
	case eSTATE_READ_3:
		if(eTRUE == efReadPort_GPIO(psButton->ePort,psButton->ePin))
		{
			eResult = eTRUE;
			eStateReadButton = eSTATE_READ_1;
		}else
			{
				eResult = eFALSE;
				eStateReadButton = eSTATE_READ_1;
			}
		break;
	default: 
		eResult = eFALSE;
		eStateReadButton = eSTATE_READ_1;
		break;
	
	}//End of switch
	
	psButton -> eState  = eStateReadButton;
	
	return eResult;
}

#endif
