/*
 * ADC_driver.c
 *
 *  Created on: Oct 11, 2018
 *      Author: ivan_
 */

#include "ADC_driver.h"

void vfConfigReg_ADC(void);

eStatus_ADC_t vfReadPinsPortB_ADC(ePINx_ADC_t ePINx, sDATA_ADC_t** spDataADC);
eStatus_ADC_t vfReadPinsPortC_ADC(ePINx_ADC_t ePINx, sDATA_ADC_t** spDataADC);
eStatus_ADC_t vfReadPinsPortD_ADC(ePINx_ADC_t ePINx, sDATA_ADC_t** spDataADC);
eStatus_ADC_t vfReadPinsPortE_ADC(ePINx_ADC_t ePINx, sDATA_ADC_t** spDataADC);

void vfConvert_ADC(sDATA_ADC_t** spDataADC);

eStatus_ADC_t vfReadPinsPortB_ADC(ePINx_ADC_t ePINx, sDATA_ADC_t** spDataADC)
{
	eStatus_ADC_t eReturn = eFALSE_ADC;
		
	switch(ePINx)
	{
	case ePIN_0_ADC:
		//Activate clock for PortE
		SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
		//Select mode zero in port B to use it as ADC -  ADC0_SE8/TSI0_CH0 
		PORTB_PCR0 = PORT_PCR_MUX(0);
		//NOTE: You MUST assign the mask to assure you write a 0
		/*Configure Registers from ADC*/
		vfConfigReg_ADC();
		/*Assign channel of ADC*/
		ADC0_SC1A |= ADC_SC1_ADCH(8);
		/*Assign values to ADC struct*/
		(*spDataADC) -> ePortADC = ePORTB_ADC;
		(*spDataADC) -> ePinADC  = ePIN_0_ADC;
			
		eReturn = eTRUE_ADC;
		break;
	case ePIN_1_ADC:
		SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
		//Select mode zero in port B to use it as ADC -    ADC0_SE9/TSI0_CH6 
		PORTB_PCR1 = PORT_PCR_MUX(0);
			
		vfConfigReg_ADC();
			
		ADC0_SC1A |= ADC_SC1_ADCH(9);
		
		(*spDataADC) -> ePortADC = ePORTB_ADC;
		(*spDataADC) -> ePinADC  = ePIN_1_ADC;
			
		eReturn = eTRUE_ADC;
		break;
	case ePIN_2_ADC:
		
		SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
		//Select mode zero in port B to use it as ADC -    ADC0_SE12/TSI0_CH7  
		PORTB_PCR2 = PORT_PCR_MUX(0);
		
		vfConfigReg_ADC();
			
		ADC0_SC1A |= ADC_SC1_ADCH(12);
			
		(*spDataADC) -> ePortADC = ePORTB_ADC;
		(*spDataADC) -> ePinADC  = ePIN_2_ADC;
			
		eReturn = eTRUE_ADC;
		break;
	case ePIN_3_ADC:
			
		SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
		//Select mode zero in port B to use it as ADC -   ADC0_SE13/TSI0_CH8 
		PORTB_PCR3 = PORT_PCR_MUX(0);
		
		vfConfigReg_ADC();
			
		ADC0_SC1A |= ADC_SC1_ADCH(13);
		
		(*spDataADC) -> ePortADC = ePORTB_ADC;
		(*spDataADC) -> ePinADC  = ePIN_3_ADC;
			
		eReturn = eTRUE_ADC;
		break;
	default: eReturn = eFALSE_ADC;
		break;
	}
		
	return eReturn;
}
eStatus_ADC_t vfReadPinsPortC_ADC(ePINx_ADC_t ePINx, sDATA_ADC_t** spDataADC)
{
	eStatus_ADC_t eReturn = eFALSE_ADC;
		
	switch(ePINx)
	{
	case ePIN_0_ADC:
		//Activate clock for PortE
		SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
		//Select mode zero in port C to use it as ADC -   ADC0_SE14/TSI0_CH13 
		PORTC_PCR0 = PORT_PCR_MUX(0);
		//NOTE: You MUST assign the mask to assure you write a 0
		/*Configure Registers from ADC*/
		vfConfigReg_ADC();
		/*Assign channel of ADC*/
		ADC0_SC1A |= ADC_SC1_ADCH(14);
		/*Assign values to ADC struct*/
		(*spDataADC) -> ePortADC = ePORTC_ADC;
		(*spDataADC) -> ePinADC  = ePIN_0_ADC;
			
		eReturn = eTRUE_ADC;
		break;
	case ePIN_1_ADC:
		SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
		//Select mode zero in port E to use it as ADC -   ADC0_SE15/TSI0_CH14 
		PORTC_PCR1 = PORT_PCR_MUX(0);
			
		vfConfigReg_ADC();
			
		ADC0_SC1A |= ADC_SC1_ADCH(15);
		
		(*spDataADC) -> ePortADC = ePORTC_ADC;
		(*spDataADC) -> ePinADC  = ePIN_1_ADC;
			
		eReturn = eTRUE_ADC;
		break;
	case ePIN_2_ADC:
		
		SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
		//Select mode zero in port E to use it as ADC -    ADC0_SE11/TSI0_CH15  
		PORTC_PCR2 = PORT_PCR_MUX(0);
		
		vfConfigReg_ADC();
			
		ADC0_SC1A |= ADC_SC1_ADCH(11);
			
		(*spDataADC) -> ePortADC = ePORTC_ADC;
		(*spDataADC) -> ePinADC  = ePIN_2_ADC;
			
		eReturn = eTRUE_ADC;
		break;
		
	default: eReturn = eFALSE_ADC;
		break;
	}
		
	return eReturn;
}

