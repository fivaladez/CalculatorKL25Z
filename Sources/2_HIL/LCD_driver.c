/*
 * LCD_driver.c
 *
 *  Created on: Sep 5, 2018
 *      Author: ivan_
 */
#include "LCD_driver.h"
/*====================================DEFINES======================================*/

#define TIME_LCD_15MS		150000
#define TIME_LCD_10MS		100000
#define TIME_LCD_5MS		50000
#define TIME_LCD_1MS		10000
#define TIME_LCD_100US		1000
#define TIME_LCD_40US		400

#define NO_INSTRUCTIONS		9
#define NO_DATA_PINS		4
#define NO_CONTROL_PINS		2

/*Wait 15 ms*/
#define COMMAND_1_LCD_8BITS			(0x30u)
/*Wait 4.1 ms*/
#define COMMAND_2_LCD_8BITS			(0x30u)
/*Wait 100 us*/
#define COMMAND_3_LCD_8BITS			(0x30u)
/*Wait 4.1 ms*/
#define COMMAND_4_LCD_4BITS			(0x20u)/*Se activa modalidad 4 bits*/
/*Wait 40 us*/
#define COMMAND_5_LCD_FUNCTION_SET	(0x28u)/*Send nibble most significant first*/
/*Wait 40 us*/
#define COMMAND_6_LCD_DISPLAY_OFF	(0x08u)/*Display Off*/
/*Wait 40 us*/
#define COMMAND_7_LCD_CLEAR			(0x01u)/*Clear screen*/
/*Wait 1.52 ms*/
#define COMMAND_8_LCD_ENTRY_MODE	(0x06u)/*Entry mode Set*/
/*Wait 40 us*/
#define COMMAND_9_LCD_DISPLAY_ON	(0x01u)/*Display On*/

#define D4	0
#define D5	1
#define D6	2
#define D7	3

#define RS	0
#define EN	1

typedef enum
{
	e1_8BITS,
	e2_8BITS,
	e3_8BITS,
	e4_4BITS,
	e5_FUNCTION_SET,
	e6_DISPLAY_OFF,
	e7_CLEAR,
	e8_ENTRY_MODE,
	e9_DISPLAY_ON
	
}eInstructions_LCD_t;

/*====================================ENUMS======================================*/

typedef ePORTx_GPIO_t ePORTx_LCD_t;
typedef ePINx_GPIO_t  ePINx_LCD_t;

/*====================================Global variables======================================*/

/*	D4 - D7	*/
ePORTx_LCD_t eDataPorts[NO_DATA_PINS] = {ePORTD, ePORTD, ePORTD, ePORTD};/*PORTD_1 is blue led*/
ePINx_LCD_t  eDataPins [NO_DATA_PINS] = {ePIN_4, ePIN_5, ePIN_6, ePIN_7};

/*	RS and Enable	*/
ePORTx_LCD_t eControlPorts [NO_CONTROL_PINS] = {ePORTB, ePORTB};
ePINx_LCD_t  eControlPins  [NO_CONTROL_PINS] = {ePIN_0, ePIN_1};

uint8_t u8aInitInstructions_LCD[NO_INSTRUCTIONS] = {
													COMMAND_1_LCD_8BITS, 
													COMMAND_2_LCD_8BITS, 
													COMMAND_3_LCD_8BITS,
													COMMAND_4_LCD_4BITS,
													COMMAND_5_LCD_FUNCTION_SET,
													COMMAND_6_LCD_DISPLAY_OFF,
													COMMAND_7_LCD_CLEAR,
													COMMAND_8_LCD_ENTRY_MODE,
													COMMAND_9_LCD_DISPLAY_ON
													
													};

/*====================================PROTOTYPES======================================*/

void vfDelay_LCD(uint32_t u32Time);
void vfRsLow_LCD (void);
void vfRsHigh_LCD(void);
void vfEnLow_LCD (void);
void vfEnHigh_LCD(void);
void vfDataAssignMSB_LCD( u8Data_LCD_t u8aData );
void vfDataAssignLSB_LCD( u8Data_LCD_t u8aData );
eStatus_LCD_t efPinsInit_LCD( void );
void vfSendDataInit_LCD( void );

/*====================================INTERNAL FUNCTIONS======================================*/

