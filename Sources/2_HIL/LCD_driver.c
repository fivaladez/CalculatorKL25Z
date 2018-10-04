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
#define TIME_LCD_1_5MS		15200
#define TIME_LCD_1MS		10000
#define TIME_LCD_100US		1000
#define TIME_LCD_40US		400/*Best approach to 40us*/

#if DATA_BITS_4 == 0u

#define NO_INSTRUCTIONS		7
#define NO_DATA_PINS		4
#define NO_CONTROL_PINS		2

#define COMMAND_1_LCD	(0x33u)/*For 8 bits twice*/
#define COMMAND_2_LCD	(0x32u)/*For 8 and 4 bits*/
#define COMMAND_3_LCD	(0x28u)/*For 4 bits and 2 lines*/
#define COMMAND_4_LCD	(0x0Eu)/*Display On, Cursor On*/
/*This command can not be sent with normal function sendCommand*/
#define COMMAND_5_LCD	(0x01u)/*Clear screen*/
#define COMMAND_6_LCD	(0x06u)/*Increment cursor*/
#define COMMAND_7_LCD	(0x80u)/*eFILA_01_0*/

#define D4	(0u)
#define D5	(1u)
#define D6	(2u)
#define D7	(3u)

#define RS	(0u)
#define EN	(1u)

#else

#define NO_INSTRUCTIONS		7
#define NO_DATA_PINS		8
#define NO_CONTROL_PINS		2

#define COMMAND_1_LCD	(0x38u)/*For 8 bits and 2 lines*/
#define COMMAND_2_LCD	(0x38u)/*For 8 bits and 2 lines*/
#define COMMAND_3_LCD	(0x38u)/*For 8 bits and 2 lines*/
#define COMMAND_4_LCD	(0x0Eu)/*Display On, Cursor On*/
/*This command can not be sent with normal function sendCommand*/
#define COMMAND_5_LCD	(0x01u)/*Clear screen*/
#define COMMAND_6_LCD	(0x06u)/*Increment cursor*/
#define COMMAND_7_LCD	(0x80u)/*eFILA_01_0*/

#define D0	(0u)
#define D1	(1u)
#define D2	(2u)
#define D3	(3u)
#define D4	(4u)
#define D5	(5u)
#define D6	(6u)
#define D7	(7u)

#define RS	(0u)
#define EN	(1u)

#endif

/*====================================ENUMS======================================*/

typedef ePORTx_GPIO_t ePORTx_LCD_t;
typedef ePINx_GPIO_t  ePINx_LCD_t;

/*====================================Global variables======================================*/
#if DATA_BITS_4 == 0u
/*	D4 - D7	*/
ePORTx_LCD_t eDataPorts[NO_DATA_PINS] = {ePORTC,  ePORTC,  ePORTC,  ePORTC};/*PORTD_1 is blue led*/
ePINx_LCD_t  eDataPins [NO_DATA_PINS] = {ePIN_4, ePIN_3, ePIN_0, ePIN_7};

/*	RS and Enable	*/
ePORTx_LCD_t eControlPorts [NO_CONTROL_PINS] = {ePORTB, ePORTB};
ePINx_LCD_t  eControlPins  [NO_CONTROL_PINS] = {ePIN_0, ePIN_1};
#else
/*	D0 - D7	*/
ePORTx_LCD_t eDataPorts[NO_DATA_PINS] = {ePORTC,  ePORTC,  ePORTC,  ePORTC, ePORTC,  ePORTC,  ePORTC,  ePORTC};
ePINx_LCD_t  eDataPins [NO_DATA_PINS] = {ePIN_11, ePIN_10, ePIN_6, ePIN_5, ePIN_4, ePIN_3, ePIN_0, ePIN_7};

/*	RS and Enable	*/
ePORTx_LCD_t eControlPorts [NO_CONTROL_PINS] = {ePORTB, ePORTB};
ePINx_LCD_t  eControlPins  [NO_CONTROL_PINS] = {ePIN_0, ePIN_1};
#endif
/*====================================PROTOTYPES======================================*/

void vfDelay_LCD(uint32_t u32Time);
void vfRsLow_LCD (void);
void vfRsHigh_LCD(void);
void vfEnLow_LCD (void);
void vfEnHigh_LCD(void);

