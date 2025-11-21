#include "led.h"
Led led1(RED,ON);
int main()
{
	USART2_Init();
	Led led2(BLUE,ON);
	Led *led3= new Led(YELLOW,ON);	//variable for dynamic memory allocation
	
	
	led1.Led_getstate();
	led2.Led_getstate();
	led3->Led_getstate();
	
	led1.Led_setstate(OFF);
	led2.Led_setstate(OFF);
	led3->Led_setstate(OFF);
	
	delete led3;	//freeing it
	while(1)
	{}
}