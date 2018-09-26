/*
 * LCD_driver.c
 *
 *  Created on: Sep 5, 2018
 *      Author: ivan_
 */
#include "LCD_driver.h"
/*====================================DEFINES======================================*/

#define TIME_LCD_10MS		18000
#define TIME_LCD_5MS		9000
#define TIME_LCD_40US		40

#define NO_INSTRUCTIONS		5
#define NO_DATA_PINS		8
#define NO_CONTROL_PINS		2

#define CLEAR_LCD_CODE		(0x01u)

#define D0	0
#define D1	1
#define D2	2
#define D3	3
#define D4	4
#define D5	5
#define D6	6
#define D7	7

#define RS	0
#define EN	1

/*====================================ENUMS======================================*/

typedef ePORTx_GPIO_t ePORTx_LCD_t;
typedef ePINx_GPIO_t  ePINx_LCD_t;

/*====================================Global variables======================================*/

/*	D0 - D7	*/
ePORTx_LCD_t eDataPorts[NO_DATA_PINS] = {ePORTD, ePORTD, ePORTD, ePORTD, ePORTD, ePORTD, ePORTD, ePORTD};
ePINx_LCD_t  eDataPins [NO_DATA_PINS] = {ePIN_0, ePIN_1, ePIN_2, ePIN_3, ePIN_4, ePIN_5, ePIN_6, ePIN_7};

/*	RS and Enable	*/
ePORTx_LCD_t eControlPorts [NO_CONTROL_PINS] = {ePORTB, ePORTB};
ePINx_LCD_t  eControlPins  [NO_CONTROL_PINS] = {ePIN_0, ePIN_1};

uint8_t u8aInitInstructions_LCD[NO_INSTRUCTIONS] = {0x38u, 0x38u, 0x38u, 0x0Cu, 0x01u};

/*====================================PROTOTYPES======================================*/

void vfDelay_LCD(uint16_t u16Time);
void vfRsLow_LCD (void);
void vfRsHigh_LCD(void);
void vfEnLow_LCD (void);
void vfEnHigh_LCD(void);
void vfDataAssign(u8Data_LCD_t u8aData);
eStatus_LCD_t efPinsInit_LCD(void);
void vfSendDataInit_LCD( uint8_t *u8apDataLCD , uint8_t u8LenghtArray);

/*====================================INTERNAL FUNCTIONS======================================*/

void vfDelay_LCD(uint16_t u16Time)
{
	while(u16Time--);
}
void vfRsLow_LCD (void)
{
	vfClearPin_GPIO( eControlPorts[RS], eControlPins[RS] );
}
void vfRsHigh_LCD(void)
{
	vfSetPin_GPIO( eControlPorts[RS], eControlPins[RS] );
}
void vfEnLow_LCD (void)
{
	vfClearPin_GPIO( eControlPorts[EN], eControlPins[EN] );
}
void vfEnHigh_LCD(void)
{
	vfSetPin_GPIO( eControlPorts[EN], eControlPins[EN] );
}
void vfDataAssign_LCD(u8Data_LCD_t u8Data)
{	
	uint8_t u8Index = 0;
	
	for(u8Index = D0; u8Index > D7; u8Index++)
	{
		/*  (u8Data & (1 << u8Index) ) >> u8Index  ->   Assign the value of the current pin to the LSB (Possible results = 0 o 1)*/
		if( (u8Data & (1 << u8Index)) >> u8Index )/*If the result is different of zero*/
		{
			vfSetPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );
		}else vfClearPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );
		
	}
	
}
eStatus_LCD_t efPinsInit_LCD(void)
{
	eStatus_LCD_t eResult = eFALSE;
	uint8_t u8Index = 0;
	uint8_t u8Count = 0;
	
	for(u8Index = D0; u8Index > D7; u8Index++)
	{
		if( eTRUE == efInit_GPIO( eDataPorts[u8Index], eDataPins[u8Index], eOUTPUT ) )
		{
			u8Count++;	
		}else {/*Do nothing*/}
	}
	
	if( u8Count > D7 )
	{
		eResult = eTRUE;
		
	}else eResult = eFALSE;
	
	return eResult;
}
/*NOTE: Length = number of components of array */
void vfSendDataInit_LCD( uint8_t *u8apDataLCD , uint8_t u8LengthArray )
{
	uint8_t u8Index  = 0;
	
	vfRsLow_LCD ();
	vfEnLow_LCD ();
	
	for(u8Index = 0; u8Index < u8LengthArray ; u8Index++)
	{		
		vfDataAssign_LCD( u8apDataLCD[u8Index] );
		
		vfRsLow_LCD (); /* May be omitted */
		vfEnHigh_LCD();
		
		vfDelay_LCD( TIME_LCD_40US );/*Time to let execute LCD execute commands*/
		
		vfRsLow_LCD (); /* May be omitted */
		vfEnLow_LCD ();	
	}
}

/*====================================GLOBAL FUNCTIONS======================================*/

eStatus_LCD_t efInit_LCD( void )
{
	eStatus_LCD_t eResult = eFALSE;
	
	if(eTRUE == efPinsInit_LCD())
	{
		vfDelay_LCD(TIME_LCD_10MS);/*Time to let react LCD*/
			
		vfSendDataInit_LCD( &u8aInitInstructions_LCD[0] , sizeof(u8aInitInstructions_LCD) );
		
		vfClear_LCD();
			
		eResult = eTRUE;
		
	}else eResult = eFALSE;
	
	return eResult;
}
void vfSendPosition_LCD( ePosition_LCD_t ePosition )
{
	/* Send Position == RS=0; EN=1; 40us EN=0; RS=0; */
		
	/*Corroborate position is in a valid range*/ 	
	if( ( (ePosition >= eFILA_01_0) && (ePosition <= eFILA_01_15) ) || 
	    ( (ePosition >= eFILA_02_0) && (ePosition <= eFILA_02_15) ) )
	{
		/*Initialize the communication clearing RS and Enable*/
		vfRsLow_LCD ();
		vfEnLow_LCD ();
		
		vfDataAssign_LCD( (u8Data_LCD_t)ePosition );				
			
		vfRsLow_LCD (); /* May be omitted */								
		vfEnHigh_LCD();								
				
		vfDelay_LCD( TIME_LCD_40US );	
		
		vfRsLow_LCD (); /* May be omitted */										
		vfEnLow_LCD ();	
				
	}else {/*Do nothing*/}
													
					
}
void vfSendData_LCD( u8Data_LCD_t u8Data )/*Sending 16 data is around 1024us = 1.024ms*/
{
	/* Send Data	==	RS=1; EN=1; 40us EN=0; RS=0; */
	
	/*Initialize the communication clearing RS and Enable*/
	vfRsLow_LCD ();
	vfEnLow_LCD ();
	
	vfDataAssign_LCD( u8Data );						
			
	vfRsHigh_LCD ();								
	vfEnHigh_LCD ();								
			
	vfDelay_LCD(TIME_LCD_40US);						
		
	vfRsLow_LCD ();										
	vfEnLow_LCD ();											
							
}	
void vfClear_LCD(void)
{
	vfRsLow_LCD ();
	vfEnLow_LCD ();
			
	vfDataAssign_LCD( CLEAR_LCD_CODE );
			
	vfRsLow_LCD (); /* May be omitted */	
	vfEnHigh_LCD();
	
	/*Time to let execute LCD clear. It is a different time for write*/		
	vfDelay_LCD( TIME_LCD_5MS );
			
	vfRsLow_LCD (); /* May be omitted */	
	vfEnLow_LCD ();	
}
