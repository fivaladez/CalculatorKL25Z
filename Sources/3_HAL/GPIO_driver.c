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
		case ePORTA_GPIO: GPIOA_PDOR |= (1<<u8PINx);
			break;
		case ePORTB_GPIO: GPIOB_PDOR |= (1<<u8PINx);
			break;
		case ePORTC_GPIO: GPIOC_PDOR |= (1<<u8PINx);   
			break;
		case ePORTD_GPIO: GPIOD_PDOR |= (1<<u8PINx);
			break;
		case ePORTE_GPIO: GPIOE_PDOR |= (1<<u8PINx);
			break;
		default: 
			break;
	}//End switch
}
void vfClearPort_GPIO(uint8_t u8PORTx,uint8_t u8PINx)/*Write a 0*/
{
	switch(u8PORTx){
		case ePORTA_GPIO: GPIOA_PDOR &= ~(1<<u8PINx);
			break;
		case ePORTB_GPIO: GPIOB_PDOR &= ~(1<<u8PINx);
				break;
		case ePORTC_GPIO: GPIOC_PDOR &= ~(1<<u8PINx);   
			break;
		case ePORTD_GPIO: GPIOD_PDOR &= ~(1<<u8PINx);
			break;
		case ePORTE_GPIO: GPIOE_PDOR &= ~(1<<u8PINx);
			break;
		default: 
			break;
	}//End switch
}

void vfTogglePort_GPIO(uint8_t u8PORTx,uint8_t u8PINx)
{
	switch(u8PORTx){
		case ePORTA_GPIO: GPIOA_PDOR ^= (1<<u8PINx);
			break;
		case ePORTB_GPIO: GPIOB_PDOR ^= (1<<u8PINx);
			break;
		case ePORTC_GPIO: GPIOC_PDOR ^= (1<<u8PINx);   
			break;
		case ePORTD_GPIO: GPIOD_PDOR ^= (1<<u8PINx);
			break;
		case ePORTE_GPIO: GPIOE_PDOR ^= (1<<u8PINx);
			break;
		default: 
			break;
	}//End switch
}

uint8_t u8fReadPort_GPIO(uint8_t u8PORTx,uint8_t u8PINx)
{
	uint8_t u8logicValue = eFALSE_GPIO;
	
	switch(u8PORTx){
		case ePORTA_GPIO: u8logicValue = ((GPIOA_PDIR &= (1 << u8PINx)) >> u8PINx);//Possible results: 1 or 0
			break;
		case ePORTB_GPIO: u8logicValue = ((GPIOB_PDIR &= (1 << u8PINx)) >> u8PINx);
				break;
		case ePORTC_GPIO: u8logicValue = ((GPIOC_PDIR &= (1 << u8PINx)) >> u8PINx);   
			break;
		case ePORTD_GPIO: u8logicValue = ((GPIOD_PDIR &= (1 << u8PINx)) >> u8PINx);
			break;
		case ePORTE_GPIO: u8logicValue = ((GPIOE_PDIR &= (1 << u8PINx)) >> u8PINx);
			break;
		default:     u8logicValue = eFALSE_GPIO;
			break;
	}//End switch
	
	if(0 == u8logicValue)
	{
		u8logicValue = eFALSE_GPIO;
	}else if(1 == u8logicValue)
		{
			u8logicValue = eTRUE_GPIO;
		}
	
	return u8logicValue;
}