#if DATA_BITS_4 == 0u
void vfDataAssignMSB_LCD( uint8_t u8aData );
void vfDataAssignLSB_LCD( uint8_t u8aData );
#else
void vfDataAssign_LCD   ( uint8_t u8aData );
#endif

eStatus_LCD_t efPinsInit_LCD( void );


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

#if DATA_BITS_4 == 0u
void vfDataAssignMSB_LCD( uint8_t u8Data )
{	
	uint8_t u8Index = 0;
	
	for(u8Index = D4; u8Index <= D7; u8Index++)
	{
		/*  (u8Data & (1 << u8Index) ) >> u8Index  ->   Assign the value of the current pin to the MSB (Possible results = 0 o 1)*/
		if( (u8Data & (1 << (4 + u8Index))) >> (4 + u8Index) )/*If the result is different of zero*/
		{
			vfSetPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );
		}else vfClearPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );
		
	}
	
}
void vfDataAssignLSB_LCD( uint8_t u8Data )
{	
	uint8_t u8Index = 0;
		
	for(u8Index = D4; u8Index <= D7; u8Index++)
	{
		/*  (u8Data & (1 << u8Index) ) >> u8Index  ->   Assign the value of the current pin to the LSB (Possible results = 0 o 1)*/
		if( (u8Data & (1 << u8Index)) >> u8Index )/*If the result is different of zero*/
		{
			vfSetPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );
		}else vfClearPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );	
	}
	
}
#else
void vfDataAssign_LCD( uint8_t u8Data )
{	
	uint8_t u8Index = 0;
		
	for(u8Index = D0; u8Index <= D7; u8Index++)
	{
		if( (u8Data & (1 << u8Index)) >> u8Index )/*If the result is different of zero*/
		{
			vfSetPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );
		}else vfClearPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );
			
	}
	
}
#endif


eStatus_LCD_t efPinsInit_LCD(void)
{
	eStatus_LCD_t eResult = eFALSE;
	uint8_t u8Index;
	uint8_t u8Count = 0;
	
#if DATA_BITS_4 == 0u
	for( u8Index = D4 ; u8Index <= D7 ; u8Index++ )
	{			
		if( eTRUE == efInit_GPIO( eDataPorts[u8Index], eDataPins[u8Index], eOUTPUT ) )
		{
			u8Count++;	
		}else {/*Do nothing*/}
	}	
#else 
	for( u8Index = D0 ; u8Index <= D7 ; u8Index++ )
	{			
		if( eTRUE == efInit_GPIO( eDataPorts[u8Index], eDataPins[u8Index], eOUTPUT ) )
		{
			u8Count++;	
		}else {/*Do nothing*/}
	}	
#endif
	
	
	if( eTRUE == efInit_GPIO( eControlPorts[RS], eControlPins[RS], eOUTPUT ) )
	{
		u8Count++;	
		if( eTRUE == efInit_GPIO( eControlPorts[EN], eControlPins[EN], eOUTPUT ) )
		{
			u8Count++;	
		}else {/*Do nothing*/}
	}else {/*Do nothing*/}
	
	
	if( u8Count == ( NO_DATA_PINS + NO_CONTROL_PINS ) )
	{
		eResult = eTRUE;
		
	}else eResult = eFALSE;
	
	return eResult;
}

/*====================================VISIBLE FUNCTIONS======================================*/

