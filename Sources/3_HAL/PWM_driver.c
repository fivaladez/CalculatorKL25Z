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

void vfConfigReg_TPM0_PWM( uint16_t u16Period )
{
	/*
	 * The edge-aligned mode is selected when (CPWMS = 0), and (MSnB:MSnA = 1:0).
	 * The EPWM period is determined by (MOD + 0x0001) and 
	 * the pulse width (duty cycle) is determined by CnV
	 */
	
	/*Activate TPM0 channel*/
	SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK; 
	/*Selects the clock source for the TPM counter clock*/
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);
	/*MCGFLLCLK clock */
	SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK; 
	/*Clean all registers, those are not going to be used*/
	SIM_SOPT4 = 0x00000000;
	
	/*Clear counter register*/
	TPM0_CNT = 0;
	/*Set signal period */
	TPM0_MOD = u16Period;
	/*Clean all register*/
	TPM0_SC = 0x00;
	TPM0_SC &= ~TPM_SC_DMA_MASK;  /* Disables DMA transfers.*/
	TPM0_SC &= ~TPM_SC_TOF_MASK;  /* FLAG: LPTPM counter has not overflowed*/
	TPM0_SC &= ~TPM_SC_TOIE_MASK; /* Disable TOF interrupts.*/
	TPM0_SC &= ~TPM_SC_CPWMS_MASK;/* LPTPM counter operates in up counting mode*//*Configure as PWM*/
	TPM0_SC |= TPM_SC_CMOD(1);    /* LPTPM counter increments on every LPTPM counter clock */
	TPM0_SC |= TPM_SC_PS(3);      /* For the clock mode selected Divided by 8*/
	/*Duty cycle*/
	TPM0_C0V = 0x0000;
	TPM0_C1V = 0x0000;
	TPM0_C2V = 0x0000;
	TPM0_C3V = 0x0000;
	TPM0_C4V = 0x0000;
	TPM0_C5V = 0x0000;
		
	/*See page 556 and 555 for TPMx_CnSC configuration and edge-aligned mode*/
	/*
	 * NOTE: For this register, the MCU will not change properly the values
	 * 		 using mask by mask. So, you MUST write at once in the register to
	 * 		 get a correct functionality
	 **/
	
	/*Same configuration for All TPM channels*/
	TPM0_C0SC = 0x28;/*0010 1000*/
	TPM0_C1SC = 0x28;		
	TPM0_C2SC = 0x28;		
	TPM0_C3SC = 0x28;		
	TPM0_C4SC = 0x28;		
	TPM0_C5SC = 0x28;
	
	/*The next lines will not work*/
	
	//TPM0_C0SC &= ~TPM_CnSC_CHF_MASK;  /* Channel flag*/
	//TPM0_C0SC &= ~TPM_CnSC_CHIE_MASK; /* Disable channel interrupts*/
	//TPM0_C0SC |=  TPM_CnSC_MSB_MASK;  /* Channel mode select*//*As PWM*/
	//TPM0_C0SC &= ~TPM_CnSC_MSA_MASK;  /* Channel mode select*//*As PWM*/
	//TPM0_C0SC |=  TPM_CnSC_ELSB_MASK; /* Edge or Level Select*/
	//TPM0_C0SC &= ~TPM_CnSC_ELSA_MASK; /* Edge or Level Select*/
	//TPM0_C0SC &= ~TPM_CnSC_DMA_MASK;  /* Disable DMA transfers*/
	
			
}
void vfConfigReg_TPM1_PWM( uint16_t u16Period )
{
	/*
	 * The edge-aligned mode is selected when (CPWMS = 0), and (MSnB:MSnA = 1:0).
	 * The EPWM period is determined by (MOD + 0x0001) and 
	 * the pulse width (duty cycle) is determined by CnV
	 */
	
	/*Activate TPM1 channel*/
	SIM_SCGC6 |= SIM_SCGC6_TPM1_MASK; 
	/*Selects the clock source for the TPM counter clock*/
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);
	/*MCGFLLCLK clock */
	SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK; 
	/*Clean all registers, those are not going to be used*/
	SIM_SOPT4 = 0x00000000;
	
	/*Clear counter register*/
	TPM1_CNT = 0;
	/*Set signal period */
	TPM1_MOD = u16Period;
	/*Clean all register*/
	TPM1_SC = 0x00;
	TPM1_SC &= ~TPM_SC_DMA_MASK;  /* Disables DMA transfers.*/
	TPM1_SC &= ~TPM_SC_TOF_MASK;  /* FLAG: LPTPM counter has not overflowed*/
	TPM1_SC &= ~TPM_SC_TOIE_MASK; /* Disable TOF interrupts.*/
	TPM1_SC &= ~TPM_SC_CPWMS_MASK;/* LPTPM counter operates in up counting mode*//*Configure as PWM*/
	TPM1_SC |= TPM_SC_CMOD(1);    /* LPTPM counter increments on every LPTPM counter clock */
	TPM1_SC |= TPM_SC_PS(3);      /* For the clock mode selected Divided by 8*/
	/*Duty cycle*/
	TPM1_C0V = 0x0000;
	TPM1_C1V = 0x0000;
	/*See page 556 and 555 for TPMx_CnSC configuration and edge-aligned mode*/
	/*
	 * NOTE: For this register, the MCU will not change properly the values
	 * 		 using mask by mask. So, you MUST write at once in the register to
	 * 		 get a correct functionality
	 **/
	TPM1_C0SC = 0x28;
	TPM1_C1SC = 0x28;	
	
}
void vfConfigReg_TPM2_PWM( uint16_t u16Period )
{
	/*
	 * The edge-aligned mode is selected when (CPWMS = 0), and (MSnB:MSnA = 1:0).
	 * The EPWM period is determined by (MOD + 0x0001) and 
	 * the pulse width (duty cycle) is determined by CnV
	 */
	
	/*Activate TPM2 channel*/
	SIM_SCGC6 |= SIM_SCGC6_TPM2_MASK; 
	/*Selects the clock source for the TPM counter clock*/
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);
	/*MCGFLLCLK clock */
	SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK; 
	/*Clean all registers, those are not going to be used*/
	SIM_SOPT4 = 0x00000000;
	
	/*Clear counter register*/
	TPM2_CNT = 0;
	/*Set signal period */
	TPM2_MOD = u16Period;
	/*Clean all register*/
	TPM2_SC = 0x00;
	TPM2_SC &= ~TPM_SC_DMA_MASK;  /* Disables DMA transfers.*/
	TPM2_SC &= ~TPM_SC_TOF_MASK;  /* FLAG: LPTPM counter has not overflowed*/
	TPM2_SC &= ~TPM_SC_TOIE_MASK; /* Disable TOF interrupts.*/
	TPM2_SC &= ~TPM_SC_CPWMS_MASK;/* LPTPM counter operates in up counting mode*//*Configure as PWM*/
	TPM2_SC |= TPM_SC_CMOD(1);    /* LPTPM counter increments on every LPTPM counter clock */
	TPM2_SC |= TPM_SC_PS(3);      /* For the clock mode selected Divided by 8*/
	/*Duty cycle*/
	TPM2_C0V = 0x0000;
	TPM2_C1V = 0x0000;
	/*See page 556 and 555 for TPMx_CnSC configuration and edge-aligned mode*/
	/*
	 * NOTE: For this register, the MCU will not change properly the values
	 * 		 using mask by mask. So, you MUST write at once in the register to
	 * 		 get a correct functionality
	 **/
	TPM2_C0SC = 0x28;
	TPM2_C1SC = 0x28;
}

