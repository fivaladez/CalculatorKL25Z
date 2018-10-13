/*
 * ADC_driver.c
 *
 *  Created on: Oct 11, 2018
 *      Author: ivan_
 */

#include "ADC_driver.h"

eStatus_ADC_t efInit_ADC(ePORTx_ADC_t ePORTx, ePINx_ADC_t ePINx){
	
	switch(ePORTx)
	{
	case ePORTB_ADC:
		if( ePINx == ePIN_0_ADC  || ePINx == ePIN_1_ADC || ePINx == ePIN_2_ADC || ePINx == ePIN_3_ADC )
		{
			
		}
		else
		{
			
		}
		break;
	case ePORTC_ADC:
		if( ePINx == ePIN_0_ADC  || ePINx == ePIN_1_ADC || ePINx == ePIN_2_ADC )
		{
					
		}
		else
		{
				
		}
		break;
	case ePORTD_ADC:
		if( ePINx == ePIN_5_ADC  || ePINx == ePIN_6_ADC )
		{
					
		}
		else
		{
					
		}
		break;
	case ePORTE_ADC:
		if( ePINx == ePIN_20_ADC  || ePINx == ePIN_21_ADC || ePINx == ePIN_22_ADC || ePINx == ePIN_23_ADC )
		{
					
		}
		else
		{
					
		}
		break;
	default:
		break;
	}
	/*Activate clock for PortE*/
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
	/*Activate clock for ADC0*/
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	/*Select mode zero in port E to use it as ADC -  ADC0_DP0/ADC0_SE0 */
	PORTE_PCR20 = PORT_PCR_MUX(0);
	/*NOTE: You MUST assign the mask to be completely sure which bits you are changing*/
	
	ADC0_SC1A = 0x00;
	ADC0_SC1A |= ADC_SC1_ADCH(0); 
	ADC0_SC1A &= ADC_SC1_ADCH(0);
	ADC0_CFG1 = 0x00;
	ADC0_CFG2 = 0x00;
	ADC0_SC2 = 0x00;
	ADC0_SC3 = 0x87;
	
}
eStatus_ADC_t efRead_ADC(void){
	//uint8_t u8ADC_val = 0;
	//uint8_t u8Result = 0;
	if(ADC0_SC1A & ADC_SC1_COCO_MASK){
				
		//u8ADC_val = ADC0_RA;	
		ADC0_SC1A |= 0x00;/*Conversion initiated when write in it*/
		
	}else{}
}
