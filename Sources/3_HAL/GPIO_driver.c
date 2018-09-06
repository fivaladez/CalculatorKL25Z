/*
 * GPIO_driver.c
 *
 *  Created on: Sep 4, 2018
 *      Author: ivan_
 */

#include "derivative.h"
#include "GPIO_driver.h"

/*RED LED -> PTB 18, GREEN LED -> PTB 19, BLUE LED -> PTD 1*/

void vfSetPort_GPIO(uint8_t u8PORTx,uint8_t u8PINx) /*Write a 1*/
{
	switch(u8PORTx){
		case ePORTA: GPIOA_PDOR |= (1<<u8PINx);
			break;
		case ePORTB: GPIOB_PDOR |= (1<<u8PINx);
			break;
		case ePORTC: GPIOC_PDOR |= (1<<u8PINx);   
			break;
		case ePORTD: GPIOD_PDOR |= (1<<u8PINx);
			break;
		case ePORTE: GPIOE_PDOR |= (1<<u8PINx);
			break;
		default: 
			break;
	}//End switch
}
void vfClearPort_GPIO(uint8_t u8PORTx,uint8_t u8PINx)/*Write a 0*/
{
	switch(u8PORTx){
		case ePORTA: GPIOA_PDOR &= ~(1<<u8PINx);
			break;
		case ePORTB: GPIOB_PDOR &= ~(1<<u8PINx);
				break;
		case ePORTC: GPIOC_PDOR &= ~(1<<u8PINx);   
			break;
		case ePORTD: GPIOD_PDOR &= ~(1<<u8PINx);
			break;
		case ePORTE: GPIOE_PDOR &= ~(1<<u8PINx);
			break;
		default: 
			break;
	}//End switch
}

void vfTogglePort_GPIO(uint8_t u8PORTx,uint8_t u8PINx)
{
	switch(u8PORTx){
		case ePORTA: GPIOA_PDOR ^= (1<<u8PINx);
			break;
		case ePORTB: GPIOB_PDOR ^= (1<<u8PINx);
			break;
		case ePORTC: GPIOC_PDOR ^= (1<<u8PINx);   
			break;
		case ePORTD: GPIOD_PDOR ^= (1<<u8PINx);
			break;
		case ePORTE: GPIOE_PDOR ^= (1<<u8PINx);
			break;
		default: 
			break;
	}//End switch
}

uint8_t u8fReadPort_GPIO(uint8_t u8PORTx,uint8_t u8PINx)
{
	uint8_t u8logicValue = eFALSE;
	
	switch(u8PORTx){
		case ePORTA: u8logicValue = ((GPIOA_PDIR &= (1 << u8PINx)) >> u8PINx);//Possible results: 1 or 0
			break;
		case ePORTB: u8logicValue = ((GPIOB_PDIR &= (1 << u8PINx)) >> u8PINx);
				break;
		case ePORTC: u8logicValue = ((GPIOC_PDIR &= (1 << u8PINx)) >> u8PINx);   
			break;
		case ePORTD: u8logicValue = ((GPIOD_PDIR &= (1 << u8PINx)) >> u8PINx);
			break;
		case ePORTE: u8logicValue = ((GPIOE_PDIR &= (1 << u8PINx)) >> u8PINx);
			break;
		default:     u8logicValue = eFALSE;
			break;
	}//End switch
	
	if(0 == u8logicValue)
	{
		u8logicValue = eFALSE;
	}else if(1 == u8logicValue)
		{
			u8logicValue = eTRUE;
		}
	
	return u8logicValue;
}

