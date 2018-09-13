/*
 * GPIO_driver.c
 *
 *  Created on: Sep 4, 2018
 *      Author: ivan_
 */

#include "GPIO_driver.h"

eStatus_GPIO_t efInit_GPIO  (ePORTx_GPIO_t ePORTx,ePINx_GPIO_t ePINx,eInOut_GPIO_t eInOut)
{
	eStatus_GPIO_t eResult = eFALSE;
	
	switch(ePORTx){
		case ePORTA:
			if(ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_4 || ePINx == ePIN_5 || ePINx == ePIN_12 || ePINx == ePIN_13)
			{
				SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;				     //1° Enable clock for this port
				PORTA_PCR(ePINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); //2° Mode 1 for working as GPIO_vfInit
				GPIOA_PDOR &= ~(1<<ePINx);						     //3° Make sure of initial value of the pin (write a zero)
				if(eINPUT == eInOut)
				{
					GPIOA_PDDR &= ~(1<<ePINx);					     //4° Define this pin as input
					eResult = eTRUE;
				}else if(eOUTPUT == eInOut)
					{
						GPIOA_PDDR |= (1<<ePINx);					 //4° Define this pin as output
						eResult = eTRUE;
					}else eResult = eFALSE;													 
			}else eResult = eFALSE;
			break;
		case ePORTB:
			if(ePINx == ePIN_0  || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_8 || ePINx == ePIN_9 
			|| ePINx == ePIN_18 || ePINx == ePIN_19)
			{    
				SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;				     
				PORTB_PCR(ePINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); 
				GPIOB_PDOR &= ~(1<<ePINx);
				if(eINPUT == eInOut)
				{
					GPIOB_PDDR &= ~(1<<ePINx);
					eResult = eTRUE;
				}else if(eOUTPUT == eInOut)
					{
						GPIOB_PDDR |= (1<<ePINx);
						eResult = eTRUE;
					}else eResult = eFALSE;
			}else eResult = eFALSE;
			break;
		case ePORTC:
			if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5 
			|| ePINx == ePIN_6 || ePINx == ePIN_7 || ePINx == ePIN_8 || ePINx == ePIN_9 || ePINx == ePIN_10 || ePINx == ePIN_11
			|| ePINx == ePIN_12 || ePINx == ePIN_13 || ePINx == ePIN_16 || ePINx == ePIN_17)
			{    
				SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;				     
				PORTC_PCR(ePINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); 
				GPIOC_PDOR &= ~(1<<ePINx);	
				if(eINPUT == eInOut)
				{
					GPIOC_PDDR &= ~(1<<ePINx);	
					eResult = eTRUE;
				}else if(eOUTPUT == eInOut)
					{
						GPIOC_PDDR |= (1<<ePINx);
						eResult = eTRUE;
					}else eResult = eFALSE;
			}else eResult = eFALSE;
			break;
		case ePORTD:
			if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4
			|| ePINx == ePIN_5 || ePINx == ePIN_6 || ePINx == ePIN_7 || ePINx == ePIN_13)
			{    
				SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;				     
				PORTD_PCR(ePINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); 
				GPIOD_PDOR &= ~(1<<ePINx);	
				if(eINPUT == eInOut)
				{
					GPIOD_PDDR &= ~(1<<ePINx);
					eResult = eTRUE;
				}else if(eOUTPUT == eInOut)
					{
						GPIOD_PDDR |= (1<<ePINx);
						eResult = eTRUE;
					}else eResult = eFALSE;
			}else eResult = eFALSE;
			break;
		case ePORTE:
			if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4
			|| ePINx == ePIN_5 || ePINx == ePIN_20 || ePINx == ePIN_21 || ePINx == ePIN_22 || ePINx == ePIN_23
			|| ePINx == ePIN_29 || ePINx == ePIN_30)
			{    
				SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;				     
				PORTE_PCR(ePINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); 
				GPIOE_PDOR &= ~(1<<ePINx);	
				if(eINPUT == eInOut)
				{
					GPIOE_PDDR &= ~(1<<ePINx);	
					eResult = eTRUE;
				}else if(eOUTPUT == eInOut)
					{
						GPIOE_PDDR |= (1<<ePINx);
						eResult = eTRUE;
					}else eResult = eFALSE;
			}else eResult = eFALSE;
			break;
		default: eResult = eFALSE;
			break;	
		}//End switch
	
	return eResult;
	
}//End function
void vfSetPort_GPIO   (ePORTx_GPIO_t ePORTx,ePINx_GPIO_t ePINx) /*Write a 1*/
{
	switch(ePORTx){
		case ePORTA: GPIOA_PDOR |= (1<<ePINx);
			break;
		case ePORTB: GPIOB_PDOR |= (1<<ePINx);
			break;
		case ePORTC: GPIOC_PDOR |= (1<<ePINx);   
			break;
		case ePORTD: GPIOD_PDOR |= (1<<ePINx);
			break;
		case ePORTE: GPIOE_PDOR |= (1<<ePINx);
			break;
		default: 
			break;
	}//End switch
}
void vfClearPort_GPIO (ePORTx_GPIO_t ePORTx,ePINx_GPIO_t ePINx)/*Write a 0*/
{
	switch(ePORTx){
		case ePORTA: GPIOA_PDOR &= ~(1<<ePINx);
			break;
		case ePORTB: GPIOB_PDOR &= ~(1<<ePINx);
				break;
		case ePORTC: GPIOC_PDOR &= ~(1<<ePINx);   
			break;
		case ePORTD: GPIOD_PDOR &= ~(1<<ePINx);
			break;
		case ePORTE: GPIOE_PDOR &= ~(1<<ePINx);
			break;
		default: 
			break;
	}//End switch
}
void vfTogglePort_GPIO(ePORTx_GPIO_t ePORTx,ePINx_GPIO_t ePINx)
{
	switch(ePORTx){
		case ePORTA: GPIOA_PDOR ^= (1<<ePINx);
			break;
		case ePORTB: GPIOB_PDOR ^= (1<<ePINx);
			break;
		case ePORTC: GPIOC_PDOR ^= (1<<ePINx);   
			break;
		case ePORTD: GPIOD_PDOR ^= (1<<ePINx);
			break;
		case ePORTE: GPIOE_PDOR ^= (1<<ePINx);
			break;
		default: 
			break;
	}//End switch
}
eStatus_GPIO_t efReadPort_GPIO(ePORTx_GPIO_t ePORTx,ePINx_GPIO_t ePINx)
{
	eStatus_GPIO_t eStatus = eFALSE;
	
	switch(ePORTx){
		case ePORTA: eStatus = ((GPIOA_PDIR &= (1 << ePINx)) >> ePINx);//Possible results: 1 or 0
			break;
		case ePORTB: eStatus = ((GPIOB_PDIR &= (1 << ePINx)) >> ePINx);
				break;
		case ePORTC: eStatus = ((GPIOC_PDIR &= (1 << ePINx)) >> ePINx);   
			break;
		case ePORTD: eStatus = ((GPIOD_PDIR &= (1 << ePINx)) >> ePINx);
			break;
		case ePORTE: eStatus = ((GPIOE_PDIR &= (1 << ePINx)) >> ePINx);
			break;
		default:     eStatus = eFALSE;
			break;
	}//End switch
	
	if(0 == eStatus)
	{
		eStatus = eFALSE;
	}else if(1 == eStatus)
		{
			eStatus = eTRUE;
		}
	
	return eStatus;
}
void vfPassValToPort_GPIO(ePORTx_GPIO_t ePORTx,ePINx_GPIO_t ePINx, uint8_t u8Data) 
{
	switch(ePORTx){
		case ePORTA: 
			if( 0u == u8Data )
			{
				GPIOA_PDOR &= ~(1<<ePINx);
			}else if( 1u == u8Data )
				{
					GPIOA_PDOR |= (1<<ePINx);
				}
			break;
		case ePORTB: 
			if( 0u == u8Data )
			{
				GPIOB_PDOR &= ~(1<<ePINx);
			}else if( 1u == u8Data )
				{
					GPIOB_PDOR |= (1<<ePINx);
				}
			break;
		case ePORTC: 
			if( 0u == u8Data )
			{
				GPIOC_PDOR &= ~(1<<ePINx);
			}else if( 1u == u8Data )
				{
					GPIOC_PDOR |= (1<<ePINx);
				}   
			break;
		case ePORTD: 
			if( 0u == u8Data )
			{
				GPIOD_PDOR &= ~(1<<ePINx);
			}else if( 1u == u8Data )
				{
					GPIOD_PDOR |= (1<<ePINx);
				}
			break;
		case ePORTE: 
			if( 0u == u8Data )
			{
				GPIOE_PDOR &= ~(1<<ePINx);
			}else if( 1u == u8Data )
				{
					GPIOE_PDOR |= (1<<ePINx);
				}
			break;
		default: /**/
			break;
	}//End switch
}