uint8_t u8fInit_GPIO(uint8_t u8PORTx,uint8_t u8PINx,uint8_t u8InOut)
{
	uint8_t u8Result;
	u8Result = eFALSE_GPIO;
	
	switch(u8PORTx){
		case ePORTA_GPIO:
			if(u8PINx == ePIN_1_GPIO || u8PINx == ePIN_2_GPIO || u8PINx == ePIN_4_GPIO || u8PINx == ePIN_5_GPIO || u8PINx == ePIN_12_GPIO || u8PINx == ePIN_13_GPIO)
			{
				SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;				     //1° Enable clock for this port
				PORTA_PCR(u8PINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); //2° Mode 1 for working as GPIO_vfInit
				GPIOA_PDOR &= ~(1<<u8PINx);						     //3° Make sure of initial value of the pin (write a zero)
				if(eIN_GPIO == u8InOut)
				{
					GPIOA_PDDR &= ~(1<<u8PINx);					     //4° Define this pin as input
					u8Result = eTRUE_GPIO;
				}else if(eOUT_GPIO == u8InOut)
					{
						GPIOA_PDDR |= (1<<u8PINx);					 //4° Define this pin as output
						u8Result = eTRUE_GPIO;
					}else u8Result = eFALSE_GPIO;													 
			}else u8Result = eFALSE_GPIO;
			break;
		case ePORTB_GPIO:
			if(u8PINx == ePIN_0_GPIO || u8PINx == ePIN_1_GPIO || u8PINx == ePIN_2_GPIO || u8PINx == ePIN_3_GPIO || u8PINx == ePIN_8_GPIO || u8PINx == ePIN_9_GPIO 
			|| u8PINx == ePIN_18_GPIO || u8PINx == ePIN_19_GPIO)
			{    
				SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;				     
				PORTB_PCR(u8PINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); 
				GPIOB_PDOR &= ~(1<<u8PINx);
				if(eIN_GPIO == u8InOut)
				{
					GPIOB_PDDR &= ~(1<<u8PINx);
					u8Result = eTRUE_GPIO;
				}else if(eOUT_GPIO == u8InOut)
					{
						GPIOB_PDDR |= (1<<u8PINx);
						u8Result = eTRUE_GPIO;
					}else u8Result = eFALSE_GPIO;
			}else u8Result = eFALSE_GPIO;
			break;
		case ePORTC_GPIO:
			if(u8PINx == ePIN_0_GPIO || u8PINx == ePIN_1_GPIO || u8PINx == ePIN_2_GPIO || u8PINx == ePIN_3_GPIO || u8PINx == ePIN_4_GPIO || u8PINx == ePIN_5_GPIO 
			|| u8PINx == ePIN_6_GPIO || u8PINx == ePIN_7_GPIO || u8PINx == ePIN_8_GPIO || u8PINx == ePIN_9_GPIO || u8PINx == ePIN_10_GPIO || u8PINx == ePIN_11_GPIO
			|| u8PINx == ePIN_12_GPIO || u8PINx == ePIN_13_GPIO || u8PINx == ePIN_16_GPIO || u8PINx == ePIN_17_GPIO)
			{    
				SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;				     
				PORTC_PCR(u8PINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); 
				GPIOC_PDOR &= ~(1<<u8PINx);	
				if(eIN_GPIO == u8InOut)
				{
					GPIOC_PDDR &= ~(1<<u8PINx);	
					u8Result = eTRUE_GPIO;
				}else if(eOUT_GPIO == u8InOut)
					{
						GPIOC_PDDR |= (1<<u8PINx);
						u8Result = eTRUE_GPIO;
					}else u8Result = eFALSE_GPIO;
			}else u8Result = eFALSE_GPIO;
			break;
		case ePORTD_GPIO:
			if(u8PINx == ePIN_0_GPIO || u8PINx == ePIN_1_GPIO || u8PINx == ePIN_2_GPIO || u8PINx == ePIN_3_GPIO || u8PINx == ePIN_4_GPIO
			|| u8PINx == ePIN_5_GPIO || u8PINx == ePIN_6_GPIO || u8PINx == ePIN_7_GPIO)
			{    
				SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;				     
				PORTD_PCR(u8PINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); 
				GPIOD_PDOR &= ~(1<<u8PINx);	
				if(eIN_GPIO == u8InOut)
				{
					GPIOD_PDDR &= ~(1<<u8PINx);
					u8Result = eTRUE_GPIO;
				}else if(eOUT_GPIO == u8InOut)
					{
						GPIOD_PDDR |= (1<<u8PINx);
						u8Result = eTRUE_GPIO;
					}else u8Result = eFALSE_GPIO;
			}else u8Result = eFALSE_GPIO;
			break;
		case ePORTE_GPIO:
			if(u8PINx == ePIN_0_GPIO || u8PINx == ePIN_1_GPIO || u8PINx == ePIN_2_GPIO || u8PINx == ePIN_3_GPIO || u8PINx == ePIN_4_GPIO
			|| u8PINx == ePIN_5_GPIO || u8PINx == ePIN_20_GPIO || u8PINx == ePIN_21_GPIO || u8PINx == ePIN_22_GPIO || u8PINx == ePIN_23_GPIO
			|| u8PINx == ePIN_29_GPIO || u8PINx == ePIN_30_GPIO)
			{    
				SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;				     
				PORTE_PCR(u8PINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO); 
				GPIOE_PDOR &= ~(1<<u8PINx);	
				if(eIN_GPIO == u8InOut)
				{
					GPIOE_PDDR &= ~(1<<u8PINx);	
					u8Result = eTRUE_GPIO;
				}else if(eOUT_GPIO == u8InOut)
					{
						GPIOE_PDDR |= (1<<u8PINx);
						u8Result = eTRUE_GPIO;
					}else u8Result = eFALSE_GPIO;
			}else u8Result = eFALSE_GPIO;
			break;
		default: u8Result = eFALSE_GPIO;
			break;	
		}//End switch
	
	return u8Result;
	
}//End function
