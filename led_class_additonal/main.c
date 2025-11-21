#include "powerled.h"
#include "uart.h"
#include "medical_led.h"
int main()
{
	USART2_Init();
	 
	medical_led led1;
	PowerLed_Type led2;
	
	medical_led_ctor(&led1,INFRARED,ON,(LedColor_Type)INFRARED);
	PowerLed_ctor(led2,GREEN,ON,CURR_NORMAL,VOLTAGE_NORMAL);
	
	while(1)
	{
		PowerLed_diagnostics(&led2);
		medical_led_diagnostic(&led1);
		PowerLed_effeciency(&led2);
		medical_led_effeciency(&led2);
		
	}
}