uint8_t u8fInit_GPIO(uint8_t u8PORTx,uint8_t u8PINx,uint8_t u8InOut)
{
	uint8_t u8Result;
	u8Result = eFALSE;
	
	switch(u8PORTx){
		case ePORTA:
			if(u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_4 || u8PINx == ePIN_5 || u8PINx == ePIN_12 || u8PINx == ePIN_13)
			{
				SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;				     //1° Enable clock for this port
				PORTA_PCR(u8PINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); //2° Mode 1 for working as GPIO_vfInit
				GPIOA_PDOR &= ~(1<<u8PINx);						     //3° Make sure of initial value of the pin (write a zero)
				if(eIN == u8InOut)
				{
					GPIOA_PDDR &= ~(1<<u8PINx);					     //4° Define this pin as input
					u8Result = eTRUE;
				}else if(eOUT == u8InOut)
					{
						GPIOA_PDDR |= (1<<u8PINx);					 //4° Define this pin as output
						u8Result = eTRUE;
					}else u8Result = eFALSE;													 
			}else u8Result = eFALSE;
			break;
		case ePORTB:
			if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_8 || u8PINx == ePIN_9 || u8PINx == ePIN_18 || u8PINx == ePIN_19)
			{    
				SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;				     
				PORTB_PCR(u8PINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); 
				GPIOB_PDOR &= ~(1<<u8PINx);
				if(eIN == u8InOut)
				{
					GPIOB_PDDR &= ~(1<<u8PINx);
					u8Result = eTRUE;
				}else if(eOUT == u8InOut)
					{
						GPIOB_PDDR |= (1<<u8PINx);
						u8Result = eTRUE;
					}else u8Result = eFALSE;
			}else u8Result = eFALSE;
			break;
		case ePORTC:
			if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 || u8PINx == ePIN_6 || u8PINx == ePIN_7 
			|| u8PINx == ePIN_8 || u8PINx == ePIN_9 || u8PINx == ePIN_10 || u8PINx == ePIN_11 || u8PINx == ePIN_12 || u8PINx == ePIN_13 || u8PINx == ePIN_16 || u8PINx == ePIN_17)
			{    
				SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;				     
				PORTC_PCR(u8PINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); 
				GPIOC_PDOR &= ~(1<<u8PINx);	
				if(eIN == u8InOut)
				{
					GPIOC_PDDR &= ~(1<<u8PINx);	
					u8Result = eTRUE;
				}else if(eOUT == u8InOut)
					{
						GPIOC_PDDR |= (1<<u8PINx);
						u8Result = eTRUE;
					}else u8Result = eFALSE;
			}else u8Result = eFALSE;
			break;
		case ePORTD:
			if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 || u8PINx == ePIN_6 || u8PINx == ePIN_7)
			{    
				SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;				     
				PORTD_PCR(u8PINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); 
				GPIOD_PDOR &= ~(1<<u8PINx);	
				if(eIN == u8InOut)
				{
					GPIOD_PDDR &= ~(1<<u8PINx);
					u8Result = eTRUE;
				}else if(eOUT == u8InOut)
					{
						GPIOD_PDDR |= (1<<u8PINx);
						u8Result = eTRUE;
					}else u8Result = eFALSE;
			}else u8Result = eFALSE;
			break;
		case ePORTE:
			if(u8PINx == ePIN_0 || u8PINx == ePIN_1 || u8PINx == ePIN_2 || u8PINx == ePIN_3 || u8PINx == ePIN_4 || u8PINx == ePIN_5 || u8PINx == ePIN_20 || u8PINx == ePIN_21 
						|| u8PINx == ePIN_22 || u8PINx == ePIN_23 || u8PINx == ePIN_29 || u8PINx == ePIN_30)
			{    
				SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;				     
				PORTE_PCR(u8PINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); 
				GPIOE_PDOR &= ~(1<<u8PINx);	
				if(eIN == u8InOut)
				{
					GPIOE_PDDR &= ~(1<<u8PINx);	
					u8Result = eTRUE;
				}else if(eOUT == u8InOut)
					{
						GPIOE_PDDR |= (1<<u8PINx);
						u8Result = eTRUE;
					}else u8Result = eFALSE;
			}else u8Result = eFALSE;
			break;
		default: u8Result = eFALSE;
			break;	
		}//End switch
	
	return u8Result;
	
}//End function