eStatus_PWM_t efInit_PWM(sDATA_PWM_t* sDATA_PWM, ePORTx_PWM_t ePORTx, ePINx_PWM_t ePINx, uint16_t u16Period)
{
	eStatus_PWM_t eReturn = eFALSE_PWM;
	
	switch(ePORTx)
	{
	case ePORTA_PWM:
		break;
	case ePORTB_PWM:
		break;
	case ePORTE_PWM:
		if(ePINx == ePIN_20_PWM  || ePINx == ePIN_21_PWM || ePINx == ePIN_22_PWM  || ePINx == ePIN_23_PWM ||
		   ePINx == ePIN_29_PWM  || ePINx == ePIN_30_PWM || ePINx == ePIN_31_PWM )
		{
			/*Activate clock for port E*/
			SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
			/*Selected as TPM function the pin you pass as argument*/
			PORTE_PCR(ePINx) = PORT_PCR_MUX(3);
			
			sDATA_PWM -> ePort = ePORTx;
			sDATA_PWM -> ePin = ePINx;
			
			sDATA_PWM -> u16Period      = u16Period;
			sDATA_PWM -> u16PeriodConst = (u16Period/100);
			sDATA_PWM -> u8Percent      = 0;
			
			eReturn = eTRUE_PWM;
			
			if( ePINx == ePIN_20_PWM )
			{
				vfConfigReg_TPM1_PWM( u16Period );
				sDATA_PWM -> eChannel       = eCH0_PWM;
			}
			else if( ePINx == ePIN_21_PWM )
			{
				vfConfigReg_TPM1_PWM( u16Period );
				sDATA_PWM -> eChannel       = eCH1_PWM;
			}
			else if( ePINx == ePIN_22_PWM )
			{
				vfConfigReg_TPM2_PWM( u16Period );
				sDATA_PWM -> eChannel       = eCH0_PWM;
			}
			else if( ePINx == ePIN_23_PWM )
			{
				vfConfigReg_TPM2_PWM( u16Period );
				sDATA_PWM -> eChannel       = eCH1_PWM;
			}
			else if( ePINx == ePIN_29_PWM )
			{
				vfConfigReg_TPM0_PWM( u16Period );
				sDATA_PWM -> eChannel       = eCH2_PWM;
			}
			else if( ePINx == ePIN_30_PWM )
			{
				vfConfigReg_TPM0_PWM( u16Period );
				sDATA_PWM -> eChannel       = eCH3_PWM;
			}
			else if( ePINx == ePIN_31_PWM )
			{
				vfConfigReg_TPM0_PWM( u16Period );
				sDATA_PWM -> eChannel       = eCH4_PWM;
			}
			else/*In case of any error*/
			{
				eReturn = eFALSE_PWM;
			}
			
		}else
		{
			eReturn = eFALSE_PWM;
		}
		break;
	default: eReturn = eFALSE_PWM;
		break;
	}
		
		
	
	return eReturn;
}

