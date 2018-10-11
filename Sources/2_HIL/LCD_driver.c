/*
** Project: Calculator for KL25Z
** File   : LCD_driver.c
** Author : Ivan Valadez
** Date   : 6 - October - 2018
**
** Overview: C file containing
**
** $Log$
*/
/*---------------------------------------------------------------------------
** Includes
*/
#include "LCD_driver.h"
/*====================================DEFINES======================================*/
/*---------------------------------------------------------------------------
** Defines and Macros
*/
#define TIME_LCD_15MS		(150000u)
#define TIME_LCD_10MS		(100000u)
#define TIME_LCD_5MS		(50000u)
#define TIME_LCD_1_5MS		(15200u)
#define TIME_LCD_1MS		(10000u)
#define TIME_LCD_100US		(1000u)

#if DATA_BITS_4 == 0u

#define TIME_LCD_40US		(400u)/*Best approach to 40us = 400*/

#define NO_INSTRUCTIONS		(7u)
#define NO_DATA_PINS		(4u)
#define NO_CONTROL_PINS		(2u)

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

#define TIME_LCD_40US		(450u)/*Time some different from 4 bit mode*/

#define NO_INSTRUCTIONS		(7u)
#define NO_DATA_PINS		(8u)
#define NO_CONTROL_PINS		(2u)

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
/*---------------------------------------------------------------------------
** Typedefs
*/
typedef ePORTx_GPIO_t ePORTx_LCD_t;
typedef ePINx_GPIO_t  ePINx_LCD_t;
/*---------------------------------------------------------------------------
** Data
*/
#if DATA_BITS_4 == 0u
/*	D4 - D7	*/
ePORTx_LCD_t eDataPorts[NO_DATA_PINS] = {ePORTC,  ePORTC,  ePORTC,  ePORTC};/*PORTD_1 is blue led*/
ePINx_LCD_t  eDataPins [NO_DATA_PINS] = {ePIN_4,  ePIN_3,  ePIN_0,  ePIN_7};
#else
/*	D0 - D7	*/
ePORTx_LCD_t eDataPorts[NO_DATA_PINS] = {ePORTC,  ePORTC,  ePORTC,  ePORTC, ePORTC,  ePORTC,  ePORTC,  ePORTC};
ePINx_LCD_t  eDataPins [NO_DATA_PINS] = {ePIN_11, ePIN_10, ePIN_6,  ePIN_5, ePIN_4,  ePIN_3,  ePIN_0,  ePIN_7};
#endif
/*	RS and Enable	*/                         /* RS  ,    EN*/
ePORTx_LCD_t eControlPorts [NO_CONTROL_PINS] = {ePORTB, ePORTB};
ePINx_LCD_t  eControlPins  [NO_CONTROL_PINS] = {ePIN_0, ePIN_1};
/*---------------------------------------------------------------------------
** Prototypes Functions
*/
void vfDelay_LCD(uint32_t u32Time);
void vfRsLow_LCD (void);
void vfRsHigh_LCD(void);
void vfEnLow_LCD (void);
void vfEnHigh_LCD(void);
eStatus_LCD_t efPinsInit_LCD( void );

