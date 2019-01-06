/*
** Project: Calculator for KL25Z
** File   : UART_driver.c
** Author : Ivan Valadez
** Date   : 06 - January - 2019
**
** Overview: C file containing the functions for using UART pins from MCU KL25K of nxp
**
** $Log$
*/
/*---------------------------------------------------------------------------
** Includes
 */
#include "UART_driver.h"
/*---------------------------------------------------------------------------
** Defines and Macros
*/
/*---------------------------------------------------------------------------
** Typedefs
*/
/*---------------------------------------------------------------------------
** Data
*/
/*---------------------------------------------------------------------------
** Prototypes Functions
*/
void vfConvert_UART(sDATA_UART_t** spDataUART);

void vfConfigReg_UART0(void);
void vfConfigReg_UART1(void);
void vfConfigReg_UART2(void);
eStatus_UART_t vfInitPortAChannelx_UART( eCHANNELx_UART_t eChannelx , sDATA_UART_t** spDataUART );
eStatus_UART_t vfInitPortCChannelx_UART( eCHANNELx_UART_t eChannelx , sDATA_UART_t** spDataUART );
eStatus_UART_t vfInitPortDChannelx_UART( eCHANNELx_UART_t eChannelx , sDATA_UART_t** spDataUART );
eStatus_UART_t vfInitPortEChannelx_UART( eCHANNELx_UART_t eChannelx , sDATA_UART_t** spDataUART );

/*---------------------------------------------------------------------------
** Functions
*/
/*-------------------------------------------------------------------------*/

/*! \brief    efInit_UART
**
** \note	  Auto-select function of initialization for specific port and channel.
** 			  returns TRUE if the parameters are valid and the function could started correctly
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_UART_t ePORTx,
** 						 eCHANNELx_UART_t eChannelx,
** 						 sDATA_UART_t* spDataUART
**
** \return               eStatus_UART_t eReturn
** \description
*/
eStatus_UART_t efInit_UART( ePORTx_UART_t ePORTx, eCHANNELx_UART_t eChannelx, sDATA_UART_t* spDataUART)
{
	eStatus_UART_t eReturn = eFALSE_UART;
	spDataUART -> u8ValTxUART = 0;
	spDataUART -> u8ValRxUART = 0;
	spDataUART -> u8Hundreds = 0;
	spDataUART -> u8Dozens = 0;
	spDataUART -> u8Units = 0;
	spDataUART -> eChannelUART = 0;
	spDataUART -> ePortUART = 0;
	spDataUART -> ePinTxUART = 0;
	spDataUART -> ePinRxUART = 0;
	spDataUART -> eSatusUART = 0;
	
	switch( ePORTx )
	{
	case ePORTA_UART: 	spDataUART -> ePortUART = ePORTA_UART;
						eReturn = vfInitPortAChannelx_UART( eChannelx, (&spDataUART) );
		break;
	case ePORTC_UART: 	spDataUART -> ePortUART = ePORTC_UART;
						eReturn = vfInitPortCChannelx_UART( eChannelx, (&spDataUART) );
		break;
	case ePORTD_UART:   spDataUART -> ePortUART = ePORTD_UART;
						eReturn = vfInitPortDChannelx_UART( eChannelx, (&spDataUART) );
		break;
	case ePORTE_UART:   spDataUART -> ePortUART = ePORTE_UART;
						eReturn = vfInitPortEChannelx_UART( eChannelx, (&spDataUART) );
		break;
	default: eReturn = eFALSE_UART;
		break;
	}
	
	return eReturn;
}

