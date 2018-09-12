/*
 * LCD_driver.c
 *
 *  Created on: Sep 5, 2018
 *      Author: ivan_
 */
#include "derivative.h"
#include "LCD_driver.h"
#include "GPIO_driver.h"
/*====================================DEFINES======================================*/

#define TIME_LCD_10MS		18000
#define TIME_LCD_5MS		9000
#define TIME_LCD_3MS		4500
#define TIME_LCD_1MS		1000
#define TIME_LCD_500US		500
#define TIME_LCD_250US		250
#define TIME_LCD_40US		40
#define TIME_LCD_10US		10
#define TIME_LCD_5US		5

#define INIT_INST_LENGTH	5

#define CLEAR_LCD_CODE		(0x01u)

/*====================================ENUMS======================================*/

typedef enum
{
	eSTATE_INSTRUCTION_LCD,
	eSTATE_DATA_LCD
}eStates_LCD_t;

/*====================================Global variables======================================*/

uint8_t u8RsPort = ePORTB;
uint8_t u8RsPin  = ePIN_0;

uint8_t u8EnPort = ePORTB;
uint8_t u8EnPin  = ePIN_1;

uint8_t u8Port_0 = ePORTD;
uint8_t u8Pin_0  = ePIN_0;

uint8_t u8Port_1 = ePORTD;
uint8_t u8Pin_1  = ePIN_1;

uint8_t u8Port_2 = ePORTD;
uint8_t u8Pin_2  = ePIN_2;

uint8_t u8Port_3 = ePORTD;
uint8_t u8Pin_3  = ePIN_3;

uint8_t u8Port_4 = ePORTD;
uint8_t u8Pin_4  = ePIN_4;

uint8_t u8Port_5 = ePORTD;
uint8_t u8Pin_5  = ePIN_5;

uint8_t u8Port_6 = ePORTD;
uint8_t u8Pin_6  = ePIN_6;

uint8_t u8Port_7 = ePORTD;
uint8_t u8Pin_7  = ePIN_7;

uint8_t u8aInitInstructions_LCD[INIT_INST_LENGTH] = {0x38, 0x38, 0x38, 0x0C, 0x01};

/*====================================PROTOTYPES======================================*/

void vfRsLow_LCD (void);
void vfRsHigh_LCD(void);
void vfEnLow_LCD (void);
void vfEnHigh_LCD(void);

void vfInitOuts_LCD(void);

void vfDataAssign(uint8_t u8aData);

void vfSendDataInit_LCD( uint8_t *u8aDataLCD , uint8_t u8LenghtArray);

void vfDelay_LCD(uint16_t u16Time);

/*====================================INTERNAL FUNCTIONS======================================*/

void vfDelay_LCD(uint16_t u16Time)
{
	while(u16Time--);
}

void vfRsLow_LCD (void)
{
	vfClearPort_GPIO(u8RsPort,u8RsPin);
}

void vfRsHigh_LCD(void)
{
	vfSetPort_GPIO(u8RsPort,u8RsPin);
}

void vfEnLow_LCD (void)
{
	vfClearPort_GPIO(u8EnPort,u8EnPin);
}

void vfEnHigh_LCD(void)
{
	vfSetPort_GPIO(u8EnPort,u8EnPin);
}

void vfDataAssign(uint8_t u8Data)
{	
	vfPassValToPort_GPIO(u8Port_0, u8Pin_0, ( (u8Data &= (1 << 0) ) >> 0) );
	vfPassValToPort_GPIO(u8Port_1, u8Pin_1, ( (u8Data &= (1 << 1) ) >> 1) );
	vfPassValToPort_GPIO(u8Port_2, u8Pin_2, ( (u8Data &= (1 << 2) ) >> 2) );
	vfPassValToPort_GPIO(u8Port_3, u8Pin_3, ( (u8Data &= (1 << 3) ) >> 3) );
	vfPassValToPort_GPIO(u8Port_4, u8Pin_4, ( (u8Data &= (1 << 4) ) >> 4) );
	vfPassValToPort_GPIO(u8Port_5, u8Pin_5, ( (u8Data &= (1 << 5) ) >> 5) );
	vfPassValToPort_GPIO(u8Port_6, u8Pin_6, ( (u8Data &= (1 << 6) ) >> 6) );
	vfPassValToPort_GPIO(u8Port_7, u8Pin_7, ( (u8Data &= (1 << 7) ) >> 7) );
}

uint8_t u8InitOuts_LCD(void)
{
	uint8_t u8Return = eNOTREADY_LCD;
	
	if( eTRUE == u8fInit_GPIO( u8Port_0, u8Pin_0, eOUTPUT ) )
	{
		if( eTRUE == u8fInit_GPIO( u8Port_1, u8Pin_1, eOUTPUT ) )
			{
			if( eTRUE == u8fInit_GPIO( u8Port_2, u8Pin_2, eOUTPUT ) )
				{
				if( eTRUE == u8fInit_GPIO( u8Port_3, u8Pin_3, eOUTPUT ) )
					{
					if( eTRUE == u8fInit_GPIO( u8Port_4, u8Pin_4, eOUTPUT ) )
						{
						if( eTRUE == u8fInit_GPIO( u8Port_5, u8Pin_5, eOUTPUT ) )
							{
							if( eTRUE == u8fInit_GPIO( u8Port_6, u8Pin_6, eOUTPUT ) )
								{
								if( eTRUE == u8fInit_GPIO( u8Port_7, u8Pin_7, eOUTPUT))
									{
										u8Return = eREADY_LCD;
										
									}else u8Return = eNOTREADY_LCD;
								}else u8Return = eNOTREADY_LCD;
							}else u8Return = eNOTREADY_LCD;
						}else u8Return = eNOTREADY_LCD;
					}else u8Return = eNOTREADY_LCD;
				}else u8Return = eNOTREADY_LCD;
			}else u8Return = eNOTREADY_LCD;
	}else u8Return = eNOTREADY_LCD;
	
	return u8Return;
}

