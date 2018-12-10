/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "Buttons_driver.h"
#include "Leds_driver.h"
#include "LCD_driver.h"
#include "ADC_driver.h"
#include "PWM_driver.h"
#include "UART_driver.h"

#define TIME_1S			1800000
#define TIME_500MS		900000
#define TIME_250MS		450000

#define sde	123

void vfdelay(uint32_t u32Time);

int main(void)
{
	sButton_t sButton1;
	sDATA_ADC_t sData_ADC;
	sDATA_PWM_t sData_PWM;
	sDATA_UART_t sData_UART;

	if( eTRUE_LED == efInit_LED(eRED_LED)  &&  eTRUE_LED ==  efInit_LED(eGREEN_LED)  &&  eTRUE_LED ==  efInit_LED(eBLUE_LED) )
	{
		vfTurnOff_LED(eRED_LED);
		vfTurnOff_LED(eGREEN_LED);
		vfTurnOff_LED(eBLUE_LED);

		if(eTRUE_BUTTONS == efCreateButton(&sButton1, ePORTA_GPIO, ePIN_1_GPIO))
		{
			vfTurnOn_LED(eBLUE_LED);

		}else
		{
			vfTurnOff_LED(eBLUE_LED);
		}
		/*=============================================*/
		if( eTRUE_LCD == efInit_LCD())
		{
			vfTurnOn_LED(eGREEN_LED);

		}else
		{
			vfTurnOff_LED(eGREEN_LED);
		}
		/*=============================================*/
		if( eTRUE_ADC == efInit_ADC( ePORTD_ADC, ePIN_6_ADC, &sData_ADC) )
		{
			vfTurnOn_LED(eRED_LED);
		}
		else
		{
			vfTurnOff_LED(eRED_LED);
		}
		/*=============================================*/		
		if( eTRUE_PWM == efInit_PWM( &sData_PWM, ePORTD_PWM, ePIN_2_PWM, PWM_PERIOD_16ms) )
		{
			vfTurnOff_LED(eRED_LED);vfTurnOff_LED(eGREEN_LED);vfTurnOff_LED(eBLUE_LED);
		}
		else
		{
			
		}
		/*=============================================*/
		
		if( eTRUE_UART == efInit_UART( ePORTE_UART, eUART_0, &sData_UART) )
		{
			vfTurnOn_LED(eRED_LED);vfTurnOn_LED(eGREEN_LED);vfTurnOn_LED(eBLUE_LED);
		}
		else
		{
					
		}
		/*=============================================*/
	}

	vfTurnOff_LED(eRED_LED);vfTurnOff_LED(eGREEN_LED);vfTurnOff_LED(eBLUE_LED);
	for(;;) {

	   	if(eTRUE_BUTTONS == efReadButtonNonBlocking(&sButton1))
	   	{
	   		
	   		//vfTurnOn_LED( eRED_LED );
	   		while( eFALSE_UART == efSend_UART(&sData_UART, 45) ){}
	   		while( eFALSE_UART == efRead_UART(&sData_UART) ){}
	   		vfSendPosition_LCD(eFILA_02_0);
	   		vfSendMessage_LCD("UART: ");
	   		/*0x30 is equal to a number 0 in ASCII*/
	   		vfSendData_LCD( 0x30 + sData_UART.u8Hundreds );
	   		vfSendData_LCD( 0x30 + sData_UART.u8Dozens );
	   		vfSendData_LCD( 0x30 + sData_UART.u8Units );
	   		if( sData_UART.u8ValRxUART == sData_UART.u8ValTxUART )
	   		{
	   			vfSendMessage_LCD(" Correct  ");
	   		}else 
	   		{
	   			vfSendMessage_LCD(" Incorrect");
	   		}
	   		

	   	}else if(eTRUE_ADC == efRead_ADC( &sData_ADC ) )
	   	{
	   		vfPercentage_PWM( &sData_PWM, (uint8_t)sData_ADC.u16Percent);
	   		
	   		//vfClear_LCD();
	   		vfSendPosition_LCD(eFILA_01_0);
	   		vfSendMessage_LCD("ADC: ");
	   		/*0x30 is equal to a number 0 in ASCII*/
	   		vfSendData_LCD( 0x30 + sData_ADC.u8Hundreds );
	   		vfSendData_LCD( 0x30 + sData_ADC.u8Dozens );
	   		vfSendData_LCD( 0x30 + sData_ADC.u8Units );
	   		vfSendData_LCD( '%' );
	   		
	   	}
	   	else
	   	{
	   		//vfTurnOff_LED( eRED_LED );
	   		vfClear_LCD();
	   	}
	   	

	}//End of infinity loop

	return 0;
}

void vfdelay(uint32_t u32Time)
{
	while(u32Time--);
}
