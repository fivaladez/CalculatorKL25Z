/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "Buttons_driver.h"
#include "Leds_driver.h"
#include "LCD_driver.h"

#define TIME_1S			1800000
#define TIME_500MS		900000
#define TIME_250MS		450000

void vfdelay(uint32_t u32Time);

int main(void)
{
	sButton_t sButton1;
	
	if( eTRUE == efInit_LED(eRED)  &&  eTRUE ==  efInit_LED(eGREEN)  &&  eTRUE ==  efInit_LED(eBLUE) )
	{
		vfTurnOff_LED(eRED);
		vfTurnOff_LED(eGREEN);
		vfTurnOff_LED(eBLUE);
		
		if(eTRUE == efCreateButton(&sButton1, ePORTA, ePIN_1))
		{
			vfTurnOn_LED(eBLUE);
			
		}else 
			{
				vfTurnOff_LED(eBLUE);
		    }
		
		if( eTRUE == efInit_LCD())
		{
			vfTurnOn_LED(eGREEN);
			
		}else 
			{
				vfTurnOff_LED(eGREEN);
			}
	}
	
	vfTurnOff_LED(eRED);
	vfTurnOff_LED(eGREEN);
	vfTurnOff_LED(eBLUE);
	
	for(;;) {	   
		
	   	if(eTRUE == efReadButtonNonBlocking(&sButton1))
	   	{
	   		vfTurnOn_LED( eRED );
	   		vfSendPosition_LCD(eFILA_01_0);
	   		vfSendMessage_LCD("Hello World");
	   		
	   	}else 
	   	{
	   		vfTurnOff_LED( eRED );
	   		//vfClear_LCD();
	   	}
	   	
	   	
	}//End of infinity loop
	
	return 0;
}

void vfdelay(uint32_t u32Time)
{
	while(u32Time--);
}