#if DATA_BITS_4 == 0u
void vfDataAssignMSB_LCD( uint8_t u8aData );
void vfDataAssignLSB_LCD( uint8_t u8aData );
#else
void vfDataAssign_LCD   ( uint8_t u8aData );
#endif
/*---------------------------------------------------------------------------
** Internal Functions
*/
/*! \brief    vfDelay_LCD
**
** \note	  Makes a decrement count until get to 0
** 			  It is for waste time
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            uint32_t u32Time
**
** \return               NA
** \description
*/
void vfDelay_LCD(uint32_t u32Time)
{
	while(u32Time--);
}
/*! \brief    vfRsLow_LCD
**
** \note	  Writes a logic 0 in the pin assigned to be Register Select (RS)
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            NA
**
** \return          	 NA
** \description
*/
void vfRsLow_LCD (void)
{
	vfClearPin_GPIO( eControlPorts[RS], eControlPins[RS] );
}
/*! \brief    vfRsHigh_LCD
**
** \note	  Writes a logic 1 in the pin assigned to be Register Select (RS)
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            NA
**
** \return          	 NA
** \description
*/
void vfRsHigh_LCD(void)
{
	vfSetPin_GPIO( eControlPorts[RS], eControlPins[RS] );
}
/*! \brief    vfEnLow_LCD
**
** \note	  Writes a logic 0 in the pin assigned to be Enable (EN)
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            NA
**
** \return          	 NA
** \description
*/
void vfEnLow_LCD (void)
{
	vfClearPin_GPIO( eControlPorts[EN], eControlPins[EN] );
}
/*! \brief    vfEnHigh_LCD
**
** \note	  Writes a logic 1 in the pin assigned to be Enable (EN)
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            NA
**
** \return          	 NA
** \description
*/
void vfEnHigh_LCD(void)
{
	vfSetPin_GPIO( eControlPorts[EN], eControlPins[EN] );
}

#if DATA_BITS_4 == 0u
/*! \brief    vfDataAssignMSB_LCD
**
** \note	 Assig the nibble most significant of a byte to 4 pins of data
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            uint8_t u8Data
**
** \return          	 NA
** \description
*/
void vfDataAssignMSB_LCD( uint8_t u8Data )
{
	uint8_t u8Index = 0;

	for(u8Index = D4; u8Index <= D7; u8Index++)
	{
		/*  (u8Data & (1 << u8Index) ) >> u8Index ->  (Possible results = 0 o 1)*/
		/*Read ono to one bits of the most significant nibble of u8Data*/
		if( u8Data & (1 << (4 + u8Index)) )/*Bit read equal to 1*/
		{
			vfSetPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );
		}else vfClearPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] ); /*Bit read equal to 0*/

	}

}
/*! \brief    vfDataAssignLSB_LCD
**
** \note	 Assig the nibble least significant of a byte to 4 pins of data
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            uint8_t u8Data
**
** \return          	 NA
** \description
*/
void vfDataAssignLSB_LCD( uint8_t u8Data )
{
	uint8_t u8Index = 0;

	for(u8Index = D4; u8Index <= D7; u8Index++)
	{
		/*  (u8Data & (1 << u8Index) ) >> u8Index  ->   Assign the value of the current pin to the LSB (Possible results = 0 o 1)*/
		/*Read ono to one bits of the lowest significant nibble of u8Data*/
		if( u8Data & (1 << u8Index))/*Bit read equal to 1*/
		{
			vfSetPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );
		}else vfClearPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );/*Bit read equal to 0*/
	}

}
#else
/*! \brief    vfDataAssign_LCD
**
** \note	 Assig a byte to 8 pins of data
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            uint8_t u8Data
**
** \return          	 NA
** \description
*/
void vfDataAssign_LCD( uint8_t u8Data )
{
	uint8_t u8Index = 0;

	for(u8Index = D0; u8Index <= D7; u8Index++)
	{
		/*Read ono to one bits of u8Data*/
		if( u8Data & (1 << u8Index) )/*Bit read equal to 1*/
		{
			vfSetPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );
		}else vfClearPin_GPIO( eDataPorts[u8Index], eDataPins[u8Index] );/*Bit read equal to 0*/

	}

}
#endif
/*! \brief    efPinsInit_LCD
**
** \note	 Initializes pins of data and control that are going to be used
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            uint8_t u8Data
**
** \return          	 eStatus_LCD_t
** \description
*/
eStatus_LCD_t efPinsInit_LCD(void)
{
	eStatus_LCD_t eResult = eFALSE;
	uint8_t u8Index;
	uint8_t u8Count = 0;

#if DATA_BITS_4 == 0u
	/*Initialize 4 pins for data*/
	for( u8Index = D4 ; u8Index <= D7 ; u8Index++ )
	{
		if( eTRUE == efInit_GPIO( eDataPorts[u8Index], eDataPins[u8Index], eOUTPUT ) )
		{
			u8Count++;
		}else {/*Do nothing*/}
	}
#else
	/*Initialize 8 pins for data*/
	for( u8Index = D0 ; u8Index <= D7 ; u8Index++ )
	{
		if( eTRUE == efInit_GPIO( eDataPorts[u8Index], eDataPins[u8Index], eOUTPUT ) )
		{
			u8Count++;
		}else {/*Do nothing*/}
	}
#endif
	/*Initialize pins of control (RS and EN)*/
	if( eTRUE == efInit_GPIO( eControlPorts[RS], eControlPins[RS], eOUTPUT ) )
	{
		u8Count++;
		if( eTRUE == efInit_GPIO( eControlPorts[EN], eControlPins[EN], eOUTPUT ) )
		{
			u8Count++;
		}else {/*Do nothing*/}
	}else {/*Do nothing*/}

	/*Check that all pins were initialized correctly*/
	if( u8Count == ( NO_DATA_PINS + NO_CONTROL_PINS ) )
	{
		eResult = eTRUE;

	}else eResult = eFALSE;

	return eResult;
}
/*---------------------------------------------------------------------------
** External Functions
*/