eStatus_ADC_t vfReadPinsPortE_ADC(ePINx_ADC_t ePINx, sDATA_ADC_t** spDataADC)
{
	eStatus_ADC_t eReturn = eFALSE_ADC;
		
	switch(ePINx)
	{
	case ePIN_20_ADC:
		//Activate clock for PortE
		SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
		//Select mode zero in port E to use it as ADC -  ADC0_DP0/ADC0_SE0
		PORTE_PCR20 = PORT_PCR_MUX(0);
		//NOTE: You MUST assign the mask to assure you write a 0
		/*Configure Registers from ADC*/
		vfConfigReg_ADC();
		/*Assign channel of ADC*/
		ADC0_SC1A |= ADC_SC1_ADCH(0);
		/*Assign values to ADC struct*/
		(*spDataADC) -> ePortADC = ePORTE_ADC;
		(*spDataADC) -> ePinADC  = ePIN_20_ADC;
			
		eReturn = eTRUE_ADC;
		break;
	case ePIN_21_ADC:
		SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
		//Select mode zero in port E to use it as ADC -   ADC0_DM0/ADC0_SE4a
		PORTE_PCR21 = PORT_PCR_MUX(0);
			
		vfConfigReg_ADC();
			
		ADC0_SC1A |= ADC_SC1_ADCH(4);
		
		(*spDataADC) -> ePortADC = ePORTE_ADC;
		(*spDataADC) -> ePinADC  = ePIN_21_ADC;
			
		eReturn = eTRUE_ADC;
		break;
	case ePIN_22_ADC:
		
		SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
		//Select mode zero in port E to use it as ADC -   ADC0_DP3/ADC0_SE3 
		PORTE_PCR22 = PORT_PCR_MUX(0);
		
		vfConfigReg_ADC();
			
		ADC0_SC1A |= ADC_SC1_ADCH(3);
			
		(*spDataADC) -> ePortADC = ePORTE_ADC;
		(*spDataADC) -> ePinADC  = ePIN_22_ADC;
			
		eReturn = eTRUE_ADC;
		break;
	case ePIN_23_ADC:
			
		SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
		//Select mode zero in port E to use it as ADC -   ADC0_DM3/ADC0_SE7a 
		PORTE_PCR23 = PORT_PCR_MUX(0);
		
		vfConfigReg_ADC();
			
		ADC0_SC1A |= ADC_SC1_ADCH(7);
		
		(*spDataADC) -> ePortADC = ePORTE_ADC;
		(*spDataADC) -> ePinADC  = ePIN_23_ADC;
			
		eReturn = eTRUE_ADC;
		break;
	default: eReturn = eFALSE_ADC;
		break;
	}
		
	return eReturn;
}

