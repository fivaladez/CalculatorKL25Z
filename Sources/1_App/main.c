/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "Buttons_driver.h"
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

void vfdelay(uint32_t u32Time);

int main(void)
{
	int counter = 0;
	sButton_t sButton1;
	
	if(eTRUE == u8fInit_GPIO(ePORTB ,ePIN_18, eOUT) && eTRUE ==  u8fInit_GPIO(ePORTB ,ePIN_19, eOUT))
	{
		if(eTRUE == u8fCreateButton(&sButton1, ePORTA, ePIN_1))
		{
			vfClearPort_GPIO(ePORTB ,ePIN_18);//Turn on Led Red
		}else vfSetPort_GPIO(ePORTB ,ePIN_18);
	}
	
	for(;;) {	   
	   	counter++;
	   	if(eTRUE == u8fReadButton(&sButton1))
	   	{
	   		vfSetPort_GPIO(ePORTB ,ePIN_18);//Turn off led red
	   		vfClearPort_GPIO(ePORTB ,ePIN_19);//Turn on Led Green
	   		//vfdelay(TIME_1S);
	   	}else 
	   		{
	   			vfSetPort_GPIO(ePORTB ,ePIN_19);//Turn off led green
	   			vfClearPort_GPIO(ePORTB ,ePIN_18);//Turn on Led Red
	   			//vfdelay(TIME_1S);
	   		}
	   	
	}
	
	return 0;
}

void vfdelay(uint32_t u32Time)
{
	uint32_t u32Value = 0;
	
	for(u32Value = u32Time; 0 < u32Value; u32Value--)
	{
		/*Do nothing*/
	}
	
}
