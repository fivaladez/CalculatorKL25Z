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
#define LIMIT_PINx			(0x19u)

#define TIME_Button_1S			1800000
#define TIME_Button_500MS		900000
#define TIME_Button_250MS		450000
#define TIME_Button_100MS		180000
#define TIME_Button_50MS		90000
#define TIME_Button_25MS		45000
#define TIME_Button_10MS		18000
#define TIME_Button_5MS			9000
#define TIME_Button_3MS			4500
#define TIME_Button_1MS			1000
#define TIME_Button_500US		500
#define TIME_Button_250US		250

static uint8_t u8CounterID = 0;

sPITx_t svsPITx;

uint8_t u8fReadButtonFast(sButton_t *psButton);

void vfdelay_Button(uint32_t u32Time);

/*=================================================================================================================*/

void vfdelay_Button(uint32_t u32Time)
{
	uint32_t u32Value = 0;
	for(u32Value = u32Time; 0 < u32Value; u32Value--){/*Do nothing*/}
}

/*=================================================================================================================*/

uint8_t u8fReadButtonFast(sButton_t *psButton)
{
	uint8_t u8Result = eFALSE;
	
	if(eTRUE == u8fReadPort_GPIO(psButton->u8Port,psButton->u8Pin))
	{	
		u8Result = eTRUE;
		
	}else u8Result = eFALSE;
	
	return u8Result;
}

/*=================================================================================================================*/

uint8_t u8fReadButton(sButton_t *psButton)
{
	uint8_t u8Result = eFALSE;
	
	if( eTRUE  == u8fReadPort_GPIO(psButton->u8Port,psButton->u8Pin))
	{
		if(eTRUE == u8fReadPort_GPIO(psButton->u8Port,psButton->u8Pin))
		{
			vfdelay_Button(TIME_Button_100MS);
			if(eTRUE == u8fReadPort_GPIO(psButton->u8Port,psButton->u8Pin))
			{
				u8Result = eTRUE;
			}else u8Result = eFALSE;
			
		}else u8Result = eFALSE;
		
	}else u8Result = eFALSE;
	
	return u8Result;
}

/*=================================================================================================================*/

uint8_t u8fReadButtonNonBlocking0(sButtonNonBlocking0_t *psButton)
{
	uint8_t u8Result = eFALSE;
	uint8_t u8StateReadButton = psButton -> u8State;
	
	switch(u8StateReadButton)
	{
	case eSTATE_READ_1: 
		if(eTRUE == u8fReadPort_GPIO(psButton->u8Port,psButton->u8Pin))
		{
			u8Result = eFALSE;
			u8StateReadButton = eSTATE_WAIT_2;
			vfDisable_PIT(&svsPITx);
			vfEnable_PIT(&svsPITx);
		}else
			{
				u8Result = eFALSE;
				u8StateReadButton = eSTATE_READ_1;
				vfDisable_PIT(&svsPITx);
			}
		break;
	case eSTATE_WAIT_2:
		if( eREADY_PIT == u8fRead_PIT(&svsPITx) )
		{
			u8Result = eFALSE;
			u8StateReadButton = eSTATE_READ_3;
			vfDisable_PIT(&svsPITx);
		}else 
			{
				u8Result = eFALSE;
				u8StateReadButton = eSTATE_WAIT_2;
			}
		
		break;
	case eSTATE_READ_3:
		if(eTRUE == u8fReadPort_GPIO(psButton->u8Port,psButton->u8Pin))
		{
			u8Result = eTRUE;
			u8StateReadButton = eSTATE_READ_1;
		}else
			{
				u8Result = eFALSE;
				u8StateReadButton = eSTATE_READ_1;
			}
		break;
	default: 
		u8Result = eFALSE;
		u8StateReadButton = eSTATE_READ_1;
		break;
	
	}//End of switch
	
	psButton -> u8State  = u8StateReadButton;
	
	return u8Result;
}

/*=================================================================================================================*/

