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
#define DEBOUNCING (5u)/*You must adjust the value according to the performance of the main code*/
/*---------------------------------------------------------------------------
** Typedefs
*/
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
	eStatus_Buttons_t eResult = eFALSE;

	switch(ePORTx){
	case ePORTA:
		/*Verify ePINx is a valid direction to the corresponding port of board KL25Z*/
		if(ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_4 || ePINx == ePIN_5 || ePINx == ePIN_12 || ePINx == ePIN_13)
		{
			if(eTRUE == efInit_GPIO( ePORTx, ePINx, eINPUT ) )/*Calling Initialization of the pin*/
			{
				psButton -> u8ID    	= INITIAL_ID + u8CounterID;
				psButton -> ePort   	= ePORTx;
				psButton -> ePin    	= ePINx;
				psButton -> u16Debounce = DEBOUNCING; /*Initial value for ReadButtonNonBlocking*/
				psButton -> eState    	= eINCOMPLETE;/*Initial state for ReadButtonNonBlocking*/

				eResult = eTRUE;
			}else eResult = eFALSE;

		}else eResult = eFALSE;
		break;
	case ePORTB:
		if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_8 || ePINx == ePIN_9)
		{
			if(eTRUE == efInit_GPIO( ePORTx, ePINx, eINPUT ) )
			{
				psButton -> u8ID    	= INITIAL_ID + u8CounterID;
				psButton -> ePort   	= ePORTx;
				psButton -> ePin    	= ePINx;
				psButton -> u16Debounce = DEBOUNCING;
				psButton -> eState    	= eINCOMPLETE;

				eResult = eTRUE;
			}else eResult = eFALSE;
		}else eResult = eFALSE;
		break;
	case ePORTC:
		if(ePINx == ePIN_0  || ePINx == ePIN_1  || ePINx == ePIN_2  || ePINx == ePIN_3 || ePINx == ePIN_4  || ePINx == ePIN_5
		|| ePINx == ePIN_6  || ePINx == ePIN_7  || ePINx == ePIN_8  || ePINx == ePIN_9 || ePINx == ePIN_10 || ePINx == ePIN_11
		|| ePINx == ePIN_12 || ePINx == ePIN_13 || ePINx == ePIN_16 || ePIN_17)
		{
			if(eTRUE == efInit_GPIO( ePORTx, ePINx, eINPUT ) )
			{
				psButton -> u8ID    	= INITIAL_ID + u8CounterID;
				psButton -> ePort   	= ePORTx;
				psButton -> ePin    	= ePINx;
				psButton -> u16Debounce = DEBOUNCING;
				psButton -> eState    	= eINCOMPLETE;

				eResult = eTRUE;
			}else eResult = eFALSE;
		}else eResult = eFALSE;
		break;
	case ePORTD:
		if(ePINx == ePIN_0 || ePINx == ePIN_1 || ePINx == ePIN_2 || ePINx == ePIN_3 || ePINx == ePIN_4 || ePINx == ePIN_5
		|| ePINx == ePIN_6 || ePINx == ePIN_7)
		{
			if(eTRUE == efInit_GPIO( ePORTx, ePINx, eINPUT ) )
			{
				psButton -> u8ID    	= INITIAL_ID + u8CounterID;
				psButton -> ePort   	= ePORTx;
				psButton -> ePin    	= ePINx;
				psButton -> u16Debounce = DEBOUNCING;
				psButton -> eState    	= eINCOMPLETE;

				eResult = eTRUE;
			}else eResult = eFALSE;
		}else eResult = eFALSE;
		break;
	case ePORTE:
		if(ePINx == ePIN_0  || ePINx == ePIN_1  || ePINx == ePIN_2  || ePINx == ePIN_3  || ePINx == ePIN_4  || ePINx == ePIN_5
		|| ePINx == ePIN_20 || ePINx == ePIN_21 || ePINx == ePIN_22 || ePINx == ePIN_23 || ePINx == ePIN_29 || ePINx == ePIN_30)
		{
			if(eTRUE == efInit_GPIO( ePORTx, ePINx, eINPUT ) )
			{
				psButton -> u8ID    	= INITIAL_ID + u8CounterID;
				psButton -> ePort   	= ePORTx;
				psButton -> ePin    	= ePINx;
				psButton -> u16Debounce = DEBOUNCING;
				psButton -> eState    	= eINCOMPLETE;

				eResult = eTRUE;
			}else eResult = eFALSE;
		}else eResult = eFALSE;
		break;
	default:     eResult = eFALSE;
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
** \return               eStatus_Buttons_t, A flag = eFALSE to not reading and Flag = eTRUE read a press
** \description
*/
eStatus_Buttons_t efReadButton    (sButton_t *psButton)
{
	eStatus_Buttons_t eResult = eFALSE;

	if( eTRUE  == efReadPin_GPIO(psButton->ePort,psButton->ePin))
	{
		if(eTRUE == efReadPin_GPIO(psButton->ePort,psButton->ePin))
		{
			vfdelay_Button(TIME_Button_100MS);
			if(eTRUE == efReadPin_GPIO(psButton->ePort,psButton->ePin))
			{
				eResult = eTRUE;
			}else eResult = eFALSE;

		}else eResult = eFALSE;

	}else eResult = eFALSE;

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
** \return               eStatus_Buttons_t, A flag = eFALSE to not reading and Flag = eTRUE read a press
** \decription
*/
eStatus_Buttons_t efReadButtonNonBlocking(sButton_t *psButton)
{
	eStatus_Buttons_t eResult = eFALSE;

	if( eTRUE == efReadPin_GPIO( psButton->ePort, psButton->ePin ) )
	{	/* The variable eState determine if the button already was mark as TRUE
	 	 * and it makes that the count and the process do not have to start again
	 	 * */
		if( eCOMPLETE != psButton->eState )
		{
			if( 0 < (psButton -> u16Debounce) )
			{
				eResult = eFALSE;
				(psButton -> u16Debounce)--;
				psButton->eState = eINCOMPLETE;/*eINCOMPLETE means that the function continues*/

			}else
				{
					(psButton -> u16Debounce) = DEBOUNCING;
					eResult = eTRUE;
					psButton->eState = eCOMPLETE;/*To end this state*/
				}
		}else
		{
			psButton->eState = eCOMPLETE;/*Keep in this state of COMPLITE and return a TRUE*/
			eResult = eTRUE;
		}

	}else
	{
	    (psButton -> u16Debounce) = DEBOUNCING;
		eResult = eFALSE;
		psButton->eState = eINCOMPLETE;
	}

	return eResult;
}
