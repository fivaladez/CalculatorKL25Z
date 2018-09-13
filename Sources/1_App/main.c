/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "Buttons_driver.h"
#include "Leds_driver.h"

#define TIME_1S			1800000
#define TIME_500MS		900000
#define TIME_250MS		450000

void vfdelay(uint32_t u32Time);

int main(void)
{
	int counter = 0;
	sButton_t sButton1;
	
	if(eTRUE == efInit_LED(eRED) && eTRUE ==  efInit_LED(eGREEN) && eTRUE ==  efInit_LED(eBLUE))
	{
		vfTurnOff_LED(eRED);
		vfTurnOff_LED(eGREEN);
		if(eTRUE == efCreateButton(&sButton1, ePORTA, ePIN_1))
		{
			vfTurnOn_LED(eBLUE);
		}else vfTurnOff_LED(eBLUE);
	}
	
	for(;;) {	   
	   	counter++;
	   	if(eTRUE == efReadButton(&sButton1))
	   	{
	   		vfTurnOff_LED(eRED);
	   		vfTurnOn_LED(eGREEN);
	   		//vfdelay(TIME_1S);
	   	}else 
	   		{
	   			vfTurnOff_LED(eGREEN);
	   			vfTurnOn_LED(eRED);
	   			//vfdelay(TIME_1S);
	   		}
	   	
	}
	
	return 0;
}

void vfdelay(uint32_t u32Time)
{
	while(u32Time--);
}