uint8_t u8fReadButtonNonBlocking1(sButtonNonBlocking1_t *psButton)
{
	uint8_t u8Result = eFALSE;
	uint8_t u8StateReadButton = psButton -> u8State;
	
	switch(u8StateReadButton)
	{
	case eSTATE_READ_1: 
		if(eTRUE == u8fReadPort_GPIO(psButton->u8Port,psButton->u8Pin))
		{
			u8Result = eFALSE;
			u8StateReadButton = eSTATE_WAIT_2;
			vfDisable_PIT(&svsPITx);
			vfEnable_PIT(&svsPITx);
		}else
			{
				u8Result = eFALSE;
				u8StateReadButton = eSTATE_READ_1;
				vfDisable_PIT(&svsPITx);
			}
		break;
	case eSTATE_WAIT_2:
		if( eREADY_PIT == u8fRead_PIT(&svsPITx) )
		{
			u8Result = eFALSE;
			u8StateReadButton = eSTATE_READ_3;
			vfDisable_PIT(&svsPITx);
		}else 
			{
				u8Result = eFALSE;
				u8StateReadButton = eSTATE_WAIT_2;
			}
		
		break;
	case eSTATE_READ_3:
		if(eTRUE == u8fReadPort_GPIO(psButton->u8Port,psButton->u8Pin))
		{
			u8Result = eTRUE;
			u8StateReadButton = eSTATE_READ_1;
		}else
			{
				u8Result = eFALSE;
				u8StateReadButton = eSTATE_READ_1;
			}
		break;
	default: 
		u8Result = eFALSE;
		u8StateReadButton = eSTATE_READ_1;
		break;
	
	}//End of switch
	
	psButton -> u8State  = u8StateReadButton;
	
	return u8Result;
}

/*=================================================================================================================*/

uint8_t u8fCreateButton(sButton_t *psButton, uint8_t u8PORTx,uint8_t u8PINx)
{
	uint8_t u8Result = eFALSE;
			
	switch(u8PORTx){
		case ePORTA:
			if(u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_4 || u8PINx == ePIN_5 || u8PINx == ePIN_12 || u8PINx == ePIN_13)
			{
				psButton -> u8ID     = INITIAL_ID + u8CounterID;
				psButton -> u8Port   = u8PORTx;
				psButton -> u8Pin    = u8PINx;
				if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
				{
					u8Result = eTRUE;
				}else u8Result = eFALSE;
					
			}else u8Result = eFALSE;
			break;
		case ePORTB: 
			if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_8 || u8PINx == ePIN_9)
			{
				psButton -> u8ID   = INITIAL_ID + u8CounterID;
				psButton -> u8Port = u8PORTx;
				psButton -> u8Pin  = u8PINx;
				if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
				{
					u8Result = eTRUE;
				}else u8Result = eFALSE;
			}else u8Result = eFALSE;
			break;
		case ePORTC: 
			if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 
			|| u8PINx == ePIN_6 || u8PINx == ePIN_7 || u8PINx == ePIN_8 || u8PINx == ePIN_9 || u8PINx == ePIN_10 || u8PINx == ePIN_11 
			|| u8PINx == ePIN_12 || u8PINx == ePIN_13 || u8PINx == ePIN_16 || ePIN_17)
			{
				psButton -> u8ID   = INITIAL_ID + u8CounterID;
				psButton -> u8Port = u8PORTx;
				psButton -> u8Pin  = u8PINx;
				if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
				{
					u8Result = eTRUE;
				}else u8Result = eFALSE;
			}else u8Result = eFALSE;  
			break;
		case ePORTD: 
			if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 
			|| u8PINx == ePIN_6 || u8PINx == ePIN_7)
			{
				psButton -> u8ID   = INITIAL_ID + u8CounterID;
				psButton -> u8Port = u8PORTx;
				psButton -> u8Pin  = u8PINx;
				if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
				{
					u8Result = eTRUE;
				}else u8Result = eFALSE;
			}else u8Result = eFALSE;
			break;
		case ePORTE: 
			if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 
			|| u8PINx == ePIN_20 || u8PINx == ePIN_21 || u8PINx == ePIN_22 || u8PINx == ePIN_23 || u8PINx == ePIN_29 || u8PINx == ePIN_30)
			{
				psButton -> u8ID   = INITIAL_ID + u8CounterID;
				psButton -> u8Port = u8PORTx;
				psButton -> u8Pin  = u8PINx;
				if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
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

/*=================================================================================================================*/

uint8_t u8fCreateButtonNonBlocking0(sButtonNonBlocking0_t *psButton, uint8_t u8PORTx,uint8_t u8PINx)
{
	uint8_t u8Result = eFALSE;
	
	if( eREADY_PIT == u8fInit_PIT(LDVAL_1S, eCHANNEL_0_PIT, &svsPITx) )
	{
			
		switch(u8PORTx){
			case ePORTA:
				if(u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_4 || u8PINx == ePIN_5 || u8PINx == ePIN_12 || u8PINx == ePIN_13)
				{
					psButton -> u8ID     = INITIAL_ID + u8CounterID;
					psButton -> u8Port   = u8PORTx;
					psButton -> u8Pin    = u8PINx;
					psButton -> u8State  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
						
				}else u8Result = eFALSE;
				break;
			case ePORTB: 
				if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_8 || u8PINx == ePIN_9)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> u8Port = u8PORTx;
					psButton -> u8Pin  = u8PINx;
					psButton -> u8State  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;
				break;
			case ePORTC: 
				if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 
				|| u8PINx == ePIN_6 || u8PINx == ePIN_7 || u8PINx == ePIN_8 || u8PINx == ePIN_9 || u8PINx == ePIN_10 || u8PINx == ePIN_11 
				|| u8PINx == ePIN_12 || u8PINx == ePIN_13 || u8PINx == ePIN_16 || ePIN_17)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> u8Port = u8PORTx;
					psButton -> u8Pin  = u8PINx;
					psButton -> u8State  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;  
				break;
			case ePORTD: 
				if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 
				|| u8PINx == ePIN_6 || u8PINx == ePIN_7)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> u8Port = u8PORTx;
					psButton -> u8Pin  = u8PINx;
					psButton -> u8State  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;
				break;
			case ePORTE: 
				if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 
				|| u8PINx == ePIN_20 || u8PINx == ePIN_21 || u8PINx == ePIN_22 || u8PINx == ePIN_23 || u8PINx == ePIN_29 || u8PINx == ePIN_30)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> u8Port = u8PORTx;
					psButton -> u8Pin  = u8PINx;
					psButton -> u8State  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
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

