#include "powerled.h"
#include "uart.h"
int main()
{
	USART2_Init();
	PowerLed_Type led1,led2;
	PowerLed_ctor(&led1,RED,ON,CURR_NORMAL,DIAM_5MM,VOLTAGE_NORMAL);
	PowerLed_ctor(&led2,YELLOW,ON,CURR_NORMAL,DIAM_5MM,VOLTAGE_NORMAL);
	
	while(1)
	{}
}