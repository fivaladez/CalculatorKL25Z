/*
** Project: Calculator for KL25Z
** File   : GPIO_driver.c
** Author : Ivan Valadez
** Date   : 10 - October - 2018
**
** Overview: C file containing the functions for using GPIO pins from MCU KL25K of nxp
**
** $Log$
*/
/*****************************************************************************
**                                                                          **
** 																	        **
** 																	        **
** 														                    **
** 														                    **
** 		   															        **
**                                                                          **
*****************************************************************************/

/*---------------------------------------------------------------------------
** Includes
*/
#include "GPIO_driver.h"
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
/*---------------------------------------------------------------------------
** Functions
*/
/*-------------------------------------------------------------------------*/
/*! \brief    efInit_GPIO
**
** \note	  Initialize Clock, Port and Pin as an output or input and returns
** 			  TRUE if the parameters are valid and the function could started
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 ePINx_GPIO_t ePINx,
** 						 eInOut_GPIO_t eInOut
**
** \return               eStatus_GPIO_t, A confirmation (success or fail) of internal process 
** \description			 
*/
eStatus_GPIO_t efInit_GPIO  ( ePORTx_GPIO_t ePORTx, ePINx_GPIO_t ePINx, eInOut_GPIO_t eInOut )
{
	eStatus_GPIO_t eResult = eFALSE;
	
	switch(ePORTx){
		case ePORTA:
			if(ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_4 || ePINx == ePIN_5 || ePINx == ePIN_12 || ePINx == ePIN_13)
			{
				SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;				     //1° Enable clock for this port
				PORTA_PCR(ePINx) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO);  //2° Mode 1 for working as GPIO_vfInit
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
	
}
/*! \brief    vfSetPin_GPIO
**
** \note	  Writes a logic 1 in the port and pin that you pass as argument
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 ePINx_GPIO_t ePINx
**
** \return          	 NA 
** \description	
*/
void vfSetPin_GPIO   ( ePORTx_GPIO_t ePORTx, ePINx_GPIO_t ePINx ) /*Write a 1*/
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
/*! \brief    vfClearPin_GPIO
**
** \note	  Writes a logic 0 in the port and pin that you pass as argument
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 ePINx_GPIO_t ePINx
**
** \return          	 NA 
** \description	
*/
void vfClearPin_GPIO ( ePORTx_GPIO_t ePORTx, ePINx_GPIO_t ePINx )/*Write a 0*/
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
/*! \brief    vfTogglePin_GPIO
**
** \note	  Toggle the value in the port and pin that you pass as argument
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 ePINx_GPIO_t ePINx
**
** \return          	 NA 
** \description	
*/
void vfTogglePin_GPIO( ePORTx_GPIO_t ePORTx, ePINx_GPIO_t ePINx )
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
/*! \brief    efReadPin_GPIO
**
** \note	  Read the logic value of the required pin and return
** 			  TRUE  = Logic 0
** 			  FALSE = Logic 1
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 ePINx_GPIO_t ePINx,
**
** \return               eStatus_GPIO_t, A confirmation (success or fail) of internal process 
** \description	
*/
eStatus_GPIO_t efReadPin_GPIO( ePORTx_GPIO_t ePORTx, ePINx_GPIO_t ePINx )
{
	eStatus_GPIO_t eStatus = eFALSE;
	
	switch(ePORTx){/*	Possible results: 1 or 0	*/
		case ePORTA: eStatus = ((GPIOA_PDIR &= (1 << ePINx)) >> ePINx);
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
		eStatus = eTRUE;
	}else if(1 == eStatus)
		{
			eStatus = eFALSE;
		}
	
	return eStatus;
}
/*! \brief    vfWritePin_GPIO
**
** \note	  Writes a binary value (0 or 1) in the pin that you pass as argument
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 ePINx_GPIO_t ePINx,
** 						 uint8_t u8Data
**
** \return          	 NA 
** \description	
*/
void vfWritePin_GPIO( ePORTx_GPIO_t ePORTx, ePINx_GPIO_t ePINx, uint8_t u8Data ) 
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
		default: /*Do nothing*/
			break;
	}//End switch
}
/*! \brief    vfWritePort_GPIO
**
** \note	  Writes the value of a byte in the port you pass as argument
** \Attention You will affect the complete register GPIOx_PDOR, so, be careful
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePORTx_GPIO_t ePORTx,
** 						 uint8_t u8Data
**
** \return          	 NA 
** \description	
*/
void vfWritePort_GPIO( ePORTx_GPIO_t ePORTx, uint8_t u8Data ) 
{
	switch(ePORTx){
		case ePORTA: GPIOA_PDOR = u8Data;
			break;
		case ePORTB: GPIOB_PDOR = u8Data;
			break;
		case ePORTC: GPIOC_PDOR = u8Data;   
			break;
		case ePORTD: GPIOD_PDOR = u8Data;
			break;
		case ePORTE: GPIOE_PDOR = u8Data;
			break;
		default: 
			break;
	}
}