/*! \brief    vfInitPortXChannelx_UART
**
** \note	  Initialization for specific channel.
** 			  It enables specifict registers for ports and calls functions for modify UART registers.
** 			  returns TRUE if the parameters are valid and the function could started correctly
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_UART_t ePORTx,
** 						 eCHANNELx_UART_t eChannelx,
** 						 sDATA_UART_t* spDataUART
**
** \return               eStatus_UART_t eReturn
** \description
*/
eStatus_UART_t vfInitPortAChannelx_UART( eCHANNELx_UART_t eChannelx , sDATA_UART_t** spDataUART ){
	
	eStatus_UART_t eReturn = eFALSE_UART;
		
	switch((*spDataUART) -> eChannelUART)
	{
	case eUART_0:
		/*Set clock of PORTA*/
		SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
		/*Set Mode for pins*/
		PORTA_PCR2 |= PORT_PCR_MUX(2);//Tx UART	
		PORTA_PCR1 |= PORT_PCR_MUX(2);//Rx UART
		
		(*spDataUART) -> ePinTxUART = ePIN_2_UART;
		(*spDataUART) -> ePinRxUART = ePIN_1_UART;
		(*spDataUART) -> eChannelUART = eUART_0;
		
		vfConfigReg_UART0();
		
		eReturn = eTRUE_UART;
		break;
	default: eReturn = eFALSE_UART;
		break;
	}
		
	return eReturn;
}
eStatus_UART_t vfInitPortCChannelx_UART( eCHANNELx_UART_t eChannelx , sDATA_UART_t** spDataUART ){
	
	eStatus_UART_t eReturn = eFALSE_UART;
		
	switch((*spDataUART) -> eChannelUART)
	{
	case eUART_1:
		/*Set clock of PORTE*/
		SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
		/*Set Mode for pins*/
		PORTC_PCR4 |= PORT_PCR_MUX(3);//Tx UART	
		PORTC_PCR3 |= PORT_PCR_MUX(3);//Rx UART
				
		(*spDataUART) -> ePinTxUART = ePIN_4_UART;
		(*spDataUART) -> ePinRxUART = ePIN_3_UART;
		(*spDataUART) -> eChannelUART = eUART_1;
		
		vfConfigReg_UART1();
				
		eReturn = eTRUE_UART;
		break;
	default: eReturn = eFALSE_UART;
		break;
	}
		
	return eReturn;
}
eStatus_UART_t vfInitPortDChannelx_UART( eCHANNELx_UART_t eChannelx , sDATA_UART_t** spDataUART ){
	
	eStatus_UART_t eReturn = eFALSE_UART;
		
	switch((*spDataUART) -> eChannelUART)
	{
	case eUART_0:
		/*Set clock of PORTD*/
		SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
		/*Set Mode for pins*/
		PORTD_PCR7 |= PORT_PCR_MUX(3);//Tx UART	
		PORTD_PCR6 |= PORT_PCR_MUX(3);//Rx UART
		
		(*spDataUART) -> ePinTxUART = ePIN_7_UART;
		(*spDataUART) -> ePinRxUART = ePIN_6_UART;
		(*spDataUART) -> eChannelUART = eUART_0;
		
		vfConfigReg_UART0();
		
		eReturn = eTRUE_UART;
		break;
	case eUART_2:
		/*Set clock of PORTD*/
		SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
		/*Set Mode for pins*/
		PORTD_PCR5 |= PORT_PCR_MUX(3);//Tx UART	
		PORTD_PCR4 |= PORT_PCR_MUX(3);//Rx UART
						
		(*spDataUART) -> ePinTxUART = ePIN_5_UART;
		(*spDataUART) -> ePinRxUART = ePIN_4_UART;
		(*spDataUART) -> eChannelUART = eUART_2;
						
		vfConfigReg_UART2();
						
		eReturn = eTRUE_UART;
		break;
	default: eReturn = eFALSE_UART;
		break;
	}
		
	return eReturn;
}
eStatus_UART_t vfInitPortEChannelx_UART( eCHANNELx_UART_t eChannelx , sDATA_UART_t** spDataUART ){
	
	eStatus_UART_t eReturn = eFALSE_UART;
		
	switch((*spDataUART) -> eChannelUART)
	{
	case eUART_0:
		/*Set clock of PORTE*/
		SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
		/*Set Mode for pins*/
		PORTE_PCR20 |= PORT_PCR_MUX(4);//Tx UART	
		PORTE_PCR21 |= PORT_PCR_MUX(4);//Rx UART
		
		(*spDataUART) -> ePinTxUART = ePIN_20_UART;
		(*spDataUART) -> ePinRxUART = ePIN_21_UART;
		(*spDataUART) -> eChannelUART = eUART_0;
		
		vfConfigReg_UART0();
		
		eReturn = eTRUE_UART;
		break;
	case eUART_1:
		/*Set clock of PORTE*/
		SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
		/*Set Mode for pins*/
		PORTE_PCR0 |= PORT_PCR_MUX(3);//Tx UART	
		PORTE_PCR1 |= PORT_PCR_MUX(3);//Rx UART
				
		(*spDataUART) -> ePinTxUART = ePIN_0_UART;
		(*spDataUART) -> ePinRxUART = ePIN_1_UART;
		(*spDataUART) -> eChannelUART = eUART_1;
				
		vfConfigReg_UART1();
				
		eReturn = eTRUE_UART;
		break;
	case eUART_2:
		/*Set clock of PORTE*/
		SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
		/*Set Mode for pins*/
		PORTE_PCR22 |= PORT_PCR_MUX(4);//Tx UART	
		PORTE_PCR23 |= PORT_PCR_MUX(4);//Rx UART
						
		(*spDataUART) -> ePinTxUART = ePIN_22_UART;
		(*spDataUART) -> ePinRxUART = ePIN_23_UART;
		(*spDataUART) -> eChannelUART = eUART_2;
						
		vfConfigReg_UART2();
						
		eReturn = eTRUE_UART;
		break;
	default: eReturn = eFALSE_UART;
		break;
	}
		
	return eReturn;
}

