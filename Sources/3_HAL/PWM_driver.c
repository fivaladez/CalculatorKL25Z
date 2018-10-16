/*
 * PWM_driver.c
 *
 *  Created on: Oct 14, 2018
 *      Author: ivan_
 */

#include "PWM_driver.h"

void vfConfigReg_TPM0_PWM( uint16_t u16 );
void vfConfigReg_TPM1_PWM( uint16_t u16 );
void vfConfigReg_TPM2_PWM( uint16_t u16 );

void vfConfigReg_TPM2_PWM( uint16_t u16Period )
{
	/*Clear counter register*/
	TPM2_CNT = 0;
	/*Set signal period at the same time*/
	TPM2_MOD = u16Period;
	
	TPM2_SC = 0x00;
	TPM2_SC &= ~TPM_SC_DMA_MASK;/* Disables DMA transfers.*/
	TPM2_SC &= ~TPM_SC_TOF_MASK;/* FLAG: LPTPM counter has not overflowed*/
	TPM2_SC &= ~TPM_SC_TOIE_MASK;/* Disable TOF interrupts.*/
	TPM2_SC &= ~TPM_SC_CPWMS_MASK;/* LPTPM counter operates in up counting mode*/
	TPM2_SC |= TPM_SC_CMOD(1);// LPTPM counter increments on every LPTPM counter clock 
	TPM2_SC |= TPM_SC_PS(3);/* for the clock mode selected Divided by 8*/
	//Duty cycle E22
	TPM2_C0V = 0x0000;
	//See page 556 for TPMx_CnSC configuration
	TPM2_C0SC = 0x28;		//0010 100
}

eStatus_PWM_t efInit_PWM(eChannel_PWM_t eChTPM,ePORTx_PWM_t ePORTx, ePINx_PWM_t ePINx,uint16_t u16Period)
{
	eStatus_PWM_t eReturn = eFALSE_PWM;
	
	switch(eChTPM)
	{
	case eTPM0:
		break;
	case eTPM1:
		break;
	case eTPM2:
		/*Activate TPM2 channel*/
		SIM_SCGC6 |= SIM_SCGC6_TPM2_MASK; 
		/*Selects the clock source for the TPM counter clock*/
		SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);
		/*MCGFLLCLK clock */
		SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK; 
		/*Clean all registers, those are not going to be used*/
		SIM_SOPT4 = 0x00000000;
		
		vfConfigReg_TPM2_PWM( u16Period );
		switch(ePORTx)
		{
		case ePORTA_PWM:
			break;
		case ePORTB_PWM:
			break;
		case ePORTE_PWM:
			if(ePINx == ePIN_22_PWM  || ePINx == ePIN_23_PWM )
			{
				SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
				/*Selected as TPM function*/
				PORTE_PCR(ePINx) = PORT_PCR_MUX(3);
				
			}else{eReturn = eFALSE_PWM;}
			break;
		default:
			break;
		}
		
		break;
	default:
		break;
	}
	
	return eReturn;
}
void vfPercentage_TPM2_PWM(uint8_t *u8pPercent)
{
	TPM2_C0V = ( (*u8pPercent)*PWM_PERIOD_CONST );
}
