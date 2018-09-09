/*
 * LCD_driver.c
 *
 *  Created on: Sep 5, 2018
 *      Author: ivan_
 */
#include "derivative.h"
#include "LCD_driver.h"
#include "GPIO_driver.h"

#define TIME_1S			1800000
#define TIME_500MS		900000
#define TIME_250MS		450000
#define TIME_100MS		180000
#define TIME_50MS		90000
#define TIME_25MS		45000
#define TIME_10MS		18000
#define TIME_5MS		9000
#define TIME_3MS		4500
#define TIME_1MS		1000
#define TIME_500US		500
#define TIME_250US		250
#define TIME_100US		100
#define TIME_10US		10
#define TIME_5US		5

uint8_t u8RsPort = ePORTB_GPIO;
uint8_t u8RsPin  = ePIN_0_GPIO;

uint8_t u8EnPort = ePORTB_GPIO;
uint8_t u8EnPin  = ePIN_1_GPIO;

uint8_t u8Port_0 = ePORTD_GPIO;
uint8_t u8Pin_0  = ePIN_0_GPIO;

uint8_t u8Port_1 = ePORTD_GPIO;
uint8_t u8Pin_1  = ePIN_1_GPIO;

uint8_t u8Port_2 = ePORTD_GPIO;
uint8_t u8Pin_2  = ePIN_2_GPIO;

uint8_t u8Port_3 = ePORTD_GPIO;
uint8_t u8Pin_3  = ePIN_3_GPIO;

uint8_t u8Port_4 = ePORTD_GPIO;
uint8_t u8Pin_4  = ePIN_4_GPIO;

uint8_t u8Port_5 = ePORTD_GPIO;
uint8_t u8Pin_5  = ePIN_5_GPIO;

uint8_t u8Port_6 = ePORTD_GPIO;
uint8_t u8Pin_6  = ePIN_6_GPIO;

uint8_t u8Port_7 = ePORTD_GPIO;
uint8_t u8Pin_7  = ePIN_7_GPIO;

#define INIT_INST_LENGTH	5

uint8_t u8aInitInstructions_LCD[INIT_INST_LENGTH] = {0x38, 0x38, 0x38, 0x0C, 0x01};

void vfRsLow_LCD (void);
void vfRsHigh_LCD (void);
void vfEnLow_LCD (void);
void vfEnHigh_LCD(void);

void vfDataAssign(uint8_t u8aData);

void vfInitOuts_LCD(void);

void vfDelay_LCD(uint32_t u32Time);

/*==========================================================================*/

void vfDelay_LCD(uint32_t u32Time)
{
	uint32_t u32Value = 0;
	for(u32Value = u32Time; 0 < u32Value; u32Value--){/*Do nothing*/}
}

void vfRsLow_LCD (void)
{
	vfClearPort_GPIO(u8RsPort,u8RsPin);
}

void vfRsHigh_LCD (void)
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

/*==========================================================================*/

void vfDataAssign(uint8_t u8Data)
{
	uint8_t u8aBit[8] = {0};
	u8aBit[0] = ( (u8Data &= (1 << 0) ) >> 0);
	u8aBit[1] = ( (u8Data &= (1 << 1) ) >> 1);
	u8aBit[2] = ( (u8Data &= (1 << 2) ) >> 2);
	u8aBit[3] = ( (u8Data &= (1 << 3) ) >> 3);
	u8aBit[4] = ( (u8Data &= (1 << 4) ) >> 4);
	u8aBit[5] = ( (u8Data &= (1 << 5) ) >> 5);
	u8aBit[6] = ( (u8Data &= (1 << 6) ) >> 6);
	u8aBit[7] = ( (u8Data &= (1 << 7) ) >> 7);
	
	vfPassValToPort_GPIO(u8Port_0, u8Pin_0, u8aBit[0] );
	vfPassValToPort_GPIO(u8Port_1, u8Pin_1, u8aBit[1] );
	vfPassValToPort_GPIO(u8Port_2, u8Pin_2, u8aBit[2] );
	vfPassValToPort_GPIO(u8Port_3, u8Pin_3, u8aBit[3] );
	vfPassValToPort_GPIO(u8Port_4, u8Pin_4, u8aBit[4] );
	vfPassValToPort_GPIO(u8Port_5, u8Pin_5, u8aBit[5] );
	vfPassValToPort_GPIO(u8Port_6, u8Pin_6, u8aBit[6] );
	vfPassValToPort_GPIO(u8Port_7, u8Pin_7, u8aBit[7] );
}

uint8_t u8InitOuts_LCD(void)
{
	uint8_t u8Return = eNOTREADY_LCD;
	
	if( eTRUE_GPIO == u8fInit_GPIO( u8Port_0, u8Pin_0, eOUT_GPIO ) )
	{
		if( eTRUE_GPIO == u8fInit_GPIO( u8Port_1, u8Pin_1, eOUT_GPIO ) )
			{
			if( eTRUE_GPIO == u8fInit_GPIO( u8Port_2, u8Pin_2, eOUT_GPIO ) )
				{
				if( eTRUE_GPIO == u8fInit_GPIO( u8Port_3, u8Pin_3, eOUT_GPIO ) )
					{
					if( eTRUE_GPIO == u8fInit_GPIO( u8Port_4, u8Pin_4, eOUT_GPIO ) )
						{
						if( eTRUE_GPIO == u8fInit_GPIO( u8Port_5, u8Pin_5, eOUT_GPIO ) )
							{
							if( eTRUE_GPIO == u8fInit_GPIO( u8Port_6, u8Pin_6, eOUT_GPIO ) )
								{
								if( eTRUE_GPIO == u8fInit_GPIO( u8Port_7, u8Pin_7, eOUT_GPIO))
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

/*NOTE: The length must the the number of components of the array o use sizeof but allways checking the variable is uint8_t*/
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
		
		vfDelay_LCD(TIME_5US);
		
		vfRsLow_LCD ();
		vfEnLow_LCD ();	
	}
	
}


uint8_t u8fInit_LCD( void )
{
	uint8_t u8Return = eNOTREADY_LCD;
	
	if(eREADY_LCD == u8InitOuts_LCD())
	{
		vfDelay_LCD(TIME_10MS);
			
		vfSendDataInit_LCD( &u8aInitInstructions_LCD[0] , sizeof(u8aInitInstructions_LCD));
			
		u8Return = eREADY_LCD;
		
	}else u8Return = eNOTREADY_LCD;
	
	return u8Return;
}
