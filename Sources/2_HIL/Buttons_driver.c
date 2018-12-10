/*
** Project: Calculator for KL25Z
** File   : Buttons_driver.c
** Author : Ivan Valadez
** Date   : 2 - October - 2018
**
** Overview: C file containing
**
** $Log$
*/
/*---------------------------------------------------------------------------
** Includes
*/
#include "Buttons_driver.h"
/*---------------------------------------------------------------------------
** Defines and Macros
*/
#define INITIAL_ID			(0x00u)

#define TIME_Button_1S			(1800000u)
#define TIME_Button_500MS		(900000u)
#define TIME_Button_250MS		(450000u)
#define TIME_Button_100MS		(180000u)

/*Original 2500*/
#define DEBOUNCING (20u)/*You must adjust the value according to the performance of the main code*/
/*---------------------------------------------------------------------------
** Typedefs
*/
typedef eInOut_GPIO_t  eInOut_Buttons_t;
/*---------------------------------------------------------------------------
** Data
*/
static uint8_t u8CounterID = 0;
/*---------------------------------------------------------------------------
** Prototypes Functions
*/
void vfdelay_Button(uint32_t u32Time);
/*---------------------------------------------------------------------------
** Functions
*/
/*! \brief    vfdelay_Button
**
** \note	  Makes a decrement count until get to 0
** 			  Its function is waste time
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            uint32_t u32Time
**
** \return               NA
** \description
*/
void vfdelay_Button(uint32_t u32Time)
{
	while(u32Time--);
}
/*-------------------------------------------------------------------------*/
/*! \brief    efCreateButton
**
** \note	  Initialize the port and pin as input that you will use as button.
** 			  Also, verify the arguments passed are valid or not and returns
** 			  a boolean value for success or fail of the process.
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            sButton_t *psButton,
** 						 ePORTx_Buttons_t ePORTx,
** 						 ePINx_Buttons_t ePINx
**
** \return               eStatus_Buttons_t, A confirmation of internal process (Success or Fail)
** \description
*/
eStatus_Buttons_t efCreateButton  (sButton_t *psButton, ePORTx_Buttons_t ePORTx,ePINx_Buttons_t ePINx)
{
	eStatus_Buttons_t eResult = eFALSE_BUTTONS;

	switch(ePORTx){
	case ePORTA_GPIO:
		/*Verify ePINx is a valid direction to the corresponding port of board KL25Z*/
		if(ePINx == ePIN_1_GPIO  || ePINx == ePIN_2_GPIO || ePINx == ePIN_4_GPIO || ePINx == ePIN_5_GPIO || 
		   ePINx == ePIN_12_GPIO || ePINx == ePIN_13_GPIO)
		{
			if((eStatus_GPIO_t)eTRUE_BUTTONS == efInit_GPIO( ePORTx, ePINx, eINPUT_GPIO ) )/*Calling Initialization of the pin*/
			{
				psButton -> u8ID    	= INITIAL_ID + u8CounterID;
				psButton -> ePort   	= ePORTx;
				psButton -> ePin    	= ePINx;
				psButton -> u16Debounce = DEBOUNCING; /*Initial value for ReadButtonNonBlocking*/
				psButton -> eState    	= eNOT_PRESSED;/*Initial state for ReadButtonNonBlocking*/

				eResult = eTRUE_BUTTONS;
			}else eResult = eFALSE_BUTTONS;

		}else eResult = eFALSE_BUTTONS;
		break;
	case ePORTB_GPIO:
		if(ePINx == ePIN_0_GPIO || ePINx == ePIN_1_GPIO || ePINx == ePIN_2_GPIO || ePINx == ePIN_3_GPIO || 
		   ePINx == ePIN_8_GPIO || ePINx == ePIN_9_GPIO)
		{
			if((eStatus_GPIO_t)eTRUE_BUTTONS == efInit_GPIO( ePORTx, ePINx, eINPUT_GPIO ) )
			{
				psButton -> u8ID    	= INITIAL_ID + u8CounterID;
				psButton -> ePort   	= ePORTx;
				psButton -> ePin    	= ePINx;
				psButton -> u16Debounce = DEBOUNCING;
				psButton -> eState    	= eNOT_PRESSED;

				eResult = eTRUE_BUTTONS;
			}else eResult = eFALSE_BUTTONS;
		}else eResult = eFALSE_BUTTONS;
		break;
	case ePORTC_GPIO:
		if(ePINx == ePIN_0_GPIO  || ePINx == ePIN_1_GPIO  || ePINx == ePIN_2_GPIO  || ePINx == ePIN_3_GPIO || 
		   ePINx == ePIN_4_GPIO  || ePINx == ePIN_5_GPIO  || ePINx == ePIN_6_GPIO  || ePINx == ePIN_7_GPIO ||
		   ePINx == ePIN_8_GPIO  || ePINx == ePIN_9_GPIO  || ePINx == ePIN_10_GPIO || ePINx == ePIN_11_GPIO||
		   ePINx == ePIN_12_GPIO || ePINx == ePIN_13_GPIO || ePINx == ePIN_16_GPIO || ePIN_17_GPIO)
		{
			if((eStatus_GPIO_t)eTRUE_BUTTONS == efInit_GPIO( ePORTx, ePINx, eINPUT_GPIO ) )
			{
				psButton -> u8ID    	= INITIAL_ID + u8CounterID;
				psButton -> ePort   	= ePORTx;
				psButton -> ePin    	= ePINx;
				psButton -> u16Debounce = DEBOUNCING;
				psButton -> eState    	= eNOT_PRESSED;

				eResult = eTRUE_BUTTONS;
			}else eResult = eFALSE_BUTTONS;
		}else eResult = eFALSE_BUTTONS;
		break;
	case ePORTD_GPIO:
		if(ePINx == ePIN_0_GPIO || ePINx == ePIN_1_GPIO || ePINx == ePIN_2_GPIO || ePINx == ePIN_3_GPIO ||
		   ePINx == ePIN_4_GPIO || ePINx == ePIN_5_GPIO	|| ePINx == ePIN_6_GPIO || ePINx == ePIN_7_GPIO)
		{
			if((eStatus_GPIO_t)eTRUE_BUTTONS == efInit_GPIO( ePORTx, ePINx, eINPUT_GPIO ) )
			{
				psButton -> u8ID    	= INITIAL_ID + u8CounterID;
				psButton -> ePort   	= ePORTx;
				psButton -> ePin    	= ePINx;
				psButton -> u16Debounce = DEBOUNCING;
				psButton -> eState    	= eNOT_PRESSED;

				eResult = eTRUE_BUTTONS;
			}else eResult = eFALSE_BUTTONS;
		}else eResult = eFALSE_BUTTONS;
		break;
	case ePORTE_GPIO:
		if(ePINx == ePIN_0_GPIO  || ePINx == ePIN_1_GPIO  || ePINx == ePIN_2_GPIO  || ePINx == ePIN_3_GPIO  ||
		   ePINx == ePIN_4_GPIO  || ePINx == ePIN_5_GPIO  || ePINx == ePIN_20_GPIO || ePINx == ePIN_21_GPIO ||
		   ePINx == ePIN_22_GPIO || ePINx == ePIN_23_GPIO || ePINx == ePIN_29_GPIO || ePINx == ePIN_30_GPIO)
		{
			if((eStatus_GPIO_t)eTRUE_BUTTONS == efInit_GPIO( ePORTx, ePINx, eINPUT_GPIO ) )
			{
				psButton -> u8ID    	= INITIAL_ID + u8CounterID;
				psButton -> ePort   	= ePORTx;
				psButton -> ePin    	= ePINx;
				psButton -> u16Debounce = DEBOUNCING;
				psButton -> eState    	= eNOT_PRESSED;

				eResult = eTRUE_BUTTONS;
			}else eResult = eFALSE_BUTTONS;
		}else eResult = eFALSE_BUTTONS;
		break;
	default:     eResult = eFALSE_BUTTONS;
	break;
	}//End switch

	u8CounterID++;

	return eResult;
}
/*! \brief    efReadButton
**
** \note	  Read the value of the button that you create and return its state (Logic 1 or 0)
** 			  Read twice the value to avoid some errors and use the function delay as a debouncer
**
** 			  NOTE: Check configuration of GPIO_driver.c to see if the button is pull-up or pull-down
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            sButton_t *psButton,
**
** \return               eStatus_Buttons_t, A flag = eFALSE_BUTTONS to not reading and Flag = eTRUE_BUTTONS read a press
** \description
*/
eStatus_Buttons_t efReadButton    (sButton_t *psButton)
{
	eStatus_Buttons_t eResult = eFALSE_BUTTONS;

	if( (eStatus_GPIO_t)eTRUE_BUTTONS  == efReadPin_GPIO(psButton->ePort,psButton->ePin))
	{
		if((eStatus_GPIO_t)eTRUE_BUTTONS == efReadPin_GPIO(psButton->ePort,psButton->ePin))
		{
			vfdelay_Button(TIME_Button_100MS);
			if((eStatus_GPIO_t)eTRUE_BUTTONS == efReadPin_GPIO(psButton->ePort,psButton->ePin))
			{
				eResult = eTRUE_BUTTONS;
			}else eResult = eFALSE_BUTTONS;

		}else eResult = eFALSE_BUTTONS;

	}else eResult = eFALSE_BUTTONS;

	return eResult;
}
/*! \brief    efReadButtonNonBlocking
**
** \note	  Read the value of the button that you create and return its state (Logic 1 or 0)
** 			  Also, the function it is not blocking. You MUST adapt the define DEBOUNCING
** 			  The definition is not a time, it is a Iteration of the function.
** 			  It determine the times you use this function and the value of the pin is still true
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            sButton_t *psButton,
**
** \return               eStatus_Buttons_t, A flag = eFALSE_BUTTONS to not reading and Flag = eTRUE_BUTTONS read a press
** \decription
*/
eStatus_Buttons_t efReadButtonNonBlocking(sButton_t *psButton)
{
	eStatus_Buttons_t eResult = eFALSE_BUTTONS;

	if( (eStatus_GPIO_t)eTRUE_BUTTONS == efReadPin_GPIO( psButton->ePort, psButton->ePin ) )
	{	/* The variable eState determine if the button already was mark as TRUE
	 	 * and it makes that the count and the process do not have to start again
	 	 * */
		if( eALREADY_PRESSED != psButton->eState )
		{
			if( 0 < (psButton -> u16Debounce) )
			{
				eResult = eFALSE_BUTTONS;
				(psButton -> u16Debounce)--;
				psButton->eState = eNOT_PRESSED;/*eNOT_PRESSED means that the function continues*/

			}else
				{
					(psButton -> u16Debounce) = DEBOUNCING;
					eResult = eTRUE_BUTTONS;
					psButton->eState = eALREADY_PRESSED;/*To end this state*/
				}
		}else
		{
			psButton->eState = eALREADY_PRESSED;/*Keep in this state of COMPLITE and return a TRUE*/
			eResult = eTRUE_BUTTONS;
		}

	}else
	{
	    (psButton -> u16Debounce) = DEBOUNCING;
		eResult = eFALSE_BUTTONS;
		psButton->eState = eNOT_PRESSED;
	}

	return eResult;
}