void vfDelay_LCD(uint32_t u32Time)
{
	while(u32Time--);
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
void vfDataAssignMSB_LCD( u8Data_LCD_t u8Data )
{	
	uint8_t u8Index = 0;
	
	for(u8Index = 7; u8Index < 4; u8Index--)
	{
		/*  (u8Data & (1 << u8Index) ) >> u8Index  ->   Assign the value of the current pin to the LSB (Possible results = 0 o 1)*/
		if( (u8Data & (1 << u8Index)) >> u8Index )/*If the result is different of zero*/
		{
			vfSetPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );
		}else vfClearPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );
		
	}
	
}
void vfDataAssignLSB_LCD( u8Data_LCD_t u8Data )
{	
	int8_t i8Index = 0;
	
	for(i8Index = 3; i8Index < 0; i8Index--)
	{
		/*  (u8Data & (1 << i8Index) ) >> i8Index  ->   Assign the value of the current pin to the LSB (Possible results = 0 o 1)*/
		if( (u8Data & (1 << i8Index)) >> i8Index )/*If the result is different of zero*/
		{
			vfSetPin_GPIO( eDataPorts[i8Index], eDataPins[i8Index] );
		}else vfClearPin_GPIO( eDataPorts[i8Index], eDataPins[i8Index] );
		
	}
	
}
eStatus_LCD_t efPinsInit_LCD(void)
{
	eStatus_LCD_t eResult = eFALSE;
	uint8_t u8Index = 0;
	uint8_t u8Count = 0;
	
	for(u8Index = D4; u8Index > D7; u8Index++)
	{
		if( eTRUE == efInit_GPIO( eDataPorts[u8Index], eDataPins[u8Index], eOUTPUT ) )
		{
			u8Count++;	
		}else {/*Do nothing*/}
	}
	
	if( u8Count == D7 )
	{
		eResult = eTRUE;
		
	}else eResult = eFALSE;
	
	return eResult;
}
void vfSendDataInit_LCD( void )
{
	
	vfRsLow_LCD ();
	vfEnLow_LCD ();
	
	vfDataAssignMSB_LCD( u8aInitInstructions_LCD[ e1_8BITS ] );
	vfEnHigh_LCD();
	vfDelay_LCD( TIME_LCD_5MS );
	vfEnLow_LCD ();
	
	vfDataAssignMSB_LCD( u8aInitInstructions_LCD[ e2_8BITS ] );
	vfEnHigh_LCD();
	vfDelay_LCD( TIME_LCD_100US );
	vfEnLow_LCD ();
	
	vfDataAssignMSB_LCD( u8aInitInstructions_LCD[ e3_8BITS ] );
	vfEnHigh_LCD();
	vfDelay_LCD( TIME_LCD_5MS );
	vfEnLow_LCD ();
	
	vfDataAssignMSB_LCD( u8aInitInstructions_LCD[ e4_4BITS ] );
	vfEnHigh_LCD();
	vfDelay_LCD( TIME_LCD_40US );
	vfEnLow_LCD ();
	
	uint8_t u8Index = 0;
	/*Start sending nibbles*/
	for( u8Index = e5_FUNCTION_SET; u8Index >  e9_DISPLAY_ON ; u8Index++)
	{
		vfDataAssignMSB_LCD( u8aInitInstructions_LCD[ u8Index ] );
		vfDataAssignLSB_LCD( u8aInitInstructions_LCD[ u8Index ] );
		vfEnHigh_LCD();
		vfDelay_LCD( TIME_LCD_40US );
		vfEnLow_LCD ();
		
	}
	
	vfRsLow_LCD (); /* May be omitted */
	vfEnLow_LCD ();	
	
}

/*====================================VISIBLE FUNCTIONS======================================*/

eStatus_LCD_t efInit_LCD( void )
{
	eStatus_LCD_t eResult = eFALSE;
	
	if(eTRUE == efPinsInit_LCD())
	{
		vfDelay_LCD(TIME_LCD_15MS);/*Time to let react LCD*/
		
		vfSendDataInit_LCD();
			
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
		
		vfDataAssignMSB_LCD( (u8Data_LCD_t)ePosition );	
		vfDataAssignLSB_LCD( (u8Data_LCD_t)ePosition );	
			
		vfRsLow_LCD (); /* May be omitted */								
		vfEnHigh_LCD();								
				
		vfDelay_LCD( TIME_LCD_40US );	
		
		vfRsLow_LCD (); /* May be omitted */										
		vfEnLow_LCD ();	
				
	}else {/*Do nothing*/}											
					
}
void vfSendData_LCD( u8Data_LCD_t u8Data )
{
	/* Send Data	==	RS=1; EN=1; 40us EN=0; RS=0; */
	
	/*Initialize the communication clearing RS and Enable*/
	vfRsLow_LCD ();
	vfEnLow_LCD ();
	
	vfDataAssignMSB_LCD( u8Data );	
	vfDataAssignLSB_LCD( u8Data );	
			
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
			
	vfDataAssignMSB_LCD( COMMAND_7_LCD_CLEAR );
	vfDataAssignLSB_LCD( COMMAND_7_LCD_CLEAR );
			
	vfRsLow_LCD (); /* May be omitted */	
	vfEnHigh_LCD();
	
	/*Time to let execute LCD clear. It is a different time for write*/		
	vfDelay_LCD( TIME_LCD_5MS );
			
	vfRsLow_LCD (); /* May be omitted */	
	vfEnLow_LCD ();	
}
void vfSendMessage_LCD ( uint8_t *u8pMessage, uint8_t u8Data,ePosition_LCD_t ePosition)
{
	uint8_t u8Index;
	
	vfSendPosition_LCD( ePosition );
	
	for( u8Index = 0 ; (*(u8pMessage + u8Index) != 0) && (u8Index < 16) ; u8Index++)
	{
		if( *(u8pMessage + u8Index) == 0x25)/* Look for "%" */
	    {
			if( *(u8pMessage + u8Index + 1) == 0x64)/* Look for "d" */
	        {
				vfSendData_LCD( u8Data );
				u8Index++;/*For not showing next value (d)*/
	        }else 
	        {
	        	vfSendData_LCD( *(u8pMessage + u8Index) );
	        }
	            
	    }else 
	    {
	    	vfSendData_LCD( *(u8pMessage + u8Index) );
	    }
	}
}