void vfConfigReg_ADC(void)
{
	//Activate clock for ADC0
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	
	ADC0_SC1A = 0x00;
	ADC0_CFG1 = 0x00;
	ADC0_CFG2 = 0x00;
	ADC0_SC2  = 0x00;
	ADC0_SC3  = 0x87;
	
	ADC0_SC1A &= ~ADC_SC1_AIEN_MASK;//Interrupt disable with zero
	ADC0_SC1A &= ~ADC_SC1_DIFF_MASK;//Differential mode disable with zero
	//All DADPx inputs may be used as single-ended inputs if SC1n[DIFF] is low
	ADC0_SC1A |= ADC_SC1_ADCH(0);//Channel select and start conversion		Writes ones 
	ADC0_SC1A &= ADC_SC1_ADCH(0);//											Writes zeros
		
	ADC0_CFG1 &= ~ADC_CFG1_ADLPC_MASK;//Normal power consume
	ADC0_CFG1 &= ~ADC_CFG1_ADIV_MASK;//The divide ratio is 1 and the clock rate is input clock
	ADC0_CFG1 &= ~ADC_CFG1_ADLSMP_MASK;//Short sample time
	ADC0_CFG1 &= ~ADC_CFG1_MODE_MASK;// It is single-ended 8-bit conversion
	ADC0_CFG1 &= ~ADC_CFG1_ADICLK_MASK;//Select the bus clock

#if ADC_CHANNEL == a
	ADC0_CFG2 &= ~ADC_CFG2_MUXSEL_MASK;//ADxxa channels are selected
#elif ADC_CHANNEL == b
	ADC0_CFG2 |= ADC_CFG2_MUXSEL_MASK;//ADxxb channels are selected
#endif
	ADC0_CFG2 &= ~ADC_CFG2_ADACKEN_MASK;//Asynchronous clock output disable
	ADC0_CFG2 &= ~ADC_CFG2_ADHSC_MASK;// Normal conversion sequence selected
	ADC0_CFG2 &= ~ADC_CFG2_ADLSTS_MASK;//Default longest sample time
		
	ADC0_SC2 &= ~ADC_SC2_ADTRG_MASK;// Software trigger selected
	//Software trigger: When software trigger is selected, a conversion is initiated following a write to SC1A.
	ADC0_SC2 &= ~ADC_SC2_ACFE_MASK;//Compare function disabled
	ADC0_SC2 &= ~ADC_SC2_ACFGT_MASK;//Configures less than threshold
	ADC0_SC2 &= ~ADC_SC2_ACREN_MASK;//Range function disabled
	ADC0_SC2 &= ~ADC_SC2_DMAEN_MASK;// DMA is disabled
	ADC0_SC2 &= ~ADC_SC2_REFSEL_MASK;// Default voltage reference pin pair
		
	ADC0_SC3 |= ADC_SC3_CAL_MASK;//Begins the calibration sequence when set
	//(ADC0_SC3 & ADC_SC3_CALF_MASK) READ flag of CALF to know state of ADC calibration
	ADC0_SC3 &= ~ADC_SC3_ADCO_MASK;// One conversion or one set of conversions 
	ADC0_SC3 |= ADC_SC3_AVGE_MASK;//Hardware average function enabled
	ADC0_SC3 |= ADC_SC3_AVGS_MASK;//32 samples averaged
	
}
eStatus_ADC_t efInit_ADC( ePORTx_ADC_t ePORTx, ePINx_ADC_t ePINx, sDATA_ADC_t* spDataADC){
	
	eStatus_ADC_t eReturn = eFALSE_ADC;
	
	switch( ePORTx )
	{
	case ePORTB_ADC: eReturn =  vfReadPinsPortB_ADC( ePINx, (&spDataADC) );
		break;
	case ePORTC_ADC: eReturn =  vfReadPinsPortC_ADC( ePINx, (&spDataADC) );
		break;
	case ePORTD_ADC: //eReturn =  vfReadPinsPortD_ADC( ePINx, (&spDataADC) );
		break;
	case ePORTE_ADC: eReturn =  vfReadPinsPortE_ADC( ePINx, (&spDataADC) );
		break;
	default: eReturn = eFALSE_ADC;
		break;
	}
	
	return eReturn;
}
eStatus_ADC_t efRead_ADC(sDATA_ADC_t* spDataADC){
	
	eStatus_ADC_t eReturn = eFALSE_ADC;
	
	if(ADC0_SC1A & ADC_SC1_COCO_MASK){
		
		/*Assign value read from ADC to an element of ADC struct*/
		spDataADC -> u8ValADC  = ADC0_RA;
		vfConvert_ADC( (&spDataADC) );
		/*The conversion is initiated when you write in this register*/
		ADC0_SC1A |= 0x00;
		
		eReturn = eTRUE_ADC;
		
	}else
	{
		eReturn = eFALSE_ADC;
	}
	
	return eReturn;
}

void vfConvert_ADC(sDATA_ADC_t** spDataADC)
{
	uint8_t u8Cnt = 0;
	(*spDataADC) -> u16Percent = 0;
	(*spDataADC) -> u8Hundreds = 0;
	(*spDataADC) -> u8Dozens = 0;
	(*spDataADC) -> u8Units = 0;
	
	/*Get the value of ADC in percent*/	
	(*spDataADC) -> u16Percent = ( (*spDataADC) -> u8ValADC) * 100;
	/*Divide ADC value for 255*/
	for( u8Cnt = 0; (*spDataADC) -> u16Percent >= 255 ; u8Cnt++ ){
		(*spDataADC) -> u16Percent -= 255;
	}
	/*Assign the result of division*/
	(*spDataADC) -> u16Percent = u8Cnt;/*Values from 0 to 100*/
	
	
	/*Get individual numbers for hundreds, dozens and units for LCD*/
	if( (*spDataADC) -> u16Percent >= 100 ){
		
		(*spDataADC) -> u8Hundreds = 1;
		(*spDataADC) -> u8Dozens = 0;
		(*spDataADC) -> u8Units = 0;
		
	}
	else
	{
		(*spDataADC) -> u8Hundreds = 0;
			
		(*spDataADC) -> u8Dozens = (*spDataADC) -> u16Percent;
		for( u8Cnt = 0 ; (*spDataADC) -> u8Dozens >= 10 ; u8Cnt++ ){
			(*spDataADC) -> u8Dozens -= 10;
		}
		(*spDataADC) -> u8Dozens = u8Cnt;
				
		(*spDataADC) -> u8Units = (((*spDataADC) -> u16Percent)-((*spDataADC) -> u8Hundreds*100)-((*spDataADC) -> u8Dozens*10));
	}
}
