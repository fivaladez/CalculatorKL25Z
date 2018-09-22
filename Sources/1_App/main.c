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
	int counter = 0;
	sButton_t sButton1;
	
	if( eTRUE == efInit_LED(eRED)  &&  eTRUE ==  efInit_LED(eGREEN)  &&  eTRUE ==  efInit_LED(eBLUE) )
	{
		vfTurnOff_LED(eRED);
		
		if(eTRUE == efCreateButton(&sButton1, ePORTA, ePIN_1))
		{
			vfTurnOn_LED(eBLUE);
			
		}else 
			{
				vfTurnOff_LED(eBLUE);
		    }
		
		if( eTRUE == efInit_LCD())
		{
			vfTurnOn_LED(eBLUE);
			
		}else 
			{
				vfTurnOff_LED(eGREEN);
			}
	}
	
	for(;;) {	   
	   	counter++;
	   	if(eTRUE == efReadButtonNonBlocking(&sButton1))
	   	{
	   		vfTurnOn_LED(eBLUE);
	   		if( eTRUE == efPossitionData_LCD(eFILA_01_4) )
	   		{
	   			vfSendData_LCD('H');
	   			vfSendData_LCD('E');
	   			vfSendData_LCD('L');
	   			vfSendData_LCD('L');
	   			vfSendData_LCD('O');
	   			   	
	   			vfTurnOn_LED(eGREEN);
	   		}else 
	   			{
	   				vfTurnOff_LED(eGREEN);
	   			}
	   	}else 
	   		{
	   			vfTurnOff_LED(eBLUE);
	   			vfTurnOff_LED(eGREEN);
	   			vfClear_LCD();
	   		}
	   	
	   	
	   	
	}//End of infinity for
	
	return 0;
}

void vfdelay(uint32_t u32Time)
{
	while(u32Time--);
}
