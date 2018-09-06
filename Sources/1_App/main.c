/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "Buttons_driver.h"
#include "GPIO_driver.h"

#define TIME_1S			100000
#define TIME_500MS		50000
#define TIME_250MS		25000
#define TIME_100MS		10000
#define TIME_50MS		5000
#define TIME_25MS		2500
#define TIME_10MS		1000
#define TIME_5MS		500

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
	   		vfTogglePort_GPIO(ePORTB ,ePIN_19);//Turn on Led Green
	   	}//else vfSetPort_GPIO(ePORTB ,ePIN_19);
	   	vfdelay(TIME_1S);
	   	
	}
	
	return 0;
}

void vfdelay(uint32_t u32Time)
{
	uint32_t u32Value = 0;
	
	for(u32Value = u32Time * 10; 0 < u32Value; u32Value--)
	{
		/*Do nothing*/
	}
	
}