/*! \brief    efInit_LCD
**
** \note	  Initializes ports and pins for data and control of LCD.
**			  Also, send command to establish functionalities of the LCD 16x2
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            NA
**
** \return               eStatus_LCD_t, A confirmation (success or fail) of internal process
** \description
*/
eStatus_LCD_t efInit_LCD( void )
{
	eStatus_LCD_t eResult = eFALSE;

	if(eTRUE == efPinsInit_LCD())
	{
		/*Time to let react LCD*/
		vfDelay_LCD( TIME_LCD_15MS );

		/*Initializing commands for LCD*/
		vfSendCommand_LCD( COMMAND_1_LCD );
		vfSendCommand_LCD( COMMAND_2_LCD );
		vfSendCommand_LCD( COMMAND_3_LCD );
		vfSendCommand_LCD( COMMAND_4_LCD );
		vfClear_LCD();/*This command needs a different time of response*/
		vfSendCommand_LCD( COMMAND_6_LCD );
		vfSendCommand_LCD( COMMAND_7_LCD );

		eResult = eTRUE;

	}else eResult = eFALSE;

	return eResult;
}
/*! \brief    vfSendPosition_LCD
**
** \note	  Handles the transmission of commands to positioning the cursor
**			  filtering the accepted values for that and with the posibility
**			  of work with 4 and 8 bits of data
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            ePosition_LCD_t ePosition
**
** \return               NA
** \description
*/
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
/*! \brief    vfSendCommand_LCD
**
** \note	  Handles the transmission of commands to modify functionalities of LCD
**			  Also, it has the posibility of work with 4 and 8 bits of data
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            u8Command_LCD_t u8Command
**
** \return               NA
** \description
*/
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
/*! \brief    vfSendData_LCD
**
** \note	  Handles the transmission of data to LCD
**			  Also, it has the posibility of work with 4 and 8 bits of data
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            u8Data_LCD_t u8Data
**
** \return               NA
** \description
*/
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
/*! \brief    vfClear_LCD
**
** \note	  Handles the transmission of the command to clear screen of LCD
**			  Also, it has the posibility of work with 4 and 8 bits of data
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            NA
**
** \return               NA
** \description
*/
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
/*! \brief    vfSendMessage_LCD
**
** \note	  Handles the transmission of a chain of characters to LCD
**			  Limit the spaces to write to 16 and finish when it finds a NULL
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            char *u8pMessage
**
** \return               NA
** \description
*/
void vfSendMessage_LCD ( char *u8pMessage )
{
	uint8_t u8Index;
	/*Check the pointer is initialized and it will not send more than 16 bytes*/
	for( u8Index = 0 ; (*(u8pMessage + u8Index) != 0) && (u8Index < 16) ; u8Index++)
	{
		vfSendData_LCD( *(u8pMessage + u8Index) );
	}
}