/*=================================================================================================================*/

uint8_t u8fCreateButtonNonBlocking1(sButtonNonBlocking1_t *psButton, uint8_t u8PORTx,uint8_t u8PINx)
{
	uint8_t u8Result = eFALSE;
	
	if( eREADY_PIT == u8fInit_PIT(LDVAL_1S, eCHANNEL_1_PIT, &svsPITx) )
	{
			
		switch(u8PORTx){
			case ePORTA:
				if(u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_4 || u8PINx == ePIN_5 || u8PINx == ePIN_12 || u8PINx == ePIN_13)
				{
					psButton -> u8ID     = INITIAL_ID + u8CounterID;
					psButton -> u8Port   = u8PORTx;
					psButton -> u8Pin    = u8PINx;
					psButton -> u8State  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
						
				}else u8Result = eFALSE;
				break;
			case ePORTB: 
				if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_8 || u8PINx == ePIN_9)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> u8Port = u8PORTx;
					psButton -> u8Pin  = u8PINx;
					psButton -> u8State  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;
				break;
			case ePORTC: 
				if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 
				|| u8PINx == ePIN_6 || u8PINx == ePIN_7 || u8PINx == ePIN_8 || u8PINx == ePIN_9 || u8PINx == ePIN_10 || u8PINx == ePIN_11 
				|| u8PINx == ePIN_12 || u8PINx == ePIN_13 || u8PINx == ePIN_16 || ePIN_17)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> u8Port = u8PORTx;
					psButton -> u8Pin  = u8PINx;
					psButton -> u8State  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;  
				break;
			case ePORTD: 
				if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 
				|| u8PINx == ePIN_6 || u8PINx == ePIN_7)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> u8Port = u8PORTx;
					psButton -> u8Pin  = u8PINx;
					psButton -> u8State  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
					{
						u8Result = eTRUE;
					}else u8Result = eFALSE;
				}else u8Result = eFALSE;
				break;
			case ePORTE: 
				if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 
				|| u8PINx == ePIN_20 || u8PINx == ePIN_21 || u8PINx == ePIN_22 || u8PINx == ePIN_23 || u8PINx == ePIN_29 || u8PINx == ePIN_30)
				{
					psButton -> u8ID   = INITIAL_ID + u8CounterID;
					psButton -> u8Port = u8PORTx;
					psButton -> u8Pin  = u8PINx;
					psButton -> u8State  = eSTATE_READ_1;
					if(eTRUE == u8fInit_GPIO(psButton -> u8Port, psButton -> u8Pin, eIN))
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

/*=================================================================================================================*/