void vfPercentage_PWM(sDATA_PWM_t* sDATA_PWM, uint8_t u8pPercent)
{
	if(100 >= u8pPercent && 0 <= u8pPercent)
	{
		sDATA_PWM -> u8Percent = u8pPercent;
		
		switch( sDATA_PWM->ePort )
		{
		case ePORTA_PWM:
			break;
		case ePORTB_PWM:
			break;
		case ePORTC_PWM:
			break;
		case ePORTD_PWM:
			break;
		case ePORTE_PWM:
			if( (sDATA_PWM->ePin) == ePIN_20_PWM )
			{
				TPM1_C0V = ( 10 + ( (sDATA_PWM->u8Percent) * (sDATA_PWM->u16PeriodConst) ) );
			}
			else if( (sDATA_PWM->ePin) == ePIN_21_PWM )
			{
				TPM1_C1V = ( 10 + ( (sDATA_PWM->u8Percent) * (sDATA_PWM->u16PeriodConst) ) );
			}
			else if( (sDATA_PWM->ePin) == ePIN_22_PWM )
			{
				/*Plus 10 to achieve a 100% of duty cycle*/
				TPM2_C0V = ( 10 + ( (sDATA_PWM->u8Percent) * (sDATA_PWM->u16PeriodConst) ) );
			}
			else if( (sDATA_PWM->ePin) == ePIN_23_PWM )
			{
				TPM2_C1V = ( 10 + ( (sDATA_PWM->u8Percent) * (sDATA_PWM->u16PeriodConst) ) );
			}
			else if( (sDATA_PWM->ePin) == ePIN_29_PWM )
			{
				TPM0_C2V = ( 10 + ( (sDATA_PWM->u8Percent) * (sDATA_PWM->u16PeriodConst) ) );
			}
			else if( (sDATA_PWM->ePin) == ePIN_30_PWM )
			{
				TPM0_C3V = ( 10 + ( (sDATA_PWM->u8Percent) * (sDATA_PWM->u16PeriodConst) ) );
			}
			else if( (sDATA_PWM->ePin) == ePIN_31_PWM )
			{
				TPM0_C4V = ( 10 + ( (sDATA_PWM->u8Percent) * (sDATA_PWM->u16PeriodConst) ) );
			}
			else
			{
				TPM0_C0V = 0; TPM0_C1V = 0;
				TPM0_C2V = 0; TPM0_C3V = 0;
				TPM0_C4V = 0; TPM0_C5V = 0;

				TPM1_C0V = 0; TPM1_C1V = 0;
				
				TPM2_C0V = 0; TPM2_C1V = 0;
			}
			break;
		default:
			/*Clean registers of Duty Cycle*/
			TPM0_C0V = 0;
			TPM0_C1V = 0;
			TPM1_C0V = 0;
			TPM1_C1V = 0;
			TPM2_C0V = 0;
			TPM2_C1V = 0;
			break;
		}//End switch
		
	}//End if
	
}