/*NOTE: The length must the the number of components of the array o use sizeof but always checking the variable is uint8_t*/
void vfSendDataInit_LCD( uint8_t *u8aDataLCD , uint8_t u8LengthArray )
{
	uint8_t u8Index  = 0;
	
	for(u8Index = 0; u8Index < u8LengthArray ; u8Index++)
	{		
		vfRsLow_LCD ();
		vfEnLow_LCD ();
		
		vfDataAssign( u8aDataLCD[u8Index] );
		
		vfRsLow_LCD ();
		vfEnHigh_LCD();
		
		vfDelay_LCD(TIME_LCD_5MS);/*Time to let execute LCD execute commands*/
		
		vfRsLow_LCD ();
		vfEnLow_LCD ();	
	}
}

/*====================================GLOBAL FUNCTIONS======================================*/

uint8_t u8fSendData_LCD( uint8_t *u8aDataLCD , uint8_t u8LengthArray , uint8_t u8StartPossition)
{
	uint8_t u8Return = eNOTREADY_LCD;
	static uint8_t u8State  = eSTATE_INSTRUCTION_LCD;
	static uint8_t u8Index  = 0;
	
	
	switch(u8State)
	{
	case eSTATE_INSTRUCTION_LCD:
		if( ((u8StartPossition >= BEGINING_RAW_1) && ((u8StartPossition + u8LengthArray) <= END_RAW_1) ) || /*Corroboarate the value of possition is in range*/
			((u8StartPossition >= BEGINING_RAW_2) && ((u8StartPossition + u8LengthArray) <= END_RAW_2) ) )
		{
			/*These instructions set are for positioning the cursor in LCD -> Assign Data, RS = 0 and EN = 1, wait 5 uSeconds, RS = 0 and EN = 0*/
							
			vfRsLow_LCD ();
			vfEnLow_LCD ();
			
			vfDataAssign( BEGINING_RAW_1 );
								
			vfRsLow_LCD ();
			vfEnHigh_LCD();
									
			vfDelay_LCD(TIME_LCD_40US);/*Time to let execute LCD write*/
									
			vfRsLow_LCD ();
			vfEnLow_LCD ();
			
			u8State  = eSTATE_DATA_LCD;
			u8Return = eNOTREADY_LCD;
				
		}else 
			{
				u8State  = eSTATE_INSTRUCTION_LCD;
				u8Return = eNOTREADY_LCD;
			}	
		break;
	case eSTATE_DATA_LCD:
		if(u8Index < u8LengthArray)
		{
			/*These instruction sets are for write in LCD -> Assign Data, RS = 1 and EN = 1, wait 5 uSeconds, RS = 0 and EN = 0*/
			vfRsLow_LCD ();
			vfEnLow_LCD ();
								
			vfDataAssign( u8aDataLCD[u8Index] );
							
			vfRsHigh_LCD ();
			vfEnHigh_LCD();
							
			vfDelay_LCD(TIME_LCD_40US);
							
			vfRsLow_LCD ();
			vfEnLow_LCD ();	
			
			u8Index++;
			u8State  = eSTATE_DATA_LCD;
			u8Return = eNOTREADY_LCD;
		}else 
			{
				u8Index = 0;
				u8State  = eSTATE_INSTRUCTION_LCD;
				u8Return = eREADY_LCD;
			}
		break;
	default:
		u8Index = 0;
		u8State  = eSTATE_INSTRUCTION_LCD;
		u8Return = eNOTREADY_LCD;
		break;
	}//End of switch
	
	return u8Return;
}

uint8_t u8fInit_LCD( void )
{
	uint8_t u8Return = eNOTREADY_LCD;
	
	if(eREADY_LCD == u8InitOuts_LCD())
	{
		vfDelay_LCD(TIME_LCD_10MS);
			
		vfSendDataInit_LCD( &u8aInitInstructions_LCD[0] , sizeof(u8aInitInstructions_LCD));
			
		u8Return = eREADY_LCD;
		
	}else u8Return = eNOTREADY_LCD;
	
	return u8Return;
}

void vfClear_LCD(void)
{
	vfRsLow_LCD ();
	vfEnLow_LCD ();
			
	vfDataAssign( CLEAR_LCD_CODE );
			
	vfRsLow_LCD ();
	vfEnHigh_LCD();
			
	vfDelay_LCD(TIME_LCD_5MS);/*Time to let execute LCD clear*/
			
	vfRsLow_LCD ();
	vfEnLow_LCD ();	
}
