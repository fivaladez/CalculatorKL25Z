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
	sMessage_LCD_t sMessage_LCD;
	
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
			
			vfInit_Msg_LCD( &sMessage_LCD );
			sMessage_LCD.u8Data[0] = 'H';
			sMessage_LCD.u8Data[1] = 'O';
			sMessage_LCD.u8Data[2] = 'L';
			sMessage_LCD.u8Data[3] = 'A';
			
			sMessage_LCD.ePossition = eFILA_01_4;
			
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
	   	}else 
	   		{
	   			vfTurnOff_LED(eBLUE);
	   		}
	   	
	   	if( eTRUE == efSendData_LCD( &sMessage_LCD ) )
	    {
	   		vfTurnOn_LED(eGREEN);
	   		vfdelay(TIME_1S);
	   	}else 
	   		{
	   			vfTurnOff_LED(eGREEN);
	   		}
	   	
	}//End of infinity for
	
	return 0;
}

void vfdelay(uint32_t u32Time)
{
	while(u32Time--);
}
