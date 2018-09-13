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

typedef ePORTx_GPIO_t ePORTx_LCD_t;
typedef ePINx_GPIO_t  ePINx_LCD_t;
typedef enum
{
	eSTATE_INSTRUCTION_LCD,
	eSTATE_DATA_LCD
}eStates_LCD_t;

/*====================================Global variables======================================*/

ePORTx_LCD_t eRsPort = ePORTB; 	ePINx_LCD_t  eRsPin  = ePIN_0;
ePORTx_LCD_t eEnPort = ePORTB; 	ePINx_LCD_t  eEnPin  = ePIN_1;

ePORTx_LCD_t ePort_0 = ePORTD; 	ePINx_LCD_t  ePin_0  = ePIN_0;
ePORTx_LCD_t ePort_1 = ePORTD; 	ePINx_LCD_t  ePin_1  = ePIN_1;
ePORTx_LCD_t ePort_2 = ePORTD; 	ePINx_LCD_t  ePin_2  = ePIN_2;
ePORTx_LCD_t ePort_3 = ePORTD; 	ePINx_LCD_t  ePin_3  = ePIN_3;
ePORTx_LCD_t ePort_4 = ePORTD; 	ePINx_LCD_t  ePin_4  = ePIN_4;
ePORTx_LCD_t ePort_5 = ePORTD; 	ePINx_LCD_t  ePin_5  = ePIN_5;
ePORTx_LCD_t ePort_6 = ePORTD; 	ePINx_LCD_t  ePin_6  = ePIN_6;
ePORTx_LCD_t ePort_7 = ePORTD; 	ePINx_LCD_t  ePin_7  = ePIN_7;

uint8_t u8aInitInstructions_LCD[INIT_INST_LENGTH] = {0x38, 0x38, 0x38, 0x0C, 0x01};

/*====================================PROTOTYPES======================================*/

void vfDelay_LCD(uint16_t u16Time);
void vfRsLow_LCD (void);
void vfRsHigh_LCD(void);
void vfEnLow_LCD (void);
void vfEnHigh_LCD(void);
void vfDataAssign(uint8_t u8aData);
eStatus_LCD_t efInitOuts_LCD(void);
void vfSendDataInit_LCD( uint8_t *u8apDataLCD , uint8_t u8LenghtArray);

/*====================================INTERNAL FUNCTIONS======================================*/

void vfDelay_LCD(uint16_t u16Time)
{
	while(u16Time--);
}
void vfRsLow_LCD (void)
{
	vfClearPort_GPIO(eRsPort,eRsPin);
}
void vfRsHigh_LCD(void)
{
	vfSetPort_GPIO(eRsPort,eRsPin);
}
void vfEnLow_LCD (void)
{
	vfClearPort_GPIO(eEnPort,eEnPin);
}
void vfEnHigh_LCD(void)
{
	vfSetPort_GPIO(eEnPort,eEnPin);
}
void vfDataAssign_LCD(uint8_t u8Data)
{	
	vfPassValToPort_GPIO(ePort_0, ePin_0, ( (u8Data &= (1 << 0) ) >> 0) );
	vfPassValToPort_GPIO(ePort_1, ePin_1, ( (u8Data &= (1 << 1) ) >> 1) );
	vfPassValToPort_GPIO(ePort_2, ePin_2, ( (u8Data &= (1 << 2) ) >> 2) );
	vfPassValToPort_GPIO(ePort_3, ePin_3, ( (u8Data &= (1 << 3) ) >> 3) );
	vfPassValToPort_GPIO(ePort_4, ePin_4, ( (u8Data &= (1 << 4) ) >> 4) );
	vfPassValToPort_GPIO(ePort_5, ePin_5, ( (u8Data &= (1 << 5) ) >> 5) );
	vfPassValToPort_GPIO(ePort_6, ePin_6, ( (u8Data &= (1 << 6) ) >> 6) );
	vfPassValToPort_GPIO(ePort_7, ePin_7, ( (u8Data &= (1 << 7) ) >> 7) );
}
eStatus_LCD_t efInitOuts_LCD(void)
{
	eStatus_LCD_t eResult = eFALSE;
	
	if( eTRUE == efInit_GPIO( ePort_0, ePin_0, eOUTPUT ) )
	{
		if( eTRUE == efInit_GPIO( ePort_1, ePin_1, eOUTPUT ) )
			{
			if( eTRUE == efInit_GPIO( ePort_2, ePin_2, eOUTPUT ) )
				{
				if( eTRUE == efInit_GPIO( ePort_3, ePin_3, eOUTPUT ) )
					{
					if( eTRUE == efInit_GPIO( ePort_4, ePin_4, eOUTPUT ) )
						{
						if( eTRUE == efInit_GPIO( ePort_5, ePin_5, eOUTPUT ) )
							{
							if( eTRUE == efInit_GPIO( ePort_6, ePin_6, eOUTPUT ) )
								{
								if( eTRUE == efInit_GPIO( ePort_7, ePin_7, eOUTPUT))
									{
										eResult = eTRUE;
										
									}else eResult = eFALSE;
								}else eResult = eFALSE;
							}else eResult = eFALSE;
						}else eResult = eFALSE;
					}else eResult = eFALSE;
				}else eResult = eFALSE;
			}else eResult = eFALSE;
	}else eResult = eFALSE;
	
	return eResult;
}
/*NOTE: The length must the the number of components of the array o use sizeof but always checking the variable is uint8_t*/
void vfSendDataInit_LCD( uint8_t *u8apDataLCD , uint8_t u8LengthArray )
{
	uint8_t u8Index  = 0;
	
	for(u8Index = 0; u8Index < u8LengthArray ; u8Index++)
	{		
		vfRsLow_LCD ();
		vfEnLow_LCD ();
		
		vfDataAssign_LCD( u8apDataLCD[u8Index] );
		
		vfRsLow_LCD ();
		vfEnHigh_LCD();
		
		vfDelay_LCD(TIME_LCD_5MS);/*Time to let execute LCD execute commands*/
		
		vfRsLow_LCD ();
		vfEnLow_LCD ();	
	}
}

