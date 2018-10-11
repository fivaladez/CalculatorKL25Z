/*
** Project: Calculator for KL25Z
** File   : Buttons_driver.h
** Author : Ivan Valadez
** Date   : 2 - October - 2018
**
** Overview: Header file containing
**
** $Log$
*/
#ifndef BUTTONS_DRIVER_H_
#define BUTTONS_DRIVER_H_
/*---------------------------------------------------------------------------
** Includes
*/
#include "derivative.h"
#include "GPIO_driver.h"
/*---------------------------------------------------------------------------
** Defines and Macros
*/
#define NONBLOCKING	(0u)
/*---------------------------------------------------------------------------
** Typedefs
*/
typedef ePINx_GPIO_t   ePINx_Buttons_t;
typedef ePORTx_GPIO_t  ePORTx_Buttons_t;
typedef eStatus_GPIO_t eStatus_Buttons_t;
typedef eInOut_GPIO_t  eInOut_Buttons_t;
typedef enum
{
	eCOMPLETE,
	eINCOMPLETE

}eState_Buttons_t;
typedef struct
{
	uint8_t 		 u8ID;
	ePORTx_Buttons_t ePort;
	ePINx_Buttons_t  ePin;
	eState_Buttons_t eState;
	uint16_t 		 u16Debounce;

}sButton_t;
/*---------------------------------------------------------------------------
** Data
*/

/*---------------------------------------------------------------------------
** Functions
*/

/*-------------------------------------------------------------------------*/
/*! \brief    efCreateButton
**
** \note	  Initialize the port and pin as input that you will use as button
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            sButton_t *psButton,
** 						 ePORTx_Buttons_t ePORTx,
** 						 ePINx_Buttons_t ePINx
**
** \return               eStatus_Buttons_t, A confirmation of internal process (Success or Fail)
*/
eStatus_Buttons_t efCreateButton  (sButton_t *psButton, ePORTx_Buttons_t ePORTx,ePINx_Buttons_t ePINx);
/*! \brief    efReadButton
**
** \note	  Read the value of the button that you create and return its state (Logic 1 or 0)
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            sButton_t *psButton,
**
** \return               eStatus_Buttons_t, A confirmation of internal process (Active or Inactive)
*/
eStatus_Buttons_t efReadButton    (sButton_t *psButton);
/*! \brief    efReadButtonNonBlocking
**
** \note	  Read the value of the button that you create and return its state (Logic 1 or 0)
** 			  Also, the function it is not blocking. You MUST adapt the time of debouncing
** 			  In fact, it is not a time, it is a Iteration of the function.
**
** \param[out]           NA
** \param[in,out]        NA
** \param[in]            sButton_t *psButton,
**
** \return               eStatus_Buttons_t, A confirmation of internal process (Active or Inactive)
*/
eStatus_Buttons_t efReadButtonNonBlocking(sButton_t *psButton);

#endif /* BUTTONS_DRIVER_H_ */