/*! \brief    vfConfigReg_UARTX
**
** \note	  Modify specific registers for the channel.
** 			  It enables specifict registers for UART registers.
** 			  
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            NA
**
** \return               NA
** \description
*/
void vfConfigReg_UART0(void){
	SIM_SCGC4 |=  SIM_SCGC4_UART0_MASK;//Set clock UART0
	SIM_SOPT2 |=  SIM_SOPT2_UART0SRC(1);//Select clock source UART0 MCGFLLCLK
	SIM_SOPT2 &=~ SIM_SOPT2_PLLFLLSEL_MASK;//Default clock MCGFLLCLK clock 
	SIM_SOPT5 |= SIM_SOPT5_UART0TXSRC(0);/* UART0 transmit data source select - 00 UART0_TX pin */
	SIM_SOPT5 &= ~SIM_SOPT5_UART0RXSRC_MASK;/*UART0 receive data source select - 0 UART0_RX pin */
	SIM_SOPT5 &= ~SIM_SOPT5_UART0ODE_MASK;/*0 Open drain is disabled on UART0 */
				
	// baud rate = baud clock / ((OSR+1) * SBR)
	// 9600 = 48 000 000 / ( (4+1)*(48000) )
	// 300  = 21 000 000 / ((9+1)*7000)
	UART0_BDH &= ~UART_BDH_LBKDIE_MASK; /*Hardware interrupts from UART _S2[LBKDIF] disabled*/
	UART0_BDH &= ~UART_BDH_RXEDGIE_MASK;/*Hardware interrupts from UART _S2[RXEDGIF] disabled*/
	UART0_BDH |=  UART_BDH_SBNS_MASK;   /*Stop Bit Number Select -> Two stop bit*/
	UART0_BDH |=  UART_BDH_SBR(SBR>>8);
	
	UART0_BDL |=  UART_BDL_SBR(SBR);
			
	UART0_C1 &= ~UART_C1_LOOPS_MASK; /* Normal operation - UART _RX and UART _TX use separate pins*/
	/*Unique register for UART0*/
	UART0_C1 &= ~UART0_C1_DOZEEN_MASK;/* UART is enabled  in Wait mode*/
	UART0_C1 &= ~UART_C1_RSRC_MASK;  /* Unusable. Must be combined with UART0_C1_LOOPS_MASK = 1*/
	UART0_C1 &= ~UART_C1_M_MASK;     /* Receiver and transmitter use 8-bit data characters*/
	UART0_C1 &= ~UART_C1_WAKE_MASK;  /* Idle-line wakeup.*/
	UART0_C1 &= ~UART_C1_ILT_MASK;   /* Idle character bit count starts after start bit. */
	UART0_C1 |=  UART_C1_PE_MASK;    /* Parity enabled*/
	UART0_C1 &= ~UART_C1_PT_MASK;	  /* Even parity*/
	
	UART0_C2 &= ~UART_C2_TIE_MASK; /* Hardware interrupts from TDRE disabled*/
	UART0_C2 &= ~UART_C2_TCIE_MASK;/* Hardware interrupts from TC disabled; */
	UART0_C2 &= ~UART_C2_RIE_MASK; /* Hardware interrupts from RDRF disabled*/
	UART0_C2 &= ~UART_C2_ILIE_MASK;/* Hardware interrupts from IDLE disabled*/
	UART0_C2 &= ~UART_C2_TE_MASK;  /* Transmitter disabled. */
	UART0_C2 &= ~UART_C2_RE_MASK;  /* Receiver disabled*/
	UART0_C2 &= ~UART_C2_RWU_MASK; /* Normal UART receiver operation*/
	UART0_C2 &= ~UART_C2_SBK_MASK; /* Normal transmitter operation*/
	
	/*Flags p729*/
	UART0_S1 &= ~UART_S1_TDRE_MASK;/* Transmit Data Register Empty Flag*/
	UART0_S1 &= ~UART_S1_TC_MASK;  /*Transmission complete flag*/
	UART0_D = 0x00;/*To clean TDRE and TC flags*/
	UART0_S1 &= ~UART_S1_RDRF_MASK;/*Receive Data Register Full Flag*/
	if(UART0_D){/*To clean RDRF flag*/}
	/*Clean flags*/
	UART0_S1 |=  UART_S1_IDLE_MASK;/*Idle Line Flag*/
	UART0_S1 |=  UART_S1_OR_MASK;/*Receiver Overrun Flag*/
	UART0_S1 |=  UART_S1_NF_MASK;/*Noise flag*/
	UART0_S1 |=  UART_S1_FE_MASK;/*Framing Error Flag*/
	UART0_S1 |=  UART_S1_PF_MASK;/*Parity Error Flag*/
	
	UART0_S2 = 0x0000;
	UART0_C3 = 0x0000;
	UART0_C5 = 0x0000;
	
	/*Unique registers for UART0*/
	UART0_C4 &= ~UART0_C4_MAEN1_MASK;/* All data received is transferred to the data buffer if MAEN2 is cleared*/
	UART0_C4 &= ~UART0_C4_MAEN2_MASK;/* All data received is transferred to the data buffer if MAEN1 is cleared*/
	UART0_C4 &= ~UART0_C4_M10_MASK;/*Receiver and transmitter use 8-bit or 9-bit data characters*/
	UART0_C4 |= UART0_C4_OSR(OSR);/*Over Sampling Ratio*/
	/*OSR range: 4 - 32, Default value: 16*/
		
	UART0_C2 |= UART_C2_TE_MASK; //Enable transmitter
	UART0_C2 |= UART_C2_RE_MASK; //Enable receiver
}
void vfConfigReg_UART1(void){
	SIM_SCGC4 |=  SIM_SCGC4_UART1_MASK;//Set clock UART1
	SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK;//Default clock MCGFLLCLK clock 
	SIM_SOPT5 |= SIM_SOPT5_UART1TXSRC(0);/* UART0 transmit data source select - 00 UART0_TX pin */
	SIM_SOPT5 &= ~SIM_SOPT5_UART1RXSRC_MASK;/*UART0 receive data source select - 0 UART0_RX pin */
	SIM_SOPT5 &= ~SIM_SOPT5_UART1ODE_MASK;/*0 Open drain is disabled on UART0 */
	
	// baud rate = UART module clock / ( SBR[12:0]x16)
	UART1_BDH &= ~UART_BDH_LBKDIE_MASK; /*Hardware interrupts from UART _S2[LBKDIF] disabled*/
	UART1_BDH &= ~UART_BDH_RXEDGIE_MASK;/*Hardware interrupts from UART _S2[RXEDGIF] disabled*/
	UART1_BDH |=  UART_BDH_SBNS_MASK;   /*Stop Bit Number Select -> Two stop bit*/
	UART1_BDH |=  UART_BDH_SBR(SBR>>8);
	
	UART1_BDL |=  UART_BDL_SBR(SBR);
			
	UART1_C1 &= ~UART_C1_LOOPS_MASK; /* Normal operation - UART _RX and UART _TX use separate pins*/
	/*Register for UART1 and UART2*/
	UART1_C1 &= ~UART_C1_UARTSWAI_MASK;/* UART continue to run in Wait mode*/
	
	UART1_C1 &= ~UART_C1_RSRC_MASK;  /* Unusable. Must be combined with UART0_C1_LOOPS_MASK = 1*/
	UART1_C1 &= ~UART_C1_M_MASK;     /* Receiver and transmitter use 8-bit data characters*/
	UART1_C1 &= ~UART_C1_WAKE_MASK;  /* Idle-line wakeup.*/
	UART1_C1 &= ~UART_C1_ILT_MASK;   /* Idle character bit count starts after start bit. */
	UART1_C1 |=  UART_C1_PE_MASK;    /* Parity enabled*/
	UART1_C1 &= ~UART_C1_PT_MASK;	  /* Even parity*/
	
	UART1_C2 &= ~UART_C2_TIE_MASK; /* Hardware interrupts from TDRE disabled*/
	UART1_C2 &= ~UART_C2_TCIE_MASK;/* Hardware interrupts from TC disabled; */
	UART1_C2 &= ~UART_C2_RIE_MASK; /* Hardware interrupts from RDRF disabled*/
	UART1_C2 &= ~UART_C2_ILIE_MASK;/* Hardware interrupts from IDLE disabled*/
	UART1_C2 &= ~UART_C2_TE_MASK;  /* Transmitter disabled. */
	UART1_C2 &= ~UART_C2_RE_MASK;  /* Receiver disabled*/
	UART1_C2 &= ~UART_C2_RWU_MASK; /* Normal UART receiver operation*/
	UART1_C2 &= ~UART_C2_SBK_MASK; /* Normal transmitter operation*/
	
	/*Flags p729*/
	UART1_S1 &= ~UART_S1_TDRE_MASK;/* Transmit Data Register Empty Flag*/
	UART1_S1 &= ~UART_S1_TC_MASK;  /*Transmission complete flag*/
	UART1_D = 0x00;/*To clean TDRE and TC flags*/
	UART1_S1 &= ~UART_S1_RDRF_MASK;/*Receive Data Register Full Flag*/
	if(UART1_D){/*To clean RDRF flag*/}
	/*Clean flags*/
	UART1_S1 |=  UART_S1_IDLE_MASK;/*Idle Line Flag*/
	UART1_S1 |=  UART_S1_OR_MASK;/*Receiver Overrun Flag*/
	UART1_S1 |=  UART_S1_NF_MASK;/*Noise flag*/
	UART1_S1 |=  UART_S1_FE_MASK;/*Framing Error Flag*/
	UART1_S1 |=  UART_S1_PF_MASK;/*Parity Error Flag*/
	
	UART1_S2 = 0x0000;
	UART1_C3 = 0x0000;
	
	UART1_C4 |= UART_C4_TDMAS_MASK;/*If TIE set and TDRE flag set, the TDRE DMA request signal is asserted to request a DMA transfer.*/
	UART1_C4 |= UART_C4_RDMAS_MASK;/*If RIE set and RDRF flag set, RDRF DMA request signal is asserted to request a DMA transfer.*/
		
	UART1_C2 |= UART_C2_TE_MASK; //Enable transmitter
	UART1_C2 |= UART_C2_RE_MASK; //Enable receiver
}
void vfConfigReg_UART2(void){
	SIM_SCGC4 |=  SIM_SCGC4_UART2_MASK;//Set clock UART1
	SIM_SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_MASK;//Default clock MCGFLLCLK clock 
	SIM_SOPT5 |= SIM_SOPT5_UART1TXSRC(0);/* UART2 transmit data source select - 00 UART0_TX pin */
	SIM_SOPT5 &= ~SIM_SOPT5_UART1RXSRC_MASK;/*UART2 receive data source select - 0 UART0_RX pin */
	SIM_SOPT5 &= ~SIM_SOPT5_UART1ODE_MASK;/*0 Open drain is disabled on UART0 */
	
	// baud rate = UART module clock / ( SBR[12:0]x16)
	UART2_BDH &= ~UART_BDH_LBKDIE_MASK; /*Hardware interrupts from UART _S2[LBKDIF] disabled*/
	UART2_BDH &= ~UART_BDH_RXEDGIE_MASK;/*Hardware interrupts from UART _S2[RXEDGIF] disabled*/
	UART2_BDH |=  UART_BDH_SBNS_MASK;   /*Stop Bit Number Select -> Two stop bit*/
	UART2_BDH |=  UART_BDH_SBR(SBR>>8);
	
	UART2_BDL |=  UART_BDL_SBR(SBR);
			
	UART2_C1 &= ~UART_C1_LOOPS_MASK; /* Normal operation - UART _RX and UART _TX use separate pins*/
	/*Register for UART1 and UART2*/
	UART2_C1 &= ~UART_C1_UARTSWAI_MASK;/* UART continue to run in Wait mode*/
	
	UART2_C1 &= ~UART_C1_RSRC_MASK;  /* Unusable. Must be combined with UART0_C1_LOOPS_MASK = 1*/
	UART2_C1 &= ~UART_C1_M_MASK;     /* Receiver and transmitter use 8-bit data characters*/
	UART2_C1 &= ~UART_C1_WAKE_MASK;  /* Idle-line wakeup.*/
	UART2_C1 &= ~UART_C1_ILT_MASK;   /* Idle character bit count starts after start bit. */
	UART2_C1 |=  UART_C1_PE_MASK;    /* Parity enabled*/
	UART2_C1 &= ~UART_C1_PT_MASK;	  /* Even parity*/
	
	UART2_C2 &= ~UART_C2_TIE_MASK; /* Hardware interrupts from TDRE disabled*/
	UART2_C2 &= ~UART_C2_TCIE_MASK;/* Hardware interrupts from TC disabled; */
	UART2_C2 &= ~UART_C2_RIE_MASK; /* Hardware interrupts from RDRF disabled*/
	UART2_C2 &= ~UART_C2_ILIE_MASK;/* Hardware interrupts from IDLE disabled*/
	UART2_C2 &= ~UART_C2_TE_MASK;  /* Transmitter disabled. */
	UART2_C2 &= ~UART_C2_RE_MASK;  /* Receiver disabled*/
	UART2_C2 &= ~UART_C2_RWU_MASK; /* Normal UART receiver operation*/
	UART2_C2 &= ~UART_C2_SBK_MASK; /* Normal transmitter operation*/
	
	/*Flags p729*/
	UART2_S1 &= ~UART_S1_TDRE_MASK;/* Transmit Data Register Empty Flag*/
	UART2_S1 &= ~UART_S1_TC_MASK;  /*Transmission complete flag*/
	UART2_D = 0x00;/*To clean TDRE and TC flags*/
	UART2_S1 &= ~UART_S1_RDRF_MASK;/*Receive Data Register Full Flag*/
	if(UART2_D){/*To clean RDRF flag*/}
	/*Clean flags*/
	UART2_S1 |=  UART_S1_IDLE_MASK;/*Idle Line Flag*/
	UART2_S1 |=  UART_S1_OR_MASK;/*Receiver Overrun Flag*/
	UART2_S1 |=  UART_S1_NF_MASK;/*Noise flag*/
	UART2_S1 |=  UART_S1_FE_MASK;/*Framing Error Flag*/
	UART2_S1 |=  UART_S1_PF_MASK;/*Parity Error Flag*/
	
	UART2_S2 = 0x0000;
	UART2_C3 = 0x0000;
	
	UART2_C4 |= UART_C4_TDMAS_MASK;/*If TIE set and TDRE flag set, the TDRE DMA request signal is asserted to request a DMA transfer.*/
	UART2_C4 |= UART_C4_RDMAS_MASK;/*If RIE set and RDRF flag set, RDRF DMA request signal is asserted to request a DMA transfer.*/
		
	UART2_C2 |= UART_C2_TE_MASK; //Enable transmitter
	UART2_C2 |= UART_C2_RE_MASK; //Enable receiver
}
/*! \brief    efRead_UART
**
** \note	  Read the value of the UART based on UART channel. Also read and clean flags if needed
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            sDATA_UART_t* spDataUART
**
** \return               eStatus_UART_t eReturn, A confirmation of data received or not
*/
eStatus_UART_t efRead_UART  (sDATA_UART_t* spDataUART){
	eStatus_UART_t eReturn = eFALSE_UART;
	
	switch( spDataUART -> eChannelUART )
	{
	case eUART_0:
		if( UART0_S1 & UART_S1_RDRF_MASK ){
			if( (UART0_S1 & UART_S1_NF_MASK) || (UART0_S1 & UART_S1_PF_MASK) || (UART0_S1 & UART_S1_FE_MASK) 
			 || (UART0_S1 & UART_S1_OR_MASK) )
			{
				/*Clean the corresponding flags error*/
				if( UART0_S1 & UART_S1_NF_MASK )
				{
					UART0_S1 |= UART_S1_NF_MASK;
				}
				if( UART0_S1 & UART_S1_PF_MASK )
				{
					UART0_S1 |= UART_S1_PF_MASK;
				}
				if( UART0_S1 & UART_S1_FE_MASK )
				{
					UART0_S1 |= UART_S1_FE_MASK;
				}
				if( UART0_S1 & UART_S1_OR_MASK )
				{
					UART0_S1 |= UART_S1_OR_MASK;
				}
			
				eReturn = eFALSE_UART;
			}
			else
			{
				/*Read value received and clean UART_S1_RDRF flag*/
				spDataUART -> u8ValRxUART = UART0_D;
				vfConvert_UART( (&spDataUART));
				eReturn = eTRUE_UART;
			}
		}else eReturn = eFALSE_UART;
		break;
	case eUART_1:
		if( UART1_S1 & UART_S1_RDRF_MASK ){
			if( (UART1_S1 & UART_S1_NF_MASK) || (UART1_S1 & UART_S1_PF_MASK) || (UART1_S1 & UART_S1_FE_MASK) 
			 || (UART1_S1 & UART_S1_OR_MASK) )
			{
				/*Clean the corresponding flags error*/
				if( UART1_S1 & UART_S1_NF_MASK )
				{
					UART1_S1 |= UART_S1_NF_MASK;
				}
				if( UART1_S1 & UART_S1_PF_MASK )
				{
					UART1_S1 |= UART_S1_PF_MASK;
				}
				if( UART1_S1 & UART_S1_FE_MASK )
				{
					UART1_S1 |= UART_S1_FE_MASK;
				}
				if( UART1_S1 & UART_S1_OR_MASK )
				{
					UART1_S1 |= UART_S1_OR_MASK;
				}
					
				eReturn = eFALSE_UART;
			}
			else
			{
				/*Read value received and clean UART_S1_RDRF flag*/
				spDataUART -> u8ValRxUART = UART1_D;
				vfConvert_UART( (&spDataUART));
				eReturn = eTRUE_UART;
			}
		}else eReturn = eFALSE_UART;
		break;
	case eUART_2:
		if( UART2_S1 & UART_S1_RDRF_MASK ){
			if( (UART2_S1 & UART_S1_NF_MASK) || (UART2_S1 & UART_S1_PF_MASK) || (UART2_S1 & UART_S1_FE_MASK) 
			 || (UART2_S1 & UART_S1_OR_MASK) )
			{
				/*Clean the corresponding flags error*/
				if( UART2_S1 & UART_S1_NF_MASK )
				{
					UART2_S1 |= UART_S1_NF_MASK;
				}
				if( UART2_S1 & UART_S1_PF_MASK )
				{
					UART2_S1 |= UART_S1_PF_MASK;
				}
				if( UART2_S1 & UART_S1_FE_MASK )
				{
					UART2_S1 |= UART_S1_FE_MASK;
				}
				if( UART2_S1 & UART_S1_OR_MASK )
				{
					UART2_S1 |= UART_S1_OR_MASK;
				}
						
				eReturn = eFALSE_UART;
			}
			else
			{
				/*Read value received and clean UART_S1_RDRF flag*/
				spDataUART -> u8ValRxUART = UART2_D;
				vfConvert_UART( (&spDataUART));
				eReturn = eTRUE_UART;
			}
		}else eReturn = eFALSE_UART;
		break;
	default: eReturn = eFALSE_UART;
		break;
	}
	
	return  eReturn;
}
/*! \brief    efSend_UART
**
** \note	  Send the value by UART based on UART channel
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            sDATA_UART_t* spDataUART, uint8_t u8UARTval
**
** \return               eStatus_UART_t eReturn, A confirmation of data sent or not
*/
eStatus_UART_t efSend_UART (sDATA_UART_t* spDataUART, uint8_t u8UARTval){
	eStatus_UART_t eReturn = eFALSE_UART;
	
	switch( spDataUART -> eChannelUART )
	{
	case eUART_0:
		if(UART0_S1 & UART0_S1_TDRE_MASK){/*Transmit Data Register Empty Flag*/
			UART0_D = u8UARTval;
			spDataUART -> u8ValTxUART = u8UARTval;
			eReturn = eTRUE_UART;
		}else {eReturn = eFALSE_UART;}	
		break;
	case eUART_1:
		if(UART1_S1 & UART_S1_TDRE_MASK){/*Transmit Data Register Empty Flag*/
			UART1_D = u8UARTval;
			spDataUART -> u8ValTxUART = u8UARTval;
			eReturn = eTRUE_UART;
		}else {eReturn = eFALSE_UART;}	
		break;
	case eUART_2:
		if(UART2_S1 & UART_S1_TDRE_MASK){/*Transmit Data Register Empty Flag*/
			UART2_D = u8UARTval;
			spDataUART -> u8ValTxUART = u8UARTval;
			eReturn = eTRUE_UART;
		}else {eReturn = eFALSE_UART;}	
		break;
	default: eReturn = eFALSE_UART;
		break;
	}
	
	return eReturn;
}
/*! \brief    vfConvert_UART
**
** \note	  Separate Hundreds, Dozens and Units from UART read value.
** 			  Most used for display UART values on LCD
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]           sDATA_UART_t** spDataUART
**
** \return               NA
*/
void vfConvert_UART(sDATA_UART_t** spDataUART)
{
	uint8_t u8Cnt = 0;
	(*spDataUART) -> u8Hundreds = (*spDataUART) -> u8ValRxUART;
	(*spDataUART) -> u8Dozens   = (*spDataUART) -> u8ValRxUART;
	(*spDataUART) -> u8Units    = (*spDataUART) -> u8ValRxUART;

	/*======================Get Hundreds==================================*/
	for( u8Cnt = 0 ; (*spDataUART) -> u8Hundreds > 100 ; u8Cnt++ ){
		(*spDataUART) -> u8Hundreds -= 100;
	}
	(*spDataUART) -> u8Hundreds = u8Cnt;
	
	/*======================Get Dozens====================================*/
	if( (*spDataUART) -> u8Hundreds >= 1)
	{
		(*spDataUART) -> u8Dozens -= ( (*spDataUART) -> u8Hundreds * 100 );
		for( u8Cnt = 0 ; (*spDataUART) -> u8Dozens > 10 ; u8Cnt++ ){
			(*spDataUART) -> u8Dozens -= 10;
		}
		(*spDataUART) -> u8Dozens = u8Cnt;
	}
	else
	{
		for( u8Cnt = 0 ; (*spDataUART) -> u8Dozens >= 10 ; u8Cnt++ ){
			(*spDataUART) -> u8Dozens -= 10;
		}
		(*spDataUART) -> u8Dozens = u8Cnt;
	}
	/*======================Get Units=====================================*/
	(*spDataUART) -> u8Units = (*spDataUART)->u8Units - ((*spDataUART)->u8Hundreds * 100) - ((*spDataUART) -> u8Dozens * 10) ;

	
}