/*====================================GLOBAL FUNCTIONS======================================*/

eStatus_LCD_t efSendData_LCD( uint8_t *u8apDataLCD , uint8_t u8LengthArray , ePOSSITIONS_LCD_t ePossition)
{
	static eStatus_LCD_t eResult = eFALSE;
	static eStates_LCD_t eState  = eSTATE_INSTRUCTION_LCD;
	static uint8_t u8Index  = 0;
	
	
	switch(eState)
	{
	case eSTATE_INSTRUCTION_LCD:
		if( ((ePossition >= eFILA_01_0) && ((ePossition + u8LengthArray) <= eFILA_01_15) ) || /*Corroboarate the value of possition is in range*/
			((ePossition >= eFILA_02_0) && ((ePossition + u8LengthArray) <= eFILA_02_15) ) )
		{
			/*These instructions set are for positioning the cursor in LCD -> Assign Data, RS = 0 and EN = 1, wait 5 uSeconds, RS = 0 and EN = 0*/
							
			vfRsLow_LCD ();
			vfEnLow_LCD ();
			
			vfDataAssign_LCD( eFILA_01_0 );
								
			vfRsLow_LCD ();
			vfEnHigh_LCD();
									
			vfDelay_LCD(TIME_LCD_40US);/*Time to let execute LCD write*/
									
			vfRsLow_LCD ();
			vfEnLow_LCD ();
			
			eState  = eSTATE_DATA_LCD;
			eResult = eFALSE;
				
		}else 
			{
				eState  = eSTATE_INSTRUCTION_LCD;
				eResult = eFALSE;
			}	
		break;
	case eSTATE_DATA_LCD:
		if(u8Index < u8LengthArray)
		{
			/*These instruction sets are for write in LCD -> Assign Data, RS = 1 and EN = 1, wait 5 uSeconds, RS = 0 and EN = 0*/
			vfRsLow_LCD ();
			vfEnLow_LCD ();
								
			vfDataAssign_LCD( u8apDataLCD[u8Index] );
							
			vfRsHigh_LCD ();
			vfEnHigh_LCD();
							
			vfDelay_LCD(TIME_LCD_40US);
							
			vfRsLow_LCD ();
			vfEnLow_LCD ();	
			
			u8Index++;
			eState  = eSTATE_DATA_LCD;
			eResult = eFALSE;
		}else 
			{
				u8Index = 0;
				eState  = eSTATE_INSTRUCTION_LCD;
				eResult = eTRUE;
			}
		break;
	default:
		u8Index = 0;
		eState  = eSTATE_INSTRUCTION_LCD;
		eResult = eFALSE;
		break;
	}//End of switch
	
	return eResult;
}
eStatus_LCD_t efInit_LCD( void )
{
	eStatus_LCD_t eResult = eFALSE;
	
	if(eTRUE == efInitOuts_LCD())
	{
		vfDelay_LCD(TIME_LCD_10MS);
			
		vfSendDataInit_LCD( &u8aInitInstructions_LCD[0] , sizeof(u8aInitInstructions_LCD));
			
		eResult = eTRUE;
		
	}else eResult = eFALSE;
	
	return eResult;
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