eStatus_LCD_t efInit_LCD( void )
{
	eStatus_LCD_t eResult = eFALSE;
	
	if(eTRUE == efPinsInit_LCD())
	{
		vfDelay_LCD( TIME_LCD_15MS );/*Time to let react LCD*/
		
		vfSendCommand_LCD( COMMAND_1_LCD );
		vfSendCommand_LCD( COMMAND_2_LCD );
		vfSendCommand_LCD( COMMAND_3_LCD );
		vfSendCommand_LCD( COMMAND_4_LCD );
		vfClear_LCD();
		vfSendCommand_LCD( COMMAND_6_LCD );
		vfSendCommand_LCD( COMMAND_7_LCD );
			
		eResult = eTRUE;
		
	}else eResult = eFALSE;
	
	return eResult;
}
void vfSendPosition_LCD( ePosition_LCD_t ePosition )
{	
	/*Corroborate position is in a valid range*/ 	
	if( ( (ePosition >= eFILA_01_0) && (ePosition <= eFILA_01_15) ) || 
	    ( (ePosition >= eFILA_02_0) && (ePosition <= eFILA_02_15) ) )
	{
		/*Initialize the communication clearing RS and Enable*/
		vfRsLow_LCD ();
		vfEnLow_LCD ();		
		
#if DATA_BITS_4 == 0u
		vfDataAssignMSB_LCD( ePosition );/*Highest priority nibble*/
		vfEnHigh_LCD();	
		vfDelay_LCD( TIME_LCD_40US );
		vfEnLow_LCD();	
			
		vfDataAssignLSB_LCD( ePosition );/*Lowest priority nibble*/
		vfEnHigh_LCD();	
		vfDelay_LCD( TIME_LCD_40US );
		vfEnLow_LCD();	
#else
		vfDataAssign_LCD( ePosition );
		vfEnHigh_LCD();	
		vfDelay_LCD( TIME_LCD_40US );
		vfEnLow_LCD();	
#endif	
				
	}else {/*Do nothing*/}											
					
}
void vfSendCommand_LCD( u8Command_LCD_t u8Command )
{	
	/*Initialize the communication clearing RS and Enable*/
	vfRsLow_LCD ();
	vfEnLow_LCD ();		
	
#if DATA_BITS_4 == 0u
	vfDataAssignMSB_LCD( u8Command );/*Highest priority nibble*/
	vfEnHigh_LCD();	
	vfDelay_LCD( TIME_LCD_40US );
	vfEnLow_LCD();	
			
	vfDataAssignLSB_LCD( u8Command );/*Lowest priority nibble*/
	vfEnHigh_LCD();	
	vfDelay_LCD( TIME_LCD_40US );
	vfEnLow_LCD();	
#else
	vfDataAssign_LCD( u8Command );
	vfEnHigh_LCD();	
	vfDelay_LCD( TIME_LCD_40US );
	vfEnLow_LCD();	
#endif
																
}
void vfSendData_LCD( u8Data_LCD_t u8Data )
{	
	/*Initialize the communication clearing RS and Enable*/
	vfRsHigh_LCD ();
	vfEnLow_LCD ();
	
#if DATA_BITS_4 == 0u
	vfDataAssignMSB_LCD( u8Data );
	vfEnHigh_LCD();	
	vfDelay_LCD( TIME_LCD_40US );
	vfEnLow_LCD();
	
	vfDataAssignLSB_LCD( u8Data );
	vfEnHigh_LCD();	
	vfDelay_LCD( TIME_LCD_40US );
	vfEnLow_LCD();
#else
	vfDataAssign_LCD( u8Data );
	vfEnHigh_LCD();	
	vfDelay_LCD( TIME_LCD_40US );
	vfEnLow_LCD();
#endif
	
	vfRsLow_LCD ();											
							
}	
void vfClear_LCD(void)
{
	/*Initialize the communication clearing RS and Enable*/
	vfRsLow_LCD ();
	vfEnLow_LCD ();	
	
#if DATA_BITS_4 == 0u			
	vfDataAssignMSB_LCD( COMMAND_5_LCD );/*Highest priority nibble*/
	vfEnHigh_LCD();	
	vfDelay_LCD( TIME_LCD_1_5MS );
	vfEnLow_LCD();	
			
	vfDataAssignLSB_LCD( COMMAND_5_LCD );/*Lowest priority nibble*/
	vfEnHigh_LCD();	
	vfDelay_LCD( TIME_LCD_1_5MS );
	vfEnLow_LCD();
#else
	vfDataAssign_LCD( COMMAND_5_LCD );
	vfEnHigh_LCD();	
	vfDelay_LCD( TIME_LCD_1_5MS );
	vfEnLow_LCD();
#endif
}
void vfSendMessage_LCD ( char *u8pMessage )
{
	uint8_t u8Index;
	
	for( u8Index = 0 ; (*(u8pMessage + u8Index) != 0) && (u8Index < 16) ; u8Index++)
	{
		vfSendData_LCD( *(u8pMessage + u8Index) );
	}
}
