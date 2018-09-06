/*
 * Buttons_driver.c
 *
 *  Created on: Sep 4, 2018
 *      Author: ivan_
 */
#include "derivative.h"
#include "Buttons_driver.h"

#define INITIAL_ID			(0x00u)
#define LIMIT_PINx			(0x19u)


static uint8_t u8CounterID = 0;

void vfdelay_Button(uint16_t u16Time)
{
	uint32_t u32Value = 0;
	
	for(u32Value = u16Time * 10; 0 < u32Value; u32Value--)
	{
		/*Do nothing*/
	}
	
}

uint8_t u8fCreateButton(sButton_t *psButton, uint8_t u8PORTx,uint8_t u8PINx)
{
	uint8_t u8Result;
	u8Result = eFALSE;
	
	switch(u8PORTx){
		case ePORTA: if(u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_4 || u8PINx == ePIN_5 || u8PINx == ePIN_12 || u8PINx == ePIN_13)
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
		case ePORTB: if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_8 || u8PINx == ePIN_9)
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
		case ePORTC: if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 
		|| u8PINx == ePIN_6 || u8PINx == ePIN_7 || u8PINx == ePIN_8 || u8PINx == ePIN_9 || u8PINx == ePIN_10 || u8PINx == ePIN_11 || u8PINx == ePIN_12 
		|| u8PINx == ePIN_13 || u8PINx == ePIN_16 || ePIN_17)
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
		case ePORTD: if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 
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
		case ePORTE: if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 
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

uint8_t u8fReadButton(sButton_t *psButton)
{
	uint8_t u8Result = eFALSE;
	
	if(eTRUE == u8fReadPort_GPIO(psButton->u8Port,psButton->u8Pin))
	{
		vfdelay_Button(1000);
		if(eTRUE == u8fReadPort_GPIO(psButton->u8Port,psButton->u8Pin))
		{
			u8Result = eTRUE;
		}else u8Result = eFALSE;
		
	}else u8Result = eFALSE;
	
	return u8Result;
}


