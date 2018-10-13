/*
 * ADC_driver.h
 *
 *  Created on: Oct 11, 2018
 *      Author: ivan_
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "derivative.h"

/*This Driver ONLY works for single ended ADC channel*/
typedef enum
{
	ePORTB_ADC,
	ePORTC_ADC,
	ePORTD_ADC,
	ePORTE_ADC

}ePORTx_ADC_t;
typedef enum
{
	ePIN_0_ADC,  ePIN_1_ADC,  ePIN_2_ADC,
	ePIN_3_ADC,  ePIN_5_ADC,  ePIN_6_ADC,
	ePIN_20_ADC, ePIN_21_ADC, ePIN_22_ADC,
	ePIN_23_ADC

}ePINx_ADC_t;
typedef enum
{
	eFALSE_ADC,
	eTRUE_ADC

}eStatus_ADC_t;

/*
 *  //Activate clock for PortE
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
	//Activate clock for ADC0
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	//Select mode zero in port E to use it as ADC -  ADC0_DP0/ADC0_SE0
	PORTE_PCR20 = PORT_PCR_MUX(0);
	//NOTE: You MUST assign the mask to be completely sure which bits you are changing
	
	//Clean the entire register
	ADC0_SC1A = 0x00;
	ADC0_SC1A &= ~ADC_SC1_AIEN_MASK;//Interrupt disable with zero
	ADC0_SC1A &= ~ADC_SC1_DIFF_MASK;//Differential mode disable with zero
	//All DADPx inputs may be used as single-ended inputs if SC1n[DIFF] is low
	ADC0_SC1A |= ADC_SC1_ADCH(0);//Channel select and start conversion		Writes ones 
	ADC0_SC1A &= ADC_SC1_ADCH(0);//											Writes zeros
	
	ADC0_CFG1 = 0x00;
	ADC0_CFG1 &= ~ADC_CFG1_ADLPC_MASK;//Normal power consume
	ADC0_CFG1 &= ~ADC_CFG1_ADIV_MASK;//The divide ratio is 1 and the clock rate is input clock
	ADC0_CFG1 &= ~ADC_CFG1_ADLSMP_MASK;//Short sample time
	ADC0_CFG1 &= ~ADC_CFG1_MODE_MASK;// It is single-ended 8-bit conversion
	ADC0_CFG1 &= ~ADC_CFG1_ADICLK_MASK;//Select the bus clock
	
	ADC0_CFG2 = 0x00;
	ADC0_CFG2 &= ~ADC_CFG2_MUXSEL_MASK;//ADxxa channels are selected
	ADC0_CFG2 &= ~ADC_CFG2_ADACKEN_MASK;//Asynchronous clock output disable
	ADC0_CFG2 &= ~ADC_CFG2_ADHSC_MASK;// Normal conversion sequence selected
	ADC0_CFG2 &= ~ADC_CFG2_ADLSTS_MASK;//Default longest sample time
	
	ADC0_SC2 = 0x00;
	ADC0_SC2 &= ~ADC_SC2_ADTRG_MASK;// Software trigger selected
	//Software trigger: When software trigger is selected, a conversion is initiated following a write to SC1A.
	ADC0_SC2 &= ~ADC_SC2_ACFE_MASK;//Compare function disabled
	ADC0_SC2 &= ~ADC_SC2_ACFGT_MASK;//Configures less than threshold
	ADC0_SC2 &= ~ADC_SC2_ACREN_MASK;//Range function disabled
	ADC0_SC2 &= ~ADC_SC2_DMAEN_MASK;// DMA is disabled
	ADC0_SC2 &= ~ADC_SC2_REFSEL_MASK;// Default voltage reference pin pair
	
	ADC0_SC3 = 0x00;
	//ADC0_SC3 = 0x87;
	ADC0_SC3 |= ADC_SC3_CAL_MASK;//Begins the calibration sequence when set
	//(ADC0_SC3 & ADC_SC3_CALF_MASK) READ flag of CALF to know state of ADC calibration
	ADC0_SC3 &= ~ADC_SC3_ADCO_MASK;// One conversion or one set of conversions 
	ADC0_SC3 |= ADC_SC3_AVGE_MASK;//Hardware average function enabled
	ADC0_SC3 |= ADC_SC3_AVGS_MASK;//32 samples averaged
 * 
 * */

#endif /* ADC_DRIVER_H_ */
